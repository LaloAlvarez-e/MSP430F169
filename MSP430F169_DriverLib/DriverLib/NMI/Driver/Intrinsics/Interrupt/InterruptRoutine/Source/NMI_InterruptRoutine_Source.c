/**
 *
 * @file NMI_InterruptRoutine_Source.c
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
#include "DriverLib/NMI/Driver/Intrinsics/Interrupt/InterruptRoutine/Header/NMI_InterruptRoutine_Source.h"

static MCU__pu16fIRQSourceHandler_t NMI_pu16fIRQSourceHandler = &MCU__u16IRQSourceHandler_Dummy;


MCU__pu16fIRQSourceHandler_t NMI__pu16fGetIRQSourceHandler(void)
{
    MCU__pu16fIRQSourceHandler_t IRQSourceHandler;
    IRQSourceHandler = NMI_pu16fIRQSourceHandler;
    return (IRQSourceHandler);
}

void NMI__vSetIRQSourceHandler(MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler)
{
    NMI_pu16fIRQSourceHandler = pu16fIRQSourceHandler;
}


