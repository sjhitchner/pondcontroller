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

// get/set PULSE_COUNT_HIGH aliases
#define PULSE_COUNT_HIGH_TRIS                 TRISAbits.TRISA2
#define PULSE_COUNT_HIGH_LAT                  LATAbits.LATA2
#define PULSE_COUNT_HIGH_PORT                 PORTAbits.RA2
#define PULSE_COUNT_HIGH_WPU                  WPUAbits.WPUA2
#define PULSE_COUNT_HIGH_OD                   ODCONAbits.ODA2
#define PULSE_COUNT_HIGH_ANS                  ANSELAbits.ANSA2
#define PULSE_COUNT_HIGH_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define PULSE_COUNT_HIGH_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define PULSE_COUNT_HIGH_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define PULSE_COUNT_HIGH_GetValue()           PORTAbits.RA2
#define PULSE_COUNT_HIGH_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define PULSE_COUNT_HIGH_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define PULSE_COUNT_HIGH_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define PULSE_COUNT_HIGH_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define PULSE_COUNT_HIGH_SetPushPull()        do { ODCONAbits.ODA2 = 0; } while(0)
#define PULSE_COUNT_HIGH_SetOpenDrain()       do { ODCONAbits.ODA2 = 1; } while(0)
#define PULSE_COUNT_HIGH_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define PULSE_COUNT_HIGH_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

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

// get/set PULSE_COUNT_LOW aliases
#define PULSE_COUNT_LOW_TRIS                 TRISCbits.TRISC5
#define PULSE_COUNT_LOW_LAT                  LATCbits.LATC5
#define PULSE_COUNT_LOW_PORT                 PORTCbits.RC5
#define PULSE_COUNT_LOW_WPU                  WPUCbits.WPUC5
#define PULSE_COUNT_LOW_OD                   ODCONCbits.ODC5
#define PULSE_COUNT_LOW_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define PULSE_COUNT_LOW_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define PULSE_COUNT_LOW_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define PULSE_COUNT_LOW_GetValue()           PORTCbits.RC5
#define PULSE_COUNT_LOW_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define PULSE_COUNT_LOW_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define PULSE_COUNT_LOW_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define PULSE_COUNT_LOW_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define PULSE_COUNT_LOW_SetPushPull()        do { ODCONCbits.ODC5 = 0; } while(0)
#define PULSE_COUNT_LOW_SetOpenDrain()       do { ODCONCbits.ODC5 = 1; } while(0)

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