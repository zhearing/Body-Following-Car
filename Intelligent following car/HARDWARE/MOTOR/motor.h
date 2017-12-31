#ifndef __MOTOR_H
#define __MOTOR_H

#include "sys.h"
#include "stdio.h"

int Limit_Space(void);
void PWM_Init(u16 arr,u16 psc);

void Timer2_Init(void);
void MyTimer2_Startup(u16 num,u16 frequency);

void USART1_DATA(void);
void USART2_DATA(u8 keyflag);

#endif

