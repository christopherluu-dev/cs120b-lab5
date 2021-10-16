/*	Author: christopherluu
 *  Partner(s) Name: 
 *	Lab Section: 22
 *	Assignment: Lab #5  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
    while (1) {
        unsigned char tempA = ~PINA & 0x0F;
        unsigned char tempC = 0;
        
        if(~tempA >= 13){
            tempC = tempC | 0x3F;
        }
        else if(~tempA >= 10){
            tempC = tempC | 0x3E;
        }
        else if(~tempA >= 7){
            tempC = tempC | 0x3C;
        }
        else if(~tempA >= 5){
            tempC = tempC | 0x38;
        }
        else if(~tempA >= 3){
            tempC = tempC | 0x30;
        }
        else if(~tempA >= 1){
            tempC = tempC | 0x20;
        }

        if(~tempA <= 4){
            tempC = tempC | 0x40;
        }

        PORTC = tempC;
    }
    return 1;
}
