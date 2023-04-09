#pragma once

//PORT B

//(player 1 - shift register 0)
#define P1_DS    PB0	//(data in)
#define P1_STCP  PB1    //(shift register clock in)
#define P1_SHCP	 PB2    //(shift storage clock in)
//(player 2 - shift register 1)
#define P2_DS	 PB3    //(data in)
#define P2_STCP  PB4	//(shift register clock in)
#define P2_SHCP  PB5	//(shift register clock in)

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