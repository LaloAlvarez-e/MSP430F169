/**
 *
 * @file DMA_InterruptSource_Enable.c
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
#include "DriverLib/DMA/Driver/Intrinsics/Interrupt/Header/DMA_InterruptSource_Enable.h"

#include "DriverLib/DMA/Driver/Intrinsics/Primitives/DMA_Primitives.h"
#include "DriverLib/DMA/Peripheral/DMA_Peripheral.h"

void DMA_CH__vSetEnableInterruptSource(DMA_nCH enChannelArg,
                                    DMA_nCH_INT_ENABLE enState)
{
    DMA_Register_t pstRegisterData;

    pstRegisterData.uptrAddress = DMA_CH_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enState;
    pstRegisterData.u16Mask = (uint16_t) DMA_CH_CTL_IE_MASK;
    pstRegisterData.u8Shift = DMA_CH_CTL_R_IE_BIT;

    DMA_CH__vWriteRegister(enChannelArg,
                         &pstRegisterData);
}

void DMA_CH__vEnaInterruptSource(DMA_nCH enChannelArg)
{
    DMA_CH__vSetEnableInterruptSource(enChannelArg, DMA_enCH_INT_ENABLE_ENA);
}

void DMA_CH__vDisInterruptSource(DMA_nCH enChannelArg)
{
    DMA_CH__vSetEnableInterruptSource(enChannelArg, DMA_enCH_INT_ENABLE_DIS);
}

DMA_nCH_INT_ENABLE DMA_CH__enGetEnableInterruptSource(DMA_nCH enChannelArg)
{
    DMA_Register_t pstRegisterData;
    DMA_nCH_INT_ENABLE enEnable;

    pstRegisterData.uptrAddress = DMA_CH_CTL_OFFSET;
    pstRegisterData.u16Mask = DMA_CH_CTL_IE_MASK;
    pstRegisterData.u8Shift = DMA_CH_CTL_R_IE_BIT;
    enEnable = (DMA_nCH_INT_ENABLE) DMA_CH__u16ReadRegister(enChannelArg,
                                                &pstRegisterData);
    return (enEnable);
}
