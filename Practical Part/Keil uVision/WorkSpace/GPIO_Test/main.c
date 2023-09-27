/*********************< LIB *********************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*********************< MCAL *********************/
/**< MCAL_RCC interfacce file */
#include "RCC_interface.h"
/**< MCAL_GPIO interface file*/
#include "GPIO_interface.h"
/*********************< APP *********************/
int main(void)
{
	/**< Init for SYSCLK */
	Mcal_Rcc_InitSysClock();
	
	/**< Enable for wanted peripheral */
	Mcal_Rcc_EnablePeripheral(RCC_APB2,RCC_APB2ENR_IOPAEN);
	
	/**< Set PIN0, PIN1, PIN2 to be OUTPUT PUSH PULL with Freq = 2MHZ */
	Mcal_Gpio_SetPinMode(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT_PUSH_PULL_2MHZ);
	Mcal_Gpio_SetPinMode(GPIO_PORTA, GPIO_PIN4, GPIO_OUTPUT_PUSH_PULL_2MHZ);
	
	/**< Input Pull Up */
	Mcal_Gpio_SetPinMode(GPIO_PORTA, GPIO_PIN2, GPIO_INPUT_PULL_DOWN_MOD);
	Mcal_Gpio_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_HIGH);

	/**< Input Pull Down */
	Mcal_Gpio_SetPinMode(GPIO_PORTA, GPIO_PIN10, GPIO_INPUT_PULL_UP_MOD);
	Mcal_Gpio_SetPinValue(GPIO_PORTA, GPIO_PIN10, GPIO_LOW);

	/**< The Return Value of Push Button */
	u8 Local_ReturnValue_1;
	

	
	for(;;)
	{
		Mcal_Gpio_GetPinValue(GPIO_PORTA, GPIO_PIN2, &Local_ReturnValue_1);
		if(Local_ReturnValue_1 == 0)
		{
			Mcal_Gpio_SetPinValue(GPIO_PORTA, GPIO_PIN4, GPIO_HIGH);

		}	
	}
}
