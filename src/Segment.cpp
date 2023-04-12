#include <Segment.h>
#include <ShiftReg.h>

void displayValueP1(byte value)
{
    //set P2_LATCH to low
      PORTB&=~(1<<P1_LATCH);
      //shift the data in shift register
      myShiftOut(P1_DATA, P1_CLOCK, LSBFIRST, value);
      //set the P2_LATCH to high again
      PORTB|=(1<<P1_LATCH);
}

void displayValueP2(byte value)
{
    //set P2_LATCH to low
      PORTB&=~(1<<P2_LATCH);
      PORTB&=~(1<<P1_LATCH);
      //shift the data in shift register
      myShiftOut(P2_DATA, P2_CLOCK, LSBFIRST, value);
      //set the P2_LATCH to high again
      PORTB|=(1<<P2_LATCH);
      PORTB|=(1<<P1_LATCH);
}


