#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

typedef enum {
	OPEN, SECURING, SECURED, OPENING
} state_t;

volatile state_t state = OPEN;
volatile int securing_period_counter = 0;
volatile int opening_period_counter = 0;

GPIO_InitTypeDef user_button_handle;
TIM_HandleTypeDef open_timer_handle;
TIM_HandleTypeDef securing_timer_handle;
TIM_HandleTypeDef opening_timer_handle;

static void Error_Handler(void);
static void SystemClock_Config(void);

void init_user_button() {

	__HAL_RCC_GPIOI_CLK_ENABLE()
	;

	user_button_handle.Pin = GPIO_PIN_11;
	user_button_handle.Pull = GPIO_NOPULL;
	user_button_handle.Speed = GPIO_SPEED_FAST;
	user_button_handle.Mode = GPIO_MODE_IT_RISING; // IT LIKE INTERRUPT, Generate rising endge of signal

	HAL_GPIO_Init(GPIOI, &user_button_handle);

	// Priority of the interrupt, we have to set it!
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 0);

	// Enable interrupt
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

void timer_init(void) {
	__HAL_RCC_TIM2_CLK_ENABLE()
	;

	HAL_TIM_Base_DeInit(&open_timer_handle);
	__HAL_TIM_SET_COUNTER(&open_timer_handle, 0);

	open_timer_handle.Instance = TIM2;
	open_timer_handle.Init.Prescaler = 10800 - 1;
	open_timer_handle.Init.Period = 10000 - 1;
	open_timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
	open_timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	HAL_TIM_Base_Init(&open_timer_handle);

	HAL_NVIC_SetPriority(TIM2_IRQn, 4, 0);

	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

void timer2_init(void) {
	__HAL_RCC_TIM3_CLK_ENABLE()
	;

	HAL_TIM_Base_DeInit(&securing_timer_handle);
	__HAL_TIM_SET_COUNTER(&securing_timer_handle, 0);

	securing_timer_handle.Instance = TIM3;
	securing_timer_handle.Init.Prescaler = 10800 - 1;
	securing_timer_handle.Init.Period = 5000 - 1;
	securing_timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
	securing_timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	HAL_TIM_Base_Init(&securing_timer_handle);

	HAL_NVIC_SetPriority(TIM3_IRQn, 1, 0);

	HAL_NVIC_EnableIRQ(TIM3_IRQn);
}

void timer3_init(void) {
	__HAL_RCC_TIM4_CLK_ENABLE()
	;

	HAL_TIM_Base_DeInit(&opening_timer_handle);
	__HAL_TIM_SET_COUNTER(&opening_timer_handle, 0);

	opening_timer_handle.Instance = TIM4;
	opening_timer_handle.Init.Prescaler = 10800 - 1;
	opening_timer_handle.Init.Period = 5000 - 1;
	opening_timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
	opening_timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	HAL_TIM_Base_Init(&opening_timer_handle);

	HAL_NVIC_SetPriority(TIM4_IRQn, 3, 0);

	HAL_NVIC_EnableIRQ(TIM4_IRQn);
}

void init_led() {
	BSP_LED_Init(LED_GREEN);
}
int main(void) {

	HAL_Init();
	SystemClock_Config();
	init_led();
	init_user_button();
	timer_init();
	timer2_init();
	timer3_init();
	HAL_TIM_Base_Start_IT(&open_timer_handle);

	while (1) {
	}

	return 0;
}
//
void EXTI15_10_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(user_button_handle.Pin);

}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (GPIO_Pin == user_button_handle.Pin) {
		if (state == OPEN) {
			state = SECURING;
			HAL_TIM_Base_Stop_IT(&open_timer_handle);
			HAL_TIM_Base_Start_IT(&securing_timer_handle);
		} else if (state == SECURED) {
			state = OPENING;
			HAL_TIM_Base_Start_IT(&opening_timer_handle);
		}
	}
}

void TIM2_IRQHandler(void) {
	HAL_TIM_IRQHandler(&open_timer_handle);
}

void TIM3_IRQHandler(void) {
	HAL_TIM_IRQHandler(&securing_timer_handle);
}

void TIM4_IRQHandler(void) {
	HAL_TIM_IRQHandler(&opening_timer_handle);
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim->Instance == TIM2) {
		BSP_LED_Toggle(LED_GREEN);
	} else if (htim->Instance == TIM3) {
		BSP_LED_Toggle(LED_GREEN);
		securing_period_counter++;
		if (securing_period_counter % 10 == 0) {
			HAL_TIM_Base_Stop_IT(&securing_timer_handle);
			state = SECURED;
			BSP_LED_Off(LED_GREEN);
		}
	} else if (htim->Instance == TIM4) {
		BSP_LED_Toggle(LED_GREEN);
		opening_period_counter++;
		if (opening_period_counter % 12 == 0) {
			HAL_TIM_Base_Stop_IT(&opening_timer_handle);
			state = OPEN;
			HAL_TIM_Base_Start_IT(&open_timer_handle);
		}
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
