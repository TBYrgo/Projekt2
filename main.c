/********************************************************************************
Main: Program i form av tillst�ndsmaskin som blinkar tre leds i olika hastigheter
samt om de alla ska vara p� eller av.
********************************************************************************/

#include "header.h"

/********************************************************************************
S�tter ig�ng programmet och h�ller det ig�ng s� l�nge str�m finns
********************************************************************************/
int main(void)
{
	setup();
	
	while(1)
	{
		fsm_set_output();
	}
	
	return 0;
}