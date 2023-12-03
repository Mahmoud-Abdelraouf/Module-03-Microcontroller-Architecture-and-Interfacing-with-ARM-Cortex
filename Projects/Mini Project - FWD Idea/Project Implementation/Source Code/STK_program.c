/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 14 Sep 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : STK_program.c              *****************/
/****************************************************************/

/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL *****************************/
#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

/**
 * @defgroup Public_Functions STK Driver
 * @{
 */

void MCAL_STK_Init(u32 Copy_Ticks)
{
    /**< Disable SysTick timer */
    STK->CTRL &= ~STK_CTRL_ENABLE_MASK;

    /**< Configure SysTick timer to use the processor clock */
    #if STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_1
        STK -> CTRL |= STK_CTRL_CLKSOURCE_MASK;             /**< Set bit 2 to use the processor clock */
    #elif STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_8
        STK->CTRL &= ~STK_CTRL_CLKSOURCE_MASK;              /**< Clear bit 2 to use the processor clock/8 */
    #else 
        #error "Invalid STK_CTRL_CLKSOURCE value. Please choose STK_CTRL_CLKSOURCE_1 or STK_CTRL_CLKSOURCE_8."
    #endif

    /**< Generate interrupt when it reaches zero */
    #if STK_CTRL_TICKINT == STK_CTRL_TICKINT_ENABLE
        STK->CTRL |= STK_CTRL_TICKINT_MASK;      /**< Set bit 1 to enable interrupt when the counter reaches zero */
    #elif STK_CTRL_TICKINT == STK_CTRL_TICKINT_DISABLE
        STK->CTRL &= ~STK_CTRL_TICKINT_MASK;     /**< Clear bit 1 to enable interrupt when the counter reaches zero */
    #else
        #error "Invalid STK_CTRL_TICKINT value. Please choose STK_CTRL_TICKINT_ENABLE or STK_CTRL_TICKINT_DISABLE."
    #endif

    /**< Load the initial value into the SysTick timer */
    STK->LOAD = Copy_Ticks;  
}

void MCAL_STK_Start(void)
{
    /**< Enable SysTick timer */
    STK->CTRL |= STK_CTRL_ENABLE_MASK;
}

void MCAL_STK_Stop(void)
{
    /**< Disable SysTick timer */
    STK->CTRL &= ~STK_CTRL_ENABLE_MASK;
}

void MCAL_STK_Reset(void)
{
    /**< Disable SysTick timer */
    STK->CTRL &= ~STK_CTRL_ENABLE_MASK;

    /**< Clear the current value */
    STK->VAL = 0;

    /**< Set the reload value to 0 */
    STK->LOAD = 0;

    /**< Clear the count flag */
    STK->CTRL &= ~STK_CTRL_COUNTFLAG_MASK;
}

u32 MCAL_STK_GetRemainingCounts(void)
{
    /* Get the current value of the SysTick timer */
    return STK->VAL;
}

u32 MCAL_STK_GetElapsedCounts(void)
{
    static u32 Local_PreviousValue = 0;  /**< Store the previous SysTick timer value */ 
    u32 Local_CurrentValue = STK->VAL;   /**< Get the current SysTick timer value */ 
    u32 Local_ElapsedTicks;

    /**< Check if the timer has wrapped around (current value is less than the previous value) */ 
    if (Local_CurrentValue < Local_PreviousValue) 
    {
        /**< Calculate elapsed ticks considering timer overflow */ 
        Local_ElapsedTicks = Local_PreviousValue - Local_CurrentValue;
    } 
    else 
    {
        /**< Calculate elapsed ticks without timer overflow */ 
        Local_ElapsedTicks = STK->LOAD - (Local_CurrentValue - Local_PreviousValue);
    }

    /**< Update the previous value for the next call */ 
    Local_PreviousValue = Local_CurrentValue;

    return Local_ElapsedTicks;
}

Std_ReturnType MCAL_STK_SetBusyWait(u32 Copy_Microseconds)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    /**< Calculate the number of ticks required for the given microseconds */ 
    u32 TicksRequired = (Copy_Microseconds * (STK_AHB_CLK / 1000000));

    /**< Check if the ticks required is within the valid range */ 
    if (TicksRequired <= 0x00FFFFFF) 
    {
        /**< Set the reload value of the SysTick timer */ 
        STK->LOAD = TicksRequired;

        /**< Enable the SysTick timer */ 
        STK->CTRL |= STK_CTRL_ENABLE_MASK;

        /**< Wait until the COUNTFLAG bit is set (indicates timer has counted down to zero) */ 
        while (!(STK->CTRL & STK_CTRL_COUNTFLAG_MASK));

        /**< Disable the SysTick timer */ 
        STK->CTRL &= ~STK_CTRL_ENABLE_MASK;

        /**< Reset the timer value */ 
        STK->VAL = 0;

        Local_FunctionStatus = E_OK;
    }

    return Local_FunctionStatus;
}
  
Std_ReturnType MCAL_STK_SetDelay_ms(f32 Copy_Milliseconds)
{
    /**< Calculate the number of ticks required to wait for the specified number of milliseconds */
    u32 Local_u32Ticks = (u32)((Copy_Milliseconds * STK_AHB_CLK) / 1000.0);

    /**< Check if TicksRequired is within the valid range */
    if (Local_u32Ticks <= 0x00FFFFFF)
    {
        /**< Configure SysTick timer with the calculated number of ticks */
        STK->LOAD = Local_u32Ticks;

        /**< Enable SysTick timer */
        STK->CTRL |= STK_CTRL_ENABLE_MASK;

        /**< Wait until the SysTick timer reaches zero */
        while (!(STK->CTRL & STK_CTRL_COUNTFLAG_MASK));

        /**< Disable SysTick timer */
        STK->CTRL &= ~STK_CTRL_ENABLE_MASK;

        /**< Reset the timer value */ 
        STK->VAL = 0;

        /**< Return success status */
        return E_OK;
    }
    else
    { 
        /**< Return error status */
        return E_NOT_OK;
    }
}

Std_ReturnType MCAL_STK_SetIntervalSingle(u32 Copy_Microseconds, void (*Copy_Callback)(void))
{

}

Std_ReturnType MCAL_STK_SetIntervalPeriodic(u32 Copy_Microseconds, void (*Copy_Callback)(void))
{

}

/**
 * @} // End of Public_Functions
 */

/**
 * @defgroup IRQ_Handlers IRQ Handlers
 * @{
 */

void SysTick_Handler(void)
{

}

/**
 * @} // End of IRQ_Handlers
 */
