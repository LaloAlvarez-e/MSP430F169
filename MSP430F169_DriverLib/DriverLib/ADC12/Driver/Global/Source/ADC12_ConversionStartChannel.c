/**
 *
 * @file ADC12_ConversionStartChannel.c
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
 * @verbatim 22 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 22 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <DriverLib/ADC12/Driver/Global/Header/ADC12_ConversionStartChannel.h>
#include "DriverLib/ADC12/Driver/Intrinsics/ADC12_Intrinsics.h"
#include "DriverLib/ADC12/Peripheral/ADC12_Peripheral.h"

void ADC12__vSetConversionStartChannel(ADC12_nCH enStartChannelArg)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CTL1_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enStartChannelArg;
    pstRegisterData.u16Mask = ADC12_CTL1_CSTARTADD_MASK;
    pstRegisterData.u8Shift = ADC12_CTL1_R_CSTARTADD_BIT;
    ADC12__vWriteRegister(&pstRegisterData);
}

ADC12_nCH ADC12__enGetConversionStartChannel(void)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CTL1_OFFSET;
    pstRegisterData.u16Value = (uint16_t) ADC12_enCH0;
    pstRegisterData.u16Mask = ADC12_CTL1_CSTARTADD_MASK;
    pstRegisterData.u8Shift = ADC12_CTL1_R_CSTARTADD_BIT;
    (void) ADC12__u16ReadRegister(&pstRegisterData);
    return ((ADC12_nCH) pstRegisterData.u16Value);
}





