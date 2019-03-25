#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

GPIO_InitTypeDef green_and_blue_LED_handle;
GPIO_InitTypeDef red_LED_handle;
GPIO_InitTypeDef blue_button_handle; // GREEN
GPIO_InitTypeDef external_button1_handle;
GPIO_InitTypeDef external_button2_handle;

TIM_HandleTypeDef Tim_Handle;
TIM_OC_InitTypeDef sConfig;

TIM_HandleTypeDef timer_handle;

volatile int counter = 0;

static void Error_Handler(void);
static void SystemClock_Config(void);

void init_timer()
{
	__HAL_RCC_TIM2_CLK_ENABLE()
	;

	HAL_TIM_Base_DeInit(&timer_handle);
	__HAL_TIM_SET_COUNTER(&timer_handle, 0);
	timer_handle.Instance = TIM2;
	timer_handle.Init.Prescaler = 54000 - 1; /* 108000000/54000=2000 -> speed of 1 count-up: 1/2000 sec = 0.5 ms */
	timer_handle.Init.Period = 2000 - 1; /* 2000 x 0.5 ms = 1 second period */
	timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&timer_handle);

	HAL_NVIC_SetPriority(TIM2_IRQn, 2, 0);

	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

void init_external_button1()
{
	__HAL_RCC_GPIOI_CLK_ENABLE()
	;

	external_button1_handle.Pin = GPIO_PIN_2;
	external_button1_handle.Pull = GPIO_NOPULL;
	external_button1_handle.Speed = GPIO_SPEED_FAST;
	external_button1_handle.Mode = GPIO_MODE_IT_RISING;

	HAL_GPIO_Init(GPIOI, &external_button1_handle);

	HAL_NVIC_SetPriority(EXTI2_IRQn, 4, 0);

	HAL_NVIC_EnableIRQ(EXTI2_IRQn);
}

void init_external_button2()
{
	__HAL_RCC_GPIOG_CLK_ENABLE()
	;

	external_button2_handle.Pin = GPIO_PIN_7;
	external_button2_handle.Pull = GPIO_NOPULL;
	external_button2_handle.Speed = GPIO_SPEED_FAST;
	external_button2_handle.Mode = GPIO_MODE_IT_RISING;

	HAL_GPIO_Init(GPIOG, &external_button2_handle);

	HAL_NVIC_SetPriority(EXTI9_5_IRQn, 4, 0);

	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
}

void init_user_button()
{

	__HAL_RCC_GPIOI_CLK_ENABLE()
	;

	blue_button_handle.Pin = GPIO_PIN_11;
	blue_button_handle.Pull = GPIO_NOPULL;
	blue_button_handle.Speed = GPIO_SPEED_FAST;
	blue_button_handle.Mode = GPIO_MODE_IT_RISING;

	HAL_GPIO_Init(GPIOI, &blue_button_handle);

	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 4, 0);

	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void init_green_and_blue_LED()
{
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;
	green_and_blue_LED_handle.Pin = GPIO_PIN_8 | GPIO_PIN_9;
	green_and_blue_LED_handle.Mode = GPIO_MODE_OUTPUT_PP;
	green_and_blue_LED_handle.Pull = GPIO_NOPULL;
	green_and_blue_LED_handle.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &green_and_blue_LED_handle);
}

void init_red_LED()
{
	__HAL_RCC_GPIOI_CLK_ENABLE()
	;
	red_LED_handle.Pin = GPIO_PIN_0;
	red_LED_handle.Mode = GPIO_MODE_AF_PP;
	red_LED_handle.Pull = GPIO_NOPULL;
	red_LED_handle.Speed = GPIO_SPEED_HIGH;
	red_LED_handle.Alternate = GPIO_AF2_TIM5;

	HAL_GPIO_Init(GPIOI, &red_LED_handle);
}

void init_timer_PWM()
{
	__HAL_RCC_TIM5_CLK_ENABLE()
	;
	/* configuring the basic mode of your timer (which direction should it count, what is the maximum value, etc.) */
	Tim_Handle.Instance = TIM5;
	Tim_Handle.Init.Prescaler = 108 - 1; /* 108000000/108=1000000 -> speed of 1 count-up: 1/1000000 s = 0.001 ms */
	Tim_Handle.Init.Period = 100 - 1; /* 100 x 0.001 ms = 10 ms = 0.01 s period */
	Tim_Handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	Tim_Handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	/* configuring the timer in PWM mode instead of calling HAL_TIM_Base_Init(&Tim_Handle) */
	HAL_TIM_PWM_Init(&Tim_Handle);

	/* output compare config ***********************************************************************************************/
	sConfig.Pulse = 50;
	/* 50% * 0.01 s = 0.005 s: 0.005 low, then 0.005 s high; our eyes are not able to notice, that it is a vibrating light */
	sConfig.OCMode = TIM_OCMODE_PWM1;
	sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfig.OCFastMode = TIM_OCFAST_ENABLE;

	HAL_TIM_PWM_ConfigChannel(&Tim_Handle, &sConfig, TIM_CHANNEL_4);
}

int main(void)
{
	HAL_Init();
	SystemClock_Config();

	init_green_and_blue_LED();
	init_red_LED();

	init_user_button();
	init_external_button1();
	init_external_button2();

	init_timer_PWM();

	init_timer();

	HAL_TIM_PWM_Start(&Tim_Handle, TIM_CHANNEL_4);

	HAL_TIM_Base_Start_IT(&timer_handle);

	while (1) {

	}

	return 0;

}

void TIM2_IRQHandler()
{
	HAL_TIM_IRQHandler(&timer_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM2) {
		if (counter == 1) {
			__HAL_TIM_SET_COMPARE(&Tim_Handle, TIM_CHANNEL_4, 100);
			counter = 0;
		} else if (counter == 0) {
			__HAL_TIM_SET_COMPARE(&Tim_Handle, TIM_CHANNEL_4, 0);
			counter++;
		}
	}
}

void EXTI2_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(external_button1_handle.Pin);
}

void EXTI9_5_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(external_button2_handle.Pin);
}

void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(blue_button_handle.Pin);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == blue_button_handle.Pin) {
		HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_8); // GREEN
	} else if (GPIO_Pin == external_button1_handle.Pin) {
		HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_9);
	} else if (GPIO_Pin == external_button2_handle.Pin) {
		__HAL_TIM_SET_COMPARE(&Tim_Handle, TIM_CHANNEL_4, 99);
	}
}

static void Error_Handler(void)
{
}

static void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/**Configure the main internal regulator output voltage */
	__HAL_RCC_PWR_CLK_ENABLE()
	;
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
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}