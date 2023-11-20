/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 29 Sep 2023                *****************/
/******* Version   : 0.2                        *****************/
/******* File Name : DIO_config.h               *****************/
/****************************************************************/
#ifndef __DIO_CONFIG_H_
#define __DIO_CONFIG_H_

/**
 * @brief Initial Direction Options for All Pins
 *
 * The following macros define the initial direction settings for each pin on the specified ports.
 * You can choose one of the following options for a pin's initial direction:
 *
 * - DIO_INITIAL_OUTPUT: Set the pin as an output.
 * - DIO_INITIAL_INPUT : Set the pin as an input.
 */
 
/**************************< Port A **************************/
#define DIO_PA0_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT
#define DIO_PA1_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT
#define DIO_PA2_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT
#define DIO_PA3_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT
#define DIO_PA4_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT
#define DIO_PA5_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT
#define DIO_PA6_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT
#define DIO_PA7_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT

/**************************< Port B **************************/
#define DIO_PB0_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT
#define DIO_PB1_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT
#define DIO_PB2_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT
#define DIO_PB3_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT
#define DIO_PB4_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT
#define DIO_PB5_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT
#define DIO_PB6_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT
#define DIO_PB7_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT

/**************************< Port C **************************/
#define DIO_PC0_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT
#define DIO_PC1_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT
#define DIO_PC2_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT
#define DIO_PC3_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT
#define DIO_PC4_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT
#define DIO_PC5_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT
#define DIO_PC6_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT
#define DIO_PC7_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT

/**************************< Port D **************************/
#define DIO_PD0_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT
#define DIO_PD1_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT
#define DIO_PD2_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT
#define DIO_PD3_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT
#define DIO_PD4_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT
#define DIO_PD5_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT
#define DIO_PD6_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT
#define DIO_PD7_INITIAL_DIRECTION   DIO_INITIAL_OUTPUT
  
 /**
 * @brief Initial Value Options for All Pins
 *
 * The following macros define the initial value settings for each pin on the specified ports.
 * You can choose one of the following options for a pin's initial value:
 *
 * - DIO_OUTPUT_LOW : Set the pin's initial value to low (logic 0).
 * - DIO_OUTPUT_HIGH: Set the pin's initial value to high (logic 1).
 * - DIO_FLOATING   : Set the pin as floating (for input pins).
 * - DIO_PULL_UP    : Set the pin with an internal pull-up resistor (for input pins).
 */
 
/**************************< Port A **************************/
#define DIO_PA0_INITIAL_VALUE   DIO_OUTPUT_LOW
#define DIO_PA1_INITIAL_VALUE   DIO_OUTPUT_LOW
#define DIO_PA2_INITIAL_VALUE   DIO_OUTPUT_LOW
#define DIO_PA3_INITIAL_VALUE   DIO_OUTPUT_LOW
#define DIO_PA4_INITIAL_VALUE   DIO_OUTPUT_LOW
#define DIO_PA5_INITIAL_VALUE   DIO_OUTPUT_LOW
#define DIO_PA6_INITIAL_VALUE   DIO_OUTPUT_LOW
#define DIO_PA7_INITIAL_VALUE   DIO_OUTPUT_LOW

/**************************< Port B **************************/
#define DIO_PB0_INITIAL_VALUE   DIO_OUTPUT_LOW
#define DIO_PB1_INITIAL_VALUE   DIO_OUTPUT_LOW
#define DIO_PB2_INITIAL_VALUE   DIO_OUTPUT_LOW
#define DIO_PB3_INITIAL_VALUE   DIO_OUTPUT_LOW
#define DIO_PB4_INITIAL_VALUE   DIO_OUTPUT_LOW
#define DIO_PB5_INITIAL_VALUE   DIO_OUTPUT_LOW
#define DIO_PB6_INITIAL_VALUE   DIO_OUTPUT_LOW
#define DIO_PB7_INITIAL_VALUE   DIO_OUTPUT_LOW

/**************************< Port C **************************/
#define DIO_PC0_INITIAL_VALUE   DIO_OUTPUT_LOW
#define DIO_PC1_INITIAL_VALUE   DIO_OUTPUT_LOW
#define DIO_PC2_INITIAL_VALUE   DIO_OUTPUT_LOW
#define DIO_PC3_INITIAL_VALUE   DIO_OUTPUT_LOW
#define DIO_PC4_INITIAL_VALUE   DIO_OUTPUT_LOW
#define DIO_PC5_INITIAL_VALUE   DIO_OUTPUT_LOW
#define DIO_PC6_INITIAL_VALUE   DIO_OUTPUT_LOW
#define DIO_PC7_INITIAL_VALUE   DIO_OUTPUT_LOW

/**************************< Port D **************************/
#define DIO_PD0_INITIAL_VALUE   DIO_OUTPUT_LOW
#define DIO_PD1_INITIAL_VALUE   DIO_OUTPUT_LOW
#define DIO_PD2_INITIAL_VALUE   DIO_OUTPUT_LOW
#define DIO_PD3_INITIAL_VALUE   DIO_OUTPUT_LOW
#define DIO_PD4_INITIAL_VALUE   DIO_OUTPUT_LOW
#define DIO_PD5_INITIAL_VALUE   DIO_OUTPUT_LOW
#define DIO_PD6_INITIAL_VALUE   DIO_OUTPUT_LOW
#define DIO_PD7_INITIAL_VALUE   DIO_OUTPUT_LOW  


#endif /**< __DIO_CONFIG_H_ */