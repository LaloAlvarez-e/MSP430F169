/**
 *
 * @file DAC12_WriteRegister.c
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
#include "DriverLib/DAC12/Driver/Intrinsics/Primitives/Header/DAC12_WriteRegister.h"

#include "DriverLib/DAC12/Peripheral/DAC12_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

void DAC12__vWriteRegister(DAC12_Register_t* pstRegisterData)
{
    const uintptr_t ptrBase = DAC12_BASE;
    pstRegisterData->uptrAddress += ptrBase;
    MCU__vWriteRegister_16bits(pstRegisterData);
}

void DAC12_CH__vWriteRegister(DAC12_nCH enChannelArg,
                            DAC12_Register_t* pstRegisterData)
{
    uintptr_t ptrPortBase = 0U;
    ptrPortBase = DAC12_CH__uptrBlockBaseAddress(enChannelArg);
    pstRegisterData->uptrAddress += ptrPortBase;
    MCU__vWriteRegister_16bits(pstRegisterData);
}
