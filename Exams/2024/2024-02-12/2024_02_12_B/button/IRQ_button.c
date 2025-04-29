#include "button.h"
#include "lpc17xx.h"
#define 	NUM_ROWS			8
#define 	NUM_COLUMNS 	9
char maze[NUM_ROWS*NUM_COLUMNS];
char path[NUM_ROWS*NUM_COLUMNS];
extern exploreMaze(int,int,int,int);
				
void EINT0_IRQHandler (void)	  
{
	LPC_SC->EXTINT |= (1 << 0);     /* clear pending interrupt         */
}


void EINT1_IRQHandler (void)	  
{
	int i;
	int Timer_value=LPC_TIM0 -> TC;
	
	for(i=0;i<(NUM_ROWS*NUM_COLUMNS)-1;i++){
		Timer_value = (Timer_value * 11 + 6) % 73;
		if(Timer_value<41)maze[i]=' ';
		if(Timer_value>40)maze[i]='X';
	}
	
	
	
	for(i=0;i<NUM_COLUMNS-1;i++)maze[i]='X';	//top border
	
	for(i=NUM_COLUMNS;i<=(NUM_ROWS-1)*NUM_COLUMNS;i+=NUM_COLUMNS)maze[i]='X';//left border
		
	for(i=((NUM_COLUMNS-1)+NUM_COLUMNS);i<=(NUM_ROWS*NUM_COLUMNS)-1;i+=NUM_COLUMNS)maze[i]='X'; //right border
	
	for(i=(NUM_ROWS-1)*NUM_COLUMNS;i<=(NUM_ROWS*NUM_COLUMNS)-1;i+=NUM_COLUMNS)maze[i]='X';//bottom border
	
	i=NUM_COLUMNS+1;
	maze[i] = ' ';
	i=(NUM_ROWS*NUM_COLUMNS)-1;
	i-=NUM_COLUMNS;
	i-=1;
	maze[i] = ' ';
	exploreMaze(NUM_ROWS,NUM_COLUMNS,maze,path);
	LPC_SC->EXTINT |= (1 << 1);     /* clear pending interrupt         */
}

void EINT2_IRQHandler (void)	  
{
	LPC_SC->EXTINT |= (1 << 2);     /* clear pending interrupt         */    
}


