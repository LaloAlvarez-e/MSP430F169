/**
 *
 * @file ADC12_WriteRegister.c
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
#include "DriverLib/ADC12/Driver/Intrinsics/Primitives/Header/ADC12_WriteRegister.h"

#include "DriverLib/ADC12/Peripheral/ADC12_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

void ADC12__vWriteRegister(ADC12_Register16Bits_t* pstRegisterData)
{
    pstRegisterData->uptrAddress += ADC12_BASE;
    MCU__vWriteRegister_16bits(pstRegisterData);
}

void ADC12_CH__vWriteRegister_16bits(ADC12_nCH enChannelArg,
                            ADC12_Register16Bits_t* pstRegisterData)
{
    uintptr_t ptrPortBase;
    ptrPortBase = ADC12_CH__uptrBlockBaseAddress(enChannelArg);
    pstRegisterData->uptrAddress += ptrPortBase;
    MCU__vWriteRegister_16bits(pstRegisterData);
}


void ADC12_CH__vWriteRegister_8bits(ADC12_nCH enChannelArg,
                            ADC12_Register8Bits_t* pstRegisterData)
{
    uintptr_t ptrPortBase;
    ptrPortBase = ADC12_CH__uptrBlockBaseAddress(enChannelArg);
    pstRegisterData->uptrAddress += ptrPortBase;
    MCU__vWriteRegister_8bits(pstRegisterData);
}

