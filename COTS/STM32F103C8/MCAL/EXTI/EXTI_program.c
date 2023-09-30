/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 9 Sep 2023                 *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : EXTI_program.c             *****************/
/****************************************************************/

/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL *****************************/
/**< GPIO */
#include "GPIO_interface.h"
/**< AFIO */
#include "AFIO_interface.h"
/**< EXTI */
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
/*****************************< Global Variable Section *****************************/
static EXTI_CallbackFunc_t EXTI_Callback[16] = {NULL};
/*****************************< Function Implementations *****************************/
void MCAL_EXTI_vInit(void)
{
    for (u8 Line = 0; Line < EXTI_LINES_COUNT; Line++)
    {
        if (EXTI_Configurations[Line].LineEnabled == EXTI_LINE_ENABLED)
        {
            EXTI->IMR |= (1 << Line);  /**< Enable the EXTI line */ 
            switch (EXTI_Configurations[Line].TriggerType)
            {
                /**< Configure rising edge trigger */
                case EXTI_RISING_EDGE:          
                    SET_BIT(EXTI->RTSR, Line);
                    CLR_BIT(EXTI->FTSR, Line); 
                    break;
                /**< Configure falling edge trigger */ 
                case EXTI_FALLING_EDGE:
                    CLR_BIT(EXTI->RTSR, Line);
                    SET_BIT(EXTI->FTSR, Line);
                    break;
                /**< Configure both edges trigger */
                case EXTI_BOTH_EDGES:
                    SET_BIT(EXTI->RTSR, Line);
                    SET_BIT(EXTI->FTSR, Line);
                    break;
            }
            
            if(EXTI_Configurations[Line].SetCallback != NULL)
            {
                /**< Set the callback function */ 
                EXTI_Configurations[Line].SetCallback();
            }

            /**< Check if GPIO port configuration is available */ 
            if (EXTI_Configurations[Line].GPIO_PortMap != EXTI_GPIO_NONE)
            {
                /**< Enable EXTI line for the specified GPIO pin */ 
                MCAL_AFIO_SetEXTIConfiguration(Line, EXTI_Configurations[Line].GPIO_PortMap);
            }
        }
        else
        {
            EXTI->IMR &= ~(1 << Line);  /**< Disable the EXTI line */ 
        }
    }
}

Std_ReturnType MCAL_EXTI_InitEXTIForGPIO(u8 GPIO_Pin, u8 GPIO_Port) 
{
    /**< Check if GPIO_Pin is within valid range */ 
    if (GPIO_Pin > EXTI_LINE15 || GPIO_Port > GPIO_PORTC) 
    {
        return E_NOT_OK; /**< Invalid GPIO pin or port */ 
    }

    /**< Determine the GPIO port mapping configuration based on GPIO_Port */ 
    u8 PortMap = 0;
    if (GPIO_Port == GPIO_PORTA)
    {
        PortMap = EXTI_PORTMAP_GPIOA;
    } 
    else if (GPIO_Port == GPIO_PORTB) 
    {
        PortMap = EXTI_PORTMAP_GPIOB;
    } 
    else if (GPIO_Port == GPIO_PORTC) 
    {
        PortMap = EXTI_PORTMAP_GPIOC;
    }
    else 
    {
        return E_NOT_OK; /**< Unsupported GPIO port */ 
    }

    /**< Configure EXTI mapping using AFIO function */ 
    Std_ReturnType Local_Result = MCAL_AFIO_SetEXTIConfiguration(GPIO_Pin, PortMap);

    /**< Check if the EXTI configuration was successful */ 
    if (Local_Result == E_OK)
    {
        return E_OK; /**< EXTI initialization successful */ 
    } 
    else 
    {
        return E_NOT_OK; /**< EXTI configuration failed */ 
    }
}

Std_ReturnType MCAL_EXTI_EnableLine(u8 Copy_Line)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if(Copy_Line < EXTI_LINES_COUNT)
    {
        SET_BIT(EXTI->IMR, Copy_Line);
        Local_FunctionStatus = E_OK;
    }
    else
    {
       Local_FunctionStatus = E_NOT_OK; 
    }
    
    return Local_FunctionStatus;

}

Std_ReturnType MCAL_EXTI_DisableLine(u8 Copy_Line)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if(Copy_Line < EXTI_LINES_COUNT)
    {
        CLR_BIT(EXTI->IMR, Copy_Line);
        Local_FunctionStatus = E_OK;
    }
    else
    {
       Local_FunctionStatus = E_NOT_OK; 
    }
    
    return Local_FunctionStatus;
}

Std_ReturnType MCAL_EXTI_SetTrigger(u8 Copy_Line, u8 Copy_Mode)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if(Copy_Line < EXTI_LINES_COUNT)
    {
        switch (Copy_Mode)
        {
            case EXTI_RISING_EDGE:
                SET_BIT(EXTI->RTSR, Copy_Line);
                CLR_BIT(EXTI->FTSR, Copy_Line);
                Local_FunctionStatus = E_OK;
                break;

            case EXTI_FALLING_EDGE:
                CLR_BIT(EXTI->RTSR, Copy_Line);
                SET_BIT(EXTI->FTSR, Copy_Line);
                Local_FunctionStatus = E_OK;
                break;

            case EXTI_BOTH_EDGES:
                SET_BIT(EXTI->RTSR, Copy_Line);
                SET_BIT(EXTI->FTSR, Copy_Line);
                Local_FunctionStatus = E_OK;
                break;

            default:
                Local_FunctionStatus = E_NOT_OK;
                break;
        }
    }
    else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    
    return Local_FunctionStatus;
}

Std_ReturnType MCAL_EXTI_SetCallback(u8 Copy_Line , EXTI_CallbackFunc_t CallbackFunc)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    /**< Check if the provided callback function is NULL */ 
    if (NULL == CallbackFunc)
    {
        /**< Return E_NOT_OK to indicate an invalid input */ 
        return Local_FunctionStatus;
    }

    /**< Set the callback function for the specified EXTI line */ 
    EXTI_Callback[Copy_Line] = CallbackFunc;

    /**< Operation successful, return E_OK */ 
    Local_FunctionStatus = E_OK;

    return Local_FunctionStatus;
}

/** @addtogroup EXTI_ISRs
  * @brief EXTI Line[x] Interrupt Service Routine (ISR).
  * @details This functions are called when an interrupt event occurs on EXTI Line[x].
  *          You can customize this function to handle the specific interrupt event.
  * @{
  */

void EXTI0_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE0]();
    }
}

void EXTI1_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE1]();
    }
}

void EXTI2_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE2]();
    }
}

void EXTI3_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE3]();
    }
}

void EXTI4_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE4]();
    }
}

void EXTI5_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE5]();
    }
}

void EXTI6_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE6]();
    }
}

void EXTI7_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE7]();
    }
}

void EXTI8_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE8]();
    }
}

void EXTI9_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE9]();
    }
}

void EXTI10_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE10]();
    }
}

void EXTI11_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE11]();
    }
}

void EXTI12_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE12]();
    }
}

void EXTI13_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE13]();
    }
}

void EXTI14_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE14]();
    }
}

void EXTI15_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE15]();
    }
}

/**
  * @} (End of EXTI_ISRs)
  */

/*****************************< End of Function Implementations *****************************/

