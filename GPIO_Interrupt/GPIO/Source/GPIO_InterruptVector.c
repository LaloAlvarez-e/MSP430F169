/**
 *
 * @file GPIO_InterruptVector.c
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
#include "GPIO/Header/GPIO_InterruptVector.h"
#include "GPIO/Header/GPIO_InterruptSource.h"
#include <msp430.h>
#include <stdint.h>

#pragma vector = PORT1_VECTOR
__interrupt void PORT1_IrqHandler(void)
{
    uint16_t (*MyIRQSourceHandler) (void) = (uint16_t (*) (void)) 0UL;
    uint16_t u16Status = LPM4_bits;
    uint8_t u8Flags = P1IFG;
    uint8_t u8Enable = P1IE;

    u8Flags &= u8Enable;

    if(0U != (u8Flags & BIT0))
    {
        P1IFG &= ~BIT0;
        MyIRQSourceHandler = GPIO__pu16fGetInterruptSource(0U);
        u16Status &= MyIRQSourceHandler();
    }
    if(0U != (u8Flags & BIT1))
    {
        P1IFG &= ~BIT1;
        MyIRQSourceHandler = GPIO__pu16fGetInterruptSource(1U);
        u16Status &= MyIRQSourceHandler();
    }
    if(0U != (u8Flags & BIT2))
    {
        P1IFG &= ~BIT2;
        MyIRQSourceHandler = GPIO__pu16fGetInterruptSource(2U);
        u16Status &= MyIRQSourceHandler();
    }
    if(0U != (u8Flags & BIT3))
    {
        P1IFG &= ~BIT3;
        MyIRQSourceHandler = GPIO__pu16fGetInterruptSource(3U);
        u16Status &= MyIRQSourceHandler();
    }
    if(0U != (u8Flags & BIT4))
    {
        P1IFG &= ~BIT4;
        MyIRQSourceHandler = GPIO__pu16fGetInterruptSource(4U);
        u16Status &= MyIRQSourceHandler();
    }
    if(0U != (u8Flags & BIT5))
    {
        P1IFG &= ~BIT5;
        MyIRQSourceHandler = GPIO__pu16fGetInterruptSource(5U);
        u16Status &= MyIRQSourceHandler();
    }
    if(0U != (u8Flags & BIT6))
    {
        P1IFG &= ~BIT6;
        MyIRQSourceHandler = GPIO__pu16fGetInterruptSource(6U);
        u16Status &= MyIRQSourceHandler();
    }
    if(0U != (u8Flags & BIT7))
    {
        P1IFG &= ~BIT7;
        MyIRQSourceHandler = GPIO__pu16fGetInterruptSource(7U);
        u16Status &= MyIRQSourceHandler();
    }
    __low_power_mode_off_on_exit();
    __bis_SR_register_on_exit(u16Status);
    _NOP();
}
