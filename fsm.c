#include "header.h"


static void leds_blink(const volatile uint16_t* blink_speed_ms);
static void delay_ms(const volatile uint16_t* delay_time_ms);

static enum led_state state = STATE_OFF;		//Lagrar dörrens tillståd
static uint16_t speed_ms = 0;					//Blinkhastigheten 


/********************************************************************************
Sätter tillståndet tills startläget, släcker alla lysdioder
********************************************************************************/
void fsm_reset(void)
{
	state = STATE_OFF;
	speed_ms = 0;
	LEDS_OFF;
	return;
}


/********************************************************************************
Uppdaterar tillståndet genom att kolla nuvarande tillstånd och sedan kolla vilken 
knapp som är nedtryckt. 
********************************************************************************/
void fsm_update(void)
{
	switch(state)
	{
		case STATE_OFF:
		{
			if(NEXT1_BUTTON_PRESSED)
			{
				state = STATE_SLOW;
			}
			else if (NEXT2_BUTTON_PRESSED)
			{
				state = STATE_MEDIUM;
			}
			else if (PREVIOUS1_BUTTON_PRESSED)
			{
				state = STATE_ON;
			}
			else if (PREVIOUS2_BUTTON_PRESSED)
			{
				state = STATE_FAST;
			}
			else if (RESET_BUTTON_PRESSED)
			{
				fsm_reset();
			}
		break;
		}
		
		case STATE_SLOW:
		{
			if(NEXT1_BUTTON_PRESSED)
			{
				state = STATE_MEDIUM;
			}
			else if (NEXT2_BUTTON_PRESSED)
			{
				state = STATE_FAST;
			}
			else if (PREVIOUS1_BUTTON_PRESSED)
			{
				state = STATE_OFF;
			}
			else if (PREVIOUS2_BUTTON_PRESSED)
			{
				state = STATE_ON;
			}
			else if (RESET_BUTTON_PRESSED)
			{
				fsm_reset();
			}
			break;
		}
		
		case STATE_MEDIUM:
		{
			if(NEXT1_BUTTON_PRESSED)
			{
				state = STATE_FAST;
			}
			else if (NEXT2_BUTTON_PRESSED)
			{
				state = STATE_ON;
			}
			else if (PREVIOUS1_BUTTON_PRESSED)
			{
				state = STATE_SLOW;
			}
			else if (PREVIOUS2_BUTTON_PRESSED)
			{
				state = STATE_OFF;
			}
			else if (RESET_BUTTON_PRESSED)
			{
				fsm_reset();
			}
			break;
		}
		
		case STATE_FAST:
		{
			if(NEXT1_BUTTON_PRESSED)
			{
				state = STATE_ON;
			}
			else if (NEXT2_BUTTON_PRESSED)
			{
				state = STATE_OFF;
			}
			else if (PREVIOUS1_BUTTON_PRESSED)
			{
				state = STATE_MEDIUM;
			}
			else if (PREVIOUS2_BUTTON_PRESSED)
			{
				state = STATE_SLOW;
			}
			else if (RESET_BUTTON_PRESSED)
			{
				fsm_reset();
			}
			break;
		}
		
		case STATE_ON:
		{
			if(NEXT1_BUTTON_PRESSED)
			{
				state = STATE_OFF;
			}
			else if (NEXT2_BUTTON_PRESSED)
			{
				state = STATE_SLOW;
			}
			else if (PREVIOUS1_BUTTON_PRESSED)
			{
				state = STATE_FAST;
			}
			else if (PREVIOUS2_BUTTON_PRESSED)
			{
				state = STATE_MEDIUM;
			}
			else if (RESET_BUTTON_PRESSED)
			{
				fsm_reset();
			}
			break;
		}
		
		default:
		{
			fsm_reset();
			break;
		}
	}
	
	if (state == STATE_OFF) speed_ms = 0;
	else if (state == STATE_SLOW) speed_ms = 500;
	else if (state == STATE_MEDIUM) speed_ms = 250;
	else if (state == STATE_FAST) speed_ms = 50;
	else if (state == STATE_ON) speed_ms = 0;
	return;
}


/********************************************************************************
Uppdaterar utsignalerna beroende på vilket tillstånd maskinen befinner sig i. 
********************************************************************************/
void fsm_set_output(void)
{
	if (state == STATE_OFF)
	{
		LEDS_OFF;
	}
	else if (state == STATE_SLOW)
	{
		leds_blink(&speed_ms);
	}
	else if (state == STATE_MEDIUM)
	{
		leds_blink(&speed_ms);
	}
	else if(state == STATE_FAST)
	{
		leds_blink(&speed_ms);		
	}
	else if (state == STATE_ON)
	{
		LEDS_ON;
	}
	else
	{
		fsm_reset();
	}
	return;
}

/********************************************************************************
Bestämmer att lysdioderna ska blinka i en slinga med olika fördröjningshastigheter 
beroende vilket tillstånd maskinen befinner sig i. 
********************************************************************************/
static void leds_blink(const volatile uint16_t* blink_speed_ms)
{
	LEDS_OFF;
	LED1_ON;
	delay_ms(blink_speed_ms);

	LED1_OFF;
	LED2_ON;
	delay_ms(blink_speed_ms);

	LED2_OFF;
	LED3_ON;
	delay_ms(blink_speed_ms);

	LED3_OFF;
	return;
}

/********************************************************************************
Funktion som skapar fördröjningen som använder sig av pekare för att kunna uppdateras direkt. 
********************************************************************************/
static void delay_ms(const volatile uint16_t* delay_time_ms)
{
	for(uint16_t i = 0; i < *delay_time_ms; i++)
	{
		_delay_ms(1);
	}
	return;
}