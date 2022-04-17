/**
 *
 * @file TIMERB_RegisterPeripheral.c
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
 * @verbatim 6 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 6 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/TIMERB/Peripheral/RegisterPeripheral/TIMERB_RegisterPeripheral.h"
#include "DriverLib/TIMERB/Peripheral/Header/TIMERB_Enum.h"

uintptr_t TIMERB_CC__uptrBlockBaseAddress(TIMERB_nCC enModuleArg)
{
    const uintptr_t TIMERB_BLOCK_BASE[(uint8_t) TIMERB_enCC_MAX] =
    {
         TIMERB_CC0_BASE, TIMERB_CC1_BASE, TIMERB_CC2_BASE,
         TIMERB_CC3_BASE, TIMERB_CC4_BASE, TIMERB_CC5_BASE,
         TIMERB_CC6_BASE
    };
    uintptr_t uptrReg = 0UL;
    uptrReg = TIMERB_BLOCK_BASE[(uint8_t) enModuleArg];
    return(uptrReg);
}

uintptr_t TIMERB__uptrBlockBaseAddress(void)
{
    uintptr_t uptrReg = 0U;
    uptrReg = TIMERB_BASE;
    return(uptrReg);
}




