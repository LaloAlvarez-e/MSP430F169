/**
 *
 * @file CLOCK_Frequency.c
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
#include "DriverLib/CLOCK/Driver/Header/CLOCK_Frequency.h"

#include "DriverLib/CLOCK/Driver/Header/CLOCK_Selector.h"
#include "DriverLib/CLOCK/Driver/Header/CLOCK_LFXT1.h"
#include "DriverLib/CLOCK/Driver/Header/CLOCK_XT2.h"
#include "DriverLib/CLOCK/Driver/DCO/CLOCK_DCO.h"

uint32_t CLOCK__u32GetFrequency(CLOCK_nSIGNAL enClockSignal)
{
    uint32_t u32FrequencyReg;
    CLOCK_nSOURCE enClockSourceR;
    enClockSourceR = CLOCK__enGetSource(enClockSignal);
    switch(enClockSourceR)
    {
    case CLOCK_enSOURCE_LFXT1:
        u32FrequencyReg = CLOCK__u32GetLFXT1Frequency();
        break;
    case CLOCK_enSOURCE_XT2:
        u32FrequencyReg = CLOCK__u32GetXT2Frequency();
        break;
    case CLOCK_enSOURCE_DCO:
        u32FrequencyReg = CLOCK__u32GetDCOFrequency();
        break;
    default:
        u32FrequencyReg = 0U;
        break;
    }

    return (u32FrequencyReg);
}

uint32_t CLOCK__u32GetMCLKFrequency(void)
{
    uint32_t u32FrequencyReg;
    u32FrequencyReg = CLOCK__u32GetFrequency(CLOCK_enSIGNAL_MCLK);
    return (u32FrequencyReg);
}


uint32_t CLOCK__u32GetSMCLKFrequency(void)
{
    uint32_t u32FrequencyReg;
    u32FrequencyReg = CLOCK__u32GetFrequency(CLOCK_enSIGNAL_SMCLK);
    return (u32FrequencyReg);
}


uint32_t CLOCK__u32GetACLKFrequency(void)
{
    uint32_t u32FrequencyReg;
    u32FrequencyReg = CLOCK__u32GetFrequency(CLOCK_enSIGNAL_ACLK);
    return (u32FrequencyReg);
}



