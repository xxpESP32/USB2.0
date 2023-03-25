#ifndef __ADC_H
#define __ADC_H
#include "main.h"
#include "gpio.h"


extern uint16_t ADC_ALL_BUFF[4];

extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_adc1;
extern ADC_ChannelConfTypeDef sConfig;

void ADC_Dma_Init(void);
void ADC_Init(void);




#endif