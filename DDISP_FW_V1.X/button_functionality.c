#include <xc.h>
#include "button_functionality.h"

void buttonRuntime(int* b1v,int* b10v) {//Runtime Checking
    int var = 0;
    leftTurnButton(b1v, &var);
    rightTurnButton(b10v, &var);
}
void leftTurnButton(int* b1FunctionActive, int* b1Latch) {
    switch (Button1_GetValue()) {//Check Button Press 
    case 0://Reset Latch
        *b1Latch = 0;
        break;
    case 1://Activation
        switch (*b1Latch) {//Checks to see if button prev called
        case 0://Func as normal
            switch (*b1FunctionActive) {//Checks to see if active
            case 0://Not active
                //Set Activation
                *b1FunctionActive = 1;
                break;
            case 1://Active
                //Deactivate 
                *b1FunctionActive = 0;
                break;
            }
            *b1Latch = 1;
            break;
        }
        break;
    }
}
void rightTurnButton(int* b10FunctionActive, int* b10Latch){
    switch (Button10_GetValue()) {//Check Button Press 
    case 0://Reset Latch
        *b10Latch = 0;
        break;
    case 1://Activation
        switch (*b10Latch) {//Checks to see if button prev called
        case 0://Func as normal
            switch (*b10FunctionActive) {//Checks to see if active
            case 0://Not active
                //Set Activation
                *b10FunctionActive = 1;
                break;
            case 1://Active
                //Deactivate 
                *b10FunctionActive = 0;
                break;
            }
            *b10Latch = 1;
            break;
        }
        break;
    }
}

void hazardButton(int* b2FunctionActive, int* b2Latch){
    switch (Button2_GetValue()) {//Check Button Press 
    case 0://Reset Latch
        *b2Latch = 0;
        break;
    case 1://Activation
        switch (*b2Latch) {//Checks to see if button prev called
        case 0://Func as normal
            switch (*b2FunctionActive) {//Checks to see if active
            case 0://Not active
                //Set Activation
                *b2FunctionActive = 1;
                break;
            case 1://Active
                //Deactivate 
                *b2FunctionActive = 0;
                break;
            }
            *b2Latch = 1;
            break;
        }
        break;
    }
}
