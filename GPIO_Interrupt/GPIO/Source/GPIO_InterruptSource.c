/**
 *
 * @file GPIO_InterruptSource.c
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
 * @verbatim 4 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 4 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "GPIO/Header/GPIO_InterruptSource.h"
#include <stdint.h>


static uint16_t GPIO_u16DummySource(void);

uint16_t (*GPIO_pu16fIRQSourceHandler[8U])(void) =
{
 &GPIO_u16DummySource,
 &GPIO_u16DummySource,
 &GPIO_u16DummySource,
 &GPIO_u16DummySource,
 &GPIO_u16DummySource,
 &GPIO_u16DummySource,
 &GPIO_u16DummySource,
 &GPIO_u16DummySource,
};


static uint16_t GPIO_u16DummySource(void)
{
    while(1U)
    {
    }
    return (0U);
}

uint16_t (*GPIO__pu16fGetInterruptSource(uint8_t u8Pin))(void)
{
    uint16_t (*IRQSourceHandler)(void) = (uint16_t (*)(void)) 0U;
    IRQSourceHandler = GPIO_pu16fIRQSourceHandler[u8Pin];
    return (IRQSourceHandler);
}

void GPIO__vSetInterruptSource(uint8_t u8Pin, uint16_t (*pu16fFunctionality)(void))
{
    GPIO_pu16fIRQSourceHandler[u8Pin] = pu16fFunctionality;
}

