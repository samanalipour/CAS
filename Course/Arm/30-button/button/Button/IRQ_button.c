#include "../Main.h"
#include "LPC17xx.h"
#define debounce_time 50
extern uint32_t tick;
uint32_t last_tick = 0;
int state = 1;

uint32_t last_tick1 = 0;
int state1 = 1;

int counter1=0;
void EINT0_IRQHandler (void)	  
{
	if(tick<debounce_time && state==1){
		//  write code from here with or without debouncing
		counter1++;
		LED_Out(counter1);
		state=0;
		last_tick = tick;
		LPC_SC->EXTINT &= (1 << 0); /* clear pending interrupt         */
		return;
	}
	if ((tick - last_tick) < debounce_time) {	
        LPC_SC->EXTINT &= (1 << 0); /* clear pending interrupt         */
        return;
	}
	last_tick = tick;
	state=1;
//  write code from here with or without debouncing
	counter1++;
	LED_Out(counter1);
	LPC_SC->EXTINT &= (1 << 0);     /* clear pending interrupt         */
}


void EINT1_IRQHandler (void)	  
{
	
	if(tick<debounce_time && state1==1){
		//  write code from here with or without debouncing
		counter1--;
		LED_Out(counter1);
		state1=0;
		last_tick1 = tick;
		LPC_SC->EXTINT &= (1 << 1); /* clear pending interrupt         */
		return;
	}
	if ((tick - last_tick1) < debounce_time) {	
        LPC_SC->EXTINT &= (1 << 1); /* clear pending interrupt         */
        return;
	}
	last_tick1 = tick;
	state=1;
//  write code from here with or without debouncing
	
	
	counter1--;
	LED_Out(counter1);
	LPC_SC->EXTINT &= (1 << 1);     /* clear pending interrupt         */
}

void EINT2_IRQHandler (void)	  
{
	LED_Out(0);
  LPC_SC->EXTINT &= (1 << 2);     /* clear pending interrupt         */    
}


