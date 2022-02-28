/**
 *
 * @file CLOCK_InterruptSource_Status.c
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
 * @verbatim 12 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 12 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/CLOCK/Driver/Intrinsics/Interrupt/Header/CLOCK_InterruptSource_Status.h"

#include "DriverLib/CLOCK/Driver/Intrinsics/Primitives/CLOCK_Primitives.h"
#include "DriverLib/CLOCK/Peripheral/CLOCK_Peripheral.h"

void CLOCK__vSetStatusInterruptSource(CLOCK_nINT_STATUS enStatus)
{
    CLOCK__vWriteRegister(CLOCK_IFG1_OFFSET,
                         (uint8_t) enStatus,
                         CLOCK_IFG1_OFIFG_MASK,
                         CLOCK_IFG1_R_OFIFG_BIT);
}

CLOCK_nINT_STATUS CLOCK__enGetStatusInterruptSource(void)
{
    CLOCK_nINT_STATUS enStatus = CLOCK_enINT_STATUS_NOOCCUR;
    enStatus = (CLOCK_nINT_STATUS) CLOCK__u8ReadRegister(CLOCK_IFG1_OFFSET,
                                                         CLOCK_IFG1_OFIFG_MASK,
                                                         CLOCK_IFG1_R_OFIFG_BIT);
    return (enStatus);
}
