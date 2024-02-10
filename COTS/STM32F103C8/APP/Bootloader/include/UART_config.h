/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 32 Sep 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : UART_config.h              *****************/
/****************************************************************/
#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

/**
 * @addtogroup UART_Configuration_Options
 * @{
 */

/**
 * @brief Enumeration for UART parity modes.
 *
 * This enumeration defines the possible parity modes for the UART driver.
 * PARITY_NONE: No parity bit is used.
 * PARITY_EVEN: Even parity is used.
 * PARITY_ODD: Odd parity is used.
 */
typedef enum
{
  PARITY_NONE,  /**< No parity bit is used */
  PARITY_EVEN,  /**< Even parity is used */
  PARITY_ODD    /**< Odd parity is used */
} UART_Parity_t;

/**
 * @brief Enumeration for UART stop bit modes.
 *
 * This enumeration defines the possible stop bit modes for the UART driver.
 * STOP_BITS_1: 1 stop bit is used.
 * STOP_BITS_2: 2 stop bits are used.
 */
typedef enum
{
  STOP_BITS_1,  /**< 1 stop bit is used */
  STOP_BITS_2   /**< 2 stop bits are used */
} UART_StopBits_t;

/**
 * @brief Enumeration for UART data word lengths.
 *
 * This enumeration defines the possible data word lengths for the UART driver.
 * DATA_BITS_8: 8 data bits are used.
 * DATA_BITS_9: 9 data bits are used.
 */
typedef enum
{
  DATA_BITS_8,  /**< 8 data bits are used */
  DATA_BITS_9   /**< 9 data bits are used */
} UART_DataBits_t;

/**
 * @brief Enumeration for UART baud rate options.
 *
 * This enumeration defines the possible baud rate options for the UART driver.
 * BAUD_RATE_9600: Baud rate of 9600.
 * BAUD_RATE_115200: Baud rate of 115200.
 * BAUD_RATE_57600: Baud rate of 57600.
 * BAUD_RATE_38400: Baud rate of 38400.
 */
typedef enum
{
  BAUD_RATE_9600,     /**< Baud rate of 9600 */
  BAUD_RATE_115200,   /**< Baud rate of 115200 */
  BAUD_RATE_57600,    /**< Baud rate of 57600 */
  BAUD_RATE_38400     /**< Baud rate of 38400 */
} UART_BaudRate_t;

/**
 * @}
 */



#endif /**< UART_CONFIG_H_ */