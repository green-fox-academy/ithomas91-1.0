
#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

GPIO_InitTypeDef push_button;
GPIO_InitTypeDef LEDS;

volatile int button_counter = 0;
volatile uint32_t start = 0;

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

	BSP_LED_Init(LED_GREEN);

	init_push_button();

	start = HAL_GetTick();

	while (1) {

	}

}

void EXTI9_5_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(push_button.Pin);

}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {

	if (GPIO_Pin == push_button.Pin) {

		if (HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_8) == 1) {

			if (HAL_GetTick() > 200 + start) {
				button_counter++;
				BSP_LED_Toggle(LED_GREEN);

				if (button_counter % 5 == 0) {

					HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_10);
				}
			}

		}
		start = HAL_GetTick();
	}
}
