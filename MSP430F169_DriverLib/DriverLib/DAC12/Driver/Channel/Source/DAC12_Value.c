/**
 *
 * @file DAC12_Value.c
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
#include <DriverLib/DAC12/Driver/Channel/Header/DAC12_Value.h>
#include "DriverLib/DAC12/Driver/Intrinsics/DAC12_Intrinsics.h"
#include "DriverLib/DAC12/Peripheral/DAC12_Peripheral.h"

void DAC12__vSetValue(DAC12_nCH enChannelArg, uint16_t u16ValueArg)
{
    DAC12_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CH_DAT_OFFSET;
    pstRegisterData.u16Value = u16ValueArg;
    pstRegisterData.u16Mask = DAC12_CH_DAT_DATA_MASK;
    pstRegisterData.u8Shift = DAC12_CH_DAT_R_DATA_BIT;
    (void) DAC12_CH__vWriteRegister(enChannelArg, &pstRegisterData);
}

uint16_t DAC12__u16GetValue(DAC12_nCH enChannelArg)
{
    DAC12_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CH_DAT_OFFSET;
    pstRegisterData.u16Value = 0U;
    pstRegisterData.u16Mask = DAC12_CH_DAT_DATA_MASK;
    pstRegisterData.u8Shift = DAC12_CH_DAT_R_DATA_BIT;
    (void) DAC12_CH__u16ReadRegister(enChannelArg, &pstRegisterData);
    return (pstRegisterData.u16Value);
}




