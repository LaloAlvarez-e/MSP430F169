/**
 *
 * @file ADC12_VoltageReference.c
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
#include <DriverLib/ADC12/Driver/Channel/Config/Header/ADC12_VoltageReference.h>
#include "DriverLib/ADC12/Driver/Intrinsics/ADC12_Intrinsics.h"
#include "DriverLib/ADC12/Peripheral/ADC12_Peripheral.h"

void ADC12_CH__vSetVoltageRefPositive(ADC12_nCH enChannelArg,
                                     ADC12_nVREFP enVoltageRefArg)
{
    ADC12_Register8Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CH_CTL_OFFSET;
    pstRegisterData.u8Value = (uint8_t) enVoltageRefArg;
    pstRegisterData.u8Mask = ADC12_CH_CTL_SREFP_MASK;
    pstRegisterData.u8Shift = ADC12_CH_CTL_R_SREFP_BIT;
    ADC12_CH__vWriteRegister_8bits(enChannelArg,
                         &pstRegisterData);

}

ADC12_nVREFP ADC12_CH__enGetVoltageRefPositive(ADC12_nCH enChannelArg)
{
    ADC12_Register8Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CH_CTL_OFFSET;
    pstRegisterData.u8Value = (uint8_t) ADC12_enVREFP_VCC;
    pstRegisterData.u8Mask = ADC12_CH_CTL_SREFP_MASK;
    pstRegisterData.u8Shift = ADC12_CH_CTL_R_SREFP_BIT;
    (void) ADC12_CH__u8ReadRegister(enChannelArg, &pstRegisterData);
    return ((ADC12_nVREFP) pstRegisterData.u8Value);
}


void ADC12_CH__vSetVoltageRefNegative(ADC12_nCH enChannelArg,
                                     ADC12_nVREFN enVoltageRefArg)
{
    ADC12_Register8Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CH_CTL_OFFSET;
    pstRegisterData.u8Value = (uint8_t) enVoltageRefArg;
    pstRegisterData.u8Mask = ADC12_CH_CTL_SREFN_MASK;
    pstRegisterData.u8Shift = ADC12_CH_CTL_R_SREFN_BIT;
    ADC12_CH__vWriteRegister_8bits(enChannelArg,
                         &pstRegisterData);

}

ADC12_nVREFN ADC12_CH__enGetVoltageRefNegative(ADC12_nCH enChannelArg)
{
    ADC12_Register8Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CH_CTL_OFFSET;
    pstRegisterData.u8Value = (uint8_t) ADC12_enVREFN_GND;
    pstRegisterData.u8Mask = ADC12_CH_CTL_SREFN_MASK;
    pstRegisterData.u8Shift = ADC12_CH_CTL_R_SREFN_BIT;
    (void) ADC12_CH__u8ReadRegister(enChannelArg, &pstRegisterData);
    return ((ADC12_nVREFN) pstRegisterData.u8Value);
}




