#ifndef __menu_H
#define __menu_H
#include "main.h"
#include "gpio.h"

#define NMOS_1 GPIO_PIN_12
#define NMOS_2 GPIO_PIN_6
#define Buzz   GPIO_PIN_11

#define NMOS_ON_1()   HAL_GPIO_WritePin(GPIOA,NMOS_1,GPIO_PIN_SET);
#define NMOS_OFF_1()   HAL_GPIO_WritePin(GPIOA,NMOS_1,GPIO_PIN_RESET);

#define NMOS_ON_2()   HAL_GPIO_WritePin(GPIOA,NMOS_2,GPIO_PIN_SET);
#define NMOS_OFF_2()   HAL_GPIO_WritePin(GPIOA,NMOS_2,GPIO_PIN_RESET);

#define NMOS_ON_3()   HAL_GPIO_WritePin(GPIOA,NMOS_3,GPIO_PIN_SET);
#define NMOS_OFF_3()   HAL_GPIO_WritePin(GPIOA,NMOS_3,GPIO_PIN_RESET);

#define NMOS_ON_4()   HAL_GPIO_WritePin(GPIOA,NMOS_4,GPIO_PIN_SET);
#define NMOS_OFF_4()   HAL_GPIO_WritePin(GPIOA,NMOS_4,GPIO_PIN_RESET);

typedef struct{
	u8 index;
	u8 next;
	u8 enter;
	u8 back;
	void (*current_operation)(void);		
}Menu_Creat;
extern Menu_Creat M_G[10];

extern void (*current_operation_func)(void);
extern u8 index_cp;

void menu_part_main(void);

void menu_part_son_one(void);
void menu_part_son_tow(void);
void menu_part_son_three(void);
void menu_part_son_four(void);
void menu_part_son_five(void);
void menu_part_son_six(void);
void menu_part_son_seven(void);

void GPIO_NMos_Init(void);
void Menu_Loop(void);

#endif 