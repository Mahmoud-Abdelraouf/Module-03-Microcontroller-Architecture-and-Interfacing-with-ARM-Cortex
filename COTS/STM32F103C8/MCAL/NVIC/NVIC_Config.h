/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 6 Sep 2023                 *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : NVIC_config.h              *****************/
/****************************************************************/
#ifndef NVIC_CONFIG_H_
#define NVIC_CONFIG_H_

/**
 * @addtogroup User_Configuration
 * @{
 */

/**
 * @brief Total Number of Interrupts
 *
 * This macro defines the total number of interrupt sources in the system.
 * It is a user-configurable setting and is used to dimension data structures
 * related to interrupt handling.
 */
#define NUMBER_OF_INTERRUPTS            67

/**
 * @brief Maximum NVIC Interrupt Priority
 *
 * This macro defines the highest priority level that can be assigned to an
 * interrupt in the Nested Vectored Interrupt Controller (NVIC). Interrupts
 * with higher priority values have lower actual priorities. It is a
 * user-configurable setting.
 *
 * @note This macro is intended for use with the MCAL_NVIC_xSetPriority function
 *       which sets both group and sub-group priorities. If you are using the
 *       MCAL_NVIC_vSetPriority function which sets group and sub-group priorities
 *       separately, consider using the PRIORITY_GROUPING macro instead.
 */
#define NVIC_MAX_PRIORITY               15

/**
 * @brief Priority Grouping Options for NVIC (for MCAL_NVIC_vSetPriority)
 *
 * These macros define the available priority grouping options for the Nested
 * Vectored Interrupt Controller (NVIC) when using the MCAL_NVIC_vSetPriority function.
 * You can choose one of these options to configure how interrupt priorities are grouped.
 *
 * @attention These macros are intended for use with MCAL_NVIC_vSetPriority and should not
 * be used with MCAL_NVIC_xSetPriority.
 *
 * - _16GROUP_0SUB:  16 subgroups with 0 bits for sub-priority.
 * - _8GROUP_2SUB :   8 subgroups with 2 bits for sub-priority.
 * - _4GROUP_4SUB :   4 subgroups with 4 bits for sub-priority.
 * - _2GROUP_8SUB :   2 subgroups with 8 bits for sub-priority.
 * - _0GROUP_16SUB:  No grouping with 16 bits for sub-priority.
 */
#define PRIORITY_GROUPING   _4GROUP_4SUB


/**
 * @} User_Configuration
 */

#endif /**< NVIC_CONFIG_H_ */