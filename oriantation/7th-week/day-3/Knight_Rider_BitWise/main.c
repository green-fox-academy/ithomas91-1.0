#include <stdlib.h>
#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

int main(void)
{
    GPIO_InitTypeDef LED;

    HAL_Init();

    __HAL_RCC_GPIOF_CLK_ENABE();

    LED.Pin = GPIO_PIN_10 | GPIO_PIN_9 | GPIO_PIN_8 | GPIO_PIN_7;
    LED.Mode = GPIO_MODE_OUTPUT_PP;
    LED.Pull = GPIO_NOPULL;
    LED.Speed = GPIO_SPEED_HIGH;

    HAL_GPIO_Init(GPIOF, &LED);

    int begin_status = 1000;

    While(1){

        for (int i = 0; i < sizeof(begin_status); ++i) {
            if(begin_status[i] == 1){

            }
        }

    }
}