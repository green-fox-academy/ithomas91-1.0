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

   // Make the green user LED flashing with 2 Hz, but the
	//flashing should not begin until the user button is not pressed.
	//Once it is pushed, the LED should be blinking forever.


int main(void)
{
	HAL_Init();

	    BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

	    BSP_LED_Init(LED1);

	    int sum_press = 0;
	    int previous_status = 0;
	    int current_status = 0;


	    while (1) {

	        current_status = BSP_PB_GetState(BUTTON_KEY);

	        if(current_status == 1 && previous_status == 0) {
	        sum_press++;
	        }

	        previous_status = current_status;

	        if(sum_press >= 5)
	        BSP_LED_On(LED1);
	    }
}
