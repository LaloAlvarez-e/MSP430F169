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
#include "DriverLib/CLOCK/Driver/Intrinsics/Interrupt/Header/CLOCK_InterruptSource_Enable.h"

#include "DriverLib/CLOCK/Driver/Intrinsics/Primitives/CLOCK_Primitives.h"
#include "DriverLib/CLOCK/Peripheral/CLOCK_Peripheral.h"

void CLOCK__vSetEnableInterruptSource(CLOCK_nINT_ENABLE enState)
{
    CLOCK_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = CLOCK_IE1_OFFSET;
    pstRegisterData.u8Value = (uint8_t) enState;
    pstRegisterData.u8Mask = CLOCK_IE1_IE_MASK;
    pstRegisterData.u8Shift = CLOCK_IE1_R_IE_BIT;

    CLOCK__vWriteRegister(&pstRegisterData);
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
    CLOCK_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = CLOCK_IE1_OFFSET;
    pstRegisterData.u8Value = (uint8_t) CLOCK_enINT_ENABLE_DIS;
    pstRegisterData.u8Mask = CLOCK_IE1_IE_MASK;
    pstRegisterData.u8Shift = CLOCK_IE1_R_IE_BIT;

    (void) CLOCK__u8ReadRegister(&pstRegisterData);

    return ((CLOCK_nINT_ENABLE) pstRegisterData.u8Value);
}


