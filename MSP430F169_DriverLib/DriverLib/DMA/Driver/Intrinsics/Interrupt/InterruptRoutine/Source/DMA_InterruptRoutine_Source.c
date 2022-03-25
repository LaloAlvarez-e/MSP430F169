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

static MCU__pu16fIRQSourceHandler_t DMA_pu16fIRQSourceHandler[(uint8_t) DMA_enCH_MAX]
                                                              [(uint8_t) DMA_enCH_TRIGGER_MAX]=
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

MCU__pu16fIRQSourceHandler_t DMA__pu16fGetIRQSourceHandler(DMA_nCH enChannelArg, DMA_nCH_TRIGGER enTrigger)
{
    MCU__pu16fIRQSourceHandler_t IRQSourceHandler = (MCU__pu16fIRQSourceHandler_t) 0U;
    IRQSourceHandler = DMA_pu16fIRQSourceHandler[(uint8_t) enChannelArg][(uint8_t) enTrigger];
    return (IRQSourceHandler);
}

void DMA__vSetIRQSourceHandler(DMA_nCH enChannelArg, DMA_nCH_TRIGGER enTrigger,
                               MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler)
{
    DMA_pu16fIRQSourceHandler[(uint8_t) enChannelArg][(uint8_t) enTrigger] = pu16fIRQSourceHandler;
}
