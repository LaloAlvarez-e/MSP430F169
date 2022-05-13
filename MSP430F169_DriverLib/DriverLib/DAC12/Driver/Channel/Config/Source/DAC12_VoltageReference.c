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

void DAC12_CH__vSetVoltageRef(DAC12_nCH enChannelArg,
                              DAC12_nVREF enVoltageRefArg)
{
    DAC12_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CH_CTL_OFFSET;
    pstRegisterData.u16Value = (uint8_t) enVoltageRefArg;
    pstRegisterData.u16Mask = DAC12_CH_CTL_SREF_MASK;
    pstRegisterData.u8Shift = DAC12_CH_CTL_R_SREF_BIT;
    DAC12_CH__vWriteRegister(enChannelArg,
                         &pstRegisterData);

}

DAC12_nVREF DAC12_CH__enGetVoltageRef(DAC12_nCH enChannelArg)
{
    DAC12_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CH_CTL_OFFSET;
    pstRegisterData.u16Value = (uint8_t) DAC12_enVREF_VREFP;
    pstRegisterData.u16Mask = DAC12_CH_CTL_SREF_MASK;
    pstRegisterData.u8Shift = DAC12_CH_CTL_R_SREF_BIT;
    (void) DAC12_CH__u16ReadRegister(enChannelArg, &pstRegisterData);
    return ((DAC12_nVREF) pstRegisterData.u16Value);
}

