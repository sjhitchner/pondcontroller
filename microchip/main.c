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

#define ADD_FLOW_SUM_TICK_TRIGGER 40

uint16_t pumpFlowRate;
uint16_t addFlowSum;  // Sum of how many ticks happened
uint16_t addFlowSumPrevious;
uint8_t addFlowSumTick = 0;
uint16_t flow2Rate;
bool dosePumpPrimeOn;
uint8_t dosePumpPrimeCount;

// Calibration values from ADC from pots
uint16_t dosingPumpCalibration;
uint16_t addFlowCalibration;
uint16_t pumpFlowCalibration;
uint16_t flow2Calibration;
adc_channel_t currentADC;

void initializeCalibrationValues();
void selectAndStartNextADCConversion();
void readCompletedADCConversion();

/* 
 * Notes
 * Timer1
 * 500kHz clock, 1:8 Pre-scaler => 524,288 max count
 *  On interrupt need to initialize counter with 24,288 0x5ee0
 * 
 * TODO
 * I2C
 * OneWire
 * 
 *
 * PWM2_LoadDutyValue(dosingDutyCycle>>2);
 *  
 */

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
   
    // Pump flow sensor 
    pumpFlowCounter = 0;        // Read from pump flow sensor
    pumpFlowCount = 0;
    flow2Counter = 0;        // Read from pump flow sensor
    flow2Count = 0;
    addFlowCounter = 0;        // Read from pump flow sensor
    addFlowCount = 0;
    addFlowSum = 0;
    addFlowSumPrevious = 0;
    addFlowSumTick = 0;
    
    dosePumpPrimeOn = false;
    dosePumpPrimeCount = 0;
    
    // Dosing Pump and Sensor Calibration
    dosingPumpCalibration = 0;
    addFlowCalibration = 0;
    pumpFlowCalibration = 0;
    flow2Calibration = 0;
    
    initializeCalibrationValues();
    selectAndStartNextADCConversion();
    
    while (1)
    {
        __delay_ms(50);
        
        // If a tick (second interval passed) do calculations
        if (tick>0) {
            calculatePumpFlowRate();
            calculateFlow2Rate();
            addFlowSum += addFlowCount;
            tick--;
        }
                
        if (ADC_IsConversionDone()) {
            readCompletedADCConversion();
            selectAndStartNextADCConversion();
        }
        
        // Need to determine how much water was added
        if (addFlowSum > 0 && ) {
            if (addFlowSumPrevious == addFlowSum) {
                addFlowSumTick++;
                
                if (addFlowSumTick > ADD_FLOW_SUM_TICK_TRIGGER) {
                    // TODO Trigger dose pump for a given period
                    addFlowSum = 0;
                    addFlowSumPrevious = 0;
                    addFlowSumTick = 0;
                }
            } else {
                addFlowSumPrevious = addFlowSum;
                addFlowSumTick = 0;
            }
        }
        
        // Prime Dose Pump
        if (DOSE_PUMP_PRIME_GetValue() > 0) {
            dosePumpPrimeCount++;
            if (dosePumpPrimeCount > 4) {
                dosePumpPrimeOn = true;
                startDosePump();
            }
        } else {
            dosePumpPrimeCount = 0;
            if (dosePumpPrimeOn) {
                stopDosePump();
                dosePumpPrimeOn = false;
            }
        }
    }
}

// Pump flow sensor
// F = 7.5 * Q (L/min) -> 7.5*Q (L/min) * (min/60s)
// F = 7.5/60 Q (L/s)
void calculatePumpFlowRate() {
    uint16_t factor = pumpFlowCalibration >> 5; // Convert 10bit to (0-31) 5bit
    pumpFlowRate = pumpFlowCount / factor;
}

void calculateFlow2Rate() {
    uint16_t factor = flow2Calibration >> 5; // Convert 10bit to (0-31) 5bit
    flow2Rate = flow2Count / factor;
}

// Initialize Calibration Values
void initializeCalibrationValues() {
    // Select first ADC channel
    currentADC = FLOW_SENSOR_CAL_2;
    
    dosingPumpCalibration = ADC_GetConversion(DOSE_PUMP_DC_CAL);
    addFlowCalibration = ADC_GetConversion(ADD_FLOW_SENSOR_CAL);
    pumpFlowCalibration = ADC_GetConversion(PUMP_FLOW_SENSOR_CAL);
    flow2Calibration = ADC_GetConversion(FLOW_SENSOR_CAL_2);
}

void selectAndStartNextADCConversion() {
    switch (currentADC) {
        case DOSE_PUMP_DC_CAL:
            currentADC = ADD_FLOW_SENSOR_CAL;
            break;
        case ADD_FLOW_SENSOR_CAL:
            currentADC = PUMP_FLOW_SENSOR_CAL;
            break;
        case PUMP_FLOW_SENSOR_CAL:
            currentADC = FLOW_SENSOR_CAL_2;
            break;
        case FLOW_SENSOR_CAL_2:
            currentADC = DOSE_PUMP_DC_CAL;
            break;
    }
    
    ADC_SelectChannel(currentADC);
    ADC_StartConversion();   
}

void readCompletedADCConversion() {
    uint16_t result = ADC_GetConversionResult();
         
    switch (currentADC) {
        case DOSE_PUMP_DC_CAL:
            dosingPumpCalibration = result;
            break;
        case ADD_FLOW_SENSOR_CAL:
            addFlowCalibration = result;
            break;
        case PUMP_FLOW_SENSOR_CAL:
            pumpFlowCalibration = result;
            break;
        case FLOW_SENSOR_CAL_2:
            flow2Calibration = result;
            break;
    }
}

void startDosePump() {
    PWM2_LoadDutyValue(dosingPumpCalibration>>2);
}

void stopDosePump() {
    PWM2_LoadDutyValue(0x0);
}

