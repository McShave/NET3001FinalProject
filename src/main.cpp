#include <Arduino.h>
#include <avr_debugger.h>
#include <PINS.h>

int main()
{
    #ifdef __DEBUG__
      dbg_start();
    #endif

}