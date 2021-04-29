#ifndef LCD
#define LCD

#include "stm32l0xx_hal.h"

void LCD_Init();
void LCD_Set8BitMode();
void LCD_ClearDisplay();
void LCD_ReturnHome();
void LCD_TurnDisplayOn();
void LCD_TurnDisplayOff();
void LCD_DisplayChar(char c);
void LCD_Print(const char* string);

#endif