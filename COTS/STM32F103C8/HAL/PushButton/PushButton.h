/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 16 Sep 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : PushButton.h               *****************/
/****************************************************************/
#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_

/****************************************************************
 *                     Interface Section                        *
 ****************************************************************/

/**
 * @addtogroup PushButton_Driver
 * @{
 */

/**
 * @brief Debounce Delay in Milliseconds
 *
 * This constant defines the debounce delay in milliseconds. It is used to ensure
 * that button state changes are stable for a certain period before being considered valid.
 * Adjust the value as needed depending on your specific application and hardware characteristics.
 */
#define DEBOUNCE_DELAY_MS 2 /**< Define a debounce delay in milliseconds (adjust as needed) */

/**
 * @brief SysTick Reload Value
 *
 * This constant defines the maximum value that can be loaded into the SysTick timer.
 * When initializing the SysTick timer, this value is used to set the timer's initial
 * count and determines the duration of the timer before it overflows.
 * In this case, it's set to the maximum 24-bit value (0x00FFFFFF), resulting in a timer
 * that counts down from this value to 0 before overflowing.
 */
#define SYSTICK_RELOAD_VALUE    0x00FFFFFF /**< Define a systick reload value (adjust as needed) */

/**
 * @brief Push Button Enumeration
 *
 * Enumeration of available push buttons.
 */
typedef enum {
    PB_PORTA, /**< Port A */
    PB_PORTB, /**< Port B */
    PB_PORTC  /**< Port C */
} PushButton_Port_t;

/**
 * @brief Enumeration of Push Button Pin IDs
 *
 * This enumeration defines the available push button pin IDs.
 */
typedef enum {
    PB_PIN0,  /**< Pin 0 */ 
    PB_PIN1,  /**< Pin 1 */
    PB_PIN2,  /**< Pin 2 */
    PB_PIN3,  /**< Pin 3 */
    PB_PIN4,  /**< Pin 4 */
    PB_PIN5,  /**< Pin 5 */
    PB_PIN6,  /**< Pin 6 */
    PB_PIN7,  /**< Pin 7 */
    PB_PIN8,  /**< Pin 8 */
    PB_PIN9,  /**< Pin 9 */
    PB_PIN10, /**< Pin 10 */
    PB_PIN11, /**< Pin 11 */
    PB_PIN12, /**< Pin 12 */
    PB_PIN13, /**< Pin 13 */
    PB_PIN14, /**< Pin 14 */
    PB_PIN15, /**< Pin 15 */ 
} LED_Pin_t;

/**
 * @brief Enumeration of Push Button Active States
 *
 * This enumeration defines the active states for a push button.
 * - ACTIVE_HIGH: The button is considered active when it's in a high state (e.g., logic level 1).
 * - ACTIVE_LOW: The button is considered active when it's in a low state (e.g., logic level 0).
 */
typedef enum {
    ACTIVE_LOW,    /**< Active when low (e.g., logic level 0) */
    ACTIVE_HIGH   /**< Active when high (e.g., logic level 1) */
} PushButton_State_t;

/**
 * @brief Initializes a Push Button.
 *
 * This function initializes a push button by configuring its GPIO pin as an input.
 *
 * @param[in] Copy_ButtonPortId The ID of the GPIO port (e.g., GPIO_PORTA, GPIO_PORTB, etc.).
 * @param[in] Copy_ButtonPinId The ID of the GPIO pin (e.g., GPIO_PIN0, GPIO_PIN1, etc.).
 * @param[in] Copy_ActiveLevel The active level of the push button (ACTIVE_HIGH or ACTIVE_LOW).
 * @return Std_ReturnType Returns E_OK if the operation was successful, or E_NOT_OK if an error occurred.
 */
Std_ReturnType HAL_PushButton_Init(PushButton_Port_t Copy_ButtonPortId, LED_Pin_t Copy_ButtonPinId, PushButton_State_t ActiveLevel);

/**
 * @brief Reads the state of a Push Button.
 *
 * This function reads the current state of the specified push button (pressed or not pressed).
 *
 * @param[in] Copy_ButtonPortId The ID of the GPIO port (e.g., GPIO_PORTA, GPIO_PORTB, etc.).
 * @param[in] Copy_ButtonPinId The ID of the GPIO pin (e.g., GPIO_PIN0, GPIO_PIN1, etc.).
 * @param[out] Copy_ButtonState Pointer to the variable where the button state will be stored (1 for pressed, 0 for not pressed).
 * @return Std_ReturnType Returns E_OK if the operation was successful, or E_NOT_OK if an error occurred.
 */
Std_ReturnType HAL_PushButton_Read(u8 Copy_ButtonPortId, u8 Copy_ButtonPinId, u8 *Copy_ButtonState);

/**
 * @} (end of PushButton_Driver)
 */

/****************************************************************
 *                 End of Interface Section                     *
 ****************************************************************/


#endif /**< PUSHBUTTON_H_ */