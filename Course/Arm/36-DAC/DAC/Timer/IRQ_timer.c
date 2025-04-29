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
 uint16_t SinTable[45] =                                       
 {
     410, 467, 523, 576, 627, 673, 714, 749, 778,
     799, 813, 819, 817, 807, 789, 764, 732, 694, 
     650, 602, 550, 495, 438, 381, 324, 270, 217,
     169, 125, 87 , 55 , 30 , 12 , 2  , 0  , 6  ,   
     20 , 41 , 70 , 105, 146, 193, 243, 297, 353
 };
 int index=0;
void TIMER0_IRQHandler (void)
{
	DAC_write(SinTable[index]);
	index++;
	if(index>45){
		index=0;
	}
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
