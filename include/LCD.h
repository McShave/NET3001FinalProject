#pragma once
#include <Arduino.h>
#include <PINS.h>

// Functions Prototypes
void delayMs(uint16_t ms);

// initialize the library with the numbers of the interface pins
void LCD_nibble_write(uint8_t data, uint8_t control);
void LCD_command(uint8_t command);
void LCD_data(uint8_t data);
void LCD_init(void);
void PORTS_init(void);
void LCD_string(char *str);