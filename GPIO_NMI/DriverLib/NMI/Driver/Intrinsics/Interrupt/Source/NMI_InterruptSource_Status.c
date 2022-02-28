/**
 *
 * @file NMI_InterruptSource_Status.c
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
 * @verbatim 25 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 25 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/NMI/Driver/Intrinsics/Interrupt/Header/NMI_InterruptSource_Status.h"

#include "DriverLib/NMI/Driver/Intrinsics/Primitives/NMI_Primitives.h"
#include "DriverLib/NMI/Peripheral/NMI_Peripheral.h"

void NMI__vSetStatusInterruptSource(NMI_nINT_STATUS enStatus)
{
    NMI__vWriteRegister_8bits(NMI_IFG1_OFFSET,
                         (uint8_t) enStatus,
                         NMI_IFG1_IFG_MASK,
                         NMI_IFG1_R_IFG_BIT);
}

NMI_nINT_STATUS NMI__enGetStatusInterruptSource(void)
{
    NMI_nINT_STATUS enStatus = NMI_enINT_STATUS_NOOCCUR;
    enStatus = (NMI_nINT_STATUS) NMI__u8ReadRegister(NMI_IFG1_OFFSET,
                                                         NMI_IFG1_IFG_MASK,
                                                         NMI_IFG1_R_IFG_BIT);
    return (enStatus);
}



