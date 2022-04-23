/**
 *
 * @file ADC12_PowerState.c
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
#include <DriverLib/ADC12/Driver/Global/Header/ADC12_PowerState.h>
#include "DriverLib/ADC12/Driver/Intrinsics/ADC12_Intrinsics.h"
#include "DriverLib/ADC12/Peripheral/ADC12_Peripheral.h"

void ADC12__vSetPowerCoreState(ADC12_nSTATE enStateArg)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CTL0_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enStateArg;
    pstRegisterData.u16Mask = ADC12_CTL0_ON_MASK;
    pstRegisterData.u8Shift = ADC12_CTL0_R_ON_BIT;
    ADC12__vWriteRegister(&pstRegisterData);
}

void ADC12__vPowerOnCore(void)
{
    ADC12__vSetPowerCoreState(ADC12_enSTATE_ON);
}

void ADC12__vPowerOffCore(void)
{
    ADC12__vSetPowerCoreState(ADC12_enSTATE_OFF);
}

ADC12_nSTATE ADC12__enGetPowerCoreState(void)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CTL0_OFFSET;
    pstRegisterData.u16Value = (uint16_t) ADC12_enSTATE_OFF;
    pstRegisterData.u16Mask = ADC12_CTL0_ON_MASK;
    pstRegisterData.u8Shift = ADC12_CTL0_R_ON_BIT;
    (void) ADC12__u16ReadRegister(&pstRegisterData);
    return ((ADC12_nSTATE) pstRegisterData.u16Value);
}







