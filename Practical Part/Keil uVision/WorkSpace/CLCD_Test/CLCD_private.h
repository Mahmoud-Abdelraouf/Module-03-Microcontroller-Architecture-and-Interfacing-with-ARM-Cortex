/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 16 Sep 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : CLCD_private.h             *****************/
/****************************************************************/

#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H


/**
 * @brief Offset for DDRAM addresses in the second row of a 2-row display.
 */
#define DDRAM_ADDRESS_OFFSET                   0x40

/**
 * @brief Commands for LCD in 8-bit mode.
 */
#define LCD_8BIT_MODE_COMMAND                  0x38
#define LCD_DISPLAY_ON_COMMAND                 0x0C
#define LCD_CLEAR_COMMAND                      0x01

/**
 * @brief Commands for initializing LCD in 4-bit mode.
 */
#define LCD_4BIT_MODE_COMMAND_1                0x33
#define LCD_4BIT_MODE_COMMAND_2                0x32
#define LCD_4BIT_MODE_COMMAND_3                0x28


/**< Private function prototypes */ 
/**
 * @brief Sends 4-bit data to the LCD.
 *
 * This function sends a 4-bit command or data to the LCD module using the 4-bit mode
 * based on the provided configuration and value. It sequentially sets the 4 data pins
 * (4 most significant bits first) to transmit the specified value to the LCD.
 *
 * @param[in] config Pointer to the LCD configuration structure.
 * @param[in] value The 4-bit value to be sent to the LCD.
 * @note This function assumes that the required GPIO and timing functions have been initialized separately.
 */
static void HAL_LCD_Send4Bits(const LCD_Config_t *config, uint8_t value);

/**
 * @brief Sends 8-bit data to the LCD.
 *
 * This function sends an 8-bit command or data to the LCD module based on the provided
 * configuration and value. It sequentially sets the 8 data pins to transmit the specified
 * value to the LCD.
 *
 * @param[in] config Pointer to the LCD configuration structure.
 * @param[in] value The 8-bit value to be sent to the LCD.
 * @note This function assumes that the required GPIO and timing functions have been initialized separately.
 */
static void HAL_LCD_Send8Bits(const LCD_Config_t *config, uint8_t value);


#endif /**< LCD_PRIVATE_H */