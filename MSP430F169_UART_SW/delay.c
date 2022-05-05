/**
 *
 * @file delay.c
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
 * @verbatim 4 may. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 4 may. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#include "delay.h"
#include "DriverLib/DriverLib.h"

uint16_t Delay_u16Handler(uintptr_t uptrModule, uint16_t u16IntSource);

uint32_t u32DelayOverflow = 0U;
uint32_t u32DelayOld = 0U;
uint32_t u32Delay = 0U;

void Delay__vInit(void)
{

    TIMERA_CC__vRegisterIRQSourceHandler(TIMERA_enCC1,
                                       TIMERA_enCC_MODE_COMPARE,
                                       &Delay_u16Handler);
    TIMERA_CC1_R_R = 8000U - 1U;
    TIMERA_CC1_CTL_R =  TIMERA_CC_CTL_R_IE_ENA;
}

void Delay__vmiliseconds(uint16_t u16DelayArg)
{
    uint32_t u32DifArg = 0U;
    u32DifArg = u32DelayOverflow;
    u32DifArg += u16DelayArg;
    while(u32DelayOverflow != u32DifArg)
    {
        __bis_SR_register(LPM1_bits);
    }
}


uint16_t Delay_u16Handler(uintptr_t uptrModule, uint16_t u16IntSource)
{
    TIMERA_CC1_R_R += 8000U;
    u32DelayOverflow++;
    return 0U;
}

