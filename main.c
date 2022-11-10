/********************************************************************************
Main: Program i form av tillståndsmaskin som blinkar tre leds i olika hastigheter
samt om de alla ska vara på eller av.
********************************************************************************/

#include "header.h"

/********************************************************************************
Sätter igång programmet och håller det igång så länge ström finns
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