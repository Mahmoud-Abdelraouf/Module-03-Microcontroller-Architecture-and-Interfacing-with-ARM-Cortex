/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 16 Sep 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : LED_interface.h            *****************/
/****************************************************************/
#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

/**
 * @addtogroup LED_Parameters
 * @{
 */

/**
 * @brief LED Port Enumeration
 *
 * Enumeration of available LED ports.
 */
typedef enum {
    LED_PORTA, /**< Port A */ 
    LED_PORTB, /**< Port B */
    LED_PORTC  /**< Port C */
} LED_Port_t;

/**
 * @brief LED Pin Enumeration
 *
 * Enumeration of available LED pins.
 */
typedef enum {
    LED_PIN0,  /**< Pin 0 */ 
    LED_PIN1,  /**< Pin 1 */
    LED_PIN2,  /**< Pin 2 */
    LED_PIN3,  /**< Pin 3 */
    LED_PIN4,  /**< Pin 4 */
    LED_PIN5,  /**< Pin 5 */
    LED_PIN6,  /**< Pin 6 */
    LED_PIN7,  /**< Pin 7 */
    LED_PIN8,  /**< Pin 8 */
    LED_PIN9,  /**< Pin 9 */
    LED_PIN10, /**< Pin 10 */
    LED_PIN11, /**< Pin 11 */
    LED_PIN12, /**< Pin 12 */
    LED_PIN13, /**< Pin 13 */
    LED_PIN14, /**< Pin 14 */
    LED_PIN15, /**< Pin 15 */ 
} LED_Pin_t;

/**
 * @brief LED Delay in Milliseconds Type
 *
 * Type definition for LED delay in milliseconds.
 */
typedef u32 LED_Delay_ms_t;

/**
 * @} (LED_Parameters)
 */


/**
 * @defgroup LED_Functions LED Functions
 * @{
 */

/**
 * @brief Initialize an LED
 *
 * Initializes the specified LED pin for output.
 *
 * @param[in] Copy_LedPortId The ID of the LED port.
 * @param[in] Copy_LedPinId The ID of the LED pin.
 * @return Std_ReturnType Returns E_OK if initialization is successful, or E_NOT_OK if an error occurs.
 */
Std_ReturnType HAL_LED_Init(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId);

/**
 * @brief Turn On an LED
 *
 * Turns on the specified LED.
 *
 * @param[in] Copy_LedPortId The ID of the LED port.
 * @param[in] Copy_LedPinId The ID of the LED pin.
 * @return Std_ReturnType Returns E_OK if the operation was successful, or E_NOT_OK if an error occurs.
 */
Std_ReturnType HAL_LED_On(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId);

/**
 * @brief Turn Off an LED
 *
 * Turns off the specified LED.
 *
 * @param[in] Copy_LedPortId The ID of the LED port.
 * @param[in] Copy_LedPinId The ID of the LED pin.
 * @return Std_ReturnType Returns E_OK if the operation was successful, or E_NOT_OK if an error occurs.
 */
Std_ReturnType HAL_LED_Off(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId);

/**
 * @brief Toggle an LED
 *
 * Toggles the state of the specified LED.
 *
 * @param[in] Copy_LedPortId The ID of the LED port.
 * @param[in] Copy_LedPinId The ID of the LED pin.
 * @return Std_ReturnType Returns E_OK if the operation was successful, or E_NOT_OK if an error occurs.
 */
Std_ReturnType HAL_LED_Toggle(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId);

/**
 * @brief Blink an LED Once
 *
 * Blinks the specified LED once with a specified delay.
 *
 * @param[in] Copy_LedPortId The ID of the LED port.
 * @param[in] Copy_LedPinId The ID of the LED pin.
 * @param[in] Copy_BlinkTime The delay in milliseconds for each blink.
 * @return Std_ReturnType Returns E_OK if the operation was successful, or E_NOT_OK if an error occurs.
 */
Std_ReturnType HAL_LED_BlinkOnce(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId, LED_Delay_ms_t Copy_BlinkTime);

/**
 * @brief Blink an LED Twice
 *
 * Blinks the specified LED twice with a specified delay between blinks.
 *
 * @param[in] Copy_LedPortId The ID of the LED port.
 * @param[in] Copy_LedPinId The ID of the LED pin.
 * @param[in] Copy_BlinkTime The delay in milliseconds for each blink.
 * @return Std_ReturnType Returns E_OK if the operation was successful, or E_NOT_OK if an error occurs.
 */
Std_ReturnType HAL_LED_BlinkTwice(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId, LED_Delay_ms_t Copy_BlinkTime);

/**
 * @} (end of LED_Functions)
 */

#endif /**< LED_INTERFACE_H_ */