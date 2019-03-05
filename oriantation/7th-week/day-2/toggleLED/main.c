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

//Toggle the green user LED with the blue user button switch, so the LED
//should be turned on to a push, and then off to another push, and so on.
int main(void)
{
    HAL_Init();
    BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
//
    BSP_LED_Init(LED1);
    int button_status = 0;
    int previous_button_status = 0;
    while (1) {
    	button_status = !BSP_PB_GetState(BUTTON_KEY);
    	if(button_status == 0 && previous_button_status == 1){
    		BSP_LED_Toggle(LED1);
    	}
    	previous_button_status = button_status;
    }
}
