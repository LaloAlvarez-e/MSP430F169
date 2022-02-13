/**
 *
 * @file CLOCK_InterruprRegister_Source.c
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
 * @verbatim 13 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 13 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "CLOCK/Driver/Intrinsics/Interrupt/InterruptRegister/Header/CLOCK_InterruptRegister_Source.h"
#include "CLOCK/Driver/Intrinsics/Interrupt/InterruptRoutine/Header/CLOCK_InterruptRoutine_Source.h"

void CLOCK__vRegisterIRQSourceHandler(MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler)
{
    if(0U != (uintptr_t) pu16fIRQSourceHandler)
    {
        CLOCK__vSetIRQSourceHandler(pu16fIRQSourceHandler);
    }
}



