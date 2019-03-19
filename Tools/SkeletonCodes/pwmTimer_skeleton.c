#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

TIM_HandleTypeDef pwm_timer_handle;

void timer_init (void)
{
   __HAL_RCC_TIM2_CLK_ENABLE();

   HAL_TIM_Base_DeInit(&pwm_timer_handle);
   __HAL_TIM_SET_COUNTER(&pwm_timer_handle, 0);
   
   timer_handle.Instance = TIM2;
   timer_handle.Init.Prescaler = 54000 - 1;
   timer_handle.Init.Period = 1000 - 1;
   timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
   timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
   HAL_TIM_Base_Init(&timer_handle);

   HAL_TIM_Base_Start_IT(&pwm_timer_handle);

   HAL_NVIC_SetPriority(TIM2_IRQn, 1, 0);

   HAL_NVIC_EnableIRQ(TIM2_IRQn);

    HAL_TIM_PWM_Init(&pwm_timer_handle);
   
    /* output compare config ***********************************************************************************************/
    sConfig.Pulse = 50;
    /* 50% * 0.01 s = 0.005 s: 0.005 low, then 0.005 s high; our eyes are not able to notice, that it is a vibrating light */
    sConfig.OCMode = TIM_OCMODE_PWM1;
    sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfig.OCFastMode = TIM_OCFAST_ENABLE;

    HAL_TIM_PWM_ConfigChannel(&pwm_timer_handle, &sConfig, TIM_CHANNEL_1);

    /* starting PWM */
    HAL_TIM_PWM_Start(&pwm_timer_handle, TIM_CHANNEL_1);
}

int main(void)
{
   HAL_Init();
   SystemClock_Config();

   BSP_LED_Init(LED_GREEN);

   timer_init();

   HAL_TIM_Base_Start_IT(&timer_handle);
   while (1) {
   }
}

void TIM2_IRQHandler(void)
{
   HAL_TIM_IRQHandler(&pwm_timer_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
   if(htim->Instance == TIM2) {
       BSP_LED_Toggle(LED_GREEN);
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