/**
 *
 * @file DAC12_Mode.c
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
#include <DriverLib/DAC12/Driver/Channel/Config/Header/DAC12_Mode.h>
#include "DriverLib/DAC12/Driver/Intrinsics/DAC12_Intrinsics.h"
#include "DriverLib/DAC12/Peripheral/DAC12_Peripheral.h"

void DAC12_CH__vSetMode(DAC12_nCH enChannelArg,
                        DAC12_nMODE enModeArg)
{
    DAC12_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CH_CTL_OFFSET;
    pstRegisterData.u16Value = (uint8_t) enModeArg;
    pstRegisterData.u16Mask = DAC12_CH_CTL_AMP_MASK;
    pstRegisterData.u8Shift = DAC12_CH_CTL_R_AMP_BIT;
    DAC12_CH__vWriteRegister(enChannelArg,
                         &pstRegisterData);

}

DAC12_nMODE DAC12_CH__enGetMode(DAC12_nCH enChannelArg)
{
    DAC12_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CH_CTL_OFFSET;
    pstRegisterData.u16Value = (uint8_t) DAC12_enMODE_OFF_OFF;
    pstRegisterData.u16Mask = DAC12_CH_CTL_AMP_MASK;
    pstRegisterData.u8Shift = DAC12_CH_CTL_R_AMP_BIT;
    (void) DAC12_CH__u16ReadRegister(enChannelArg, &pstRegisterData);
    return ((DAC12_nMODE) pstRegisterData.u16Value);
}




