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
unsigned int i=0;
unsigned int j=0;
extern unsigned int v[1000];
extern unsigned int q_max;
uint16_t SinTable[45] =                                       
{
	 410, 467, 523, 576, 627, 673, 714, 749, 778,
	 799, 813, 819, 817, 807, 789, 764, 732, 694, 
	 650, 602, 550, 495, 438, 381, 324, 270, 217,
	 169, 125, 87 , 55 , 30 , 12 , 2  , 0  , 6  ,   
	 20 , 41 , 70 , 105, 146, 193, 243, 297, 353
};
void TIMER0_IRQHandler (void)
{
	if(LPC_TIM1->TCR & 1){
		LPC_TIM0->IR |= 1;			/* clear interrupt flag */
		return;
	}
	if(LPC_TIM2->TCR & 1){
		LPC_TIM0->IR |= 1;			/* clear interrupt flag */
		return;
	}
	i++;
	
	if(i==1000){
		disable_timer(0);
	}
	float threshold1 = ((5351 - 1062) / q_max) * v[i-1];
	threshold1 = (5351 - threshold1)/5;
	
	float threshold2 = ((40000000 - 625000) / q_max) * v[i-1];
	threshold2 = (40000000 - threshold2)/5;
	
	unsigned int threshold1_cast = (unsigned int)threshold1;
	unsigned int threshold2_cast = (unsigned int)threshold2;
	init_timer_SRI(1,threshold1_cast,0b011);			//stop reset interrupt
	enable_timer(1);
	init_timer_SRI(2,threshold2_cast,0b111);			//stop reset interrupt
	enable_timer(2);
  LPC_TIM0->IR |= 1;			/* clear interrupt flag */
  return;
}


void TIMER1_IRQHandler (void)
{
	DAC_write(SinTable[j]);
	j++;
	if(j==45)j=0;
  LPC_TIM1->IR = 1;			/* clear interrupt flag */
  return;
}

void TIMER2_IRQHandler (void)
{
	disable_timer(1);
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
