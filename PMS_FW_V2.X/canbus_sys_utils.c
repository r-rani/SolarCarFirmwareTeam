#include <xc.h>
#include "canbus_sys_utils.h"
#include "mcc_generated_files/mcc.h"

uCAN_MSG rx, tx;

void canbusSend(int id,int data){
    tx.frame.idType = 1; //1 as we are using a standard ID
	tx.frame.id = id; //Arbitration ID;
	tx.frame.dlc = 0x01; //dlc = "data length code"; How many BYTES of data you're sending in this case 8 bc 8 bytes 0->8
	tx.frame.data0 = data;
	CAN_transmit(&tx);
}

