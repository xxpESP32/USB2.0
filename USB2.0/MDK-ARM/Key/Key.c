#include "Key.h"
#include "menu.h"
#include "oled.h"
#include "AT24C32.h"
#include "Wire.h"

u8 switch_Flag;
u8 SD_switch_Flag;
u8 Sound_switch_Flag;
u8 UI_switch_Flag;
u8 Rt_switch_Flag;
//+++++++++++++++++++++
// AT24C02 1  ´æ´¢MOS¹Ü¿ª¹Ø×´Ì¬
// AT24C02 2  ´æ´¢SD¿¨µÄMOS¹Ü¿ª¹Ø×´Ì¬
// AT24C02 3  ´æ´¢ÉùÒô¿ª¹Ø×´Ì¬
// AT24C02 4  ´æ´¢Æ¤·ô¿ª¹Ø×´Ì¬
//+++++++++++++++++++++


static void switch_ON_OFF(void);
static void Sound_ON_OFF(void);
void GPIO_Begin(void){
	GPIO_InitTypeDef GPIO_InitStruct;
	__HAL_RCC_GPIOA_CLK_ENABLE();
	
	GPIO_InitStruct.Mode=GPIO_MODE_INPUT;
	GPIO_InitStruct.Pin =KEY_Left|KEY_True|KEY_Right;
	GPIO_InitStruct.Pull=GPIO_PULLUP;
	
	HAL_GPIO_Init(GPIOA,&GPIO_InitStruct);
}

void Key_Loop(void){
	if(HAL_GPIO_ReadPin(GPIOA,KEY_Left)==0){
		 if(Sound_switch_Flag==0){
			 HAL_GPIO_WritePin(GPIOA,Buzz,GPIO_PIN_SET);
			 HAL_Delay(100);
		 }else if(Sound_switch_Flag==1){
			 HAL_GPIO_WritePin(GPIOA,Buzz,GPIO_PIN_RESET);
			 HAL_Delay(100);			 
		 }
			OLED_Clear();
		
			index_cp=M_G[index_cp].next;
			
		
	}
	if(HAL_GPIO_ReadPin(GPIOA,KEY_True)==0){
		 if(Sound_switch_Flag==0){
			 HAL_GPIO_WritePin(GPIOA,Buzz,GPIO_PIN_SET);
			 HAL_Delay(100);
		 }else if(Sound_switch_Flag==1){
			 HAL_GPIO_WritePin(GPIOA,Buzz,GPIO_PIN_RESET);
			 HAL_Delay(100);			 
		 }
		  Sound_ON_OFF();
			switch_ON_OFF();
			OLED_Clear();
		
			index_cp=M_G[index_cp].enter;
			
		
	}
	if(HAL_GPIO_ReadPin(GPIOA,KEY_Right)==0){
		 HAL_GPIO_WritePin(GPIOA,Buzz,GPIO_PIN_SET);
		 if(Sound_switch_Flag==0){
			 HAL_GPIO_WritePin(GPIOA,Buzz,GPIO_PIN_SET);
			 HAL_Delay(100);
		 }else if(Sound_switch_Flag==1){
			 HAL_GPIO_WritePin(GPIOA,Buzz,GPIO_PIN_RESET);
			 HAL_Delay(100);			 
		 }		

			OLED_Clear();
		
			index_cp=M_G[index_cp].back;
			
		
	}
	HAL_GPIO_WritePin(GPIOA,Buzz,GPIO_PIN_RESET);
	Menu_Loop();
	OLED_Refresh();
	while(HAL_GPIO_ReadPin(GPIOA,KEY_Left)==0);
	while(HAL_GPIO_ReadPin(GPIOA,KEY_True)==0);
	while(HAL_GPIO_ReadPin(GPIOA,KEY_Right)==0);
}

static void switch_ON_OFF(void){
	if(index_cp==1){
		switch_Flag=!switch_Flag;
		AT24C32_Write_OneByte(1,switch_Flag);
	}
	if(index_cp==2){
		SD_switch_Flag=!SD_switch_Flag;
		//AT24C32_Write_OneByte(2,SD_switch_Flag);
	}	
}

static void Sound_ON_OFF(void){
	if(index_cp==5){
		Sound_switch_Flag=!Sound_switch_Flag;
		AT24C32_Write_OneByte(3,Sound_switch_Flag);		
	}
	if(index_cp==6){
		UI_switch_Flag=!UI_switch_Flag;
		AT24C32_Write_OneByte(4,UI_switch_Flag);
	}
	if(index_cp==7){
		Rt_switch_Flag=!Rt_switch_Flag;
		AT24C32_Write_OneByte(5,Rt_switch_Flag);		
	}
}

void Set_Init(void){
  switch_Flag=AT24C32_Read_OneByte(1);
  //SD_switch_Flag=AT24C32_Read_OneByte(2);	
	Sound_switch_Flag=AT24C32_Read_OneByte(3);
	UI_switch_Flag=AT24C32_Read_OneByte(4);
	Rt_switch_Flag=AT24C32_Read_OneByte(5);
}