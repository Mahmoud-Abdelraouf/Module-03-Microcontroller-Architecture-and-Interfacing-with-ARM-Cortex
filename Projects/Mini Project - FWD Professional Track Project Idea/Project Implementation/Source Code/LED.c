/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 16 Sep 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : LED_program.c              *****************/
/****************************************************************/

/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL *****************************/
#include "GPIO_interface.h"
#include "STK_interface.h"
/*****************************< HAL *****************************/
#include "LED.h"

/**
 * @defgroup Public_Functions LED Driver
 * @{
 */

Std_ReturnType HAL_LED_Init(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId)
{
    /**< Init LED to be output */  
    return MCAL_GPIO_SetPinMode(Copy_LedPortId, Copy_LedPinId, GPIO_OUTPUT_PUSH_PULL_2MHZ);
}

Std_ReturnType HAL_LED_On(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId)
{
    return MCAL_GPIO_SetPinValue(Copy_LedPortId, Copy_LedPinId, GPIO_HIGH);
}

Std_ReturnType HAL_LED_Off(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId)
{
    return MCAL_GPIO_SetPinValue(Copy_LedPortId, Copy_LedPinId, GPIO_LOW);
}

Std_ReturnType HAL_LED_Toggle(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId)
{
    return MCAL_GPIO_TogglePin(Copy_LedPortId, Copy_LedPinId);
}

Std_ReturnType HAL_LED_BlinkOnce(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId, LED_Delay_ms_t Copy_BlinkTime)
{
    if(MCAL_GPIO_SetPinValue(Copy_LedPortId, Copy_LedPinId, GPIO_HIGH) == E_NOT_OK)
    {
        return E_NOT_OK;
    }

    if(MCAL_STK_SetDelay_ms(Copy_BlinkTime) == E_NOT_OK)
    {
        return E_NOT_OK;
    }

    if(MCAL_GPIO_SetPinValue(Copy_LedPortId, Copy_LedPinId, GPIO_LOW) == E_NOT_OK)
    {
        return E_NOT_OK;
    }

    return E_OK;
}

Std_ReturnType HAL_LED_BlinkTwice(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId, LED_Delay_ms_t Copy_BlinkTime)
{
    if(HAL_LED_BlinkOnce(Copy_LedPortId, Copy_LedPinId, Copy_BlinkTime) == E_NOT_OK)
    {
        return E_NOT_OK;
    }

    MCAL_STK_SetDelay_ms(Copy_BlinkTime);

    HAL_LED_BlinkOnce(Copy_LedPortId, Copy_LedPinId, Copy_BlinkTime);

    return E_OK;
}

/**
 * @} // End of Public_Functions
 */
