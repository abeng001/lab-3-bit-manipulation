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
  DDRB = 0xFF; PORTB = 0x00;
  DDRC = 0xFF; PORTC = 0x00;

  unsigned char tempB = 0x00;
  unsigned char tempC = 0x00;
  unsigned char lowerMask = 0x0F;
  unsigned char upperMask = 0xF0;

    while (1) {
      tempB = 0x00;
      tempC = 0x00;
      tempB = ((PINA >> 4) & lowerMask);
      PORTB = tempB;

      tempC = ((PINA << 4) & upperMask);
      PORTC = tempC;

    }
    return 1;
}
