#include "LCD_functions.h"
#include "button_functionality.h"
#include <stdio.h>
#include <stdlib.h>

uCAN_MSG rx;

void main(void)
{
    SYSTEM_Initialize();
    
    IO_RD2_SetHigh();

    LCD_command(0x01);
    
    TRISD5 = 0;
    TRISD6 = 0;
    TRISD7 = 0;

    TRISB = 0x00;
    
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_EN = 0;

    LATB = 0x00;
    
    LCD_init();

    int latch = 0;
    
    int* currentState = malloc(sizeof(int));//current state of CLK pin on encoder
    int* prevState = malloc(sizeof(int));//previous state of CLK pin on encoder
    *currentState = IO_RC4_GetValue();
    *prevState = IO_RC4_GetValue();
    int counter = 0;//keeps track of menu array index
    int lastCounter = counter;
  
    int exitBTNPressed = 1;
    
    char menu[6][10] = {"Title 1","Reading 1","Title 2","Reading 2","Title 3","Reading 3"};
    
    LCD_print_string(menu[0],0,0);
    
    while (1){
        latch = enterExitButtons(latch);
        lastCounter = counter;
        counter = updateEncoder(currentState,prevState,counter);
        //only allows enter button to be used when exit button has already been used
        if (latch == 1 && exitBTNPressed == 1){
            counter += 1;
            exitBTNPressed = 0;
        }
        //only allows exit button to be used when enter button has already been used
        else if (latch == 0 && exitBTNPressed == 0){
            counter -= 1;
            exitBTNPressed = 1;     
        }
        
        //Only updates if position has changed
        if (lastCounter != counter){
            LCD_command(0x01);
            LCD_print_string(menu[counter],0,0);
        }  
                
        if(CAN_receive(&rx)){
           // RLED_Toggle();
            __delay_ms(1);
        }
    }
}