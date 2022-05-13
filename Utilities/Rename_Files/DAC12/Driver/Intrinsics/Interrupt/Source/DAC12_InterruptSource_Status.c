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
    DAC12_Register16Bits_t pstRegisterData;

    pstRegisterData.uptrAddress = DAC12_IFG_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enStatus;
    pstRegisterData.u16Mask = DAC12_IFG_CH0_MASK;
    pstRegisterData.u8Shift = (uint8_t) enChannelArg;
    DAC12__vWriteRegister(&pstRegisterData);
}

DAC12_nINT_STATUS DAC12_CH__enGetStatusInterruptSource(DAC12_nCH enChannelArg)
{
    DAC12_Register16Bits_t pstRegisterData;
    DAC12_nINT_STATUS enStatus = DAC12_enINT_STATUS_NOOCCUR;

    pstRegisterData.uptrAddress = DAC12_IFG_OFFSET;
    pstRegisterData.u16Mask = DAC12_IFG_CH0_MASK;
    pstRegisterData.u8Shift = (uint8_t) enChannelArg;

    enStatus = (DAC12_nINT_STATUS) DAC12__u16ReadRegister(&pstRegisterData);
    return (enStatus);
}
