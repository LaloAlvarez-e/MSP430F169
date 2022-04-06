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
    NMI_Register8Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = NMI_IE1_OFFSET;
    pstRegisterData.u8Value = (uint8_t) enState;
    pstRegisterData.u8Mask = NMI_IE1_IE_MASK;
    pstRegisterData.u8Shift = NMI_IE1_R_IE_BIT;

    NMI__vWriteRegister_8bits(&pstRegisterData);
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
    NMI_Register8Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = NMI_IE1_OFFSET;
    pstRegisterData.u8Value = (uint8_t) NMI_enINT_ENABLE_DIS;
    pstRegisterData.u8Mask = NMI_IE1_IE_MASK;
    pstRegisterData.u8Shift = NMI_IE1_R_IE_BIT;

    (void) NMI__u8ReadRegister(&pstRegisterData);
    return ((NMI_nINT_ENABLE) pstRegisterData.u8Value);
}

