/********************************************************************************
Innehåller olika defineringar och deklarationer av funktioner
********************************************************************************/

#ifndef HEADER_H_
#define HEADER_H_

/*Klockfrekvensen som används vid delayfunktionen*/
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

#define LED1_ON PORTB |= (1 << LED1)	//Tänder led 1
#define LED2_ON PORTB |= (1 << LED2)	//Tänder led 2
#define LED3_ON PORTB |= (1 << LED3)	//Tänder led 3

#define LED1_OFF PORTB &= ~(1 << LED1)	//Släcker led 1
#define LED2_OFF PORTB &= ~(1 << LED2)	//Släcker led 2
#define LED3_OFF PORTB &= ~(1 << LED3)	//Släcker led 3
     
#define LEDS_OFF PORTB &= ~((1 << LED1) | (1 << LED2) | (1 << LED3))	//Släcker alla leds
#define LEDS_ON PORTB |= (1 << LED1) | (1 << LED2) | (1 << LED3)		//Tänder alla leds

#define RESET_BUTTON_PRESSED (PIND & (1 << RESET_BUTTON))				//Definerar nedtryckt reset knapp
#define PREVIOUS2_BUTTON_PRESSED (PIND & (1 << PREVIOUS2_BUTTON))		//Definerar nedtryckt föregåendeX2 knapp
#define PREVIOUS1_BUTTON_PRESSED (PINB & (1 << PREVIOUS1_BUTTON))		//Definerar nedtryckt föregående knapp
#define NEXT1_BUTTON_PRESSED (PINB & (1 << NEXT1_BUTTON))				//Definerar nedtryckt nästa knapp
#define NEXT2_BUTTON_PRESSED (PINB & (1 << NEXT2_BUTTON))				//Definerar nedtryckt nästaX2 knapp

typedef enum { false, true} bool;		//Datatyp bool som definerar sant eller falskt
	
enum led_state {STATE_OFF, STATE_SLOW, STATE_MEDIUM, STATE_FAST, STATE_ON};		//Datatyp för lagring av de olika tillstånden

void setup(void);			//Intierar mikrodatorn
void fsm_reset(void);		//Initierar reset funktion som sätter alla leds till släckt
void fsm_update(void);		//Initierar update funktionen som uppdaterar tillståndet 
void fsm_set_output(void);	//Initierar output funktionen som bestämmer utsignaler beroende på tillståndet

#endif