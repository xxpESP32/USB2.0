#ifndef __OLED_H
#define __OLED_H 

#include "main.h"
#include "stdlib.h"	

//-----------------OLED�˿ڶ���---------------- 

#define OLED_SCL_Clr()   HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,GPIO_PIN_RESET)//SCL
#define OLED_SCL_Set()   HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,GPIO_PIN_SET)

#define OLED_SDA_Clr() HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,GPIO_PIN_RESET)//SCL
#define OLED_SDA_Set() HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,GPIO_PIN_SET)

//#define OLED_RES_Clr() GPIO_ResetBits(GPIOA,GPIO_Pin_2)//RES
//#define OLED_RES_Set() GPIO_SetBits(GPIOA,GPIO_Pin_2)


#define OLED_CMD  0	//д����
#define OLED_DATA 1	//д����

void OLED_ClearPoint(u8 x,u8 y);
void OLED_ColorTurn(u8 i);
void OLED_DisplayTurn(u8 i);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_WaitAck(void);
void Send_Byte(u8 dat);
void OLED_WR_Byte(u8 dat,u8 mode);
void OLED_DisPlay_On(void);
void OLED_DisPlay_Off(void);
void OLED_Refresh(void);
void OLED_Clear(void);
void OLED_Clear_Anti(void);
void OLED_Clear_Progress(u8 x,u8 y); //����ض�������
void OLED_DrawPoint(u8 x,u8 y,u8 t);
void OLED_DrawLine(u8 x1,u8 y1,u8 x2,u8 y2,u8 mode);
void OLED_Draw_Rect(u8 x,u8 y,u8 w,u8 h,u8 mode);//������
void OLED_DrawProgress(u8 x,u8 y,u8 w,u8 h,u8 mode,u16 set_Value);//��������
void OLED_DrawCircle(u8 x,u8 y,u8 r);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size1,u8 mode);
void OLED_ShowChar6x8(u8 x,u8 y,u8 chr,u8 mode);
void OLED_ShowString(u8 x,u8 y,u8 *chr,u8 size1,u8 mode);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size1,u8 mode);
void OLED_ShowFloatNum_8(u16 x,u16 y,float num,u8 len,u8 size1,u8 mode);
void OLED_ShowFloatNum1(u16 x,u16 y,float num,u8 len,u8 size1,u8 mode);
void OLED_ShowFloatNum2(u16 x,u16 y,float num,u8 len,u8 size1,u8 mode);
void OLED_ShowFloatNum4(u16 x,u16 y,double num,u8 len,u8 size1,u8 mode);
void OLED_ShowFloatNum5(u16 x,u16 y,double num,u8 len,u8 size1,u8 mode);
void OLED_ShowChinese(u8 x,u8 y,u8 num,u8 size1,u8 mode);
void OLED_ScrollDisplay(u8 num,u8 space,u8 mode);
void OLED_ShowPicture(u8 x,u8 y,u8 sizex,u8 sizey,u8 BMP[],u8 mode);
void OLED_Init(void);

#endif

