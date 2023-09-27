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
#define SCB_CPUID           (*((volatile u32 *)(SCB_BASE_ADDRESS + 0x00))) /**< CPUID Base Register */
#define SCB_ICSR            (*((volatile u32 *)(SCB_BASE_ADDRESS + 0x04))) /**< Interrupt Control and State Register */
#define SCB_AIRCR           (*((volatile u32 *)(SCB_BASE_ADDRESS + 0x0C))) /**< Application Interrupt and Reset Control Register */
#define SCB_SCR             (*((volatile u32 *)(SCB_BASE_ADDRESS + 0x10))) /**< System Control Register */
#define SCB_CCR             (*((volatile u32 *)(SCB_BASE_ADDRESS + 0x14))) /**< Configuration and Control Register */
#define SCB_SHPR1           (*((volatile u32 *)(SCB_BASE_ADDRESS + 0x18))) /**< System Handler Priority Register 1 */
#define SCB_SHPR2           (*((volatile u32 *)(SCB_BASE_ADDRESS + 0x1C))) /**< System Handler Priority Register 2 */
#define SCB_SHPR3           (*((volatile u32 *)(SCB_BASE_ADDRESS + 0x20))) /**< System Handler Priority Register 3 */
#define SCB_SHCSR           (*((volatile u32 *)(SCB_BASE_ADDRESS + 0x24))) /**< System Handler Control and State Register */
#define SCB_HFSR            (*((volatile u32 *)(SCB_BASE_ADDRESS + 0x2C))) /**< HardFault Status Register */
#define SCB_MMAR            (*((volatile u32 *)(SCB_BASE_ADDRESS + 0x34))) /**< MemManage Fault Address Register */
#define SCB_BFAR            (*((volatile u32 *)(SCB_BASE_ADDRESS + 0x38))) /**< BusFault Address Register */

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
#define SCB_16GROUP_SUB0   0x05FA0300U /**< 16 Priority Levels, No Sub-priority */
#define SCB_8GROUP_SUB2    0x05FA0400U /**< 8 Priority Levels, 2 Sub-priority Levels */
#define SCB_4GROUP_SUB4    0x05FA0500U /**< 4 Priority Levels, 4 Sub-priority Levels */
#define SCB_2GROUP_SUB8    0x05FA0600U /**< 2 Priority Levels, 8 Sub-priority Levels */
#define SCB_0GROUP_SUB16   0x05FA0700U /**< No Grouping, 16 Sub-priority Levels */
/** @} */


#endif /**< SCB_PRIVATE_H_ */