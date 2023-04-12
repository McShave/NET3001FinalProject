#include <Arduino.h>
#include <avr_debugger.h>
#include <PINS.h>
#include <USART.h>
#include <LCD.h>
#include <BUTTONS.h>
#include <LED.h>
#include <ShiftReg.h>
#include <Segment.h>
#include <math.h>
#include <time.h>


void get_names();
void LCD_send_names();
void game_loop();
void p1_has_scored();
void p2_has_scored();
void LCD_player_scored(byte pNum);

char player1[MAX_TEXT];
char player2[MAX_TEXT];

volatile uint8_t p1_score;
volatile uint8_t p2_score;

volatile boolean p1_scored;
volatile boolean p2_scored;

byte digits[ARRAY_SIZE_DECIMAL] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6 }; 


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

  p1_score = 0;
  p2_score = 0;
  p1_scored = false;
  p2_scored = false;


  get_names();
  LCD_send_names();

  displayValueP1(digits[p1_score]);
  displayValueP2(digits[p2_score]);

  while(1)
  {
    game_loop();
  }
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

  PORTD |= (1 << P1_LED) | (1 << P2_LED);
  sei();
 
  while(1)
  {
    if (p1_scored == true)
    {
      p1_scored = false;
      p1_has_scored();
      break;
    }
    if (p2_scored == true)
    {
      p2_scored = false;
      p2_has_scored();
      break;
    }
  }
  //update 7-segments

}

ISR(INT0_vect)
{
  cli();
  p1_score++;
  p1_scored = true;
}

ISR(INT1_vect)
{
  cli();
  p2_score++;
  p2_scored = true;
}

void p1_has_scored()
{
  PORTD &= ~(1 << P2_LED);
  delayMs(250);
  for (int i = 0; i < 3; i++)
  {
    PORTD &= ~(1 << P1_LED);
    delayMs(250);
    PORTD |= (1 << P1_LED);
    delayMs(250);
  }
  PORTD &= ~(1 << P1_LED);
  displayValueP1(digits[p1_score]);
  LCD_player_scored(10);
}

void p2_has_scored()
{
  PORTD &= ~(1 << P1_LED);
  delayMs(250);
  for (int i = 0; i < 3; i++)
  {
    PORTD &= ~(1 << P2_LED);
    delayMs(250);
    PORTD |= (1 << P2_LED);
    delayMs(250);
  }
  PORTD &= ~(1 << P2_LED);
  displayValueP2(digits[p2_score]);
  LCD_player_scored(20);
}

void LCD_player_scored(byte pNum)
{
  char text1[MAX_TEXT];
  char text2[MAX_TEXT] = "has scored!";
  if (pNum == 10) { strcpy(text1, player1); }
  if (pNum == 20) { strcpy(text1, player2); }

  LCD_command(0x01);
  LCD_command(0x80);
  LCD_string(text1);
  LCD_command(0xC0);
  LCD_string(text2);
  for (int i = 0; i < 16; i++)
  {
    LCD_command(0x1C);
    delayMs(250);
  }
  LCD_command(0x01);
  LCD_send_names();

}