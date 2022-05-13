/**
 *
 * @file DAC12_VoltageReference.c
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
 * @verbatim 23 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 23 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <DriverLib/DAC12/Driver/Channel/Config/Header/DAC12_VoltageReference.h>
#include "DriverLib/DAC12/Driver/Intrinsics/DAC12_Intrinsics.h"
#include "DriverLib/DAC12/Peripheral/DAC12_Peripheral.h"

void DAC12_CH__vSetVoltageRefPositive(DAC12_nCH enChannelArg,
                                     DAC12_nVREFP enVoltageRefArg)
{
    DAC12_Register8Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CH_CTL_OFFSET;
    pstRegisterData.u8Value = (uint8_t) enVoltageRefArg;
    pstRegisterData.u8Mask = DAC12_CH_CTL_SREFP_MASK;
    pstRegisterData.u8Shift = DAC12_CH_CTL_R_SREFP_BIT;
    DAC12_CH__vWriteRegister_8bits(enChannelArg,
                         &pstRegisterData);

}

DAC12_nVREFP DAC12_CH__enGetVoltageRefPositive(DAC12_nCH enChannelArg)
{
    DAC12_Register8Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CH_CTL_OFFSET;
    pstRegisterData.u8Value = (uint8_t) DAC12_enVREFP_VCC;
    pstRegisterData.u8Mask = DAC12_CH_CTL_SREFP_MASK;
    pstRegisterData.u8Shift = DAC12_CH_CTL_R_SREFP_BIT;
    (void) DAC12_CH__u8ReadRegister(enChannelArg, &pstRegisterData);
    return ((DAC12_nVREFP) pstRegisterData.u8Value);
}


void DAC12_CH__vSetVoltageRefNegative(DAC12_nCH enChannelArg,
                                     DAC12_nVREFN enVoltageRefArg)
{
    DAC12_Register8Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CH_CTL_OFFSET;
    pstRegisterData.u8Value = (uint8_t) enVoltageRefArg;
    pstRegisterData.u8Mask = DAC12_CH_CTL_SREFN_MASK;
    pstRegisterData.u8Shift = DAC12_CH_CTL_R_SREFN_BIT;
    DAC12_CH__vWriteRegister_8bits(enChannelArg,
                         &pstRegisterData);

}

DAC12_nVREFN DAC12_CH__enGetVoltageRefNegative(DAC12_nCH enChannelArg)
{
    DAC12_Register8Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CH_CTL_OFFSET;
    pstRegisterData.u8Value = (uint8_t) DAC12_enVREFN_GND;
    pstRegisterData.u8Mask = DAC12_CH_CTL_SREFN_MASK;
    pstRegisterData.u8Shift = DAC12_CH_CTL_R_SREFN_BIT;
    (void) DAC12_CH__u8ReadRegister(enChannelArg, &pstRegisterData);
    return ((DAC12_nVREFN) pstRegisterData.u8Value);
}




