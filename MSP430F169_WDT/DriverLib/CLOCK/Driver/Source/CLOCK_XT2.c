/**
 *
 * @file CLOCK_XT2.c
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
#include "DriverLib/CLOCK/Driver/Header/CLOCK_XT2.h"

#define CLOCK_XT2_FREQ (8000000UL)

uint32_t CLOCK__u32GetXT2Frequency(void)
{
    const uint32_t u32XT2FreqReg = CLOCK_XT2_FREQ;
    return (u32XT2FreqReg);
}



