/**
 *
 * @file DMA_InterruptRoutine_Source.c
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
#include "DriverLib/DMA/Driver/Intrinsics/Interrupt/InterruptRoutine/Header/DMA_InterruptRoutine_Source.h"

static uint16_t DMA_u16IRQSourceHandler_Dummy(uintptr_t uptrModule,
                                               uint8_t u8IntSource);

static MCU__pu16fIRQSourceHandler_t DMA_pu16fIRQSourceHandler[(uint8_t) DMA_enPORT2 + 1U]
                                                              [(uint8_t) DMA_enPIN_NUMBER_MAX]=
{
    {
        &DMA_u16IRQSourceHandler_Dummy,
        &DMA_u16IRQSourceHandler_Dummy,
        &DMA_u16IRQSourceHandler_Dummy,
        &DMA_u16IRQSourceHandler_Dummy,
        &DMA_u16IRQSourceHandler_Dummy,
        &DMA_u16IRQSourceHandler_Dummy,
        &DMA_u16IRQSourceHandler_Dummy,
        &DMA_u16IRQSourceHandler_Dummy,
    },
    {
        &DMA_u16IRQSourceHandler_Dummy,
        &DMA_u16IRQSourceHandler_Dummy,
        &DMA_u16IRQSourceHandler_Dummy,
        &DMA_u16IRQSourceHandler_Dummy,
        &DMA_u16IRQSourceHandler_Dummy,
        &DMA_u16IRQSourceHandler_Dummy,
        &DMA_u16IRQSourceHandler_Dummy,
        &DMA_u16IRQSourceHandler_Dummy,
    },
};

static uint16_t DMA_u16IRQSourceHandler_Dummy(uintptr_t uptrModule,
                                               uint8_t u8IntSource)
{
    while(1U)
    {
    }
    return (0U);
}
MCU__pu16fIRQSourceHandler_t DMA__pu16fGetIRQSourceHandler(DMA_nPORT enPortArg, DMA_nPIN_NUMBER enPin)
{
    MCU__pu16fIRQSourceHandler_t IRQSourceHandler = (MCU__pu16fIRQSourceHandler_t) 0U;
    if((DMA_enPORT1 == enPortArg) || (DMA_enPORT2 == enPortArg))
    {
        IRQSourceHandler = DMA_pu16fIRQSourceHandler[(uint8_t) enPortArg][(uint8_t) enPin];
    }
    return (IRQSourceHandler);
}

void DMA__vSetIRQSourceHandler(DMA_nPORT enPortArg, DMA_nPIN_NUMBER enPin,
                                MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler)
{
    if((DMA_enPORT1 == enPortArg) || (DMA_enPORT2 == enPortArg))
    {
    DMA_pu16fIRQSourceHandler[(uint8_t) enPortArg][(uint8_t) enPin] = pu16fIRQSourceHandler;
    }
}
