/**
 *
 * @file GPIO_InterruptRoutine_Source.c
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
#include "DriverLib/GPIO/Driver/Intrinsics/Interrupt/InterruptRoutine/Header/GPIO_InterruptRoutine_Source.h"

static MCU__pu16fIRQSourceHandler_t GPIO_pu16fIRQSourceHandler[(uint8_t) GPIO_enPORT2 + 1U]
                                                              [(uint8_t) GPIO_enPIN_NUMBER_MAX]=
{
    {
        &MCU__u16IRQSourceHandler_Dummy,
        &MCU__u16IRQSourceHandler_Dummy,
        &MCU__u16IRQSourceHandler_Dummy,
        &MCU__u16IRQSourceHandler_Dummy,
        &MCU__u16IRQSourceHandler_Dummy,
        &MCU__u16IRQSourceHandler_Dummy,
        &MCU__u16IRQSourceHandler_Dummy,
        &MCU__u16IRQSourceHandler_Dummy,
    },
    {
        &MCU__u16IRQSourceHandler_Dummy,
        &MCU__u16IRQSourceHandler_Dummy,
        &MCU__u16IRQSourceHandler_Dummy,
        &MCU__u16IRQSourceHandler_Dummy,
        &MCU__u16IRQSourceHandler_Dummy,
        &MCU__u16IRQSourceHandler_Dummy,
        &MCU__u16IRQSourceHandler_Dummy,
        &MCU__u16IRQSourceHandler_Dummy,
    },
};

MCU__pu16fIRQSourceHandler_t GPIO__pu16fGetIRQSourceHandler(GPIO_nPORT enPortArg, GPIO_nPIN_NUMBER enPin)
{
    MCU__pu16fIRQSourceHandler_t IRQSourceHandler;
    if((GPIO_enPORT1 == enPortArg) || (GPIO_enPORT2 == enPortArg))
    {
        IRQSourceHandler = GPIO_pu16fIRQSourceHandler[(uint8_t) enPortArg][(uint8_t) enPin];
    }
    else
    {
        IRQSourceHandler = (MCU__pu16fIRQSourceHandler_t) 0U;
    }
    return (IRQSourceHandler);
}

void GPIO__vSetIRQSourceHandler(GPIO_nPORT enPortArg, GPIO_nPIN_NUMBER enPin,
                                MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler)
{
    if((GPIO_enPORT1 == enPortArg) || (GPIO_enPORT2 == enPortArg))
    {
        GPIO_pu16fIRQSourceHandler[(uint8_t) enPortArg][(uint8_t) enPin] = pu16fIRQSourceHandler;
    }
}
