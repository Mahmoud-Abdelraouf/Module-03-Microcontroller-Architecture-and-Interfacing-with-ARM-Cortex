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
 * This function initializes the SysTick timer with the specified reload value. The timer is configured to use the processor clock
 * or a divided clock source based on the configuration settings. It also allows generating an interrupt when the timer reaches zero.
 * This function sets the initial value of the timer and prepares it for counting down.
 *
 * @param[in] Copy_Ticks The number of clock cycles to reload the SysTick timer with.
 *
 * @note The actual time duration for the timer to reach zero depends on the clock frequency and the value passed as `Copy_Ticks`.
 * 
 * @warning This function should be used carefully, as improper configuration may lead to unexpected behavior.
 *
 * @return None.
 */
void MCAL_STK_Init(u32 Copy_Ticks);

/**
 * @brief Starts the SysTick timer.
 *
 * This function starts the SysTick timer. Once the timer is started, it will count down from the reload value specified in the
 * "STK_Init" function until it reaches zero. When the timer reaches zero, it will generate an interrupt and reload with
 * the initial value.
 *
 * @param None.
 *
 * @return None.
 */
void MCAL_STK_Start(void);

/**
 * @brief Stops the SysTick timer.
 *
 * This function stops the SysTick timer. Once the timer is stopped, it will no longer count down or generate interrupts.
 *
 * @param None.
 *
 * @return None.
 */
void MCAL_STK_Stop(void);

/**
 * @brief Resets the SysTick timer.
 *
 * This function disables the SysTick timer, clears the current value, sets the reload value to 0,
 * and clears the count flag.
 *
 * @param None.
 *
 * @return None.
 */
void MCAL_STK_Reset(void);

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
u32 MCAL_STK_GetRemainingCounts(void);

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
u32 MCAL_STK_GetElapsedCounts(void);

/**
 * @brief Blocks the CPU for the specified number of microseconds.
 *
 * This function blocks the CPU for the specified number of microseconds using the SysTick timer. The function calculates the
 * number of ticks required to wait for the specified number of microseconds based on the current system clock frequency and
 * the reload value of the SysTick timer.
 *
 * @param[in] Copy_u32Microseconds The number of microseconds to wait. This value should be less than or equal to 16777215 (0x00FFFFFF).
 *
 * @note The maximum delay achievable with this function, when the SysTick timer clock is 1 MHz, is approximately 16 seconds.
 *
 * @return E_OK if the delay was successful, E_NOT_OK if an error occurred.
 */
Std_ReturnType MCAL_STK_SetBusyWait(u32 Copy_Microseconds);

/**
 * @brief Blocks the CPU for the specified number of milliseconds.
 *
 * This function blocks the CPU for the specified number of milliseconds using the SysTick timer. The function calculates the
 * number of ticks required to wait for the specified number of milliseconds based on the current system clock frequency and
 * the reload value of the SysTick timer.
 *
 * @param[in] Copy_Milliseconds The number of milliseconds to wait. This value should be less than or equal to 16777215 (0x00FFFFFF).
 *
 * @note The maximum delay achievable with this function, when the SysTick timer clock is 1 MHz, is approximately 16 seconds.
 * 
 * @return E_OK if the delay was successful, E_NOT_OK if an error occurred.
 */
Std_ReturnType MCAL_STK_SetDelay_ms(f32 Copy_Milliseconds);


/**
 * @brief Set a single-shot interval with a specified callback function.
 *
 * This function configures the SysTick timer to generate a single-shot interval after the specified number of microseconds.
 * When the interval elapses, the provided callback function will be called.
 *
 * @param[in] Copy_Microseconds The duration of the interval in microseconds.
 * @param[in] Copy_Callback A pointer to the callback function to execute when the interval elapses.
 *
 * @return E_OK if the interval configuration was successful, E_NOT_OK if an error occurred.
 */
Std_ReturnType MCAL_STK_SetIntervalSingle(u32 Copy_Microseconds, void (*Copy_Callback)(void));

/**
 * @brief Set a periodic interval with a specified callback function.
 *
 * This function configures the SysTick timer to generate periodic intervals with the specified duration in microseconds.
 * When each interval elapses, the provided callback function will be called.
 *
 * @param[in] Copy_Microseconds The duration of each interval in microseconds.
 * @param[in] Copy_Callback A pointer to the callback function to execute for each interval.
 *
 * @return E_OK if the interval configuration was successful, E_NOT_OK if an error occurred.
 */
Std_ReturnType MCAL_STK_SetIntervalPeriodic(u32 Copy_Microseconds, void (*Copy_Callback)(void));




#endif /**< STK_INTERFACE_H_ */
