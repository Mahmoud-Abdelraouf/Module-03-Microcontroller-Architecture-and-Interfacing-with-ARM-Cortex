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
	
	/***********************< LCD - 4-bit mode ***********************/
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
	/***********************< End of LCD - 4-bit mode ***********************/
	
	///***********************< LCD - 8-bit mode ***********************/
	LCD_Config_t lcd_2;
	lcd_2.mode = LCD_8BitMode;
	for(uint8_t i = 0; i < 8; i++) 
	{
		lcd_2.dataPins[i].LCD_PortId = LCD_PORTA; // Data Pins attached to Port A
		lcd_2.dataPins[i].LCD_PinId = 8 - i ; // 
	}
	
	lcd_2.enablePin.LCD_PortId = LCD_PORTA;
	lcd_2.enablePin.LCD_PinId = LCD_PIN9;
	
	lcd_2.rsPin.LCD_PortId = LCD_PORTA;
	lcd_2.rsPin.LCD_PinId = LCD_PIN10;
	/***********************< End of LCD - 8-bit mode ***********************/
	
	/*****************************< End Config of lcd *****************************/
	
	/**< Init the LCD */
	HAL_LCD_Init(&lcdConfig);
	/**< Print string */
	HAL_LCD_SendString(&lcdConfig, "IEEE ASUSB");
	HAL_LCD_GoToXYPos(&lcdConfig, 1, 0);
	HAL_LCD_SendNumber(&lcdConfig, 4);
	
	
	/**< Init the LCD */
	HAL_LCD_Init(&lcd_2);
	/**< Print string */
	HAL_LCD_SendString(&lcd_2, "Hello, From LCD 8-Bit mode");
	HAL_LCD_GoToXYPos(&lcd_2, 1, 0);
	HAL_LCD_SendNumber(&lcd_2, 8);
	
	
	for(;;);
}
