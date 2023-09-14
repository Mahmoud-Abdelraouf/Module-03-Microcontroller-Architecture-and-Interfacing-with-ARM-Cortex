/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 14 Sep 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : STK_interface.h            *****************/
/****************************************************************/
#ifndef STK_INTERFACE_H_
#define STK_INTERFACE_H_

/**
 * @brief Initializes the SysTick timer with the specified reload value.
 *
 * This function initializes the SysTick timer with the specified reload value. The timer is configured to generate an interrupt
 * when it reaches zero, and then reloads the timer with the specified value. The interrupt can be used to implement a periodic
 * timebase for the application.
 *
 * @param[in] void.
 *
 * @return None.
 */
void STK_Init(u32 Copy_Ticks);

/**
 * @brief Starts the SysTick timer.
 *
 * This function starts the SysTick timer. Once the timer is started, it will count down from the reload value specified in the
 * `STK_voidInit` function until it reaches zero. When the timer reaches zero, it will generate an interrupt and reload with
 * the initial value.
 *
 * @param None.
 *
 * @return None.
 */
void STK_Start(void);

/**
 * @brief Stops the SysTick timer.
 *
 * This function stops the SysTick timer. Once the timer is stopped, it will no longer count down or generate interrupts.
 *
 * @param None.
 *
 * @return None.
 */
void STK_Stop(void);


/**
 * @brief Resets the SysTick timer.
 *
 * This function disables the SysTick timer, clears the current value, sets the reload value to 0,
 * and clears the count flag.
 *
 * @param None
 *
 * @return None
 */
void STK_Reset(void);

/**
 * @brief Gets the current value of the SysTick timer.
 *
 * This function gets the current value of the SysTick timer. The timer value represents the number of ticks remaining until
 * the timer reaches zero.
 *
 * @param None.
 *
 * @return The current value of the SysTick timer.
 */
Std_ReturnType STK_GetRemainingCounts(void);

/**
 * @brief Get the number of elapsed ticks since the last SysTick timer reset.
 *
 * This function calculates the number of ticks that have elapsed since the last reset of the SysTick timer.
 * The elapsed time is calculated as the difference between the value of the SysTick timer when this function
 * is called and the initial value of the timer when it was last reset.
 *
 * @note This function assumes that the SysTick timer is running and has not overflowed since it was last reset.
 * If the timer has overflowed, the elapsed ticks value will be incorrect and the function may return unexpected results.
 *
 * @param None.
 * 
 * @return The number of elapsed ticks as an unsigned 32-bit integer.
 */
Std_ReturnType STK_GetElapsedCounts(void);

/**
 * @brief Blocks the CPU for the specified number of microseconds.
 *
 * This function blocks the CPU for the specified number of microseconds using the SysTick timer. The function calculates the
 * number of ticks required to wait for the specified number of microseconds based on the current system clock frequency and
 * the reload value of the SysTick timer.
 *
 * @param[in] Copy_u32Microseconds The number of microseconds to wait. This value should be less than or equal to 16777215 (0x00FFFFFF).
 *
 * @return None.
 */
Std_ReturnType STK_SetBusyWait(u32 Copy_Microseconds);


/**
 * @brief Blocks the CPU for the specified number of milliseconds.
 *
 * This function blocks the CPU for the specified number of microseconds using the SysTick timer. The function calculates the
 * number of ticks required to wait for the specified number of microseconds based on the current system clock frequency and
 * the reload value of the SysTick timer.
 *
 * @param[in] Copy_u32Milliseconds The number of milliseconds to wait. This value should be less than or equal to 16777215 (0x00FFFFFF).
 *
 * @return None.
 */
void STK_SetDelay(f32 Copy_Milliseconds);


/**
 * @brief Calls a function after the specified number of microseconds.
 *
 * This function sets a callback function to be called after the specified number of microseconds using the SysTick timer. The
 * function calculates the number of ticks required to wait for the specified number of microseconds based on the current system
 * clock frequency and the reload value of the SysTick timer. When the requested delay has elapsed, the callback function will be
 * called.
 *
 * @param[in] Copy_u32Microseconds The number of microseconds to wait. This value should be less than or equal to 16777215 (0x00FFFFFF).
 * @param[in] Copy_pfCallback The callback function to call when the requested delay has elapsed.
 *
 * @return None.
 */
Std_ReturnType STK_SetIntervalSingle(u32 Copy_Microseconds, void (*Copy_Callback)(void));

/**
 * @brief Calls a function periodically with the specified period in microseconds.
 *
 * This function sets a callback function to be called periodically with the specified period using the SysTick timer. The
 * function calculates the number of ticks required to wait for the specified period based on the current system clock frequency
 * and the reload value of the SysTick timer. When the requested period has elapsed, the callback function will be called.
 *
 * @param[in] Copy_u32Microseconds The period of the callback function in microseconds. This value should be less than or equal to 16777215 (0x00FFFFFF).
 * @param[in] Copy_pfCallback The callback function to call periodically.
 *
 * @return None.
 */
Std_ReturnType STK_SetIntervalPeriodic(u32 Copy_Microseconds, void (*Copy_Callback)(void));




#endif /**< STK_INTERFACE_H_ */
