/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 9 Sep 2023                 *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : EXTI_program.h             *****************/
/****************************************************************/

/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**< MCAL */
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

Std_ReturnType EXTI_Init(void)
{
    
}

Std_ReturnType EXTI_Enable(u8 Copy_Line)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if(Copy_Line < 16)
    {
        SET_BIT(EXTI->EXTI_IMR, Copy_Line);
        Local_FunctionStatus = E_OK;
    }
    else
    {
       Local_FunctionStatus = E_NOT_OK; 
    }
    
    return Local_FunctionStatus;

}

Std_ReturnType EXTI_Disable(u8 Copy_Line)
{
    {
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if(Copy_Line < 16)
    {
        CLR_BIT(EXTI->EXTI_IMR, Copy_Line);
        Local_FunctionStatus = E_OK;
    }
    else
    {
       Local_FunctionStatus = E_NOT_OK; 
    }
    
    return Local_FunctionStatus;

}
}

Std_ReturnType EXTI_SetPinTrigger(u8 Copy_Line, u8 Copy_Mode)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    switch (Copy_Mode)
    {
    case EXTI_RISING_EDGE:
        SET_BIT(EXTI->EXTI_RTSR, Copy_Line);
        Local_FunctionStatus = E_OK;
        break;

    case EXTI_FILING_EDGE:
        SET_BIT(EXTI->EXTI_FTSR, Copy_Line);
        Local_FunctionStatus = E_OK;
        break;

    case EXTI_BOTH_EDGE:
        SET_BIT(EXTI->EXTI_RTSR, Copy_Line);
        SET_BIT(EXTI->EXTI_FTSR, Copy_Line);
        Local_FunctionStatus = E_OK;
        break;
    
    default:
        Local_FunctionStatus = E_NOT_OK;
        break;
    }

    return Local_FunctionStatus;
}

