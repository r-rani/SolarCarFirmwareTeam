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


////////////////////////////////////Button Variables
//Button1--Left Turn Signal
int b1FuncActive=0;
//Button2--Hazard Signal
int b2FuncActive=0;
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


void main(void){
    SYSTEM_Initialize();
    RC6_SetHigh();//Init Transmission on HMI Bus(Need to check If we actually need this)
    
    while (1){
        if (b10FuncActive){
            canRightSignal(1);
            rightTurnIndicator(1);
            __delay_ms(1000); //instead of delays think of working in a timer
            canRightSignal(0);
            rightTurnIndicator(0);
            __delay_ms(1000);            
        }
        if (b1FuncActive){
            canLeftSignal(1);
            leftTurnIndicator(1);
            __delay_ms(1000);
            canLeftSignal(0);
            leftTurnIndicator(0);
            __delay_ms(1000);
        }
        if (b2FuncActive){
            canHazardSignal(1);
            hazardSignal(1);
            __delay_ms(1000);
            canHazardSignal(0);
            hazardSignal(0);
            __delay_ms(1000);
        }

        rightTurnButton(&b10FuncActive);
        leftTurnButton(&b1FuncActive);
        hazardButton(&b2FuncActive);
        
        /*if (CAN_receive(&rx1)){
         if (rx1.frame.idType == 1){
             if (rx1.frame.id == ID){
                __delay_ms(1);*/
             }
        //buttonRuntime(&b1FuncActive,&b10FuncActive);
        //processRuntime(b1FuncActive, b10FuncActive, b2FuncActive);
        //__delay_ms(10);
}


