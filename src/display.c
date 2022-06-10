#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 1000000UL
#include <util/delay.h>

#include "initialize.h"
#include "display.h"
#include "LCD.h"
#include "timer.h"
#include "hardware.h"

void display_num(volatile int disp_rpm)
{
//	char disp[]= {0,0,0,0};
	
	disp_1= disp_rpm/1000;
	disp_2= (disp_rpm%1000)/100;
	disp_3= (disp_rpm%100)/10;
	disp_4= (disp_rpm%10);
}
