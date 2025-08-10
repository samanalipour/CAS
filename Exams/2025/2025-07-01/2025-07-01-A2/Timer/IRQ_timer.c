/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_timer.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    timer.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "LPC17xx.h"
#include "../Main.h"
extern uint32_t tick;
extern int nextElementLCG (int x, int a, int c,int n,int m);
#define n 10
int value = 1;
int flag=0; 
extern int sequence;
extern int num_correct;
extern int num_wrong;
void TIMER0_IRQHandler (void)
{
	if(sequence <n){
		flag=1;
			value = nextElementLCG(value,131,7,sequence,255);
			LED_Out(0);
			if((value%4)==0)LED_On(11-11);
			else if((value%4)==1)LED_On(11-10);
			else if((value%4)==2)LED_On(11-9);
			else if((value%4)==3)LED_On(11-8);
	}else{
		LED_Out(0);
		if(num_correct > num_wrong)LED_On(11-4);
		else LED_On(11-5);
	}
	sequence = sequence+1;
	
  LPC_TIM0->IR |= 1;			/* clear interrupt flag */
  return;
}


void TIMER1_IRQHandler (void)
{
  LPC_TIM1->IR = 1;			/* clear interrupt flag */
  return;
}

void TIMER2_IRQHandler (void)
{
  LPC_TIM2->IR = 1;			/* clear interrupt flag */
  return;
}

void TIMER3_IRQHandler (void)
{
	tick++;
  LPC_TIM3->IR = 1;			/* clear interrupt flag */
  return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/
