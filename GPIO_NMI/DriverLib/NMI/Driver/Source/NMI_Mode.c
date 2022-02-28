/**
 *
 * @file NMI_Mode.c
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
#include "DriverLib/NMI/Driver/Header/NMI_Mode.h"

#include "DriverLib/NMI/Driver/Intrinsics/Primitives/NMI_Primitives.h"
#include "DriverLib/NMI/Peripheral/NMI_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

void NMI__vSetMode(NMI_nMODE enModeArg)
{
    uint16_t u16Value = 0U;
    u16Value = (uint16_t) enModeArg;
    u16Value <<= NMI_CTL_R_NMI_BIT;
    u16Value |= NMI_CTL_R_PW_WRITE;
    NMI__vWriteRegister_16bits(NMI_CTL_OFFSET, u16Value,
                               NMI_CTL_R_PW_MASK | NMI_CTL_R_NMI_MASK,
                               0UL);
}

NMI_nMODE NMI__enGetMode(void)
{
    NMI_nMODE enModeReg = NMI_enMODE_NMI;
    enModeReg = (NMI_nMODE) NMI__u16ReadRegister(NMI_CTL_OFFSET,
                                       NMI_CTL_NMI_MASK,
                                       NMI_CTL_R_NMI_BIT);

    return (enModeReg);
}




