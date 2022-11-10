#include "header.h"

/************************************************************************
Definerar avbrottsrutinerna som anropas när knapp på pin 11 - 13 trycks ned.                                                        
************************************************************************/

ISR (PCINT0_vect)
{
	if (PREVIOUS1_BUTTON_PRESSED || NEXT1_BUTTON_PRESSED || NEXT2_BUTTON_PRESSED) //
	{
		fsm_update();
	}
	
return;

}

/********************************************************************************
Definerar avbrottsrutinen för reset knapp som ligger på pin två 
********************************************************************************/
ISR (INT0_vect)
{
	fsm_reset();
}


/********************************************************************************
Definerar avbrottsrutinen för knapp som ligger på pin tre
********************************************************************************/
ISR(INT1_vect)
{
	if(PREVIOUS2_BUTTON_PRESSED)
	{
		fsm_update();
	}

return;
}