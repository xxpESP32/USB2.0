#include "menu.h"
#include "menu_gui.h"
#include "menu.h"
u8 index_cp;
void (*current_operation_func)(void);



void GPIO_NMos_Init(void){
		GPIO_InitTypeDef GPIO_InitStruct = {0};
		__HAL_RCC_GPIOA_CLK_ENABLE();
		__HAL_RCC_GPIOB_CLK_ENABLE();		
		
		GPIO_InitStruct.Pin = NMOS_1|Buzz;
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
		
		GPIO_InitStruct.Pin = NMOS_2;
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);		
		
	  HAL_GPIO_WritePin(GPIOB,NMOS_2,GPIO_PIN_RESET);		
	  HAL_GPIO_WritePin(GPIOA,NMOS_1,GPIO_PIN_RESET);
}

Menu_Creat M_G[10]={
	
	{0,1,0,7,(*menu_part_main)}, //第一级
	
	{1,2,1,0,(*menu_part_son_one)},//第二级
	{2,3,2,1,(*menu_part_son_tow)},//第二级	
	{3,4,3,2,(*menu_part_son_three)},//第二级
	{4,5,4,3,(*menu_part_son_four)},//第二级	
	
	{5,6,5,4,(*menu_part_son_five)},//声音开关	
	{6,7,6,5,(*menu_part_son_six)},//背景	
	{7,0,7,6,(*menu_part_son_seven)},//清空时间
		
};

void Menu_Loop(void){
			current_operation_func=M_G[index_cp].current_operation;
      current_operation_func();	
	
}

void menu_part_main(void){
	menu_main_gui();
}
void menu_part_son_one(void){
	menu_switch_gui();
}
void menu_part_son_tow(void){
	menu_SD_switch_gui();
}
void menu_part_son_three(void){
	menu_Timer_gui();
}
void menu_part_son_four(void){
	menu_information_gui();
}
void menu_part_son_five(void){
	//menu_information_gui();
		menu_Set_Sound_gui();  	
}
void menu_part_son_six(void){
	//menu_information_gui();
	menu_Set_UI_gui();	
}
void menu_part_son_seven(void){
	//menu_information_gui();
	menu_Set_Rt_gui();	
}