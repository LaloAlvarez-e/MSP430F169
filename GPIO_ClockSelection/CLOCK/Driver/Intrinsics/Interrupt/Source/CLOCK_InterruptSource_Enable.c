/**
 *
 * @file CLOCK_InterruptSource_Enable.c
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
#include "CLOCK/Driver/Intrinsics/Interrupt/Header/CLOCK_InterruptSource_Enable.h"

#include "CLOCK/Driver/Intrinsics/Primitives/CLOCK_Primitives.h"
#include "CLOCK/Peripheral/CLOCK_Peripheral.h"

void CLOCK__vSetEnableInterruptSource(CLOCK_nINT_ENABLE enState)
{
    CLOCK__vWriteRegister(CLOCK_IE1_OFFSET,
                         (uint8_t) enState,
                         CLOCK_IE1_OFIE_MASK,
                         CLOCK_IE1_R_OFIE_BIT);
}

void CLOCK__vEnaInterruptSource(void)
{
    CLOCK__vSetEnableInterruptSource(CLOCK_enINT_ENABLE_ENA);
}

void CLOCK__vDisInterruptSource(void)
{
    CLOCK__vSetEnableInterruptSource(CLOCK_enINT_ENABLE_DIS);
}

CLOCK_nINT_ENABLE CLOCK__enGetEnableInterruptSource(void)
{
    CLOCK_nINT_ENABLE enEnable = CLOCK_enINT_ENABLE_DIS;
    enEnable = (CLOCK_nINT_ENABLE) CLOCK__u8ReadRegister(CLOCK_IE1_OFFSET,
                                                CLOCK_IE1_OFIE_MASK,
                                                CLOCK_IE1_R_OFIE_BIT);
    return (enEnable);
}


