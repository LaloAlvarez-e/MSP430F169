/**
 *
 * @file DAC12_EnableConversion.c
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
#include <DriverLib/DAC12/Driver/Global/Header/DAC12_EnableConversion.h>
#include "DriverLib/DAC12/Driver/Intrinsics/DAC12_Intrinsics.h"
#include "DriverLib/DAC12/Peripheral/DAC12_Peripheral.h"

void DAC12__vSetEnableConversion(DAC12_nENABLE enEnableArg)
{
    DAC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CTL0_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enEnableArg;
    pstRegisterData.u16Mask = DAC12_CTL0_ENC_MASK;
    pstRegisterData.u8Shift = DAC12_CTL0_R_ENC_BIT;
    DAC12__vWriteRegister(&pstRegisterData);
}

void DAC12__vEnableConversion(void)
{
    DAC12__vSetEnableConversion(DAC12_enENABLE_ENA);
}

void DAC12__vDisableConversion(void)
{
    DAC12__vSetEnableConversion(DAC12_enENABLE_DIS);
}

void DAC12__vRestartEnableConversion(void)
{
    DAC12__vDisableConversion();
    DAC12__vEnableConversion();
}

DAC12_nENABLE DAC12__enGetEnableConversion(void)
{
    DAC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CTL0_OFFSET;
    pstRegisterData.u16Value = (uint16_t) DAC12_enENABLE_DIS;
    pstRegisterData.u16Mask = DAC12_CTL0_ENC_MASK;
    pstRegisterData.u8Shift = DAC12_CTL0_R_ENC_BIT;
    (void) DAC12__u16ReadRegister(&pstRegisterData);
    return ((DAC12_nENABLE) pstRegisterData.u16Value);
}





