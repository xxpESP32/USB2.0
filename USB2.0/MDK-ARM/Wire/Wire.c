#include "Wire.h"


void GPIO_inits(void){
	//首先是初始化数据总线和时钟总线
		GPIO_InitTypeDef GPIO_InitStruct = {0};
		__HAL_RCC_GPIOA_CLK_ENABLE();	
		
		GPIO_InitStruct.Pin = SDA_GPIO|SCL_GPIO;
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(Wrie_GPIO, &GPIO_InitStruct);
	  HAL_GPIO_WritePin(Wrie_GPIO,SDA_GPIO|SCL_GPIO,GPIO_PIN_SET);		
		
	
}

void GPIO_OUT_IN(u8 FLAG){  //数据总线的推挽输出和上拉输入模式
		GPIO_InitTypeDef GPIO_InitStruct = {0};	
	if(FLAG==1){
		__HAL_RCC_GPIOA_CLK_ENABLE();	
		
		GPIO_InitStruct.Pin = SDA_GPIO;
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(Wrie_GPIO, &GPIO_InitStruct);

	}else if(FLAG==0){
		__HAL_RCC_GPIOA_CLK_ENABLE();
		GPIO_InitStruct.Pin = SDA_GPIO;
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct.Pull = GPIO_NOPULL;

		HAL_GPIO_Init(Wrie_GPIO, &GPIO_InitStruct);		
		
	}		

}

void I2C_Strat(void){ 
	//模式是推挽输出模式
	GPIO_OUT_IN(1);    //I2C的起始信号是数据总线和时钟总线同时拉高
	SCL_HIGH;          //让后再延时4us，让后将SDA拉低
	SDA_HIGH;       //总之就是将数据总线由高电平转为低电平
	delay_us(4);
	SDA_LOW;
	delay_us(4);
	SCL_LOW;
}
void I2C_Stopping(void){
	GPIO_OUT_IN(1);
	SDA_LOW;
	delay_us(4);
	SCL_HIGH;
	delay_us(4);
	SDA_HIGH;
	delay_us(4);
}
u8 I2C_ACK_Wait(void){
	u8 Time_err;                 //ACk的等待就是读取当前ACk的状态
	GPIO_OUT_IN(0);              //上拉输入模式
	SCL_HIGH;delay_us(2);        //开始之前要吧把数据总线和时钟总线同时拉高
	//SDA_HIGH;Delay_us(1);          
	
	while(SDA_Read){             //判断数据总线的引脚状态为高返回1反之输出0时要
		Time_err++;                //将时钟总线拉低再返回0
		if(Time_err>250){          //这里的
			I2C_Stopping();
			return 1;
		}
	}
	SCL_LOW;
	delay_us(2);
	return 0;

}

void I2C_ACK(void){
	SCL_LOW;
	GPIO_OUT_IN(1);
	SDA_LOW;
	delay_us(2);
	SCL_HIGH;
	delay_us(2);
	SCL_LOW;
}
void I2C_NACK(void){
	SCL_LOW;
	GPIO_OUT_IN(1);
	SDA_HIGH;
	delay_us(2);
	SCL_HIGH;
	delay_us(2);
	SCL_LOW;
}
void I2C_Send_Byte(u8 tx){
	u8 t=0;
	GPIO_OUT_IN(1);
	SCL_LOW;
	for(t=0;t<8;t++){
		if((tx&0x80)>>7){
			SDA_HIGH;
		}else{
			SDA_LOW;
		}
		tx<<=1;
		delay_us(2);
		SCL_HIGH;
		delay_us(2);
		SCL_LOW;
		delay_us(2);
	}
	
	
}
/*
u8 I2C_Read_Byte(u8 ack){ // 1
	u8 i,rece;
	GPIO_OUT_IN(0);
	for(i=0;i<8;i++){
		SCL_LOW;
		Delay_us(2);
		SCL_HIGH;
		rece<<=1;
		if(SDA_Read) rece++;
		Delay_us(1);
	}
	 if(!ack){
		 I2C_NACK();
	 }else{     
		 I2C_ACK();
	 }
	 return rece;
}
*/
u8 I2C_Read_Byte(void){ // 1
	u8 i,rece;
	GPIO_OUT_IN(0);
	for(i=0;i<8;i++){
		SCL_LOW;
		delay_us(2);
		SCL_HIGH;
		rece<<=1;
		if(SDA_Read) rece++;
		delay_us(1);
	}
	 
	 return rece;
}
