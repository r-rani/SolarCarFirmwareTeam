#include "LCD_functions.h"

//Called after every command, runs command on LCD
void LCD_intake(void){
    LCD_EN = 1;     
    NOP();
    LCD_EN = 0;
    __delay_ms(3);
}

void LCD_command(uint8_t command){
    LCD_RS = 0;         //command register is selected
    LCD_RW = 0;         //write operation
    
    LCD_DATA = command; //sends data to port B as command
    LCD_intake();
}

uint8_t LCD_set_pos(uint8_t x, uint8_t y){
    if (y%2 == 1){
        x += 0x40;  //accesses memory addresses of line 2 on LCD
    }
    
    LCD_command(0x80 | x);
    return x;
}

void LCD_print(uint8_t x,uint8_t pos, uint8_t line){
    LCD_set_pos(pos,line); //sets cursor to desired starting location

    LCD_RS = 1;
    LCD_RW = 0;
    LCD_DATA = x;           //send data to LCD
    LCD_intake();
}

void LCD_print_string(const char *str, uint8_t pos, uint8_t line){
    uint8_t i = 0;
    while (str[i] != 0){
        if (pos + i > 15){
            LCD_print(str[i],pos+i-16,line + 1);    //prints to second line if first line overflows
        }
        else{
            LCD_print(str[i],pos+i,line);           //prints to first line by default
        }
        i++;
    }
}

void LCD_init(void){
    __delay_ms(15);
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_DATA = 0;

    LCD_command(0x38);  //uses 2 line and initializes 5*8 matrix on LCD
    LCD_command(0x01);  //clears display of screen
    LCD_command(0x0C);  //display on, cursor off
    LCD_command(0x06);  //increment cursor (right shift)
    
    LCD_print_string("System Start",0,0);
    __delay_ms(200);
    for(uint8_t i=0;i<4;i++){
        LCD_print_string(".",12+i,0);
        __delay_ms(200);
    }
    LCD_command(0x01);   
}
