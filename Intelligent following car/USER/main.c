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
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);	 //ʹ��PE�˿�ʱ��
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;				 //PE.6 �˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOE, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOE.6
}

int main(void)
{
	u8 key;	//����
	u8 flag2=0;//Ĭ���Զ�
	delay_init();	    	 //��ʱ������ʼ��
	NVIC_Configuration(); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
 	LED_Init();			     //LED�˿ڳ�ʼ��
	Timer2_Init( );	
	uart_init(115200);	 //���ڳ�ʼ��Ϊ115200
	PWM_Init(1000,0);  	//����Ƶ��PWMƵ��=72000/1000=72Khz
	Remote_Init();			//������ճ�ʼ��
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
			TIM2->CCER&=0; //��ֹ�������			
		}
		
		if(flag2==1)	//���Ͻǰ���
		{
			
			USART2_DATA(key);
			  
		} 

		if(flag&&((PEin(6)==0)||flag2==0))//���Ͻǰ����򿪹ش�
		{
		  
			USART1_DATA();
			flag=0;
		}
		
		
	}
}

