/*	Author: christopherluu
 *  Partner(s) Name: 
 *	Lab Section: 22
 *	Assignment: Lab #5  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *  Video (demo): https://youtu.be/5gxh-BLSrTk
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States{
    START,
    INIT,
    PRESS,
    RELEASE
} state;

unsigned char phases[7] = {0x03, 0x06, 0x0C, 0x18, 0x30, 0x15, 0x2A};
unsigned char counter = 0;
unsigned char tempB = 0x00;

void Tick() {
    unsigned char on = ~PINA & 0x01;
    
    switch(state){
        case START:
            state = INIT;
            break;
        case INIT:
            if(on){
                state = PRESS;
            }
            else
            {
                state = INIT;
            }
            break;
        case PRESS:
            break;
        case RELEASE:
            if(on){
                state = RELEASE;
            }
            else{
                state = INIT;
            }
            break;
        default:
            state = INIT;
            break;
    }
    
    switch(state){
        case START:
            break;
        case INIT:
            break;
        case PRESS:
            tempB = phases[counter];
            if(counter < 7)
                counter++;
            else
                counter = 0;
            state = RELEASE;
            break;
        case RELEASE:
            break;
        default:
            break;
    }
    PORTB = tempB;
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;

    /* Insert your solution below */
    while (1) {
        Tick();
    }
    return 1;
}
