/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 6 Sep 2023                 *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : NVIC_interface.h           *****************/
/****************************************************************/
#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

typedef u8          IRQn_Type;


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
 * @param[in] IRQn          The interrupt number (IRQn_Type) to set the priority for.
 * @param[in] Copy_Priority The priority level to set (0 to 255, with 0 being the highest).
 *
 * @return Std_ReturnType
 *   - E_OK     : Priority set successfully.
 *   - E_NOT_OK : An error occurred (invalid interrupt number or priority level).
 */
Std_ReturnType MCAL_NVIC_SetPriority(IRQn_Type IRQn, u32 Copy_Priority);

/**
 * @brief Get the priority of a specific interrupt in the NVIC.
 *
 * This function retrieves the priority of the specified interrupt in the NVIC.
 *
 * @param[in] IRQn The interrupt number (IRQn_Type) to get the priority for.
 *
 * @return u32
 *   - The priority level of the interrupt (0 to 255, with 0 being the highest).
 */
Std_ReturnType MCAL_NVIC_GetPriority(IRQn_Type IRQn);

/**
 * @} (end of group NVIC_Control)
 */


 








#endif /**< NVIC_INTERFACE_H_ */