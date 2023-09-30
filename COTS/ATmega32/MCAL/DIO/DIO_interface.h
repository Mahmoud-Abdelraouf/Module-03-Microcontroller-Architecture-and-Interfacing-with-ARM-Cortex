/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 29 Sep 2023                *****************/
/******* Version   : 0.2                        *****************/
/******* File Name : DIO_interface.h            *****************/
/****************************************************************/
 #ifndef __DIO_INTERFACE_H_
 #define __DIO_INTERFACE_H_

/**
 * @addtogroup DIO_Macros Digital I/O (DIO) Macros
 * @{
 */

/**< Macros for PORTS */
#define DIO_PORTA     0 /**< Port A */
#define DIO_PORTB     1 /**< Port B */
#define DIO_PORTC     2 /**< Port C */
#define DIO_PORTD     3 /**< Port D */

/**< Macros for PINS */
#define DIO_PIN0      0 /**< Pin 0 */
#define DIO_PIN1      1 /**< Pin 1 */
#define DIO_PIN2      2 /**< Pin 2 */
#define DIO_PIN3      3 /**< Pin 3 */
#define DIO_PIN4      4 /**< Pin 4 */
#define DIO_PIN5      5 /**< Pin 5 */
#define DIO_PIN6      6 /**< Pin 6 */
#define DIO_PIN7      7 /**< Pin 7 */

/**< Macros for Pin Direction */
#define DIO_OUTPUT    1 /**< Output Direction */
#define DIO_INPUT     0 /**< Input Direction */

/**< Macros for Pin Value */
#define DIO_HIGH      1 /**< High Pin Value */
#define DIO_LOW       0 /**< Low Pin Value */

/**
 * @} DIO_Macros
 */

/**
 * @addtogroup DIO_Functions
 * @{
 */

/**
 * @brief Initialize the Digital I/O (DIO) ports and pins.
 *
 * This function initializes the DIO ports and pins based on predefined constants for
 * direction (input/output) and initial values (high/low). It configures the data direction
 * registers (DDRx) and sets the initial output values for the pins.
 *
 * @note You should call this function once at the beginning of your program to set up
 * the DIO ports and pins.
 */
void DIO_voidInit(void);

/**
 * @brief Set the direction (input/output) of a specific pin in a given port.
 *
 * This function allows you to set the direction of a specific pin in a selected port.
 *
 * @param[in] Copy_PortId       The ID of the port (DIO_PORTA, DIO_PORTB, DIO_PORTC, or DIO_PORTD).
 * @param[in] Copy_PinId        The ID of the pin within the port (0-7).
 * @param[in] Copy_PinDirection The desired direction for the pin (DIO_OUTPUT or DIO_INPUT).
 *
 * @return Std_ReturnType
 *   - E_OK     : The operation was successful, and the pin direction was set.
 *   - E_NOT_OK : An error occurred (invalid port, pin, or direction).
 *
 * @note You should call this function to configure the direction of a specific pin within a port.
 *       Use DIO_OUTPUT to set the pin as an output and DIO_INPUT to set it as an input.
 */
Std_ReturnType DIO_SetPinDirection(u8 Copy_PortId, u8 Copy_PinId, u8 Copy_PinDirection);

/**
 * @brief Set the value (high/low) of a specific pin in a given port.
 *
 * This function allows you to set the value of a specific pin in a selected port.
 *
 * @param[in] Copy_PortId   The ID of the port (DIO_PORTA, DIO_PORTB, DIO_PORTC, or DIO_PORTD).
 * @param[in] Copy_PinId    The ID of the pin within the port (0-7).
 * @param[in] Copy_PinValue The desired value for the pin (DIO_HIGH or DIO_LOW).
 *
 * @return Std_ReturnType
 *   - E_OK     : The operation was successful, and the pin value was set.
 *   - E_NOT_OK : An error occurred (invalid port, pin, or value).
 *
 * @note You should call this function to set the value of a specific pin within a port.
 *       Use DIO_HIGH to set the pin value to high (logic 1) and DIO_LOW to set it to low (logic 0).
 */
Std_ReturnType DIO_SetPinValue(u8 Copy_PortId, u8 Copy_PinId, u8 Copy_PinValue);

/**
 * @brief Get the value (high/low) of a specific pin in a given port.
 *
 * This function allows you to retrieve the value of a specific pin in a selected port.
 *
 * @param[in]  Copy_PortId         The ID of the port (DIO_PORTA, DIO_PORTB, DIO_PORTC, or DIO_PORTD).
 * @param[in]  Copy_PinId          The ID of the pin within the port (0-7).
 * @param[out] Copy_ReturnedPinValue A pointer to where the pin value will be stored (DIO_HIGH or DIO_LOW).
 *
 * @return Std_ReturnType
 *   - E_OK     : The operation was successful, and the pin value was retrieved.
 *   - E_NOT_OK : An error occurred (invalid port, pin, or pointer).
 *
 * @note You should call this function to read the value of a specific pin within a port.
 *       The pin value will be stored at the memory location pointed to by `Copy_ReturnedPinValue`.
 */
Std_ReturnType DIO_GetPinValue(u8 Copy_PortId, u8 Copy_PinId, u8 *Copy_ReturnedPinValue);

/**
 * @brief Set the direction (input/output) for all pins of a specific port.
 *
 * This function allows you to set the direction (input/output) for all pins of a specific port
 * simultaneously.
 *
 * @param[in]  Copy_PortId         The ID of the port (DIO_PORTA, DIO_PORTB, DIO_PORTC, or DIO_PORTD).
 * @param[in]  Copy_PortDirection  The desired direction for the entire port (DIO_OUTPUT or DIO_INPUT).
 *
 * @return Std_ReturnType
 *   - E_OK     : The operation was successful, and the port direction was set.
 *   - E_NOT_OK : An error occurred (invalid port or direction).
 *
 * @note You should call this function to configure the entire port as input or output.
 */
Std_ReturnType DIO_SetPortDirection(u8 Copy_PortId, u8 Copy_PortDirection);

/**
 * @brief Set the output values for all pins of a specific port.
 *
 * This function allows you to set the output values (high/low) for all pins of a specific port
 * simultaneously.
 *
 * @param[in]  Copy_PortId    The ID of the port (DIO_PORTA, DIO_PORTB, DIO_PORTC, or DIO_PORTD).
 * @param[in]  Copy_PortValue The desired output values for the entire port, where each bit represents
 *                            the corresponding pin (e.g., bit 0 for pin 0).
 *
 * @return Std_ReturnType
 *   - E_OK     : The operation was successful, and the port values were set.
 *   - E_NOT_OK : An error occurred (invalid port).
 *
 * @note This function allows you to set the output values for all pins of a specific port simultaneously.
 */
Std_ReturnType DIO_SetPortValue(u8 Copy_PortId, u8 Copy_PortValue);

/**
 * @brief Get the current input values of all pins of a specific port.
 *
 * This function retrieves the current input values (high/low) of all pins of a specific port
 * and stores them in the provided pointer.
 *
 * @param[in]  Copy_u8portId         The ID of the port (DIO_PORTA, DIO_PORTB, DIO_PORTC, or DIO_PORTD).
 * @param[out] Copy_ReturnedPortValue A pointer to a variable where the input values of the entire port will be stored.
 *
 * @return Std_ReturnType
 *   - E_OK     : The operation was successful, and the port values were retrieved.
 *   - E_NOT_OK : An error occurred (invalid port or null pointer).
 *
 * @note This function allows you to get the input values for all pins of a specific port simultaneously.
 */
Std_ReturnType DIO_GetPortValue(u8 Copy_u8portId, u8 *Copy_ReturnedPortValue);

/**
 * @} DIO_Functions
 */


#endif /**< __DIO_INTERFACE_H_ */
