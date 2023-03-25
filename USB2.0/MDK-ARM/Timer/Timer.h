#ifndef __Timer_H
#define __Timer_H
#include "main.h"
#include "gpio.h"

extern uint32_t XX;
extern uint32_t H;
extern uint32_t M;
extern uint32_t S;

extern float umA_Num_Sum;
extern float uW_Num_Sum;

void Timer_Init(void);

#endif 