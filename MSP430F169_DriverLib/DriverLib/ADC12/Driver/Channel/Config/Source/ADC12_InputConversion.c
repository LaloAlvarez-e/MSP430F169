/**
 *
 * @file ADC12_InputConversion.c
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
#include <DriverLib/ADC12/Driver/Channel/Config/Header/ADC12_InputConversion.h>
#include "DriverLib/ADC12/Driver/Intrinsics/ADC12_Intrinsics.h"
#include "DriverLib/ADC12/Peripheral/ADC12_Peripheral.h"

void ADC12_CH__vSetInputConversion(ADC12_nCH enChannelArg,
                          ADC12_nINPUT enEnableArg)
{
    ADC12_Register8Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CH_CTL_OFFSET;
    pstRegisterData.u8Value = (uint8_t) enEnableArg;
    pstRegisterData.u8Mask = ADC12_CH_CTL_INCH_MASK;
    pstRegisterData.u8Shift = ADC12_CH_CTL_R_INCH_BIT;
    ADC12_CH__vWriteRegister_8bits(enChannelArg,
                         &pstRegisterData);

}

ADC12_nINPUT ADC12_CH__enGetInputConversion(ADC12_nCH enChannelArg)
{
    ADC12_Register8Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CH_CTL_OFFSET;
    pstRegisterData.u8Value = (uint8_t) ADC12_enINPUT_A0;
    pstRegisterData.u8Mask = ADC12_CH_CTL_INCH_MASK;
    pstRegisterData.u8Shift = ADC12_CH_CTL_R_INCH_BIT;
    (void) ADC12_CH__u8ReadRegister(enChannelArg, &pstRegisterData);
    return ((ADC12_nINPUT) pstRegisterData.u8Value);
}





