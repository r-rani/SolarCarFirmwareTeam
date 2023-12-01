#include <xc.h>
#include "mcc_generated_files/mcc.h"
#include "canbus_sys_utils.h"

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

#define canbus_msg_startupfail_msg 0x122
#define canbus_msg_bps_msg 0x12
#define canbus_msg_auxfail_msg 0x121
#define canbus_msg_auxlow_msg 0x123
#define canbus_shutdown_success_msg 0x18
#define canbus_msg_startup_success_msg 0x22
#define canbus_msg_ok_msg 0x111
#define canbus_latch_shutdown_msg 0x17
#define start_shutdown 0x255

static float THRESVOLT = 10.2; //10.2V - actual should be 12V, but 10.2V due to ADC module
static int STARTUP_SUCCESS = 0; //boolean for startup process success
static int iterator = 0; //motor while loop iterator 

uCAN_MSG rx, tx21, tx20; //initializations for transmit and receive messages

int ADC_Conv_pinSeven(){
    //int adc_val = ADC_GetConversion(channel_AN4);
    int adc_val= IO_RA5_GetValue();
    return adc_val;
    float input_voltage = (float)((adc_val / 4095.0)*5.0); //10 bit adc , 5V= reference voltage
    //int voltage = (int)input_voltage;
    tx21.frame.id = 0x1;
    tx21.frame.idType = 0x1;
    tx21.frame.dlc = 0x1;
    tx21.frame.data0 = input_voltage;
//    CAN_transmit(&tx21);
    //canbusSend(0x1,(int)((adc_val / 4095.0)*5.0));
    
    
    if (input_voltage >= 3.4){
        return 1;
    }
    else{
        return 1; //debug
    }
}

int ADC_Conv_pinNine(){
    int adc_val= IO_RE1_GetValue();
    return adc_val;
    //float adc_val = ADC_GetConversion(channel_AN6);
    //adc_val = ((adc_val / 4095.0)*5.0); //12 bit adc , 5V= reference voltage
    //int input_voltage = (int)adc_val;
    //int voltage = (int)input_voltage;
    tx20.frame.id = 0x2;
    tx20.frame.idType = 0x1;
    tx20.frame.dlc = 0x1;
    tx20.frame.data0 = (int)((adc_val / 4095.0)*5.0);
//    CAN_transmit(&tx20);
    //canbusSend(0x2,(int)((adc_val / 4095.0)*5.0));
    if (((adc_val / 4095.0)*5.0) >= 4){
        return 1;
    }
    else{
        return 0;
    }
}

//START UP FAIL DDISP
void canbus_msg_startupfail(int number){
    canbusSend(canbus_msg_startupfail_msg,number);
}

//BPS Fault DDISP
void canbus_msg_bps(int number){
    canbusSend(canbus_msg_bps_msg,number);
}

//AUX battery failure DDISP
void canbus_msg_auxfail(int number){
    canbusSend(canbus_msg_auxfail_msg,number);
}

//AUX line low voltage DDISP
void canbus_msg_auxlow(int number){
    canbusSend(canbus_msg_auxlow_msg,number);
}

//CANBUS shutdown sequence success message
void canbus_shutdown_success(int number){
    canbusSend(canbus_shutdown_success_msg,number);
}

void canbus_msg_startup_success(int number){
    canbusSend(canbus_msg_startup_success_msg,number);
}

void canbus_msg_ok(int number){
    canbusSend(canbus_msg_ok_msg,number); 
}

void canbus_latch_shutdown(int number){
    canbusSend(canbus_latch_shutdown_msg,number);
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
            canbus_msg_startup_success(1);
        }
        else{
            IO_RC0_SetLow();
            IO_RC1_SetLow();
            //ERROR 2
            canbus_msg_startupfail(1);
            __delay_ms(200);
            canbus_latch_shutdown(1);
            
        }   
    }
    else{
        __delay_ms(5000);
        //ERROR 1
        canbus_msg_auxlow(1);
        __delay_ms(200);
        canbus_latch_shutdown(1);
    }
}

void shutdown_seq(void){
    canbus_shutdown_success(1); //transmits CANBUS with unique id ----> shutdown
}

void e_stop_seq(void){
    canbus_msg_bps(1);
    IO_RA3_SetLow();  //ati aux
    IO_RA2_SetLow(); //ati dcdc
}

void aux_battery_LV(void){
    canbus_msg_auxlow(1);
}

void main(void){
    // Initialize the device
    SYSTEM_Initialize();
    int iter = 0;
    while (1){
        if (STARTUP_SUCCESS == 0){
                start_up_seq();
        }
        else{
            if (CAN_receive(&rx)){
                if (rx.frame.idType == 1){
                    if (rx.frame.id == start_shutdown){
                        shutdown_seq();
                    }
                }
            }
            if (ADC_Conv_pinSeven() == 0){   //AUX low
                aux_battery_LV();
            }
            if (ADC_Conv_pinNine() == 0){ //DCDC low
                e_stop_seq();
            }
            if (iter >= 10000){
                canbus_msg_ok(1);
                __delay_ms(1000);
                iter = 0;
            }
        }
        
        iter += 1;
    }
 }