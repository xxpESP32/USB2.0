#ifndef __menu_gui_H
#define __menu_gui_H
#include "main.h"
#include "gpio.h"

typedef struct {
	float ADC_Otput_Voltage;
	float ADC_Otput_Current;
	float ADC_Otput_Power;
	
}ADC_Output_Dat;


//typedef struct {

//	
//}Timer;
//extern Timer Time;



void menu_main_gui(void);
void menu_switch_gui(void);
void menu_SD_switch_gui(void);
void menu_Timer_gui(void);
void menu_information_gui(void);
void menu_Set_Sound_gui(void);
void menu_Set_UI_gui(void);
void menu_Set_Rt_gui(void);
#endif