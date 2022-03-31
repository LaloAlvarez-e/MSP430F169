/**
 *
 * @file WDT_InterruptSource_Enable.c
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
#include "DriverLib/WDT/Driver/Intrinsics/Interrupt/Header/WDT_InterruptSource_Enable.h"

#include "DriverLib/WDT/Driver/Intrinsics/Primitives/WDT_Primitives.h"
#include "DriverLib/WDT/Peripheral/WDT_Peripheral.h"

void WDT__vSetEnableInterruptSource(WDT_nINT_ENABLE enState)
{
    WDT__vWriteRegister_8bits(WDT_IE1_OFFSET,
                         (uint8_t) enState,
                         WDT_IE1_IE_MASK,
                         WDT_IE1_R_IE_BIT);
}

void WDT__vEnaInterruptSource(void)
{
    WDT__vSetEnableInterruptSource(WDT_enINT_ENABLE_ENA);
}

void WDT__vDisInterruptSource(void)
{
    WDT__vSetEnableInterruptSource(WDT_enINT_ENABLE_DIS);
}

WDT_nINT_ENABLE WDT__enGetEnableInterruptSource(void)
{
    WDT_nINT_ENABLE enEnable = WDT_enINT_ENABLE_DIS;
    enEnable = (WDT_nINT_ENABLE) WDT__u8ReadRegister(WDT_IE1_OFFSET,
                                                WDT_IE1_IE_MASK,
                                                WDT_IE1_R_IE_BIT);
    return (enEnable);
}

