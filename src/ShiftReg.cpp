#include <ShiftReg.h>

void init_shift(byte dataPin, byte clockPin, byte latchPin)
{
    DDRB |= (1<<dataPin) | (1<<latchPin) | (1<<clockPin); // Port D PIN4,5, and 6 set to ouput 

}


//function to generate a byte from a serial data in shift register
void myShiftOut(byte dataPin, byte clockPin, byte bitOrder, byte val)
{
  byte i;
  for (i = 0; i < 8; i++)  
  {
      if (bitOrder == LSBFIRST) {
        if((val & 1)) //if the bit is 1
        {
          PORTB|= (1<<dataPin); //send one
        }
        else
        {
          PORTB&= ~(1<<dataPin); //send 0
        }   
        val >>= 1; //shift the data to right to get the next LSB
      } else {
        if((val & 128) != 0)
        {
          PORTB|= (1<<dataPin);
        }
        else
        {
          PORTB&= ~(1<<dataPin);
        }   
        val <<= 1; //shift the data to left to get the next MSB
      }
      //Create a clock pulse
      PORTB |= (1<<clockPin);
      PORTB &= ~(1<<clockPin);
  }
}
