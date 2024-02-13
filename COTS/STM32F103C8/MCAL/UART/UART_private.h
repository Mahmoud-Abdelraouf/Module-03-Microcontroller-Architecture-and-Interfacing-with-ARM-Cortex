/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 32 Sep 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : UART_private.h             *****************/
/****************************************************************/
#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

/**
 * @brief USART base address.
 */
#define USART1_BASE_ADDRESS 0x40013800

/**
 * @brief Structure representing USART registers.
 */
typedef struct {
    volatile u32 SR;   /**< Status register */
    volatile u32 DR;   /**< Data register */
    volatile u32 BRR;  /**< Baud rate register */
    volatile u32 CR1;  /**< Control register 1 */
    volatile u32 CR2;  /**< Control register 2 */
    volatile u32 CR3;  /**< Control register 3 */
    volatile u32 GTPR; /**< Guard time and prescaler register */
} USART_RegDef_t;

/**
 * @brief USART2 pointer.
 */
#define USART1   ((USART_RegDef_t *)USART1_BASE_ADDRESS)

/**
 * @brief USART control register 1 (USART_CR1) bit definitions.
 */
#define USART_CR1_UE        0x00002000 /**< USART enable */
#define USART_CR1_M         0x00001000 /**< Word length */
#define USART_CR1_PCE       0x00000400 /**< Parity control enable */
#define USART_CR1_PS        0x00000200 /**< Parity selection */
#define USART_CR1_PEIE      0x00000100 /**< PE interrupt enable */
#define USART_CR1_TXEIE     0x00000080 /**< TXE interrupt enable */
#define USART_CR1_TCIE      0x00000040 /**< Transmission complete interrupt enable */
#define USART_CR1_RXNEIE    0x00000020 /**< RXNE interrupt enable */
#define USART_CR1_IDLEIE    0x00000010 /**< IDLE interrupt enable */
#define USART_CR1_TE        0x00000008 /**< Transmitter enable */
#define USART_CR1_RE        0x00000004 /**< Receiver enable */
#define USART_CR1_RWU       0x00000002 /**< Receiver wakeup */
#define USART_CR1_SBK       0x00000001 /**< Send break */

/**
 * @brief USART control register 2 (USART_CR2) bit definitions.
 */
#define USART_CR2_LINEN     0x00004000 /**< LIN mode enable */
#define USART_CR2_STOP      0x00003000 /**< STOP bits */
#define USART_CR2_CLKEN     0x00000400 /**< Clock enable */
#define USART_CR2_CPOL      0x00000200 /**< Clock polarity */
#define USART_CR2_CPHA      0x00000100 /**< Clock phase */
#define USART_CR2_LBCL      0x00000080 /**< Last bit clock pulse */
#define USART_CR2_LBDIE     0x00000040 /**< LIN break detection interrupt enable */
#define USART_CR2_LBDL      0x00000020 /**< LIN break detection length */
#define USART_CR2_ADD       0x0000000F /**< Address of the USART node */

/**
 * @brief USART control register 3 (USART_CR3) bit definitions.
 */
#define USART_CR3_ONEBIT    0x00008000 /**< One sample bit method enable */
#define USART_CR3_CTSIE     0x00000400 /**< CTS interrupt enable */
#define USART_CR3_CTSE      0x00000200 /**< CTS enable */
#define USART_CR3_RTSE      0x00000100 /**< RTS enable */
#define USART_CR3_DMAT      0x00000080 /**< DMA enable transmitter */
#define USART_CR3_DMAR      0x00000040 /**< DMA enable receiver */
#define USART_CR3_SCEN      0x00000020 /**< Smartcard mode enable */
#define USART_CR3_NACK      0x00000010 /**< Smartcard NACK enable */
#define USART_CR3_HDSEL     0x00000008 /**< Half-duplex selection */
#define USART_CR3_IRLP      0x00000004 /**< IrDA low-power */
#define USART_CR3_IREN      0x00000002 /**< IrDA mode enable */
#define USART_CR3_EIE       0x00000001 /**< Error interrupt enable */

/**
 * @brief USART status register (USART_SR) bit definitions.
 */
#define USART_SR_TXE        0x00000080 /**< Transmit data register empty */
#define USART_SR_TC         0x00000040 /**< Transmission complete */
#define USART_SR_RXNE       0x00000020 /**< Read data register not empty */
#define USART_SR_IDLE       0x00000010 /**< IDLE line detected */
#define USART_SR_ORE        0x00000008 /**< Overrun error */
#define USART_SR_NE         0x00000004 /**< Noise error flag */
#define USART_SR_FE         0x00000002 /**< Framing error */
#define USART_SR_PE         0x00000001 /**< Parity error */


#endif /**< UART_PRIVATE_H_ */