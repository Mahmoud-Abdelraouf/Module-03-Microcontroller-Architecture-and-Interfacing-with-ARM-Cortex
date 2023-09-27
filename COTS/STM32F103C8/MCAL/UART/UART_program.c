/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 32 Sep 2023                *****************/
/******* Version   : 0.1                        *****************/
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
Std_ReturnType UART_Init(USART_Config_t *Copy_USARTConfig)
{
    /**< Configure UART word length (data bits) */
  if (Copy_USARTConfig->WordLength == UART_WORD_LENGTH_8BIT)
  {
    /**< Configure 8-bit word length */
    USART2->CR1 &= ~USART_CR1_M;  /**< Clear the M bit for 8-bit word length */ 
  }
  else if (Copy_USARTConfig->WordLength == UART_WORD_LENGTH_9BIT)
  {
    /**< Configure 9-bit word length */
    USART2->CR1 |= USART_CR1_M;  /**< Set the M bit for 8-bit word length */ 
  }

  /**< Configure UART stop bits */
  USART2->CR2 &= ~USART_CR2_STOP;     /**< Clear the STOP bits */ 
  USART2->CR2 |= Copy_USARTConfig->StopBits;    /**< Set the specified stop bits */

  /**< Configure UART parity mode */
  if (Copy_USARTConfig->ParityMode == UART_PARITY_NONE)
  {
    /**< Configure no parity */
    USART2->CR1 &= ~(USART_CR1_PCE | USART_CR1_PS); /**< Clear the PCE and PS bits for no parity */
  }
  else if (Copy_USARTConfig->ParityMode == UART_PARITY_EVEN)
  {
    /**< Configure even parity */
    USART2->CR1 |= USART_CR1_PCE;   /**< Set the PCE bit for even parity */ 
    USART2->CR1 &= ~USART_CR1_PS;   /**< Clear the PS bit for even parity */
  }
  else if (Copy_USARTConfig->ParityMode == UART_PARITY_ODD)
  {
    /**< Configure odd parity */
    USART2->CR1 |= USART_CR1_PCE;   /**< Set the PCE bit for odd parity */ 
    USART2->CR1 |= USART_CR1_PS;    /**< Set the PS bit for odd parity */ 
  }

  /*********************< Configure UART baud rate *********************/
  /**< Calculate the value of the USARTDIV register based on the desired baud rate */
  f32 Local_f32USARTDIV = (f32)USART_CLK_SRC / (16 * Copy_USARTConfig->BaudRate);

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

  /**< Enable UART */
  USART2->CR1 |= USART_CR1_UE;  /**< Set the UE bit to enable UART */ 
}
