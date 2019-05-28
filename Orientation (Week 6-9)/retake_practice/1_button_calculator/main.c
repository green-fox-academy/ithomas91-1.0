#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include <stdio.h>

GPIO_InitTypeDef external_button;
TIM_HandleTypeDef status_timer;
UART_HandleTypeDef uart_handle;
GPIO_InitTypeDef user_button_handle;

#define UART_PUTCHAR int __io_putchar(int ch)

typedef enum {
	BASE_STATUS, FIRST_NUMBER, OPERANDUS, SECOND_NUMBER, RESULT
} status_t;

volatile uint32_t previous_button_press_time = 0;
volatile int first_number = 0;
volatile int second_number = 0;
volatile int operator = 0;
volatile period_counter = 0;
volatile int result = 0;
volatile status_t status = BASE_STATUS;

void SystemClock_Config(void);

void init_user_button() {
	__HAL_RCC_GPIOI_CLK_ENABLE()
	;

	user_button_handle.Pin = GPIO_PIN_11;
	user_button_handle.Mode = GPIO_MODE_IT_RISING;
	user_button_handle.Pull = GPIO_NOPULL;
	user_button_handle.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOI, &user_button_handle);

	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 5, 0);
}

void init_button() {
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	external_button.Pin = GPIO_PIN_9;
	external_button.Mode = GPIO_MODE_IT_RISING;
	external_button.Pull = GPIO_NOPULL;
	external_button.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOF, &external_button);

	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
	HAL_NVIC_SetPriority(EXTI9_5_IRQn, 4, 0);
}


void init_timer2() {
	__HAL_RCC_TIM2_CLK_ENABLE()
	;

	status_timer.Instance = TIM2;
	status_timer.Init.Prescaler = 10800 - 1; /* 108000000/10800=10000 -> speed of 1 count-up: 1/10000 sec = 0.1 ms */
	status_timer.Init.Period = 10000 - 1; /* 50000 x 0.1 ms = 5 second period */
	status_timer.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	status_timer.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&status_timer);

	HAL_NVIC_EnableIRQ(TIM2_IRQn);
	HAL_NVIC_SetPriority(TIM2_IRQn, 8, 0);
}

void init_uart() {
	__HAL_RCC_USART1_CLK_ENABLE()
	;

	uart_handle.Instance = USART1;
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);
}

int main() {
	HAL_Init();
	SystemClock_Config();
	BSP_LED_Init(LED_GREEN);
	init_button();
	init_timer2();
	init_uart();
	init_user_button();

	while (1) {
		if (status == BASE_STATUS) {
			BSP_LED_On(LED_GREEN);
		}
	}

}

void EXTI9_5_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(external_button.Pin);
}

void TIM2_IRQHandler() {
	HAL_TIM_IRQHandler(&status_timer);
}
void EXTI15_10_IRQHandler(void) {
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	uint32_t current_time = HAL_GetTick();
	if (current_time - previous_button_press_time < 250) {
		return;
	}
	if (GPIO_Pin == external_button.Pin) {
		if (status == BASE_STATUS) {
			HAL_TIM_Base_Start_IT(&status_timer);
			status = FIRST_NUMBER;
			printf(
					"Press 1-5 times the blue button to get the first number!\r\n");
		}
	}
	if (status == FIRST_NUMBER) {
		if (GPIO_Pin == user_button_handle.Pin) {
			first_number++;
			printf("%d \r\n", first_number);
		}
	}
	if (status == OPERANDUS) {
		if (GPIO_Pin == user_button_handle.Pin) {
			operator++;
			if (operator == 1) {
				printf("MINUS\r\n");
			} else if (operator == 2) {
				printf("PLUS\r\n");
			} else {
				printf("ERROR, PRESS RESET\r\n");
				status = BASE_STATUS;
				HAL_TIM_Base_Stop_IT(&status_timer);

			}
		}
	}
	if (status == SECOND_NUMBER) {
		if (GPIO_Pin == user_button_handle.Pin) {
			second_number++;
			printf("%d \r\n", second_number);
		}
	}
	previous_button_press_time = current_time;

}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim->Instance == status_timer.Instance) {
		period_counter++;
		BSP_LED_Off(LED_GREEN);
		if (period_counter == 5) {
			status = OPERANDUS;
			printf("PRESS once to get (-) or twice to get (+) operator\r\n");
		}
		if (period_counter == 10) {
			status = SECOND_NUMBER;
			printf(
					"Press 1-5 times the blue button to get the second number!\r\n");

		}
		if (period_counter == 15) {
			status = RESULT;
			BSP_LED_Toggle(LED_GREEN);
			if (operator == 1) {
				result = first_number - second_number;
				printf("THE RESULT IS:%d\r\n", result);

			} else {
				result = first_number + second_number;
				printf("THE RESULT IS:%d\r\n", result);

			}
		}
		if (period_counter == 25) {
			status = BASE_STATUS;
			period_counter = 0;
			__HAL_TIM_SET_COUNTER(&status_timer, 0);
			printf("PRESS RESET!\r\n");

		}
	}
}
void Error_Handler(void) {
}

void SystemClock_Config(void) {
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
UART_PUTCHAR {
	HAL_UART_Transmit(&uart_handle, (uint8_t*) &ch, 1, 0xFFFF);
	return ch;
}