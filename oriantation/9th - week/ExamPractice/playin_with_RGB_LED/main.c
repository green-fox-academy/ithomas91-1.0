#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

TIM_HandleTypeDef TimHandle;
TIM_HandleTypeDef TimHandle2;
TIM_HandleTypeDef TimHandle3;

GPIO_InitTypeDef PA15_LED_config;
GPIO_InitTypeDef PA15_LED_config2;
GPIO_InitTypeDef PA15_LED_config3;

TIM_OC_InitTypeDef sConfig;
TIM_OC_InitTypeDef sConfig2;
TIM_OC_InitTypeDef sConfig3;

GPIO_InitTypeDef push_button;

volatile int x = 0;

static void Error_Handler(void);
static void SystemClock_Config(void);

void init_push_button() {
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	push_button.Pin = GPIO_PIN_10;
	push_button.Mode = GPIO_MODE_IT_RISING;
	push_button.Pull = GPIO_NOPULL;
	push_button.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &push_button);

	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 1, 0);

	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void init_Red_led() {
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;
	PA15_LED_config.Pin = GPIO_PIN_15;
	PA15_LED_config.Mode = GPIO_MODE_AF_PP; /* configure as output, in push-pull mode */
	PA15_LED_config.Pull = GPIO_NOPULL;
	PA15_LED_config.Speed = GPIO_SPEED_HIGH;
	PA15_LED_config.Alternate = GPIO_AF1_TIM2; /* this alternate function we need to use TIM2 in output compare mode */
	HAL_GPIO_Init(GPIOA, &PA15_LED_config);

	/* base timer config ***************************************************************************************************/
	/* we need to enable the TIM2 */
	__HAL_RCC_TIM2_CLK_ENABLE()
	;
	/* configuring the basic mode of your timer (which direction should it count, what is the maximum value, etc.) */
	TimHandle.Instance = TIM2;
	TimHandle.Init.Prescaler = 108 - 1; /* 108000000/108=1000000 -> speed of 1 count-up: 1/1000000 s = 0.001 ms */
	TimHandle.Init.Period = 100 - 1; /* 100 x 0.001 ms = 10 ms = 0.01 s period */
	TimHandle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TimHandle.Init.CounterMode = TIM_COUNTERMODE_UP;

	/* configuring the timer in PWM mode instead of calling HAL_TIM_Base_Init(&TimHandle) */
	HAL_TIM_PWM_Init(&TimHandle);

	/* output compare config ***********************************************************************************************/
	sConfig.Pulse = 50;
	/* 50% * 0.01 s = 0.005 s: 0.005 low, then 0.005 s high; our eyes are not able to notice, that it is a vibrating light */
	sConfig.OCMode = TIM_OCMODE_PWM1;
	sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfig.OCFastMode = TIM_OCFAST_ENABLE;

	HAL_TIM_PWM_ConfigChannel(&TimHandle, &sConfig, TIM_CHANNEL_1);

	/* starting PWM */
	HAL_TIM_PWM_Start(&TimHandle, TIM_CHANNEL_1);
}

void init_Green_led() {
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;
	PA15_LED_config2.Pin = GPIO_PIN_8;
	PA15_LED_config2.Mode = GPIO_MODE_AF_PP; /* configure as output, in push-pull mode */
	PA15_LED_config2.Pull = GPIO_NOPULL;
	PA15_LED_config2.Speed = GPIO_SPEED_HIGH;
	PA15_LED_config2.Alternate = GPIO_AF1_TIM1; /* this alternate function we need to use TIM2 in output compare mode */
	HAL_GPIO_Init(GPIOA, &PA15_LED_config2);

	/* base timer config ***************************************************************************************************/
	/* we need to enable the TIM2 */
	__HAL_RCC_TIM1_CLK_ENABLE()
	;
	/* configuring the basic mode of your timer (which direction should it count, what is the maximum value, etc.) */
	TimHandle2.Instance = TIM1;
	TimHandle2.Init.Prescaler = 108 - 1; /* 108000000/108=1000000 -> speed of 1 count-up: 1/1000000 s = 0.001 ms */
	TimHandle2.Init.Period = 100 - 1; /* 100 x 0.001 ms = 10 ms = 0.01 s period */
	TimHandle2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TimHandle2.Init.CounterMode = TIM_COUNTERMODE_UP;

	/* configuring the timer in PWM mode instead of calling HAL_TIM_Base_Init(&TimHandle) */
	HAL_TIM_PWM_Init(&TimHandle2);

	/* output compare config ***********************************************************************************************/
	sConfig2.Pulse = 50;
	/* 50% * 0.01 s = 0.005 s: 0.005 low, then 0.005 s high; our eyes are not able to notice, that it is a vibrating light */
	sConfig2.OCMode = TIM_OCMODE_PWM1;
	sConfig2.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfig2.OCFastMode = TIM_OCFAST_ENABLE;

	HAL_TIM_PWM_ConfigChannel(&TimHandle2, &sConfig2, TIM_CHANNEL_1);

	/* starting PWM */
	HAL_TIM_PWM_Start(&TimHandle2, TIM_CHANNEL_1);
}

void init_Blue_led() {
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;
	PA15_LED_config3.Pin = GPIO_PIN_8;
	PA15_LED_config3.Mode = GPIO_MODE_AF_PP; /* configure as output, in push-pull mode */
	PA15_LED_config3.Pull = GPIO_NOPULL;
	PA15_LED_config3.Speed = GPIO_SPEED_HIGH;
	PA15_LED_config3.Alternate = GPIO_AF1_TIM1; /* this alternate function we need to use TIM2 in output compare mode */
	HAL_GPIO_Init(GPIOA, &PA15_LED_config3);

	/* base timer config ***************************************************************************************************/
	/* we need to enable the TIM2 */
	__HAL_RCC_TIM12_CLK_ENABLE()
	;
	/* configuring the basic mode of your timer (which direction should it count, what is the maximum value, etc.) */
	TimHandle3.Instance = TIM12;
	TimHandle3.Init.Prescaler = 108 - 1; /* 108000000/108=1000000 -> speed of 1 count-up: 1/1000000 s = 0.001 ms */
	TimHandle3.Init.Period = 100 - 1; /* 100 x 0.001 ms = 10 ms = 0.01 s period */
	TimHandle3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TimHandle3.Init.CounterMode = TIM_COUNTERMODE_UP;

	/* configuring the timer in PWM mode instead of calling HAL_TIM_Base_Init(&TimHandle) */
	HAL_TIM_PWM_Init(&TimHandle3);

	/* output compare config ***********************************************************************************************/
	sConfig2.Pulse = 50;
	/* 50% * 0.01 s = 0.005 s: 0.005 low, then 0.005 s high; our eyes are not able to notice, that it is a vibrating light */
	sConfig3.OCMode = TIM_OCMODE_PWM1;
	sConfig3.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfig3.OCFastMode = TIM_OCFAST_ENABLE;

	HAL_TIM_PWM_ConfigChannel(&TimHandle3, &sConfig3, TIM_CHANNEL_1);

	/* starting PWM */
	HAL_TIM_PWM_Start(&TimHandle3, TIM_CHANNEL_1);
}

int main(void) {
	SystemClock_Config();
	HAL_Init();

	init_Red_led();
	init_Green_led();
	init_Blue_led();
	init_push_button();
	HAL_TIM_PWM_Start(&TimHandle, TIM_CHANNEL_1);
	__HAL_TIM_SET_COMPARE(&TimHandle, TIM_CHANNEL_1, 0);
	HAL_TIM_PWM_Start(&TimHandle2, TIM_CHANNEL_1);
	__HAL_TIM_SET_COMPARE(&TimHandle2, TIM_CHANNEL_1, 0);
	HAL_TIM_PWM_Start(&TimHandle3, TIM_CHANNEL_1);
	__HAL_TIM_SET_COMPARE(&TimHandle3, TIM_CHANNEL_1, 0);

	while (1) {

	}

}

void EXTI15_10_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(push_button.Pin);

}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (GPIO_Pin == push_button.Pin) {
// Action taken by pressing button
		__HAL_TIM_SET_COMPARE(&TimHandle, TIM_CHANNEL_1, 10);
		__HAL_TIM_SET_COMPARE(&TimHandle2, TIM_CHANNEL_1, 80);
		__HAL_TIM_SET_COMPARE(&TimHandle3, TIM_CHANNEL_1, 30);


	}
}

static void Error_Handler(void) {
}

static void SystemClock_Config(void) {
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
