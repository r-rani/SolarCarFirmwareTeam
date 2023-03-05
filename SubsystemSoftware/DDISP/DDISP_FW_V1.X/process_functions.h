#ifndef PROCESS_FUNCTIONS_H
#define	PROCESS_FUNCTIONS_H

#include <xc.h>
#include "mcc_generated_files/mcc.h"
#include "uart_interface.h"

void processRuntime(int,int,int);
void leftTurnSignal(int);
void rightTurnSignal(int);
void hazardTurnSignal(int);

#endif

