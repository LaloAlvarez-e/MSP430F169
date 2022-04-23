/**
 *
 * @file ADC12_EndOfSequence.c
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
#include <DriverLib/ADC12/Driver/Channel/Config/Header/ADC12_EndOfSequence.h>
#include "DriverLib/ADC12/Driver/Intrinsics/ADC12_Intrinsics.h"
#include "DriverLib/ADC12/Peripheral/ADC12_Peripheral.h"

void ADC12_CH__vSetEndOfSequence(ADC12_nCH enChannelArg,
                          ADC12_nENABLE enEnableArg)
{
    ADC12_Register8Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CH_CTL_OFFSET;
    pstRegisterData.u8Value = (uint8_t) enEnableArg;
    pstRegisterData.u8Mask = ADC12_CH_CTL_EOS_MASK;
    pstRegisterData.u8Shift = ADC12_CH_CTL_R_EOS_BIT;
    ADC12_CH__vWriteRegister_8bits(enChannelArg,
                         &pstRegisterData);

}

ADC12_nENABLE ADC12_CH__enGetEndOfSequence(ADC12_nCH enChannelArg)
{
    ADC12_Register8Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CH_CTL_OFFSET;
    pstRegisterData.u8Value = (uint8_t) ADC12_enENABLE_DIS;
    pstRegisterData.u8Mask = ADC12_CH_CTL_EOS_MASK;
    pstRegisterData.u8Shift = ADC12_CH_CTL_R_EOS_BIT;
    (void) ADC12_CH__u8ReadRegister(enChannelArg, &pstRegisterData);
    return ((ADC12_nENABLE) pstRegisterData.u8Value);
}




