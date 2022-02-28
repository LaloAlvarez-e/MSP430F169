/**
 *
 * @file NMI_InterruptSource_Enable.c
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
#include "DriverLib/NMI/Driver/Intrinsics/Interrupt/Header/NMI_InterruptSource_Enable.h"

#include "DriverLib/NMI/Driver/Intrinsics/Primitives/NMI_Primitives.h"
#include "DriverLib/NMI/Peripheral/NMI_Peripheral.h"

void NMI__vSetEnableInterruptSource(NMI_nINT_ENABLE enState)
{
    NMI__vWriteRegister_8bits(NMI_IE1_OFFSET,
                         (uint8_t) enState,
                         NMI_IE1_IE_MASK,
                         NMI_IE1_R_IE_BIT);
}

void NMI__vEnaInterruptSource(void)
{
    NMI__vSetEnableInterruptSource(NMI_enINT_ENABLE_ENA);
}

void NMI__vDisInterruptSource(void)
{
    NMI__vSetEnableInterruptSource(NMI_enINT_ENABLE_DIS);
}

NMI_nINT_ENABLE NMI__enGetEnableInterruptSource(void)
{
    NMI_nINT_ENABLE enEnable = NMI_enINT_ENABLE_DIS;
    enEnable = (NMI_nINT_ENABLE) NMI__u8ReadRegister(NMI_IE1_OFFSET,
                                                NMI_IE1_IE_MASK,
                                                NMI_IE1_R_IE_BIT);
    return (enEnable);
}

