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
	
	
	
	MCAL_NVIC_xSetPriority(35, 10);
	
	MCAL_NVIC_SetPendingIRQ(35);
	
	
	
	MCAL_NVIC_ClearPendingIRQ(35);

	
	MCAL_NVIC_DisableIRQ(35);
	
	MCAL_NVIC_EnableIRQ(36);
	
	MCAL_NVIC_xSetPriority(35, 8);


	
	while(1)
	{
		/**< Body */
		
		
		
	}
}
