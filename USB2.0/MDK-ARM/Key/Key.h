#ifndef __Key_H
#define __Key_H
#include "main.h"
#include "gpio.h"

#define KEY_Left GPIO_PIN_4
#define KEY_True GPIO_PIN_5
#define KEY_Right GPIO_PIN_6

extern u8 switch_Flag;
extern u8 SD_switch_Flag;
extern u8 Sound_switch_Flag;
extern u8 UI_switch_Flag;
extern u8 Rt_switch_Flag;

void GPIO_Begin(void);
void Key_Loop(void);
void Set_Init(void);

#endif