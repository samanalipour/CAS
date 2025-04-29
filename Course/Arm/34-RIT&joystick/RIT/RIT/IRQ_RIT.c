/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_RIT.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    RIT.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "LPC17xx.h"
#include "RIT.h"
#include "../Main.h"
/******************************************************************************
** Function name:		RIT_IRQHandler
**
** Descriptions:		REPETITIVE INTERRUPT TIMER handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/

void RIT_IRQHandler (void)
{				
		if((LPC_GPIO1->FIOPIN & (1<<26)) == 0){			//down
			LED_Off(0);
		}
		if((LPC_GPIO1->FIOPIN & (1<<27)) == 0){			//left
			LED_On(1);
		}
		if((LPC_GPIO1->FIOPIN & (1<<28)) == 0){			//right
			LED_Off(1);
		}
		if((LPC_GPIO1->FIOPIN & (1<<29)) == 0){			//up
			LED_On(0);
		}
  LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
	
}

/******************************************************************************
**                            End Of File
******************************************************************************/
