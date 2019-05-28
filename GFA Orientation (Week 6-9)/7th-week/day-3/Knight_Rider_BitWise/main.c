GPIO_InitTypeDef LEDS;

int main(void) {

	HAL_Init();

	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	LEDS.Pin = GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10;
	LEDS.Mode = GPIO_MODE_OUTPUT_PP;
	LEDS.Pull = GPIO_NOPULL;
	LEDS.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &LEDS);

	/*	 0001  	1
	 	 0010	2
	 	 0100	4
	 	 1000	8
	 	 0100	4
		 0010	2
	 	 0001	1     */

	uint16_t led_state = 1;
	uint16_t pin_number = GPIO_PIN_7;

	while (1) 
	{

		for (int i = 1; i <= 3; ++i) {
			HAL_GPIO_WritePin(GPIOF, pin_number, led_state);
			HAL_Delay(60);
			HAL_GPIO_WritePin(GPIOF, pin_number, GPIO_PIN_RESET);

			pin_number = pin_number << 1;
			led_state = led_state << 1;

		}
		for (int i = 3; i >= 1; --i) {
			HAL_GPIO_WritePin(GPIOF, pin_number, led_state);

			HAL_Delay(60);
			HAL_GPIO_WritePin(GPIOF, pin_number, GPIO_PIN_RESET);
			pin_number = pin_number >> 1;
			led_state = led_state >> 1;
		}
	}
}
