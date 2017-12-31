#include "stm32f10x.h"
#include "delay.h"
#include "sys.h"
#include "led.h"
#include "motor.h"
#include "remote.h" 
#include "usart.h"	

extern int flag;

void Enable_Init(void)
{ 
 GPIO_InitTypeDef  GPIO_InitStructure;	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);	 //使能PE端口时钟
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;				 //PE.6 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOE, &GPIO_InitStructure);					 //根据设定参数初始化GPIOE.6
}

int main(void)
{
	u8 key;	//红外
	u8 flag2=0;//默认自动
	delay_init();	    	 //延时函数初始化
	NVIC_Configuration(); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
 	LED_Init();			     //LED端口初始化
	Timer2_Init( );	
	uart_init(115200);	 //串口初始化为115200
	PWM_Init(1000,0);  	//不分频。PWM频率=72000/1000=72Khz
	Remote_Init();			//红外接收初始化
	Enable_Init();

	while(1)
	{

		key=Remote_Scan();	
		
		if(key==162)
		{
//		Waterlights();
			flag2=1;
		}
		if(key==226)
		{
			flag2=0;			
		} 
		
		if(key==66)
		{
			TIM2->CCER&=0; //禁止步进电机			
		}
		
		if(flag2==1)	//左上角按键
		{
			
			USART2_DATA(key);
			  
		} 

		if(flag&&((PEin(6)==0)||flag2==0))//右上角按键或开关打开
		{
		  
			USART1_DATA();
			flag=0;
		}
		
		
	}
}

