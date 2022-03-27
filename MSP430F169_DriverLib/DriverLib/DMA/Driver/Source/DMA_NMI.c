/**
 *
 * @file DMA_NMI.c
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
#include <DriverLib/DMA/Driver/Header/DMA_NMI.h>
#include "DriverLib/DMA/Driver/Intrinsics/DMA_Intrinsics.h"
#include "DriverLib/DMA/Peripheral/DMA_Peripheral.h"

void DMA__vSetNMITranferStop(DMA_nENABLE enNMIEnableArg)
{
    DMA_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = DMA_CTL1_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enNMIEnableArg;
    pstRegisterData.u16Mask = DMA_CTL1_ENNMI_MASK;
    pstRegisterData.u8Shift = DMA_CTL1_R_ENNMI_BIT;
    DMA__vWriteRegister(&pstRegisterData);
}

DMA_nENABLE DMA__enGetNMITranferStop(void)
{
    DMA_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = DMA_CTL1_OFFSET;
    pstRegisterData.u16Value = 0U;
    pstRegisterData.u16Mask = DMA_CTL1_ENNMI_MASK;
    pstRegisterData.u8Shift = DMA_CTL1_R_ENNMI_BIT;
    (void) DMA__u16ReadRegister(&pstRegisterData);
    return ((DMA_nENABLE) pstRegisterData.u16Value);
}





