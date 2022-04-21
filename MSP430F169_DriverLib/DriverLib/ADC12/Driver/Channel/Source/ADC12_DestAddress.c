/**
 *
 * @file ADC12_DestAddress.c
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
 * @verbatim 25 mar. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 25 mar. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <DriverLib/ADC12/Driver/Channel/Header/ADC12_DestAddress.h>
#include "DriverLib/ADC12/Driver/Intrinsics/ADC12_Intrinsics.h"
#include "DriverLib/ADC12/Peripheral/ADC12_Peripheral.h"

void ADC12__vSetDestAddress(ADC12_nCH enChannelArg,
                         uint16_t u16AddressArg)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CH_DA_OFFSET;
    pstRegisterData.u16Value = (uint16_t) u16AddressArg;
    pstRegisterData.u16Mask = ADC12_CH_DA_DA_MASK;
    pstRegisterData.u8Shift = ADC12_CH_DA_R_DA_BIT;
    ADC12_CH__vWriteRegister_16bits(enChannelArg,
                         &pstRegisterData);
}

uint16_t ADC12__u16GetDestAddress(ADC12_nCH enChannelArg)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CH_DA_OFFSET;
    pstRegisterData.u16Value = 0U;
    pstRegisterData.u16Mask = ADC12_CH_DA_DA_MASK;
    pstRegisterData.u8Shift = ADC12_CH_DA_R_DA_BIT;
    (void) ADC12_CH__u16ReadRegister(enChannelArg, &pstRegisterData);
    return (pstRegisterData.u16Value);
}



