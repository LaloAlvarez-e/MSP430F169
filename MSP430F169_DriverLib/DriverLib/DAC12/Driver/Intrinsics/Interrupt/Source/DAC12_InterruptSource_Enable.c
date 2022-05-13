/**
 *
 * @file DAC12_InterruptSource_Enable.c
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
 * @verbatim 7 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 7 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/DAC12/Driver/Intrinsics/Interrupt/Header/DAC12_InterruptSource_Enable.h"

#include "DriverLib/DAC12/Driver/Intrinsics/Primitives/DAC12_Primitives.h"
#include "DriverLib/DAC12/Peripheral/DAC12_Peripheral.h"

void DAC12_CH__vSetEnableInterruptSource(DAC12_nCH enChannelArg,
                                    DAC12_nINT_ENABLE enState)
{
    DAC12_Register_t pstRegisterData;

    pstRegisterData.uptrAddress = DAC12_CH_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enState;
    pstRegisterData.u16Mask = DAC12_CH_CTL_IE_MASK;
    pstRegisterData.u8Shift = (uint8_t) DAC12_CH_CTL_R_IE_BIT;

    DAC12_CH__vWriteRegister(enChannelArg, &pstRegisterData);
}

void DAC12_CH__vEnaInterruptSource(DAC12_nCH enChannelArg)
{
    DAC12_CH__vSetEnableInterruptSource(enChannelArg, DAC12_enINT_ENABLE_ENA);
}

void DAC12_CH__vDisInterruptSource(DAC12_nCH enChannelArg)
{
    DAC12_CH__vSetEnableInterruptSource(enChannelArg, DAC12_enINT_ENABLE_DIS);
}

DAC12_nINT_ENABLE DAC12_CH__enGetEnableInterruptSource(DAC12_nCH enChannelArg)
{
    DAC12_Register_t pstRegisterData;
    DAC12_nINT_ENABLE enEnable = DAC12_enINT_ENABLE_DIS;

    pstRegisterData.uptrAddress = DAC12_CH_CTL_OFFSET;
    pstRegisterData.u16Mask = DAC12_CH_CTL_IE_MASK;
    pstRegisterData.u8Shift = (uint8_t) DAC12_CH_CTL_R_IE_BIT;
    enEnable = (DAC12_nINT_ENABLE) DAC12_CH__u16ReadRegister(enChannelArg,
                                                             &pstRegisterData);
    return (enEnable);
}
