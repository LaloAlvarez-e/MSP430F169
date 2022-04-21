/**
 *
 * @file ADC12_ReadRegister.c
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
#include "DriverLib/ADC12/Driver/Intrinsics/Primitives/Header/ADC12_ReadRegister.h"

#include "DriverLib/ADC12/Peripheral/ADC12_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

uint16_t ADC12__u16ReadRegister(ADC12_Register16Bits_t* pstRegisterData)
{
    const uintptr_t ptrBase = ADC12_BASE;
    uint16_t u16RegisterValue = 0U;

    pstRegisterData->uptrAddress += ptrBase;
    u16RegisterValue = MCU__u16ReadRegister(pstRegisterData);

    return (u16RegisterValue);
}

uint16_t ADC12_CH__u16ReadRegister(ADC12_nCH enChannelArg,
                                 ADC12_Register16Bits_t* pstRegisterData)
{
    uintptr_t ptrChannelBase = 0U;
    uint16_t u16RegisterValue = 0U;

    ptrChannelBase = ADC12_CH__uptrBlockBaseAddress(enChannelArg);
    pstRegisterData->uptrAddress += ptrChannelBase;
    u16RegisterValue = MCU__u16ReadRegister(pstRegisterData);

    return (u16RegisterValue);
}

uint8_t ADC12_CH__u8ReadRegister(ADC12_nCH enChannelArg,
                                 ADC12_Register8Bits_t* pstRegisterData)
{
    uintptr_t ptrChannelBase = 0U;
    uint8_t u8RegisterValue = 0U;

    ptrChannelBase = ADC12_CH__uptrBlockBaseAddress(enChannelArg);
    pstRegisterData->uptrAddress += ptrChannelBase;
    u8RegisterValue = MCU__u8ReadRegister(pstRegisterData);

    return (u8RegisterValue);
}


