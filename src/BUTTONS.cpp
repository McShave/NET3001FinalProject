#include <BUTTONS.h>


void button_init()
{
	DDRD &= ~((1 << P1_BUTTON) | (1 << P2_BUTTON)); //clear DDRD of button pins
	PORTD |= (1 << P1_BUTTON) | (1 << P2_BUTTON); 	//set PUR of button pins

	EICRA |=  (0 << ISC00) | (1 << ISC01) | (0 << ISC10) | (1 << ISC11)  ; //set up falling edge for INT0 and INT1
	EIMSK |= (1 << INT0) | (1 << INT1);   //enable INT0 and INT1 interrupt
}