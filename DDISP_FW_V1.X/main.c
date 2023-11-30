///////////////////////////////////////////////////
// Low Voltage System FW Origin                  //
// Program Implimentaion By: Anthony Seymour     //
// Uart Functionality By: Eric Liu               //
// Checksum By: Micheal Holden                   //
// Date: 2022-06-17                              //
///////////////////////////////////////////////////

#include <xc.h>  
#include "mcc_generated_files/mcc.h"
#include "uart_interface.h"
#include "button_functionality.h"
#include "process_functions.h"
#include "can_interface.h"

uCAN_MSG rx;

////////////////////////////////////Button Variables
//Button1--Left Turn Signal
int b1FuncActive=0;
int lastb1 = 0;
int blinkb1 = 0;
int latchb1 = 0;
//Button2--Hazard Signal
int b2FuncActive=0;
int lastb2 = 0;
int blinkb2 = 0;
int latchb2 = 0;
//Button3
int b3FuncActive=0;
//Button4
int b4FuncActive=0;
//Button5
int b5FuncActive=0;
//Button6
int b6FuncActive=0;
//Button7
int b7FuncActive=0;
//Button8
int b8FuncActive=0;
//Button9
int b9FuncActive=0;
//Button10--Right Turn Signal
int b10FuncActive=0;
int lastb10 = 0;
int blinkb10 = 0;
int latchb10 = 0;


void main(void){
    SYSTEM_Initialize();
    
    while (1){
        if (CAN_receive(&rx)){
            if (rx.frame.id == 0x22){//startup success from PMS
                break;
            }
            else if (rx.frame.id == 0x122){
                //do nothing
            }
        }
    }
    RC6_SetHigh();//Init Transmission on HMI Bus
    __delay_ms(1000);
    init();//clear display through UART
    __delay_ms(500);
    char tog = 1;
    int counter = 0;
    int speed = 0; //placeholder
    
    while (1){
        counter++;
        __delay_ms(50);
        
        /////////////////////////
        //BUTTON IMPLEMENTATION//
        /////////////////////////
        //if buttons are newly activated
        if (b10FuncActive && !lastb10 && !blinkb1 && !blinkb2){
            blinkb10 = 1;
            canRightSignal(1);
            __delay_ms(1);
            rightTurnIndicator(1);
             __delay_ms(1);
        }
        if (b1FuncActive && !lastb1 && !blinkb2 && !blinkb10){
            blinkb1 = 1;
            canLeftSignal(1);
            __delay_ms(1);
            leftTurnIndicator(1);
            __delay_ms(1);
        }
        if (b2FuncActive && !lastb2){
            blinkb2 = 1;
            blinkb1 = 0;
            blinkb10 = 0;
            
            //deactivate turn signals
            canLeftSignal(0);
            __delay_ms(1);
            canRightSignal(0);
            __delay_ms(1);
            leftTurnIndicator(0);
            __delay_ms(1);
            rightTurnIndicator(0);
             __delay_ms(1);
             
            canHazardSignal(1);
            __delay_ms(1);
            hazardSignal(1);
            __delay_ms(1);
        }
        
        //if buttons are newly deactivated
        if (!b10FuncActive && lastb10){
            blinkb10 = 0;
            canRightSignal(0);
            __delay_ms(1);
            rightTurnIndicator(0);
             __delay_ms(1);
        }
        if (!b1FuncActive && lastb1){
            blinkb1 = 0;
            canLeftSignal(0);
            __delay_ms(1);
            leftTurnIndicator(0);
            __delay_ms(1);
        }
        if (!b2FuncActive && lastb2){
            blinkb2 = 0;
            canHazardSignal(0);
            __delay_ms(1);
            hazardSignal(0);
            __delay_ms(1);
        }
       /* if (tog == 1){
            tog = 0;
        }
        else{
            tog = 1;
        }
        leftTurnIndicator(tog);
        __delay_ms(500);*/

        
        //update last values for each button (prevents double transmission)
        lastb1 = b1FuncActive;
        lastb2 = b2FuncActive;
        lastb10 = b10FuncActive;
        
        leftTurnButton(&b1FuncActive, &latchb1);
        rightTurnButton(&b10FuncActive, &latchb10);
        hazardButton(&b2FuncActive, &latchb2);
        //update speed value on display
        if (counter >= 10 && speed != -1){//500ms
            counter = 0;
            motorSpeed(speed);
            speed++;
        }
        
        //////////////////////////////
        //CAN RECEIVE + UART SECTION//
        //////////////////////////////
        if (CAN_receive(&rx)){
            if (rx.frame.idType == 1){
                //BMS failure or ESTOP procedure
                if (rx.frame.id == 0x02F4 || rx.frame.id == 0x04F4 || rx.frame.id == 0x05F4 || rx.frame.id == 0x07F4 || rx.frame.id == 0x08F4 || rx.frame.id == 0x4){
                    __delay_ms(1);
                    warningLED(1);
                }
                //auxiliary battery connection
                if (rx.frame.id == 0x80){
                    if (rx.frame.data0 == 1){//normal case
                        __delay_ms(1);
                        auxBattConn(1);                           
                    }
                    else {//error case
                        __delay_ms(1);
                        auxBattConn(0);                    
                    }
                }
                //motor speed
                if (rx.frame.id == 0x81){//verify where we're getting this data from
                    __delay_ms(1);
                    speed = rx.frame.data0;
                }
            }
        }
        //buttonRuntime(&b1FuncActive,&b10FuncActive);
        //processRuntime(b1FuncActive, b10FuncActive, b2FuncActive);
        //__delay_ms(10);
    }
}


