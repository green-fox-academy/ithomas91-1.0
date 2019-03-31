int _write(int file, char *ptr, int len)
{
	int DataIdx;

	for (DataIdx = 0; DataIdx < len; DataIdx++)
	{
		HAL_UART_Transmit(&UartHandle, (uint8_t*)&*ptr++, 1, 0xFFFF);
	}
	return len;
}
