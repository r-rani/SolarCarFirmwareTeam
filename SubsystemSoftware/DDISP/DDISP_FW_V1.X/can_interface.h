#ifndef CAN_INTERFACE_H
#define	CAN_INTERFACE_H

#include <xc.h>
#include "mcc_generated_files/mcc.h"

void canRightSignal(int number);
void canLeftSignal(int number);
void canHazardSignal(int number);
void canFrontSignal(int number);
void canBackSignal(int number);

#endif

