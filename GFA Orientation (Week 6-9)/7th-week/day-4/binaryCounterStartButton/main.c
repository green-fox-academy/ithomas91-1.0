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

/* create a config structure */
GPIO_InitTypeDef LEDS;
GPIO_InitTypeDef push_button;


int main(void)
{
    HAL_Init();

    /* we need to enable the GPIOA port's clock first */
    __HAL_RCC_GPIOF_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();


    LEDS.Pin = GPIO_PIN_10 | GPIO_PIN_9 | GPIO_PIN_8 | GPIO_PIN_7;
    LEDS.Mode = GPIO_MODE_OUTPUT_PP;
    LEDS.Pull = GPIO_NOPULL;
    LEDS.Speed = GPIO_SPEED_HIGH;

    HAL_GPIO_Init(GPIOF, &LEDS);

    	push_button.Pin = GPIO_PIN_4;
        push_button.Mode = GPIO_MODE_INPUT;
        push_button.Pull = GPIO_NOPULL;
        push_button.Speed = GPIO_SPEED_HIGH;

        HAL_GPIO_Init(GPIOF, &push_button);

    while (1) {
    	if (HAL_GPIO_ReadPin(GPIOB, push_button.Pin)) {
			for	(unsigned int i = 0; i < 16; i++){
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, ((((i / 2) / 2) /2)%2));
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, (((i / 2) / 2) %2));
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, ((i / 2)%2));
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, (i % 2));
				HAL_Delay(500);
			}
    	}
    }
}
