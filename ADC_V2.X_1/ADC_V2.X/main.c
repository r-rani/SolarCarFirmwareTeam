#include "mcc_generated_files/mcc.h"
#include "canbus_sys_utils.h"

void main(void)
{
    SYSTEM_Initialize();

    while (1){
        int anoValue = ADC_GetConversion(potA0);
        canbusSend(RIGHT_SIGNAL,anoValue);
        LED_SetHigh();
        __delay_ms(10);
    }
}
