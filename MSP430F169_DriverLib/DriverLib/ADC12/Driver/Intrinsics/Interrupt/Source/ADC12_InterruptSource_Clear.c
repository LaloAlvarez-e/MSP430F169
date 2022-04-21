/**
 *
 * @file ADC12_InterruptSource_Clear.c
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
#include "DriverLib/ADC12/Driver/Intrinsics/Interrupt/Header/ADC12_InterruptSource_Clear.h"

#include "DriverLib/ADC12/Driver/Intrinsics/Primitives/ADC12_Primitives.h"
#include "DriverLib/ADC12/Peripheral/ADC12_Peripheral.h"

void ADC12_CH__vClearInterruptSource(ADC12_nCH enChannelArg)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_IFG_OFFSET;
    pstRegisterData.u16Value = ADC12_IFG_CH0_NOOCCUR;
    pstRegisterData.u16Mask = ADC12_IFG_CH0_MASK;
    pstRegisterData.u8Shift = (uint8_t) enChannelArg;
    ADC12__vWriteRegister(&pstRegisterData);
}
