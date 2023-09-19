/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 16 Sep 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : PushButton_program.c       *****************/
/****************************************************************/

/*****************************< LIB *****************************/
#include <stdbool.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL *****************************/
#include "GPIO_interface.h"
#include "STK_interface.h"
/*****************************< HAL *****************************/
#include "PushButton.h"
/*****************************< Function Implementations *****************************/
/**
 * @defgroup Public_Functions LED Driver
 * @{
 */

Std_ReturnType HAL_PushButton_Init(PushButton_Port_t Copy_ButtonPortId, LED_Pin_t Copy_ButtonPinId, PushButton_State_t Copy_ActiveLevel)
{
    if (Copy_ActiveLevel != ACTIVE_HIGH && Copy_ActiveLevel != ACTIVE_LOW) 
    {
        return E_NOT_OK; /**< Invalid pull-up/down configuration */
    }
    else
    {
        /**< Initialize Push Button to be input with pull-up or pull-down */
        #if(Copy_ActiveLevel == ACTIVE_LOW)
            Copy_ActiveLevel = GPIO_INPUT_PULL_UP;
            if(MCAL_GPIO_SetPinMode(Copy_ButtonPortId, Copy_ButtonPinId, Copy_ActiveLevel) == E_NOT_OK)
            {
                return E_NOT_OK; /**< GPIO initialization failed */
            }

            MCAL_GPIO_SetPinValue(Copy_ButtonPortId, Copy_ButtonPinId, GPIO_HIGH);

            return E_OK;

        #elif(Copy_ActiveLevel == ACTIVE_HIGH)
            Copy_ActiveLevel = GPIO_INPUT_PULL_DOWN;
            if(MCAL_GPIO_SetPinMode(Copy_ButtonPortId, Copy_ButtonPinId, Copy_ActiveLevel) == E_NOT_OK)
            {
                return E_NOT_OK; /**< GPIO initialization failed */
            }

            MCAL_GPIO_SetPinValue(Copy_ButtonPortId, Copy_ButtonPinId, GPIO_LOW);

            return E_OK;

        #else
            #error "Unexpected condition in HAL_PushButton_Init"            
        #endif
    }
}

Std_ReturnType HAL_PushButton_Read(u8 Copy_ButtonPortId, u8 Copy_ButtonPinId, u8 *Copy_ButtonState, u32 numIterations)
{
    if (Copy_ButtonState == NULL)
    {
        return E_NOT_OK; /**< Invalid pointer */
    }

    /**< Start the SysTick timer */
    MCAL_STK_Init(SYSTICK_RELOAD_VALUE); /**< Initialize SysTick with a suitable reload value. */ 
    MCAL_STK_Start();

    /**< Variables to store button state */
    bool currentButtonState;
    bool lastButtonState;

    /**< Variables to track time for debounce */
    static u32 lastDebounceTime = 0;

    u32 stableCount = 0; /**< Count of stable readings */ 

    /**< Repeat the reading and debouncing for the specified number of iterations */ 
    for (u32 i = 0; i < numIterations; i++)
    {
        /**< Read the current button state */
        if (MCAL_GPIO_GetPinValue(Copy_ButtonPortId, Copy_ButtonPinId, &currentButtonState) != E_OK)
        {
            return E_NOT_OK; /**< Error reading button state */
        }

        u32 currentMillis = MCAL_STK_GetElapsedCounts(); // Get the current time in milliseconds

        /**< Check if the button state has changed and is stable for the debounce delay */ 
        if (currentButtonState != lastButtonState)
        {
            /**< Update the last button state */
            lastButtonState = currentButtonState;

            /**< Update the last debounce time */
            lastDebounceTime = currentMillis;
        }

        /**< Check if the button state has been stable for the debounce delay */
        if ((currentMillis - lastDebounceTime) >= DEBOUNCE_DELAY_MS)
        {
            /**< Increment the stable count */
            stableCount++;

            /**< If the button state has been stable for a sufficient number of times, consider it stable */ 
            if (stableCount >= (numIterations-2))
            {
                /**< Assign the debounced button state to the output parameter */
                *Copy_ButtonState = currentButtonState;
                return E_OK;
            }
        }

        /**< Button state is not stable yet, return the previous state */
        *Copy_ButtonState = lastButtonState;
    }

    return E_NOT_OK; /**< Button state not stable after the specified number of iterations */
}

/**
 * @} (End of Public_Functions) 
 */