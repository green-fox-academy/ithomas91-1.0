#include "stm32f7xx_hal.h"
#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

GPIO_InitTypeDef blue_user_button;
TIM_HandleTypeDef water_timer;
GPIO_InitTypeDef colder_button;
GPIO_InitTypeDef warmer_button;
GPIO_InitTypeDef blue_led;
GPIO_InitTypeDef red_led;
TIM_HandleTypeDef red_pwm_timer;
TIM_HandleTypeDef blue_pwm_timer;

static void Error_Handler(void);
static void SystemClock_Config(void);

typedef enum 
{
    ON = 0,
    OFF = 1
} state_t;

typedef enum
{
    ICE_COLD = 0,
    COLD = 1,
    LUKEWARM = 2,
    WARM = 3,
    HOT = 4
} temperature_t;

volatile uint32_t last_debounce_time = 0;
volatile temperature_t temperature = LUKEWARM;
volatile state_t state = OFF;

void init_blue_user_button()
{
    __HAL_RCC_GPIOI_CLK_ENABLE();
    blue_user_button.Pin = GPIO_PIN_11;
    blue_user_button.Mode = GPIO_MODE_IT_RISING;
    blue_user_button.Pull = GPIO_NOPULL;
    blue_user_button.Speed = GPIO_SPEED_FAST;

    HAL_GPIO_Init(GPIOI, &blue_user_button);
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 4, 0);
}

void init_timer()
{
    __HAL_RCC_TIM4_CLK_ENABLE();
    water_timer.Instance = TIM4;
    water_timer.Init.Prescaler = 10800 - 1;
    water_timer.Init.Period = 50000 - 1;
    water_timer.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    water_timer.Init.CounterMode = TIM_COUNTERMODE_UP;

    HAL_TIM_Base_Init(&water_timer);
    HAL_NVIC_EnableIRQ(TIM4_IRQn);
    HAL_NVIC_SetPriority(TIM4_IRQn, 5, 0);
}
void init_colder_button()
{
    __HAL_RCC_GPIOA_CLK_ENABLE();

    colder_button.Pin = GPIO_PIN_0;
    colder_button.Mode = GPIO_MODE_IT_RISING;
    colder_button.Pull = GPIO_NOPULL;
    colder_button.Speed = GPIO_SPEED_FAST;

    HAL_GPIO_Init(GPIOA, &colder_button);
    HAL_NVIC_EnableIRQ(EXTI0_IRQn);
    HAL_NVIC_SetPriority(EXTI0_IRQn, 6, 0);
}

void init_warmer_button()
{
    __HAL_RCC_GPIOF_CLK_ENABLE();

    warmer_button.Pin = GPIO_PIN_9;
    warmer_button.Mode = GPIO_MODE_IT_RISING;
    warmer_button.Pull = GPIO_NOPULL;
    warmer_button.Speed = GPIO_SPEED_FAST;

    HAL_GPIO_Init(GPIOF, &warmer_button);
    HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
    HAL_NVIC_SetPriority(EXTI9_5_IRQn, 6, 0);
}

void init_led_pins()
{
    __HAL_RCC_GPIOB_CLK_ENABLE();
    blue_led.Pin = GPIO_PIN_4;
    blue_led.Pull = GPIO_NOPULL;
    blue_led.Speed = GPIO_SPEED_FAST;
    blue_led.Mode = GPIO_MODE_AF_PP;
    blue_led.Alternate = GPIO_AF2_TIM3;
    HAL_GPIO_Init(GPIOB, &blue_led);

    __HAL_RCC_GPIOA_CLK_ENABLE();
    red_led.Pin = GPIO_PIN_15;
    red_led.Pull = GPIO_NOPULL;
    red_led.Speed = GPIO_SPEED_FAST;
    red_led.Mode = GPIO_MODE_AF_PP;
    red_led.Alternate = GPIO_AF1_TIM2;
    HAL_GPIO_Init(GPIOA, &red_led);
}

void init_pwm()
{
    // Initialize the timers
    __HAL_RCC_TIM3_CLK_ENABLE();
    blue_pwm_timer.Instance = TIM3;
    blue_pwm_timer.Init.Prescaler = 108 - 1; /* 108000000/108=1000000 -> speed of 1 count-up: 1/1000000 s = 0.001 ms */
    blue_pwm_timer.Init.Period = 100 - 1;    /* 100 x 0.001 ms = 10 ms = 0.01 s period */
    blue_pwm_timer.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    blue_pwm_timer.Init.CounterMode = TIM_COUNTERMODE_UP;
    HAL_TIM_PWM_Init(&blue_pwm_timer);

    __HAL_RCC_TIM2_CLK_ENABLE();
    red_pwm_timer.Instance = TIM2;
    red_pwm_timer.Init.Prescaler = 108 - 1; /* 108000000/108=1000000 -> speed of 1 count-up: 1/1000000 s = 0.001 ms */
    red_pwm_timer.Init.Period = 100 - 1;    /* 100 x 0.001 ms = 10 ms = 0.01 s period */
    red_pwm_timer.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    red_pwm_timer.Init.CounterMode = TIM_COUNTERMODE_UP;
    HAL_TIM_PWM_Init(&red_pwm_timer);

    TIM_OC_InitTypeDef sConfig;

    /* output compare config ***********************************************************************************************/
    sConfig.Pulse = 100;
    /* 50% * 0.01 s = 0.005 s: 0.005 low, then 0.005 s high; our eyes are not able to notice, that it is a vibrating light */
    sConfig.OCMode = TIM_OCMODE_PWM1;
    sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfig.OCFastMode = TIM_OCFAST_ENABLE;

    HAL_TIM_PWM_ConfigChannel(&blue_pwm_timer, &sConfig, TIM_CHANNEL_1);
    HAL_TIM_PWM_ConfigChannel(&red_pwm_timer, &sConfig, TIM_CHANNEL_1);

    /* starting PWM */
    HAL_TIM_PWM_Start(&blue_pwm_timer, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&red_pwm_timer, TIM_CHANNEL_1);
}

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    init_blue_user_button();
    init_timer();
    init_colder_button();
    init_warmer_button();
    init_led_pins();
    init_pwm();

    int blue_led_intensity = 100;
    int red_led_intensity = 100;
        while (1)
        {
            if (state == ON)
            {
                switch (temperature)
                {
                case ICE_COLD:
                    blue_led_intensity = 0;
                    red_led_intensity = 100;
                    break;
                case COLD:
                    blue_led_intensity = 25;
                    red_led_intensity = 75;
                    break;
                case LUKEWARM:
                    blue_led_intensity = 50;
                    red_led_intensity = 50;
                    break;
                case WARM:
                    blue_led_intensity = 75;
                    red_led_intensity = 25;
                    break;
                case HOT:
                    blue_led_intensity = 100;
                    red_led_intensity = 0;
                    break;
                default:
                    break;
                }
            }
            else
            {
                    blue_led_intensity = 100;
                    red_led_intensity = 100;
            }

            __HAL_TIM_SET_COMPARE(&blue_pwm_timer, TIM_CHANNEL_1, blue_led_intensity);
            __HAL_TIM_SET_COMPARE(&red_pwm_timer, TIM_CHANNEL_1, red_led_intensity);

        }
}
void EXTI15_10_IRQHandler()
{
    HAL_GPIO_EXTI_IRQHandler(blue_user_button.Pin);
}

void EXTI9_5_IRQHandler()
{
    HAL_GPIO_EXTI_IRQHandler(warmer_button.Pin);
}

void EXTI0_IRQHandler()
{
    HAL_GPIO_EXTI_IRQHandler(colder_button.Pin);
}
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    uint32_t current_time = HAL_GetTick();
    if (current_time - last_debounce_time < 250)
    {
        return;
    }
    if (GPIO_Pin == blue_user_button.Pin)
    {
        if (state == OFF)
        {
            state = ON;
            temperature = LUKEWARM;
            HAL_TIM_Base_Start_IT(&water_timer);
        }
        __HAL_TIM_SET_COUNTER(&water_timer, 0);
    }
    else if (GPIO_Pin == warmer_button.Pin && state == ON)
    {
        if (temperature < HOT)
        {
            temperature++;
        }
    }
    else if (GPIO_Pin == colder_button.Pin && state == ON)
    {
        if (temperature > ICE_COLD)
        {
            temperature--;
        }
    }

    last_debounce_time = current_time;
}

void TIM4_IRQHandler()
{
    HAL_TIM_IRQHandler(&water_timer);
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == water_timer.Instance)
    {
        state = OFF;
        HAL_TIM_Base_Stop(&water_timer);
    }
}

static void Error_Handler(void)
{
}

static void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    /**Configure the main internal regulator output voltage */
    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /**Initializes the CPU, AHB and APB busses clocks */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
    RCC_OscInitStruct.PLL.PLLM = 8;
    RCC_OscInitStruct.PLL.PLLN = 216;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
    RCC_OscInitStruct.PLL.PLLQ = 2;

    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }

    /**Activate the Over-Drive mode */
    if (HAL_PWREx_EnableOverDrive() != HAL_OK)
    {
        Error_Handler();
    }

    /**Initializes the CPU, AHB and APB busses clocks */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
    {
        Error_Handler();
    }
}

void SysTick_Handler(void)
{
    HAL_IncTick();
}

void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
    while (1)
    {
    }
}

void MemManage_Handler(void)
{
    while (1)
    {
    }
}

void BusFault_Handler(void)
{
    while (1)
    {
    }
}

void UsageFault_Handler(void)
{
    while (1)
    {
    }
}

void SVC_Handler(void)
{
}

void DebugMon_Handler(void)
{
}

void PendSV_Handler(void)
{
}