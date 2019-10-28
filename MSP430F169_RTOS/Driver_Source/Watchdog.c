/*
 * Watchdog.c
 *
 *  Created on: 27/10/2019
 *      Author: Lalo
 */

#include <Watchdog.h>

void Watchdog__vInit(Watchdog_nMode enMode, Watchdog_nClock enClockSource, Watchdog_nDiv enDiv )
{
    uint16_t u16Reg=0x5A00;

    u16Reg|=WDTCNTCL;
    u16Reg|=(uint16_t)enMode<<4;
    u16Reg|=(uint16_t)enClockSource<<2;
    u16Reg|=(uint16_t)enDiv<<0;
    WDTCTL=u16Reg;
}
void Watchdog__vDeinit(void )
{
    uint16_t u16Reg=0x5A00|WDTHOLD|WDTCNTCL;
    WDTCTL=u16Reg;
}


void Watchdog__vClearCount(void)
{
    uint16_t u16Value=WDTCTL;
    uint16_t u16Reg=0x5A00|WDTCNTCL;

    u16Value&=~0xFF00;

    WDTCTL=u16Reg|u16Value;
}

void Watchdog__vEnableInterrupt(Watchdog_nInterrupt enInterrupt)
{
    if(enInterrupt&Watchdog_enInterruptNMI)
    {
        IE1|=NMIIE;
    }
    if(enInterrupt&Watchdog_enInterruptWDT)
    {
        IE1|=WDTIE;
    }
}
void Watchdog__vDisableInterrupt(Watchdog_nInterrupt enInterrupt)
{
    if(enInterrupt&Watchdog_enInterruptNMI)
    {
        IE1&=~NMIIE;
    }
    if(enInterrupt&Watchdog_enInterruptWDT)
    {
        IE1&=~WDTIE;
    }
}



void Watchdog__vSetInterrupt(Watchdog_nInterrupt enInterrupt)
{
    if(enInterrupt&Watchdog_enInterruptNMI)
    {
        IFG1|=NMIIFG;
    }
    if(enInterrupt&Watchdog_enInterruptWDT)
    {
        IFG1|=WDTIFG;
    }
}
void Watchdog__vClearInterrupt(Watchdog_nInterrupt enInterrupt)
{
    if(enInterrupt&Watchdog_enInterruptNMI)
    {
        IFG1&=~NMIIFG;
    }
    if(enInterrupt&Watchdog_enInterruptWDT)
    {
        IFG1&=~WDTIFG;
    }
}
