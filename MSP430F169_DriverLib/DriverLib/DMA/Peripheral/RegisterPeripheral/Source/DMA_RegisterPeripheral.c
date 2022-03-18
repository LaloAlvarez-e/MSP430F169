/**
 *
 * @file DMA_RegisterPeripheral.c
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
 * @verbatim 6 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 6 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/DMA/Peripheral/RegisterPeripheral/DMA_RegisterPeripheral.h"
#include "DriverLib/DMA/Peripheral/Header/DMA_Enum.h"

uintptr_t DMA_CH__uptrBlockBaseAddress(DMA_nCH enChannelArg)
{
    const uintptr_t DMA_BLOCK_BASE[(uint8_t) DMA_enCH_MAX] =
    {
         DMA_CH0_BASE, DMA_CH1_BASE, DMA_CH2_BASE
    };
    uintptr_t uptrReg = 0UL;
    uptrReg = DMA_BLOCK_BASE[(uint8_t) enChannelArg];
    return(uptrReg);
}

uintptr_t DMA__uptrBlockBaseAddress(void)
{
    uintptr_t uptrReg = 0U;
    uptrReg = DMA_BASE;
    return(uptrReg);
}




