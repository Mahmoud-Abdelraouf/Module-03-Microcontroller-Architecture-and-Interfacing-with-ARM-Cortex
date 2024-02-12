/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 10 Feb 2024                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : main.c                     *****************/
/****************************************************************/

/*****************************< LIB *****************************/
#include <string.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL *****************************/
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "UART_interface.h"
#include "FPEC_interface.h"
/*****************************< APP *****************************/
#include "Parse.h"
/*****************************< Business Logic *****************************/
uint8_t WriteReqFlag = 1;

char RecvBuffer[100];
uint8_t RecvCounter = 0;

typedef void (*Function_t)(void);
Function_t _fstAppAdd = 0;

void func(void) {
#define SCB_VTOR   (*((volatile u32*)0xE000ED08))

	SCB_VTOR = 0x08004800;

	_fstAppAdd = (*(Function_t *)(0x08004804));
	_fstAppAdd();
}

void main(void) {
	Std_ReturnType RecvStatus;

	/**< Init the SysClk */
	MCAL_RCC_InitSysClock();

	/**< Enable peripherals' clk */
	MCAL_RCC_EnablePeripheral(RCC_APB2, RCC_APB2ENR_USART1EN); /**< UART1 */
	MCAL_RCC_EnablePeripheral(RCC_APB2, RCC_APB2ENR_IOPAEN);   /**< PortA */
	MCAL_RCC_EnablePeripheral(RCC_AHB, RCC_AHBENR_FLITFEN);    /**< FPEC */

	/**< Set the mode of UART pins */
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN9, GPIO_OUTPUT_AFPP_2MHZ); /**< UART: TX  */
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN10, GPIO_INPUT_FLOATING);   /**< UART: RX */

	/**< Init the USART */
	USART_Config_t Local_Uart1 = {
		.BaudRate = USART_BAUD_RATE_9600,
		.ParityMode = USART_PARITY_NONE,
		.StopBits = USART_STOP_BITS_1,
		.WordLength = USART_WORD_LENGTH_8BIT
	};
	MCAL_USART_Init(&Local_Uart1);

	/**< Init the STK -> based on options in the config file */
	MCAL_STK_vInit();
	/**< wait 15msec before jump to the application */
	MCAL_STK_SetIntervalSingle(15000000, func);

	while(1) {
	    /**< Check if data has been received from the USART */
	    RecvStatus = MCAL_USART_Receive(&(RecvBuffer[RecvCounter]));

	    if (RecvStatus == E_OK) {
	        /**< Stop the timer as data is received */
	        MCAL_STK_Stop();

	        /**< Check if the received character is null terminator */
	        if(RecvBuffer[RecvCounter] == '\0') {
	            /**< Check if there is a write request pending */
	            if (WriteReqFlag == 1) {
	                /**< Erase the application area in the flash memory */
	                MCAL_FPEC_EraseAppArea();
	                WriteReqFlag = 0; /**< Reset write request flag */
	            }

	            /**< Parse the received HEX line */
	            parse_hex_line(RecvBuffer);

	            /**< Send acknowledgment 'ok' over USART */
	            MCAL_USART_Transmit("ok", strlen("ok"));

	            /**< Reset the receive counter for the next message */
	            RecvCounter = 0;
	        } else {
	            /**< Increment receive counter to receive the next character */
	            RecvCounter++;
	        }

	        /**< Restart the timer with a delay of 15,000,000 microseconds (15 seconds) */
	        MCAL_STK_SetIntervalSingle(15000000, func);
	    } else {
	        /**< No data received, handle this case later */
	        // TODO: Handle this case later
	    }
	}
}
