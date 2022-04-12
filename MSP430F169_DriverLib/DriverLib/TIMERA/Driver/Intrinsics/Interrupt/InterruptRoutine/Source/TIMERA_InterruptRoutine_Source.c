/**
 *
 * @file TIMERA_InterruptRoutine_Source.c
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
#include "DriverLib/TIMERA/Driver/Intrinsics/Interrupt/InterruptRoutine/Header/TIMERA_InterruptRoutine_Source.h"

static MCU__pu16fIRQSourceHandler_t TIMERA_CC_pu16fIRQSourceHandler[(uint8_t) TIMERA_enCC_MAX]
                                                              [(uint8_t) TIMERA_enCC_MODE_MAX]=
{
    {
        &MCU__u16IRQSourceHandler_Dummy,
        &MCU__u16IRQSourceHandler_Dummy,
    },
    {
        &MCU__u16IRQSourceHandler_Dummy,
        &MCU__u16IRQSourceHandler_Dummy,
    },
    {
        &MCU__u16IRQSourceHandler_Dummy,
        &MCU__u16IRQSourceHandler_Dummy,
    },
};

static MCU__pu16fIRQSourceHandler_t TIMERA_pu16fIRQSourceHandler = &MCU__u16IRQSourceHandler_Dummy;


MCU__pu16fIRQSourceHandler_t TIMERA_CC__pu16fGetIRQSourceHandler(TIMERA_nCC enModuleArg, TIMERA_nCC_MODE enMode)
{
    MCU__pu16fIRQSourceHandler_t IRQSourceHandler = (MCU__pu16fIRQSourceHandler_t) 0U;
    IRQSourceHandler = TIMERA_CC_pu16fIRQSourceHandler[(uint8_t) enModuleArg][(uint8_t) enMode];
    return (IRQSourceHandler);
}

void TIMERA_CC__vSetIRQSourceHandler(TIMERA_nCC enModuleArg, TIMERA_nCC_MODE enMode,
                               MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler)
{
    TIMERA_CC_pu16fIRQSourceHandler[(uint8_t) enModuleArg][(uint8_t) enMode] = pu16fIRQSourceHandler;
}

MCU__pu16fIRQSourceHandler_t TIMERA__pu16fGetIRQSourceHandler(void)
{
    MCU__pu16fIRQSourceHandler_t IRQSourceHandler = (MCU__pu16fIRQSourceHandler_t) 0U;
    IRQSourceHandler = TIMERA_pu16fIRQSourceHandler;
    return (IRQSourceHandler);
}

void TIMERA__vSetIRQSourceHandler(MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler)
{
    TIMERA_pu16fIRQSourceHandler = pu16fIRQSourceHandler;
}

