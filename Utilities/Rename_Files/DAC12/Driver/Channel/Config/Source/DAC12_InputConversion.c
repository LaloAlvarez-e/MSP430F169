/**
 *
 * @file DAC12_InputConversion.c
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
#include <DriverLib/DAC12/Driver/Channel/Config/Header/DAC12_InputConversion.h>
#include "DriverLib/DAC12/Driver/Intrinsics/DAC12_Intrinsics.h"
#include "DriverLib/DAC12/Peripheral/DAC12_Peripheral.h"

void DAC12_CH__vSetInputConversion(DAC12_nCH enChannelArg,
                          DAC12_nINPUT enEnableArg)
{
    DAC12_Register8Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CH_CTL_OFFSET;
    pstRegisterData.u8Value = (uint8_t) enEnableArg;
    pstRegisterData.u8Mask = DAC12_CH_CTL_INCH_MASK;
    pstRegisterData.u8Shift = DAC12_CH_CTL_R_INCH_BIT;
    DAC12_CH__vWriteRegister_8bits(enChannelArg,
                         &pstRegisterData);

}

DAC12_nINPUT DAC12_CH__enGetInputConversion(DAC12_nCH enChannelArg)
{
    DAC12_Register8Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CH_CTL_OFFSET;
    pstRegisterData.u8Value = (uint8_t) DAC12_enINPUT_A0;
    pstRegisterData.u8Mask = DAC12_CH_CTL_INCH_MASK;
    pstRegisterData.u8Shift = DAC12_CH_CTL_R_INCH_BIT;
    (void) DAC12_CH__u8ReadRegister(enChannelArg, &pstRegisterData);
    return ((DAC12_nINPUT) pstRegisterData.u8Value);
}





