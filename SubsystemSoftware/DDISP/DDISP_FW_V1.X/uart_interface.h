#ifndef UART_INTERFACE_H
#define	UART_INTERFACE_H

#include <xc.h>
#include "mcc_generated_files/mcc.h"

//Uart Communication functions
void leftTurnIndicator(int);//userLED0
void rightTurnIndicator(int);//userLED1
void warningLED1(int);//iMediaLED1
void warningLED2(int);//iMediaLED2
void motorSpeed(int);//ledDigits0
void motorControlerTemp(int);//ledDigits1
void batteryTemp(int);//ledDigits2
void batterySOC(int);//ledDigits3 In percent
void hazardSignal(int);//userLed2
void batterySOCGraphic(int);//socGauge

#endif

