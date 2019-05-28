typedef enum {
	INFO_RADIO, MUSIC_FM, JAZZY_RADIO, KLASSZIK_RADIO, KLUB_RADIO
} radio_channel_t;

void radio_names(radio_channel_t radio_chanel) {
	switch (radio_chanel) {

	case INFO_RADIO:
		'88.1';
		break;
	case MUSIC_FM:
		'89.5';
		break;
	case JAZZY_RADIO:
		'90.9';
		break;
	case KLASSZIK_RADIO:
		'92.1';
		break;
	case KLUB_RADIO:
		'92.9';
		break;

	}
}



volatile uint8_t volume = 0;
volatile float radio_frequency = 87.5;
volatile push_button_time= 0;
volatile uint32_t period_timer = 0;
volatile uint32_t elapsed_time;


GPIO_InitTypeDef volume_up_button;
GPIO_InitTypeDef volume_down_button;
GPIO_InitTypeDef switch_up_radio;
GPIO_InitTypeDef switch_down_radio;
TIM_HandleTypeDef timer_handle;

static void Error_Handler(void);
static void SystemClock_Config(void);

void init_push_button_1() {
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	volume_up_button.Pin = GPIO_PIN_6;
	volume_up_button.Mode = GPIO_MODE_IT_RISING;
	volume_up_button.Pull = GPIO_NOPULL;
	volume_up_button.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &volume_up_button);

	HAL_NVIC_SetPriority(EXTI9_5_IRQn, 1, 0);

	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
}

void init_push_button_2() {
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	volume_up_button.Pin = GPIO_PIN_7;
	volume_up_button.Mode = GPIO_MODE_IT_RISING;
	volume_up_button.Pull = GPIO_NOPULL;
	volume_up_button.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &volume_down_button);

	HAL_NVIC_SetPriority(EXTI9_5_IRQn, 1, 0);

	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
}

void init_push_button_3() {
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	volume_up_button.Pin = GPIO_PIN_8;
	volume_up_button.Mode = GPIO_MODE_IT_RISING;
	volume_up_button.Pull = GPIO_NOPULL;
	volume_up_button.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &switch_up_radio);

	HAL_NVIC_SetPriority(EXTI9_5_IRQn, 1, 0);

	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
}

void init_push_button_4() {
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	volume_up_button.Pin = GPIO_PIN_9;
	volume_up_button.Mode = GPIO_MODE_IT_RISING;
	volume_up_button.Pull = GPIO_NOPULL;
	volume_up_button.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &switch_down_radio);

	HAL_NVIC_SetPriority(EXTI9_5_IRQn, 1, 0);

	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
}

void timer_init(void) {
	__HAL_RCC_TIM2_CLK_ENABLE()
	;

	HAL_TIM_Base_DeInit(&timer_handle);
	__HAL_TIM_SET_COUNTER(&timer_handle, 0);

	timer_handle.Instance = TIM2;
	timer_handle.Init.Prescaler = 10800 - 1;
	timer_handle.Init.Period = 10000 - 1;
	timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
	timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	HAL_TIM_Base_Init(&timer_handle);

	HAL_NVIC_SetPriority(TIM2_IRQn, 1, 0);

	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

int main(void) {
	HAL_Init();
	SystemClock_Config();
	init_push_button_1();
	init_push_button_2();
	init_push_button_3();
	init_push_button_4();

	while (1) {

	}

}

void EXTI9_5_IRQHandler() {
	
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_6);
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_7);
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_8);
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_9);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (GPIO_Pin == &volume_up_button) {
		
		HAL_TIM_Base_Start_IT(&timer_handle);
		volume_up_button.Mode = GPIO_MODE_IT_FALLING;
		
		HAL_GPIO_Init(GPIOF, &volume_up_button);
		push_button_time = period_timer;
		__HAL_TIM_GET_COUNTER()
	}
}

void TIM2_IRQHandler(void) {
	HAL_TIM_IRQHandler(&timer_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim->Instance == TIM2) {
		period_timer++;
		
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
