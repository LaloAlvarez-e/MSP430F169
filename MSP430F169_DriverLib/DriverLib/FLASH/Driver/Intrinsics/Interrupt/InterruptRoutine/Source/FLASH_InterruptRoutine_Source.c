/**
 *
 * @file FLASH_InterruptRoutine_Source.c
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
 * @verbatim 25 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 25 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/FLASH/Driver/Intrinsics/Interrupt/InterruptRoutine/Header/FLASH_InterruptRoutine_Source.h"

static uint16_t FLASH_u16IRQSourceHandler_Dummy(uintptr_t uptrModule,
                                               uint8_t u8IntSource);

static MCU__pu16fIRQSourceHandler_t FLASH_pu16fIRQSourceHandler = &FLASH_u16IRQSourceHandler_Dummy;

static uint16_t FLASH_u16IRQSourceHandler_Dummy(uintptr_t uptrModule,
                                               uint8_t u8IntSource)
{
    while(1U)
    {
    }
    return (0U);
}


MCU__pu16fIRQSourceHandler_t FLASH__pu16fGetIRQSourceHandler(void)
{
    MCU__pu16fIRQSourceHandler_t IRQSourceHandler = (MCU__pu16fIRQSourceHandler_t) 0U;
    IRQSourceHandler = FLASH_pu16fIRQSourceHandler;
    return (IRQSourceHandler);
}

void FLASH__vSetIRQSourceHandler(MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler)
{
    FLASH_pu16fIRQSourceHandler = pu16fIRQSourceHandler;
}


