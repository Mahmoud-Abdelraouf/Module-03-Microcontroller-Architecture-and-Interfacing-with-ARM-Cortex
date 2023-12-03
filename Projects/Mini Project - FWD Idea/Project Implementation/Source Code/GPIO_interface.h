/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 29 Aug 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : GPIO_interface.h           *****************/
/****************************************************************/
#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/**
 * @defgroup GPIO_Configuration GPIO Configuration
 * @brief Macros and definitions for configuring GPIO pins.
 * @{
 */

/**
 * @defgroup GPIO_Port GPIO Port Definitions
 * @brief Definitions for GPIO port indices.
 * @{
 */
#define GPIO_PORTA          0 /**< GPIO Port A */
#define GPIO_PORTB          1 /**< GPIO Port B */
#define GPIO_PORTC          2 /**< GPIO Port C */
/** @} */

/**
 * @defgroup GPIO_Values GPIO Values
 * @brief Values to represent the logical state of GPIO pins.
 * @{
 */
#define GPIO_LOW            0   /**< GPIO Low value */
#define GPIO_HIGH           1   /**< GPIO High value */
/** @} */ // End of GPIO_Values group


/**
 * @defgroup GPIO_Pin GPIO Pin Definitions
 * @brief Definitions for GPIO pin indices.
 * @{
 */
#define GPIO_PIN0           0  /**< GPIO Pin 0 */
#define GPIO_PIN1           1  /**< GPIO Pin 1 */
#define GPIO_PIN2           2  /**< GPIO Pin 2 */
#define GPIO_PIN3           3  /**< GPIO Pin 3 */
#define GPIO_PIN4           4  /**< GPIO Pin 4 */
#define GPIO_PIN5           5  /**< GPIO Pin 5 */
#define GPIO_PIN6           6  /**< GPIO Pin 6 */
#define GPIO_PIN7           7  /**< GPIO Pin 7 */
#define GPIO_PIN8           8  /**< GPIO Pin 8 */
#define GPIO_PIN9           9  /**< GPIO Pin 9 */
#define GPIO_PIN10          10 /**< GPIO Pin 10 */
#define GPIO_PIN11          11 /**< GPIO Pin 11 */
#define GPIO_PIN12          12 /**< GPIO Pin 12 */
#define GPIO_PIN13          13 /**< GPIO Pin 13 */
#define GPIO_PIN14          14 /**< GPIO Pin 14 */
#define GPIO_PIN15          15 /**< GPIO Pin 15 */
/** @} */

/**
 * @defgroup GPIO_InputModes GPIO Input Modes
 * @brief Definitions for different GPIO input modes.
 * @{
 */
#define GPIO_INPUT_ANALOG_MOD                    0b0000 /**< GPIO Input Analog Mode */
#define GPIO_INPUT_FLOATING_MOD                  0b0100 /**< GPIO Input Floating Mode */
#define GPIO_INPUT_PULL_DOWN_MOD                 0b1000 /**< GPIO Input Pull down Mode */
#define GPIO_INPUT_PULL_UP_MOD                   0b1000 /**< GPIO Input Pull up Mode */
/** @} */

/**
 * @defgroup GPIO_OutputModes GPIO Output Modes
 * @brief Definitions for different GPIO output modes.
 * @{
 */
#define GPIO_OUTPUT_PUSH_PULL_10MHZ              0b0001 /**< GPIO Output Push-Pull Mode, 10MHz */
#define GPIO_OUTPUT_OPEN_DRAIN_10MHZ             0b0101 /**< GPIO Output Open-Drain Mode, 10MHz */
#define GPIO_OUTPUT_AF_PUSH_PULL_10MHZ           0b1001 /**< GPIO Output Alternate Function Push-Pull Mode, 10MHz */
#define GPIO_OUTPUT_AF_OPEN_DRAIN_10MHZ          0b1101 /**< GPIO Output Alternate Function Open-Drain Mode, 10MHz */

#define GPIO_OUTPUT_PUSH_PULL_2MHZ               0b0010 /**< GPIO Output Push-Pull Mode, 2MHz */
#define GPIO_OUTPUT_OPEN_DRAIN_2MHZ              0b0110 /**< GPIO Output Open-Drain Mode, 2MHz */
#define GPIO_OUTPUT_AF_PUSH_PULL_2MHZ            0b1010 /**< GPIO Output Alternate Function Push-Pull Mode, 2MHz */
#define GPIO_OUTPUT_AF_OPEN_DRAIN_2MHZ           0b1110 /**< GPIO Output Alternate Function Open-Drain Mode, 2MHz */

#define GPIO_OUTPUT_PUSH_PULL_50MHZ              0b0011 /**< GPIO Output Push-Pull Mode, 50MHz */
#define GPIO_OUTPUT_OPEN_DRAIN_50MHZ             0b0111 /**< GPIO Output Open-Drain Mode, 50MHz */
#define GPIO_OUTPUT_AF_PUSH_PULL_50MHZ           0b1011 /**< GPIO Output Alternate Function Push-Pull Mode, 50MHz */
#define GPIO_OUTPUT_AF_OPEN_DRAIN_50MHZ          0b1111 /**< GPIO Output Alternate Function Open-Drain Mode, 50MHz */
/** @} */

/** @} */


/**
 * @defgroup GPIO_Functions GPIO Functions
 * @brief GPIO functions for controlling GPIO pins.
 * @{
 */

/**
 * @brief Sets the mode of a GPIO pin.
 *
 * This function sets the mode of a specified GPIO pin.
 *
 * @param[in] Copy_PortId The ID of the GPIO port (e.g., GPIO_PORTA, GPIO_PORTB, etc.).
 * @param[in] Copy_PinId The ID of the GPIO pin (e.g., GPIO_PIN0, GPIO_PIN1, etc.).
 * @param[in] Copy_PinMode The desired mode for the GPIO pin.
 * @return Std_ReturnType Returns E_OK if the operation was successful, or E_NOT_OK if an error occurred.
 */
Std_ReturnType MCAL_GPIO_SetPinMode(u8 Copy_PortId, u8 Copy_PinId, u8 Copy_PinMode);

/**
 * @brief Sets the value of a GPIO pin.
 *
 * This function sets the value of a specified GPIO pin to either high or low.
 *
 * @param[in] Copy_PortId The ID of the GPIO port (e.g., GPIO_PORTA, GPIO_PORTB, etc.).
 * @param[in] Copy_PinId The ID of the GPIO pin (e.g., GPIO_PIN0, GPIO_PIN1, etc.).
 * @param[in] Copy_PinValue The desired value for the GPIO pin (GPIO_HIGH or GPIO_LOW).
 * @return Std_ReturnType Returns E_OK if the operation was successful, or E_NOT_OK if an error occurred.
 */
Std_ReturnType MCAL_GPIO_SetPinValue(u8 Copy_PortId, u8 Copy_PinId, u8 Copy_PinValue);

/**
 * @brief Gets the value of a GPIO pin.
 *
 * This function reads the current value of a specified GPIO pin and stores it in the provided pointer.
 *
 * @param[in] Copy_PortId The ID of the GPIO port (e.g., GPIO_PORTA, GPIO_PORTB, etc.).
 * @param[in] Copy_PinId The ID of the GPIO pin (e.g., GPIO_PIN0, GPIO_PIN1, etc.).
 * @param[out] Copy_PinReturnValue Pointer to the variable where the pin value will be stored (GPIO_HIGH or GPIO_LOW).
 * @return Std_ReturnType Returns E_OK if the operation was successful, or E_NOT_OK if an error occurred.
 */
Std_ReturnType MCAL_GPIO_GetPinValue(u8 Copy_PortId, u8 Copy_PinId, u8 *Copy_PinReturnValue);

/**
 * @brief Toggles the value of a GPIO pin.
 *
 * This function toggles the value of a specified GPIO pin. If the pin is currently
 * high, it will be set to low, and if it is currently low, it will be set to high.
 *
 * @param[in] Copy_PortId The ID of the GPIO port (e.g., GPIO_PORTA, GPIO_PORTB, etc.).
 * @param[in] Copy_PinId The ID of the GPIO pin (e.g., GPIO_PIN0, GPIO_PIN1, etc.).
 *
 * @return Std_ReturnType Returns E_OK if the operation was successful, or E_NOT_OK if an error occurred.
 */
Std_ReturnType MCAL_GPIO_TogglePin(u8 Copy_PortId, u8 Copy_PinId);

/** @} */ // End of GPIO_Functions group


#endif /**< GPIO_INTERFACE_H_ */