#ifndef __NC_H
#define __NC_H

#include "sys.h"
#include "stdio.h"


void PWM_Init(u16 arr,u16 psc);
void Timer2_Init(void);
void MyTimer2_Startup(u16 num,u16 frequency);
void USART1_DATA(void);
void USART2_DATA( u8 keyflag);


#endif
