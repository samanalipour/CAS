#include "button.h"
#include "lpc17xx.h"
#define NUM_ROWS 		 10
#define NUM_COLUMNS  8
char matrix [NUM_ROWS * NUM_COLUMNS];
int Timer_value;
extern int mazeSolver(int,int,int);
void EINT0_IRQHandler (void)	  
{
	Timer_value = LPC_TIM0 -> TC;
	matrix[0] = '*';
	matrix[NUM_COLUMNS-1] = '*';
	matrix[(NUM_COLUMNS*NUM_ROWS) - NUM_COLUMNS] = '*';
	matrix[(NUM_COLUMNS*NUM_ROWS)-1] = '*';	
	
	for(int i=0;i<(NUM_ROWS*NUM_COLUMNS)-1;i++){
		Timer_value = (Timer_value * 18) % 101;
		if(Timer_value<60)matrix[i]=' ';
		if(Timer_value>=60)matrix[i]='*';
	}
	
	for(i=0;i<NUM_COLUMNS-1;i++){
		Timer_value = (Timer_value * 18) % 101;
		if(Timer_value<90)matrix[i]='*';
		if(Timer_value>=90)matrix[i]='n';
	}
	
	for(i=NUM_COLUMNS;i<=(NUM_ROWS-1)*NUM_COLUMNS;i+=NUM_COLUMNS){
		Timer_value = (Timer_value * 18) % 101;
		if(Timer_value<90)matrix[i]='*';
		if(Timer_value>=90)matrix[i]='w';		
	}
		
	for(i=((NUM_COLUMNS-1)+NUM_COLUMNS);i<=(NUM_ROWS*NUM_COLUMNS)-1;i+=NUM_COLUMNS){
		Timer_value = (Timer_value * 18) % 101;
		if(Timer_value<90)matrix[i]='*';
		if(Timer_value>=90)matrix[i]='e';		
	} //right border
	
	for(i=(NUM_ROWS-1)*NUM_COLUMNS;i<=(NUM_ROWS*NUM_COLUMNS)-1;i+=NUM_COLUMNS){
		Timer_value = (Timer_value * 18) % 101;
		if(Timer_value<90)matrix[i]='*';
		if(Timer_value>=90)matrix[i]='s';		
	}//bottom border	
	
	int result = mazeSolver(NUM_ROWS, NUM_COLUMNS, matrix); 
	
	
	
	LPC_SC->EXTINT |= (1 << 0);     /* clear pending interrupt         */
}


void EINT1_IRQHandler (void)	  
{
	LPC_SC->EXTINT |= (1 << 1);     /* clear pending interrupt         */
}

void EINT2_IRQHandler (void)	  
{
	LPC_SC->EXTINT |= (1 << 2);     /* clear pending interrupt         */    
}


