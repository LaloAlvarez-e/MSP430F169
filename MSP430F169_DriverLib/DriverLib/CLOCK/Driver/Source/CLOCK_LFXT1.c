/**
 *
 * @file CLOCK_LFXT1.c
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
 * @verbatim 16 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 16 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/CLOCK/Driver/Header/CLOCK_LFXT1.h"

#include "DriverLib/CLOCK/Driver/Header/CLOCK_Mode.h"

#define CLOCK_LF_FREQ (32768UL)
#define CLOCK_XT1_FREQ (0UL)

uint32_t CLOCK__u32GetXT1Frequency(void)
{
    const uint32_t u32XT1FreqReg = CLOCK_XT1_FREQ;
    return (u32XT1FreqReg);
}

uint32_t CLOCK__u32GetLFFrequency(void)
{
    const uint32_t u32LFFreqReg = CLOCK_LF_FREQ;
    return (u32LFFreqReg);
}

uint32_t CLOCK__u32GetLFXT1Frequency(void)
{
    uint32_t u32LFXT1FreqReg = 0U;
    CLOCK_nFREQMODE enFreqModeReg = CLOCK_enFREQMODE_LOW;
    enFreqModeReg = CLOCK__enGetLFXT1FrequencyMode();
    switch(enFreqModeReg)
    {
    case CLOCK_enFREQMODE_LOW:
        u32LFXT1FreqReg = CLOCK__u32GetLFFrequency();
        break;
    case CLOCK_enFREQMODE_HIGH:
        u32LFXT1FreqReg = CLOCK__u32GetXT1Frequency();
        break;
    default:
        break;
    }
    return (u32LFXT1FreqReg);
}


