/**
 *
 * @file FLASH_InterruptRoutine_Vector.c
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
#include "DriverLib/FLASH/Driver/Intrinsics/Interrupt/InterruptRoutine/Header/FLASH_InterruptRoutine_Vector.h"
#include "DriverLib/FLASH/Driver/Intrinsics/Interrupt/InterruptRoutine/Header/FLASH_InterruptRoutine_Source.h"

#include "DriverLib/FLASH/Driver/Intrinsics/Primitives/FLASH_Primitives.h"
#include "DriverLib/FLASH/Peripheral/FLASH_Peripheral.h"
#include <msp430.h>

__interrupt void FLASH_IRQVectorHandler(void)
{
    MCU__pu16fIRQSourceHandler_t IRQSourceHandlerReg = (MCU__pu16fIRQSourceHandler_t) 0UL;
    uint16_t u16Status = LPM4_bits;
    const uintptr_t optrBaseAddress = FLASH_BASE;

    IRQSourceHandlerReg = FLASH__pu16fGetIRQSourceHandler();
    u16Status &= IRQSourceHandlerReg(optrBaseAddress, 0U);

    __low_power_mode_off_on_exit();
    __bis_SR_register_on_exit(u16Status);
    _NOP();
}
