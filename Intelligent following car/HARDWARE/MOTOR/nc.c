#include "nc.h"
#include "sys.h"
#include "delay.h"
#include "usart.h"

//PA6为PWM输出 ，控制直流电机
//PA0为PWM输出 ，控制步进电机
//PA2为方向 ，控制步进电机转向
//串口数据格式  1 直流电机运行 左转，步进电机左转1s	 （1-15）

u16 stepfrequency=1000; 
u16 mubiao=0;
u16 dangqian=0;

void USART1_DATA(void)
{
	switch(USART_RX_BUF[1]-'a'+1)	//控制那个电机动作
	{
		

   case 1:
			  PAout(1)=0;	// 直流前进
				PAout(4)=1;	  // 步进电机 左转	
				delay_ms(100); 
			  TIM3->CCER|=1; /*启动PWM1 直流电机运行   */
				TIM2->CCER|=1; //通道1输出使能					
				MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //以1000hz的频率输出500个脉冲  /*启动PWM1*/
		break;
		case 2:
				TIM3->CCER &= ~1;/*禁止PWM1*/
				TIM2->CCER &= ~1;/*禁止步进*/
			break;
			
		case 3:
			  PAout(1)=1;	// 直流电机 后退
			  delay_ms(100);
        TIM3->CCER|=1; /*启动PWM1 直流电机运行   */
				TIM2->CCER&=0; //禁止步进电机
				break;
			
		
		case 4:
			  PAout(1)=0;	// 直流电机 前进
				PAout(4)=1;	  // 步进电机 左转	 
			  TIM3->CCER|=1; /*启动PWM1 直流电机运行   */
				TIM2->CCER|=1; //通道1输出使能					
				MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //以1000hz的频率输出500个脉冲  /*启动PWM1*/
		break;
		
		case 5:
			  PAout(1)=0;	// 直流电机 前进
				PAout(4)=1;	  // 步进电机 左转	 
			  TIM3->CCER|=1; /*启动PWM1 直流电机运行   */
				TIM2->CCER|=1; //通道1输出使能					
				MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //以1000hz的频率输出500个脉冲  /*启动PWM1*/
		break;
		case 6:
			  PAout(1)=0;	// 直流电机 前进
				PAout(4)=1;	  // 步进电机 左转	 
			  TIM3->CCER|=1; /*启动PWM1 直流电机运行   */
				TIM2->CCER|=1; //通道1输出使能					
				MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //以1000hz的频率输出500个脉冲  /*启动PWM1*/
		break;
		case 7:
			  PAout(1)=0;	// 直流电机 前进
				PAout(4)=1;	  // 步进电机 左转	 
			  TIM3->CCER|=1; /*启动PWM1 直流电机运行   */
				TIM2->CCER|=1; //通道1输出使能					
				MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //以1000hz的频率输出500个脉冲  /*启动PWM1*/
		break;
		
//		case 6:
//			  PAout(1)=0;	// 直流电机 左转
//				PAout(4)=0;	  // 步进电机 左转	 
//			  TIM3->CCER|=1; /*启动PWM1 直流电机运行   */
//				TIM2->CCER|=1; //通道1输出使能					
//				MyTimer2_Startup(stepfrequency*2,stepfrequency);   //以1000hz的频率输出500个脉冲  /*启动PWM1*/
//		break;
//		case 7:
//			  PAout(1)=0;	// 直流电机 左转
//				PAout(4)=0;	  // 步进电机 左转	 
//			  TIM3->CCER|=1; /*启动PWM1 直流电机运行   */
//				TIM2->CCER|=1; //通道1输出使能					
//				MyTimer2_Startup(stepfrequency*2,stepfrequency);   //以1000hz的频率输出500个脉冲  /*启动PWM1*/
//		break;
		
		case 8:
			  PAout(1)=0;	// 直流电机 前进
			  TIM3->CCER|=1; /*启动PWM1 直流电机运行   */
				TIM2->CCER &= ~1;/*禁止步进*/						
		break;
//		case 9:
//			  PAout(1)=0;	// 直流电机 左转
//				PAout(4)=1;	  // 步进电机 右转 
//			  TIM3->CCER|=1; /*启动PWM1 直流电机运行   */
//				TIM2->CCER|=1; //通道1输出使能					
//				MyTimer2_Startup(stepfrequency*2,stepfrequency);   //以1000hz的频率输出500个脉冲  /*启动PWM1*/
//		break;
//		
//		case 10:
//			  PAout(1)=0;	// 直流电机 左转
//				PAout(4)=1;	  // 步进电机 右转 
//			  TIM3->CCER|=1; /*启动PWM1 直流电机运行   */
//				TIM2->CCER|=1; //通道1输出使能					
//				MyTimer2_Startup(stepfrequency*2,stepfrequency);   //以1000hz的频率输出500个脉冲  /*启动PWM1*/
//		break;
		case 9:
			  PAout(1)=0;	// 直流电机 前进
				PAout(4)=0;	  // 步进电机 右转 
			  TIM3->CCER|=1; /*启动PWM1 直流电机运行   */
				TIM2->CCER|=1; //通道1输出使能					
				MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //以1000hz的频率输出500个脉冲  /*启动PWM1*/
		 break;
		case 10:
			  PAout(1)=0;	// 直流电机 前进
				PAout(4)=0;	  // 步进电机 右转 
			  TIM3->CCER|=1; /*启动PWM1 直流电机运行   */
				TIM2->CCER|=1; //通道1输出使能					
				MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //以1000hz的频率输出500个脉冲  /*启动PWM1*/
		break;
		case 11:
			  PAout(1)=0;	// 直流电机 前进
				PAout(4)=0;	  // 步进电机 右转 
			  TIM3->CCER|=1; /*启动PWM1 直流电机运行   */
				TIM2->CCER|=1; //通道1输出使能					
				MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //以1000hz的频率输出500个脉冲  /*启动PWM1*/
		break;
		case 12:
			  PAout(1)=0;	// 直流电机 前进
				PAout(4)=0;	  // 步进电机 右转 
			  TIM3->CCER|=1; /*启动PWM1 直流电机运行   */
				TIM2->CCER|=1; //通道1输出使能					
				MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //以1000hz的频率输出500个脉冲  /*启动PWM1*/
		break;
		case 13:
			  PAout(1)=0;	// 直流电机 前进
				PAout(4)=0;	  // 步进电机 右转 
			  TIM3->CCER|=1; /*启动PWM1 直流电机运行   */
				TIM2->CCER|=1; //通道1输出使能					
				MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //以1000hz的频率输出500个脉冲  /*启动PWM1*/
		break;
		
//		case 12:
//			  PAout(1)=0;	// 直流电机 左转
//				PAout(4)=1;	  // 步进电机 右转 
//			  TIM3->CCER|=1; /*启动PWM1 直流电机运行   */
//				TIM2->CCER|=1; //通道1输出使能					
//				MyTimer2_Startup(stepfrequency*2,stepfrequency);   //以1000hz的频率输出500个脉冲  /*启动PWM1*/
//		break;
//		
//		case 13:
//			  PAout(1)=0;	// 直流电机 左转
//				PAout(4)=1;	  // 步进电机 右转 
//			  TIM3->CCER|=1; /*启动PWM1 直流电机运行   */
//				TIM2->CCER|=1; //通道1输出使能					
//				MyTimer2_Startup(stepfrequency*2,stepfrequency);   //以1000hz的频率输出500个脉冲  /*启动PWM1*/
//		break;
		default :
			break;
		}
		USART_RX_STA = 0;		  	//接受完成标志清零，启动下一次接受
}

void USART2_DATA( u8 keyflag)
{
	switch(keyflag)	//控制那个电机动作
	{		

		case 104:			 // 1
			PAout(1)=0;	// 直流电机 前进
			PAout(4)=1;	  // 步进电机 左转	 
			delay_ms(100); 
			TIM3->CCER|=1; /*启动PWM1 直流电机运行   */
			TIM2->CCER|=1; //通道1输出使能					
			MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //以1000hz的频率输出500个脉冲  /*启动PWM1*/
		break;

		case 152:			 //2
			TIM3->CCER &= ~1;/*禁止PWM1*/
			TIM2->CCER &= ~1;/*禁止步进*/
		break;

		case 176:		   //3
			PAout(1)=1;	// 直流电机 后退
			delay_ms(100); 
			TIM3->CCER|=1; /*启动PWM1 直流电机运行   */
			TIM2->CCER&=0; //禁止步进电机
		break;


		case 48:			 //4
			PAout(1)=0;	// 直流电机 前进
			PAout(4)=1;	  // 步进电机 左转	 
			delay_ms(100); 
			TIM3->CCER|=1; /*启动PWM1 直流电机运行   */
			TIM2->CCER|=1; //通道1输出使能					
			MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //以1000hz的频率输出500个脉冲  /*启动PWM1*/
		break;

		case 24:			   //5
			PAout(1)=0;	// 直流电机 前进
			PAout(4)=1;	  // 步进电机 左转	
			delay_ms(100);  
			TIM3->CCER|=1; /*启动PWM1 直流电机运行   */
			TIM2->CCER|=1; //通道1输出使能					
			MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //以1000hz的频率输出500个脉冲  /*启动PWM1*/
		break;
		
		case 122:			   //6
			PAout(1)=0;	// 直流电机 前进
			PAout(4)=1;	  // 步进电机 左转	
			delay_ms(100);  
			TIM3->CCER|=1; /*启动PWM1 直流电机运行   */
			TIM2->CCER|=1; //通道1输出使能					
			MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //以1000hz的频率输出500个脉冲  /*启动PWM1*/
		break;
		
		case 16:			 //7
			PAout(1)=0;	// 直流电机 左转
			PAout(4)=1;	  // 步进电机 左转
			delay_ms(100); 	 
			TIM3->CCER|=1; /*启动PWM1 直流电机运行   */
			TIM2->CCER|=1; //通道1输出使能					
			MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //以1000hz的频率输出500个脉冲  /*启动PWM1*/
		break;	 		

		case 56:			//8
			PAout(1)=0;	// 直流电机 前进
			delay_ms(100); 
			TIM3->CCER|=1; /*启动PWM1 直流电机运行   */
			TIM2->CCER &= ~1;/*禁止步进*/						
		break;

		case 90:			//
			PAout(1)=0;	// 直流电机 前
			PAout(4)=0;	  // 步进电机 右转 
			delay_ms(100); 
			TIM3->CCER|=1; /*启动PWM1 直流电机运行   */
			TIM2->CCER|=1; //通道1输出使能					
			MyTimer2_Startup(stepfrequency*0.5,stepfrequency);   //以1000hz的频率输出500个脉冲  /*启动PWM1*/
		break;

		default:
		break;
	}
}


// PWM波部分

//PWM输出初始化
//arr：自动重装值
//psc：时钟预分频数
void PWM_Init(u16 arr,u16 psc)
{		 					 
	//此部分需手动修改IO口设置
	RCC->APB1ENR|=1<<1;       //TIM3时钟使能
	RCC->APB2ENR|=1<<2;    //GPIOA使能 

	GPIOA->CRL&=0XF0F0FF00;//PA0设置成输出	  
	GPIOA->CRL|=0X0B03003B;  
	GPIOA->ODR|=1<<6;  
	TIM3->ARR=arr;//设定计数器自动重装值 
   TIM3->CCR1=TIM3->ARR>>1;   //匹配值1等于重装值一半，是以占空比为50%
 //	TIM3->CCR1=arr/2;   //匹配值1等于重装值一半，是以占空比为50%

	TIM3->PSC=psc;//预分频器不分频
	
	TIM3->CCMR1|=7<<4;  //CH1 PWM2模式			 
	TIM3->CCMR1|=1<<3; //CH1预装载使能	  

	TIM3->CCER|=1<<1;   //OC1 OC1低电平有效	 	

	TIM3->CR1=0x8000;   //ARPE使能
	TIM3->CR1|=0x01;    //使能定时器3 									  
}  	 



// 定时器2初始化
void Timer2_Init(void)	
{
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC->APB1ENR|=1<<0;//TIM2时钟使能 
	TIM2->PSC=72-1;  //设置定时器2预分频值，使定时器得到1MHz的计数频率  

 	TIM2->CR1|=1<<2;    //设置只有计数溢才产生更新中断
	TIM2->DIER|=1<<0;   //允许更新中断				

	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //先占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //从优先级3级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器

	TIM2->CCMR1&=~(3<<0);         //CH1通道配置为输出模式 	
	TIM2->CCMR1|=7<<4;  //CH1 PWM2模式	 
	
}

 void MyTimer2_Startup(u16 num,u16 frequency)
{
	mubiao=num;
	dangqian=0;
	if(frequency<20)  frequency=20;
	TIM2->ARR=1000000/frequency-1;  //设定重装值
	TIM2->CCR1=TIM2->ARR>>1;   //匹配值1等于重装值一半，是以占空比为50%
	TIM2->CR1|=1<<0;              //启动定时器TIMER2计数
}

// 定时器2中断服务程序

void TIM2_IRQHandler(void)
{
	
	if(TIM2->SR&0X0010)	 //溢出中断
	{
	  	dangqian++;
		if(dangqian==mubiao)
		{
				TIM2->CR1&=~(1<<0);
				TIM2->CCER &= ~1;/*禁止PWM1*/
				dangqian=mubiao=0;	
		}
		 TIM2->SR&=~(1<<0);//清除中断标志位				  					 
	}
	
} 
