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

// get/set RA2 procedures
#define RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()              PORTAbits.RA2
#define RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()             do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()           do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode()         do { ANSELAbits.ANSA2 = 1; } while(0)
#define RA2_SetDigitalMode()        do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set TMR1_TICK aliases
#define TMR1_TICK_TRIS                 TRISAbits.TRISA5
#define TMR1_TICK_LAT                  LATAbits.LATA5
#define TMR1_TICK_PORT                 PORTAbits.RA5
#define TMR1_TICK_WPU                  WPUAbits.WPUA5
#define TMR1_TICK_OD                   ODCONAbits.ODA5
#define TMR1_TICK_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define TMR1_TICK_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define TMR1_TICK_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define TMR1_TICK_GetValue()           PORTAbits.RA5
#define TMR1_TICK_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define TMR1_TICK_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define TMR1_TICK_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define TMR1_TICK_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define TMR1_TICK_SetPushPull()        do { ODCONAbits.ODA5 = 0; } while(0)
#define TMR1_TICK_SetOpenDrain()       do { ODCONAbits.ODA5 = 1; } while(0)

// get/set IO_RB6 aliases
#define IO_RB6_TRIS                 TRISBbits.TRISB6
#define IO_RB6_LAT                  LATBbits.LATB6
#define IO_RB6_PORT                 PORTBbits.RB6
#define IO_RB6_WPU                  WPUBbits.WPUB6
#define IO_RB6_OD                   ODCONBbits.ODB6
#define IO_RB6_ANS                  ANSELBbits.ANSB6
#define IO_RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define IO_RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define IO_RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define IO_RB6_GetValue()           PORTBbits.RB6
#define IO_RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define IO_RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define IO_RB6_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define IO_RB6_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define IO_RB6_SetPushPull()        do { ODCONBbits.ODB6 = 0; } while(0)
#define IO_RB6_SetOpenDrain()       do { ODCONBbits.ODB6 = 1; } while(0)
#define IO_RB6_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define IO_RB6_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set IO_RB7 aliases
#define IO_RB7_TRIS                 TRISBbits.TRISB7
#define IO_RB7_LAT                  LATBbits.LATB7
#define IO_RB7_PORT                 PORTBbits.RB7
#define IO_RB7_WPU                  WPUBbits.WPUB7
#define IO_RB7_OD                   ODCONBbits.ODB7
#define IO_RB7_ANS                  ANSELBbits.ANSB7
#define IO_RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define IO_RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define IO_RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define IO_RB7_GetValue()           PORTBbits.RB7
#define IO_RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define IO_RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define IO_RB7_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define IO_RB7_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define IO_RB7_SetPushPull()        do { ODCONBbits.ODB7 = 0; } while(0)
#define IO_RB7_SetOpenDrain()       do { ODCONBbits.ODB7 = 1; } while(0)
#define IO_RB7_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define IO_RB7_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set DOSE_RATE aliases
#define DOSE_RATE_TRIS                 TRISCbits.TRISC0
#define DOSE_RATE_LAT                  LATCbits.LATC0
#define DOSE_RATE_PORT                 PORTCbits.RC0
#define DOSE_RATE_WPU                  WPUCbits.WPUC0
#define DOSE_RATE_OD                   ODCONCbits.ODC0
#define DOSE_RATE_ANS                  ANSELCbits.ANSC0
#define DOSE_RATE_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define DOSE_RATE_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define DOSE_RATE_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define DOSE_RATE_GetValue()           PORTCbits.RC0
#define DOSE_RATE_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define DOSE_RATE_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define DOSE_RATE_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define DOSE_RATE_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define DOSE_RATE_SetPushPull()        do { ODCONCbits.ODC0 = 0; } while(0)
#define DOSE_RATE_SetOpenDrain()       do { ODCONCbits.ODC0 = 1; } while(0)
#define DOSE_RATE_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define DOSE_RATE_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set PULSE aliases
#define PULSE_TRIS                 TRISCbits.TRISC4
#define PULSE_LAT                  LATCbits.LATC4
#define PULSE_PORT                 PORTCbits.RC4
#define PULSE_WPU                  WPUCbits.WPUC4
#define PULSE_OD                   ODCONCbits.ODC4
#define PULSE_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define PULSE_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define PULSE_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define PULSE_GetValue()           PORTCbits.RC4
#define PULSE_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define PULSE_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define PULSE_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define PULSE_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define PULSE_SetPushPull()        do { ODCONCbits.ODC4 = 0; } while(0)
#define PULSE_SetOpenDrain()       do { ODCONCbits.ODC4 = 1; } while(0)

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
    Interrupt on Change Handler for the IOCCF4 pin functionality
 * @Example
    IOCCF4_ISR();
 */
void IOCCF4_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF4 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF4 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF4_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF4_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF4 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF4_SetInterruptHandler() method.
    This handler is called every time the IOCCF4 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF4_SetInterruptHandler(IOCCF4_InterruptHandler);

*/
extern void (*IOCCF4_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF4 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF4_SetInterruptHandler() method.
    This handler is called every time the IOCCF4 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF4_SetInterruptHandler(IOCCF4_DefaultInterruptHandler);

*/
void IOCCF4_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/