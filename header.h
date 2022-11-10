/********************************************************************************
Inneh�ller olika defineringar och deklarationer av funktioner
********************************************************************************/

#ifndef HEADER_H_
#define HEADER_H_

/*Klockfrekvensen som anv�nds vid delayfunktionen*/
#define F_CPU 16000000UL

/*Olika inkluderingsbiblotek*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

/*Definerar lysdioderna och knapparna*/
#define LED1 0					//Led till pin 8	
#define LED2 1					//Led till pin 9
#define LED3 2					//Led till pin 10

#define PREVIOUS1_BUTTON 3		//Knapp till pin 11	
#define NEXT1_BUTTON 4			//Knapp till pin 12
#define NEXT2_BUTTON 5			//Knapp till pin 13

#define PREVIOUS2_BUTTON 3		//Knapp till pin 3
#define RESET_BUTTON 2			//Knapp till pin 2

#define LED1_ON PORTB |= (1 << LED1)	//T�nder led 1
#define LED2_ON PORTB |= (1 << LED2)	//T�nder led 2
#define LED3_ON PORTB |= (1 << LED3)	//T�nder led 3

#define LED1_OFF PORTB &= ~(1 << LED1)	//Sl�cker led 1
#define LED2_OFF PORTB &= ~(1 << LED2)	//Sl�cker led 2
#define LED3_OFF PORTB &= ~(1 << LED3)	//Sl�cker led 3
     
#define LEDS_OFF PORTB &= ~((1 << LED1) | (1 << LED2) | (1 << LED3))	//Sl�cker alla leds
#define LEDS_ON PORTB |= (1 << LED1) | (1 << LED2) | (1 << LED3)		//T�nder alla leds

#define RESET_BUTTON_PRESSED (PIND & (1 << RESET_BUTTON))				//Definerar nedtryckt reset knapp
#define PREVIOUS2_BUTTON_PRESSED (PIND & (1 << PREVIOUS2_BUTTON))		//Definerar nedtryckt f�reg�endeX2 knapp
#define PREVIOUS1_BUTTON_PRESSED (PINB & (1 << PREVIOUS1_BUTTON))		//Definerar nedtryckt f�reg�ende knapp
#define NEXT1_BUTTON_PRESSED (PINB & (1 << NEXT1_BUTTON))				//Definerar nedtryckt n�sta knapp
#define NEXT2_BUTTON_PRESSED (PINB & (1 << NEXT2_BUTTON))				//Definerar nedtryckt n�staX2 knapp

typedef enum { false, true} bool;		//Datatyp bool som definerar sant eller falskt
	
enum led_state {STATE_OFF, STATE_SLOW, STATE_MEDIUM, STATE_FAST, STATE_ON};		//Datatyp f�r lagring av de olika tillst�nden

void setup(void);			//Intierar mikrodatorn
void fsm_reset(void);		//Initierar reset funktion som s�tter alla leds till sl�ckt
void fsm_update(void);		//Initierar update funktionen som uppdaterar tillst�ndet 
void fsm_set_output(void);	//Initierar output funktionen som best�mmer utsignaler beroende p� tillst�ndet

#endif