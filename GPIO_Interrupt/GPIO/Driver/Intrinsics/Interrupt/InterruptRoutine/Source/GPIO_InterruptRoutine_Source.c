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
#include "GPIO/Driver/Intrinsics/Interrupt/InterruptRoutine/Header/GPIO_InterruptRoutine_Source.h"

static uint16_t GPIO_u16IRQSourceHandler_Dummy(PORT_EXT_t* pstPort,
                                               GPIO_nPIN_NUMBER enPinNumber);

static uint16_t (*GPIO_pu16fIRQSourceHandler[(uint8_t) GPIO_enPORT2 + 1U]
                                     [(uint8_t) GPIO_enPIN_NUMBER_MAX])
                                             (PORT_EXT_t* pstPort, GPIO_nPIN_NUMBER enPinNumber) =
{
    {
        &GPIO_u16IRQSourceHandler_Dummy,
        &GPIO_u16IRQSourceHandler_Dummy,
        &GPIO_u16IRQSourceHandler_Dummy,
        &GPIO_u16IRQSourceHandler_Dummy,
        &GPIO_u16IRQSourceHandler_Dummy,
        &GPIO_u16IRQSourceHandler_Dummy,
        &GPIO_u16IRQSourceHandler_Dummy,
        &GPIO_u16IRQSourceHandler_Dummy,
    },
    {
        &GPIO_u16IRQSourceHandler_Dummy,
        &GPIO_u16IRQSourceHandler_Dummy,
        &GPIO_u16IRQSourceHandler_Dummy,
        &GPIO_u16IRQSourceHandler_Dummy,
        &GPIO_u16IRQSourceHandler_Dummy,
        &GPIO_u16IRQSourceHandler_Dummy,
        &GPIO_u16IRQSourceHandler_Dummy,
        &GPIO_u16IRQSourceHandler_Dummy,
    },
};

static uint16_t GPIO_u16IRQSourceHandler_Dummy(PORT_EXT_t* pstPort,
                                               GPIO_nPIN_NUMBER enPinNumber)
{
    while(1U)
    {
    }
    return (0U);
}

uint16_t (*GPIO__pu16fGetIRQSourceHandler(GPIO_nPORT enPortArg, GPIO_nPIN_NUMBER enPin))
(PORT_EXT_t* pstPortArg, GPIO_nPIN_NUMBER enPinNumberArg)
{
    uint16_t (*IRQSourceHandler)(PORT_EXT_t* pstPortArg, GPIO_nPIN_NUMBER enPinNumberArg) =
            (uint16_t (*)(PORT_EXT_t* pstPortArg, GPIO_nPIN_NUMBER enPinNumberArg)) 0U;
    if((GPIO_enPORT1 == enPortArg) || (GPIO_enPORT2 == enPortArg))
    {
        IRQSourceHandler = GPIO_pu16fIRQSourceHandler[(uint8_t) enPortArg][(uint8_t) enPin];
    }
    return (IRQSourceHandler);
}

void GPIO__vSetIRQSourceHandler(GPIO_nPORT enPortArg, GPIO_nPIN_NUMBER enPin,
                                uint16_t (*IRQSourceHandler)(PORT_EXT_t* pstPortArg, GPIO_nPIN_NUMBER enPinNumberArg))
{
    if((GPIO_enPORT1 == enPortArg) || (GPIO_enPORT2 == enPortArg))
    {
        GPIO_pu16fIRQSourceHandler[(uint8_t) enPortArg][(uint8_t) enPin] = IRQSourceHandler;
    }
}
