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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC16F1619
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

#define PUMP_FLOW_FACTOR 8 // 7.5*Q (L/min) * (min/60s) = 7.5/60 Q (L/s)



struct PondStatus {
    uint16_t pumpFlowRate;
};

struct PondStatus pond;

uint16_t dosingDutyCycle;
unsigned char pulseCount;

/*
 Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    
    TMR1_StartTimer();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    tick = 0;
   
    // Read from pump flow sensor
    pumpFlowCounter = 0;
    pumpFlowCount = 0;
 
    // Read from pot
    dosingDutyCycle = 0;
    
    // Select first ADC channel
    ADC_SelectChannel(DOSE_RATE);
    ADC_StartConversion();
    
    while (1)
    {
        __delay_ms(100);
        
        // If a tick (second interval passed) do calculations
        if (tick>0) {
            pond.pumpFlowRate = pumpFlowCount / PUMP_FLOW_FACTOR;
            tick--;
        }
                
        if (ADC_IsConversionDone()) {
            dosingDutyCycle = ADC_GetConversionResult();
            PWM2_LoadDutyValue(dosingDutyCycle>>2);
            ADC_StartConversion();
        }
        
        /*
        if (pulseCount&0x1) {
            PULSE_COUNT_LOW_SetHigh();
        } else {
            PULSE_COUNT_LOW_SetLow();
        }
        
        if (pulseCount&0x2) {
            PULSE_COUNT_HIGH_SetHigh();
        } else {
            PULSE_COUNT_HIGH_SetLow();
        }
        */
    }
}
/**
 * Timer1
 * 500kHz clock, 1:8 Pre-scaler => 524,288 max count
 *  On interrupt need to initialize counter with 24,288 0x5ee0
 * 
 * 
 End of File
*/