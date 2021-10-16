/*	Author: christopherluu
 *  Partner(s) Name: 
 *	Lab Section: 22
 *	Assignment: Lab #5  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
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
    ADD,
    ADDON,
    MINUS,
    MINUSON,
    RESET,
    RESETON
} state;

void Tick() {
    unsigned char tempA0 = ~PINA & 0x01;
    unsigned char tempA1 = ~PINA & 0x02;

    switch(state){
        case START:
            state = INIT;
            break;
        case INIT:
            if(!tempA0 && !tempA1){
                state = INIT;
            }
            else if(tempA0 && !tempA1){
                state = ADD;
            }
            else if(!tempA0 && tempA1){
                state = MINUS;
            }
            else if(tempA0 && tempA1){
                state = RESET;
            }
            break;
        case ADD:
            break;
        case ADDON:
            if(tempA0 && !tempA1){
                state = ADDON;
            }
            else if(tempA0 && tempA1){
                state = RESET;
            }
            else{
                state = INIT;
            }
            break;
        case MINUS:
            break;
        case MINUSON:
            if(!tempA0 && tempA1){
                state = MINUSON;
            }
            else if(tempA0 && tempA1){
                state = RESET;
            }
            else{
                state = INIT;
            }
            break;
        case RESET:
            break;
        case RESETON:
            if(tempA0 && tempA1){
                state = RESETON;
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
        case ADD:
            if(PORTC < 9){
                PORTC = PORTC + 1;
            }
            state = ADDON;
            break;
        case ADDON:
            break;
        case MINUS:
            if(PORTC > 0){
                PORTC = PORTC - 1;
            }
            state = MINUSON;
            break;
        case MINUSON:
            break;
        case RESET:
            PORTC = 0x00;
            state = RESETON;
            break;
        case RESETON:
            break;
        default:
            break;
    }
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;

    /* Insert your solution below */
    state = START;
    PORTC = 0x07;
    while (1) {
        Tick();
    }
    return 1;
}
