#include <xc.h>
#include "can_interface.h"

/*
 tx1 -> Right signal
 tx2 -> Left signal
 tx3 -> Hazard signal
 tx4 -> Front signal
 tx5 -> Back signal
 tx6 -> request signal for motor speed
 */

uCAN_MSG tx1, tx2, tx3, tx4, tx5, tx6;

void canRightSignal(int number){
	tx1.frame.idType = 1; //1 as we are using a standard ID
	tx1.frame.id = 0x62; //Arbitration ID;
	tx1.frame.dlc = 0x01; //dlc = "data length code"; How many BYTES of data you're sending in this case 8 bc 8 bytes 0->8
	tx1.frame.data0 = number;
	CAN_transmit(&tx1);
}

void canLeftSignal(int number){
	tx2.frame.idType = 1; //1 as we are using a standard ID
	tx2.frame.id = 0x63; //Arbitration ID;
	tx2.frame.dlc = 0x01; //dlc = "data length code"; How many BYTES of data you're sending in this case 8 bc 8 bytes 0->8
	tx2.frame.data0 = number;
	CAN_transmit(&tx2);
}

void canHazardSignal(int number){
	tx3.frame.idType = 1; //1 as we are using a standard ID
	tx3.frame.id = 0x61; //Arbitration ID;
	tx3.frame.dlc = 0x01; //dlc = "data length code"; How many BYTES of data you're sending in this case 8 bc 8 bytes 0->8
	tx3.frame.data0 = number;
	CAN_transmit(&tx3);
}

void canFrontSignal(int number){
	tx4.frame.idType = 1; //1 as we are using a standard ID
	tx4.frame.id = 0x64; //Arbitration ID;
	tx4.frame.dlc = 0x01; //dlc = "data length code"; How many BYTES of data you're sending in this case 8 bc 8 bytes 0->8
	tx4.frame.data0 = number;
	CAN_transmit(&tx4);
}

void canBackSignal(int number){
	tx5.frame.idType = 1; //1 as we are using a standard ID
	tx5.frame.id = 0x66; //Arbitration ID;
	tx5.frame.dlc = 0x01; //dlc = "data length code"; How many BYTES of data you're sending in this case 8 bc 8 bytes 0->8
	tx5.frame.data0 = number;
	CAN_transmit(&tx5);
}

void requestSpeed(int number){
	tx6.frame.idType = 1; //1 as we are using a standard ID
	tx6.frame.id = 0x05; //Arbitration ID;
	tx6.frame.dlc = 0x01; //dlc = "data length code"; How many BYTES of data you're sending in this case 8 bc 8 bytes 0->8
	tx6.frame.data0 = number;
	CAN_transmit(&tx6);
}
