#include "../Main.h"
#include "LPC17xx.h"
//#define debounce_time 50
//extern uint32_t tick;
//uint32_t last_tick = 0;
//int state = 1;
int	value = 0;
int cnt=0;
extern int nonRestoringSquareRoot(int x, int k);
void EINT0_IRQHandler (void)	  
{
//	if(tick<debounce_time && state==1){
//		test++;
//		state=0;
//		last_tick = tick;
//		LPC_SC->EXTINT &= (1 << 0); /* clear pending interrupt         */
//		return;
//	}
//	if ((tick - last_tick) < debounce_time) {	
//        LPC_SC->EXTINT &= (1 << 0); /* clear pending interrupt         */
//        return;
//	}
//	last_tick = tick;
//	state=1;
//  write code from here with or without debouncing
	
	int result = nonRestoringSquareRoot(value,cnt);
	result = result & 0xFF;
	LED_Out(result);
	LPC_SC->EXTINT &= (1 << 0);     /* clear pending interrupt         */
}


void EINT1_IRQHandler (void)	  
{
	value = value << 1; 
	cnt++;
	LPC_SC->EXTINT &= (1 << 1);     /* clear pending interrupt         */
}

void EINT2_IRQHandler (void)	  
{
	cnt++;
	value = value << 1; 
	value = value | 1;	
  LPC_SC->EXTINT &= (1 << 2);     /* clear pending interrupt         */    
}


