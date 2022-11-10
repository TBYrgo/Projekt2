#include "header.h"

/*Initierar funktionerna för initieringen av portar och interrupts*/
static inline void init_ports(void);
static inline void init_interrupts(void);


/********************************************************************************
Setup funktion för att köra de olika initieringarna
********************************************************************************/
void setup(void)
{
	init_ports();
	init_interrupts();
	fsm_reset();
	return;	
}


/********************************************************************************
Initierar portarna vi kommer att använda
********************************************************************************/
static inline void init_ports(void)
{
	DDRB = (1 << LED1) | (1 << LED2) | (1 << LED3);
	PORTD = (1 << RESET_BUTTON) | (1 << PREVIOUS2_BUTTON);
	PORTB = (1 << NEXT1_BUTTON) | (1 << NEXT2_BUTTON) | (1 << PREVIOUS1_BUTTON);
	return;
}

/********************************************************************************
Initierar avbrottsrutinerna 
********************************************************************************/
static inline void init_interrupts(void)
{
	asm("SEI");
	PCICR = (1 << PCIE0);																//Aktiverar PCIavbrott
	PCMSK0 = (1 << PREVIOUS1_BUTTON) | (1 << NEXT1_BUTTON) | (1 << NEXT2_BUTTON);		//Bestämmer vilka knappar som ska använda avbrottet
	
	EICRA = (1 << ISC10) | (1 << ISC01) | (ISC11);										//Aktiverar Externavbrott på fallande flank på pin 2 och stigande flank på pin 3
	EIMSK = (1 << INT0) | (1 << INT1);													
	return;
}
