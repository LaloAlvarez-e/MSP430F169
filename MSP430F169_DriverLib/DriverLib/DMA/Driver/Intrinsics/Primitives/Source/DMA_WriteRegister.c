/**
 *
 * @file DMA_WriteRegister.c
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
#include "DriverLib/DMA/Driver/Intrinsics/Primitives/Header/DMA_WriteRegister.h"

#include "DriverLib/DMA/Peripheral/DMA_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

void DMA__vWriteRegister(DMA_nPORT enPortArg,
                          DMA_Register_t* pstRegisterData)
{
    uintptr_t ptrPortBase = 0U;
    ptrPortBase = DMA__uptrBlockBaseAddress(enPortArg);
    pstRegisterData->uptrAddress += ptrPortBase;
    MCU__vWriteRegister_8bits(pstRegisterData);
}
