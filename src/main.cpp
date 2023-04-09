#include <Arduino.h>
#include <avr_debugger.h>
#include <PINS.h>
#include <USART.h>
#include <LCD.h>
#include <BUTTONS.h>
#include <LED.h>
#include <math.h>
#include <time.h>


void get_names();
void LCD_send_names();
void game_loop();

char player1[MAX_TEXT];
char player2[MAX_TEXT];

byte* p1_score;
byte* p2_score;


int main()
{
  #ifdef __DEBUG__
    dbg_start();
  #endif

  DDRB = 0x00;
  DDRC = 0x00;
  DDRD = 0x00;

  PORTB = 0x00;
  PORTC = 0x00;
  PORTD = 0x00;

  USART_init();
  LCD_init();
  button_init();
  LED_init();

  *p1_score = 0;
  *p2_score = 0;


  get_names();
  LCD_send_names();

  game_loop();

}



void get_names()
{
  char temp[MAX_TEXT];

  strcpy(temp, "\nEnter name of player 1: ");

  USART_send_string(temp);

  USART_get_string(player1);

  if (strlen(player1) > 12)
  {
    strcpy(temp, player1);
    for (int i = 0; i < 12; i++)
    {
      player1[i] = temp[i];
    }
    player1[12] = '\0';
  }

  strcpy(temp, "\n Enter name of player 2: ");

  USART_send_string(temp);

  USART_get_string(player2);

  if (strlen(player2) > 12)
  {
    strcpy(temp, player2);
    for (int i = 0; i < 12; i++)
    {
      player2[i] = temp[i];
    }
    player2[12] = '\0';
  }
}


void LCD_send_names()
{
  char temp[MAX_TEXT];

  sprintf(temp, "P1: %s", player1);

  LCD_command(0x80);
  LCD_string(temp);

  sprintf(temp, "P2: %s", player2);

  LCD_command(0xC0);
  LCD_string(temp);

}

void game_loop()
{
  srand(time(NULL));

  uint16_t randTime = (rand()%4500)+500;

  delayMs(randTime);

  PORTC |= (1 << BUZZER);
  sei();
  delayMs(500);
  PORTC &= ~(1 << BUZZER);
 
  //update 7-segments

}

ISR(INT0_vect)
{
  cli();
  (*p1_score)++;

  PORTD |= (1 << P1_LED);
  delayMs(2000);
  PORTD &= ~(1 << P1_LED);
}

ISR(INT1_vect)
{
  cli();
  (*p2_score)++;

  PORTD |= (1 << P2_LED);
  delayMs(2000);
  PORTD &= ~(1 << P2_LED);
}