/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 26 Aug 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : RCC_interface.h            *****************/
/****************************************************************/
#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_


/**
 * @defgroup RCC_Peripheral_Macros RCC Peripheral Macros
 * @brief Macros related to clock configuration for different peripherals.
 * @{
 */

/**
 * @defgroup RCC_Clock_Domains Clock Domains
 * @brief Macros defining the available clock domains for peripheral clock configuration.
 * @{
 */

/**
 * @brief Available clock domains for peripheral clock configuration.
 */
#define RCC_AHB                 0 /**< Advanced High-performance Bus (AHB) domain. */
#define RCC_APB1                1 /**< Advanced Peripheral Bus 1 (APB1) domain. */
#define RCC_APB2                2 /**< Advanced Peripheral Bus 2 (APB2) domain. */

/** @} */

/**
 * @defgroup RCC_AHBENR_Bit_Def RCC_AHBENR Bit Definitions
 * @brief Macros representing the bit positions in the AHB Peripheral Clock Enable Register (RCC_AHBENR).
 * @{
 */

#define RCC_AHBENR_DMA1EN       0  /**< DMA1 clock enable */
#define RCC_AHBENR_DMA2EN       1  /**< DMA2 clock enable */
#define RCC_AHBENR_SRAMEN       2  /**< SRAM interface clock enable */
#define RCC_AHBENR_FLITFEN      4  /**< FLITF clock enable */
#define RCC_AHBENR_CRCEN        6  /**< CRC clock enable */
#define RCC_AHBENR_OTGFSEN      12 /**< USB OTG FS clock enable */
#define RCC_AHBENR_ETHMACEN     14 /**< Ethernet MAC clock enable */
#define RCC_AHBENR_ETHMACTXEN   15 /**< Ethernet Transmission clock enable */
#define RCC_AHBENR_ETHMACRXEN   16 /**< Ethernet Reception clock enable */
#define RCC_AHBENR_ETHMACPTPEN  17 /**< Ethernet PTP clock enable */
#define RCC_AHBENR_OTGHSEN      29 /**< USB OTG HS clock enable */

/** @} */

/**
 * @defgroup RCC_APB1ENR_Bit_Def RCC_APB1ENR Bit Definitions
 * @brief Macros representing the bit positions in the APB1 Peripheral Clock Enable Register (RCC_APB1ENR).
 * @{
 */

#define RCC_APB1ENR_TIM2EN      0  /**< Timer 2 clock enable */
#define RCC_APB1ENR_TIM3EN      1  /**< Timer 3 clock enable */
#define RCC_APB1ENR_TIM4EN      2  /**< Timer 4 clock enable */
#define RCC_APB1ENR_TIM5EN      3  /**< Timer 5 clock enable */
#define RCC_APB1ENR_TIM6EN      4  /**< Timer 6 clock enable */
#define RCC_APB1ENR_TIM7EN      5  /**< Timer 7 clock enable */
#define RCC_APB1ENR_TIM12EN     6  /**< Timer 12 clock enable */
#define RCC_APB1ENR_TIM13EN     7  /**< Timer 13 clock enable */
#define RCC_APB1ENR_TIM14EN     8  /**< Timer 14 clock enable */
#define RCC_APB1ENR_WWDGEN      11 /**< Window Watchdog clock enable */
#define RCC_APB1ENR_SPI2EN      14 /**< SPI2 clock enable */
#define RCC_APB1ENR_SPI3EN      15 /**< SPI3 clock enable */
#define RCC_APB1ENR_USART2EN    17 /**< USART2 clock enable */
#define RCC_APB1ENR_USART3EN    18 /**< USART3 clock enable */
#define RCC_APB1ENR_UART4EN     19 /**< UART4 clock enable */
#define RCC_APB1ENR_UART5EN     20 /**< UART5 clock enable */
#define RCC_APB1ENR_I2C1EN      21 /**< I2C1 clock enable */
#define RCC_APB1ENR_I2C2EN      22 /**< I2C2 clock enable */
#define RCC_APB1ENR_USBEN       23 /**< USB clock enable */
#define RCC_APB1ENR_CANEN       25 /**< CAN clock enable */
#define RCC_APB1ENR_BKPEN       27 /**< Backup interface clock enable */
#define RCC_APB1ENR_PWREN       28 /**< Power interface clock enable */
#define RCC_APB1ENR_DACEN       29 /**< DAC clock enable */

/** @} */

/**
 * @defgroup RCC_APB2ENR_Bit_Def RCC_APB2ENR Bit Definitions
 * @brief Macros representing the bit positions in the APB2 Peripheral Clock Enable Register (RCC_APB2ENR).
 * @{
 */

#define RCC_APB2ENR_AFIOEN      0  /**< Alternate function IO clock enable */
#define RCC_APB2ENR_IOPAEN      2  /**< I/O port A clock enable */
#define RCC_APB2ENR_IOPBEN      3  /**< I/O port B clock enable */
#define RCC_APB2ENR_IOPCEN      4  /**< I/O port C clock enable */
#define RCC_APB2ENR_IOPDEN      5  /**< I/O port D clock enable */
#define RCC_APB2ENR_IOPEEN      6  /**< I/O port E clock enable */
#define RCC_APB2ENR_IOPFEN      7  /**< I/O port F clock enable */
#define RCC_APB2ENR_IOPGEN      8  /**< I/O port G clock enable */
#define RCC_APB2ENR_ADC1EN      9  /**< ADC1 clock enable */
#define RCC_APB2ENR_ADC2EN      10 /**< ADC2 clock enable */
#define RCC_APB2ENR_TIM1EN      11 /**< Timer 1 clock enable */
#define RCC_APB2ENR_SPI1EN      12 /**< SPI1 clock enable */
#define RCC_APB2ENR_TIM8EN      13 /**< Timer 8 clock enable */
#define RCC_APB2ENR_USART1EN    14 /**< USART1 clock enable */
#define RCC_APB2ENR_ADC3EN      15 /**< ADC3 clock enable */
#define RCC_APB2ENR_TIM9EN      19 /**< Timer 9 clock enable */
#define RCC_APB2ENR_TIM10EN     20 /**< Timer 10 clock enable */
#define RCC_APB2ENR_TIM11EN     21 /**< Timer 11 clock enable */

/** @} */

/** @} */  /* End of RCC_Peripheral_Macros group */


/**
 * @defgroup RCC_API RCC APIs
 * @brief Functions for RCC (Reset and Clock Control) configuration.
 * @{
 */

/**
 * @brief Initialize the system clock configuration.
 *
 * This function initializes the system clock configuration according to the desired settings.
 * It should be called early in the program to properly configure the clock system.
 *
 * @return Std_ReturnType
 * @retval E_OK     Clock initialization successful.
 * @retval E_NOT_OK Clock initialization failed.
 */
Std_ReturnType MCAL_RCC_InitSysClock(void);

/**
 * @brief Enable a specific peripheral on a specific bus.
 *
 * This function enables a specific peripheral on a specific bus.
 *
 * @param[in] Copy_PeripheralId The ID of the peripheral to be enabled.
 * @param[in] Copy_BusId        The ID of the bus to which the peripheral belongs (RCC_AHB, RCC_APB1, or RCC_APB2).
 * @return Std_ReturnType
 * @retval E_OK     Peripheral enabling successful.
 * @retval E_NOT_OK Peripheral enabling failed.
 */
Std_ReturnType MCAL_RCC_EnablePeripheral(u8 Copy_BusId, u8 Copy_PeripheralId);

/**
 * @brief Disable a specific peripheral.
 *
 * This function disables a previously enabled peripheral.
 * 
 * @param[in] Copy_PeripheralId The ID of the peripheral to be enabled.
 * @param[in] Copy_BusId        The ID of the bus to which the peripheral belongs (RCC_AHB, RCC_APB1, or RCC_APB2).
 * @return Std_ReturnType
 * @retval E_OK     Peripheral disabling successful.
 * @retval E_NOT_OK Peripheral disabling failed.
 */
Std_ReturnType MCAL_RCC_DisablePeripheral(u8 Copy_BusId, u8 Copy_PeripheralId);

/**
 * @}
 */




#endif /**< RCC_INTERFACE_H_ */