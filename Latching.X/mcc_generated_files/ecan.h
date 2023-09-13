/**
  CAN Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    can.h

  @Summary
    This is the generated header file for the ECAN driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs driver for CAN.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F46K80
        Driver Version    :  2.12.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00
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

#ifndef ECAN_H
#define ECAN_H

/**
  Section: Included Files
*/

#include <stdbool.h>
#include <stdint.h>

/**

Global Defines  

*/
typedef union {

    struct {
        uint8_t idType;
        uint32_t id;
        uint8_t dlc;
        uint8_t data0;
        uint8_t data1;
        uint8_t data2;
        uint8_t data3;
        uint8_t data4;
        uint8_t data5;
        uint8_t data6;
        uint8_t data7;
    } frame;
    uint8_t array[14];
} uCAN_MSG;

/**
 Defines
*/

#define dSTANDARD_CAN_MSG_ID_2_0B 1
#define dEXTENDED_CAN_MSG_ID_2_0B 2

// For backwards-compatibility with pre-v1.79 users
#define ECAN_ISR_ECAN_WAKI ECAN_WAKI_ISR

/**
  Section: CAN APIs
*/

/**
    @Summary
        Initializes the ECAN module. 

    @Description
        This routine sets all the set parameters to the ECAN module.

    @Preconditions 
        None

    @Param
        None
  
    @Returns
        None
 
    @Example
        <code>
        ECAN_Initialize();  
        </code>                                                                      
*/
void ECAN_Initialize(void);
/**
                                                                           
    @Summary
        CAN_sleep

    @Description
        Puts the CAN module to sleep

    @Param
        None 

    @Returns
        None   

    @Example
        <code>
        CAN_Initialize();  
        </code> 
                                                                           
*/

void CAN_sleep(void);

/**
    @Summary
        CAN_transmit

    @Description
        Transmits out sCAN_MSG

    @Param
        Pointer to a sCAN_MSG

    @Returns
        True or False if message was loaded to transmit buffer 

    @Example
        <code>
        uCAN_MSG txMessage;
        CAN_transmit(&txMessage);  
        </code>                                                                             
*/
uint8_t CAN_transmit(uCAN_MSG *tempCanMsg);


/**

	@Summary
		CAN_receive

	@Description
		Receives CAN messages

	@Param
		Pointer to a sCAN_MSG

	@Returns
		True or False for a new message 
  
	@Example
		<code>
		uCAN_MSG rxMessage;
		CAN_receive(&rxMessage);  
		</code> 
                                                                             
*/
uint8_t CAN_receive(uCAN_MSG *tempCanMsg);

/**
 
	@Summary
		CAN_messagesInBuffer
 
	@Description
		Checks to see how many messages are in the buffer
	
	@Param
		None

	@Returns
		Returns total number of messages in the buffers

	@Example
		<code>
		uint8_t nrMsg;
		nrMsg = CAN_messagesInBuffer();  
		</code>                                                                            
*/
uint8_t CAN_messagesInBuffer(void);

/**

	@Summary
		CAN_isBusOff

	@Description
		Checks to see if module is busoff

	@Param
		None

	@Returns
		True if module is in Busoff, False is if it is not

	@Example
		<code>
		uint8_t busOff;
		busOff = CAN_isBusOff();  
		</code> 
                                                  
*/

uint8_t CAN_isBusOff(void);

/**

	@Summary
		CAN_isRXErrorPassive

	@Description
		Checks to see if module is RX Error Passive
        
	@Param
		None
 
	@Returns
 		True if module is in RX Error Passive, False is if it is not                                                    

 	@Example
		<code>
		uint8_t errRxPasive;
		errRxPasive = CAN_isRXErrorPassive();
		</code>     
                                                    
 */
 
uint8_t CAN_isRXErrorPassive(void);

/**

	@Summary
		CAN_isTXErrorPassive

	@Description
		Checks to see if module is TX Error Passive

	@Param
		None

	@Returns
		True if module is in TX Error Passive, False is if it is not

	@Example
		<code>
		uint8_t errTxPasive;
		errTxPasive = CAN_isTXErrorPassive();  
		</code>       

*/

uint8_t CAN_isTXErrorPassive(void);

/**
    @Summary
        ECAN_SetWakeUpInterruptHandler

    @Description
        Sets the ECAN Wake up interrupt handler

    @Param
        Address of the callback routine

    @Returns
        None

    @Example
        <code>
        volatile bool customWakeUpFlag = false;

        void CustomWakeUpInterruptHandler(void)
        {
            customWakeUpFlag = true;
            // ...
        }

        void main(void)
        {
            // ...
            ECAN_SetWakeUpInterruptHandler(CustomWakeUpInterruptHandler);

            while (1)
            {
                if (customWakeUpFlag) {
                    customWakeUpFlag = false;
                    // ...
                }
            }
        }
        </code>       
*/
void ECAN_SetWakeUpInterruptHandler(void (*handler)(void));

/**
    @Summary
        ECAN_WAKI_ISR

    @Description
        Implements the ECAN Wake up interrupt service routine

    @Param
        None

    @Returns
        None
*/
void ECAN_WAKI_ISR(void);


#endif // ECAN_H
