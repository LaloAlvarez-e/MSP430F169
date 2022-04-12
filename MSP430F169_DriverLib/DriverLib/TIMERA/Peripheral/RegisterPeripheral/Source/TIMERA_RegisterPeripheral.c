/**
 *
 * @file TIMERA_RegisterPeripheral.c
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
#include "DriverLib/TIMERA/Peripheral/RegisterPeripheral/TIMERA_RegisterPeripheral.h"
#include "DriverLib/TIMERA/Peripheral/Header/TIMERA_Enum.h"

uintptr_t TIMERA_CC__uptrBlockBaseAddress(TIMERA_nCC enModuleArg)
{
    const uintptr_t TIMERA_BLOCK_BASE[(uint8_t) TIMERA_enCC_MAX] =
    {
         TIMERA_CC0_BASE, TIMERA_CC1_BASE, TIMERA_CC2_BASE
    };
    uintptr_t uptrReg = 0UL;
    uptrReg = TIMERA_BLOCK_BASE[(uint8_t) enModuleArg];
    return(uptrReg);
}

uintptr_t TIMERA__uptrBlockBaseAddress(void)
{
    uintptr_t uptrReg = 0U;
    uptrReg = TIMERA_BASE;
    return(uptrReg);
}




