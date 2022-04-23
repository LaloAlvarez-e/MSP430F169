/**
 *
 * @file ADC12_VoltageReference.c
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
#include <DriverLib/ADC12/Driver/Global/Header/ADC12_VoltageReference.h>
#include "DriverLib/ADC12/Driver/Intrinsics/ADC12_Intrinsics.h"
#include "DriverLib/ADC12/Peripheral/ADC12_Peripheral.h"

void ADC12__vSetVREFState(ADC12_nSTATE enStateArg)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CTL0_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enStateArg;
    pstRegisterData.u16Mask = ADC12_CTL0_REFON_MASK;
    pstRegisterData.u8Shift = ADC12_CTL0_R_REFON_BIT;
    ADC12__vWriteRegister(&pstRegisterData);
}

void ADC12__vPowerOnVREF(void)
{
    ADC12__vSetVREFState(ADC12_enSTATE_ON);
}

void ADC12__vPowerOffVREF(void)
{
    ADC12__vSetVREFState(ADC12_enSTATE_OFF);
}

ADC12_nSTATE ADC12__enGetVREFState(void)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CTL0_OFFSET;
    pstRegisterData.u16Value = (uint16_t) ADC12_enSTATE_OFF;
    pstRegisterData.u16Mask = ADC12_CTL0_REFON_MASK;
    pstRegisterData.u8Shift = ADC12_CTL0_R_REFON_BIT;
    (void) ADC12__u16ReadRegister(&pstRegisterData);
    return ((ADC12_nSTATE) pstRegisterData.u16Value);
}


void ADC12__vSetVREFValue(ADC12_nVREF enValueArg)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CTL0_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enValueArg;
    pstRegisterData.u16Mask = ADC12_CTL0_REF2_5V_MASK;
    pstRegisterData.u8Shift = ADC12_CTL0_R_REF2_5V_BIT;
    ADC12__vWriteRegister(&pstRegisterData);
}


ADC12_nVREF ADC12__enGetVREFValue(void)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CTL0_OFFSET;
    pstRegisterData.u16Value = (uint16_t) ADC12_enVREF_1_5V;
    pstRegisterData.u16Mask = ADC12_CTL0_REF2_5V_MASK;
    pstRegisterData.u8Shift = ADC12_CTL0_R_REF2_5V_BIT;
    (void) ADC12__u16ReadRegister(&pstRegisterData);
    return ((ADC12_nVREF) pstRegisterData.u16Value);
}



