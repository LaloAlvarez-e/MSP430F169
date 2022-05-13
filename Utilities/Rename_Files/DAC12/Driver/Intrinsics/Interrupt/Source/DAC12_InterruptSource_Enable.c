/**
 *
 * @file DAC12_InterruptSource_Enable.c
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
#include "DriverLib/DAC12/Driver/Intrinsics/Interrupt/Header/DAC12_InterruptSource_Enable.h"

#include "DriverLib/DAC12/Driver/Intrinsics/Primitives/DAC12_Primitives.h"
#include "DriverLib/DAC12/Peripheral/DAC12_Peripheral.h"

void DAC12_CH__vSetEnableInterruptSource(DAC12_nCH enChannelArg,
                                    DAC12_nINT_ENABLE enState)
{
    DAC12_Register16Bits_t pstRegisterData;

    pstRegisterData.uptrAddress = DAC12_IE_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enState;
    pstRegisterData.u16Mask = (uint16_t) DAC12_IE_CH0_MASK;
    pstRegisterData.u8Shift = (uint8_t) enChannelArg;

    DAC12__vWriteRegister(&pstRegisterData);
}

void DAC12_CH__vEnaInterruptSource(DAC12_nCH enChannelArg)
{
    DAC12_CH__vSetEnableInterruptSource(enChannelArg, DAC12_enINT_ENABLE_ENA);
}

void DAC12_CH__vDisInterruptSource(DAC12_nCH enChannelArg)
{
    DAC12_CH__vSetEnableInterruptSource(enChannelArg, DAC12_enINT_ENABLE_DIS);
}

DAC12_nINT_ENABLE DAC12_CH__enGetEnableInterruptSource(DAC12_nCH enChannelArg)
{
    DAC12_Register16Bits_t pstRegisterData;
    DAC12_nINT_ENABLE enEnable = DAC12_enINT_ENABLE_DIS;

    pstRegisterData.uptrAddress = DAC12_IE_OFFSET;
    pstRegisterData.u16Mask = DAC12_IE_CH0_MASK;
    pstRegisterData.u8Shift = (uint8_t) enChannelArg;
    enEnable = (DAC12_nINT_ENABLE) DAC12__u16ReadRegister(&pstRegisterData);
    return (enEnable);
}


void DAC12__vSetEnableInterruptSource(DAC12_nINTERRUPT enInterruptArg,
                                    DAC12_nINT_ENABLE enState)
{
    DAC12_Register16Bits_t pstRegisterData;
    uint8_t u8ShiftValue = 0U;

    pstRegisterData.uptrAddress = DAC12_CTL0_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enState;
    if(DAC12_enINTERRUPT_TOV == enInterruptArg)
    {
        u8ShiftValue = DAC12_CTL0_R_TOVIE_BIT;
    }
    else
    {
        u8ShiftValue = DAC12_CTL0_R_OVIE_BIT;
    }
    pstRegisterData.u16Mask = (uint16_t) DAC12_CTL0_OVIE_MASK;
    pstRegisterData.u8Shift = (uint8_t) u8ShiftValue;

    DAC12__vWriteRegister(&pstRegisterData);
}

void DAC12__vEnaInterruptSource(DAC12_nINTERRUPT enInterruptArg)
{
    DAC12__vSetEnableInterruptSource(enInterruptArg, DAC12_enINT_ENABLE_ENA);
}

void DAC12__vDisInterruptSource(DAC12_nINTERRUPT enInterruptArg)
{
    DAC12__vSetEnableInterruptSource(enInterruptArg, DAC12_enINT_ENABLE_DIS);
}

DAC12_nINT_ENABLE DAC12__enGetEnableInterruptSource(DAC12_nINTERRUPT enInterruptArg)
{
    DAC12_Register16Bits_t pstRegisterData;
    DAC12_nINT_ENABLE enEnable = DAC12_enINT_ENABLE_DIS;
    uint8_t u8ShiftValue = 0U;

    pstRegisterData.uptrAddress = DAC12_CTL0_OFFSET;
    pstRegisterData.u16Mask = DAC12_CTL0_OVIE_MASK;
    if(DAC12_enINTERRUPT_TOV == enInterruptArg)
    {
        u8ShiftValue = DAC12_CTL0_R_TOVIE_BIT;
    }
    else
    {
        u8ShiftValue = DAC12_CTL0_R_OVIE_BIT;
    }
    pstRegisterData.u8Shift = u8ShiftValue;
    enEnable = (DAC12_nINT_ENABLE) DAC12__u16ReadRegister(&pstRegisterData);
    return (enEnable);
}
