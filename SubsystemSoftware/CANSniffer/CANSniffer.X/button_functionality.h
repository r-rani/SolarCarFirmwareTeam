#ifndef BUTTON_FUNCTIONALITY_H
#define	BUTTON_FUNCTIONALITY_H

#include "mcc_generated_files/mcc.h"
#include "xc.h"

int enterExitButtons(int);
int updateEncoder(int*,int*,int);

int enterButtonGetValue();
int exitButtonGetValue();

#endif

