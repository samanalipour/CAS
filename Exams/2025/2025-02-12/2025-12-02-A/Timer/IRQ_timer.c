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
int sineValues[45];
extern int Maclaurin(int y, int n);
void TIMER0_IRQHandler (void)
{
	static int repeat = 0;
	static int ticks = 0;
	int input, output;
	if (repeat < 200)
		{
			float tmp = 1.428 * ticks;
			if(tmp > 0)tmp+=0.5;
			if(tmp < 0)tmp-=0.5;
			input = (int)tmp;
			// see Note 1 below
			output = 500 + Maclaurin(input, 3) / 2;
			sineValues[ticks + 22] = output;
			// see Note 2 below
			//write output to proper bits of D/A converter register
			DAC_write(output);
			ticks ++;
			if (ticks > 22)
			{
				ticks = -22;
				repeat += 1;
			}
		}
	else
		DAC_write(0);
	//write zero to proper bits of D/A converter register
	
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
