/*
 * File:   main.c
 * Author: ranir
 *
 * Created on January 30, 2023, 1:16 PM
 */


#include <xc.h>  
#include "mcc_generated_files/mcc.h"

//Can Ids
//BPS FAULT INDICATORS
#define ALM_INFO 0x07F4 //This goes for cell voltage high and cell temp high - Alarm level 3
#define CELL_VOLT_HI 0x04F4 //Alarm 1
#define CELL_TEMP_HI 0x05F4 //05F4 48 06 2F 01 3F XX XX XX Means: The highest cell temperature is 22?, corresponding to cell number 6; the lowest cell temperature is -3?, corresponding cell number is 1. The average cell temperature is 13°C
//Set by us 
#define HAZARD_SIGNAL 0x1//Temps change them after
#define RIGHT_SIGNAL 0x2
#define LEFT_SIGNAL 0x3
#define FRONT_SIGNAL 0x4
#define BACK_SIGNAL 0x5

uCAN_MSG rx;

void main(void){
    SYSTEM_Initialize();
    while (1){
        if(CAN_receive(&rx)){
            if(rx.frame.idType == 1){
                if(rx.frame.id == HAZARD_SIGNAL || ALM_INFO || CELL_VOLT_HI || CELL_TEMP_HI) {
                    if(rx.frame.data0 == 1){
                        HazardSignal_SetHigh();//555  timer set on and off 
                        HazardSignal_SetLow();
                    }else{
                        HazardSignal_SetLow();
                    }
                }
                if(rx.frame.id == RIGHT_SIGNAL) {
                    if(rx.frame.data0 == 1){
                        RightSignal_SetHigh();
                        RightSignal_SetLow();
                    }else{
                        RightSignal_SetLow();
                    }
                }
                if(rx.frame.id == LEFT_SIGNAL) {
                    if(rx.frame.data0 == 1){
                        LeftSignal_SetHigh();
                        LeftSignal_SetLow();
                    }else{
                        LeftSignal_SetLow();
                    }
                }
                if(rx.frame.id == FRONT_SIGNAL) {
                    if(rx.frame.data0 == 1){
                        FrontSignal_SetHigh();
                        FrontSignal_SetLow();
                    }else{
                        FrontSignal_SetLow();
                    }
                }
                if(rx.frame.id == BACK_SIGNAL) {
                    if(rx.frame.data0 == 1){
                        BackSignal_SetHigh();
                    }else{
                        BackSignal_SetLow();
                    }
                }
            }else{
                break; //not sure what to do when error happens
            }
        }else{
            break; //not sure what to do when error happens 
        }
    }
}