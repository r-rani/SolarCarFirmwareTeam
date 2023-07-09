#include <xc.h>
#include "mcc_generated_files/mcc.h"

//#define READ_AUX //pin 7 - RA5
//#define READ_DCDC //pin 9 - RE1
//#define HV_ON  //pin 2 - RA0
//#define DCDC_ENABLE //pin 25 - RC6
//#define ATI_DCDC //pin 4 - RA2
//#define ATI_AUX //pin 5 - RA3
//#define NEG_CON_1 //pin 16 - RC1
//#define NEG_CON_2 //pin 23 - RC4
//#define PRECHARGE_1 //pin 17 - RC2
//#define PRECHARGE_2 //pin 24 - RC5
//#define POS_CON_1 //pin 15 - RC0
//#define POS_CON_2 //pin 18 - RC3
//#define READ_MPPT //pin 3 - RA1
//#define DDISP_OUT //pin ? 
//#define MOTOR_ON // pin ?

static int THRESVOLT = 10.2; //10.2V
static int startup_success = false; //boolean for startup process success
static int shutdown_trigger = false; //something should trigger shutdown sequence (?)

int highOrlow(int voltage){
    int output;
    if (voltage >= 10.2) {
        output = 1;
    }
    else{
        output = 0;
    }
    return output;
}

uCAN_MSG tx1, tx2, tx3, tx4, tx5, tx6, tx7; //initializations for transmit and receive messages

//create a function for each DDISP message
//MPPT Error DDISP
void canbus_msg_MPPT(int number){
    tx1.frame.idType = 1;
    tx1.frame.id = 0x9; //Arbitration ID
    tx1.frame.dlc = 0x01; //1 byte
    tx1.frame.data0 = number; //data that gets sent - error codes don't require data 
}

//Motor Error DDISP
void canbus_msg_motor(int number){
    tx2.frame.idType = 1;
    tx2.frame.id = 0x9; //Arbitration ID
    tx2.frame.dlc = 0x01; //1 byte
    tx2.frame.data0 = number;
}

//START UP FAIL DDISP
void canbus_msg_startupfail(int number){
    tx3.frame.idType = 1;
    tx3.frame.id = 0x9; //Arbitration ID
    tx3.frame.dlc = 0x01; //1 byte
    tx3.frame.data0 = number;
}

//BPS Fault DDISP
void canbus_msg_bps(int number){
    tx4.frame.idType = 1;
    tx4.frame.id = 0x9; //Arbitration ID
    tx4.frame.dlc = 0x01; //1 byte
    tx4.frame.data0 = number;
}

//AUX battery failure DDISP
void canbus_msg_auxfail(int number){
    tx5.frame.idType = 1;
    tx5.frame.id = 0x9; //Arbitration ID
    tx5.frame.dlc = 0x01; //1 byte
    tx5.frame.data0 = number;
}

//AUX line low voltage DDISP
void canbus_msg_auxlow(int number){
    tx6.frame.idType = 1;
    tx6.frame.id = 0x9; //Arbitration ID
    tx6.frame.dlc = 0x01; //1 byte
    tx6.frame.data0 = number;
}

//CANBUS shutdown sequence success message
void canbus_shutdown_success(int number){
    tx7.frame.idType = 1;
    tx7.frame.id = 0x18; //Arbitration ID
    tx7.frame.dlc = 0x01; //1 byte
    tx7.frame.data0 = number;  //power mode
}

//CAN receive for motor - 4 functions
void canbus_motor_rearL(uCAN_MSG rx1){
    rx1.frame.idType = 1;
    rx1.frame.id = 0x08950225; //ID value
    rx1.frame.dlc = 0x01; //1 byte
    rx1.frame.data0 = 0x00000001;  //power mode
}

void canbus_motor_rearR(uCAN_MSG rx2){
    rx2.frame.idType = 1;
    rx2.frame.id = 0x08950245; //ID value
    rx2.frame.dlc = 0x01; //1 byte
    rx2.frame.data0 = 0x00000001;  //power mode
}

void canbus_motor_frontL(uCAN_MSG rx3){
    rx3.frame.idType = 1;
    rx3.frame.id = 0x08950265; //ID value
    rx3.frame.dlc = 0x01; //1 byte
    rx3.frame.data0 = 0x00000001;  //power mode
}

void canbus_motor_frontR(uCAN_MSG rx4){
    rx4.frame.idType = 1;
    rx4.frame.id = 0x08950285; //ID value
    rx4.frame.dlc = 0x01; //1 byte
    rx4.frame.data0 = 0x00000001;  //power mode
}

void undo_seq(void){
    if (IO_RA1_GetValue() == 1){     //read mppt
        IO_RA1_SetLow();
    }
    if (IO_RC5_GetValue() == 1){       //precharge 2
        IO_RC5_SetLow();
    }
    if (IO_RC2_GetValue() == 1){       //precharge 1
        IO_RC2_SetLow();
    }
    if (IO_RC3_GetValue() == 1){     //positive connector 2
        IO_RC3_SetLow();
    }
    if (IO_RC0_GetValue() == 1){     //positive connector 1
        IO_RC0_SetLow();
    }
//    if (MOTOR_ON == 1){      //motor on pin
//        MOTOR_ON == LOW;
//    }
    if (IO_RC4_GetValue() == 1){     //negative connector 2
        IO_RC4_SetLow();
    }
    if (IO_RC1_GetValue()== 1){      //negative connector 1
        IO_RC1_SetLow();
    }
    if (IO_RA3_GetValue() == 1){       //ATI auxiliary
        IO_RA3_SetLow();
    }
    if (IO_RA2_GetValue() == 1){      //ATI DCDC
        IO_RA2_SetLow();
    }
    if (highOrlow(IO_RE1_GetValue()) == 1){     //read DCDC
        IO_RE1_SetLow();
    }
    if (IO_RA0_GetValue() == 1){ //hv on
        IO_RA0_SetLow();
    }
    if (highOrlow(IO_RA5_GetValue()) == 1){    //read AUX
        IO_RA5_SetLow();
    }
}

void start_up_seq(void){
    //Read pin 7
    if (highOrlow(IO_RA5_GetValue()) == 0){    //pin 7 - read aux
        break; 
    }
    else if (highOrlow(IO_RA5_GetValue()) == 1){
        IO_RA0_SetHigh(); //pin 2 - hv on
        IO_RE1_SetHigh(); //read dcdc - pin 9
        
        //Read pin 9 now -- checking HV line
        if (highOrlow(IO_RE1_GetValue()) == 1){
            IO_RA2_SetHigh(); //ati dcdc
            IO_RA3_SetHigh(); //ati aux
            IO_RC1_SetHigh(); //neg connector 1
            IO_RC4_SetHigh(); //neg connector 2
            __delay_ms(5); //sleep for 5ms between steps in this process
            
            IO_RC2_SetHigh(); //precharge 1
            IO_RC5_SetHigh(); //precharge 2
            __delay_ms(5);
            
            //Motor Controller Check
            if (canbus_motor_rearL(rx1)){
                if (rx1.frame.idType == 1 && rx1.frame.id == 0x08950225 && 
                    rx1.frame.dlc = 0x01 && rx1.frame.data0 = 0x00000001){
                if (canbus_motor_rearR(&rx2)){
                    if (rx2.frame.idType == 1 && rx2.frame.id == 0x08950245 &&
                        rx2.frame.dlc = 0x01 && rx2.frame.data0 = 0x00000001){
                if (canbus_motor_frontL(&rx3)){
                    if (rx3.frame.idType == 1 && rx3.frame.id == 0x08950265 &&
                        rx3.frame.dlc = 0x01 && rx3.frame.data0 = 0x00000001){
                if (canbus_motor_frontR(&rx4)){
                    if (rx4.frame.idType == 1 && rx4.frame.id == 0x08950285 &&
                        rx4.frame.dlc = 0x01 && rx4.frame.data0 = 0x00000001){
                            IO_RC0_SetHigh(); //pos connector 1
                            IO_RC3_SetHigh(); //pos connector 2
                            __delay_ms(10); //motor controller requires longer times in between steps to charge precharge

                                //why was the precharge turned on twice in the flowchart?
                //                IO_RC2_SetHigh(); //precharge 1
                //                IO_RC5_SetHigh(); //precharge 2
                                //__delay_ms(10);

                                //Verify MPPT here - not sure how we wanted to verify
                                //But if MPPT is working and on:
                                //Read pin 3 (the MPPT Contactor)
                                if (IO_RA1_GetValue() == 1){ //read mppt
                                    //success -- not sure if we want to do anything more here
                                    startup_success = 1; //startup sequence was successful 

                                }else{
                                    undo_seq();
                                    //Send MPPT Error message to DDISP
                                    canbus_msg_MPPT(1);
                                }
                            }
                            }
                        }
                        }
                    }
                    }
                }
                }else{
                undo_seq();
                //Send Motor Error message to DDISP
                canbus_msg_motor(1);
            }
        }else{
            undo_seq();
            //Send "START UP FAIL" to DDISP
            canbus_msg_startupfail(1);
        }
    }
}

void shutdown_seq(void){
    //Read pin 7 - MCU READ AUX
    if (highOrlow(IO_RA5_GetValue()) == 1){
        break;
    }else{
        //system turns off electronically?
        //Stores successful system shut-down somewhere
        canbus_shutdown_success(1); //transmits CANBUS with unique id ----> shutdown
    }
}

void e_stop_seq(void){
    //Read pin 9 - read dcdc
    if (startup_success == 1){ //e-stop can only run when startup is on
        if (highOrlow(IO_RE1_GetValue()) == 0){
        IO_RA3_SetLow();  //ati aux
        IO_RA2_SetLow(); //ati dcdc
        
        // send display message to DDISP as "BPS Fault"
        canbus_msg_bps(1);
        }  
    }
}

//Boundary Cases
void aux_battery_failure(void){
    //Read pin 7
    if (highOrlow(IO_RA5_GetValue()) == 0){ //pin 7 and pin 9 are analog inputs   -----> need to set as analog? 
        //Read pin 9
        if (highOrlow(IO_RE1_GetValue()) == 1){
            //Supplemental battery failure 
            //Display AUX Battery Failure on DDISP
            canbus_msg_auxfail(1);
        }else{
            break;
            //Means car is off
        }
    }
}

void aux_battery_LV(void){
    //Read pin 7
    if (IO_RA5_GetValue() < THRESVOLT){
        //send msg to DDISP -- LOW AUX VOLTAGE
        canbus_msg_auxlow(1);
    }
}
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    while (1){
        //call the functions 
        //if the boolean for startup is false (startup has not run yet), then run startup. Else, don't.
        if (startup_success == 0){
            start_up_seq();
        }
        if (shutdown_trigger == 1 && startup_success == 1){ //what should be triggering the shutdown? 
            shutdown_seq(); 
        }
        
        e_stop_seq(); //may need a boundary case for this
        //other boundary cases always being checked
        aux_battery_failure();
        aux_battery_LV();
        
        
    }
}
/**
 End of File
*/

//Questions:
//1) preload connector sequence?
//2) what should trigger the shutdown sequence? The e-stop? --> main function may be faulty
//3) what is the BPS fault CAN ID?
//4) not sure if CAN receive for motor status was called properly -- need to check 

