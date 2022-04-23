/**
 *
 * @file ADC12_ConversionValue.c
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
#include <DriverLib/ADC12/Driver/Channel/Header/ADC12_ConversionValue.h>
#include "DriverLib/ADC12/Driver/Intrinsics/ADC12_Intrinsics.h"
#include "DriverLib/ADC12/Peripheral/ADC12_Peripheral.h"

uint16_t ADC12__u16GetConversionValue(ADC12_nCH enChannelArg)
{
    ADC12_Register16Bits_t pstRegisterData;
    uint16_t u16AuxiliarOffset = ADC12_CH_MEM_OFFSET;
    u16AuxiliarOffset += (uint16_t) enChannelArg;
    pstRegisterData.uptrAddress = u16AuxiliarOffset;
    pstRegisterData.u16Value = 0U;
    pstRegisterData.u16Mask = ADC12_CH_MEM_MEM_MASK;
    pstRegisterData.u8Shift = ADC12_CH_MEM_R_MEM_BIT;
    (void) ADC12_CH__u16ReadRegister(enChannelArg, &pstRegisterData);
    return (pstRegisterData.u16Value);
}




