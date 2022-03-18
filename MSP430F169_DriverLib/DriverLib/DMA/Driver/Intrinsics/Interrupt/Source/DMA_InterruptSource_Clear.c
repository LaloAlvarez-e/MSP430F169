/**
 *
 * @file DMA_InterruptSource_Clear.c
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
#include "DriverLib/DMA/Driver/Intrinsics/Interrupt/Header/DMA_InterruptSource_Clear.h"

#include "DriverLib/DMA/Driver/Intrinsics/Primitives/DMA_Primitives.h"
#include "DriverLib/DMA/Peripheral/DMA_Peripheral.h"


void DMA__vClearInterruptSource(DMA_nPORT enPortArg,
                                 DMA_nPIN enPinMask)
{
    DMA_Register_t pstRegisterData = {0UL};
    if((DMA_enPORT1 == enPortArg) || (DMA_enPORT2 == enPortArg))
    {
        pstRegisterData.uptrAddress = PORT_IFG_OFFSET;
        pstRegisterData.u8Value = PORT_IFG_PIN0_NOOCCUR;
        pstRegisterData.u8Mask = (uint8_t) enPinMask;
        pstRegisterData.u8Shift = PORT_IFG_R_PIN0_BIT;
        DMA__vWriteRegister(enPortArg,
                             &pstRegisterData);
    }
}

void DMA__vClearInterruptSourceByNumber(DMA_nPORT enPortArg,
                                 DMA_nPIN_NUMBER enPinNumber)
{
    DMA_Register_t pstRegisterData = {0UL};
    if((DMA_enPORT1 == enPortArg) || (DMA_enPORT2 == enPortArg))
    {
        pstRegisterData.uptrAddress = PORT_IFG_OFFSET;
        pstRegisterData.u8Value = PORT_IFG_PIN0_NOOCCUR;
        pstRegisterData.u8Mask = PORT_IFG_PIN0_MASK;
        pstRegisterData.u8Shift = (uint8_t) enPinNumber;
        DMA__vWriteRegister(enPortArg,
                             &pstRegisterData);
    }
}
