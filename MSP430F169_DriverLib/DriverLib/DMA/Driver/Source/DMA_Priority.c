/**
 *
 * @file DMA_Priority.c
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
#include <DriverLib/DMA/Driver/Header/DMA_Priority.h>
#include "DriverLib/DMA/Driver/Intrinsics/DMA_Intrinsics.h"
#include "DriverLib/DMA/Peripheral/DMA_Peripheral.h"

void DMA__vSetPriorityMode(DMA_nPRIORITY enPriorityArg)
{
    DMA_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = DMA_CTL1_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enPriorityArg;
    pstRegisterData.u16Mask = DMA_CTL1_ROUNDROBIN_MASK;
    pstRegisterData.u8Shift = DMA_CTL1_R_ROUNDROBIN_BIT;
    DMA__vWriteRegister(&pstRegisterData);
}

DMA_nPRIORITY DMA__enGetPriorityMode(void)
{
    DMA_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = DMA_CTL1_OFFSET;
    pstRegisterData.u16Value = 0U;
    pstRegisterData.u16Mask = DMA_CTL1_ROUNDROBIN_MASK;
    pstRegisterData.u8Shift = DMA_CTL1_R_ROUNDROBIN_BIT;
    (void) DMA__u16ReadRegister(&pstRegisterData);
    return ((DMA_nPRIORITY) pstRegisterData.u16Value);
}



