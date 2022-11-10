#include "header.h"

/************************************************************************
Definerar avbrottsrutinerna som anropas n�r knapp p� pin 11 - 13 trycks ned.                                                        
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
Definerar avbrottsrutinen f�r reset knapp som ligger p� pin tv� 
********************************************************************************/
ISR (INT0_vect)
{
	fsm_reset();
}


/********************************************************************************
Definerar avbrottsrutinen f�r knapp som ligger p� pin tre
********************************************************************************/
ISR(INT1_vect)
{
	if(PREVIOUS2_BUTTON_PRESSED)
	{
		fsm_update();
	}

return;
}