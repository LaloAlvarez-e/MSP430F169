/**
 *
 * @file DMA_Enable.c
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
 * @verbatim 28 mar. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 28 mar. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <DriverLib/DMA/Driver/Channel/Config/Header/DMA_Enable.h>
#include "DriverLib/DMA/Driver/Intrinsics/DMA_Intrinsics.h"
#include "DriverLib/DMA/Peripheral/DMA_Peripheral.h"

void DMA_CH__vSetEnable(DMA_nCH enChannelArg,
                      DMA_nCH_ENABLE enEnableArg)
{
    DMA_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = DMA_CH_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enEnableArg;
    pstRegisterData.u16Mask = DMA_CH_CTL_EN_MASK;
    pstRegisterData.u8Shift = DMA_CH_CTL_R_EN_BIT;
    DMA_CH__vWriteRegister(enChannelArg,
                         &pstRegisterData);
}

DMA_nCH_ENABLE DMA_CH__enGetEnable(DMA_nCH enChannelArg)
{
    DMA_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = DMA_CH_CTL_OFFSET;
    pstRegisterData.u16Value = 0U;
    pstRegisterData.u16Mask = DMA_CH_CTL_EN_MASK;
    pstRegisterData.u8Shift = DMA_CH_CTL_R_EN_BIT;
    (void) DMA_CH__u16ReadRegister(enChannelArg, &pstRegisterData);
    return ((DMA_nCH_ENABLE) pstRegisterData.u16Value);
}
