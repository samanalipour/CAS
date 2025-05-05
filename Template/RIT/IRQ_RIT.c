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
		if((LPC_GPIO1->FIOPIN & (1<<25)) == 0){			//sel
		}	
		if((LPC_GPIO1->FIOPIN & (1<<26)) == 0){			//down
		}
		if((LPC_GPIO1->FIOPIN & (1<<27)) == 0){			//left
		}
		if((LPC_GPIO1->FIOPIN & (1<<28)) == 0){			//right
		}
		if((LPC_GPIO1->FIOPIN & (1<<29)) == 0){			//up
		}
  LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
	
}

/******************************************************************************
**                            End Of File
******************************************************************************/
