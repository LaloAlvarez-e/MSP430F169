/**
 *
 * @file CLOCK_FreqSelect.c
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
 * @verbatim 15 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 15 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/CLOCK/Driver/DCO/Header/CLOCK_FreqSelect.h"

#include "DriverLib/CLOCK/Driver/Intrinsics/Primitives/CLOCK_Primitives.h"
#include "DriverLib/CLOCK/Peripheral/CLOCK_Peripheral.h"

void CLOCK__vSetDCOFreqSelect(uint8_t u8FreqSelection)
{
    CLOCK__vWriteRegister(CLOCK_DCOCTL_OFFSET,
                          u8FreqSelection,
                         CLOCK_DCOCTL_DCO_MASK,
                         CLOCK_DCOCTL_R_DCO_BIT);
}

uint8_t CLOCK__u8GetDCOFreqSelect(void)
{
    uint8_t u8FreqSelectionReg = 0U;

    u8FreqSelectionReg = CLOCK__u8ReadRegister(CLOCK_DCOCTL_OFFSET,
                                             CLOCK_DCOCTL_DCO_MASK,
                                             CLOCK_DCOCTL_R_DCO_BIT);
    return (u8FreqSelectionReg);
}
