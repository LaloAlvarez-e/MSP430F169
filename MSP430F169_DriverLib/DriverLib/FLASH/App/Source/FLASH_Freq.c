/**
 *
 * @file FLASH_Freq.c
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
#include "DriverLib/FLASH/App/Header/FLASH_Freq.h"

#include "DriverLib/CLOCK/CLOCK.h"
#include "DriverLib/FLASH/Driver/FLASH_Driver.h"

uint32_t FLASH__u32GetFrequency(void)
{
    uint16_t u16IntervalReg = 0U;
    uint32_t u32SysFreqReq = 0U;
    uint32_t u32FreqReg = 0UL;
    FLASH_nCLOCK enClockReg = FLASH_enCLOCK_SMCLK;

    u16IntervalReg = FLASH__u16GetInterval();
    enClockReg = FLASH__enGetClock();
    if(FLASH_enCLOCK_SMCLK == enClockReg)
    {
        u32SysFreqReq = CLOCK__u32GetFrequency(CLOCK_enSIGNAL_SMCLK);
    }
    else
    {
        u32SysFreqReq = CLOCK__u32GetFrequency(CLOCK_enSIGNAL_ACLK);
    }
    if(0UL != u32SysFreqReq)
    {
        u32FreqReg = u32SysFreqReq;
        u32FreqReg /= (uint32_t) u16IntervalReg;
    }
    return (u32FreqReg);
}



