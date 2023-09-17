/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 26 Aug 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : RCC_program.c              *****************/
/****************************************************************/

/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL *****************************/
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


Std_ReturnType Mcal_Rcc_InitSysClock(void)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    #if RCC_SYSCLK == RCC_HSE
        
        /**< Select which External CLK to will be a CLK system */
        #if RCC_CLK_BYPASS == RCC_RC_CLK_
            SET_BIT(RCC_CR, RCC_CR_HSEBYP); /**< choose RC as a SYSCLK */
        #elif RCC_CLK_BYPASS == RCC_CRYSTAL_CLK_
            CLR_BIT(RCC_CR, RCC_CR_HSEBYP); /**< choose CRYSTAL as a SYSCLK */
        #else 
            #error "Wrong Choice !!"
        #endif /**< RCC_CLK_BYPASS */

        /**< Enable HSE*/
        SET_BIT(RCC_CR, RCC_CR_HSEON);

        /**< Wait until the CLK be stable */
        while(!GET_BIT(RCC_CR, RCC_CR_HSERDY));

        /**< Select HSE as a SYSCLK */
        RCC_CFGR = 0x00000001;

        Local_FunctionStatus = E_OK;

    #elif RCC_SYSCLK == RCC_HSI
        /**< Enable HSI */
        SET_BIT(RCC_CR, RCC_CR_HSION);

        /**< Wait until the CLK be stable */
        while(!GET_BIT(RCC_CR, RCC_CR_HSIRDY));

        /**< Select HSI as a SYSCLK  */
        RCC_CFGR = 0x00000000;

        Local_FunctionStatus = E_OK;

    #elif RCC_SYSCLK == RCC_PLL


    #else
        #error "Wrong Choice !!"

    #endif /**< RCC_SYSCLK */

    return Local_FunctionStatus;
}

Std_ReturnType Mcal_Rcc_EnablePeripheral(u8 Copy_PeripheralId, u8 Copy_BusId)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    switch(Copy_BusId)
    {
        case RCC_AHB:
            SET_BIT(RCC_AHBENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
        break;

        case RCC_APB1:
            SET_BIT(RCC_APB1ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
        break;

        case RCC_APB2:
            SET_BIT(RCC_APB2ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
        break;

        default:
            Local_FunctionStatus = E_NOT_OK;
        break;
    }

    return Local_FunctionStatus;
}

Std_ReturnType Mcal_Rcc_DisablePeripheral(u8 Copy_PeripheralId, u8 Copy_BusId)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    switch(Copy_BusId)
    {
        case RCC_AHB:
            CLR_BIT(RCC_AHBENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
        break;

        case RCC_APB1:
            CLR_BIT(RCC_APB1ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
        break;

        case RCC_APB2:
            CLR_BIT(RCC_APB2ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
        break;

        default:
            Local_FunctionStatus = E_NOT_OK;
        break;
    }

    return Local_FunctionStatus;
}