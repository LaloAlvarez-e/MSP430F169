/**
 *
 * @file ADC12_Trigger.c
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
#include <DriverLib/ADC12/Driver/Channel/Header/ADC12_Trigger.h>
#include "DriverLib/ADC12/Driver/Intrinsics/ADC12_Intrinsics.h"
#include "DriverLib/ADC12/Peripheral/ADC12_Peripheral.h"

void ADC12__vSetTrigger(ADC12_nCH enChannelArg,
                      ADC12_nCH_TRIGGER enTriggerArg)
{
    uint16_t u16ShiftTemp = ADC12_CTL0_R_CH1TSEL_BIT;
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CTL0_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enTriggerArg;
    pstRegisterData.u16Mask = ADC12_CTL0_CHTSEL_MASK;
    u16ShiftTemp *= (uint16_t) enChannelArg;
    pstRegisterData.u8Shift = u16ShiftTemp;
    ADC12__vWriteRegister(&pstRegisterData);
}

ADC12_nCH_TRIGGER ADC12__enGetTrigger(ADC12_nCH enChannelArg)
{
    uint16_t u16ShiftTemp = ADC12_CTL0_R_CH1TSEL_BIT;
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CTL0_OFFSET;
    pstRegisterData.u16Value = 0U;
    pstRegisterData.u16Mask = ADC12_CTL0_CHTSEL_MASK;
    u16ShiftTemp *= (uint16_t) enChannelArg;
    pstRegisterData.u8Shift = u16ShiftTemp;
    (void) ADC12__u16ReadRegister(&pstRegisterData);
    return ((ADC12_nCH_TRIGGER) pstRegisterData.u16Value);
}




