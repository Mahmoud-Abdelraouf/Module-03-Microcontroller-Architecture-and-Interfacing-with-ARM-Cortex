/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 32 Sep 2023                *****************/
/******* Version   : 0.2                        *****************/
/******* File Name : UART_interface.h           *****************/
/****************************************************************/

/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL *****************************/
#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"
/*****************************< Function Implementations *****************************/
Std_ReturnType MCAL_USART_Init(USART_Config_t *USARTConfig)
{
	if(USARTConfig == NULL)
	{
		return E_INVALID_PARAMETER;
	}
  /**< Configure UART word length (data bits) */
  if (USARTConfig->WordLength == USART_WORD_LENGTH_8BIT)
  {
    /**< Configure 8-bit word length */
    USART2->CR1 &= ~USART_CR1_M;  /**< Clear the M bit for 8-bit word length */ 
  }
  else if (USARTConfig->WordLength == USART_WORD_LENGTH_9BIT)
  {
    /**< Configure 9-bit word length */
    USART2->CR1 |= USART_CR1_M;  /**< Set the M bit for 8-bit word length */ 
  }

  /**< Configure UART stop bits */
  USART2->CR2 &= ~USART_CR2_STOP;     /**< Clear the STOP bits */ 
  USART2->CR2 |= ((USARTConfig->StopBits) << 12);  /**< Set the specified stop bits */

  /**< Configure UART parity mode */
  if (USARTConfig->ParityMode == USART_PARITY_NONE)
  {
    /**< Configure no parity */
    USART2->CR1 &= ~(USART_CR1_PCE | USART_CR1_PS); /**< Clear the PCE and PS bits for no parity */
  }
  else if (USARTConfig->ParityMode == USART_PARITY_EVEN)
  {
    /**< Configure even parity */
    USART2->CR1 |= USART_CR1_PCE;   /**< Set the PCE bit for even parity */ 
    USART2->CR1 &= ~USART_CR1_PS;   /**< Clear the PS bit for even parity */
  }
  else if (USARTConfig->ParityMode == USART_PARITY_ODD)
  {
    /**< Configure odd parity */
    USART2->CR1 |= USART_CR1_PCE;   /**< Set the PCE bit for odd parity */ 
    USART2->CR1 |= USART_CR1_PS;    /**< Set the PS bit for odd parity */ 
  }

  /*********************< Configure UART baud rate *********************/
  /**< Calculate the value of the USARTDIV register based on the desired baud rate */
  f32 Local_f32USARTDIV = (f32)USART_CLK_SRC / (16 * USARTConfig->BaudRate);

  /**< Calculate the integer (mantissa) and fractional parts of USARTDIV */
  u16 Local_u16DIV_Mantissa = (u16)Local_f32USARTDIV;
  u16 Local_u16DIV_Fraction = (u16)(((Local_f32USARTDIV - Local_u16DIV_Mantissa) * 16) + 0.5);

  /**< Check if the fractional part requires carrying */
  u8 Local_u8Carry = 0;
  if (Local_u16DIV_Fraction >= 16)
  {
    Local_u16DIV_Fraction -= 16;
    Local_u8Carry = 1;
  }

  /**< Adjust the mantissa if carry is required */
  if (Local_u8Carry == 1)
  {
    Local_u16DIV_Mantissa += 1;
  }

  /**< Configure the Baud Rate Register (BRR) with calculated values */
  USART2->BRR = (Local_u16DIV_Mantissa << 4) | Local_u16DIV_Fraction;
  /*********************< End of Configure UART baud rate *********************/

  /**< Enable Transmitter */
  USART2->CR1 |= USART_CR1_TE;  /**< Set the TE bit to enable UART */ 
  /**< Enable Receiver */
  USART2->CR1 |= USART_CR1_RE;  /**< Set the RE bit to enable UART */ 
  /**< Enable UART */
  USART2->CR1 |= USART_CR1_UE;  /**< Set the UE bit to enable UART */  
	
	return E_OK;
}

Std_ReturnType MCAL_USART_Transmit(u8 *Data, u16 DataSize)
{
  if (Data == NULL || DataSize == 0) 
  {
    return E_INVALID_PARAMETER; /**< Define your error code for invalid parameters */ 
  }

  for (u16 i = 0; i < DataSize; ++i) 
  {
    /**< Wait for the Transmit Data Register to be empty */ 
    while (!(USART2->SR & USART_SR_TXE)) 
    {
      /**< Wait until the TXE flag is set, indicating that the data register is empty and ready to transmit */ 
    }
    /**< Load the data into the Data Register */ 
    USART2->DR = Data[i];
    /**< Wait for the Transmission Complete */ 
    while (!(USART2->SR & USART_SR_TC))
    {
      /**<  Wait until the TC flag is set, indicating that the transmission is complete */
    }
  }

  return E_OK; /**< Define your success code */ 
}

Std_ReturnType MCAL_USART_Receive(char *Data)
{
  if (Data == NULL)
  {
    return E_INVALID_PARAMETER; /**< Define your error code for invalid parameters */ 
  }

  /**< Wait until data is received */
  if (!(USART2->SR & USART_SR_RXNE))
  {
	  return E_NOT_OK;
  }
  /**< Read the received data */
  *Data = USART2->DR;

  return E_OK; /**< Define your success code */ 
}
