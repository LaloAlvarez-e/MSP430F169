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
 * @verbatim 11 may. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 11 may. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <DriverLib/DAC12/Driver/Channel/Config/Header/DAC12_EnableConversion.h>

#include "DriverLib/DAC12/Driver/Intrinsics/DAC12_Intrinsics.h"
#include "DriverLib/DAC12/Peripheral/DAC12_Peripheral.h"

void DAC12_CH__vSetEnableConversion(DAC12_nCH enChannelArg,
                                    DAC12_nENABLE enEnableArg)
{
    DAC12_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CH_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enEnableArg;
    pstRegisterData.u16Mask = DAC12_CH_CTL_ENC_MASK;
    pstRegisterData.u8Shift = DAC12_CH_CTL_R_ENC_BIT;
    DAC12_CH__vWriteRegister(enChannelArg, &pstRegisterData);
}

void DAC12_CH__vEnableConversion(DAC12_nCH enChannelArg)
{
    DAC12_CH__vSetEnableConversion(enChannelArg, DAC12_enENABLE_ENA);
}

void DAC12_CH__vDisableConversion(DAC12_nCH enChannelArg)
{
    DAC12_CH__vSetEnableConversion(enChannelArg, DAC12_enENABLE_DIS);
}

DAC12_nENABLE DAC12_CH__enGetEnableConversion(DAC12_nCH enChannelArg)
{
    DAC12_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CH_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) DAC12_enENABLE_DIS;
    pstRegisterData.u16Mask = DAC12_CH_CTL_ENC_MASK;
    pstRegisterData.u8Shift = DAC12_CH_CTL_R_ENC_BIT;
    (void) DAC12_CH__u16ReadRegister(enChannelArg, &pstRegisterData);
    return ((DAC12_nENABLE) pstRegisterData.u16Value);
}




