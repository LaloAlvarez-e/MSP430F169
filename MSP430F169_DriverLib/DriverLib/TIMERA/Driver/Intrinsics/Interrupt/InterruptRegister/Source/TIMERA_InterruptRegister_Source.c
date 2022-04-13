/**
 *
 * @file TIMERA_InterruptRegister_Source.c
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

#include "DriverLib/TIMERA/Driver/Intrinsics/Interrupt/InterruptRegister/Header/TIMERA_InterruptRegister_Source.h"
#include "DriverLib/TIMERA/Driver/Intrinsics/Interrupt/InterruptRoutine/Header/TIMERA_InterruptRoutine_Source.h"

void TIMERA_CC__vRegisterIRQSourceHandler(TIMERA_nCC enModuleArg, TIMERA_nCC_MODE enMODE,
         MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler)
{
    if(0U != (uintptr_t) pu16fIRQSourceHandler)
    {
        TIMERA_CC__vSetIRQSourceHandler(enModuleArg, enMODE, pu16fIRQSourceHandler);
    }
}


void TIMERA__vRegisterIRQSourceHandler(MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler)
{
    if(0U != (uintptr_t) pu16fIRQSourceHandler)
    {
        TIMERA__vSetIRQSourceHandler(pu16fIRQSourceHandler);
    }
}
