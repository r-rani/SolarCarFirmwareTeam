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

static float THRESVOLT = 10.2; //10.2V - actual should be 12V, but 10.2V due to ADC module
static int STARTUP_SUCCESS = 0; //boolean for startup process success
static int iterator = 0; //motor while loop iterator 

uCAN_MSG rx, tx1, tx2, tx3, tx4, tx5, tx6, tx7, tx8,tx9,tx10,tx13,tx20,tx21; //initializations for transmit and receive messages

int highOrlow(float voltage){
    int output;
    if (voltage >= 10.2) {
        output = 1;
    }
    else{
        output = 0;
    }
    return output;
}

int ADC_Conv_pinSeven(){
    float adc_val = ADC_GetConversion(channel_AN4);
    adc_val = (adc_val / 1023.0)*5.0; //10 bit adc , 5V= reference voltage
    float input_voltage = adc_val*3.0;
    if (input_voltage >= 10.2){
        return 1;
    }
    else{
        return 0;
    }
}

int ADC_Conv_pinNine(){
    float adc_val = ADC_GetConversion(channel_AN6);
    adc_val = (adc_val / 1023.0)*5.0; //10 bit adc , 5V= reference voltage
    float input_voltage = adc_val*3.0;
    if (input_voltage >= 12){
        return 1;
    }
    else{
        return 0;
    }
    

}
//create a function for each DDISP message

//START UP FAIL DDISP
void canbus_msg_startupfail(int number){
    tx3.frame.idType = 1;
    tx3.frame.id = 0x3; //Arbitration ID
    tx3.frame.dlc = 0x01; //1 byte
    tx3.frame.data0 = number;
    CAN_transmit(&tx3);
}

//BPS Fault DDISP
void canbus_msg_bps(int number){
    tx4.frame.idType = 1;
    tx4.frame.id = 0x4; //Arbitration ID
    tx4.frame.dlc = 0x01; //1 byte
    tx4.frame.data0 = number;
    CAN_transmit(&tx4);
}

//AUX battery failure DDISP
void canbus_msg_auxfail(int number){
    tx5.frame.idType = 1;
    tx5.frame.id = 0x9; //Arbitration ID
    tx5.frame.dlc = 0x01; //1 byte
    tx5.frame.data0 = number;
    CAN_transmit(&tx5);
}

//AUX line low voltage DDISP
void canbus_msg_auxlow(int number){
    tx6.frame.idType = 1;
    tx6.frame.id = 0x5; //Arbitration ID
    tx6.frame.dlc = 0x01; //1 byte
    tx6.frame.data0 = number;
    CAN_transmit(&tx6);
}

//CANBUS shutdown sequence success message
void canbus_shutdown_success(int number){
    tx7.frame.idType = 1;
    tx7.frame.id = 0x18; //Arbitration ID
    tx7.frame.dlc = 0x01; //1 byte
    tx7.frame.data0 = number;  //power mode
    CAN_transmit(&tx7);
}

void canbus_latch_shutdown(int number){
    tx8.frame.idType = 1;
    tx8.frame.id = 0x17;
    tx8.frame.dlc = 0x01;
    tx8.frame.data0 = number;
    CAN_transmit(&tx8);
}

void start_up_seq(void){
    //Read pin 7
    if (ADC_Conv_pinSeven() == 1){
        IO_RC1_SetHigh(); //pin 2 - hv on
        IO_RC2_SetHigh(); //Set pin 25 high
        __delay_ms(1000);
        IO_RC0_SetHigh();
        IO_RC2_SetLow();
        IO_RC6_SetHigh();
        //Read pin 9 now -- checking HV line
        //if (highOrlow(IO_RE1_GetValue()) == 1){
        if (ADC_Conv_pinNine() == 1){
            IO_RA2_SetHigh(); //ati dcdc
            IO_RA3_SetHigh(); //ati aux
            STARTUP_SUCCESS = 1;
        }
        else{
            IO_RC0_SetLow();
            IO_RC1_SetLow();
            //ERROR 2
            canbus_msg_startupfail(1);
            canbus_latch_shutdown(1);
            
        }   
    }
    else{
        __delay_ms(5000);
        //ERROR 1
        canbus_msg_auxlow(1);
        canbus_latch_shutdown(1);
    }
}

//void shutdown_seq(void){
//    //Read pin 7 - MCU READ AUX
//   // if (ADC_Conv_pinSeven() == 0){ 
//        //system turns off electronically?
//        //Stores successful system shut-down somewhere
//    canbus_shutdown_success(1); //transmits CANBUS with unique id ----> shutdown
//    //}
//    //canbus_shutdown_success(1);
//}

void e_stop_seq(void){
        canbus_msg_bps(1);
        IO_RA3_SetLow();  //ati aux
        IO_RA2_SetLow(); //ati dcdc
}

void aux_battery_LV(void){
    //Read pin 7
    //if (IO_RA5_GetValue() < THRESVOLT){
    if (ADC_Conv_pinSeven() != 1){

        //send msg to DDISP -- LOW AUX VOLTAGE
        canbus_msg_auxlow(1);
    }
}

void main(void){
    // Initialize the device
    SYSTEM_Initialize();
    STARTUP_SUCCESS = 0;

    while (1){
        //call the functions 
        //if the boolean for startup is false (startup has not run yet), then run startup. Else, don't.
        //pins 7 and 9 should constantly be monitored
        tx21.frame.idType = 1;
        tx21.frame.id = 0x39;
        tx21.frame.dlc = 1;
        tx21.frame.data0 = ADC_Conv_pinNine();
        CAN_transmit(&tx21);
        if (STARTUP_SUCCESS == 0){
                start_up_seq();
            }
        else{
            if (ADC_Conv_pinSeven() == 0){   //AUX low
                canbus_shutdown_success(1);
                STARTUP_SUCCESS = 0;
            }
            else if (ADC_Conv_pinNine() == 0){ //DCDC low
                e_stop_seq();
            }
        } 
        //aux_battery_LV();
    }
 }


//Questions:
//1) preload connector sequence?
//2) what should trigger the shutdown sequence? The e-stop? --> main function may be faulty
//3) what is the BPS fault CAN ID?
//4) not sure if CAN receive for motor status was called properly -- need to check 

