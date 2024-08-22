/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 20 Nov 2023                *****************/
/******* Version   : 0.2                        *****************/
/******* File Name : main.c                     *****************/
/****************************************************************/

/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL *****************************/
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "UART_interface.h"
#include "STK_interface.h"
/*****************************< HAL *****************************/
#include "LED.h"
/*****************************< APP *****************************/


/*****************************< The main objective from this project *****************************/
int main(void) 
{
	/*****************************< Local Variable section *****************************/
	u8 Local_ReceivedData[1] = {0};
	/*****************************< Init section *****************************/
	/**< Init the SysCLK */
	MCAL_RCC_InitSysClock();
	/**< Enable CLK for Peripherals */
	MCAL_RCC_EnablePeripheral(RCC_APB2, RCC_APB2ENR_IOPAEN);
	MCAL_RCC_EnablePeripheral(RCC_APB2, RCC_APB2ENR_USART1EN);
	/**< Init the TX, RX Pins */
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN9, GPIO_OUTPUT_PUSH_PULL_50MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN10, GPIO_INPUT_FLOATING);
	/**< Init the LED */
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN4, GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN1, GPIO_OUTPUT_PUSH_PULL_2MHZ);
	/**< Init the USART */
	USART_Config_t Local_Uart1 = {
		.HwFlowControl = UART_HW_FLOW_CONTROL_NONE,
		.BaudRate = UART_BAUD_RATE_9600,
		.ParityMode = UART_PARITY_NONE,
		.StopBits = UART_STOP_BITS_1,
		.WordLength = UART_WORD_LENGTH_8BIT
	};
	UART_Init(&Local_Uart1);
	/*****************************< Task section *****************************/
	for(;;)
	{
		UART_Receive(Local_ReceivedData, 1);
		if(Local_ReceivedData[0] == 'a')
		{
			MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN4, GPIO_HIGH);
		}
	}
}
