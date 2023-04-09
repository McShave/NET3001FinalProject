#pragma once
#include<Arduino.h>

#define LATCH PB4// pins 5 of Arduino for Latch pin of shift register
#define CLOCK PB5// pins 6 of Arduino for clock pin of shift register 
#define DATA PB3   // pins 4 of Arduino for data pin of shift register

#define LATCH2 PB1// pins 5 of Arduino for Latch pin of shift register
#define CLOCK2 PB2// pins 6 of Arduino for clock pin of shift register 
#define DATA2 PB0   // pins 4 of Arduino for data pin of shift register



void init_shift(byte dataPin, byte clockPin, byte latchPin);

//function to generate a byte from a serial data in shift register
void myShiftOut(byte dataPin, byte clockPin, byte bitOrder, byte val);
