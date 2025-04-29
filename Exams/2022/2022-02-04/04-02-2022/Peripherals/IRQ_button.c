#include "button.h"
#include "lpc17xx.h"
#include "led.h"

extern unsigned int nonRestoringSquareRoot(unsigned int number, unsigned int digits);
extern unsigned int value = 0;
extern unsigned int count = 0;
extern unsigned int result = 0;

void EINT0_IRQHandler (void)	  
{
	result = nonRestoringSquareRoot(value, count);
	LED_On(result);
	LPC_SC->EXTINT |= (1 << 0);     /* clear pending interrupt         */
}


void EINT1_IRQHandler (void)	  
{
	value = value << 1;
	count++;
	LPC_SC->EXTINT |= (1 << 1);     /* clear pending interrupt         */
}

void EINT2_IRQHandler (void)	  
{
	value = value << 1;
	value = value + 1;
	count++;
	LPC_SC->EXTINT |= (1 << 2);     /* clear pending interrupt         */    
}


