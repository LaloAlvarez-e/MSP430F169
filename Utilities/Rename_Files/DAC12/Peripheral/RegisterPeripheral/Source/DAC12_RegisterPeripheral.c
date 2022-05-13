/**
 *
 * @file DAC12_RegisterPeripheral.c
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
#include "DriverLib/DAC12/Peripheral/RegisterPeripheral/DAC12_RegisterPeripheral.h"
#include "DriverLib/DAC12/Peripheral/Header/DAC12_Enum.h"

uintptr_t DAC12_CH__uptrBlockBaseAddress(DAC12_nCH enChannelArg)
{
    const uintptr_t DAC12_BLOCK_BASE[(uint8_t) DAC12_enCH_MAX] =
    {
         DAC12_CH0_BASE, DAC12_CH1_BASE, DAC12_CH2_BASE, DAC12_CH3_BASE,
         DAC12_CH4_BASE, DAC12_CH5_BASE, DAC12_CH6_BASE, DAC12_CH7_BASE,
         DAC12_CH8_BASE, DAC12_CH9_BASE, DAC12_CH10_BASE, DAC12_CH11_BASE,
         DAC12_CH12_BASE, DAC12_CH13_BASE, DAC12_CH14_BASE, DAC12_CH15_BASE,
    };
    uintptr_t uptrReg = 0UL;
    uptrReg = DAC12_BLOCK_BASE[(uint8_t) enChannelArg];
    return(uptrReg);
}

uintptr_t DAC12__uptrBlockBaseAddress(void)
{
    uintptr_t uptrReg = 0U;
    uptrReg = DAC12_BASE;
    return(uptrReg);
}




