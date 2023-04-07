#include <Arduino.h>
#include <avr_debugger.h>
#include <PINS.h>
#include <USART.h>
#include <LCD.h>

void get_names(char* player1, char* player2);
void LCD_send_names(char*player1, char* player2);

int main()
{
  #ifdef __DEBUG__
    dbg_start();
  #endif

  USART_init;
  LCD_init;

  char player1[MAX_TEXT];
  char player2[MAX_TEXT];

  get_names(player1, player2);




}



void get_names(char* player1, char* player2)
{
  char temp[MAX_TEXT];

  strcpy(temp, "\nEnter name of player 1: ");

  USART_send_string(temp);

  USART_get_string(player1);

  if (strlen(player1) > 13)
  {
    strcpy(temp, player1);
    for (int i = 0; i < 13; i++)
    {
      player1[i] = temp[i];
    }
    player1[13] = '\0';
  }

  strcpy(temp, "\n Enter name of player 2: ");

  USART_get_string(player2);

  if (strlen(player2) > 13)
  {
    strcpy(temp, player2);
    for (int i = 0; i < 13; i++)
    {
      player2[i] = temp[i];
    }
    player2[13] = '\0';
  }
}


void LCD_send_names(char*player1, char* player2)
{
  char temp[MAX_TEXT];

  sprintf(temp, "P1: %s", player1);

  LCD_command(0x80);
  LCD_string(temp);

  sprintf(temp, "P2: %s", player2);

  LCD_command(0xC0);
  LCD_string(temp);

}