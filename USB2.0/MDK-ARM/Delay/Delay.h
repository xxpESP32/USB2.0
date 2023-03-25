#ifndef __Delay_H
#define __Delay_H
#include "main.h"
#include "gpio.h"
void Delay_init(u8 SYSCLK);
void delay_us(u32 nus);
#endif