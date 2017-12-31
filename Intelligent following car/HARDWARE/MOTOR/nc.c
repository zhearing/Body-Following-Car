#include "nc.h"
#include "sys.h"
#include "delay.h"
#include "usart.h"

//PA6ΪPWM��� ������ֱ�����
//PA0ΪPWM��� �����Ʋ������
//PA2Ϊ���� �����Ʋ������ת��
//�������ݸ�ʽ  1 ֱ��������� ��ת�����������ת1s	 ��1-15��

u16 stepfrequency=1000; 
u16 mubiao=0;
u16 dangqian=0;

void USART1_DATA(void)
{
	switch(USART_RX_BUF[1]-'a'+1)	//�����Ǹ��������
	{
		

   case 1:
			  PAout(1)=0;	// ֱ��ǰ��
				PAout(4)=1;	  // ������� ��ת	
				delay_ms(100); 
			  TIM3->CCER|=1; /*����PWM1 ֱ���������   */
				TIM2->CCER|=1; //ͨ��1���ʹ��					
				MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //��1000hz��Ƶ�����500������  /*����PWM1*/
		break;
		case 2:
				TIM3->CCER &= ~1;/*��ֹPWM1*/
				TIM2->CCER &= ~1;/*��ֹ����*/
			break;
			
		case 3:
			  PAout(1)=1;	// ֱ����� ����
			  delay_ms(100);
        TIM3->CCER|=1; /*����PWM1 ֱ���������   */
				TIM2->CCER&=0; //��ֹ�������
				break;
			
		
		case 4:
			  PAout(1)=0;	// ֱ����� ǰ��
				PAout(4)=1;	  // ������� ��ת	 
			  TIM3->CCER|=1; /*����PWM1 ֱ���������   */
				TIM2->CCER|=1; //ͨ��1���ʹ��					
				MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //��1000hz��Ƶ�����500������  /*����PWM1*/
		break;
		
		case 5:
			  PAout(1)=0;	// ֱ����� ǰ��
				PAout(4)=1;	  // ������� ��ת	 
			  TIM3->CCER|=1; /*����PWM1 ֱ���������   */
				TIM2->CCER|=1; //ͨ��1���ʹ��					
				MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //��1000hz��Ƶ�����500������  /*����PWM1*/
		break;
		case 6:
			  PAout(1)=0;	// ֱ����� ǰ��
				PAout(4)=1;	  // ������� ��ת	 
			  TIM3->CCER|=1; /*����PWM1 ֱ���������   */
				TIM2->CCER|=1; //ͨ��1���ʹ��					
				MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //��1000hz��Ƶ�����500������  /*����PWM1*/
		break;
		case 7:
			  PAout(1)=0;	// ֱ����� ǰ��
				PAout(4)=1;	  // ������� ��ת	 
			  TIM3->CCER|=1; /*����PWM1 ֱ���������   */
				TIM2->CCER|=1; //ͨ��1���ʹ��					
				MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //��1000hz��Ƶ�����500������  /*����PWM1*/
		break;
		
//		case 6:
//			  PAout(1)=0;	// ֱ����� ��ת
//				PAout(4)=0;	  // ������� ��ת	 
//			  TIM3->CCER|=1; /*����PWM1 ֱ���������   */
//				TIM2->CCER|=1; //ͨ��1���ʹ��					
//				MyTimer2_Startup(stepfrequency*2,stepfrequency);   //��1000hz��Ƶ�����500������  /*����PWM1*/
//		break;
//		case 7:
//			  PAout(1)=0;	// ֱ����� ��ת
//				PAout(4)=0;	  // ������� ��ת	 
//			  TIM3->CCER|=1; /*����PWM1 ֱ���������   */
//				TIM2->CCER|=1; //ͨ��1���ʹ��					
//				MyTimer2_Startup(stepfrequency*2,stepfrequency);   //��1000hz��Ƶ�����500������  /*����PWM1*/
//		break;
		
		case 8:
			  PAout(1)=0;	// ֱ����� ǰ��
			  TIM3->CCER|=1; /*����PWM1 ֱ���������   */
				TIM2->CCER &= ~1;/*��ֹ����*/						
		break;
//		case 9:
//			  PAout(1)=0;	// ֱ����� ��ת
//				PAout(4)=1;	  // ������� ��ת 
//			  TIM3->CCER|=1; /*����PWM1 ֱ���������   */
//				TIM2->CCER|=1; //ͨ��1���ʹ��					
//				MyTimer2_Startup(stepfrequency*2,stepfrequency);   //��1000hz��Ƶ�����500������  /*����PWM1*/
//		break;
//		
//		case 10:
//			  PAout(1)=0;	// ֱ����� ��ת
//				PAout(4)=1;	  // ������� ��ת 
//			  TIM3->CCER|=1; /*����PWM1 ֱ���������   */
//				TIM2->CCER|=1; //ͨ��1���ʹ��					
//				MyTimer2_Startup(stepfrequency*2,stepfrequency);   //��1000hz��Ƶ�����500������  /*����PWM1*/
//		break;
		case 9:
			  PAout(1)=0;	// ֱ����� ǰ��
				PAout(4)=0;	  // ������� ��ת 
			  TIM3->CCER|=1; /*����PWM1 ֱ���������   */
				TIM2->CCER|=1; //ͨ��1���ʹ��					
				MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //��1000hz��Ƶ�����500������  /*����PWM1*/
		 break;
		case 10:
			  PAout(1)=0;	// ֱ����� ǰ��
				PAout(4)=0;	  // ������� ��ת 
			  TIM3->CCER|=1; /*����PWM1 ֱ���������   */
				TIM2->CCER|=1; //ͨ��1���ʹ��					
				MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //��1000hz��Ƶ�����500������  /*����PWM1*/
		break;
		case 11:
			  PAout(1)=0;	// ֱ����� ǰ��
				PAout(4)=0;	  // ������� ��ת 
			  TIM3->CCER|=1; /*����PWM1 ֱ���������   */
				TIM2->CCER|=1; //ͨ��1���ʹ��					
				MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //��1000hz��Ƶ�����500������  /*����PWM1*/
		break;
		case 12:
			  PAout(1)=0;	// ֱ����� ǰ��
				PAout(4)=0;	  // ������� ��ת 
			  TIM3->CCER|=1; /*����PWM1 ֱ���������   */
				TIM2->CCER|=1; //ͨ��1���ʹ��					
				MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //��1000hz��Ƶ�����500������  /*����PWM1*/
		break;
		case 13:
			  PAout(1)=0;	// ֱ����� ǰ��
				PAout(4)=0;	  // ������� ��ת 
			  TIM3->CCER|=1; /*����PWM1 ֱ���������   */
				TIM2->CCER|=1; //ͨ��1���ʹ��					
				MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //��1000hz��Ƶ�����500������  /*����PWM1*/
		break;
		
//		case 12:
//			  PAout(1)=0;	// ֱ����� ��ת
//				PAout(4)=1;	  // ������� ��ת 
//			  TIM3->CCER|=1; /*����PWM1 ֱ���������   */
//				TIM2->CCER|=1; //ͨ��1���ʹ��					
//				MyTimer2_Startup(stepfrequency*2,stepfrequency);   //��1000hz��Ƶ�����500������  /*����PWM1*/
//		break;
//		
//		case 13:
//			  PAout(1)=0;	// ֱ����� ��ת
//				PAout(4)=1;	  // ������� ��ת 
//			  TIM3->CCER|=1; /*����PWM1 ֱ���������   */
//				TIM2->CCER|=1; //ͨ��1���ʹ��					
//				MyTimer2_Startup(stepfrequency*2,stepfrequency);   //��1000hz��Ƶ�����500������  /*����PWM1*/
//		break;
		default :
			break;
		}
		USART_RX_STA = 0;		  	//������ɱ�־���㣬������һ�ν���
}

void USART2_DATA( u8 keyflag)
{
	switch(keyflag)	//�����Ǹ��������
	{		

		case 104:			 // 1
			PAout(1)=0;	// ֱ����� ǰ��
			PAout(4)=1;	  // ������� ��ת	 
			delay_ms(100); 
			TIM3->CCER|=1; /*����PWM1 ֱ���������   */
			TIM2->CCER|=1; //ͨ��1���ʹ��					
			MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //��1000hz��Ƶ�����500������  /*����PWM1*/
		break;

		case 152:			 //2
			TIM3->CCER &= ~1;/*��ֹPWM1*/
			TIM2->CCER &= ~1;/*��ֹ����*/
		break;

		case 176:		   //3
			PAout(1)=1;	// ֱ����� ����
			delay_ms(100); 
			TIM3->CCER|=1; /*����PWM1 ֱ���������   */
			TIM2->CCER&=0; //��ֹ�������
		break;


		case 48:			 //4
			PAout(1)=0;	// ֱ����� ǰ��
			PAout(4)=1;	  // ������� ��ת	 
			delay_ms(100); 
			TIM3->CCER|=1; /*����PWM1 ֱ���������   */
			TIM2->CCER|=1; //ͨ��1���ʹ��					
			MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //��1000hz��Ƶ�����500������  /*����PWM1*/
		break;

		case 24:			   //5
			PAout(1)=0;	// ֱ����� ǰ��
			PAout(4)=1;	  // ������� ��ת	
			delay_ms(100);  
			TIM3->CCER|=1; /*����PWM1 ֱ���������   */
			TIM2->CCER|=1; //ͨ��1���ʹ��					
			MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //��1000hz��Ƶ�����500������  /*����PWM1*/
		break;
		
		case 122:			   //6
			PAout(1)=0;	// ֱ����� ǰ��
			PAout(4)=1;	  // ������� ��ת	
			delay_ms(100);  
			TIM3->CCER|=1; /*����PWM1 ֱ���������   */
			TIM2->CCER|=1; //ͨ��1���ʹ��					
			MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //��1000hz��Ƶ�����500������  /*����PWM1*/
		break;
		
		case 16:			 //7
			PAout(1)=0;	// ֱ����� ��ת
			PAout(4)=1;	  // ������� ��ת
			delay_ms(100); 	 
			TIM3->CCER|=1; /*����PWM1 ֱ���������   */
			TIM2->CCER|=1; //ͨ��1���ʹ��					
			MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //��1000hz��Ƶ�����500������  /*����PWM1*/
		break;	 		

		case 56:			//8
			PAout(1)=0;	// ֱ����� ǰ��
			delay_ms(100); 
			TIM3->CCER|=1; /*����PWM1 ֱ���������   */
			TIM2->CCER &= ~1;/*��ֹ����*/						
		break;

		case 90:			//
			PAout(1)=0;	// ֱ����� ǰ
			PAout(4)=0;	  // ������� ��ת 
			delay_ms(100); 
			TIM3->CCER|=1; /*����PWM1 ֱ���������   */
			TIM2->CCER|=1; //ͨ��1���ʹ��					
			MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //��1000hz��Ƶ�����500������  /*����PWM1*/
		break;

		default:
		break;
	}
}


// PWM������

//PWM�����ʼ��
//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��
void PWM_Init(u16 arr,u16 psc)
{		 					 
	//�˲������ֶ��޸�IO������
	RCC->APB1ENR|=1<<1;       //TIM3ʱ��ʹ��
	RCC->APB2ENR|=1<<2;    //GPIOAʹ�� 

	GPIOA->CRL&=0XF0F0FF00;//PA0���ó����	  
	GPIOA->CRL|=0X0B03003B;  
	GPIOA->ODR|=1<<6;  
	TIM3->ARR=arr;//�趨�������Զ���װֵ 
   TIM3->CCR1=TIM3->ARR>>1;   //ƥ��ֵ1������װֵһ�룬����ռ�ձ�Ϊ50%
 //	TIM3->CCR1=arr/2;   //ƥ��ֵ1������װֵһ�룬����ռ�ձ�Ϊ50%

	TIM3->PSC=psc;//Ԥ��Ƶ������Ƶ
	
	TIM3->CCMR1|=7<<4;  //CH1 PWM2ģʽ			 
	TIM3->CCMR1|=1<<3; //CH1Ԥװ��ʹ��	  

	TIM3->CCER|=1<<1;   //OC1 OC1�͵�ƽ��Ч	 	

	TIM3->CR1=0x8000;   //ARPEʹ��
	TIM3->CR1|=0x01;    //ʹ�ܶ�ʱ��3 									  
}  	 



// ��ʱ��2��ʼ��
void Timer2_Init(void)	
{
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC->APB1ENR|=1<<0;//TIM2ʱ��ʹ�� 
	TIM2->PSC=72-1;  //���ö�ʱ��2Ԥ��Ƶֵ��ʹ��ʱ���õ�1MHz�ļ���Ƶ��  

 	TIM2->CR1|=1<<2;    //����ֻ�м�����Ų��������ж�
	TIM2->DIER|=1<<0;   //��������ж�				

	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //��ռ���ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //�����ȼ�3��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);  //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���

	TIM2->CCMR1&=~(3<<0);         //CH1ͨ������Ϊ���ģʽ 	
	TIM2->CCMR1|=7<<4;  //CH1 PWM2ģʽ	 
	
}

 void MyTimer2_Startup(u16 num,u16 frequency)
{
	mubiao=num;
	dangqian=0;
	if(frequency<20)  frequency=20;
	TIM2->ARR=1000000/frequency-1;  //�趨��װֵ
	TIM2->CCR1=TIM2->ARR>>1;   //ƥ��ֵ1������װֵһ�룬����ռ�ձ�Ϊ50%
	TIM2->CR1|=1<<0;              //������ʱ��TIMER2����
}

// ��ʱ��2�жϷ������

void TIM2_IRQHandler(void)
{
	
	if(TIM2->SR&0X0010)	 //����ж�
	{
	  	dangqian++;
		if(dangqian==mubiao)
		{
				TIM2->CR1&=~(1<<0);
				TIM2->CCER &= ~1;/*��ֹPWM1*/
				dangqian=mubiao=0;	
		}
		 TIM2->SR&=~(1<<0);//����жϱ�־λ				  					 
	}
	
} 
