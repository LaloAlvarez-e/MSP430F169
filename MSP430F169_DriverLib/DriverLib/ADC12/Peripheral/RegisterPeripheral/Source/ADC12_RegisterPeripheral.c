/**
 *
 * @file ADC12_RegisterPeripheral.c
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
#include "DriverLib/ADC12/Peripheral/RegisterPeripheral/ADC12_RegisterPeripheral.h"
#include "DriverLib/ADC12/Peripheral/Header/ADC12_Enum.h"

uintptr_t ADC12_CH__uptrBlockBaseAddress(ADC12_nCH enChannelArg)
{
    const uintptr_t ADC12_BLOCK_BASE[(uint8_t) ADC12_enCH_MAX] =
    {
         ADC12_CH0_BASE, ADC12_CH1_BASE, ADC12_CH2_BASE, ADC12_CH3_BASE,
         ADC12_CH4_BASE, ADC12_CH5_BASE, ADC12_CH6_BASE, ADC12_CH7_BASE,
         ADC12_CH8_BASE, ADC12_CH9_BASE, ADC12_CH10_BASE, ADC12_CH11_BASE,
         ADC12_CH12_BASE, ADC12_CH13_BASE, ADC12_CH14_BASE, ADC12_CH15_BASE,
    };
    uintptr_t uptrReg = 0UL;
    uptrReg = ADC12_BLOCK_BASE[(uint8_t) enChannelArg];
    return(uptrReg);
}

uintptr_t ADC12__uptrBlockBaseAddress(void)
{
    uintptr_t uptrReg = 0U;
    uptrReg = ADC12_BASE;
    return(uptrReg);
}




