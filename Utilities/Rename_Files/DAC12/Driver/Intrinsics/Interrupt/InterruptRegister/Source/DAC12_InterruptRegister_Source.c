/**
 *
 * @file DAC12_InterruptRegister_Source.c
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

#include "DriverLib/DAC12/Driver/Intrinsics/Interrupt/InterruptRegister/Header/DAC12_InterruptRegister_Source.h"
#include "DriverLib/DAC12/Driver/Intrinsics/Interrupt/InterruptRoutine/Header/DAC12_InterruptRoutine_Source.h"

void DAC12_CH__vRegisterIRQSourceHandler(DAC12_nCH enChannelArg,
         MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler)
{
    if(0U != (uintptr_t) pu16fIRQSourceHandler)
    {
        DAC12_CH__vSetIRQSourceHandler(enChannelArg, pu16fIRQSourceHandler);
    }
}

void DAC12__vRegisterIRQSourceHandler(DAC12_nINTERRUPT enInterruptArg,
         MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler)
{
    if(0U != (uintptr_t) pu16fIRQSourceHandler)
    {
        DAC12__vSetIRQSourceHandler(enInterruptArg, pu16fIRQSourceHandler);
    }
}
