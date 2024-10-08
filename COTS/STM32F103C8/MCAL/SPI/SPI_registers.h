/**
 ********************************************************************************************************************************** 
 * @file SPI_registers.h
 * @brief Header file for SPI peripheral register definitions.
 * 
 * This header file provides essential definitions and structures necessary for interfacing with the Serial Peripheral Interface (SPI) on microcontrollers, 
 * specifically focusing on the STM32 platform.
 ********************************************************************************************************************************** 
 * @version V01
 * @date 10 Dec 2023
 * @author Mahmoud Abdelraouf
 * 
 * @copyright Copyright (c) 2023
 ********************************************************************************************************************************** 
 */
#ifndef __SPI_REGISTERS_H__
#define __SPI_REGISTERS_H__
/**
 * @defgroup SPI_Driver SPI Registers
 * @{
 */

/**
 * @brief Register definitions for the SPI driver.
 *
 * This section defines the base addresses of the different SPI modules and a structure definition for the SPI register map.
 *
 * @note CRC (Cyclic Redundancy Check) is a type of error-detecting code that is commonly used in digital communication networks
 * and storage devices to detect accidental changes to raw data. The CRC code is generated by performing a mathematical calculation on the data,
 * which results in a fixed-size, checksum value that can be transmitted along with the data to detect any errors that may have occurred during transmission or storage.
 *
 * CRC is a widely used standard for error detection in a variety of applications, including telecommunications,
 * computer networking, and storage devices such as hard drives, USB drives, and memory cards. Different CRC standards are available with different
 * polynomial values and bit-lengths, depending on the specific application requirements.
 *
 * In the context of microcontrollers, such as STM32, CRC can be used to calculate the checksum of data stored
 * in memory or transmitted over a communication interface, such as SPI, UART, or I2C. The STM32 devices have built-in
 * CRC hardware modules that can perform the CRC calculation efficiently and quickly, thereby reducing the software overhead and
 * improving the system's performance.
 */
/**@{*/
#define SPI1_BASE_ADDRESS   0x40013000U /**< Base address for the SPI1 module. */
#define SPI2_BASE_ADDRESS   0x40003800U /**< Base address for the SPI2 module. */
#define SPI3_BASE_ADDRESS   0x40003C00U /**< Base address for the SPI3 module. */

typedef struct {
    volatile u32 CR1;       /**< Control register 1. */
    volatile u32 CR2;       /**< Control register 2. */
    volatile u32 SR;        /**< Status register. */
    volatile u32 DR;        /**< Data register. */
    volatile u32 CRCPR;     /**< CRC polynomial register. */
    volatile u32 RXCRCR;    /**< Receive CRC register. */
    volatile u32 TXCRCR;    /**< Transmit CRC register. */
    volatile u32 I2SCFGR;   /**< I2S configuration register. */
    volatile u32 I2SPR;     /**< I2S prescaler register. */
} SPI_RegDef_t;

/**
 * @brief Type definition for the base address of a specified SPI peripheral.
 *
 * This typedef defines a pointer type `SPI_t` that represents the base address
 * of the register structure for a specific SPI peripheral. It can be used to access
 * and configure the registers of the selected SPI peripheral.
 *
 * @note Users can obtain a `SPI_t` pointer using the `SPI_SelectSpi` function by providing
 *       a valid SPI peripheral identifier.
 */
typedef SPI_RegDef_t*   SPI_t;

/**
 * @} SPI_Driver SPI Registers
 */


#endif /**< __SPI_REGISTERS_H__ */
