/*
 * Watchdog.h
 *
 *  Created on: 27/10/2019
 *      Author: Lalo
 */

#ifndef DRIVER_HEADER_WATCHDOG_H_
#define DRIVER_HEADER_WATCHDOG_H_

#include <msp430f169.h>
#include <intrinsics.h>
#include <stdint.h>


typedef enum
{
    Watchdog_enInterruptNMI   =1,
    Watchdog_enInterruptWDT   =2,
}Watchdog_nInterrupt;

typedef enum
{
    Watchdog_enDiv32768   =0,
    Watchdog_enDiv8192,
    Watchdog_enDiv512,
    Watchdog_enDiv64,
}Watchdog_nDiv;

typedef enum
{
    Watchdog_enClockSMCLK   =0,
    Watchdog_enClockACLK,
}Watchdog_nClock;

typedef enum
{
    Watchdog_enModeWDT   =0,
    Watchdog_enModeInterval,
}Watchdog_nMode;

typedef enum
{
    Watchdog_enNMIRising   =0,
    Watchdog_enNMIFalling,
}Watchdog_nNMIEdge;

typedef enum
{
    Watchdog_enEnNMI   =0,
    Watchdog_enEnRESET,
}Watchdog_nNMIFunction;


void Watchdog__vInit(Watchdog_nMode enMode, Watchdog_nClock enClockSource, Watchdog_nDiv enDiv );
void Watchdog__vDeinit(void);

void Watchdog__vClearCount(void);

void Watchdog__vEnableInterrupt(Watchdog_nInterrupt enInterrupt);
void Watchdog__vDisableInterrupt(Watchdog_nInterrupt enInterrupt);
void Watchdog__vSetInterrupt(Watchdog_nInterrupt enInterrupt);
void Watchdog__vClearInterrupt(Watchdog_nInterrupt enInterrupt);

#endif /* DRIVER_HEADER_WATCHDOG_H_ */
