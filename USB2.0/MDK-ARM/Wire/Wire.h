#ifndef __Wire_H
#define __Wire_H

#include "Delay.h"
#include "main.h"
#include "gpio.h"

#define SDA_GPIO  GPIO_PIN_7
#define SCL_GPIO  GPIO_PIN_8
#define Wrie_GPIO  GPIOA
#define SDA_LOW   HAL_GPIO_WritePin(Wrie_GPIO,SDA_GPIO,GPIO_PIN_RESET)
#define SDA_HIGH  HAL_GPIO_WritePin(Wrie_GPIO,SDA_GPIO,GPIO_PIN_SET)
#define SCL_LOW   HAL_GPIO_WritePin(Wrie_GPIO,SCL_GPIO,GPIO_PIN_RESET)
#define SCL_HIGH  HAL_GPIO_WritePin(Wrie_GPIO,SCL_GPIO,GPIO_PIN_SET)
#define SDA_Read  HAL_GPIO_ReadPin(Wrie_GPIO,SDA_GPIO)

void GPIO_inits(void);
void GPIO_OUT_IN(u8 FLAG);
void I2C_Strat(void);
void I2C_Stopping(void);
u8 I2C_ACK_Wait(void);
void I2C_ACK(void);
void I2C_NACK(void);
void I2C_Send_Byte(u8 tx);
//u8 I2C_Read_Byte(u8 ack);
u8 I2C_Read_Byte(void);
#endif
