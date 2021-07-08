/*	Author: Alyssa Zepeda
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #7  Exercise #4
 *	Exercise Description: https://youtu.be/rM3MgEn9lgA
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
unsigned char MIN = 0x47; //min from prev exercise

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
    	unsigned threshold = (MAX - MIN)/7; //(255-71)/7 = 26.3 -> 26, 7 because there are 7 sections between MIN & MAX
	while(1) {
		x = ADC;
		tempB = (char)x;
		if(tempB <= MIN) { //71
			PORTB = 0x01;
		}
		else if(tempB <= (MIN + (threshold))) { 
			PORTB = 0x03;
		}
		else if(tempB <= (MIN + (threshold * 2))) { 
                        PORTB = 0x07;
                }
		else if(tempB <= (MIN + (threshold * 3))) {
                        PORTB = 0x0F;
                }
		else if(tempB <= (MIN + (threshold * 4))) {
                        PORTB = 0x1F;
                }
		else if(tempB <= (MIN + (threshold * 5))) {
                        PORTB = 0x3F;
                }
		else if(tempB <= (MIN + (threshold * 6))) {
                        PORTB = 0x7F;
                }
		else {
			PORTB = MAX;
		}
	}
    return 1;
}
