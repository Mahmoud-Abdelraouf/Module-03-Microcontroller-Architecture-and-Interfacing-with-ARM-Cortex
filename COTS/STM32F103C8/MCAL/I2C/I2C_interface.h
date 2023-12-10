/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 10 Dec 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : I2C_interface.c            *****************/
/****************************************************************/
#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

typedef enum {
    I2C_SPEED_STANDARD,
    I2C_SPEED_FAST
} I2C_Speed_t;

typedef enum {
    I2C_Mode_I2C,
    I2C_Mode_SMBusDevice,
    I2C_Mode_SMBusHost,
} I2C_Mode_t;

typedef enum {
    I2C_DutyCycle_2,
    I2C_DutyCycle_16_9
} I2C_DutyCycle_t;

typedef struct {
    u32 ClockSpeed;
    I2C_Speed_t SpeedMode;
    I2C_Mode_t Mode;
    I2C_DutyCycle_t DutyCycle;
    u8 OwnAddress1;
    u8 Ack;
    u8 AcknowledgedAddress;
} I2C_Config_t;


Std_ReturnType I2C_Init(I2C_Config_t *I2CConfig);
Std_ReturnType I2C_StartCondition(void);
Std_ReturnType I2C_StopCondition(void);
Std_ReturnType I2C_SendData(u8 address, u8* data, u8 dataSize);
Std_ReturnType I2C_ReceiveData(u8 address, u8* data, u8 dataSize);

#endif /* I2C_INTERFACE_H_ */

