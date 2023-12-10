/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 10 Dec 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : I2C_program.c              *****************/
/****************************************************************/

/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL *****************************/
#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_config.h"
/*****************************< Public function definitions *****************************/
Std_ReturnType I2C_Init(I2C_Config_t *I2CConfig) {
    // Configure I2C peripheral based on I2CConfig settings
    // Configure clock speed, mode, duty cycle, own address, etc.
    // Configure CR2 register for clock speed
    // Configure CCR register for other settings
    
    // Return success or failure based on initialization
    return E_OK;
}

Std_ReturnType I2C_StartCondition(void) {
    // Generate the Start condition by setting the START bit in CR1 register
    I2C1->CR1 |= I2C_CR1_START;
    
    // Wait until the Start condition is generated (polling)
    while (!(I2C1->SR1 & I2C_SR1_SB));
    
    return E_OK;
}

Std_ReturnType I2C_StopCondition(void) {
    // Generate the Stop condition by setting the STOP bit in CR1 register
    I2C1->CR1 |= I2C_CR1_STOP;
    
    // Wait until the Stop condition is generated (polling)
    while (!(I2C1->SR1 & I2C_SR1_STOPF));
    
    return E_OK;
}

Std_ReturnType I2C_SendData(u8 address, u8* data, u8 dataSize) {
    // Transmit data over I2C
    
    // Set the address in the data register
    I2C1->DR = address;
    
    // Implement sending data bytes by writing to the data register and handling transfer
    
    // Wait until data transmission is complete (polling TXE and BTF flags)
    while (dataSize > 0) {
        // Write data to DR register
        I2C1->DR = *data;
        
        // Wait for data transmission to complete
        while (!(I2C1->SR1 & I2C_SR1_TXE) && !(I2C1->SR1 & I2C_SR1_BTF));
        
        dataSize--;
        data++;
    }
    
    return E_OK;
}

Std_ReturnType I2C_ReceiveData(u8 address, u8* data, u8 dataSize) {
    // Receive data over I2C
    
    // Set the address in the data register
    I2C1->DR = address;
    
    // Implement receiving data bytes by reading from the data register and handling transfer
    
    // Wait until data reception is complete (polling RXNE flag)
    while (dataSize > 0) {
        // Wait for data reception to complete
        while (!(I2C1->SR1 & I2C_SR1_RXNE));
        
        // Read data from DR register
        *data = I2C1->DR;
        
        dataSize--;
        data++;
    }
    
    return E_OK;
}
/*****************************< Private function definitions *****************************/
static void I2C_ClearADDRFlag(I2C_RegDef_t *pI2Cx) {
    // Clear ADDR flag by reading SR1 and SR2 registers
    volatile uint32_t dummyRead;
    dummyRead = pI2Cx->SR1;
    dummyRead = pI2Cx->SR2;
    (void)dummyRead; // To avoid compiler warning about unused variable
}

static void I2C_EnableAck(I2C_RegDef_t *pI2Cx) {
    // Enable ACK by setting ACK bit in CR1 register
    pI2Cx->CR1 |= I2C_CR1_ACK;
}

static void I2C_DisableAck(I2C_RegDef_t *pI2Cx) {
    // Disable ACK by clearing ACK bit in CR1 register
    pI2Cx->CR1 &= ~I2C_CR1_ACK;
}

static void I2C_MasterHandleTXEInterrupt(I2C_RegDef_t *pI2Cx, uint8_t *pData) {
    // Handle TXE interrupt (transmit buffer empty)
    // Write data to DR register for transmission
    pI2Cx->DR = *pData;
}

static void I2C_MasterHandleRXNEInterrupt(I2C_RegDef_t *pI2Cx, uint8_t *pData) {
    // Handle RXNE interrupt (receive buffer not empty)
    // Read data from DR register
    *pData = pI2Cx->DR;
}