/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F46K80
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */

/*
 Global variables
 */
int latchOn; //0 if the latch is open/off, 1 if the latch is closed/on

uCAN_MSG rx, tx;

/*
 Functions
 */


void startup(void){
    if (RB3_GetValue() == 1){ //check if 5V received on interrupt pin 36
        RB1_SetHigh(); //set pin 20 high
        
        //transmit via CAN that AUX power is now live
        //start up message - id=0x31, dlc=0x1, data0=1
        tx.frame.idType = 1;
        tx.frame.id = 0x31;
        tx.frame.dlc = 0x1;
        tx.frame.data0 = 1;
        CAN_transmit(&tx);
        
        latchOn == 1; //set start up flag to true        
    }
}

//also need to tx startup message on 0x31



void shutdown(void){    //shutdown the latch if CAN shutdown message received
    //NEEDS TO TX CAN MSG WHEN SHUTTING DOWN - ID 0x255 (tentative)
    if (latchOn == 1){
        IO_RD1_SetLow();    //set pin 20 low
        latchOn = 0;
    }
}

void shutdown_normal(void){
    //If statement to check if 5V is measured at pin 36
    if (RB3_GetValue() == 1){
       // If statement to check status of start-up flag
        if (latchOn == 1){
            IO_RD1_SetLow(); //set pin 20 low
            latchOn = 0; // Changing start-up flag to False(0)
        } 
    } 
    
}

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    while (1)
    {
        if(CAN_receive(&rx)){   //if received a CAN msg, shutdown
            if(rx.frame.idType == 1){
                shutdown();
            }
        }
        //CAN shutdown- check if message received from PMS
        
    }
}
/**
 End of File
*/