/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 6 Sep 2023                 *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : NVIC_config.h              *****************/
/****************************************************************/

/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**< MCAL */
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

/**<  */

Std_ReturnType MCAL_NVIC_EnableIRQ(IRQn_Type Copy_IRQn)
{
   Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    
   if(Copy_IRQn < 32)
    {
        NVIC_ISER0 = (1 << Copy_IRQn);
        Local_FunctionStatus = E_OK;
    }
    else if (Copy_IRQn <= 64)
    {
        NVIC_ISER1 = (1 << Copy_IRQn);
        Local_FunctionStatus = E_OK;
    }
    else if (Copy_IRQn < 96)
    {
        NVIC_ISER2 = (1 << Copy_IRQn);
        Local_FunctionStatus = E_OK;
    }
    else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    
    return Local_FunctionStatus;
    
}

Std_ReturnType MCAL_NVIC_DisableIRQ(IRQn_Type Copy_IRQn)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

   if(Copy_IRQn < 32)
    {
        NVIC_ICER0 = (1 << Copy_IRQn);
        Local_FunctionStatus = E_OK;
    }
    else if (Copy_IRQn <= 64)
    {
        NVIC_ICER1 = (1 << Copy_IRQn);
        Local_FunctionStatus = E_OK;
    }
    else if (Copy_IRQn < 96)
    {
        NVIC_ICER2 = (1 << Copy_IRQn);
        Local_FunctionStatus = E_OK;
    }
    else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    
    return Local_FunctionStatus;
}

Std_ReturnType MCAL_NVIC_SetPendingIRQ(IRQn_Type Copy_IRQn)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

   if(Copy_IRQn < 32)
    {
        NVIC_ISPR0 = (1 << Copy_IRQn);
        Local_FunctionStatus = E_OK;
    }
    else if (Copy_IRQn <= 64)
    {
        NVIC_ISPR1 = (1 << Copy_IRQn);
        Local_FunctionStatus = E_OK;
    }
    else if (Copy_IRQn < 96)
    {
        NVIC_ISPR2 = (1 << Copy_IRQn);
        Local_FunctionStatus = E_OK;
    }
    else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    
    return Local_FunctionStatus;
}

Std_ReturnType MCAL_NVIC_ClearPendingIRQ(IRQn_Type Copy_IRQn)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if (Copy_IRQn < 32)
    {
        NVIC_ICPR0 = (1U << Copy_IRQn);
        Local_FunctionStatus = E_OK;
    }
    else if (Copy_IRQn < 64)
    {
        NVIC_ICPR1 = (1U << (Copy_IRQn - 32));
        Local_FunctionStatus = E_OK;
    }
    else if (Copy_IRQn < 96)
    {
        NVIC_ICPR2 = (1U << (Copy_IRQn - 64));
        Local_FunctionStatus = E_OK;
    }

    return Local_FunctionStatus;
}

Std_ReturnType MCAL_NVIC_GetPendingIRQ(IRQn_Type Copy_IRQn, u8 *Copy_ReturnPendingFlag)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if (Copy_ReturnPendingFlag != NULL)
    {
        /**< Check the pending flag based on the interrupt number */ 
        if (Copy_IRQn < 32)
        {
            /**< Check the bit corresponding to the interrupt */ 
            if (NVIC_ISPR0 & (1U << Copy_IRQn))
            {
                *Copy_ReturnPendingFlag = 1; /**< Set to 1 if the flag is pending */ 
            }
            else
            {
                *Copy_ReturnPendingFlag = 0; /**< Set to 0 if the flag is not pending */ 
            }
            Local_FunctionStatus = E_OK;
        }
        else if (Copy_IRQn < 64)
        {
            /**< Check the bit corresponding to the interrupt */ 
            if (NVIC_ISPR1 & (1U << (Copy_IRQn - 32)))
            {
                *Copy_ReturnPendingFlag = 1; /**< Set to 1 if the flag is pending */ 
            }
            else
            {
                *Copy_ReturnPendingFlag = 0; /**< Set to 0 if the flag is not pending */ 
            }
            Local_FunctionStatus = E_OK;
        }
        else if(Copy_IRQn < 96)
        {   
            /**< Check the bit corresponding to the interrupt */
            if(NVIC_ISPR2 & (1U << (Copy_IRQn - 64)))
            {
                *Copy_ReturnPendingFlag = 1; /**< Set to 1 if the flag is pending */ 
            }
            else
            {
                *Copy_ReturnPendingFlag = 0; /**< Set to 0 if the flag is not pending */ 
            }
            Local_FunctionStatus = E_OK;
        }
        else
        {
            Local_FunctionStatus = E_NOT_OK;
        }
    }

    return Local_FunctionStatus;
}

Std_ReturnType MCAL_NVIC_SetPriority(IRQn_Type IRQn, u32 Copy_Priority)
{

}

Std_ReturnType MCAL_NVIC_GetPriority(IRQn_Type IRQn)
{
    
}