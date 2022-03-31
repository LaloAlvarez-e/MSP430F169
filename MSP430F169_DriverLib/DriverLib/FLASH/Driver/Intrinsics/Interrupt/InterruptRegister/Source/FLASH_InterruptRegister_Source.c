/**
 *
 * @file FLASH_InterruptRegister_Source.c
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
 * @verbatim 26 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 26 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/FLASH/Driver/Intrinsics/Interrupt/InterruptRegister/Header/FLASH_InterruptRegister_Source.h"
#include "DriverLib/FLASH/Driver/Intrinsics/Interrupt/InterruptRoutine/Header/FLASH_InterruptRoutine_Source.h"

void FLASH__vRegisterIRQSourceHandler(MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler)
{
    if(0U != (uintptr_t) pu16fIRQSourceHandler)
    {
        FLASH__vSetIRQSourceHandler(pu16fIRQSourceHandler);
    }
}



