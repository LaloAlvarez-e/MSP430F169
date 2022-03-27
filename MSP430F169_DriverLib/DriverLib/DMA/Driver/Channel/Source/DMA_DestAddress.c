/**
 *
 * @file DMA_DestAddress.c
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
 * @verbatim 25 mar. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 25 mar. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <DriverLib/DMA/Driver/Channel/Header/DMA_DestAddress.h>
#include "DriverLib/DMA/Driver/Intrinsics/DMA_Intrinsics.h"
#include "DriverLib/DMA/Peripheral/DMA_Peripheral.h"

void DMA__vSetDestAddress(DMA_nCH enChannelArg,
                         uint16_t u16AddressArg)
{
    DMA_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = DMA_CH_DA_OFFSET;
    pstRegisterData.u16Value = (uint16_t) u16AddressArg;
    pstRegisterData.u16Mask = DMA_CH_DA_DA_MASK;
    pstRegisterData.u8Shift = DMA_CH_DA_R_DA_BIT;
    DMA_CH__vWriteRegister(enChannelArg,
                         &pstRegisterData);
}

uint16_t DMA__u16GetDestAddress(DMA_nCH enChannelArg)
{
    DMA_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = DMA_CH_DA_OFFSET;
    pstRegisterData.u16Value = 0U;
    pstRegisterData.u16Mask = DMA_CH_DA_DA_MASK;
    pstRegisterData.u8Shift = DMA_CH_DA_R_DA_BIT;
    (void) DMA_CH__u16ReadRegister(enChannelArg, &pstRegisterData);
    return (pstRegisterData.u16Value);
}



