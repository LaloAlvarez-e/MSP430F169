/**
 *
 * @file WDT_InterruptSource_Clear.c
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
#include "DriverLib/WDT/Driver/Intrinsics/Interrupt/Header/WDT_InterruptSource_Clear.h"

#include "DriverLib/WDT/Driver/Intrinsics/Primitives/WDT_Primitives.h"
#include "DriverLib/WDT/Peripheral/WDT_Peripheral.h"

void WDT__vClearInterruptSource(void)
{
    WDT__vWriteRegister_8bits(WDT_IFG1_OFFSET,
                         WDT_IFG1_IFG_NOOCCUR,
                         WDT_IFG1_IFG_MASK,
                         WDT_IFG1_R_IFG_BIT);
}
