/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 10 Dec 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : I2C_private.c              *****************/
/****************************************************************/
#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

/**
 * @brief I2C1 base address.
 */
#define I2C1_BASE_ADDRESS 0x40005400

/**
 * @brief Structure representing I2C registers.
 */
typedef struct {
    volatile uint32_t CR1;      /**< Control register 1 */
    volatile uint32_t CR2;      /**< Control register 2 */
    volatile uint32_t OAR1;     /**< Own address register 1 */
    volatile uint32_t OAR2;     /**< Own address register 2 */
    volatile uint32_t DR;       /**< Data register */
    volatile uint32_t SR1;      /**< Status register 1 */
    volatile uint32_t SR2;      /**< Status register 2 */
    volatile uint32_t CCR;      /**< Clock control register */
    volatile uint32_t TRISE;    /**< TRISE register */
} I2C_RegDef_t;

/**
 * @brief I2C1 pointer.
 */
#define I2C1   ((I2C_RegDef_t *)I2C1_BASE_ADDRESS)

/**
 * @brief I2C control register 1 (I2C_CR1) bit definitions.
 */
#define I2C_CR1_PE          0x00000001 /**< Peripheral enable */
#define I2C_CR1_SMBUS       0x00040000 /**< SMBus mode */
#define I2C_CR1_SMBTYPE     0x00080000 /**< SMBus type */
#define I2C_CR1_ENARP       0x00100000 /**< ARP enable */
#define I2C_CR1_ENPEC       0x00200000 /**< PEC enable */
#define I2C_CR1_ENGC        0x00400000 /**< General call enable */
#define I2C_CR1_NOSTRETCH   0x00800000 /**< Clock stretching disable (Slave mode) */
#define I2C_CR1_START       0x01000000 /**< Start generation */
#define I2C_CR1_STOP        0x02000000 /**< Stop generation */
#define I2C_CR1_ACK         0x04000000 /**< Acknowledge enable */
#define I2C_CR1_POS         0x08000000 /**< Acknowledge/PEC Position (for data reception) */
#define I2C_CR1_PEC         0x10000000 /**< Packet error checking */
#define I2C_CR1_ALERT       0x20000000 /**< SMBus alert */
#define I2C_CR1_SWRST       0x80000000 /**< Software reset */

/**
 * @brief I2C control register 2 (I2C_CR2) bit definitions.
 */
#define I2C_CR2_FREQ        0x0000003F /**< Peripheral clock frequency */
#define I2C_CR2_ITERREN     0x00000400 /**< Error interrupt enable */
#define I2C_CR2_ITEVTEN     0x00000200 /**< Event interrupt enable */
#define I2C_CR2_ITBUFEN     0x00000100 /**< Buffer interrupt enable */
#define I2C_CR2_DMAEN       0x00000080 /**< DMA requests enable */
#define I2C_CR2_LAST        0x00000020 /**< DMA last transfer */

/**
 * @brief I2C status register 1 (I2C_SR1) bit definitions.
 */
#define I2C_SR1_SB          0x00000001 /**< Start bit (Master mode) */
#define I2C_SR1_ADDR        0x00000002 /**< Address sent (Master mode)/matched (Slave mode) */
#define I2C_SR1_BTF         0x00000004 /**< Byte transfer finished */
#define I2C_SR1_ADD10       0x00000008 /**< 10-bit header sent (Master mode) */
#define I2C_SR1_STOPF       0x00000010 /**< Stop detection (Slave mode) */
#define I2C_SR1_RXNE        0x00000040 /**< Data register not empty (receivers) */
#define I2C_SR1_TXE         0x00000080 /**< Data register empty (transmitters) */
#define I2C_SR1_BERR        0x00000100 /**< Bus error */
#define I2C_SR1_ARLO        0x00000200 /**< Arbitration lost (Master mode) */
#define I2C_SR1_AF          0x00000400 /**< Acknowledge failure */
#define I2C_SR1_OVR         0x00000800 /**< Overrun/Underrun */
#define I2C_SR1_PECERR      0x00001000 /**< PEC error in reception */
#define I2C_SR1_TIMEOUT     0x00004000 /**< Timeout or Tlow detection flag */
#define I2C_SR1_SMBALERT    0x00008000 /**< SMBus alert */

/**
 * @brief I2C event macros.
 */
#define I2C_EVENT_MASTER_MODE_SELECT                ((uint32_t)0x00030001) /**< EV5: SB=1, cleared by reading SR1 followed by writing DR register */
#define I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED  ((uint32_t)0x00070082) /**< EV6: ADDR=1, cleared by reading SR1 followed by writing SR2 register */
#define I2C_EVENT_MASTER_BYTE_TRANSMITTED           ((uint32_t)0x00070084) /**< EV8_2: TXE=1, BTF=1, cleared by writing DR register */
#define I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED     ((uint32_t)0x00030002) /**< EV6: ADDR=1, cleared by reading SR1 followed by reading SR2 register */
#define I2C_EVENT_MASTER_BYTE_RECEIVED              ((uint32_t)0x00030040) /**< EV7: RXNE=1, cleared by reading DR register */

/**
 * @brief I2C direction macros.
 */
#define I2C_Direction_Transmitter    ((uint8_t)0x00) /**< Transmission direction */
#define I2C_Direction_Receiver       ((uint8_t)0x01) /**< Reception direction */

/**
 * @brief I2C flag macros.
 */
#define I2C_FLAG_STOPF   ((uint32_t)0x00000010) /**< STOP detection flag */

/**
 * @brief I2C control macros.
 */
#define ENABLE   1 /**< Enable control macro */
#define DISABLE  0 /**< Enable control macro */


/* Private functions */
static void I2C_ClearADDRFlag(I2C_RegDef_t *pI2Cx);
static void I2C_EnableAck(I2C_RegDef_t *pI2Cx);
static void I2C_DisableAck(I2C_RegDef_t *pI2Cx);
static void I2C_MasterHandleTXEInterrupt(I2C_RegDef_t *pI2Cx, uint8_t *pData);
static void I2C_MasterHandleRXNEInterrupt(I2C_RegDef_t *pI2Cx, uint8_t *pData);

#endif /* I2C_PRIVATE_H_ */
