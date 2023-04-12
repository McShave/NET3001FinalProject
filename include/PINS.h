#pragma once

//PORT B

//(player 1 - shift register 0)
#define P1_DATA   PB0	//(data in)
#define P1_LATCH  PB1    //(shift register clock in)
#define P1_CLOCK  PB2    //(shift storage clock in)
//(player 2 - shift register 1)
#define P2_DATA	  PB3    //(data in)
#define P2_LATCH  PB4	//(shift register clock in)
#define P2_CLOCK  PB5	//(shift storage clock in)

#define LATCH PB4// pins 5 of Arduino for Latch pin of shift register
#define CLOCK PB5// pins 6 of Arduino for clock pin of shift register 
#define DATA PB3   // pins 4 of Arduino for data pin of shift register

#define LATCH2 PB1// pins 5 of Arduino for Latch pin of shift register
#define CLOCK2 PB2// pins 6 of Arduino for clock pin of shift register 
#define DATA2 PB0   // pins 4 of Arduino for data pin of shift register

//PORT C

//(LCD panel)
#define D4  PC0
#define D5  PC1
#define D6  PC2 
#define D7  PC3

#define BUZZER  PC4
//PC5

//PORT D

//Player 1 + 2 button
#define P1_BUTTON   PD2//(int0)
#define P2_BUTTON   PD3//(int1)

//LCD EN - RS
#define EN  PD4
#define RS  PD5

//Player 1 + 2 LED
#define P1_LED   PD6
#define P2_LED   PD7