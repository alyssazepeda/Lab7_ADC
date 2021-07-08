/*	Author: Alyssa Zepeda
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #7  Exercise #3
 *	Exercise Description: https://youtu.be/S__VBWI2l8s
 *	 
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned short x = 0x00;
unsigned char MAX = 0xFF; // maximum from prev exercise

void ADC_Init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
	//ADEN: setting this bit enables ADC
	//ADSC: setting this bit starts 1st conversion
	//ADATE: setting this bit enables auto-trigger. Since we are
	//	 in Free Running Mode, a new conversion will trigger whenever
	//	 the previous conversion completes
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
    /* Insert your solution below */
	ADC_Init();
	unsigned char tempB = 0x00;
    	while (1) {
		x = ADC;
		tempB = (char)x;
		if(tempB >= MAX/2) {
			PORTB = 0x01;
		}
		else {
			PORTB = 0x00;
		}
    	}
    return 1;
}
