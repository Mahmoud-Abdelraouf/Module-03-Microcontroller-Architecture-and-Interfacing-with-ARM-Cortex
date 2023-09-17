/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 10 Sep 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* SWM       : APP                        *****************/
/******* File Name : main.c                     *****************/
/****************************************************************/
/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**< MCAL */
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
/**< HAL */

/**< APP */




int main(void)
{
	/**< init */
	MCAL_RCC_InitSysClock();

	MCAL_RCC_EnablePeripheral(RCC_APB2, RCC_APB2ENR_IOPAEN);
	
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN1, GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN2, GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN3, GPIO_OUTPUT_PUSH_PULL_2MHZ);

	
	MCAL_NVIC_EnableIRQ(6);
	MCAL_NVIC_EnableIRQ(7);
		
	MCAL_NVIC_vSetPriority(7,0,3);
	
	MCAL_NVIC_vSetPriority(6,3,0);
	
	MCAL_NVIC_SetPendingIRQ(6);
	
	
	
	while(1)
	{
		/**< Body */
		
		
		
	}
}



void EXTI0_IRQHandler(void)
{
	MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH);
	MCAL_NVIC_SetPendingIRQ(7);
	MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_HIGH);
}

void EXTI1_IRQHandler(void)
{
		MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_HIGH);
}

