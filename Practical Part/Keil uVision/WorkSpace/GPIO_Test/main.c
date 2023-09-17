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
	
	/**< Set PIN0, PIN1, PIN2 In port A mode */
	
	Mcal_Gpio_SetPinMode(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT_PUSH_PULL_2MHZ);
	
	/**< Input Pull Up */
	Mcal_Gpio_SetPinMode(GPIO_PORTA, GPIO_PIN1, GPIO_INPUT_PULL_DOWN_MOD);
	Mcal_Gpio_SetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH);

	/**< Input Pull Down */
	Mcal_Gpio_SetPinMode(GPIO_PORTA, GPIO_PIN10, GPIO_INPUT_PULL_UP_MOD);
	Mcal_Gpio_SetPinValue(GPIO_PORTA, GPIO_PIN10, GPIO_LOW);

	u8 Local_ReturnValue_1;
	
	u8 Local_ReturnValue_2;

	
	for(;;)
	{
			Mcal_Gpio_GetPinValue(GPIO_PORTA, GPIO_PIN1, &Local_ReturnValue_1);

		
			Mcal_Gpio_GetPinValue(GPIO_PORTA, GPIO_PIN10, &Local_ReturnValue_2);
			
		
	}
}
