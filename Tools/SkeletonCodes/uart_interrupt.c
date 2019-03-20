void init_uart()
{
	__HAL_RCC_USART1_CLK_ENABLE();

	/* defining the UART configuration structure */
	uart_handle.Instance = USART1;
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);

	HAL_NVIC_SetPriority(USART1_IRQn, 3, 0);
	HAL_NVIC_EnableIRQ(USART1_IRQn);
}

int main()
{
	HAL_Init();

	BSP_LED_Init(LED_GREEN);
	init_user_button();
	init_uart();

	HAL_UART_Receive_IT(&uart_handle, &buffer, 1);

	while (1) {
	}

	return 0;
}


void USART1_IRQHandler()
{
	HAL_UART_IRQHandler(&uart_handle);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart->Instance == USART1) {
		BSP_LED_Toggle(LED_GREEN);

		HAL_UART_Receive_IT(&uart_handle, &buffer, 1);
	}
}