/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 6 Sep 2023                 *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : NVIC_private.              *****************/
/****************************************************************/
#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_


/**
 * @defgroup NVIC_Registers NVIC Registers
 * @brief NVIC (Nested Vectored Interrupt Controller) Registers.
 * @{
 */

/**
 * @brief NVIC ISER Registers.
 * @{
 */
#define NVIC_ISER0     (*((volatile u32 *)0xE000E100)) /**< INTERRUPT SET-ENABLE REGISTERS 0 to 31 */
#define NVIC_ISER1     (*((volatile u32 *)0xE000E104)) /**< INTERRUPT SET-ENABLE REGISTERS 32 to 63 */
#define NVIC_ISER2     (*((volatile u32 *)0xE000E108)) /**< INTERRUPT SET-ENABLE REGISTERS 64 to 95 */
/** @} */

/**
 * @brief NVIC ICER Registers.
 * @{
 */
#define NVIC_ICER0     (*((volatile u32 *)0xE000E180)) /**< INTERRUPT CLEAR-ENABLE REGISTERS 0 to 31 */
#define NVIC_ICER1     (*((volatile u32 *)0xE000E184)) /**< INTERRUPT CLEAR-ENABLE REGISTERS 32 to 63 */
#define NVIC_ICER2     (*((volatile u32 *)0xE000E188)) /**< INTERRUPT CLEAR-ENABLE REGISTERS 64 to 95 */
/** @} */

/**
 * @brief NVIC ISPR Registers.
 * @{
 */
#define NVIC_ISPR0     (*((volatile u32 *)0xE000E200)) /**< INTERRUPT SET-PENDING REGISTERS 0 to 31 */
#define NVIC_ISPR1     (*((volatile u32 *)0xE000E204)) /**< INTERRUPT SET-PENDING REGISTERS 32 to 63 */
#define NVIC_ISPR2     (*((volatile u32 *)0xE000E208)) /**< INTERRUPT SET-PENDING REGISTERS 64 to 95 */
/** @} */

/**
 * @brief NVIC ICPR Registers.
 * @{
 */
#define NVIC_ICPR0     (*((volatile u32 *)0xE000E280)) /**< INTERRUPT CLEAR-PENDING REGISTERS 0 to 31 */
#define NVIC_ICPR1     (*((volatile u32 *)0xE000E284)) /**< INTERRUPT CLEAR-PENDING REGISTERS 32 to 63 */
#define NVIC_ICPR2     (*((volatile u32 *)0xE000E288)) /**< INTERRUPT CLEAR-PENDING REGISTERS 64 to 95 */
/** @} */

/**
 * @brief NVIC IABR Registers.
 * @{
 */
#define NVIC_IABR0     (*((volatile u32 *)0xE000E300)) /**< INTERRUPT ACTIVE BIT REGISTERS 0 to 31 */
#define NVIC_IABR1     (*((volatile u32 *)0xE000E304)) /**< INTERRUPT ACTIVE BIT REGISTERS 32 to 63 */
#define NVIC_IABR2     (*((volatile u32 *)0xE000E308)) /**< INTERRUPT ACTIVE BIT REGISTERS 64 to 95 */
/** @} */

/**
 * @brief NVIC IPR Base Address
 */                                                 
#define NVIC_IPR_BASE_ADDRESS    (((volatile u8 *)0xE000E400)) /**< INTERRUPT PRIORITY REGISTERS BASE ADDRESS */

/**
 * @brief SCB Registers.
 * @{
 */
#define SCB_AIRCR       (*((volatile u32 *)0xE000ED0C)) /**< APPLICATION INTERRUPT AND RESET CONTROL REGISTER */
#define SCB_SHPR1       (*((volatile u32 *)0xE000ED18)) /**< SYSTEM HANDLER PRIORITY REGISTER 1 */
#define SCB_SHPR2       (*((volatile u32 *)0xE000ED1C)) /**< SYSTEM HANDLER PRIORITY REGISTER 2 */
#define SCB_SHPR3       (*((volatile u32 *)0xE000ED20)) /**< SYSTEM HANDLER PRIORITY REGISTER 3 */
/** @} */

/**
 * @brief Priority Grouping Values
 * @{
 */

/**< SCB Register Values */
#define _16GROUP_0SUB   0x05FA0300U /**< 16 Priority Levels, No Sub-priority */
#define _8GROUP_2SUB    0x05FA0400U /**< 8 Priority Levels, 2 Sub-priority Levels */
#define _4GROUP_4SUB    0x05FA0500U /**< 4 Priority Levels, 4 Sub-priority Levels */
#define _2GROUP_8SUB    0x05FA0600U /**< 2 Priority Levels, 8 Sub-priority Levels */
#define _0GROUP_16SUB   0x05FA0700U /**< No Grouping, 16 Sub-priority Levels */

/** @} */



/**
 * @} (end of group NVIC_Registers)
 */

    



#endif /**< NVIC_PRIVATE_H_ */