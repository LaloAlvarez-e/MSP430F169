/**
 *
 * @file DAC12_InterruptSource_Clear.c
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
#include "DriverLib/DAC12/Driver/Intrinsics/Interrupt/Header/DAC12_InterruptSource_Clear.h"

#include "DriverLib/DAC12/Driver/Intrinsics/Primitives/DAC12_Primitives.h"
#include "DriverLib/DAC12/Peripheral/DAC12_Peripheral.h"

void DAC12_CH__vClearInterruptSource(DAC12_nCH enChannelArg)
{
    DAC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_IFG_OFFSET;
    pstRegisterData.u16Value = DAC12_IFG_CH0_NOOCCUR;
    pstRegisterData.u16Mask = DAC12_IFG_CH0_MASK;
    pstRegisterData.u8Shift = (uint8_t) enChannelArg;
    DAC12__vWriteRegister(&pstRegisterData);
}
