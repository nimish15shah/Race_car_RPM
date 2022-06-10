#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 1000000UL
#include <util/delay.h>

#include "initialize.h"
#include "display.h"
#include "LCD.h"
#include "timer.h"
#include "hardware.h"


void initialize()
{
	count=0;
	init_timer();
	init_ports();
}

void init_ports()
{
	OUT_DDR= 0xFF;
	DDRD |= _BV(PD0) | _BV(PD2) | _BV(PD4) | _BV(PD5) | _BV(PD6);
	DDRC |= _BV(PC0);

	MCUCR |= _BV(ISC11);
	GICR |= _BV(INT1);
	PORTD |= _BV(PD3) | _BV(PD6);
	

}
