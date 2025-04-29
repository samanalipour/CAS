#include "../Main.h"
#include "LPC17xx.h"
//#define debounce_time 50
//extern uint32_t tick;
//uint32_t last_tick = 0;
//int state = 1;
const int MAX_VALUES = 10;
//#define MAX_VALUES 10
char Array[MAX_VALUES];
int index=0;
int led=0;
extern void insertionSort( char *array, int num);
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
	if(index<MAX_VALUES){
			uint32_t timer_value = read_timer(1);
			Array[index] = timer_value;
			index++;	
			if(led==0){
				LED_On(4);
				LED_Off(5);
				led = 1;
			}else{
				LED_On(5);
				LED_Off(4);
				led = 0;				
			}
	}

	
	
	LPC_SC->EXTINT &= (1 << 0);     /* clear pending interrupt         */
}


void EINT1_IRQHandler (void)	  
{
	LED_Off(4);
	LED_Off(5);
	insertionSort(Array,MAX_VALUES);
	LED_On(0);
	LPC_SC->EXTINT &= (1 << 1);     /* clear pending interrupt         */
}

void EINT2_IRQHandler (void)	  
{

  LPC_SC->EXTINT &= (1 << 2);     /* clear pending interrupt         */    
}


