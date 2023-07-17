#include <xc.h>
#include <time.h>
#include <stdio.h>
#include "mcc_generated_files/mcc.h"

uCAN_MSG tx1, tx2, tx3, tx4, tx5;

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

void main(void)
{
    
    SYSTEM_Initialize();
    
    
    
    while (1)
    {
        canFrontSignal(1);
        __delay_ms(5000);
        canFrontSignal(1);
        canBackSignal(1);
        __delay_ms(5000);
        canBackSignal(1);
        canLeftSignal(1);
        __delay_ms(5000);
        canLeftSignal(1);
        canRightSignal(1);
        __delay_ms(5000);
        canRightSignal(1);
        canHazardSignal(1);
        __delay_ms(5000);
        canHazardSignal(1);
        
        /*
        if (CAN_receive(&rx1)){
            if (rx1.frame.idType == 1){
                if (rx1.frame.id == 0x02F4){
                   IO_RD2_Toggle(); //BATT_ST, yellow
                   __delay_ms(1);
                }
                else if (rx1.frame.id == 0x04F4){
                   IO_RD3_Toggle(); //CELL_VOLT, green
                   __delay_ms(1);
                }
                else if (rx1.frame.id == 0x05F4){
                   IO_RD0_Toggle(); //CELL_TEMP, blue
                   __delay_ms(1);
                }
                else if (rx1.frame.id == 0x07F4){
                   IO_RD1_Toggle(); //ALM_INFO, red
                   __delay_ms(1);
                }
            }
        }
       */
    }
}
/**
 End of File
*/