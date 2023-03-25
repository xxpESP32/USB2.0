#include "ADC.h"
#include "oled.h"

//ADC_InitTypeDef ADC_InitStructure;
ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma1;
ADC_ChannelConfTypeDef sConfig={0};


uint16_t ADC_ALL_BUFF[4];

void ADC_Init(void){
	GPIO_InitTypeDef GPIO_InitStruct;

	
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_ADC_CLK_ENABLE();
	
	GPIO_InitStruct.Mode=GPIO_MODE_ANALOG;
	GPIO_InitStruct.Pin=GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3;
	GPIO_InitStruct.Pull=GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA,&GPIO_InitStruct);

	
	
	hadc1.Instance=ADC1;
	hadc1.Init.ClockPrescaler=ADC_CLOCKPRESCALER_PCLK_DIV4;
	hadc1.Init.ContinuousConvMode=ENABLE;
	hadc1.Init.ScanConvMode=ADC_SCAN_ENABLE;
	hadc1.Init.DiscontinuousConvMode=DISABLE;
	hadc1.Init.DataAlign=ADC_DATAALIGN_RIGHT;
	hadc1.Init.EOCSelection=ADC_EOC_SINGLE_CONV;
	hadc1.Init.ExternalTrigConv= ADC_SOFTWARE_START;
	hadc1.Init.ExternalTrigConvEdge=ADC_EXTERNALTRIGCONVEDGE_NONE;
	hadc1.Init.NbrOfConversion=4;
	//hadc1.Init.LowPowerAutoPowerOff=DISABLE;
	//hadc1.Init.LowPowerAutoWait=DISABLE;
	hadc1.Init.SamplingTimeCommon1=ADC_SAMPLETIME_160CYCLES_5;
	hadc1.Init.SamplingTimeCommon2=ADC_SAMPLETIME_160CYCLES_5;
	hadc1.Init.Overrun=ADC_OVR_DATA_PRESERVED;
	hadc1.Init.OversamplingMode=DISABLE;
	hadc1.Init.TriggerFrequencyMode=ADC_TRIGGER_FREQ_HIGH;
	hadc1.Init.DMAContinuousRequests=ENABLE;
  
	hadc1.Init.Resolution=ADC_RESOLUTION_12B;

		HAL_ADC_Init(&hadc1);
		sConfig.Channel = ADC_CHANNEL_0;
	  sConfig.Rank = ADC_REGULAR_RANK_1;
		sConfig.SamplingTime=ADC_SAMPLINGTIME_COMMON_1;
		
	  HAL_ADC_ConfigChannel(&hadc1, &sConfig);
	
		sConfig.Channel = ADC_CHANNEL_1;
	  sConfig.Rank = ADC_REGULAR_RANK_2;
		sConfig.SamplingTime=ADC_SAMPLINGTIME_COMMON_1;
		
	  HAL_ADC_ConfigChannel(&hadc1, &sConfig);
		
		sConfig.Channel = ADC_CHANNEL_2;
	  sConfig.Rank = ADC_REGULAR_RANK_3;
		sConfig.SamplingTime=ADC_SAMPLINGTIME_COMMON_2;
		
	  HAL_ADC_ConfigChannel(&hadc1, &sConfig);
		
		sConfig.Channel = ADC_CHANNEL_3;
	  sConfig.Rank = ADC_REGULAR_RANK_4;
		sConfig.SamplingTime=ADC_SAMPLINGTIME_COMMON_2;
		
	  HAL_ADC_ConfigChannel(&hadc1, &sConfig);
		
		
	  HAL_ADCEx_Calibration_Start(&hadc1);
	
	
}

void ADC_Dma_Init(void){

	__HAL_RCC_DMA1_CLK_ENABLE();
	
	hdma1.Instance=DMA1_Channel1;
	hdma1.Init.Direction=LL_DMA_DIRECTION_PERIPH_TO_MEMORY;
	hdma1.Init.MemDataAlignment=DMA_MDATAALIGN_HALFWORD;
	hdma1.Init.PeriphDataAlignment=DMA_PDATAALIGN_HALFWORD;
	hdma1.Init.MemInc=DMA_MINC_ENABLE;
	hdma1.Init.PeriphInc=DMA_PINC_DISABLE;
	hdma1.Init.Mode=DMA_CIRCULAR;
  hdma1.Init.Priority=DMA_PRIORITY_LOW;
	hdma1.Init.Request=DMA_REQUEST_ADC1;
	
	HAL_DMA_Init(&hdma1);
	__HAL_LINKDMA(&hadc1,DMA_Handle,hdma1);
	
//	HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 0, 1);
//  HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);
	
}
//void DMA1_Channel1_IRQHandler(void)
//{

//  HAL_DMA_IRQHandler(&hdma1);

//}
//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！DMA霞編！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！



//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！DMA潤崩！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！

		
