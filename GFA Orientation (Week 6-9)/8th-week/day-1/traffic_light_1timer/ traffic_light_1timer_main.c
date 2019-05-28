#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#define UART_PUTCHAR int __io_putchar(int ch)

UART_HandleTypeDef UartHandle;

/* the timer's config structure */
TIM_HandleTypeDef TimHandle2;
TIM_HandleTypeDef TimHandle3;
TIM_HandleTypeDef TimHandle4;

uint16_t tim_val = 0;/* variable to store the actual value of the timer's register (CNT) */
uint16_t seconds = 0; /* variable to store the value of ellapsed seconds */

static void Error_Handler(void);
static void SystemClock_Config(void);

int main(void) {
	HAL_Init();
	GPIO_InitTypeDef LEDS;

	/* this function call sets the timers input clock to 108 Mhz (=108000000 Hz) */
	SystemClock_Config();

	__HAL_RCC_USART1_CLK_ENABLE()
	;
	UartHandle.Instance = USART1;
	UartHandle.Init.BaudRate = 115200;
	UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
	UartHandle.Init.StopBits = UART_STOPBITS_1;
	UartHandle.Init.Parity = UART_PARITY_NONE;
	UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	UartHandle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &UartHandle);
	/* we need to enable the TIM2 */
	__HAL_RCC_TIM2_CLK_ENABLE()
	;

	TimHandle2.Instance = TIM2;
	TimHandle2.Init.Prescaler = 54000 - 1; /* 108000000/54000=20000 -> speed of 1 count-up: 1/10000 sec = 0.5 ms */
	TimHandle2.Init.Period = 24000 - 1; /* 10000 x 0.1 ms = 1 second period */
	TimHandle2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TimHandle2.Init.CounterMode = TIM_COUNTERMODE_UP;

	/* configure the timer */
	HAL_TIM_Base_Init(&TimHandle2);

	/* starting the timer */
	HAL_TIM_Base_Start(&TimHandle2);

	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	LEDS.Pin = GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10;
	LEDS.Mode = GPIO_MODE_OUTPUT_PP; /* configure as output, in push-pull mode */
	LEDS.Pull = GPIO_NOPULL; /* we don't need internal pull-up or -down resistor */
	LEDS.Speed = GPIO_SPEED_HIGH; /* we need a high-speed output */

	HAL_GPIO_Init(GPIOF, &LEDS); /* initialize the pin on GPIOF port */

	int start = 0;
	int end = 0;

	while (1) {

		tim_val = __HAL_TIM_GET_COUNTER(&TimHandle2);

		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, tim_val > 0 && tim_val < 12000);// Red light
		start = HAL_GetTick();
		printf("Red light on\n");

		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9,
				tim_val > 8000 && tim_val < 12000
						|| tim_val > 18000 && tim_val < 0);	//Amber light in 2 position
		printf("Amber light on\n");

		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9,
				tim_val > 12000 && tim_val < 18000); //Green light
		printf("Green light on\n");
		end = HAL_GetTick();
		int result = end - start;
		printf("%d\n", result);

	}
}
static void Error_Handler(void) {
}

static void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/**Configure the main internal regulator output voltage */
	__HAL_RCC_PWR_CLK_ENABLE()
	;
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 216;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 2;

	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/**Activate the Over-Drive mode */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}

UART_PUTCHAR {
	HAL_UART_Transmit(&UartHandle, (uint8_t*) &ch, 1, 0xFFFF);
	return ch;
}