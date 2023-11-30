/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 12 Sep 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : NVIC_private.h             *****************/
/****************************************************************/
#ifndef AFIO_PRIVATE_H_
#define AFIO_PRIVATE_H_

/**
 * @defgroup AFIO AFIO (Alternate Function I/O)
 * @brief Header file for the AFIO (Alternate Function I/O) peripheral.
 *
 * This header provides definitions and structures for configuring the AFIO peripheral.
 * It includes the Event Control Register, Multiplexed Pin Assignments Register,
 * External Interrupt Configuration Registers, and Multiplexed Pin Assignments Register 2.
 *
 * @addtogroup Peripheral_Registers Peripheral Registers
 * @{
 */

/**
 * @addtogroup AFIO_Registers AFIO Registers
 * @{
 */

#define AFIO_BASE_ADDRESS       0x40010000 /**< AFIO Peripheral Base Address */

/**
 * @brief AFIO Register Definition Structure
 */
typedef struct 
{
    volatile u32 EVCR;        /**< Event Control Register. */
    volatile u32 MAPR;        /**< Multiplexed Pin Assignments Register. */
    volatile u32 EXTICR[4];   /**< External Interrupt Configuration Registers. */
    volatile u32 MAPR2;       /**< Multiplexed Pin Assignments Register 2. */
} AFIO_RegDef_t;

/** AFIO peripheral instance. */
#define AFIO    ((AFIO_RegDef_t *)AFIO_BASE_ADDRESS)

/** @} */ // End of AFIO_Registers group

/** @} */ // End of AFIO group


/**
 * @defgroup AFIO_Remap_Definitions AFIO Remap Definitions
 * @{
 */

#define AFIO_MAPR_SWJ_CFG_Pos        24 /**< Bit position for SWJ (Serial Wire JTAG) configuration. */
#define AFIO_MAPR_SWJ_CFG_Msk        (0x7 << AFIO_MAPR_SWJ_CFG_Pos) /**< Bit mask for SWJ (Serial Wire JTAG) configuration. */

#define AFIO_MAPR_SWJ_CFG_001        (0x1 << AFIO_MAPR_SWJ_CFG_Pos) /**< SWJ configuration: 001 */
#define AFIO_MAPR_SWJ_CFG_010        (0x2 << AFIO_MAPR_SWJ_CFG_Pos) /**< SWJ configuration: 010 */

#define AFIO_MAPR_ADC2_ETRGREG_Pos   20 /**< Bit position for ADC2 external trigger regular conversion remapping. */
#define AFIO_MAPR_ADC2_ETRGREG_Msk   (0x1 << AFIO_MAPR_ADC2_ETRGREG_Pos) /**< Bit mask for ADC2 external trigger regular conversion remapping. */

#define AFIO_MAPR_ADC2_ETRGINJ_Pos   19 /**< Bit position for ADC2 external trigger injected conversion remapping. */
#define AFIO_MAPR_ADC2_ETRGINJ_Msk   (0x1 << AFIO_MAPR_ADC2_ETRGINJ_Pos) /**< Bit mask for ADC2 external trigger injected conversion remapping. */

#define AFIO_MAPR_ADC1_ETRGREG_Pos   18 /**< Bit position for ADC1 external trigger regular conversion remapping. */
#define AFIO_MAPR_ADC1_ETRGREG_Msk   (0x1 << AFIO_MAPR_ADC1_ETRGREG_Pos) /**< Bit mask for ADC1 external trigger regular conversion remapping. */

#define AFIO_MAPR_ADC1_ETRGINJ_Pos   17 /**< Bit position for ADC1 external trigger injected conversion remapping. */
#define AFIO_MAPR_ADC1_ETRGINJ_Msk   (0x1 << AFIO_MAPR_ADC1_ETRGINJ_Pos) /**< Bit mask for ADC1 external trigger injected conversion remapping. */

#define AFIO_MAPR_TIM5CH4_Pos        16 /**< Bit position for TIM5 channel4 internal remap. */
#define AFIO_MAPR_TIM5CH4_Msk        (0x1 << AFIO_MAPR_TIM5CH4_Pos) /**< Bit mask for TIM5 channel4 internal remap. */

#define AFIO_MAPR_PD01_Pos           15 /**< Bit position for Port D0/Port D1 mapping on OSC_IN/OSC_OUT. */
#define AFIO_MAPR_PD01_Msk           (0x1 << AFIO_MAPR_PD01_Pos) /**< Bit mask for Port D0/Port D1 mapping on OSC_IN/OSC_OUT. */

#define AFIO_MAPR_CAN_REMAP_Pos      13 /**< Bit position for CAN alternate function remapping. */
#define AFIO_MAPR_CAN_REMAP_Msk      (0x3 << AFIO_MAPR_CAN_REMAP_Pos) /**< Bit mask for CAN alternate function remapping. */

#define AFIO_MAPR_TIM4_REMAP_Pos     12 /**< Bit position for TIM4 remapping. */
#define AFIO_MAPR_TIM4_REMAP_Msk     (0x1 << AFIO_MAPR_TIM4_REMAP_Pos) /**< Bit mask for TIM4 remapping. */

#define AFIO_MAPR_TIM3_REMAP_Pos     10 /**< Bit position for TIM3 remapping. */
#define AFIO_MAPR_TIM3_REMAP_Msk     (0x3 << AFIO_MAPR_TIM3_REMAP_Pos) /**< Bit mask for TIM3 remapping. */

#define AFIO_MAPR_TIM2_REMAP_Pos      8 /**< Bit position for TIM2 remapping. */
#define AFIO_MAPR_TIM2_REMAP_Msk     (0x3 << AFIO_MAPR_TIM2_REMAP_Pos) /**< Bit mask for TIM2 remapping. */

#define AFIO_MAPR_TIM1_REMAP_Pos      6 /**< Bit position for TIM1 remapping. */
#define AFIO_MAPR_TIM1_REMAP_Msk     (0x3 << AFIO_MAPR_TIM1_REMAP_Pos) /**< Bit mask for TIM1 remapping. */

#define AFIO_MAPR_USART3_REMAP_Pos    4 /**< Bit position for USART3 remapping. */
#define AFIO_MAPR_USART3_REMAP_Msk   (0x3 << AFIO_MAPR_USART3_REMAP_Pos) /**< Bit mask for USART3 remapping. */

#define AFIO_MAPR_USART2_REMAP_Pos    3 /**< Bit position for USART2 remapping. */
#define AFIO_MAPR_USART2_REMAP_Msk   (0x1 << AFIO_MAPR_USART2_REMAP_Pos) /**< Bit mask for USART2 remapping. */

#define AFIO_MAPR_USART1_REMAP_Pos    2 /**< Bit position for USART1 remapping. */
#define AFIO_MAPR_USART1_REMAP_Msk   (0x1 << AFIO_MAPR_USART1_REMAP_Pos) /**< Bit mask for USART1 remapping. */

#define AFIO_MAPR_I2C1_REMAP_Pos      1 /**< Bit position for I2C1 remapping. */
#define AFIO_MAPR_I2C1_REMAP_Msk     (0x1 << AFIO_MAPR_I2C1_REMAP_Pos) /**< Bit mask for I2C1 remapping. */

#define AFIO_MAPR_SPI1_REMAP_Pos      0 /**< Bit position for SPI1 remapping. */
#define AFIO_MAPR_SPI1_REMAP_Msk     (0x1 << AFIO_MAPR_SPI1_REMAP_Pos) /**< Bit mask for SPI1 remapping. */

/** @} */ // End of AFIO_Remap_Definitions


/**
 * @} // End of Peripheral_Registers group
 */ 


#endif /**< AFIO_PRIVATE_H_ */
