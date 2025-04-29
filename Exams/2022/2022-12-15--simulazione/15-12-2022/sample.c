#include "led.h"
extern addFPpositiveNumbers(int , int);
int main(){
	LED_init();
	int a = 0b01000010010010110000000000000000;
	int b = 0b01000001101001000000000000000000;
	float result = addFPpositiveNumbers(a,b);
	if(result > 3.1415){
		LED_Off (1);
		LED_Off (2);
		LED_Off (3);
		LED_Off (5);
		LED_On(4);
		
		
		
	}else{
		LED_On(4);
		LED_Off (1);
		LED_Off (2);
		LED_Off (3);
		LED_Off (4);
		
	}
	
	while(1);
}