## Debounce

```c
// Declare two global variables
uint32_t last_debounce_time = 0;    // the last time the output pin was toggled
const uint32_t debounce_delay = 100;    // the debounce time in ms (increase if the output flickers)

//...

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    // Check if the time elapsed since the last valid button press is less than `debounce_delay`
    uint32_t current_time = HAL_GetTick();
    if (current_time < last_debounce_time + debounce_delay) {
        // Do nothing (this is not a real button press)
        return;
    }

    last_debounce_time = current_time;

    // Continue handling the interrupt
}