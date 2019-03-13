#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

GPIO_InitTypeDef user_button_handle;

volatile int counter = 0;

void init_user_button()  // Function of User Push Button (Blue)
{
	// Initialize the user push button (Blue)
	__HAL_RCC_GPIOI_CLK_ENABLE()
	;

	user_button_handle.Pin = GPIO_PIN_11;
	user_button_handle.Pull = GPIO_NOPULL;
	user_button_handle.Speed = GPIO_SPEED_FAST;
	user_button_handle.Mode = GPIO_MODE_IT_RISING; // IT LIKE INTERRUPT, Generate rising endge of signal

	HAL_GPIO_Init(GPIOI, &user_button_handle);

	// Priority of the interrupt, we have to set it!
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 4, 0);

	// Enable interrupt
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

int main(void) {

	HAL_Init();

	BSP_LED_Init(LED_GREEN);
	init_user_button();

	while (1) {
	}

	return 0;
}
	// 
void EXTI15_10_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(user_button_handle.Pin);

}
	//Looking for weak function in there
	
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (GPIO_Pin == user_button_handle.Pin) {
		counter++;

		BSP_LED_Toggle(LED_GREEN);
	}
}

