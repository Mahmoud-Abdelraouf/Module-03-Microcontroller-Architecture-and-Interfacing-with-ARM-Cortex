/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 16 Sep 2023                *****************/
/******* Version   : 0.2                        *****************/
/******* File Name : CLCD_interface             *****************/
/****************************************************************/
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

/*****************************< Commands for initializing LCD. *****************************/
#define _LCD_CLEAR                      0X01  // Clears the display.
#define _LCD_RETURN_HOME                0x02  // Returns cursor to home position.
#define _LCD_ENTRY_MODE_DEC_SHIFT_OFF   0x04  // Sets entry mode to decrement cursor position without display shift.
#define _LCD_ENTRY_MODE_DEC_SHIFT_ON    0x05  // Sets entry mode to decrement cursor position with display shift.
#define _LCD_ENTRY_MODE_INC_SHIFT_OFF   0x06  // Sets entry mode to increment cursor position without display shift.

#define _LCD_ENTRY_MODE_INC_SHIFT_ON    0x07  // Sets entry mode to increment cursor position with display shift.
#define _LCD_CURSOR_MOVE_SHIFT_LEFT     0x10  // Moves cursor/display left without changing DDRAM address.
#define _LCD_CURSOR_MOVE_SHIFT_RIGHT    0x14  // Moves cursor/display right without changing DDRAM address.
#define _LCD_DISPLAY_SHIFT_LEFT         0x18  // Shifts the display to the left.
#define _LCD_DISPLAY_SHIFT_RIGHT        0x1C  // Shifts the display to the right.
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF 0x0C  // Display on, cursor off, and underline off.
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON  0x0D  // Display on, cursor on, and underline off.
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF  0x0E  // Display on, cursor off, and underline on.
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON   0x0F  // Display on, cursor on, and underline on.
#define _LCD_DISPLAY_OFF_CURSOR_OFF              0x08  // Display off and cursor off.
#define _LCD_8BIT_MODE_2_LINE           0x38  // Sets 8-bit data mode with 2 display lines.
#define _LCD_4BIT_MODE_2_LINE           0x28  // Sets 4-bit data mode with 2 display lines.

#define _LCD_CGRAM_START                0x40  // Start address for Character Generator RAM (CGRAM) in the LCD.
#define _LCD_DDRAM_START                0x80  // Start address for Display Data RAM (DDRAM) in the LCD.
/*****************************< End of Commands *****************************/

/**
 * @brief Enum defining different port configurations for the LCD.
 */
typedef enum {
    LCD_PORTA,  /**< Port A */
    LCD_PORTB,  /**< Port B */
    LCD_PORTC   /**< Port C */
} LCD_Port_t;

/**
 * @brief Enum defining different pin configurations for the LCD.
 */
typedef enum {
    LCD_PIN0,   /**< Pin 0 */
    LCD_PIN1,   /**< Pin 1 */
    LCD_PIN2,   /**< Pin 2 */
    LCD_PIN3,   /**< Pin 3 */
    LCD_PIN4,   /**< Pin 4 */
    LCD_PIN5,   /**< Pin 5 */
    LCD_PIN6,   /**< Pin 6 */
    LCD_PIN7,   /**< Pin 7 */
    LCD_PIN8,   /**< Pin 8 */
    LCD_PIN9,   /**< Pin 9 */
    LCD_PIN10,  /**< Pin 10 */
    LCD_PIN11,  /**< Pin 11 */
    LCD_PIN12,  /**< Pin 12 */
    LCD_PIN13,  /**< Pin 13 */
    LCD_PIN14,  /**< Pin 14 */
    LCD_PIN15   /**< Pin 15 */
} LCD_Pin_t;

/**
 * @brief Enum defining LCD operation modes.
 */
typedef enum {
    LCD_4BitMode = 4,   /**< 4-bit mode */
    LCD_8BitMode = 8  /**< 8-bit mode */
} LCD_Mode_t;

/**
 * @brief Structure representing LCD pin configuration.
 */
typedef struct {
    uint8_t LCD_PortId: 2;  /**< Port ID for the LCD pin */
    uint8_t LCD_PinId: 4;   /**< Pin ID for the LCD pin */
    uint8_t :2;             /**< Padding */
} LCD_PinConfig_t;

/**
 * @brief Structure representing LCD configuration.
 */
typedef struct {
    uint8_t mode;                 /**< 8-bit or 4-bit mode indicator */
    LCD_PinConfig_t dataPins[8]; /**< Maximum pins for 8-bit mode */
    LCD_PinConfig_t rsPin;       /**< RS pin */
    LCD_PinConfig_t rwPin;       /**< R/W pin */
    LCD_PinConfig_t enablePin;   /**< Enable pin */
} LCD_Config_t;

/**< Public function prototypes */ 
/**
 * @brief Initializes the LCD module based on the provided configuration.
 *
 * This function initializes the LCD module based on the specified configuration. It checks
 * the mode set in the configuration (either 4-bit mode or 8-bit mode) and initializes the
 * necessary pins accordingly. It sends commands for setting up the display, clearing the screen,
 * and turning on the display.
 *
 * @param[in] config Pointer to the LCD configuration structure.
 * @note This function assumes that the required GPIO and STK (delay) modules have been initialized separately.
 * @warning Passing a NULL pointer as config will result in no action.
 */
void HAL_LCD_Init(const LCD_Config_t *config);

/**
 * @brief Sends a command to the LCD module.
 *
 * This function sends a command to the LCD module based on the provided configuration.
 * It sets the RS pin to low for command mode and the RW pin to low for write operation.
 * Depending on the configured mode (4-bit or 8-bit), it calls the corresponding function
 * to send the command.
 *
 * @param[in] config Pointer to the LCD configuration structure.
 * @param[in] command The command to be sent to the LCD.
 * @note This function assumes that the required GPIO module has been initialized separately.
 * @warning If the mode in the configuration is neither 4-bit nor 8-bit, the function returns without action.
 */
void HAL_LCD_SendCommand(const LCD_Config_t *config, uint8_t command);

/**
 * @brief Sends a character to the LCD module for display.
 *
 * This function sends a character to the LCD module based on the provided configuration.
 * It sets the RS pin to high for data mode and the RW pin to low for write operation.
 * Depending on the configured mode (4-bit or 8-bit), it calls the corresponding function
 * to send the character.
 *
 * @param[in] config Pointer to the LCD configuration structure.
 * @param[in] character The character to be sent to the LCD for display.
 * @note This function assumes that the required GPIO module has been initialized separately.
 * @warning If the mode in the configuration is neither 4-bit nor 8-bit, the function returns without action.
 */
void HAL_LCD_SendChar(const LCD_Config_t *config, uint8_t character);

/**
 * @brief Sends a null-terminated string to the LCD for display.
 *
 * This function sends a null-terminated string to the LCD module for display
 * based on the provided configuration. It iterates through the characters of
 * the string and sends each character to the LCD using the LCD_SendChar function.
 *
 * @param[in] config Pointer to the LCD configuration structure.
 * @param[in] string Pointer to the null-terminated string to be displayed on the LCD.
 * @note This function assumes that the required GPIO module and LCD character functions have been initialized separately.
 */
void HAL_LCD_SendString(const LCD_Config_t *config, const uint8_t *string);

/**
 * @brief Displays a double-precision floating-point number on the LCD.
 *
 * This function displays a double-precision floating-point number on the LCD based on
 * the provided configuration. It separates the integer and fractional parts of the number,
 * displays the integer part directly, and then displays the fractional part with three decimal
 * places using LCD_SendChar function.
 *
 * @param[in] config Pointer to the LCD configuration structure.
 * @param[in] number The double-precision floating-point number to be displayed on the LCD.
 * @note This function assumes that the required LCD character functions have been initialized separately.
 */
void HAL_LCD_SendNumber(const LCD_Config_t *config, double number);

/**
 * @brief Displays the integer part of a signed integer on the LCD.
 *
 * This function displays the integer part of a signed integer value on the LCD based on
 * the provided configuration. It separates the digits of the integer part and displays
 * them sequentially using the LCD_SendChar function.
 *
 * @param[in] config Pointer to the LCD configuration structure.
 * @param[in] number The signed integer value whose integer part is to be displayed on the LCD.
 * @note This function assumes that the required LCD character functions have been initialized separately.
 */
void HAL_LCD_SendIntegerPart(const LCD_Config_t *config, s32 number);

/**
 * @brief Clears the display of the LCD.
 *
 * This function sends a command to the LCD module based on the provided configuration
 * to clear the display content and reset the cursor to the home position (the first row
 * and the first column).
 *
 * @param[in] config Pointer to the LCD configuration structure.
 * @note This function assumes that the required LCD command functions have been initialized separately.
 */
void HAL_LCD_Clear(const LCD_Config_t *config);

/**
 * @brief Moves the cursor of the LCD to a specific position.
 *
 * This function moves the cursor of the LCD module based on the provided coordinates
 * (x and y) within the screen bounds specified by the LCD configuration.
 *
 * @param[in] config Pointer to the LCD configuration structure.
 * @param[in] x The x-coordinate (row) on the LCD (0 or 1 for a two-row display).
 * @param[in] y The y-coordinate (column) on the LCD (0 to 15 for a 16-column display).
 * @note This function assumes that the required LCD command functions have been initialized separately.
 */
void HAL_LCD_GoToXYPos(const LCD_Config_t *config, uint8_t x, uint8_t y);

#endif /* LCD_DRIVER_H */
