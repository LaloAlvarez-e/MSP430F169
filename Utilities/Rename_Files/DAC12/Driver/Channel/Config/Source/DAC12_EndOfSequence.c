/**
 *
 * @file DAC12_EndOfSequence.c
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
#include <DriverLib/DAC12/Driver/Channel/Config/Header/DAC12_EndOfSequence.h>
#include "DriverLib/DAC12/Driver/Intrinsics/DAC12_Intrinsics.h"
#include "DriverLib/DAC12/Peripheral/DAC12_Peripheral.h"

void DAC12_CH__vSetEndOfSequence(DAC12_nCH enChannelArg,
                          DAC12_nENABLE enEnableArg)
{
    DAC12_Register8Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CH_CTL_OFFSET;
    pstRegisterData.u8Value = (uint8_t) enEnableArg;
    pstRegisterData.u8Mask = DAC12_CH_CTL_EOS_MASK;
    pstRegisterData.u8Shift = DAC12_CH_CTL_R_EOS_BIT;
    DAC12_CH__vWriteRegister_8bits(enChannelArg,
                         &pstRegisterData);

}

DAC12_nENABLE DAC12_CH__enGetEndOfSequence(DAC12_nCH enChannelArg)
{
    DAC12_Register8Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CH_CTL_OFFSET;
    pstRegisterData.u8Value = (uint8_t) DAC12_enENABLE_DIS;
    pstRegisterData.u8Mask = DAC12_CH_CTL_EOS_MASK;
    pstRegisterData.u8Shift = DAC12_CH_CTL_R_EOS_BIT;
    (void) DAC12_CH__u8ReadRegister(enChannelArg, &pstRegisterData);
    return ((DAC12_nENABLE) pstRegisterData.u8Value);
}




