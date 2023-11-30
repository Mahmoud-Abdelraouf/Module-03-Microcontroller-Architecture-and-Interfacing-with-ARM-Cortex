/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 32 Sep 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : UART_interface.h           *****************/
/****************************************************************/
#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

/**
 * @addtogroup UART_Configuration_Options
 * @{
 */

#define USART_CLK_SRC           8000000
/**
 * @brief Enumeration for UART parity modes.
 *
 * This enumeration defines the possible parity modes for the UART driver.
 * PARITY_NONE: No parity bit is used.
 * PARITY_EVEN: Even parity is used.
 * PARITY_ODD: Odd parity is used.
 */
typedef enum {
  UART_PARITY_NONE,  /**< No parity bit is used */
  UART_PARITY_EVEN,  /**< Even parity is used */
  UART_PARITY_ODD    /**< Odd parity is used */
} USART_Parity_t;

/**
 * @brief Enumeration for UART stop bit modes.
 *
 * This enumeration defines the possible stop bit modes for the UART driver.
 * STOP_BITS_1: 1 stop bit is used.
 * STOP_BITS_2: 2 stop bits are used.
 */
typedef enum {
  UART_STOP_BITS_1,     /**< 1 stop bit is used */
  UART_STOP_BITS_0_5,   /**< 0.5 stop bit is used */
  UART_STOP_BITS_2,     /**< 2 stop bits are used */
  UART_STOP_BITS_1_5    /**< 1.5 stop bits are used */
} USART_StopBits_t;

/**
 * @brief Enumeration for UART data word lengths.
 *
 * This enumeration defines the possible data word lengths for the UART driver.
 * DATA_BITS_8: 8 data bits are used.
 * DATA_BITS_9: 9 data bits are used.
 */
typedef enum {
  UART_WORD_LENGTH_8BIT,  /**< 8 data bits are used */
  UART_WORD_LENGTH_9BIT   /**< 9 data bits are used */
} USART_DataBits_t;

/**
 * @brief Enumeration for UART baud rate options.
 *
 * This enumeration defines the possible baud rate options for the UART driver.
 * BAUD_RATE_9600: Baud rate of 9600.
 * BAUD_RATE_115200: Baud rate of 115200.
 * BAUD_RATE_57600: Baud rate of 57600.
 * BAUD_RATE_38400: Baud rate of 38400.
 */
typedef enum {
  UART_BAUD_RATE_9600   = 9600,     /**< Baud rate of 9600 */
  UART_BAUD_RATE_115200 = 115200,   /**< Baud rate of 115200 */
  UART_BAUD_RATE_57600  = 57600,    /**< Baud rate of 57600 */
  UART_BAUD_RATE_38400  = 38400    /**< Baud rate of 38400 */
} USART_BaudRate_t;

/**
 * @brief Enumeration of UART hardware flow control options.
 *
 * This enumeration defines the possible hardware flow control options that can be used in UART communication.
 * Hardware flow control helps manage the flow of data between the sender and receiver to prevent data overrun or loss.
 * The options include:
 *
 * - UART_HW_FLOW_CONTROL_NONE: No hardware flow control. Data transmission is not controlled by additional signals.
 * - UART_HW_FLOW_CONTROL_RTS: Request to Send (RTS) hardware flow control. The transmitter asserts the RTS signal
 *   to indicate that it is ready to send data, and the receiver uses RTS as an indication that it can receive data.
 *   Data transmission occurs only when RTS is asserted.
 * - UART_HW_FLOW_CONTROL_CTS: Clear to Send (CTS) hardware flow control. The receiver asserts the CTS signal to
 *   indicate that it is ready to accept data, and the transmitter uses CTS as an indication that it can start
 *   transmitting data. Data transmission occurs only when CTS is asserted.
 * - UART_HW_FLOW_CONTROL_RTS_CTS: RTS and CTS hardware flow control. Both RTS and CTS signals are used for flow control,
 *   allowing bidirectional control of data transmission. The transmitter uses RTS to indicate readiness, and the receiver
 *   uses CTS to indicate readiness to receive data.
 *
 * @note RTS (Request to Send): RTS is an output signal generated by the data sender (transmitter) to the data receiver.
 * When the transmitter has data to send and is ready to transmit, it asserts the RTS signal to inform the receiver
 * that it is ready to send data. The receiver uses the RTS signal as an indication that it can receive data.
 * Data transmission occurs only when the RTS signal is asserted.
 *
 * @note CTS (Clear to Send): CTS is an input signal generated by the data receiver to the data sender (transmitter).
 * When the receiver is ready to receive data, it asserts the CTS signal to inform the transmitter that it is ready
 * to accept data. The transmitter uses the CTS signal as an indication that it can start transmitting data.
 * Data transmission occurs only when the CTS signal is asserted.
 */
typedef enum {
    UART_HW_FLOW_CONTROL_NONE,   /**< No hardware flow control */
    UART_HW_FLOW_CONTROL_RTS,    /**< Request to Send (RTS) hardware flow control */
    UART_HW_FLOW_CONTROL_CTS,    /**< Clear to Send (CTS) hardware flow control */
    UART_HW_FLOW_CONTROL_RTS_CTS /**< RTS and CTS hardware flow control */
} USART_HW_FlowControl_t;

typedef struct {
  u32 BaudRate;
  u8 HwFlowControl:2;
  u8 ParityMode: 2;
  u8 StopBits: 2;
  u8 WordLength: 1;
  u8 : 1; /**< Padding to align to 8 bits */ 
} USART_Config_t;


/**
 * @}
 */

/**
 * @addtogroup UART_API's
 * @{
 */

/**
 * @brief Initializes the UART module with the provided configuration settings.
 *
 * This function initializes the UART module based on the provided configuration 
 * settings, including word length, stop bits, and parity mode. It configures the 
 * baud rate and other necessary parameters to enable UART communication.
 *
 * @param[in] USARTConfig Pointer to a structure containing UART configuration settings.
 * 
 * @return
 *     - E_OK: UART initialization successful.
 *     - E_NOT_OK: UART initialization failed or invalid configuration.
 */
Std_ReturnType UART_Init(USART_Config_t *USARTConfig);

/**
 * @brief Transmits data via the UART interface.
 *
 * This function transmits a specified amount of data through the UART interface. 
 * It sends the provided data buffer of a specified size over the UART channel.
 *
 * @param[in] Data Pointer to the data buffer to be transmitted.
 * @param[in] DataSize Size of the data buffer to be transmitted.
 * 
 * @return
 *     - E_OK: Data transmission successful.
 *     - E_NOT_OK: Data transmission failed or invalid parameters.
 */
Std_ReturnType UART_Transmit(u8 *Data, u16 DataSize);

/**
 * @brief Receives data via the UART interface.
 *
 * This function receives a specified amount of data through the UART interface. 
 * It stores the received data in the provided buffer of a specified size.
 *
 * @param[out] Data Pointer to the buffer to store the received data.
 * @param[in] DataSize Size of the buffer to store the received data.
 * 
 * @return
 *     - E_OK: Data reception successful.
 *     - E_NOT_OK: Data reception failed or invalid parameters.
 */
Std_ReturnType UART_Receive(u8 *Data, u16 DataSize);

/**
 * @}
 */

#endif /**< UART_INTERFACE_H_ */