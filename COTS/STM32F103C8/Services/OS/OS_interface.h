/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 30 Sep 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : OS_interface.h             *****************/
/****************************************************************/
#ifndef OS_INTERFACE_H_
#define OS_INTERFACE_H_



Std_ReturnType OS_CreateTask(u8 Copy_Priority, u16 Copy_Periodicity, void (*Copy_pf)(void));


void OS_StartScheduler(void);



#endif /**< OS_INTERFACE_H_ */