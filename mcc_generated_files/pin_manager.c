/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC16F1619
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.00
        MPLAB             :  MPLAB X 5.10

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.
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

#include "pin_manager.h"

uint16_t pumpFlowCounter = 0;
uint16_t pumpFlowCount = 0;
unsigned char tick = 0;



void (*IOCCF4_InterruptHandler)(void);


void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;

    /**
    TRISx registers
    */
    TRISA = 0x13;
    TRISB = 0xF0;
    TRISC = 0xFF;

    /**
    ANSELx registers
    */
    ANSELC = 0xCF;
    ANSELB = 0xF0;
    ANSELA = 0x17;

    /**
    WPUx registers
    */
    WPUB = 0x00;
    WPUA = 0x00;
    WPUC = 0x00;
    OPTION_REGbits.nWPUEN = 1;

    /**
    ODx registers
    */
    ODCONA = 0x00;
    ODCONB = 0x00;
    ODCONC = 0x00;

    /**
    SLRCONx registers
    */
    SLRCONA = 0x37;
    SLRCONB = 0xF0;
    SLRCONC = 0xFF;
    

    /**
    IOCx registers 
    */
    //interrupt on change for group IOCCF - flag
    IOCCFbits.IOCCF4 = 0;
    //interrupt on change for group IOCCN - negative
    IOCCNbits.IOCCN4 = 1;
    //interrupt on change for group IOCCP - positive
    IOCCPbits.IOCCP4 = 0;



    // register default IOC callback functions at runtime; use these methods to register a custom function
    IOCCF4_SetInterruptHandler(IOCCF4_DefaultInterruptHandler);
   
    // Enable IOCI interrupt 
    INTCONbits.IOCIE = 1; 
    
	
    RA2PPS = 0x0D;   //RA2->CCP2:CCP2;    
}
  
void PIN_MANAGER_IOC(void)
{   
	// interrupt on change for pin IOCCF4
    if(IOCCFbits.IOCCF4 == 1)
    {
        IOCCF4_ISR();  
    }	
}

/**
   IOCCF4 Interrupt Service Routine
*/
void IOCCF4_ISR(void) {
    
    // Count pulses received by pump flow meter;
    pumpFlowCounter++;

    // Call the interrupt handler for the callback registered at runtime
    if(IOCCF4_InterruptHandler)
    {
        IOCCF4_InterruptHandler();
    }
    IOCCFbits.IOCCF4 = 0;
}

/**
  Allows selecting an interrupt handler for IOCCF4 at application runtime
*/
void IOCCF4_SetInterruptHandler(void (* InterruptHandler)(void)){
    IOCCF4_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCCF4
*/
void IOCCF4_DefaultInterruptHandler(void){
    // add your IOCCF4 interrupt custom code
    // or set custom function using IOCCF4_SetInterruptHandler()
}

/**
 End of File
*/