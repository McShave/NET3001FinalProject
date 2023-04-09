#include"Segment.h"
#include"ShiftReg.h"


void displayValueP1(byte value)
{
    //set latch to low
      PORTB&=~(1<<LATCH);
      PORTB&=~(1<<LATCH2);
      //shift the data in shift register
      myShiftOut(DATA, CLOCK, LSBFIRST, value);
      //set the latch to high again
      PORTB|=(1<<LATCH);
      PORTB|=(1<<LATCH2);
}

void displayValueP2(byte value)
{
    //set latch to low
      PORTB&=~(1<<LATCH2);
      //shift the data in shift register
      myShiftOut(DATA2, CLOCK2, LSBFIRST, value);
      //set the latch to high again
      PORTB|=(1<<LATCH2);
}
