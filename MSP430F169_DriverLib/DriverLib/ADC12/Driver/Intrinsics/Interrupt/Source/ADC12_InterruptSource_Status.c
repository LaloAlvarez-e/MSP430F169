/**
 *
 * @file ADC12_InterruptSource_Status.c
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
#include "DriverLib/ADC12/Driver/Intrinsics/Interrupt/Header/ADC12_InterruptSource_Status.h"

#include "DriverLib/ADC12/Driver/Intrinsics/Primitives/ADC12_Primitives.h"
#include "DriverLib/ADC12/Peripheral/ADC12_Peripheral.h"

void ADC12_CH__vSetStatusInterruptSource(ADC12_nCH enChannelArg,
                                    ADC12_nINT_STATUS enStatus)
{
    ADC12_Register16Bits_t pstRegisterData;

    pstRegisterData.uptrAddress = ADC12_IFG_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enStatus;
    pstRegisterData.u16Mask = ADC12_IFG_CH0_MASK;
    pstRegisterData.u8Shift = (uint8_t) enChannelArg;
    ADC12__vWriteRegister(&pstRegisterData);
}

ADC12_nINT_STATUS ADC12_CH__enGetStatusInterruptSource(ADC12_nCH enChannelArg)
{
    ADC12_Register16Bits_t pstRegisterData;
    ADC12_nINT_STATUS enStatus = ADC12_enINT_STATUS_NOOCCUR;

    pstRegisterData.uptrAddress = ADC12_IFG_OFFSET;
    pstRegisterData.u16Mask = ADC12_IFG_CH0_MASK;
    pstRegisterData.u8Shift = (uint8_t) enChannelArg;

    enStatus = (ADC12_nINT_STATUS) ADC12__u16ReadRegister(&pstRegisterData);
    return (enStatus);
}
