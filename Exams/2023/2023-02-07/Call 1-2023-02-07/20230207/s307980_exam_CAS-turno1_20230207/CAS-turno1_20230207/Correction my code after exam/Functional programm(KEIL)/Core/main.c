#include <stdio.h>
#include "LPC17xx.h"
#include "button.h"
#include "led.h"
#include "timer.h"
int main(){
	LED_init();	
	BUTTON_init();	
	init_timer(1,0XFF); //Edited:initial timer one with value 0xFF 
	enable_timer(1);		//Edited:enabling timer
	while(1);
}