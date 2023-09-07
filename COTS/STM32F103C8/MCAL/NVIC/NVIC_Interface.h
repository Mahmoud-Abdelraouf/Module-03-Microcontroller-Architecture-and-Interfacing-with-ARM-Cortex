/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 6 Sep 2023                 *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : NVIC_interface.h           *****************/
/****************************************************************/
#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

/**
 * @brief Type definition for Cortex-M microcontroller interrupt numbers.
 *
 * This typedef defines the data type for representing interrupt numbers in Cortex-M
 * microcontroller architectures. Each interrupt is identified by a unique number,
 * which is used when configuring interrupt priorities and enabling/disabling interrupts.
 *
 * The specific range and mapping of interrupt numbers can vary depending on the
 * microcontroller model and vendor.
 *
 * @note The actual implementation may vary depending on the microcontroller architecture.
 *       This typedef is often defined by the microcontroller's CMSIS (Cortex Microcontroller
 *       Software Interface Standard) header file.
 */
typedef u8 IRQn_Type;

/**
 * @brief Placeholder Value for Priority Group and Sub-Group
 *
 * This macro defines a placeholder value to be used as the `Copy_GroupPriority` 
 * and `Copy_SubPriority` parameters in the `MCAL_NVIC_vSetPriority` function.
 * 
 * When the `PRIORITY_GROUPING` is set to `_0GROUP_16SUB`, the `NONE` macro can be 
 * used as the `Copy_GroupPriority` parameter to indicate that no group priority is 
 * assigned.
 * 
 * When the `PRIORITY_GROUPING` is set to `_16GROUP_0SUB`, the `NONE` macro can be 
 * used as the `Copy_SubPriority` parameter to indicate that no sub-priority is assigned.
 * 
 * Example Usage:
 * @code
 * /// Using NONE as Copy_GroupPriority when PRIORITY_GROUPING is _0GROUP_16SUB
 * MCAL_NVIC_vSetPriority(MyIRQ, NONE, 5);
 *
 * /// Using NONE as Copy_SubPriority when PRIORITY_GROUPING is _16GROUP_0SUB
 * MCAL_NVIC_vSetPriority(MyIRQ, 10, NONE);
 * @endcode
 */
#define NONE            ((INVALID_VALUE)-1)         
         
/**
 * @defgroup NVIC_Control NVIC Control Functions
 * @brief Functions to control the Nested Vectored Interrupt Controller (NVIC).
 * @{
 */

/**
 * @brief Enable a specific interrupt in the NVIC.
 *
 * This function enables the specified interrupt in the NVIC.
 *
 * @param[in] Copy_IRQn The interrupt number (IRQn_Type) to enable.
 *
 * @return Std_ReturnType
 *   - E_OK     : Interrupt enabled successfully.
 *   - E_NOT_OK : An error occurred (invalid interrupt number).
 */
Std_ReturnType MCAL_NVIC_EnableIRQ(IRQn_Type Copy_IRQn);

/**
 * @brief Disable a specific interrupt in the NVIC.
 *
 * This function disables the specified interrupt in the NVIC.
 *
 * @param[in] Copy_IRQn The interrupt number (IRQn_Type) to disable.
 *
 * @return Std_ReturnType
 *   - E_OK     : Interrupt disabled successfully.
 *   - E_NOT_OK : An error occurred (invalid interrupt number).
 */
Std_ReturnType MCAL_NVIC_DisableIRQ(IRQn_Type Copy_IRQn);

/**
 * @brief Set a specific interrupt as pending in the NVIC.
 *
 * This function sets the specified interrupt as pending in the NVIC.
 *
 * @param[in] Copy_IRQn The interrupt number (IRQn_Type) to set as pending.
 *
 * @return Std_ReturnType
 *   - E_OK     : Interrupt set as pending successfully.
 *   - E_NOT_OK : An error occurred (invalid interrupt number).
 */
Std_ReturnType MCAL_NVIC_SetPendingIRQ(IRQn_Type Copy_IRQn);

/**
 * @brief Clear the pending status of a specific interrupt in the NVIC.
 *
 * This function clears the pending status of the specified interrupt in the NVIC.
 *
 * @param[in] Copy_IRQn The interrupt number (IRQn_Type) to clear as pending.
 *
 * @return Std_ReturnType
 *   - E_OK     : Pending status cleared successfully.
 *   - E_NOT_OK : An error occurred (invalid interrupt number).
 */
Std_ReturnType MCAL_NVIC_ClearPendingIRQ(IRQn_Type Copy_IRQn);

/**
 * @brief Get the pending status of a specific interrupt in the NVIC.
 *
 * This function checks if the specified interrupt is pending in the NVIC.
 *
 * @param[in]  Copy_IRQn            The interrupt number (IRQn_Type) to check.
 * @param[out] Copy_ReturnPendingFlag Pointer to a variable where the pending status will be stored.
 *                                  This will be set to 1 if the interrupt is pending, or 0 if it's not.
 *
 * @return Std_ReturnType
 *   - E_OK     : Interrupt is pending, and the pending status is returned in 'Copy_ReturnPendingFlag'.
 *   - E_NOT_OK : An error occurred (invalid interrupt number), and 'Copy_ReturnPendingFlag' is not modified.
 */
Std_ReturnType MCAL_NVIC_GetPendingIRQ(IRQn_Type Copy_IRQn, u8 *Copy_ReturnPendingFlag);

/**
 * @brief Set the priority of a specific interrupt in the NVIC.
 *
 * This function sets the priority of the specified interrupt in the NVIC.
 *
 * @param[in] Copy_IRQn     The interrupt number (IRQn_Type) to set the priority for.
 * @param[in] Copy_Priority The priority level to set (0 to 255, with 0 being the highest).
 *
 * @return Std_ReturnType
 *   - E_OK     : Priority set successfully.
 *   - E_NOT_OK : An error occurred (invalid interrupt number or priority level).
 */
Std_ReturnType MCAL_NVIC_xSetPriority(IRQn_Type Copy_IRQn, u32 Copy_Priority);

/**
 * @brief Set the priority of a specific interrupt in the NVIC.
 *
 * This function sets the priority of the specified interrupt in the NVIC.
 *
 * @param[in] Copy_IRQn         The interrupt number (IRQn_Type) to set the priority for.
 * @param[in] Copy_GroupPriority The group priority level (0 to 7, with 0 being the highest).
 * @param[in] Copy_SubPriority  The sub-priority level within the group (0 to 3).
 *
 * @return Std_ReturnType
 *   - E_OK     : Priority set successfully.
 *   - E_NOT_OK : An error occurred (invalid interrupt number or priority levels).
 *
 * @note The priority levels must be within the valid range for your system.
 * @note When using PRIORITY_GROUPING equal to _16GROUP_0SUB, the Copy_SubPriority should be NONE.
 * @note When using PRIORITY_GROUPING equal to _0GROUP_16SUB, the Copy_GroupPriority should be NONE.
 *
 * @see NVIC_config.h for details on PRIORITY_GROUPING.
 */
Std_ReturnType MCAL_NVIC_vSetPriority(IRQn_Type Copy_IRQn, u8 Copy_GroupPriority, u8 Copy_SubPriority);

/**
 * @brief Get the priority of a specific interrupt in the NVIC.
 *
 * This function retrieves the priority of the specified interrupt in the NVIC.
 *
 * @param[in]  IRQn            The interrupt number (IRQn_Type) to get the priority for.
 * @param[out] Copy_Priority   A pointer to a variable that will store the retrieved priority.
 *
 * @return Std_ReturnType
 *   - E_OK     : Priority retrieved successfully, and the value is stored in Copy_Priority.
 *   - E_NOT_OK : An error occurred (invalid interrupt number or Copy_Priority pointer is NULL).
 */
Std_ReturnType MCAL_NVIC_xGetPriority(IRQn_Type IRQn, u8 *Copy_Priority);

/**
 * @} (end of group NVIC_Control)
 */


#endif /**< NVIC_INTERFACE_H_ */
