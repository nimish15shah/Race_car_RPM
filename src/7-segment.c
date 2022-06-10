#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 1000000UL
#include <util/delay.h>

#include "initialize.h"
#include "display.h"
#include "LCD.h"
#include "timer.h"
#include "hardware.h"


void convert(volatile char convert_x)
{
	if(convert_x==0)
	{
		result= 0b10000001; // Active Low Logic
	}

	else if(convert_x==1)
	{
		result= 0b11110011;
	}

	else if(convert_x==2)
	{
		result= 0b01001001 ;
	}

	else if(convert_x==3)
	{
		result= 0b01100001;
	}

	else if(convert_x==4)
	{
		result= 0b00110011;
	}

	else if(convert_x==5)
	{
		result= 0b00100101;
	}

	else if(convert_x==6)
	{
		result= 0b00000101;
	}

	else if(convert_x==7)
	{
		result= 0b11110001;
	}

	else if(convert_x==8)
	{
		result= 0b00000001;
	}

	else if(convert_x==9)
	{
		result= 0b00100001;
	}

	else
	{
		result= 0b11110001;
	}
//	result ^= 0xFE;	// Convert to Active High
	
	result = result>>1;

}
