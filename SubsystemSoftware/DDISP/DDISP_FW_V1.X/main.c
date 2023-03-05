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

///////////////////////////////////CANBUS STUFF
uCAN_MSG tx1, tx2, tx3, tx4, tx5, rx1, rx2;

/*
 tx1 -> Right signal
 tx2 -> Left signal
 tx3 -> Hazard signal
 tx4 -> Front signal
 tx5 -> Back signal
 rx1 -> Battery Temp
 rx2 -> Battery SOC
 */

void canRightSignal(int number){
	tx1.frame.idType = 1; //1 as we are using a standard ID
	tx1.frame.id = 0x02; //Arbitration ID;
	tx1.frame.dlc = 0x01; //dlc = "data length code"; How many BYTES of data you're sending in this case 8 bc 8 bytes 0->8
	tx1.frame.data0 = number;
	CAN_transmit(&tx1);
}

void canLeftSignal(int number){
	tx2.frame.idType = 1; //1 as we are using a standard ID
	tx2.frame.id = 0x03; //Arbitration ID;
	tx2.frame.dlc = 0x01; //dlc = "data length code"; How many BYTES of data you're sending in this case 8 bc 8 bytes 0->8
	tx2.frame.data0 = number;
	CAN_transmit(&tx2);
}

void canHazardSignal(int number){
	tx3.frame.idType = 1; //1 as we are using a standard ID
	tx3.frame.id = 0x01; //Arbitration ID;
	tx3.frame.dlc = 0x01; //dlc = "data length code"; How many BYTES of data you're sending in this case 8 bc 8 bytes 0->8
	tx3.frame.data0 = number;
	CAN_transmit(&tx3);
}

void canFrontSignal(int number){
	tx4.frame.idType = 1; //1 as we are using a standard ID
	tx4.frame.id = 0x04; //Arbitration ID;
	tx4.frame.dlc = 0x01; //dlc = "data length code"; How many BYTES of data you're sending in this case 8 bc 8 bytes 0->8
	tx4.frame.data0 = number;
	CAN_transmit(&tx4);
}

void canBackSignal(int number){
	tx5.frame.idType = 1; //1 as we are using a standard ID
	tx5.frame.id = 0x05; //Arbitration ID;
	tx5.frame.dlc = 0x01; //dlc = "data length code"; How many BYTES of data you're sending in this case 8 bc 8 bytes 0->8
	tx5.frame.data0 = number;
	CAN_transmit(&tx5);
}

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
        canRightSignal(1);
        canLeftSignal(0);
        __delay_ms(1000);
        canRightSignal(0);
        canLeftSignal(1);
        __delay_ms(1000);
        
        
        
        /*if (CAN_receive(&rx1)){
         if (rx1.frame.idType == 1){
             if (rx1.frame.id == ID){
                __delay_ms(1);*/
             }
        //buttonRuntime(&b1FuncActive,&b10FuncActive);
        //processRuntime(b1FuncActive, b10FuncActive, b2FuncActive);
        //__delay_ms(10);
    }
}
