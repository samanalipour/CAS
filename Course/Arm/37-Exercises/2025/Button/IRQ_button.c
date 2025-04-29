#include "../Main.h"
#include "LPC17xx.h"
//#define debounce_time 50
//extern uint32_t tick;
//uint32_t last_tick = 0;
//int state = 1;
extern uint8_t bitwiseAffineTransformation(char *array, int B, int C);
uint32_t MSB;
uint32_t LSB;
uint8_t result;
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
	uint32_t timer_value = read_timer(1);
	MSB = timer_value >> 8;
	LSB = timer_value & 0xFF;
	MSB = MSB ^ LSB;
	LED_Out(MSB);
	LPC_SC->EXTINT &= (1 << 0);     /* clear pending interrupt         */
}


void EINT1_IRQHandler (void)	  
{
	char  array[] = {0x8F, 0xC7, 0xE3, 0xF1, 0xF8, 0x7C, 0x3E, 0x1F};
  result = bitwiseAffineTransformation(array,MSB,0x63);
	init_timer_SRI(0,625000,0b011);	
	enable_timer(0);	
	LPC_SC->EXTINT &= (1 << 1);     /* clear pending interrupt         */
}

void EINT2_IRQHandler (void)	  
{

  LPC_SC->EXTINT &= (1 << 2);     /* clear pending interrupt         */    
}


