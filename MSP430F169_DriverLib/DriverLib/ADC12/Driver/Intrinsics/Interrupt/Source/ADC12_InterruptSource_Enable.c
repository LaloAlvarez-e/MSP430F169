/**
 *
 * @file ADC12_InterruptSource_Enable.c
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
#include "DriverLib/ADC12/Driver/Intrinsics/Interrupt/Header/ADC12_InterruptSource_Enable.h"

#include "DriverLib/ADC12/Driver/Intrinsics/Primitives/ADC12_Primitives.h"
#include "DriverLib/ADC12/Peripheral/ADC12_Peripheral.h"

void ADC12_CH__vSetEnableInterruptSource(ADC12_nCH enChannelArg,
                                    ADC12_nINT_ENABLE enState)
{
    ADC12_Register16Bits_t pstRegisterData;

    pstRegisterData.uptrAddress = ADC12_IE_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enState;
    pstRegisterData.u16Mask = (uint16_t) ADC12_IE_CH0_MASK;
    pstRegisterData.u8Shift = (uint8_t) enChannelArg;

    ADC12__vWriteRegister(&pstRegisterData);
}

void ADC12_CH__vEnaInterruptSource(ADC12_nCH enChannelArg)
{
    ADC12_CH__vSetEnableInterruptSource(enChannelArg, ADC12_enINT_ENABLE_ENA);
}

void ADC12_CH__vDisInterruptSource(ADC12_nCH enChannelArg)
{
    ADC12_CH__vSetEnableInterruptSource(enChannelArg, ADC12_enINT_ENABLE_DIS);
}

ADC12_nINT_ENABLE ADC12_CH__enGetEnableInterruptSource(ADC12_nCH enChannelArg)
{
    ADC12_Register16Bits_t pstRegisterData;
    ADC12_nINT_ENABLE enEnable;

    pstRegisterData.uptrAddress = ADC12_IE_OFFSET;
    pstRegisterData.u16Mask = ADC12_IE_CH0_MASK;
    pstRegisterData.u8Shift = (uint8_t) enChannelArg;
    enEnable = (ADC12_nINT_ENABLE) ADC12__u16ReadRegister(&pstRegisterData);
    return (enEnable);
}


void ADC12__vSetEnableInterruptSource(ADC12_nINTERRUPT enInterruptArg,
                                    ADC12_nINT_ENABLE enState)
{
    ADC12_Register16Bits_t pstRegisterData;
    uint8_t u8ShiftValue;

    pstRegisterData.uptrAddress = ADC12_CTL0_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enState;
    if(ADC12_enINTERRUPT_TOV == enInterruptArg)
    {
        u8ShiftValue = ADC12_CTL0_R_TOVIE_BIT;
    }
    else
    {
        u8ShiftValue = ADC12_CTL0_R_OVIE_BIT;
    }
    pstRegisterData.u16Mask = (uint16_t) ADC12_CTL0_OVIE_MASK;
    pstRegisterData.u8Shift = (uint8_t) u8ShiftValue;

    ADC12__vWriteRegister(&pstRegisterData);
}

void ADC12__vEnaInterruptSource(ADC12_nINTERRUPT enInterruptArg)
{
    ADC12__vSetEnableInterruptSource(enInterruptArg, ADC12_enINT_ENABLE_ENA);
}

void ADC12__vDisInterruptSource(ADC12_nINTERRUPT enInterruptArg)
{
    ADC12__vSetEnableInterruptSource(enInterruptArg, ADC12_enINT_ENABLE_DIS);
}

ADC12_nINT_ENABLE ADC12__enGetEnableInterruptSource(ADC12_nINTERRUPT enInterruptArg)
{
    ADC12_Register16Bits_t pstRegisterData;
    ADC12_nINT_ENABLE enEnable;
    uint8_t u8ShiftValue;

    pstRegisterData.uptrAddress = ADC12_CTL0_OFFSET;
    pstRegisterData.u16Mask = ADC12_CTL0_OVIE_MASK;
    if(ADC12_enINTERRUPT_TOV == enInterruptArg)
    {
        u8ShiftValue = ADC12_CTL0_R_TOVIE_BIT;
    }
    else
    {
        u8ShiftValue = ADC12_CTL0_R_OVIE_BIT;
    }
    pstRegisterData.u8Shift = u8ShiftValue;
    enEnable = (ADC12_nINT_ENABLE) ADC12__u16ReadRegister(&pstRegisterData);
    return (enEnable);
}
