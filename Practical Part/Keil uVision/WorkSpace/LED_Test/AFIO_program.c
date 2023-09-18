/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 12 Sep 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : NVIC_program.c             *****************/
/****************************************************************/

/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include <stdbool.h>
#include "BIT_MATH.h"
/*****************************< MCAL *****************************/
#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"
/*****************************< Function Implementations *****************************/
Std_ReturnType MCAL_AFIO_SetRemap(AFIO_RemapConfig_t Copy_RemapConfig) 
{
    /**< Check if the remapConfig is within valid range */ 
    if (Copy_RemapConfig > AFIO_REMAP_CUSTOM)
    {
        return E_NOT_OK;  /**< Invalid configuration */ 
    }

    // Configure the remap settings
    AFIO->MAPR &= ~AFIO_MAPR_SWJ_CFG_Msk;  /**< Clear SWJ_CFG bits */ 

    switch (Copy_RemapConfig) 
    {
        case AFIO_REMAP_NONE:
            /**< No remap, SWJ ON without trace (default) */ 
            break;
        case AFIO_REMAP_FULL:
            /**< Full SWJ (JTAG-DP + SW-DP) but without NJTRST */ 
            AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_001;
            break;
        case AFIO_REMAP_PARTIAL:
            /**< JTAG-DP Disabled and SW-DP Enabled */ 
            AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_010;
            break;
        case AFIO_REMAP_CUSTOM:
            /**< Custom remap (user-defined) */ 
            break;
        default:
            return E_NOT_OK;  /**< Invalid configuration */ 
    }

    return E_OK;  /**<  Configuration successful */
}

Std_ReturnType MCAL_AFIO_SetDebugPort(u8 Copy_DebugConfig)
{
    /**< Check if the DebugConfig value is within a valid range */ 
    if (Copy_DebugConfig > AFIO_MAPR_SWJ_CFG_Msk)
    {
        return E_NOT_OK;  /**< Invalid DebugConfig value */ 
    }

    /**< Clear the SWJ_CFG bits in the AFIO_MAPR register */ 
    AFIO->MAPR &= ~AFIO_MAPR_SWJ_CFG_Msk;

    /**< Set the SWJ_CFG bits with the provided DebugConfig value */ 
    AFIO->MAPR |= (Copy_DebugConfig & AFIO_MAPR_SWJ_CFG_Msk);

    return E_OK;  /**< Configuration successful */ 
}

void AFIO_MAPR_ADC2ETRGREGRemap(bool Copy_Enable) 
{
    u32 regValue = AFIO->MAPR;
    if (Copy_Enable) 
    {
        regValue |= AFIO_MAPR_ADC2_ETRGREG_Msk;
    } 
    else 
    {
        regValue &= ~AFIO_MAPR_ADC2_ETRGREG_Msk;
    }
    AFIO->MAPR = regValue;
}

void AFIO_MAPR_ADC2ETRGINJRemap(bool Copy_Enable) 
{
    u32 regValue = AFIO->MAPR;
    if (Copy_Enable)
    {
        regValue |= AFIO_MAPR_ADC2_ETRGINJ_Msk;
    }
    else 
    {
        regValue &= ~AFIO_MAPR_ADC2_ETRGINJ_Msk;
    }
    AFIO->MAPR = regValue;
}

Std_ReturnType MCAL_AFIO_SetEXTIConfiguration(u8 Copy_Line, u8 Copy_PortMap)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    /**< Check if the provided EXTI line or PortMap value is out of range */ 
    if (Copy_Line > 15 || Copy_PortMap > 2)
    {
        return Local_FunctionStatus;
    }

    /**< Calculate the index of the EXTI control register for the specified line */ 
    u8 Local_RegIndex = Copy_Line / 4;

    /**< Calculate the bit position within the EXTI control register for the specified line */ 
    Copy_Line %= 4;

    /**< Clear the bits that correspond to the EXTI line within the EXTI control register */ 
    AFIO->EXTICR[Local_RegIndex] &= ~((0x0F) << (Copy_Line * 4));

    /**< Set the new PortMap value for the EXTI line within the EXTI control register */ 
    AFIO->EXTICR[Local_RegIndex] |= Copy_PortMap << (Copy_Line * 4);

    /**< Configuration is successful, set the function status to E_OK */ 
    Local_FunctionStatus = E_OK;

    return Local_FunctionStatus;
}
/*****************************< End of Function Implementations *****************************/
