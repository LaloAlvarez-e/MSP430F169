/**
 *
 * @file DMA_IncrementMode.c
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
 * @verbatim 27 mar. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 27 mar. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <DriverLib/DMA/Driver/Channel/Config/Header/DMA_IncrementMode.h>
#include "DriverLib/DMA/Driver/Intrinsics/DMA_Intrinsics.h"
#include "DriverLib/DMA/Peripheral/DMA_Peripheral.h"

void DMA_CH__vSetSourceIncrementMode(DMA_nCH enChannelArg,
                          DMA_nCH_INCMODE enIncModeArg)
{
    DMA_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = DMA_CH_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enIncModeArg;
    pstRegisterData.u16Mask = DMA_CH_CTL_SRCINCR_MASK;
    pstRegisterData.u8Shift = DMA_CH_CTL_R_SRCINCR_BIT;
    DMA_CH__vWriteRegister(enChannelArg,
                         &pstRegisterData);
}

DMA_nCH_INCMODE DMA_CH__enGetSourceIncrementMode(DMA_nCH enChannelArg)
{
    DMA_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = DMA_CH_CTL_OFFSET;
    pstRegisterData.u16Value = 0U;
    pstRegisterData.u16Mask = DMA_CH_CTL_SRCINCR_MASK;
    pstRegisterData.u8Shift = DMA_CH_CTL_R_SRCINCR_BIT;
    (void) DMA_CH__u16ReadRegister(enChannelArg, &pstRegisterData);
    return ((DMA_nCH_INCMODE) pstRegisterData.u16Value);
}

void DMA_CH__vSetDestIncrementMode(DMA_nCH enChannelArg,
                          DMA_nCH_INCMODE enIncModeArg)
{
    DMA_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = DMA_CH_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enIncModeArg;
    pstRegisterData.u16Mask = DMA_CH_CTL_DSTINCR_MASK;
    pstRegisterData.u8Shift = DMA_CH_CTL_R_DSTINCR_BIT;
    DMA_CH__vWriteRegister(enChannelArg,
                         &pstRegisterData);
}

DMA_nCH_INCMODE DMA_CH__enGetDestIncrementMode(DMA_nCH enChannelArg)
{
    DMA_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = DMA_CH_CTL_OFFSET;
    pstRegisterData.u16Value = 0U;
    pstRegisterData.u16Mask = DMA_CH_CTL_DSTINCR_MASK;
    pstRegisterData.u8Shift = DMA_CH_CTL_R_DSTINCR_BIT;
    (void) DMA_CH__u16ReadRegister(enChannelArg, &pstRegisterData);
    return ((DMA_nCH_INCMODE) pstRegisterData.u16Value);
}




