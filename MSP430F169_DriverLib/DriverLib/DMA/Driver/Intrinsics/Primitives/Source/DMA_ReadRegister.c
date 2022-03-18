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

uint8_t DMA__u8ReadRegister(DMA_nPORT enPortArg,
                             DMA_Register_t* pstRegisterData)
{
    uintptr_t ptrPortBase = 0U;
    uint8_t u8RegisterValue = 0U;

    ptrPortBase = DMA__uptrBlockBaseAddress(enPortArg);
    pstRegisterData->uptrAddress += ptrPortBase;
    u8RegisterValue = MCU__u8ReadRegister(pstRegisterData);

    return (u8RegisterValue);
}


