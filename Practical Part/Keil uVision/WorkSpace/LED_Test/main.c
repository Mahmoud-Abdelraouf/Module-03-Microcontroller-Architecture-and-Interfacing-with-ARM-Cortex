/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**< MCAL */
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "AFIO_interface.h"
/**< HAL */
#include "LED.h"
/**< APP */
int main(void)
{
	/*****************************< Void Setup *****************************/
	/**< Init SysCLK */
	MCAL_RCC_InitSysClock();
	/**< Enable Peripheral */
	MCAL_RCC_EnablePeripheral(RCC_APB2, RCC_APB2ENR_IOPAEN);
	MCAL_RCC_EnablePeripheral(RCC_APB2, RCC_APB2ENR_IOPBEN);
	MCAL_RCC_EnablePeripheral(RCC_APB2, RCC_APB2ENR_AFIOEN);
	/**< Remap PA14 to be DIO */
	MCAL_AFIO_SetRemap(AFIO_REMAP_PARTIAL);
	/**< Init LED */
	HAL_LED_Init(GPIO_PORTA, GPIO_PIN4);
	HAL_LED_Init(GPIO_PORTA, GPIO_PIN5);
	HAL_LED_Init(GPIO_PORTB, GPIO_PIN7);
	/*****************************< Void Loop *****************************/
	for(;;)
	{
		HAL_LED_BlinkOnce(GPIO_PORTA, GPIO_PIN4, 500);
		
		HAL_LED_BlinkOnce(GPIO_PORTA, GPIO_PIN5, 1000);
		
		HAL_LED_BlinkOnce(GPIO_PORTB, GPIO_PIN7, 1500);

	
	}
}