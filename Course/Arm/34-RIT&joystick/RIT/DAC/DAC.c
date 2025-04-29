#include "LPC17xx.h"
void DAC_write(uint16_t value){
	LPC_DAC->DACR = value<<6;
}