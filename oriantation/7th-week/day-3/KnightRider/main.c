/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

int main(void) {
	/* create a config structure */
	GPIO_InitTypeDef LEDS;
	HAL_Init();

	/* we need to enable the GPIOA port's clock first */
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	LEDS.Pin = GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10;
	LEDS.Mode = GPIO_MODE_OUTPUT_PP; /* configure as output, in push-pull mode */
	LEDS.Pull = GPIO_NOPULL; /* we don't need internal pull-up or -down resistor */
	LEDS.Speed = GPIO_SPEED_HIGH; /* we need a high-speed output */

	HAL_GPIO_Init(GPIOF, &LEDS); /* initialize the pin on GPIOF port */

	int change = 0;
	int counter = 0;

	/*0001
	 0010
	 0100
	 1000
	 0100
	 0010
	 0001*/

	int status[4] = { 1, 2, 3, 4 };

	while (1) {
		/*for (int i = 3; i >= 0; i--) {
		 if (status[i] == 1) {
		 HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);

		 } else if (status[i] == 2) {
		 HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
		 HAL_Delay(150);
		 HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
		 HAL_Delay(150);

		 } else if (status[i] == 3) {
		 HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
		 HAL_Delay(75);
		 HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);
		 HAL_Delay(150);

		 } else if (status[i] == 4) {
		 HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
		 HAL_Delay(75);
		 HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);
		 }
		 }*/
		for (int i = 0; i < 3; i++) {
			if (status[i] == 4) {
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);
				HAL_Delay(150);

			} else if (status[i] == 3) {
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);
				HAL_Delay(150);
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);
				HAL_Delay(150);

			} else if (status[i] == 2) {
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
				HAL_Delay(75);
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
				HAL_Delay(150);

			} else if (status[i] == 1) {
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
				HAL_Delay(75);
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
			}
		}
	}
}
