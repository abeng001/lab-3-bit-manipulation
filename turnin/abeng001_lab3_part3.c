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
 DDRC = 0xFF; PORTC = 0x00;

 unsigned char belt = 0x00;
 unsigned char tempA = 0x00;
 unsigned char tempC = 0x00;
 while(1) {
   tempA = 0x00; 
   belt = 0x00;
   tempA = PINA & 0x0F;
   belt = PINA;

  if(tempA < 0x03) {
    tempC = 0x20;
  }
  else if(tempA < 0x05) {
    tempC = 0x30;
  }
  else if(tempA < 0x07) {
    tempC = 0x38;
  }
  else if(tempA < 0x0A) {
    tempC = 0x3C;
  }
  else if(tempA < 0x0D) {
    tempC = 0x3E;
  }
  else if(tempA < 0x10) {
    tempC = 0x3F;
  }
  if(tempA < 0x05) {
    tempC = tempC | 0x40;
  }
  if((belt & 0x70) == 0x30) {
    tempC = tempC | 0x80;
  }

  PORTC = tempC;
 }
 return 1;
}
