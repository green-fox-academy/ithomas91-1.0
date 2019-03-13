

// EXTERNAL PUSH BUTTON DEFINTION ************************

GPIO_InitTypeDef push_button;

void init_push_button() {
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	push_button.Pin = GPIO_PIN_8;
	push_button.Mode = GPIO_MODE_IT_RISING;
	push_button.Pull = GPIO_NOPULL;
	push_button.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &push_button);

	HAL_NVIC_SetPriority(EXTI9_5_IRQn, 1, 0);

	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
}

int main(void) {
	HAL_Init();

	init_push_button();

	while (1) {

	}

}

//**********************************************************

// LEDS DEFINITION *****************************************

void init_LEDS() {
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	LEDS.Pin = GPIO_PIN_10;
	LEDS.Mode = GPIO_MODE_OUTPUT_PP;
	LEDS.Pull = GPIO_NOPULL;
	LEDS.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &LEDS);

}

int main(void) {
	HAL_Init();

	init_LEDS();

	 // BSP_LED_Init(LED_GREEN);

	while (1) {

	}

}

//*********************************************************