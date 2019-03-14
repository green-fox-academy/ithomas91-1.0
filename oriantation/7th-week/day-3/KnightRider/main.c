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

    GPIO_InitTypeDef LEDS;
    HAL_Init();

    __HAL_RCC_GPIOF_CLK_ENABLE()
    ;

    LEDS.Pin = GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10;
    LEDS.Mode = GPIO_MODE_OUTPUT_PP;
    LEDS.Pull = GPIO_NOPULL;
    LEDS.Speed = GPIO_SPEED_HIGH;

    HAL_GPIO_Init(GPIOF, &LEDS);

    int change = 0;
    int counter = 0;

    /*0001
     0010
     0100
     1000
     0100
     0010
     0001*/

    int status[6] = { 1, 2, 3, 4, 5, 6};

    while (1) {

        for (int i = 0; i <= 6; i++) {
             if (status[i] == 6) {
                HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);
                HAL_Delay(100);
                HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
                HAL_Delay(100);

            } else if (status[i] == 5) {
                HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
                HAL_Delay(100);
                HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
                HAL_Delay(100);

            } else if (status[i] == 4) {

                HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
                HAL_Delay(75);
                HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
                HAL_Delay(75);

            } else if (status[i] == 3) {

                HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
                HAL_Delay(75);
                HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
                HAL_Delay(75);
            } else if (status[i] == 2) {

                HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);
                HAL_Delay(75);
                HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
                HAL_Delay(75);

            } else if (status[i] == 1) {

                HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);
                HAL_Delay(75);
                HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);
                HAL_Delay(75);
            }
        }
    }
}