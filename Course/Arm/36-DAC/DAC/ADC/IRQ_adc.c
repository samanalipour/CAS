/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_adc.c
** Last modified Date:  20184-12-30
** Last Version:        V1.00
** Descriptions:        functions to manage A/D interrupts
** Correlated files:    adc.h
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/

#include "LPC17xx.h"
#include "../Main.h"

/*----------------------------------------------------------------------------
  A/D IRQ: Executed when A/D Conversion is ready (signal from ADC peripheral)
 *----------------------------------------------------------------------------*/
const int freqs[8]={4240,3779,3367,3175,2834,2525,2249,2120};
unsigned short AD_current;   

void ADC_IRQHandler(void) {
  	
  AD_current = ((LPC_ADC->ADGDR>>4) & 0xFFF);/* Read Conversion Result  0-4095           */
	int value = AD_current*7;
	value = value/4095;
	disable_timer(0);
	init_timer_SRI(0,freqs[value]/0xFFF,0b011);			//stop reset interrupt
	reset_timer(0);
	enable_timer(0);
}
