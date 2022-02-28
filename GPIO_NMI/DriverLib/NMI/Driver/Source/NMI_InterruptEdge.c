/**
 *
 * @file NMI_InterruptEdge.c
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
 * @verbatim 28 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 28 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/NMI/Driver/Header/NMI_InterruptEdge.h"

#include "DriverLib/NMI/Driver/Intrinsics/Primitives/NMI_Primitives.h"
#include "DriverLib/NMI/Peripheral/NMI_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

void NMI__vSetInterruptEdge(NMI_nINT_EDGE enInterruptEdgeArg)
{
    uint16_t u16Value = 0U;
    u16Value = (uint16_t) enInterruptEdgeArg;
    u16Value <<= NMI_CTL_R_NMIES_BIT;
    u16Value |= NMI_CTL_R_PW_WRITE;
    NMI__vWriteRegister_16bits(NMI_CTL_OFFSET, u16Value,
                               NMI_CTL_R_PW_MASK | NMI_CTL_R_NMIES_MASK,
                               0UL);
}

NMI_nINT_EDGE NMI__enGetInterruptEdge(void)
{
    NMI_nINT_EDGE enInterruptEdgeReg = NMI_enINT_EDGE_RISING;
    enInterruptEdgeReg = (NMI_nINT_EDGE) NMI__u16ReadRegister(NMI_CTL_OFFSET,
                                       NMI_CTL_NMIES_MASK,
                                       NMI_CTL_R_NMIES_BIT);

    return (enInterruptEdgeReg);
}





