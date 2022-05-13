/**
 *
 * @file DAC12_PowerState.c
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
 * @verbatim 21 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 21 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <DriverLib/DAC12/Driver/Global/Header/DAC12_PowerState.h>
#include "DriverLib/DAC12/Driver/Intrinsics/DAC12_Intrinsics.h"
#include "DriverLib/DAC12/Peripheral/DAC12_Peripheral.h"

void DAC12__vSetPowerCoreState(DAC12_nSTATE enStateArg)
{
    DAC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CTL0_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enStateArg;
    pstRegisterData.u16Mask = DAC12_CTL0_ON_MASK;
    pstRegisterData.u8Shift = DAC12_CTL0_R_ON_BIT;
    DAC12__vWriteRegister(&pstRegisterData);
}

void DAC12__vPowerOnCore(void)
{
    DAC12__vSetPowerCoreState(DAC12_enSTATE_ON);
}

void DAC12__vPowerOffCore(void)
{
    DAC12__vSetPowerCoreState(DAC12_enSTATE_OFF);
}

DAC12_nSTATE DAC12__enGetPowerCoreState(void)
{
    DAC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CTL0_OFFSET;
    pstRegisterData.u16Value = (uint16_t) DAC12_enSTATE_OFF;
    pstRegisterData.u16Mask = DAC12_CTL0_ON_MASK;
    pstRegisterData.u8Shift = DAC12_CTL0_R_ON_BIT;
    (void) DAC12__u16ReadRegister(&pstRegisterData);
    return ((DAC12_nSTATE) pstRegisterData.u16Value);
}







