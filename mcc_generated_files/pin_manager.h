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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC16F1619
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.00
        MPLAB 	          :  MPLAB X 5.10	
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
#include <stdbool.h>
#include <stdint.h>

extern uint16_t pumpFlowCounter;
extern uint16_t pumpFlowCount;
extern unsigned char tick;

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_RA2 aliases
#define IO_RA2_TRIS                 TRISAbits.TRISA2
#define IO_RA2_LAT                  LATAbits.LATA2
#define IO_RA2_PORT                 PORTAbits.RA2
#define IO_RA2_WPU                  WPUAbits.WPUA2
#define IO_RA2_OD                   ODCONAbits.ODA2
#define IO_RA2_ANS                  ANSELAbits.ANSA2
#define IO_RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define IO_RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define IO_RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define IO_RA2_GetValue()           PORTAbits.RA2
#define IO_RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define IO_RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define IO_RA2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define IO_RA2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define IO_RA2_SetPushPull()        do { ODCONAbits.ODA2 = 0; } while(0)
#define IO_RA2_SetOpenDrain()       do { ODCONAbits.ODA2 = 1; } while(0)
#define IO_RA2_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define IO_RA2_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set DOSE_PUMP_PRIME aliases
#define DOSE_PUMP_PRIME_TRIS                 TRISAbits.TRISA4
#define DOSE_PUMP_PRIME_LAT                  LATAbits.LATA4
#define DOSE_PUMP_PRIME_PORT                 PORTAbits.RA4
#define DOSE_PUMP_PRIME_WPU                  WPUAbits.WPUA4
#define DOSE_PUMP_PRIME_OD                   ODCONAbits.ODA4
#define DOSE_PUMP_PRIME_ANS                  ANSELAbits.ANSA4
#define DOSE_PUMP_PRIME_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define DOSE_PUMP_PRIME_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define DOSE_PUMP_PRIME_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define DOSE_PUMP_PRIME_GetValue()           PORTAbits.RA4
#define DOSE_PUMP_PRIME_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define DOSE_PUMP_PRIME_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define DOSE_PUMP_PRIME_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define DOSE_PUMP_PRIME_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define DOSE_PUMP_PRIME_SetPushPull()        do { ODCONAbits.ODA4 = 0; } while(0)
#define DOSE_PUMP_PRIME_SetOpenDrain()       do { ODCONAbits.ODA4 = 1; } while(0)
#define DOSE_PUMP_PRIME_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define DOSE_PUMP_PRIME_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set CLK_TICK aliases
#define CLK_TICK_TRIS                 TRISAbits.TRISA5
#define CLK_TICK_LAT                  LATAbits.LATA5
#define CLK_TICK_PORT                 PORTAbits.RA5
#define CLK_TICK_WPU                  WPUAbits.WPUA5
#define CLK_TICK_OD                   ODCONAbits.ODA5
#define CLK_TICK_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define CLK_TICK_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define CLK_TICK_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define CLK_TICK_GetValue()           PORTAbits.RA5
#define CLK_TICK_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define CLK_TICK_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define CLK_TICK_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define CLK_TICK_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define CLK_TICK_SetPushPull()        do { ODCONAbits.ODA5 = 0; } while(0)
#define CLK_TICK_SetOpenDrain()       do { ODCONAbits.ODA5 = 1; } while(0)

// get/set PUMP_FLOW_SENSOR_CAL aliases
#define PUMP_FLOW_SENSOR_CAL_TRIS                 TRISBbits.TRISB4
#define PUMP_FLOW_SENSOR_CAL_LAT                  LATBbits.LATB4
#define PUMP_FLOW_SENSOR_CAL_PORT                 PORTBbits.RB4
#define PUMP_FLOW_SENSOR_CAL_WPU                  WPUBbits.WPUB4
#define PUMP_FLOW_SENSOR_CAL_OD                   ODCONBbits.ODB4
#define PUMP_FLOW_SENSOR_CAL_ANS                  ANSELBbits.ANSB4
#define PUMP_FLOW_SENSOR_CAL_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define PUMP_FLOW_SENSOR_CAL_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define PUMP_FLOW_SENSOR_CAL_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define PUMP_FLOW_SENSOR_CAL_GetValue()           PORTBbits.RB4
#define PUMP_FLOW_SENSOR_CAL_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define PUMP_FLOW_SENSOR_CAL_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define PUMP_FLOW_SENSOR_CAL_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define PUMP_FLOW_SENSOR_CAL_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define PUMP_FLOW_SENSOR_CAL_SetPushPull()        do { ODCONBbits.ODB4 = 0; } while(0)
#define PUMP_FLOW_SENSOR_CAL_SetOpenDrain()       do { ODCONBbits.ODB4 = 1; } while(0)
#define PUMP_FLOW_SENSOR_CAL_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define PUMP_FLOW_SENSOR_CAL_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set FLOW_SENSOR_CAL_2 aliases
#define FLOW_SENSOR_CAL_2_TRIS                 TRISBbits.TRISB5
#define FLOW_SENSOR_CAL_2_LAT                  LATBbits.LATB5
#define FLOW_SENSOR_CAL_2_PORT                 PORTBbits.RB5
#define FLOW_SENSOR_CAL_2_WPU                  WPUBbits.WPUB5
#define FLOW_SENSOR_CAL_2_OD                   ODCONBbits.ODB5
#define FLOW_SENSOR_CAL_2_ANS                  ANSELBbits.ANSB5
#define FLOW_SENSOR_CAL_2_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define FLOW_SENSOR_CAL_2_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define FLOW_SENSOR_CAL_2_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define FLOW_SENSOR_CAL_2_GetValue()           PORTBbits.RB5
#define FLOW_SENSOR_CAL_2_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define FLOW_SENSOR_CAL_2_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define FLOW_SENSOR_CAL_2_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define FLOW_SENSOR_CAL_2_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define FLOW_SENSOR_CAL_2_SetPushPull()        do { ODCONBbits.ODB5 = 0; } while(0)
#define FLOW_SENSOR_CAL_2_SetOpenDrain()       do { ODCONBbits.ODB5 = 1; } while(0)
#define FLOW_SENSOR_CAL_2_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define FLOW_SENSOR_CAL_2_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set TEMP_ONE_WIRE aliases
#define TEMP_ONE_WIRE_TRIS                 TRISBbits.TRISB7
#define TEMP_ONE_WIRE_LAT                  LATBbits.LATB7
#define TEMP_ONE_WIRE_PORT                 PORTBbits.RB7
#define TEMP_ONE_WIRE_WPU                  WPUBbits.WPUB7
#define TEMP_ONE_WIRE_OD                   ODCONBbits.ODB7
#define TEMP_ONE_WIRE_ANS                  ANSELBbits.ANSB7
#define TEMP_ONE_WIRE_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define TEMP_ONE_WIRE_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define TEMP_ONE_WIRE_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define TEMP_ONE_WIRE_GetValue()           PORTBbits.RB7
#define TEMP_ONE_WIRE_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define TEMP_ONE_WIRE_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define TEMP_ONE_WIRE_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define TEMP_ONE_WIRE_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define TEMP_ONE_WIRE_SetPushPull()        do { ODCONBbits.ODB7 = 0; } while(0)
#define TEMP_ONE_WIRE_SetOpenDrain()       do { ODCONBbits.ODB7 = 1; } while(0)
#define TEMP_ONE_WIRE_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define TEMP_ONE_WIRE_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()              PORTCbits.RC0
#define RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()             do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()           do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetAnalogMode()         do { ANSELCbits.ANSC0 = 1; } while(0)
#define RC0_SetDigitalMode()        do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set DOSE_PUMP_DC_CAL aliases
#define DOSE_PUMP_DC_CAL_TRIS                 TRISCbits.TRISC1
#define DOSE_PUMP_DC_CAL_LAT                  LATCbits.LATC1
#define DOSE_PUMP_DC_CAL_PORT                 PORTCbits.RC1
#define DOSE_PUMP_DC_CAL_WPU                  WPUCbits.WPUC1
#define DOSE_PUMP_DC_CAL_OD                   ODCONCbits.ODC1
#define DOSE_PUMP_DC_CAL_ANS                  ANSELCbits.ANSC1
#define DOSE_PUMP_DC_CAL_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define DOSE_PUMP_DC_CAL_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define DOSE_PUMP_DC_CAL_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define DOSE_PUMP_DC_CAL_GetValue()           PORTCbits.RC1
#define DOSE_PUMP_DC_CAL_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define DOSE_PUMP_DC_CAL_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define DOSE_PUMP_DC_CAL_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define DOSE_PUMP_DC_CAL_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define DOSE_PUMP_DC_CAL_SetPushPull()        do { ODCONCbits.ODC1 = 0; } while(0)
#define DOSE_PUMP_DC_CAL_SetOpenDrain()       do { ODCONCbits.ODC1 = 1; } while(0)
#define DOSE_PUMP_DC_CAL_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define DOSE_PUMP_DC_CAL_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set ADD_FLOW_SENSOR_CAL aliases
#define ADD_FLOW_SENSOR_CAL_TRIS                 TRISCbits.TRISC2
#define ADD_FLOW_SENSOR_CAL_LAT                  LATCbits.LATC2
#define ADD_FLOW_SENSOR_CAL_PORT                 PORTCbits.RC2
#define ADD_FLOW_SENSOR_CAL_WPU                  WPUCbits.WPUC2
#define ADD_FLOW_SENSOR_CAL_OD                   ODCONCbits.ODC2
#define ADD_FLOW_SENSOR_CAL_ANS                  ANSELCbits.ANSC2
#define ADD_FLOW_SENSOR_CAL_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define ADD_FLOW_SENSOR_CAL_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define ADD_FLOW_SENSOR_CAL_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define ADD_FLOW_SENSOR_CAL_GetValue()           PORTCbits.RC2
#define ADD_FLOW_SENSOR_CAL_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define ADD_FLOW_SENSOR_CAL_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define ADD_FLOW_SENSOR_CAL_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define ADD_FLOW_SENSOR_CAL_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define ADD_FLOW_SENSOR_CAL_SetPushPull()        do { ODCONCbits.ODC2 = 0; } while(0)
#define ADD_FLOW_SENSOR_CAL_SetOpenDrain()       do { ODCONCbits.ODC2 = 1; } while(0)
#define ADD_FLOW_SENSOR_CAL_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define ADD_FLOW_SENSOR_CAL_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set ADD_FLOW_SENSOR aliases
#define ADD_FLOW_SENSOR_TRIS                 TRISCbits.TRISC3
#define ADD_FLOW_SENSOR_LAT                  LATCbits.LATC3
#define ADD_FLOW_SENSOR_PORT                 PORTCbits.RC3
#define ADD_FLOW_SENSOR_WPU                  WPUCbits.WPUC3
#define ADD_FLOW_SENSOR_OD                   ODCONCbits.ODC3
#define ADD_FLOW_SENSOR_ANS                  ANSELCbits.ANSC3
#define ADD_FLOW_SENSOR_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define ADD_FLOW_SENSOR_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define ADD_FLOW_SENSOR_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define ADD_FLOW_SENSOR_GetValue()           PORTCbits.RC3
#define ADD_FLOW_SENSOR_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define ADD_FLOW_SENSOR_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define ADD_FLOW_SENSOR_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define ADD_FLOW_SENSOR_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define ADD_FLOW_SENSOR_SetPushPull()        do { ODCONCbits.ODC3 = 0; } while(0)
#define ADD_FLOW_SENSOR_SetOpenDrain()       do { ODCONCbits.ODC3 = 1; } while(0)
#define ADD_FLOW_SENSOR_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define ADD_FLOW_SENSOR_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set SDA aliases
#define SDA_TRIS                 TRISCbits.TRISC4
#define SDA_LAT                  LATCbits.LATC4
#define SDA_PORT                 PORTCbits.RC4
#define SDA_WPU                  WPUCbits.WPUC4
#define SDA_OD                   ODCONCbits.ODC4
#define SDA_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SDA_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SDA_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SDA_GetValue()           PORTCbits.RC4
#define SDA_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SDA_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define SDA_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define SDA_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define SDA_SetPushPull()        do { ODCONCbits.ODC4 = 0; } while(0)
#define SDA_SetOpenDrain()       do { ODCONCbits.ODC4 = 1; } while(0)

// get/set SCL aliases
#define SCL_TRIS                 TRISCbits.TRISC5
#define SCL_LAT                  LATCbits.LATC5
#define SCL_PORT                 PORTCbits.RC5
#define SCL_WPU                  WPUCbits.WPUC5
#define SCL_OD                   ODCONCbits.ODC5
#define SCL_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define SCL_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define SCL_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define SCL_GetValue()           PORTCbits.RC5
#define SCL_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define SCL_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define SCL_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define SCL_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define SCL_SetPushPull()        do { ODCONCbits.ODC5 = 0; } while(0)
#define SCL_SetOpenDrain()       do { ODCONCbits.ODC5 = 1; } while(0)

// get/set PUMP_FLOW_SENSOR aliases
#define PUMP_FLOW_SENSOR_TRIS                 TRISCbits.TRISC6
#define PUMP_FLOW_SENSOR_LAT                  LATCbits.LATC6
#define PUMP_FLOW_SENSOR_PORT                 PORTCbits.RC6
#define PUMP_FLOW_SENSOR_WPU                  WPUCbits.WPUC6
#define PUMP_FLOW_SENSOR_OD                   ODCONCbits.ODC6
#define PUMP_FLOW_SENSOR_ANS                  ANSELCbits.ANSC6
#define PUMP_FLOW_SENSOR_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define PUMP_FLOW_SENSOR_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define PUMP_FLOW_SENSOR_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define PUMP_FLOW_SENSOR_GetValue()           PORTCbits.RC6
#define PUMP_FLOW_SENSOR_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define PUMP_FLOW_SENSOR_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define PUMP_FLOW_SENSOR_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define PUMP_FLOW_SENSOR_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define PUMP_FLOW_SENSOR_SetPushPull()        do { ODCONCbits.ODC6 = 0; } while(0)
#define PUMP_FLOW_SENSOR_SetOpenDrain()       do { ODCONCbits.ODC6 = 1; } while(0)
#define PUMP_FLOW_SENSOR_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define PUMP_FLOW_SENSOR_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set FLOW_SENSOR_2 aliases
#define FLOW_SENSOR_2_TRIS                 TRISCbits.TRISC7
#define FLOW_SENSOR_2_LAT                  LATCbits.LATC7
#define FLOW_SENSOR_2_PORT                 PORTCbits.RC7
#define FLOW_SENSOR_2_WPU                  WPUCbits.WPUC7
#define FLOW_SENSOR_2_OD                   ODCONCbits.ODC7
#define FLOW_SENSOR_2_ANS                  ANSELCbits.ANSC7
#define FLOW_SENSOR_2_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define FLOW_SENSOR_2_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define FLOW_SENSOR_2_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define FLOW_SENSOR_2_GetValue()           PORTCbits.RC7
#define FLOW_SENSOR_2_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define FLOW_SENSOR_2_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define FLOW_SENSOR_2_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define FLOW_SENSOR_2_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define FLOW_SENSOR_2_SetPushPull()        do { ODCONCbits.ODC7 = 0; } while(0)
#define FLOW_SENSOR_2_SetOpenDrain()       do { ODCONCbits.ODC7 = 1; } while(0)
#define FLOW_SENSOR_2_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define FLOW_SENSOR_2_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

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


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF3 pin functionality
 * @Example
    IOCCF3_ISR();
 */
void IOCCF3_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF3 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF3 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF3_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF3_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF3 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF3_SetInterruptHandler() method.
    This handler is called every time the IOCCF3 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF3_SetInterruptHandler(IOCCF3_InterruptHandler);

*/
extern void (*IOCCF3_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF3 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF3_SetInterruptHandler() method.
    This handler is called every time the IOCCF3 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF3_SetInterruptHandler(IOCCF3_DefaultInterruptHandler);

*/
void IOCCF3_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF6 pin functionality
 * @Example
    IOCCF6_ISR();
 */
void IOCCF6_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF6 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF6 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF6_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF6_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF6 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF6_SetInterruptHandler() method.
    This handler is called every time the IOCCF6 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF6_SetInterruptHandler(IOCCF6_InterruptHandler);

*/
extern void (*IOCCF6_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF6 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF6_SetInterruptHandler() method.
    This handler is called every time the IOCCF6 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF6_SetInterruptHandler(IOCCF6_DefaultInterruptHandler);

*/
void IOCCF6_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF7 pin functionality
 * @Example
    IOCCF7_ISR();
 */
void IOCCF7_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF7 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF7 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF7_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF7_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF7 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF7_SetInterruptHandler() method.
    This handler is called every time the IOCCF7 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF7_SetInterruptHandler(IOCCF7_InterruptHandler);

*/
extern void (*IOCCF7_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF7 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF7_SetInterruptHandler() method.
    This handler is called every time the IOCCF7 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF7_SetInterruptHandler(IOCCF7_DefaultInterruptHandler);

*/
void IOCCF7_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/