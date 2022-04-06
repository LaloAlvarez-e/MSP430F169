/**
 *
 * @file CLOCK_ModulationSelection.c
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
#include "DriverLib/CLOCK/Driver/DCO/Header/CLOCK_Modulation.h"

#include "DriverLib/CLOCK/Driver/Intrinsics/Primitives/CLOCK_Primitives.h"
#include "DriverLib/CLOCK/Peripheral/CLOCK_Peripheral.h"

void CLOCK__vSetModulationSelection(uint8_t u8ModulationSelection)
{
    CLOCK_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = CLOCK_DCOCTL_OFFSET;
    pstRegisterData.u8Value = u8ModulationSelection;
    pstRegisterData.u8Mask = CLOCK_DCOCTL_MOD_MASK;
    pstRegisterData.u8Shift = CLOCK_DCOCTL_R_MOD_BIT;
    CLOCK__vWriteRegister(&pstRegisterData);
}

uint8_t CLOCK__u8GetModulationSelection(void)
{
    CLOCK_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = CLOCK_DCOCTL_OFFSET;
    pstRegisterData.u8Value = 0U;
    pstRegisterData.u8Mask = CLOCK_DCOCTL_MOD_MASK;
    pstRegisterData.u8Shift = CLOCK_DCOCTL_R_MOD_BIT;
    (void) CLOCK__u8ReadRegister(&pstRegisterData);
    return (pstRegisterData.u8Value);
}




