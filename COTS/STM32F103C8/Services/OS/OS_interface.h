/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 30 Sep 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : OS_interface.h             *****************/
/****************************************************************/
#ifndef OS_INTERFACE_H_
#define OS_INTERFACE_H_

/**
 * @addtogroup OS OS_Configuration
 * @{
 */

/**
 * @brief Typedef for Task Function Pointer
 *
 * This typedef defines a function pointer type for tasks used in the operating system.
 * A task function is a function that takes no arguments and returns void. It is typically
 * used to represent tasks that can be scheduled and executed by the operating system.
 *
 * Example Usage:
 * @code
 * TaskFunction_t myTaskFunction;
 *
 * void MyTask() {
 *     /// Task logic goes here
 * }
 *
 * myTaskFunction = MyTask;
 * @endcode
 */
typedef void (*TaskFunction_t)(void);

/**
 * @} (End of OS_Configuration)
 */

/**
 * @addtogroup PublicFunctions
 * @{
 */

/**
 * @brief Creates a task with the specified priority, periodicity, initial delay, and associated function.
 *
 * This function creates a task within the operating system scheduler. The task is defined by its priority,
 * execution periodicity (in system ticks), initial delay (in system ticks before the first execution),
 * and the function to be executed as the task body.
 *
 * @param[in] Copy_TaskPriority The priority level of the task, higher numbers indicating higher priority.
 * @param[in] Copy_TaskPeriodicity The periodicity of the task in system ticks.
 * @param[in] Copy_pfTask A pointer to the function representing the body of the task.
 * @param[in] Copy_FirstDelay The initial delay in system ticks before the first execution of the task.
 *
 * @note The priority is usually a numerical value where higher numbers indicate higher priority levels.
 * @note Periodicity determines how often the task runs, expressed in system ticks.
 * @note The initial delay specifies the number of system ticks before the task starts executing.
 * @note Ensure that the task function has a void return type and takes no parameters (void (*Copy_pfTask)(void)).
 *
 * @return
 *     - E_OK if the task was successfully created and added to the scheduler.
 *     - E_NOT_OK if an invalid function pointer is provided.
 * 
 * @note Tasks with lower priority values will run before tasks with higher priority values if they have the same periodicity.
 * @note The actual execution time of the task may vary slightly due to system timing.
 */
Std_ReturnType OS_CreateTask(u8 Copy_TaskPriority, u16 Copy_TaskPeriodicity,u8 Copy_FirstDelay, void (*Copy_pfTask)(void));

/**
 * @brief Starts the operating system scheduler.
 *
 * This function initializes the system tick timer and sets up the scheduler to run tasks periodically.
 * The system tick timer is configured with a tick time of 1 millisecond and is associated with the scheduler function.
 * After calling this function, the operating system scheduler begins executing tasks based on their specified periodicity.
 *
 * @note Ensure that tasks have been created and added to the scheduler using the OS_CreateTask function before calling this.
 * @note The scheduler function provided in the configuration should handle task execution and switching.
 *
 * @return None.
 */
void OS_StartScheduler(void);

/**
 * @} (End of PublicFunctions)
 */

#endif /**< OS_INTERFACE_H_ */