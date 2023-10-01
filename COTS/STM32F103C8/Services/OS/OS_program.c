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
/*****************************< SERVICES *****************************/
#include "OS_interface.h"
#include "OS_config.h"
#include "OS_private.h"
/****************************************< FUNCTIONS IMPLEMENTATION ****************************************/
/**
 * @addtogroup PublicFunctions
 * @{
 */

Std_ReturnType OS_CreateTask(u8 Copy_TaskPriority, u16 Copy_TaskPeriodicity,u8 Copy_FirstDelay, TaskFunction_t TaskFunction)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    /**< Check if the task function pointer is valid */
    if(TaskFunction != NULL)
    {
        /**< Set task parameters in the task scheduler */
        OS_Tasks[Copy_TaskPriority].Periodicity = Copy_TaskPeriodicity;
        OS_Tasks[Copy_TaskPriority].OS_pfSetTask = TaskFunction;
        OS_Tasks[Copy_TaskPriority].FirstDelay = Copy_FirstDelay;
        
        /**< Configured successfully */
        Local_FunctionStatus = E_OK;
    }
    else
    {
        /**< Invalid pointer to function  */
        Local_FunctionStatus = E_NOT_OK;
    }

    return Local_FunctionStatus;
}

void OS_StartScheduler(void) 
{
    /**< Initialize the system tick timer */
    MCAL_STK_vInit();

    /**< Set up the system tick timer for periodic scheduling with the specified tick time and scheduler function */
    MCAL_STK_SetIntervalPeriodic(OS_TICK_TIME, OS_SetScheduler);
}

/**
 * @} (End of PublicFunctions)
 */

/**
 * @addtogroup PrivateFunctions
 * @{
 */

static void OS_SetScheduler(void) 
{
    /**< Iterate through the task list */
    for (u8 Count = 0; Count < OS_NUMBER_TASKS; Count++) 
    {
        /**< Check if the task has a valid function pointer */
        if (OS_Tasks[Count].OS_pfSetTask != NULL) 
        {
            /**< Check if the task's first delay has expired */
            if (OS_Tasks[Count].FirstDelay == 0) 
            {
                /**< If yes, execute the task and reset the first delay */
                OS_Tasks[Count].FirstDelay = ((OS_Tasks[Count].Periodicity) - 1);
                OS_Tasks[Count].OS_pfSetTask();
            } else 
            {
                /**< If not, decrement the first delay */
                OS_Tasks[Count].FirstDelay--;
            }
        }
    }
}

/**
 * @} (End of PrivateFunctions)
 */
/****************************************< End of FUNCTIONS IMPLEMENTATION ****************************************/
