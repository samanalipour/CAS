#include "button.h"
#include "led.h"
#include <stdio.h>
#include "LPC17xx.h" 
int main(){
	BUTTON_init();
	LED_init();
	while(1){
		EINT1_IRQHandler();
		EINT2_IRQHandler();
		EINT3_IRQHandler();
		
	}
}