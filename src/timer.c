#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 1000000UL
#include <util/delay.h>

#include "initialize.h"
#include "display.h"
#include "LCD.h"
#include "timer.h"
#include "hardware.h"

void init_timer()
{
	TCCR1A= 0x00;
	TCCR1B= 0b00001010;	// Prescalin 8,

	TCNT1H= 0x00;
	TCNT1L= 0x00;

	OCR1AH= 0x7A;
	OCR1AL= 0x12;	// .25 sec

	TIMSK= 0x10;
}

ISR(TIMER1_COMPA_vect)
{
	rpm= count*60/(0.25*2);	
	count=0;
}

ISR(INT1_vect)
{
	count++;
}
