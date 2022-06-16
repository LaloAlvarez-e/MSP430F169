/**
 *
 * @file DAC12_InterruptSource_Status.c
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
#include "DriverLib/DAC12/Driver/Intrinsics/Interrupt/Header/DAC12_InterruptSource_Status.h"

#include "DriverLib/DAC12/Driver/Intrinsics/Primitives/DAC12_Primitives.h"
#include "DriverLib/DAC12/Peripheral/DAC12_Peripheral.h"

void DAC12_CH__vSetStatusInterruptSource(DAC12_nCH enChannelArg,
                                    DAC12_nINT_STATUS enStatus)
{
    DAC12_Register_t pstRegisterData;

    pstRegisterData.uptrAddress = DAC12_CH_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enStatus;
    pstRegisterData.u16Mask = DAC12_CH_CTL_IFG_MASK;
    pstRegisterData.u8Shift = (uint8_t) DAC12_CH_CTL_R_IFG_BIT;
    DAC12_CH__vWriteRegister(enChannelArg, &pstRegisterData);
}

DAC12_nINT_STATUS DAC12_CH__enGetStatusInterruptSource(DAC12_nCH enChannelArg)
{
    DAC12_Register_t pstRegisterData;
    DAC12_nINT_STATUS enStatus;

    pstRegisterData.uptrAddress = DAC12_CH_CTL_OFFSET;
    pstRegisterData.u16Mask = DAC12_CH_CTL_IFG_MASK;
    pstRegisterData.u8Shift = (uint8_t) DAC12_CH_CTL_R_IFG_BIT;

    enStatus = (DAC12_nINT_STATUS) DAC12_CH__u16ReadRegister(enChannelArg,
                                                             &pstRegisterData);
    return (enStatus);
}
