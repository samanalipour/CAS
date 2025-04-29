#include "button.h"
#include "lpc17xx.h"

/**
 * @brief  Function that initializes buttons
 */
void BUTTON_init(void) {

  LPC_PINCON->PINSEL4    |= (1 << 20);     /* External interrupt 0 pin selection */
  LPC_PINCON->PINSEL4    |= (1 << 22);     /* External interrupt 1 pin selection */
  LPC_PINCON->PINSEL4    |= (1 << 24);     /* External interrupt 2 pin selection */

  LPC_SC->EXTMODE = 0x7;

  NVIC_EnableIRQ(EINT2_IRQn);              /* enable irq in NVIC                 */
  /* NVIC_SetPriority(EINT2_IRQn, 1); */
  NVIC_EnableIRQ(EINT1_IRQn);              /* enable irq in NVIC                 */
  /* NVIC_SetPriority(EINT1_IRQn, 2); */
  NVIC_EnableIRQ(EINT0_IRQn);              /* enable irq in NVIC                 */
  /* NVIC_SetPriority(EINT0_IRQn, 3); */
}
