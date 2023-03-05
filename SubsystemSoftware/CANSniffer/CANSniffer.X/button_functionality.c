#include "button_functionality.h"

int enterButtonGetValue(){
    return IO_RD0_GetValue();
}

int exitButtonGetValue(){
    return IO_RD1_GetValue();
}

int enterExitButtons(int latch){
    switch(latch){
        case 0:
            switch(enterButtonGetValue()){
                case 0://Button pressed
                    latch = 1;//Initialize latch
                    break;
            }
        case 1:
            switch(exitButtonGetValue()){
                case 0://Button pressed
                    latch = 0;//Reset latch
                    break;
            }
    }
    return latch;
}

int updateEncoder(int* current, int* last, int counter){
    if (counter%2 == 0){//Only runs function if in TITLE mode
        *current = IO_RC4_GetValue();
        int DT = IO_RC5_GetValue();//DT pin is RC5
        if (*current != *last && *current == 1){
            if (DT != *current){//CW rotation
                counter += 2;
            }
            else{//CCW rotation
                if (counter - 2 == -2){//Keeps counter in useful range
                    counter = 4;
                }
                else{
                    counter -= 2;
                }
            }
            counter = counter%6;
        }

        *last = *current;
        __delay_ms(1);
    }
    return counter;
}