/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 29 Sep 2023                *****************/
/******* Version   : 0.2                        *****************/
/******* File Name : DIO_private.h              *****************/
/****************************************************************/
#ifndef __DIO_PRIVATE_H_
#define __DIO_PRIVATE_H_

/**
 * @brief Macro definitions for PORT registers.
 * 
 * These macros define the register addresses for PORTA, PORTB, PORTC, and PORTD.
 */
#define DIO_PORTA_R        *((volatile u8*)0X3B)
#define DIO_PORTB_R        *((volatile u8*)0X38)
#define DIO_PORTC_R        *((volatile u8*)0X35)
#define DIO_PORTD_R        *((volatile u8*)0X32)

/**
 * @brief Macro definitions for DDR registers.
 * 
 * These macros define the register addresses for DDRA, DDRB, DDRC, and DDRD (Data Direction Registers).
 */
#define DIO_DDRA_R         *((volatile u8*)0X3A)
#define DIO_DDRB_R         *((volatile u8*)0X37)
#define DIO_DDRC_R         *((volatile u8*)0X34)
#define DIO_DDRD_R         *((volatile u8*)0X31)

/**
 * @brief Macro definitions for PIN registers.
 * 
 * These macros define the register addresses for PINA, PINB, PINC, and PIND (Input Pins Registers).
 */
#define DIO_PINA_R         *((volatile u8*)0X39)
#define DIO_PINB_R         *((volatile u8*)0X36)
#define DIO_PINC_R         *((volatile u8*)0X33)
#define DIO_PIND_R         *((volatile u8*)0X30)

/**
 * @brief Macros for Pin Direction.
 * 
 * These macros define the possible directions a pin can have:
 * - DIO_INITIAL_OUTPUT: Set the pin as an output.
 * - DIO_INITIAL_INPUT: Set the pin as an input.
 */
#define DIO_INITIAL_OUTPUT  1
#define DIO_INITIAL_INPUT   0

/**
 * @brief Macros for Pin Values.
 * 
 * These macros define the possible initial values for a pin:
 * - DIO_OUTPUT_LOW: Set the pin's initial value to low (logic 0).
 * - DIO_OUTPUT_HIGH: Set the pin's initial value to high (logic 1).
 * - DIO_FLOATING: Set the pin as floating (for input pins).
 * - DIO_PULL_UP: Set the pin with an internal pull-up resistor (for input pins).
 */
#define DIO_OUTPUT_LOW      0
#define DIO_OUTPUT_HIGH     1
#define DIO_FLOATING        0
#define DIO_PULL_UP         1

/**
 * @brief Concatenation Helper Macros.
 * 
 * These macros are used to concatenate multiple bits to form a binary value.
 */
#define Conc(b7,b6,b5,b4,b3,b2,b1,b0)            Conc_Help(b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_Help(b7,b6,b5,b4,b3,b2,b1,b0)        0b##b7##b6##b5##b4##b3##b2##b1##b0

#endif /* __DIO_PRIVATE_H_ */