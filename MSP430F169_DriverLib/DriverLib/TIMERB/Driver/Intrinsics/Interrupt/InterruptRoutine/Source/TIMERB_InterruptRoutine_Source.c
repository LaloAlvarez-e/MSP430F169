/**
 *
 * @file TIMERB_InterruptRoutine_Source.c
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
#include "DriverLib/TIMERB/Driver/Intrinsics/Interrupt/InterruptRoutine/Header/TIMERB_InterruptRoutine_Source.h"

static MCU__pu16fIRQSourceHandler_t TIMERB_CC_pu16fIRQSourceHandler[(uint8_t) TIMERB_enCC_MAX]
                                                              [(uint8_t) TIMERB_enCC_MODE_MAX]=
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
    {
        &MCU__u16IRQSourceHandler_Dummy,
        &MCU__u16IRQSourceHandler_Dummy,
    },
};

static MCU__pu16fIRQSourceHandler_t TIMERB_pu16fIRQSourceHandler = &MCU__u16IRQSourceHandler_Dummy;


MCU__pu16fIRQSourceHandler_t TIMERB_CC__pu16fGetIRQSourceHandler(TIMERB_nCC enModuleArg, TIMERB_nCC_MODE enMode)
{
    MCU__pu16fIRQSourceHandler_t IRQSourceHandler;
    IRQSourceHandler = TIMERB_CC_pu16fIRQSourceHandler[(uint8_t) enModuleArg][(uint8_t) enMode];
    return (IRQSourceHandler);
}

void TIMERB_CC__vSetIRQSourceHandler(TIMERB_nCC enModuleArg, TIMERB_nCC_MODE enMode,
                               MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler)
{
    TIMERB_CC_pu16fIRQSourceHandler[(uint8_t) enModuleArg][(uint8_t) enMode] = pu16fIRQSourceHandler;
}

MCU__pu16fIRQSourceHandler_t TIMERB__pu16fGetIRQSourceHandler(void)
{
    MCU__pu16fIRQSourceHandler_t IRQSourceHandler;
    IRQSourceHandler = TIMERB_pu16fIRQSourceHandler;
    return (IRQSourceHandler);
}

void TIMERB__vSetIRQSourceHandler(MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler)
{
    TIMERB_pu16fIRQSourceHandler = pu16fIRQSourceHandler;
}

