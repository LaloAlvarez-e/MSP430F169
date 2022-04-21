/**
 *
 * @file ADC12_InterruptRegister_Source.c
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

#include "DriverLib/ADC12/Driver/Intrinsics/Interrupt/InterruptRegister/Header/ADC12_InterruptRegister_Source.h"
#include "DriverLib/ADC12/Driver/Intrinsics/Interrupt/InterruptRoutine/Header/ADC12_InterruptRoutine_Source.h"

void ADC12_CH__vRegisterIRQSourceHandler(ADC12_nCH enChannelArg,
         MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler)
{
    if(0U != (uintptr_t) pu16fIRQSourceHandler)
    {
        ADC12_CH__vSetIRQSourceHandler(enChannelArg, pu16fIRQSourceHandler);
    }
}

void ADC12__vRegisterIRQSourceHandler(ADC12_nINTERRUPT enInterruptArg,
         MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler)
{
    if(0U != (uintptr_t) pu16fIRQSourceHandler)
    {
        ADC12__vSetIRQSourceHandler(enInterruptArg, pu16fIRQSourceHandler);
    }
}
