#include "stm32f7xx_hal.h"

GPIO_InitTypeDef user_button_handle;
TIM_HandleTypeDef timer_handle;
TIM_OC_InitTypeDef sConfig;
TIM_HandleTypeDef pwm_timer_handle;
GPIO_InitTypeDef pwm_led;

static void Error_Handler(void);
static void SystemClock_Config(void);

volatile uint16_t counter = 0;

void init_user_button()  // Function of User Push Button (Blue)
{
	// Initialize the user push button (Blue)
	__HAL_RCC_GPIOI_CLK_ENABLE()
	;

	user_button_handle.Pin = GPIO_PIN_11;
	user_button_handle.Pull = GPIO_NOPULL;
	user_button_handle.Speed = GPIO_SPEED_FAST;
	user_button_handle.Mode = GPIO_MODE_IT_RISING; // IT LIKE INTERRUPT, Generate rising endge of signal

	HAL_GPIO_Init(GPIOI, &user_button_handle);

	// Priority of the interrupt, we have to set it!
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 1, 0);

	// Enable interrupt
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

void timer_init (void)
{
   __HAL_RCC_TIM3_CLK_ENABLE();

   HAL_TIM_Base_DeInit(&timer_handle);
   __HAL_TIM_SET_COUNTER(&timer_handle, 0);
   
   timer_handle.Instance = TIM3;
   timer_handle.Init.Prescaler = 10800 - 1;
   timer_handle.Init.Period = 2500 - 1;
   timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
   timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
   HAL_TIM_Base_Init(&timer_handle);

   HAL_NVIC_SetPriority(TIM3_IRQn, 2, 0);

   HAL_NVIC_EnableIRQ(TIM3_IRQn);
}

void pwm_timer_init (void)
{
   __HAL_RCC_TIM2_CLK_ENABLE();
   
   pwm_timer_handle.Instance = TIM2;
   pwm_timer_handle.Init.Prescaler = 1080 - 1;
   pwm_timer_handle.Init.Period = 1001 - 1;
   pwm_timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
   pwm_timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
   
    HAL_TIM_PWM_Init(&pwm_timer_handle);
   
    
    sConfig.Pulse = 0;
    
    sConfig.OCMode = TIM_OCMODE_PWM1;
    sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfig.OCFastMode = TIM_OCFAST_ENABLE;

    HAL_TIM_PWM_ConfigChannel(&pwm_timer_handle, &sConfig, TIM_CHANNEL_1);

    /* starting PWM */
    HAL_TIM_PWM_Start(&pwm_timer_handle, TIM_CHANNEL_1);
}

void init_GIPO_LED()
{
__HAL_RCC_GPIOA_CLK_ENABLE();
    pwm_led.Pin = GPIO_PIN_15;
    pwm_led.Mode = GPIO_MODE_AF_PP;	/* configure as output, in push-pull mode */
    pwm_led.Pull = GPIO_NOPULL;
    pwm_led.Speed = GPIO_SPEED_HIGH;
    pwm_led.Alternate = GPIO_AF1_TIM2;	/* this alternate function we need to use TIM2 in output compare mode */
    HAL_GPIO_Init(GPIOA, &pwm_led);
}
int main(void)
{
	HAL_Init();

    SystemClock_Config();

	init_user_button();
	timer_init ();
	pwm_timer_init ();
    init_GIPO_LED();
    HAL_TIM_Base_Start_IT(&timer_handle);
    
    while(1){

    }
}

void EXTI15_10_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(user_button_handle.Pin);

}
	//Looking for weak function in there
	
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (GPIO_Pin == user_button_handle.Pin) {
        if(counter <= 950){
            counter += 50;
            __HAL_TIM_SET_COMPARE(&pwm_timer_handle, TIM_CHANNEL_1, counter);
        }
	}
}
void TIM3_IRQHandler(void)
{
   HAL_TIM_IRQHandler(&timer_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
   if(htim->Instance == TIM3) {
       if(counter >= 50){
           counter -= 50;
           __HAL_TIM_SET_COMPARE(&pwm_timer_handle, TIM_CHANNEL_1, counter);
       }
   }
}

static void Error_Handler(void)
{
}

static void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct =
	{ 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct =
	{ 0 };

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

	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/**Activate the Over-Drive mode */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
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
  while (1) {}
}


void MemManage_Handler(void)
{
  while (1) {}
}

void BusFault_Handler(void)
{
  while (1) {}
}

void UsageFault_Handler(void)
{
  while (1) {}
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