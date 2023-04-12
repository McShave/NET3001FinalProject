#pragma once
#include<Arduino.h>





void init_shift(byte dataPin, byte clockPin, byte latchPin);

//function to generate a byte from a serial data in shift register
void myShiftOut(byte dataPin, byte clockPin, byte bitOrder, byte val);
