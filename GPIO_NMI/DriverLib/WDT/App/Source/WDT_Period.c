/**
 *
 * @file WDT_Period.c
 * @copyright
 * @verbatim InDeviceMex 2021 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 26 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 26 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/WDT/App/Header/WDT_Period.h"

#include "DriverLib/CLOCK/CLOCK.h"
#include "DriverLib/WDT/Driver/WDT_Driver.h"

uint32_t WDT__u32GetPeriodus(void)
{
    uint16_t u16IntervalReg = 0U;
    uint32_t u32SysFreqReq = 0U;
    uint32_t u32PeriodReg = 0UL;
    WDT_nCLOCK enClockReg = WDT_enCLOCK_SMCLK;

    u16IntervalReg = WDT__u16GetInterval();
    enClockReg = WDT__enGetClock();
    if(WDT_enCLOCK_SMCLK == enClockReg)
    {
        u32SysFreqReq = CLOCK__u32GetFrequency(CLOCK_enSIGNAL_SMCLK);
    }
    else
    {
        u32SysFreqReq = CLOCK__u32GetFrequency(CLOCK_enSIGNAL_ACLK);
    }
    if(0UL != u32SysFreqReq)
    {
        u32PeriodReg = 1000000UL;
        u32PeriodReg *= (uint32_t) u16IntervalReg;
        u32PeriodReg /= u32SysFreqReq;
    }
    return (u32PeriodReg);
}




