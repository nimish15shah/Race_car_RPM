#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 1000000UL
#include <util/delay.h>

#include "initialize.h"
#include "display.h"
#include "LCD.h"
#include "timer.h"
#include "hardware.h"

int main(void)
{
	sei();
	initialize();
	DDRB = 0xFF;
	while(1)
	{
		display_num(rpm);

		convert(disp_3);
		OUT_PORT = result | _BV(PB7);
		_delay_us(1000);
		OUT_PORT &= ~(_BV(PB7));


		convert(disp_2);
		OUT_PORT= result;
		PORTD |= _BV(PD0);
		_delay_us(1000);
		PORTD &= ~(_BV(PD0));


		convert(disp_1);
		OUT_PORT= result;
		PORTD |= _BV(PD2);
		_delay_us(1000);
		PORTD &= ~(_BV(PD2));

		convert(disp_4);
		OUT_PORT= result;
		PORTD |= _BV(PD4);
		_delay_us(1000);
		PORTD &= ~(_BV(PD4));
		
		if(rpm>3800)
		{
			PORTD |= _BV(PD5);
		}
		else
		{
			PORTD &= ~(_BV(PD5));
		}
//		DDRC |= _BV(PC0);

		if(rpm>3200 && rpm<3400)
		{
			PORTC |= _BV(PC0);
		}
		else
		{
			PORTC &= ~(_BV(PC0));
		}

			
	}



}
