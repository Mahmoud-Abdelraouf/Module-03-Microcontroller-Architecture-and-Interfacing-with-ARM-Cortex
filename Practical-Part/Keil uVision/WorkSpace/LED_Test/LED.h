/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 16 Sep 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : LED_interface.h            *****************/
/****************************************************************/
#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

typedef u8 LED_Port_t;
typedef u8 LED_Pin_t;

typedef f32 LED_Delay_ms_t;

/**
 * @brief Initializes the LED peripheral.
 *
 * This function initializes the LED peripheral with the specified identifier.
 *
 * @param[in] LedId The identifier of the LED to initialize.
 *
 * @return None.
 */
Std_ReturnType HAL_LED_Init(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId);

/**
 * @brief Turns on the specified LED.
 *
 * This function turns on the LED with the specified identifier.
 *
 * @param[in] LedId The identifier of the LED to turn on.
 *
 * @return None.
 */
Std_ReturnType HAL_LED_On(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId);

/**
 * @brief Turns off the specified LED.
 *
 * This function turns off the LED with the specified identifier.
 *
 * @param[in] LedId The identifier of the LED to turn off.
 *
 * @return None.
 */
Std_ReturnType HAL_LED_Off(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId);

/**
 * @brief Toggles the specified LED.
 *
 * This function toggles the state of the LED with the specified identifier.
 *
 * @param[in] LedId The identifier of the LED to toggle.
 *
 * @return None.
 */
Std_ReturnType HAL_LED_Toggle(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId);

/**
 * @brief Blinks the specified LED once.
 *
 * This function blinks the LED with the specified identifier once.
 *
 * @param[in] LedId The identifier of the LED to blink once.
 *
 * @return None.
 */
Std_ReturnType HAL_LED_BlinkOnce(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId, LED_Delay_ms_t Copy_BlinkTime);

/**
 * @brief Blinks the specified LED twice.
 *
 * This function blinks the LED with the specified identifier twice.
 *
 * @param[in] LedId The identifier of the LED to blink twice.
 *
 * @return None.
 */
Std_ReturnType HAL_LED_BlinkTwice(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId, LED_Delay_ms_t Copy_BlinkTime);


#endif /**< LED_INTERFACE_H_ */