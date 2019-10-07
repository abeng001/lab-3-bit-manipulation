/*	Author: abeng001
 *  Partner(s) Name: Matthew Choi
 *	Lab Section: 23
 *	Assignment: Lab #  Exercise #
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
 
 DDRA = 0x00; PORTA = 0xFF;
 DDRB = 0x00; PORTB = 0xFF;
 DDRC = 0xFF; PORTC = 0x00;

 unsigned char count = 0x00;
 unsigned char tempA = 0x00;
 unsigned char tempB = 0x00;
 unsigned char shiftA = 0x00;
 unsigned char shiftB = 0x00;
 unsigned char i = 0;

 while (1) {
   count = 0x00;
   tempA = PORTA; 
   tempB = PORTB;

   for (i = 0; i < 8; i++) {
     shiftA = tempA & 0x01;
     shiftB = tempB & 0x01;
     if (shiftA == 0x01) {
       count++;
     }
     if (shiftB == 0x01) {
       count++;
     }
      tempA = tempA >> 1;
      tempB = tempB >> 1;
   }
     PORTC = count;
 }
 return 1;
}
