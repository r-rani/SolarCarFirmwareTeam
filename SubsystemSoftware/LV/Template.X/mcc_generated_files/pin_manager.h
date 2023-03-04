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

// get/set HazardSignal aliases
#define HazardSignal_TRIS                 TRISAbits.TRISA2
#define HazardSignal_LAT                  LATAbits.LATA2
#define HazardSignal_PORT                 PORTAbits.RA2
#define HazardSignal_ANS                  ANCON0bits.ANSEL2
#define HazardSignal_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define HazardSignal_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define HazardSignal_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define HazardSignal_GetValue()           PORTAbits.RA2
#define HazardSignal_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define HazardSignal_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define HazardSignal_SetAnalogMode()      do { ANCON0bits.ANSEL2 = 1; } while(0)
#define HazardSignal_SetDigitalMode()     do { ANCON0bits.ANSEL2 = 0; } while(0)

// get/set RightSignal aliases
#define RightSignal_TRIS                 TRISAbits.TRISA3
#define RightSignal_LAT                  LATAbits.LATA3
#define RightSignal_PORT                 PORTAbits.RA3
#define RightSignal_ANS                  ANCON0bits.ANSEL3
#define RightSignal_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define RightSignal_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define RightSignal_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define RightSignal_GetValue()           PORTAbits.RA3
#define RightSignal_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define RightSignal_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define RightSignal_SetAnalogMode()      do { ANCON0bits.ANSEL3 = 1; } while(0)
#define RightSignal_SetDigitalMode()     do { ANCON0bits.ANSEL3 = 0; } while(0)

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

// get/set BPSFault aliases
#define BPSFault_TRIS                 TRISDbits.TRISD0
#define BPSFault_LAT                  LATDbits.LATD0
#define BPSFault_PORT                 PORTDbits.RD0
#define BPSFault_ANS                  ANCON1bits.ANSEL11
#define BPSFault_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define BPSFault_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define BPSFault_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define BPSFault_GetValue()           PORTDbits.RD0
#define BPSFault_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define BPSFault_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define BPSFault_SetAnalogMode()      do { ANCON1bits.ANSEL11 = 1; } while(0)
#define BPSFault_SetDigitalMode()     do { ANCON1bits.ANSEL11 = 0; } while(0)

// get/set LeftSignal aliases
#define LeftSignal_TRIS                 TRISEbits.TRISE0
#define LeftSignal_LAT                  LATEbits.LATE0
#define LeftSignal_PORT                 PORTEbits.RE0
#define LeftSignal_ANS                  ANCON0bits.ANSEL5
#define LeftSignal_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define LeftSignal_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define LeftSignal_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define LeftSignal_GetValue()           PORTEbits.RE0
#define LeftSignal_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define LeftSignal_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define LeftSignal_SetAnalogMode()      do { ANCON0bits.ANSEL5 = 1; } while(0)
#define LeftSignal_SetDigitalMode()     do { ANCON0bits.ANSEL5 = 0; } while(0)

// get/set FrontSignal aliases
#define FrontSignal_TRIS                 TRISEbits.TRISE1
#define FrontSignal_LAT                  LATEbits.LATE1
#define FrontSignal_PORT                 PORTEbits.RE1
#define FrontSignal_ANS                  ANCON0bits.ANSEL6
#define FrontSignal_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define FrontSignal_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define FrontSignal_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define FrontSignal_GetValue()           PORTEbits.RE1
#define FrontSignal_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define FrontSignal_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define FrontSignal_SetAnalogMode()      do { ANCON0bits.ANSEL6 = 1; } while(0)
#define FrontSignal_SetDigitalMode()     do { ANCON0bits.ANSEL6 = 0; } while(0)

// get/set BackSignal aliases
#define BackSignal_TRIS                 TRISEbits.TRISE2
#define BackSignal_LAT                  LATEbits.LATE2
#define BackSignal_PORT                 PORTEbits.RE2
#define BackSignal_ANS                  ANCON0bits.ANSEL7
#define BackSignal_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define BackSignal_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define BackSignal_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define BackSignal_GetValue()           PORTEbits.RE2
#define BackSignal_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define BackSignal_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define BackSignal_SetAnalogMode()      do { ANCON0bits.ANSEL7 = 1; } while(0)
#define BackSignal_SetDigitalMode()     do { ANCON0bits.ANSEL7 = 0; } while(0)

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