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

	    int n = 2000;
	    	while (1) {
	    		if (BSP_PB_GetState(BUTTON_KEY)) {
	    			while (1) {
	    				for (int i = 0; i < 3; i++) {
	    					BSP_LED_On(LED1);
	    					HAL_Delay(n);
	    					BSP_LED_Off(LED1);
	    					HAL_Delay(n);
	    				};

	    				for (int i = 0; i < 3; i++) {
	    					BSP_LED_On(LED1);
	    					HAL_Delay(n / 2);
	    					BSP_LED_Off(LED1);
	    					HAL_Delay(n / 2);
	    				};

	    				for (int i = 0; i < 3; i++) {
	    					BSP_LED_On(LED1);
	    					HAL_Delay(n / 4);
	    					BSP_LED_Off(LED1);
	    					HAL_Delay(n / 4);
	    				};

	    				for (int i = 0; i < 3; i++) {
	    					BSP_LED_On(LED1);
	    					HAL_Delay(n / 8);
	    					BSP_LED_Off(LED1);
	    					HAL_Delay(n / 8);
	    				};

	    				for (int i = 0; i < 3; i++) {
	    					BSP_LED_On(LED1);
	    					HAL_Delay(n / 4);
	    					BSP_LED_Off(LED1);
	    					HAL_Delay(n / 4);
	    				};

	    				for (int i = 0; i < 3; i++) {
	    					BSP_LED_On(LED1);
	    					HAL_Delay(n / 2);
	    					BSP_LED_Off(LED1);
	    					HAL_Delay(n / 2);
	    				};
	    			}
	    		}
	    	}
}


/*
 * 	int n = 2000;

	for (int j = 1; j < 5; j++) {
		for (int i = 0; i < 3; i++) {
			BSP_LED_On(LED1);
			HAL_Delay(n / j);
			BSP_LED_Off(LED1);
			HAL_Delay(n / j);
		}
	}

	for (int j = 3; j > 0; j--) {
		for (int i = 0; i < 3; i++) {
			BSP_LED_On(LED1);
			HAL_Delay(n / j);
			BSP_LED_Off(LED1);
			HAL_Delay(n / j);
		}
	}

	*/

 */

