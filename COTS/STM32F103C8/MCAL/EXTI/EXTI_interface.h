/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 9 Sep 2023                 *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : EXTI_interface.h           *****************/
/****************************************************************/
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/**
 * @defgroup EXTI_Configurations EXTI Line Configurations
 * @brief Configuration options for EXTI lines.
 * @{
 */

/**
 * @brief Type Definition for EXTI Callback Function
 *
 * This typedef defines the type of callback functions that can be associated
 * with EXTI (External Interrupt) events. EXTI callback functions are user-defined
 * functions that are executed when an EXTI event, such as a pin interrupt, occurs.
 * 
 * EXTI callback functions take no arguments and return no values, as they are
 * typically used to perform actions in response to an EXTI event.
 *
 * Example of defining an EXTI callback function:
 * ```c
 * void MyEXTICallback(void) {
 *     /// Your code to handle the EXTI event goes here
 * }
 * ```
 *
 * You can then associate `MyEXTICallback` or any similar function with an EXTI line
 * configuration to execute it when the corresponding EXTI event occurs.
 */
typedef void (*EXTI_CallbackFunc_t)(void);

/**
 * @name EXTI Trigger Edge Selection
 * @{
 */
#define EXTI_RISING_EDGE  0   /**< Configure for rising edge trigger. */
#define EXTI_FALLING_EDGE 1   /**< Configure for falling edge trigger. */
#define EXTI_BOTH_EDGES   2   /**< Configure for both rising and falling edge trigger. */
/** @} */

/**
 * @name EXTI Line Numbers
 * @{
 */
#define EXTI_LINE0  0   /**< EXTI line number for GPIO pin 0. */
#define EXTI_LINE1  1   /**< EXTI line number for GPIO pin 1. */
#define EXTI_LINE2  2   /**< EXTI line number for GPIO pin 2. */
#define EXTI_LINE3  3   /**< EXTI line number for GPIO pin 3. */
#define EXTI_LINE4  4   /**< EXTI line number for GPIO pin 4. */
#define EXTI_LINE5  5   /**< EXTI line number for GPIO pin 5. */
#define EXTI_LINE6  6   /**< EXTI line number for GPIO pin 6. */
#define EXTI_LINE7  7   /**< EXTI line number for GPIO pin 7. */
#define EXTI_LINE8  8   /**< EXTI line number for GPIO pin 8. */
#define EXTI_LINE9  9   /**< EXTI line number for GPIO pin 9. */
#define EXTI_LINE10 10  /**< EXTI line number for GPIO pin 10. */
#define EXTI_LINE11 11  /**< EXTI line number for GPIO pin 11. */
#define EXTI_LINE12 12  /**< EXTI line number for GPIO pin 12. */
#define EXTI_LINE13 13  /**< EXTI line number for GPIO pin 13. */
#define EXTI_LINE14 14  /**< EXTI line number for GPIO pin 14. */
#define EXTI_LINE15 15  /**< EXTI line number for GPIO pin 15. */
/** @} */

/** @} */  // EXTI_Configurations

/**
 * @defgroup EXTI_Control EXTI Control Functions
 * @brief Functions for configuring and controlling External Interrupts (EXTI).
 * @{
 */

/**
 * @brief Initialize the EXTI module.
 *
 * This function initializes the EXTI module, setting it to its default state.
 * It should be called once at the beginning of the application.
 *
 * @note To configure EXTI settings, please refer to the configuration file
 *       (e.g., @ref EXTI_config.h) where you can customize EXTI behavior as needed.
 */
void MCAL_EXTI_vInit(void);

/**
 * @brief Initialize EXTI for a specific GPIO pin.
 *
 * This function initializes EXTI for a specific GPIO pin by configuring the EXTI
 * line mapping based on the selected GPIO port and pin number.
 *
 * @param[in] GPIO_Pin The GPIO pin number (0 to 15) to be used.
 * @param[in] GPIO_Port The GPIO port (GPIO_PORTA, GPIO_PORTB, etc.) to be used.
 *
 * @note This function should be called to configure EXTI mapping for a specific GPIO pin
 *       that will trigger external interrupts.
 *
 * @return EXTI_Status_TypeDef EXTI status (EXTI_STATUS_OK or EXTI_STATUS_ERROR).
 *
 * @code
 * /// Example usage:
 * Std_ReturnType result = EXTI_InitForGPIO(GPIO_PIN0, GPIO_PORTA); // Initialize EXTI for PA0
 * if (result == E_OK) {
 *     /// EXTI initialization successful.
 * } else {
 *     /// EXTI initialization error.
 * }
 * @endcode
 */
Std_ReturnType MCAL_EXTI_InitEXTIForGPIO(u8 GPIO_Pin, u8 GPIO_Port);

/**
 * @brief Enable an external interrupt line.
 *
 * This function enables the specified external interrupt line, allowing it to
 * trigger interrupt requests.
 *
 * @param[in] Copy_Line The external interrupt line to enable.
 *
 * @return Std_ReturnType
 *   - E_OK     : Interrupt line enabled successfully.
 *   - E_NOT_OK : An error occurred (invalid interrupt line).
 */
Std_ReturnType MCAL_EXTI_EnableLine(u8 Copy_Line);

/**
 * @brief Disable an external interrupt line.
 *
 * This function disables the specified external interrupt line, preventing it
 * from triggering interrupt requests.
 *
 * @param[in] Copy_Line The external interrupt line to disable.
 *
 * @return Std_ReturnType
 *   - E_OK     : Interrupt line disabled successfully.
 *   - E_NOT_OK : An error occurred (invalid interrupt line).
 */
Std_ReturnType MCAL_EXTI_DisableLine(u8 Copy_Line);

/**
 * @brief Set the trigger mode for an external interrupt line.
 *
 * This function sets the trigger mode (e.g., rising edge, falling edge, both edges)
 * for the specified external interrupt line.
 *
 * @param[in] Copy_Line The external interrupt line to configure.
 * @param[in] Copy_Mode The trigger mode to set (e.g., EXTI_TRIGGER_RISING, EXTI_TRIGGER_FALLING, EXTI_BOTH_EDGES).
 *
 * @return Std_ReturnType
 *   - E_OK     : Trigger mode set successfully.
 *   - E_NOT_OK : An error occurred (invalid interrupt line or trigger mode).
 */
Std_ReturnType MCAL_EXTI_SetTrigger(u8 Copy_Line, u8 Copy_Mode);

/**
  * @brief  Set Callback Function for an EXTI Line
  * @param  Copy_Line: The EXTI line number (0 to 15)
  * @param  CallbackFunc: Pointer to the callback function to be set
  * @retval Std_ReturnType: Indicates whether the operation was successful or not
  *         - E_OK: Operation successful
  *         - E_NOT_OK: Invalid input (e.g., NULL callback function)
  *
  * @note   This function allows you to set a callback function to be called
  *         when the specified EXTI line triggers an interrupt. The callback
  *         function will be executed in the EXTI interrupt handler.
  *
  * Example:
  * @code
  * /// Define a callback function
  * void MyEXTICallback(void)
  * {
  *     /// Your code here
  * }
  * 
  * /// Set the callback function for EXTI Line 0
  * MCAL_EXTI_SetCallback(EXTI_LINE0, MyEXTICallback);
  * @endcode
  */
Std_ReturnType MCAL_EXTI_SetCallback(u8 Copy_Line , EXTI_CallbackFunc_t CallbackFunc);

/** @} */ // End of EXTI_Control


#endif /**< EXTI_INTERFACE_H_ */