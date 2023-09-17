/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 16 Sep 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : main.c                     *****************/
/****************************************************************/

/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL *****************************/
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
/*****************************< APP *****************************/
int main(void)
{
	/*****************************< Init Peripheral *****************************/
	/**< Init SysClk */
	MCAL_RCC_InitSysClock();
	
	/**< Enable the GPIOA */
	MCAL_RCC_EnablePeripheral(RCC_APB2, RCC_APB2ENR_IOPAEN);
	
	/**< Set the mode of the pin4 for gpio port A */
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN4, GPIO_OUTPUT_PUSH_PULL_2MHZ);
	
	/*****************************< Body of the project *****************************/
	while(1)
	{
		/*****************************< Main Function *****************************/
		/**< Set Pin value for Pin 4 in GPIO Port A to high */
		MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN4, GPIO_HIGH);
	
		/**< Set Delay  */
		STK_SetDelay_ms(500);
		
		/**< Set Pin value for Pin 4 in GPIO Port A to low */
		MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN4, GPIO_LOW);
		
		/**< Set Delay */
		STK_SetDelay_ms(500);
	}
}
