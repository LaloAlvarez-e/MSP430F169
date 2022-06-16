/**
 *
 * @file DMA_ReadRegister.c
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
#include "DriverLib/DMA/Driver/Intrinsics/Primitives/Header/DMA_ReadRegister.h"

#include "DriverLib/DMA/Peripheral/DMA_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

uint16_t DMA__u16ReadRegister(DMA_Register_t* pstRegisterData)
{
    uint16_t u16RegisterValue;

    pstRegisterData->uptrAddress += DMA_BASE;
    u16RegisterValue = MCU__u16ReadRegister(pstRegisterData);

    return (u16RegisterValue);
}

uint16_t DMA_CH__u16ReadRegister(DMA_nCH enChannelArg,
                                 DMA_Register_t* pstRegisterData)
{
    uintptr_t ptrChannelBase;
    uint16_t u16RegisterValue;

    ptrChannelBase = DMA_CH__uptrBlockBaseAddress(enChannelArg);
    pstRegisterData->uptrAddress += ptrChannelBase;
    u16RegisterValue = MCU__u16ReadRegister(pstRegisterData);

    return (u16RegisterValue);
}



