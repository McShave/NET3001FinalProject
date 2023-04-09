#include <BUTTONS.h>


void button_init()
{
	DDRD &= ~((1 << P1_BUTTON) | (1 << P2_BUTTON)); //clear DDRD of button pin
	PORTD |= (1 << P1_BUTTON) | (1 << P2_BUTTON); //set PORTD of button pin

	EICRA |= (1 << ISC01) | (1 << ISC10);  
	EIMSK |= (1 << INT0) | (1 << INT1);   //check for INT0 interrupt
}