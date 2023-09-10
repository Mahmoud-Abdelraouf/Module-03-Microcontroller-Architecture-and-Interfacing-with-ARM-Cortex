/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 9 Sep 2023                 *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : EXTI_interface.h           *****************/
/****************************************************************/
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


#define EXTI_FILING_EDGE        0
#define EXTI_RISING_EDGE        1
#define EXTI_BOTH_EDGE          2


#define EXTI0              0             
#define EXTI1              1
#define EXTI2              2
#define EXTI0              3
#define EXTI0              4
#define EXTI0              5
#define EXTI0              6
#define EXTI0              7
#define EXTI0              8
#define EXTI0              9
#define EXTI0              10
#define EXTI0              11
#define EXTI0              12
#define EXTI0              13
#define EXTI0              14
#define EXTI0              15


Std_ReturnType EXTI_Init(void);

Std_ReturnType EXTI_Enable(u8 Copy_Line);

Std_ReturnType EXTI_Disable(u8 Copy_Line);

Std_ReturnType EXTI_SetPinTrigger(u8 Copy_Line, u8 Copy_Mode);




#endif /**< EXTI_INTERFACE_H_ */