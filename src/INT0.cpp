#include <INT0.h>


void button_init()
{
	DDRD &= ~(1 << BUTTON); //clear DDRD of button pin
	PORTD |= (1 << BUTTON); //set PORTD of button pin

	EICRA |= (1 << ISC01);  
	EIMSK |= (1 << INT0);   //check for INT0 interrupt
	sei();                  //activate interrupt
}