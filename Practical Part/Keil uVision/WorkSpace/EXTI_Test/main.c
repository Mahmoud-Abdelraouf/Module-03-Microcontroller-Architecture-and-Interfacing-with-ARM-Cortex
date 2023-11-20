/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 27 Sep 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : main.c                     *****************/
/****************************************************************/

/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**< MCAL */
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "AFIO_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"
/**< HAL */


/**< APP */
void APP_TogLED(void);
void APP_OpenDoor(void);



int main(void)
{
	int x = 5;
	/**< Init SYSCLK */
	MCAL_RCC_InitSysClock();
	
	/**< Enable AFIO */
	MCAL_RCC_EnablePeripheral(RCC_APB2, RCC_APB2ENR_AFIOEN);
	/**< Enable Port A */
	MCAL_RCC_EnablePeripheral(RCC_APB2, RCC_APB2ENR_IOPAEN);
	
	/**< Set Pin 0 Mode to be Input Pull-Down -> Push Button*/
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN0, GPIO_INPUT_PULL_DOWN);
	/**< Set Pin 2 Mode to be Output Push-Pull -> LED */
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN2, GPIO_OUTPUT_PUSH_PULL_2MHZ);

	/**< Enable NVIC Bit for EXTI0 */
	MCAL_NVIC_EnableIRQ(NVIC_EXTI0_IRQn);
	
	/**< Select PA0 to work as EXTI of line 0 */
	EXTI_InitEXTIForGPIO(GPIO_PIN0, GPIO_PORTA);
	
	/**< Set EXTI Line 0 to to be Rising Edge sensitive */
	EXTI_SetTrigger(EXTI_LINE0, EXTI_RISING_EDGE);
	
	/**< Enable EXTI0 */
	EXTI_EnableLine(EXTI_LINE0);
	
	/**< Set callback Fucntion */
	MCAL_EXTI_SetCallback(APP_TogLED);
	
	
	
	while(1)
	{
			
	}
	
}

void APP_TogLED(void)
{
	static u8 Temp = 0;
	if(Temp == 0)
	{
		MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_HIGH);
		Temp = 1;
	}
	else
	{
		MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_LOW);
		Temp = 0;
	}
}
