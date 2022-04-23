/**
 *
 * @file ADC12_ConversionTrigger.c
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
#include <DriverLib/ADC12/Driver/Global/Header/ADC12_ConversionTrigger.h>
#include "DriverLib/ADC12/Driver/Intrinsics/ADC12_Intrinsics.h"
#include "DriverLib/ADC12/Peripheral/ADC12_Peripheral.h"

void ADC12__vSetConversionTrigger(ADC12_nTRIGGER enTriggerArg)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CTL1_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enTriggerArg;
    pstRegisterData.u16Mask = ADC12_CTL1_SHS_MASK;
    pstRegisterData.u8Shift = ADC12_CTL1_R_SHS_BIT;
    ADC12__vWriteRegister(&pstRegisterData);
}

ADC12_nTRIGGER ADC12__enGetConversionTrigger(void)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CTL1_OFFSET;
    pstRegisterData.u16Value = (uint16_t) ADC12_enTRIGGER_SW;
    pstRegisterData.u16Mask = ADC12_CTL1_SHS_MASK;
    pstRegisterData.u8Shift = ADC12_CTL1_R_SHS_BIT;
    (void) ADC12__u16ReadRegister(&pstRegisterData);
    return ((ADC12_nTRIGGER) pstRegisterData.u16Value);
}


void ADC12__vSetConversionTriggerEdge(ADC12_nEDGE enEdgeArg)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CTL1_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enEdgeArg;
    pstRegisterData.u16Mask = ADC12_CTL1_ISSH_MASK;
    pstRegisterData.u8Shift = ADC12_CTL1_R_ISSH_BIT;
    ADC12__vWriteRegister(&pstRegisterData);
}

ADC12_nEDGE ADC12__enGetConversionTriggerEdge(void)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CTL1_OFFSET;
    pstRegisterData.u16Value = (uint16_t) ADC12_enEDGE_RISING;
    pstRegisterData.u16Mask = ADC12_CTL1_ISSH_MASK;
    pstRegisterData.u8Shift = ADC12_CTL1_R_ISSH_BIT;
    (void) ADC12__u16ReadRegister(&pstRegisterData);
    return ((ADC12_nEDGE) pstRegisterData.u16Value);
}




