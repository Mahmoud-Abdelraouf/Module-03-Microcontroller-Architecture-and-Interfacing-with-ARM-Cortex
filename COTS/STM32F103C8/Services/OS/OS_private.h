/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 30 Sep 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : OS_private.h               *****************/
/****************************************************************/
#ifndef OS_PRIVATE_H_
#define OS_PRIVATE_H_


typedef struct {
    u16 Periodicity;
    u8 FirstDelay;
    void (*pf)(void);
} TCB_t;







#endif /**< OS_PRIVATE_H_ */