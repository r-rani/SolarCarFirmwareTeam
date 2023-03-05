/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F46K80
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set Button1 aliases
#define Button1_TRIS                 TRISAbits.TRISA0
#define Button1_LAT                  LATAbits.LATA0
#define Button1_PORT                 PORTAbits.RA0
#define Button1_ANS                  ANCON0bits.ANSEL0
#define Button1_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define Button1_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define Button1_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define Button1_GetValue()           PORTAbits.RA0
#define Button1_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define Button1_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define Button1_SetAnalogMode()      do { ANCON0bits.ANSEL0 = 1; } while(0)
#define Button1_SetDigitalMode()     do { ANCON0bits.ANSEL0 = 0; } while(0)

// get/set Button2 aliases
#define Button2_TRIS                 TRISAbits.TRISA1
#define Button2_LAT                  LATAbits.LATA1
#define Button2_PORT                 PORTAbits.RA1
#define Button2_ANS                  ANCON0bits.ANSEL1
#define Button2_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define Button2_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define Button2_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define Button2_GetValue()           PORTAbits.RA1
#define Button2_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define Button2_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define Button2_SetAnalogMode()      do { ANCON0bits.ANSEL1 = 1; } while(0)
#define Button2_SetDigitalMode()     do { ANCON0bits.ANSEL1 = 0; } while(0)

// get/set Button3 aliases
#define Button3_TRIS                 TRISAbits.TRISA2
#define Button3_LAT                  LATAbits.LATA2
#define Button3_PORT                 PORTAbits.RA2
#define Button3_ANS                  ANCON0bits.ANSEL2
#define Button3_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define Button3_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define Button3_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define Button3_GetValue()           PORTAbits.RA2
#define Button3_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define Button3_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define Button3_SetAnalogMode()      do { ANCON0bits.ANSEL2 = 1; } while(0)
#define Button3_SetDigitalMode()     do { ANCON0bits.ANSEL2 = 0; } while(0)

// get/set Button4 aliases
#define Button4_TRIS                 TRISAbits.TRISA3
#define Button4_LAT                  LATAbits.LATA3
#define Button4_PORT                 PORTAbits.RA3
#define Button4_ANS                  ANCON0bits.ANSEL3
#define Button4_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define Button4_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define Button4_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define Button4_GetValue()           PORTAbits.RA3
#define Button4_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define Button4_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define Button4_SetAnalogMode()      do { ANCON0bits.ANSEL3 = 1; } while(0)
#define Button4_SetDigitalMode()     do { ANCON0bits.ANSEL3 = 0; } while(0)

// get/set LED1 aliases
#define LED1_TRIS                 TRISAbits.TRISA5
#define LED1_LAT                  LATAbits.LATA5
#define LED1_PORT                 PORTAbits.RA5
#define LED1_ANS                  ANCON0bits.ANSEL4
#define LED1_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define LED1_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define LED1_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define LED1_GetValue()           PORTAbits.RA5
#define LED1_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define LED1_SetAnalogMode()      do { ANCON0bits.ANSEL4 = 1; } while(0)
#define LED1_SetDigitalMode()     do { ANCON0bits.ANSEL4 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)

// get/set RB3 procedures
#define RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_GetValue()              PORTBbits.RB3
#define RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_SetPullup()             do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_ResetPullup()           do { WPUBbits.WPUB3 = 0; } while(0)

// get/set Button9 aliases
#define Button9_TRIS                 TRISCbits.TRISC0
#define Button9_LAT                  LATCbits.LATC0
#define Button9_PORT                 PORTCbits.RC0
#define Button9_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define Button9_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define Button9_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define Button9_GetValue()           PORTCbits.RC0
#define Button9_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define Button9_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)

// get/set Button10 aliases
#define Button10_TRIS                 TRISCbits.TRISC1
#define Button10_LAT                  LATCbits.LATC1
#define Button10_PORT                 PORTCbits.RC1
#define Button10_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define Button10_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define Button10_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define Button10_GetValue()           PORTCbits.RC1
#define Button10_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define Button10_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set Button8 aliases
#define Button8_TRIS                 TRISCbits.TRISC2
#define Button8_LAT                  LATCbits.LATC2
#define Button8_PORT                 PORTCbits.RC2
#define Button8_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define Button8_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define Button8_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define Button8_GetValue()           PORTCbits.RC2
#define Button8_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define Button8_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)

// get/set Button7 aliases
#define Button7_TRIS                 TRISCbits.TRISC3
#define Button7_LAT                  LATCbits.LATC3
#define Button7_PORT                 PORTCbits.RC3
#define Button7_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define Button7_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define Button7_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define Button7_GetValue()           PORTCbits.RC3
#define Button7_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define Button7_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)

// get/set Button6 aliases
#define Button6_TRIS                 TRISDbits.TRISD0
#define Button6_LAT                  LATDbits.LATD0
#define Button6_PORT                 PORTDbits.RD0
#define Button6_ANS                  ANCON1bits.ANSEL11
#define Button6_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define Button6_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define Button6_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define Button6_GetValue()           PORTDbits.RD0
#define Button6_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define Button6_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define Button6_SetAnalogMode()      do { ANCON1bits.ANSEL11 = 1; } while(0)
#define Button6_SetDigitalMode()     do { ANCON1bits.ANSEL11 = 0; } while(0)

// get/set Button5 aliases
#define Button5_TRIS                 TRISDbits.TRISD1
#define Button5_LAT                  LATDbits.LATD1
#define Button5_PORT                 PORTDbits.RD1
#define Button5_ANS                  ANCON1bits.ANSEL12
#define Button5_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define Button5_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define Button5_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define Button5_GetValue()           PORTDbits.RD1
#define Button5_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define Button5_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define Button5_SetAnalogMode()      do { ANCON1bits.ANSEL12 = 1; } while(0)
#define Button5_SetDigitalMode()     do { ANCON1bits.ANSEL12 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/