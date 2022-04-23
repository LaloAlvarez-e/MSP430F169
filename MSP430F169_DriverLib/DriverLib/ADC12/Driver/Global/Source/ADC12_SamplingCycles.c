/**
 *
 * @file ADC12_SamplingCycles.c
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
#include <DriverLib/ADC12/Driver/Global/Header/ADC12_SamplingCycles.h>
#include "DriverLib/ADC12/Driver/Intrinsics/ADC12_Intrinsics.h"
#include "DriverLib/ADC12/Peripheral/ADC12_Peripheral.h"

void ADC12__vSetTimerSamplingCycles_LowChannels(ADC12_nSAMPLECYCLES enValueArg)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CTL0_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enValueArg;
    pstRegisterData.u16Mask = ADC12_CTL0_SHT0_MASK;
    pstRegisterData.u8Shift = ADC12_CTL0_R_SHT0_BIT;
    ADC12__vWriteRegister(&pstRegisterData);
}


ADC12_nSAMPLECYCLES ADC12__enGetTimerSamplingCycles_LowChannels(void)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CTL0_OFFSET;
    pstRegisterData.u16Value = (uint16_t) ADC12_enSAMPLECYCLES_4;
    pstRegisterData.u16Mask = ADC12_CTL0_SHT0_MASK;
    pstRegisterData.u8Shift = ADC12_CTL0_R_SHT0_BIT;
    (void) ADC12__u16ReadRegister(&pstRegisterData);
    return ((ADC12_nSAMPLECYCLES) pstRegisterData.u16Value);
}


void ADC12__vSetTimerSamplingCycles_HighChannels(ADC12_nSAMPLECYCLES enValueArg)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CTL0_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enValueArg;
    pstRegisterData.u16Mask = ADC12_CTL0_SHT1_MASK;
    pstRegisterData.u8Shift = ADC12_CTL0_R_SHT1_BIT;
    ADC12__vWriteRegister(&pstRegisterData);
}


ADC12_nSAMPLECYCLES ADC12__enGetTimerSamplingCycles_HighChannels(void)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CTL0_OFFSET;
    pstRegisterData.u16Value = (uint16_t) ADC12_enSAMPLECYCLES_4;
    pstRegisterData.u16Mask = ADC12_CTL0_SHT1_MASK;
    pstRegisterData.u8Shift = ADC12_CTL0_R_SHT1_BIT;
    (void) ADC12__u16ReadRegister(&pstRegisterData);
    return ((ADC12_nSAMPLECYCLES) pstRegisterData.u16Value);
}





