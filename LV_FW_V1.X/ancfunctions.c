#include <xc.h>  
#include "mcc_generated_files/mcc.h"
#include "ancfunctions.h"

////////////////////////////////////////////////////////////////////////////
//PIN-OUTPUT FUNCTIONS://///////////////////////////////////////////////////
//HazardSignal, RightSignal, LeftSignal, FrontSignal, BackSignal, BPSFault//
////////////////////////////////////////////////////////////////////////////

void hazardLightFunction(int signal){
    if(signal == 1){
        HazardSignal_SetHigh();
    }
    else if (signal == 0){
        HazardSignal_SetLow();
    }
    __delay_ms(1000);
}
void rightTurnFunction(int signal){
    if(signal == 1){
        RightSignal_SetHigh();
    }
    else if(signal == 0){
        RightSignal_SetLow();
    }
    __delay_ms(1000);
}
void leftTurnFunction(int signal){
    if(signal == 1){
        LeftSignal_SetHigh();
    }
    else{
        LeftSignal_SetLow();
    }
    __delay_ms(1000);
}
void frontTurnFunction(int signal){
    if(signal == 1){
        FrontSignal_SetHigh();
    }
    else if (signal == 0){
        FrontSignal_SetLow();
    }
    __delay_ms(1000);
}
void backTurnFunction(int signal){
    if(signal == 1){
        BackSignal_SetHigh();
    }
    else if (signal == 0){
        BackSignal_SetLow();
    }
    __delay_ms(1000);
}

void func99 (){
    BackSignal_SetLow();
    FrontSignal_SetLow();
    LeftSignal_SetLow();
    RightSignal_SetLow();
    HazardSignal_SetLow();

}