/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 30 Sep 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : OS_program.c               *****************/
/****************************************************************/

/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL *****************************/
#include "STK_interface.h"
/*****************************< Services *****************************/
#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"
/*****************************< Global Variable Section *****************************/
static TCB_t OS_Task[NUMBER_OF_TASKS];
/*****************************< Function Implementations *****************************/
Std_ReturnType OS_CreateTask(u8 Copy_Priority, u16 Copy_Periodicity,u8 Copy_FirstDelay, void (*Copy_pf)(void))
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if(Copy_Priority < NUMBER_OF_TASKS && Copy_pf != NULL)
    {
        OS_Task[Copy_Priority].Periodicity = Copy_Periodicity;
        OS_Task[Copy_Priority].FirstDelay = Copy_FirstDelay;
        OS_Task[Copy_Priority].pf = Copy_pf;

        Local_FunctionStatus = E_OK;
    }
    else
    {
        Local_FunctionStatus = E_NOT_OK;
    }

    return Local_FunctionStatus;  
}

void OS_StartScheduler(void)
{
    /**< Init STK */
    MCAL_STK_vInit();
    /**< Run  Scheduler each 1 msec */
    MCAL_STK_SetIntervalPeriodic(TICK_MICROSECONDS, OS_Scheduler);
}

static u8 TickCount = 0;

static void OS_Scheduler(void)
{
    for(u8 Count = 0; Count < NUMBER_OF_TASKS; Count++)
    {
        if((TickCount % OS_Task[Count].Periodicity) == 0)
        {
            OS_Task[Count].pf();
        }
    }   

    TickCount++;
    TickCount*=TICK_MICROSECONDS;
}