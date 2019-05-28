#include "stm32f7xx_hal.h"

GPIO_InitTypeDef push_button_1;
GPIO_InitTypeDef push_button_2;

uint32_t last_debounce_time = 0;    
//const uint32_t debounce_delay = 100;   

void init_push_button_1() {
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	push_button_1.Pin = GPIO_PIN_8;
	push_button_1.Mode = GPIO_MODE_IT_RISING;
	push_button_1.Pull = GPIO_NOPULL;
	push_button_1.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &push_button_1);

	HAL_NVIC_SetPriority(EXTI9_5_IRQn, 1, 0);

	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
}

void init_push_button_2() {
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	push_button_2.Pin = GPIO_PIN_9;
	push_button_2.Mode = GPIO_MODE_IT_RISING;
	push_button_2.Pull = GPIO_NOPULL;
	push_button_2.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &push_button_2);

	HAL_NVIC_SetPriority(EXTI9_5_IRQn, 2, 0);

	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
}
int main(void)
{
    HAL_Init();

    SystemClock_Config();

    init_push_button_1();
    init_push_button_2();


    while (1)
    {
    }
}

void EXTI15_10_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(push_button_1.Pin);

}
	//Looking for weak function in there
	
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (GPIO_Pin == push_button_1.Pin) {
		uint32_t current_time = HAL_GetTick();
    if (current_time < last_debounce_time + debounce_delay) {
        
        return;
    }

    last_debounce_time = current_time;
	}
}

void EXTI15_10_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(push_button_2.Pin);

}


void SysTick_Handler(void)
{
    HAL_IncTick();
}

void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
    while (1)
    {
    }
}

void MemManage_Handler(void)
{
    while (1)
    {
    }
}

void BusFault_Handler(void)
{
    while (1)
    {
    }
}

void UsageFault_Handler(void)
{
    while (1)
    {
    }
}

void SVC_Handler(void)
{
}

void DebugMon_Handler(void)
{
}

void PendSV_Handler(void)
{
}