#include "menu_gui.h"
#include "oled.h"
#include "ADC.h"
#include "bmp.h"
#include "Key.h"
#include "menu.h"
#include "Timer.h"

ADC_Output_Dat ADC_OUT;
//Timer Time;

	
static void main_gui_post(void);
static void swith_Gui_OFF(u8 x,u8 y,u8 mode);
static void swith_Gui_ON(u8 x,u8 y,u8 mode);

static void SD_swith_Gui_OFF(u8 x,u8 y,u8 mode);
static void SD_swith_Gui_ON(u8 x,u8 y,u8 mode);
static void SD_gui_post(void);
static void menu_Set_Post_gui(u8 Set_Flag);

static void main_gui_post(void){
	OLED_Draw_Rect(60,0,2,64,1);
	//边框
	OLED_Draw_Rect(58,0,7,2,1);
	OLED_Draw_Rect(58,30,7,2,1);
	//OLED_Draw_Rect(58,0,2,2,1);
}

void menu_main_gui(void){

	  //显示电压
	  OLED_ShowString(2,0,"V",12,1);

		//OLED_Dispaly_Voltage(12,0,5,12,1,3);
    OLED_ShowFloatNum2(12,0,((ADC_ALL_BUFF[0]*3.3)/4095)*23.00,5,12,1);
    
	  OLED_ShowString(50,0,"V",12,1);
	  //显示电流
	  OLED_ShowString(2,15,"I",12,1);
	 // OLED_Dispaly_Current(12,15,5,12,1,3);
	   
    OLED_ShowFloatNum4(12,15,(((ADC_ALL_BUFF[1]*3.3)/4095)*1.74)-0.074,5,12,1);
		OLED_ShowString(50,15,"A",12,1);
	  //显示功率
	  OLED_ShowString(70,0,"W",12,1);	
	  ADC_OUT.ADC_Otput_Voltage=((ADC_ALL_BUFF[0]*3.3)/4095)*23.00;
	  ADC_OUT.ADC_Otput_Current=((ADC_ALL_BUFF[1]*3.3)/4095);
	  ADC_OUT.ADC_Otput_Power=ADC_OUT.ADC_Otput_Voltage*ADC_OUT.ADC_Otput_Current;
		OLED_ShowFloatNum2(80,0,ADC_OUT.ADC_Otput_Power,5,12,1);
		OLED_ShowString(114+4,0,"W",12,1);
	  //显示D+
	  OLED_ShowString(71,12,"D+",8,1);	
		//OLED_Dispaly_D_add(83,12,4,8,1,3);
OLED_ShowFloatNum_8(83,12,((ADC_ALL_BUFF[2]*3.3)/4095)*23.00,4,8,1);		
	  OLED_ShowString(114,12,"V",8,1);
	  //显示D-
	  OLED_ShowString(71,12+10,"D-",8,1);	
		//OLED_Dispaly_D_minus(83,12+10,4,8,1,3);
OLED_ShowFloatNum_8(83,12+10,((ADC_ALL_BUFF[3]*3.3)/4095)*23.00,4,8,1);	
	  OLED_ShowString(114,12+10,"V",8,1);
	  main_gui_post();
		
}


static void swith_Gui_OFF(u8 x,u8 y,u8 mode){
	OLED_Draw_Rect(x,y,60,20,mode);
	OLED_Draw_Rect(x+3,y+2,25,15,mode);
	OLED_Draw_Rect(x+4,y+3,24,14,mode);
	
}
static void swith_Gui_ON(u8 x,u8 y,u8 mode){
	OLED_Draw_Rect(x,y,60,20,mode);
	OLED_Draw_Rect(x+30,y+2,25,15,mode);
	OLED_Draw_Rect(x+31,y+3,24,14,mode);
	
}

void menu_switch_gui(void){
	

		
		OLED_ShowPicture(200,12,8,8,BMP1,0);
 		OLED_ShowPicture(10,0,20,30,BMP2,0);   
	
	//开关
	  if(switch_Flag==1){
			swith_Gui_ON(40,5,1);	
			OLED_ShowChinese(105,8,0,16,1);
			HAL_GPIO_WritePin(GPIOA,NMOS_1,switch_Flag);
		}else{
			swith_Gui_OFF(40,5,1);
			OLED_ShowChinese(105,8,1,16,1);			
			HAL_GPIO_WritePin(GPIOA,NMOS_1,switch_Flag);			
		}
//			OLED_ShowString(7,2,"U1",12,1);
	
	//开关二

	
	//menu_switch_post();
}
static void SD_swith_Gui_OFF(u8 x,u8 y,u8 mode){
	OLED_Draw_Rect(x,y,33,14,mode);
	OLED_Draw_Rect(x+3,y+2,14,10,mode);
	OLED_Draw_Rect(x+4,y+3,13,8,mode);
	
}
static void SD_swith_Gui_ON(u8 x,u8 y,u8 mode){
	OLED_Draw_Rect(x,y,33,14,mode);
	OLED_Draw_Rect(x+16,y+2,14,10,mode);
	OLED_Draw_Rect(x+16,y+3,13,8,mode);
	
}
static void SD_gui_post(void){
	OLED_Draw_Rect(64,0,1,64,1);
	OLED_Draw_Rect(64,15,128,1,1);	
}
void menu_SD_switch_gui(void){
 		OLED_ShowPicture(7,0,18,32,BMP3,1);	
    	  //显示D+
	  OLED_ShowString(68,2,"D+",12,1);	
		//OLED_Dispaly_D_add(83,12,4,8,1,3);
		OLED_ShowFloatNum_8(81,2,((ADC_ALL_BUFF[2]*3.3)/4095)*23.00,4,12,1);		
	  OLED_ShowString(119,2,"V",12,1);
	  //显示D-
	  OLED_ShowString(68,19,"D-",12,1);	
		//OLED_Dispaly_D_minus(83,12+10,4,8,1,3);
		OLED_ShowFloatNum_8(81,19,((ADC_ALL_BUFF[3]*3.3)/4095)*23.00,4,12,1);	
	  OLED_ShowString(119,19,"V",12,1);
	 if(SD_switch_Flag==1){
			SD_swith_Gui_ON(25,9,1);
	     HAL_GPIO_WritePin(GPIOB,NMOS_2,SD_switch_Flag);		 
			//NMOS_ON_1();
		}else if(SD_switch_Flag==0){
			SD_swith_Gui_OFF(25,9,1);
	    HAL_GPIO_WritePin(GPIOB,NMOS_2,SD_switch_Flag);
			//NMOS_OFF_1();			
		}
		SD_gui_post();
}


void menu_Timer_gui(void){
  
	//OLED_ShowPicture(5,0,128,32,BMP4,1);	
	OLED_ShowChinese(12,0,2,16,1);
	OLED_ShowChinese(12+16,0,3,16,1);
	
	OLED_ShowNum(1,14,H,3,12,1);
	OLED_ShowString(19,14,":",12,1);	
	OLED_ShowNum(25,14,M,2,12,1);
	OLED_ShowString(25+12,14,":",12,1);	
	OLED_ShowNum(43,14,S,2,12,1);
	
	OLED_ShowFloatNum5(64-5,2,umA_Num_Sum,9,12,1);
	OLED_ShowString(113,2,"Ah",12,1);		
	OLED_ShowFloatNum5(64-5,20,uW_Num_Sum,9,12,1);
	OLED_ShowString(113,20,"Wh",12,1);
	
  OLED_Draw_Rect(65,16,128,1,1);	
	
}

void menu_information_gui(void){
	OLED_ShowString(0,0,"Versions 1.1",8,1);
	OLED_ShowString(0,8,"Updated 2023/1/2",8,1);
	OLED_ShowString(0,16,"Name T12 Golden Crow",8,1);	
	OLED_ShowString(0,24,"Author Xiao Xia ",8,1);	
  	
}

static void menu_Set_Post_gui(u8 Set_Flag){
	if(Set_Flag==0){
		OLED_Draw_Rect(120,1,4,29,1);	
		OLED_Draw_Rect(122,3,0,8,1);			
	}
	if(Set_Flag==1){
		OLED_Draw_Rect(120,1,4,29,1);
		OLED_Draw_Rect(122,3+8,0,8,1);				
	}	
	if(Set_Flag==2){
		OLED_Draw_Rect(120,1,4,29,1);
		OLED_Draw_Rect(122,20,0,8,1);				
	}	
}

void menu_Set_Sound_gui(void){
	OLED_ShowString(3,4,">",12,1);

  if(Sound_switch_Flag==0){	
		OLED_ShowPicture(10,2,16,16,Sound_ON,1);
 			SD_swith_Gui_OFF(28,1,1);     	
	}
	 else if(Sound_switch_Flag==1){	
		 
		OLED_ShowPicture(10,2,16,16,Sound_OFF,1);  
		SD_swith_Gui_ON(28,1,1);		 
	}
  if(UI_switch_Flag==0){	
	  OLED_ShowString(10,16,"UI",16,1);
				OLED_ColorTurn(UI_switch_Flag);
 	  SD_swith_Gui_ON(28,17,1);     	
	}
	 else if(UI_switch_Flag==1){	
	  OLED_ShowString(10,16,"UI",16,1);	
		OLED_ColorTurn(UI_switch_Flag);		 
		SD_swith_Gui_OFF(28,17,1);		 
	}
	menu_Set_Post_gui(0);
		OLED_ShowPicture(72,0,32,32,Dat_Bmp,1);		
}
 


void menu_Set_UI_gui(void){
	OLED_ShowString(3,4+16,">",12,1);
	
  if(Sound_switch_Flag==0){	
		OLED_ShowPicture(10,2,16,16,Sound_ON,1);
 			SD_swith_Gui_OFF(28,1,1);     	
	}
	 else if(Sound_switch_Flag==1){	
		 
		OLED_ShowPicture(10,2,16,16,Sound_OFF,1);  
		SD_swith_Gui_ON(28,1,1);		 
	}
  if(UI_switch_Flag==0){	
	  OLED_ShowString(10,16,"UI",16,1);
		OLED_ColorTurn(UI_switch_Flag);
 	  SD_swith_Gui_ON(28,17,1);     	
	}
	 else if(UI_switch_Flag==1){	
	  OLED_ShowString(10,16,"UI",16,1);	
		OLED_ColorTurn(UI_switch_Flag);		 
		SD_swith_Gui_OFF(28,17,1);		 
	} 
	 	menu_Set_Post_gui(1);
		OLED_ShowPicture(72,0,32,32,Dat_Bmp,1);	
}

void menu_Set_Rt_gui(void){
	OLED_ShowString(3,4+16,">",12,1);
	
  if(UI_switch_Flag==0){	
	  OLED_ShowString(10,0,"UI",16,1);
		OLED_ColorTurn(UI_switch_Flag);
 	  SD_swith_Gui_ON(28,1,1);     	
	}
	 else if(UI_switch_Flag==1){	
	  OLED_ShowString(10,0,"UI",16,1);	
		OLED_ColorTurn(UI_switch_Flag);		 
		SD_swith_Gui_OFF(28,1,1);		 
	}
  if(Rt_switch_Flag==0){	
	  OLED_ShowString(10,16,"Rt",16,1);
    OLED_DisplayTurn(Rt_switch_Flag);
		SD_swith_Gui_ON(28,17,1);		
	}
	 else if(Rt_switch_Flag==1){	
	  OLED_ShowString(10,16,"Rt",16,1);	
    OLED_DisplayTurn(Rt_switch_Flag);	 
		SD_swith_Gui_OFF(28,17,1);		 
	}
	
	 	menu_Set_Post_gui(2);
		OLED_ShowPicture(72,0,32,32,Dat_Bmp,1);	
}