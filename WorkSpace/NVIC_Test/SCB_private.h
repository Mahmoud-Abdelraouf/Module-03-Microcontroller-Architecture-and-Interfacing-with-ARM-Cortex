/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 7 Sep 2023                 *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : SCB_private.h              *****************/
/****************************************************************/
#ifndef SCB_PRIVATE_H_
#define SCB_PRIVATE_H_

/**< Base address of the SCB registers */
#define SCB_BASE_ADDRESS    0xE000ED00U

/**< SCB Registers */
#define SCB_CPUID           (*((volatile u32 *)(SCB_BASE_ADDRESS + 0x00))) /**< APPLICATION INTERRUPT AND RESET CONTROL REGISTER */
#define SCB_ICSR            (*((volatile u32 *)(SCB_BASE_ADDRESS + 0x04)))
#define SCB_VTOR            (*((volatile u32 *)(SCB_BASE_ADDRESS + 0x08)))
#define SCB_AIRCR           (*((volatile u32 *)(SCB_BASE_ADDRESS + 0x0C)))
#define SCB_SCR             (*((volatile u32 *)(SCB_BASE_ADDRESS + 0x10)))
#define SCB_CCR             (*((volatile u32 *)(SCB_BASE_ADDRESS + 0x14)))
#define SCB_SHPR1           (*((volatile u32 *)(SCB_BASE_ADDRESS + 0x18))) /**< SYSTEM HANDLER PRIORITY REGISTER 1 */
#define SCB_SHPR2           (*((volatile u32 *)(SCB_BASE_ADDRESS + 0x1C))) /**< SYSTEM HANDLER PRIORITY REGISTER 2 */
#define SCB_SHPR3           (*((volatile u32 *)(SCB_BASE_ADDRESS + 0x20))) /**< SYSTEM HANDLER PRIORITY REGISTER 3 */
#define SCB_SHCSR           (*((volatile u32 *)(SCB_BASE_ADDRESS + 0x24))) /**< SYSTEM HANDLER PRIORITY REGISTER 3 */
#define SCB_CFSR            (*((volatile u32 *)(SCB_BASE_ADDRESS + 0x28))) /**< SYSTEM HANDLER PRIORITY REGISTER 3 */
#define SCB_HFSR            (*((volatile u32 *)(SCB_BASE_ADDRESS + 0x2C))) /**< SYSTEM HANDLER PRIORITY REGISTER 3 */
#define SCB_MMAR            (*((volatile u32 *)(SCB_BASE_ADDRESS + 0x34))) /**< SYSTEM HANDLER PRIORITY REGISTER 3 */
#define SCB_BFAR            (*((volatile u32 *)(SCB_BASE_ADDRESS + 0x38))) /**< SYSTEM HANDLER PRIORITY REGISTER 3 */

/**< Bit positions for SCB_SHCSR register */
#define SCB_SHCSR_MEMFAULTENA_POS    16  /**< Bit position for Memory Management Fault Enable */
#define SCB_SHCSR_BUSFAULTENA_POS    17  /**< Bit position for Bus Fault Enable */
#define SCB_SHCSR_USGFAULTENA_POS    18  /**< Bit position for Usage Fault Enable */

/**< Bit positions for SCB_AIRCR register */
#define SCB_AIRCR_PRIGROUP_POS      8          /**< Bit position for Priority Grouping */
#define SCB_AIRCR_PRIGROUP_MASK     0x00000700 /**< Mask for Priority Grouping Bits */

/**
 * @brief Priority Grouping Values
 * @{
 */
#define SCB_16GROUP_0SUB   0x05FA0300U /**< 16 Priority Levels, No Sub-priority */
#define SCB_8GROUP_2SUB    0x05FA0400U /**< 8 Priority Levels, 2 Sub-priority Levels */
#define SCB_4GROUP_4SUB    0x05FA0500U /**< 4 Priority Levels, 4 Sub-priority Levels */
#define SCB_2GROUP_8SUB    0x05FA0600U /**< 2 Priority Levels, 8 Sub-priority Levels */
#define SCB_0GROUP_16SUB   0x05FA0700U /**< No Grouping, 16 Sub-priority Levels */
/** @} */


#endif /**< SCB_PRIVATE_H_ */