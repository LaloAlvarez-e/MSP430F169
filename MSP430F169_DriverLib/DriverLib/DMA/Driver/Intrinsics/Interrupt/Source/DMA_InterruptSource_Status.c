/**
 *
 * @file DMA_InterruptSource_Status.c
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
#include "DriverLib/DMA/Driver/Intrinsics/Interrupt/Header/DMA_InterruptSource_Status.h"

#include "DriverLib/DMA/Driver/Intrinsics/Primitives/DMA_Primitives.h"
#include "DriverLib/DMA/Peripheral/DMA_Peripheral.h"

void DMA_CH__vSetStatusInterruptSource(DMA_nCH enChannelArg,
                                    DMA_nCH_INT_STATUS enStatus)
{
    DMA_Register_t pstRegisterData;

    pstRegisterData.uptrAddress = DMA_CH_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enStatus;
    pstRegisterData.u16Mask = DMA_CH_CTL_IFG_MASK;
    pstRegisterData.u8Shift = DMA_CH_CTL_R_IFG_BIT;
    DMA_CH__vWriteRegister(enChannelArg,
                         &pstRegisterData);
}

DMA_nCH_INT_STATUS DMA_CH__enGetStatusInterruptSource(DMA_nCH enChannelArg)
{
    DMA_Register_t pstRegisterData;
    DMA_nCH_INT_STATUS enStatus;

    pstRegisterData.uptrAddress = DMA_CH_CTL_OFFSET;
    pstRegisterData.u16Mask = DMA_CH_CTL_IFG_MASK;
    pstRegisterData.u8Shift = DMA_CH_CTL_R_IFG_BIT;

    enStatus = (DMA_nCH_INT_STATUS) DMA_CH__u16ReadRegister(enChannelArg,
                                                &pstRegisterData);
    return (enStatus);
}


