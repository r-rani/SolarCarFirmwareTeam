#include <xc.h>
#include "uart_interface.h"

void leftTurnIndicator(int value){//userLED0
    int v1=1,v2=19,v3=0,v4=0;
    int checksum = v1^v2^v3^v4^value; 
    
    EUSART1_Write(v1);
    __delay_ms(10);
    EUSART1_Write(v2);
    __delay_ms(10);
    EUSART1_Write(v3);
    __delay_ms(10);
    EUSART1_Write(v4);        
    __delay_ms(10);
    EUSART1_Write(value);//Data In Int
    __delay_ms(10);
    EUSART1_Write(checksum);//Checksum
}
void rightTurnIndicator(int value){//userLED1
    int v1=1,v2=19,v3=1,v4=0;
    int checksum = v1^v2^v3^v4^value; 
    
    EUSART1_Write(v1);
    __delay_ms(10);
    EUSART1_Write(v2);
    __delay_ms(10);
    EUSART1_Write(v3);
    __delay_ms(10);
    EUSART1_Write(v4);        
    __delay_ms(10);
    EUSART1_Write(value);//Data In Int
    __delay_ms(10);
    EUSART1_Write(checksum);//Checksum
}
void warningLED1(int value){//iMediaLED1
    int v1=1,v2=46,v3=0,v4=0;
    int checksum = v1^v2^v3^v4^value; 
    
    EUSART1_Write(v1);
    __delay_ms(10);
    EUSART1_Write(v2);
    __delay_ms(10);
    EUSART1_Write(v3);
    __delay_ms(10);
    EUSART1_Write(v4);        
    __delay_ms(10);
    EUSART1_Write(value);//Data In Int
    __delay_ms(10);
    EUSART1_Write(checksum);//Checksum
}
void warningLED2(int value){//iMediaLED2
    int v1=1,v2=46,v3=1,v4=0;
    int checksum = v1^v2^v3^v4^value; 
    
    EUSART1_Write(v1);
    __delay_ms(10);
    EUSART1_Write(v2);
    __delay_ms(10);
    EUSART1_Write(v3);
    __delay_ms(10);
    EUSART1_Write(v4);        
    __delay_ms(10);
    EUSART1_Write(value);//Data In Int
    __delay_ms(10);
    EUSART1_Write(checksum);//Checksum
}
void motorSpeed(int value){//ledDigits0////////////////////////////NEEDS WORK
    int v1=1,v2=15,v3=0,v4=0;
//    int value1
//    int value2
    
    int checksum = v1^v2^v3^v4^value; 
    
    EUSART1_Write(v1);
    __delay_ms(10);
    EUSART1_Write(v2);
    __delay_ms(10);
    EUSART1_Write(v3);
    __delay_ms(10);
    EUSART1_Write(v4);        
    __delay_ms(10);
    EUSART1_Write(value);//Data In Int
    __delay_ms(10);
    EUSART1_Write(checksum);//Checksum
}
void motorControlerTemp(int value){//ledDigits1
    int v1=1,v2=15,v3=1,v4=0;
    int checksum = v1^v2^v3^v4^value; 
    
    EUSART1_Write(v1);
    __delay_ms(10);
    EUSART1_Write(v2);
    __delay_ms(10);
    EUSART1_Write(v3);
    __delay_ms(10);
    EUSART1_Write(v4);        
    __delay_ms(10);
    EUSART1_Write(value);//Data In Int
    __delay_ms(10);
    EUSART1_Write(checksum);//Checksum
}
void batteryTemp(int value){//ledDigits2
    int v1=1,v2=23,v3=0;
    int checksum = v1^v2^v3^value; 
    
    EUSART1_Write(v1);
    __delay_ms(10);
    EUSART1_Write(v2);
    __delay_ms(10);
    EUSART1_Write(v3);
    __delay_ms(10);
    EUSART1_Write(value);//Data In Int
    __delay_ms(10);
    EUSART1_Write(checksum);//Checksum    
}
void hazardSignal(int value){//userLed2
    int v1=1,v2=13,v3=0;
    int checksum = v1^v2^v3^value; 
    
    EUSART1_Write(v1);
    __delay_ms(10);
    EUSART1_Write(v2);
    __delay_ms(10);
    EUSART1_Write(v3);
    __delay_ms(10);
    EUSART1_Write(value);//Data In Int
    __delay_ms(10);
    EUSART1_Write(checksum);//Checksum      
}
void batterySOC(int value){//ledDigits3 In percent
    int v1=1,v2=31,v3=0,v4=0;
    int checksum = v1^v2^v3^v4^value; 
    
    EUSART1_Write(v1);
    __delay_ms(10);
    EUSART1_Write(v2);
    __delay_ms(10);
    EUSART1_Write(v3);
    __delay_ms(10);
    EUSART1_Write(v4);        
    __delay_ms(10);
    EUSART1_Write(value);//Data In Int
    __delay_ms(10);
    EUSART1_Write(checksum);//Checksum    
}
void batterySOCGraphic(int value){//socGauge
    int v1=1,v2=31,v3=1,v4=0;
    int checksum = v1^v2^v3^v4^value; 
    
    EUSART1_Write(v1);
    __delay_ms(10);
    EUSART1_Write(v2);
    __delay_ms(10);
    EUSART1_Write(v3);
    __delay_ms(10);
    EUSART1_Write(v4);        
    __delay_ms(10);
    EUSART1_Write(value);//Data In Int
    __delay_ms(10);
    EUSART1_Write(checksum);//Checksum    
}
