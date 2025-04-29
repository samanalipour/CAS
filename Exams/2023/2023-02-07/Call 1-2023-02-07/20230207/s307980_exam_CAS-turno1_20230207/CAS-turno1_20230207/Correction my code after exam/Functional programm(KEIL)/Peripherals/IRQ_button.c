#include "button.h"
#include "LPC17xx.h"
#include <stdbool.h>						//Edited:Adding stdbool for using bool values in our code
extern insertionSort(int,int);	//Edited:prototype of our ASM function
char array_1[20];								//Edited:Define some variable that we need in our code
char counter=0;
bool flag=true;
void EINT0_IRQHandler (void)	  
{
	if(counter<20)array_1[counter]=(char)LPC_TIM1 ->TC;					//Edited:whenever we press button we have an interrupt and if counter was below 20 we add the value of timer counter reg to array
	if(counter>=20){																						//Edited:if it was above 20 then we turn of led 6 and turn off led 7 and with a flag we switch this situation
		if(flag){
			LED_On(6);
			LED_Off(7);
		}
		if(!flag){
			LED_On(7);
			LED_Off(6);
		}	
	}
	counter++;
	flag=!flag;
	LPC_SC->EXTINT |= (1 << 0);     /* clear pending interrupt         */
}


void EINT1_IRQHandler (void)	  
{
	LED_Off(11);									//Edited: if we press KEY1 then we turn off all leds
	LED_Off(6);
	LED_Off(7);
	insertionSort(&array_1,20);		//Edited:we recall our ASM function and we sort array
	LED_On(11);										//Edited:when we back from subroutine we turn on led 11
	LPC_SC->EXTINT |= (1 << 1);     /* clear pending interrupt         */
	
}

void EINT2_IRQHandler (void)	  
{
	LPC_SC->EXTINT |= (1 << 2);     /* clear pending interrupt         */    
}


