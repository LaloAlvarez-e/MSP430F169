/**
 *
 * @file DAC12_Trigger.c
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
#include <DriverLib/DAC12/Driver/Channel/Config/Header/DAC12_Trigger.h>
#include "DriverLib/DAC12/Driver/Intrinsics/DAC12_Intrinsics.h"
#include "DriverLib/DAC12/Peripheral/DAC12_Peripheral.h"

void DAC12_CH__vSetTrigger(DAC12_nCH enChannelArg,
                              DAC12_nTRIGGER enTriggerArg)
{
    DAC12_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CH_CTL_OFFSET;
    pstRegisterData.u16Value = (uint8_t) enTriggerArg;
    pstRegisterData.u16Mask = DAC12_CH_CTL_LSEL_MASK;
    pstRegisterData.u8Shift = DAC12_CH_CTL_R_LSEL_BIT;
    DAC12_CH__vWriteRegister(enChannelArg,
                         &pstRegisterData);

}

DAC12_nTRIGGER DAC12_CH__enGetTrigger(DAC12_nCH enChannelArg)
{
    DAC12_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CH_CTL_OFFSET;
    pstRegisterData.u16Value = (uint8_t) DAC12_enTRIGGER_IMMEDIATE;
    pstRegisterData.u16Mask = DAC12_CH_CTL_LSEL_MASK;
    pstRegisterData.u8Shift = DAC12_CH_CTL_R_LSEL_BIT;
    (void) DAC12_CH__u16ReadRegister(enChannelArg, &pstRegisterData);
    return ((DAC12_nTRIGGER) pstRegisterData.u16Value);
}




