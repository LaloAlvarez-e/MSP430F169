/**
 *
 * @file DMA_Abort.c
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
#include <DriverLib/DMA/Driver/Channel/Config/Header/DMA_Abort.h>
#include "DriverLib/DMA/Driver/Intrinsics/DMA_Intrinsics.h"
#include "DriverLib/DMA/Peripheral/DMA_Peripheral.h"

void DMA__vSetAbort(DMA_nCH enChannelArg,
                      DMA_nCH_ABORT enAbortArg)
{
    DMA_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = DMA_CH_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enAbortArg;
    pstRegisterData.u16Mask = DMA_CH_CTL_ABORT_MASK;
    pstRegisterData.u8Shift = DMA_CH_CTL_R_ABORT_BIT;
    DMA_CH__vWriteRegister(enChannelArg,
                         &pstRegisterData);
}

void DMA__vClearAbort(DMA_nCH enChannelArg)
{
    DMA__vSetAbort(enChannelArg, DMA_enCH_ABORT_CLEAR);
}

DMA_nCH_ABORT DMA__enGetAbort(DMA_nCH enChannelArg)
{
    DMA_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = DMA_CH_CTL_OFFSET;
    pstRegisterData.u16Value = 0U;
    pstRegisterData.u16Mask = DMA_CH_CTL_ABORT_MASK;
    pstRegisterData.u8Shift = DMA_CH_CTL_R_ABORT_BIT;
    (void) DMA_CH__u16ReadRegister(enChannelArg, &pstRegisterData);
    return ((DMA_nCH_ABORT) pstRegisterData.u16Value);
}



