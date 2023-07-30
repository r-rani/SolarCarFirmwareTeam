//////////////////////////////////
// Low Voltage System FW Origin //
// By: Anthony Seymour          //
// Date: 2022-06-08             //
//////////////////////////////////

#include <xc.h>  
#include "mcc_generated_files/mcc.h"
#include "ancfunctions.h"

//Can Ids
#define HAZARD_SIGNAL 0x61//Temps change them after
#define RIGHT_SIGNAL 0x62
#define LEFT_SIGNAL 0x63
#define FRONT_SIGNAL 0x64
#define BACK_SIGNAL 0x65
#define NO 0x67

uCAN_MSG rx;

void main(void){
    SYSTEM_Initialize();
    while (1){
        
//        FrontSignal_SetHigh();
//        BackSignal_SetHigh();
//        BPSFault_SetHigh();
//        HazardSignal_SetHigh();
        if(CAN_receive(&rx)){//Sorting Buffer
            if(rx.frame.idType == 1){
                
                if(rx.frame.id == HAZARD_SIGNAL) {
                    hazardLightFunction(rx.frame.data0);
                }
                if(rx.frame.id == RIGHT_SIGNAL) {
                    rightTurnFunction(rx.frame.data0);
                }
                if(rx.frame.id == LEFT_SIGNAL) {
                    leftTurnFunction(rx.frame.data0);
                }
                if(rx.frame.id == FRONT_SIGNAL) {
                    frontTurnFunction(rx.frame.data0);
                }
                if(rx.frame.id == BACK_SIGNAL) {
                    backTurnFunction(rx.frame.data0);
                }
                if (rx.frame.id==NO){
                    func99();
                }
            }else{
                //Error with Id type
            }
        }else{
            //Error with Buffer
        }
    }
}