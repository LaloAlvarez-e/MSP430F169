/**
 *
 * @file DAC12_InterruptRoutine_Source.c
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
#include "DriverLib/DAC12/Driver/Intrinsics/Interrupt/InterruptRoutine/Header/DAC12_InterruptRoutine_Source.h"

static MCU__pu16fIRQSourceHandler_t DAC12_CH_pu16fIRQSourceHandler[(uint8_t) DAC12_enCH_MAX]=
{
    &MCU__u16IRQSourceHandler_Dummy,
    &MCU__u16IRQSourceHandler_Dummy,
    &MCU__u16IRQSourceHandler_Dummy,
    &MCU__u16IRQSourceHandler_Dummy,
    &MCU__u16IRQSourceHandler_Dummy,
    &MCU__u16IRQSourceHandler_Dummy,
    &MCU__u16IRQSourceHandler_Dummy,
    &MCU__u16IRQSourceHandler_Dummy,
    &MCU__u16IRQSourceHandler_Dummy,
    &MCU__u16IRQSourceHandler_Dummy,
    &MCU__u16IRQSourceHandler_Dummy,
    &MCU__u16IRQSourceHandler_Dummy,
    &MCU__u16IRQSourceHandler_Dummy,
    &MCU__u16IRQSourceHandler_Dummy,
    &MCU__u16IRQSourceHandler_Dummy,
    &MCU__u16IRQSourceHandler_Dummy,
};


static MCU__pu16fIRQSourceHandler_t DAC12_pu16fIRQSourceHandler[(uint8_t) DAC12_enINTERRUPT_MAX]=
{
    &MCU__u16IRQSourceHandler_Dummy,
    &MCU__u16IRQSourceHandler_Dummy,
};


MCU__pu16fIRQSourceHandler_t DAC12_CH__pu16fGetIRQSourceHandler(DAC12_nCH enChannelArg)
{
    MCU__pu16fIRQSourceHandler_t IRQSourceHandler = (MCU__pu16fIRQSourceHandler_t) 0U;
    IRQSourceHandler = DAC12_CH_pu16fIRQSourceHandler[(uint8_t) enChannelArg];
    return (IRQSourceHandler);
}

void DAC12_CH__vSetIRQSourceHandler(DAC12_nCH enChannelArg,
                               MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler)
{
    DAC12_CH_pu16fIRQSourceHandler[(uint8_t) enChannelArg] = pu16fIRQSourceHandler;
}



MCU__pu16fIRQSourceHandler_t DAC12__pu16fGetIRQSourceHandler(DAC12_nINTERRUPT enInterruptArg)
{
    MCU__pu16fIRQSourceHandler_t IRQSourceHandler = (MCU__pu16fIRQSourceHandler_t) 0U;
    IRQSourceHandler = DAC12_pu16fIRQSourceHandler[(uint8_t) enInterruptArg];
    return (IRQSourceHandler);
}

void DAC12__vSetIRQSourceHandler(DAC12_nINTERRUPT enInterruptArg,
                               MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler)
{
    DAC12_pu16fIRQSourceHandler[(uint8_t) enInterruptArg] = pu16fIRQSourceHandler;
}
