/**
 *
 * @file DMA_Trigger.c
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
#include <DriverLib/DMA/Driver/Channel/Header/DMA_Trigger.h>
#include "DriverLib/DMA/Driver/Intrinsics/DMA_Intrinsics.h"
#include "DriverLib/DMA/Peripheral/DMA_Peripheral.h"

void DMA__vSetTrigger(DMA_nCH enChannelArg,
                      DMA_nCH_TRIGGER enTriggerArg)
{
    uint16_t u16ShiftTemp = DMA_CTL0_R_CH1TSEL_BIT;
    DMA_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = DMA_CTL0_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enTriggerArg;
    pstRegisterData.u16Mask = DMA_CTL0_CHTSEL_MASK;
    u16ShiftTemp *= (uint16_t) enChannelArg;
    pstRegisterData.u8Shift = u16ShiftTemp;
    DMA__vWriteRegister(&pstRegisterData);
}

DMA_nCH_TRIGGER DMA__enGetTrigger(DMA_nCH enChannelArg)
{
    uint16_t u16ShiftTemp = DMA_CTL0_R_CH1TSEL_BIT;
    DMA_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = DMA_CTL0_OFFSET;
    pstRegisterData.u16Value = 0U;
    pstRegisterData.u16Mask = DMA_CTL0_CHTSEL_MASK;
    u16ShiftTemp *= (uint16_t) enChannelArg;
    pstRegisterData.u8Shift = u16ShiftTemp;
    (void) DMA__u16ReadRegister(&pstRegisterData);
    return ((DMA_nCH_TRIGGER) pstRegisterData.u16Value);
}




