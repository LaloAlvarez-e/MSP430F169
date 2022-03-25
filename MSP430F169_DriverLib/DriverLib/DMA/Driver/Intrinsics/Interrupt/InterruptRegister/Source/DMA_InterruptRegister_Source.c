/**
 *
 * @file DMA_InterruptRegister_Source.c
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

#include "DriverLib/DMA/Driver/Intrinsics/Interrupt/InterruptRegister/Header/DMA_InterruptRegister_Source.h"
#include "DriverLib/DMA/Driver/Intrinsics/Interrupt/InterruptRoutine/Header/DMA_InterruptRoutine_Source.h"

void DMA__vRegisterIRQSourceHandler(DMA_nCH enChannelArg, DMA_nCH_TRIGGER enTrigger,
         MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler)
{
    if(0U != (uintptr_t) pu16fIRQSourceHandler)
    {
        DMA__vSetIRQSourceHandler(enChannelArg, enTrigger, pu16fIRQSourceHandler);
    }
}
