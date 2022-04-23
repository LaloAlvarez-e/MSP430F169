/**
 *
 * @file ADC12_EnableConversion.c
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
 * @verbatim 21 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 21 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <DriverLib/ADC12/Driver/Global/Header/ADC12_EnableConversion.h>
#include "DriverLib/ADC12/Driver/Intrinsics/ADC12_Intrinsics.h"
#include "DriverLib/ADC12/Peripheral/ADC12_Peripheral.h"

void ADC12__vSetEnableConversion(ADC12_nENABLE enEnableArg)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CTL0_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enEnableArg;
    pstRegisterData.u16Mask = ADC12_CTL0_ENC_MASK;
    pstRegisterData.u8Shift = ADC12_CTL0_R_ENC_BIT;
    ADC12__vWriteRegister(&pstRegisterData);
}

void ADC12__vEnableConversion(void)
{
    ADC12__vSetEnableConversion(ADC12_enENABLE_ENA);
}

void ADC12__vDisableConversion(void)
{
    ADC12__vSetEnableConversion(ADC12_enENABLE_DIS);
}

void ADC12__vRestartEnableConversion(void)
{
    ADC12__vDisableConversion();
    ADC12__vEnableConversion();
}

ADC12_nENABLE ADC12__enGetEnableConversion(void)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CTL0_OFFSET;
    pstRegisterData.u16Value = (uint16_t) ADC12_enENABLE_DIS;
    pstRegisterData.u16Mask = ADC12_CTL0_ENC_MASK;
    pstRegisterData.u8Shift = ADC12_CTL0_R_ENC_BIT;
    (void) ADC12__u16ReadRegister(&pstRegisterData);
    return ((ADC12_nENABLE) pstRegisterData.u16Value);
}





