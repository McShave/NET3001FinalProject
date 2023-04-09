
#include <LED.h>

void LED_init()
{
    DDRD |= (1 << P1_LED) | (1 << P2_LED);
}