/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 7 Dec 2023                 *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : CLCD_program.c             *****************/
/****************************************************************/

/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL *****************************/
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
/*****************************< HAL *****************************/
#include "CLCD_interface.h"
/*****************************< Main *****************************/
int main(void)
{
	/**< init the SYSCLK */
	MCAL_RCC_InitSysClock();
	
	/**< Init the CLK for the port A, B */
	MCAL_RCC_EnablePeripheral(RCC_APB2, RCC_APB2ENR_IOPAEN);
	MCAL_RCC_EnablePeripheral(RCC_APB2, RCC_APB2ENR_IOPBEN);	
	
	/*****************************< config the lcd *****************************/
	LCD_Config_t lcdConfig;
	
	lcdConfig.mode = LCD_4BitMode;
	for(uint8_t i = 0; i < 4; i++) 
	{
		lcdConfig.dataPins[i].LCD_PortId = LCD_PORTB; // Data Pins attached to Port A
		lcdConfig.dataPins[i].LCD_PinId = 15 - i ; // D4-->PB15, D5-->PB14, D6-->PB13, D7-->PB12
	}
	
	lcdConfig.enablePin.LCD_PortId = LCD_PORTA;
	lcdConfig.enablePin.LCD_PinId = LCD_PIN11;
	
	lcdConfig.rsPin.LCD_PortId = LCD_PORTA;
	lcdConfig.rsPin.LCD_PinId = LCD_PIN12;
	/*****************************< End Config of lcd *****************************/
	
	/**< Init the LCD */
	HAL_LCD_Init(&lcdConfig);
	/**< Print string */
	HAL_LCD_SendString(&lcdConfig, "IEEE ASUSB");
	HAL_LCD_GoToXYPos(&lcdConfig, 1, 0);
	HAL_LCD_SendNumber(&lcdConfig, 2.36);
	
	for(;;);
}
