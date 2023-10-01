/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 30 Sep 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : OS_private.h               *****************/
/****************************************************************/
#ifndef OS_PRIVATE_H_
#define OS_PRIVATE_H_

/**
 * @brief A struct representing a task in the operating system.
 *
 * This struct represents a task in the operating system. It contains the task's
 * priority, periodicity, task function, and first delay.
 */
typedef struct {
    u16 Periodicity;                /**< The periodicity of the task in microsecond. */
    void (*OS_pfSetTask)(void);     /**< A pointer to the function that implements the task. */
    u8 FirstDelay;                  /**< The initial delay of the task in ticks. */
    /**< The current state of the task's scheduler. */
} OS_Task_t;

/**
 * @brief An array containing the registered tasks for the operating system.
 *
 * This array holds the registered tasks for the operating system. Each task is represented
 * by a "SOS_Task_t" structure.
 */
static OS_Task_t OS_Tasks[OS_NUMBER_TASKS] = {NULL};

/**
 * @addtogroup PrivateFunctions
 * @{
 */

/**
 * @brief Scheduler function for the operating system.
 *
 * This function is responsible for executing tasks according to their specified periodicity.
 * It iterates through the task list, and if a task is ready to run (its first delay has expired),
 * it calls the task function. The first delay is decremented at each scheduler tick until it reaches zero,
 * indicating that the task is ready to run.
 *
 * @note This function should be associated with the system tick timer using the OS_StartScheduler function.
 * @note Ensure that tasks have been created and added to the scheduler using the OS_CreateTask function before calling this.
 *
 * @return None.
 */
static void OS_SetScheduler(void);

/**
 * @} (End of PrivateFunctions)
 */


#endif /**< OS_PRIVATE_H_ */