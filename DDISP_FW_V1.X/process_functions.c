#include <xc.h>
#include "process_functions.h"

void processRuntime(int b1FuncActive,int b10FuncActive, int b2FuncActive){
    leftTurnSignal(b1FuncActive);
    rightTurnSignal(b10FuncActive);
    hazardTurnSignal(b2FuncActive);
}

//Add a safty net so that only one button can be active at a time except for hazard
void leftTurnSignal(int b1FuncActive){
    switch(b1FuncActive){
        case 1://need to interface can code Here
            leftTurnIndicator(1);
            __delay_ms(1000);
            leftTurnIndicator(0);
            __delay_ms(1000);
            break;
    }
}
void rightTurnSignal(int b10FuncActive){
    switch(b10FuncActive){
        case 1://need to interface can code Here
            rightTurnIndicator(1);
            __delay_ms(1000);
            rightTurnIndicator(0);
            __delay_ms(1000);
            break;
    }
}
void hazardTurnSignal(int b2FuncActive){
    switch(b2FuncActive){
        case 1://need to interface can code Here
            rightTurnIndicator(1);
            leftTurnIndicator(1);
            hazardSignal(1);
            __delay_ms(1000);
            leftTurnIndicator(0);
            rightTurnIndicator(0);
            hazardSignal(0);
            __delay_ms(1000);
            break;
    }
}