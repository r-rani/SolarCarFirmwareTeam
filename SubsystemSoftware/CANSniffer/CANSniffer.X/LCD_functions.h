#ifndef LCD_FUNCTIONS_H
#define	LCD_FUNCTIONS_H

#include "mcc_generated_files/mcc.h"
#include "xc.h"

#define LCD_DATA    LATB    //Port B is data port
#define LCD_RW      LATD5   //Port D5 pin is read/write
#define LCD_RS      LATD6   //Port D6 pin is register select
#define LCD_EN      LATD7   //Port D7 pin is LCD enable

void LCD_init(void);
void LCD_intake(void);
void LCD_command(uint8_t command);
uint8_t LCD_set_pos(uint8_t x, uint8_t y);
void LCD_print(uint8_t x,uint8_t pos, uint8_t line);
void LCD_print_string(const char *str, uint8_t pos, uint8_t line);

#endif