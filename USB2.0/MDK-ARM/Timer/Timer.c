#include "Timer.h"
#include "ADC.h"
#include "menu_gui.h"
TIM_HandleTypeDef htim10;
uint16_t time_nember;
float umA_Num;
float umA_Num_Sum;
float uW_Num;
float uW_Num_Sum;
	uint32_t H;
	uint32_t M;
	uint32_t S;
void Timer_Init(void){
	TIM_ClockConfigTypeDef sClockSourceConfig;
  TIM_MasterConfigTypeDef sMasterConfig;
	 __HAL_RCC_TIM1_CLK_ENABLE();

	htim10.Instance = TIM1;
  htim10.Init.Prescaler = 6400-1;
  htim10.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim10.Init.Period = 10000-1;
  htim10.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim10.Init.RepetitionCounter = 0;
  htim10.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  HAL_TIM_Base_Init(&htim10);
	
	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  HAL_TIM_ConfigClockSource(&htim10, &sClockSourceConfig);
	
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  HAL_TIMEx_MasterConfigSynchronization(&htim10, &sMasterConfig);

  HAL_NVIC_SetPriority(TIM1_BRK_UP_TRG_COM_IRQn, 2, 1);
  HAL_NVIC_EnableIRQ(TIM1_BRK_UP_TRG_COM_IRQn);
	
	HAL_TIM_Base_Start_IT(&htim10);
	//TIM3_IRQHandler 
		
}

void TIM1_BRK_UP_TRG_COM_IRQHandler(void){
	
	HAL_TIM_IRQHandler(&htim10);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance==TIM1&&((((ADC_ALL_BUFF[1]*3.3)/4095)*1.5049)-0.09)>0){
		time_nember++;
		S=time_nember;
		if(S>=60){
			M++;
			time_nember=0;
		}
		if(M>=60){
			H++;
			M=0;
		}
		umA_Num=(((((ADC_ALL_BUFF[1]*3.3)/4095)*1.5049)/3600));
		umA_Num_Sum+=umA_Num;
		uW_Num=umA_Num*((ADC_ALL_BUFF[0]*3.3)/4095)*23.00;
		uW_Num_Sum+=uW_Num;
//		XX++;
	}
	
}


