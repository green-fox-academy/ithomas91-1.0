#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include <string.h>

UART_HandleTypeDef uart_Handle;

volatile char buffer;

void init_uart() {

	// First, Enable USART Clock
	__HAL_RCC_USART1_CLK_ENABLE();

	// Defining UART configuration structure

	uart_Handle.Instance = USART1;
	uart_Handle.Init.BaudRate = 115200;
	uart_Handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_Handle.Init.StopBits = UART_STOPBITS_1;
	uart_Handle.Init.Parity = UART_PARITY_NONE;
	uart_Handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_Handle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_Handle); // communication between PC and Board

	HAL_NVIC_SetPriority(USART1_IRQn, 3, 0);
	HAL_NVIC_EnableIRQ(USART1_IRQn);

}
int main() {
	HAL_Init();

	BSP_LED_Init(LED_GREEN);

	init_uart();

	HAL_UART_Receive_IT(&uart_Handle, &buffer, 1);

	while (1) {
	}

	return 0;
}

//Handler and Callback Initializition

void USART1_IRQHandler() {
	HAL_UART_IRQHandler(&uart_Handle);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart->Instance == USART1) {
		BSP_LED_Toggle(LED_GREEN);

		HAL_UART_Receive_IT(&uart_Handle, &buffer, 1);
	}
}
