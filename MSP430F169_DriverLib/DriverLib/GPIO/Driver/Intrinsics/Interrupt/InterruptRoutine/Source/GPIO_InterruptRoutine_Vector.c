/**
 *
 * @file GPIO_InterruptRoutine_Vector.c
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
#include "DriverLib/GPIO/Driver/Intrinsics/Interrupt/InterruptRoutine/Header/GPIO_InterruptRoutine_Vector.h"
#include "DriverLib/GPIO/Driver/Intrinsics/Interrupt/InterruptRoutine/Header/GPIO_InterruptRoutine_Source.h"

#include "DriverLib/GPIO/Driver/Intrinsics/Primitives/GPIO_Primitives.h"
#include "DriverLib/GPIO/Peripheral/GPIO_Peripheral.h"
#include <msp430.h>

__interrupt void PORT1_IRQVectorHandler(void)
{
    MCU__pu16fIRQSourceHandler_t IRQSourceHandlerReg = (MCU__pu16fIRQSourceHandler_t) 0UL;
    uint16_t u16Status = 0xFFU;
    uint8_t u8Flags = PORT1_IFG_R;
    uint8_t u8Enable = PORT1_IE_R;
    const uintptr_t optrBaseAddress = PORT1_BASE;

    u8Flags &= u8Enable;
    if(0U != (u8Flags & PORT_IFG_R_PIN0_MASK))
    {
        PORT1_IFG_R &= ~PORT_IFG_R_PIN0_MASK;
        IRQSourceHandlerReg = GPIO__pu16fGetIRQSourceHandler(GPIO_enPORT1, GPIO_enPIN_NUMBER0);

        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) GPIO_enPIN_NUMBER0);
    }
    if(0U != (u8Flags & PORT_IFG_R_PIN1_MASK))
    {
        PORT1_IFG_R &= ~PORT_IFG_R_PIN1_MASK;
        IRQSourceHandlerReg = GPIO__pu16fGetIRQSourceHandler(GPIO_enPORT1, GPIO_enPIN_NUMBER1);
        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) GPIO_enPIN_NUMBER1);
    }
    if(0U != (u8Flags & PORT_IFG_R_PIN2_MASK))
    {
        PORT1_IFG_R &= ~PORT_IFG_R_PIN2_MASK;
        IRQSourceHandlerReg = GPIO__pu16fGetIRQSourceHandler(GPIO_enPORT1, GPIO_enPIN_NUMBER2);
        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) GPIO_enPIN_NUMBER2);
    }
    if(0U != (u8Flags & PORT_IFG_R_PIN3_MASK))
    {
        PORT1_IFG_R &= ~PORT_IFG_R_PIN3_MASK;
        IRQSourceHandlerReg = GPIO__pu16fGetIRQSourceHandler(GPIO_enPORT1, GPIO_enPIN_NUMBER3);
        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) GPIO_enPIN_NUMBER3);
    }
    if(0U != (u8Flags & PORT_IFG_R_PIN4_MASK))
    {
        PORT1_IFG_R &= ~PORT_IFG_R_PIN4_MASK;
        IRQSourceHandlerReg = GPIO__pu16fGetIRQSourceHandler(GPIO_enPORT1, GPIO_enPIN_NUMBER4);
        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) GPIO_enPIN_NUMBER4);
    }
    if(0U != (u8Flags & PORT_IFG_R_PIN5_MASK))
    {
        PORT1_IFG_R &= ~PORT_IFG_R_PIN5_MASK;
        IRQSourceHandlerReg = GPIO__pu16fGetIRQSourceHandler(GPIO_enPORT1, GPIO_enPIN_NUMBER5);
        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) GPIO_enPIN_NUMBER5);
    }
    if(0U != (u8Flags & PORT_IFG_R_PIN6_MASK))
    {
        PORT1_IFG_R &= ~PORT_IFG_R_PIN6_MASK;
        IRQSourceHandlerReg = GPIO__pu16fGetIRQSourceHandler(GPIO_enPORT1, GPIO_enPIN_NUMBER6);
        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) GPIO_enPIN_NUMBER6);
    }
    if(0U != (u8Flags & PORT_IFG_R_PIN7_MASK))
    {
        PORT1_IFG_R &= ~PORT_IFG_R_PIN7_MASK;
        IRQSourceHandlerReg = GPIO__pu16fGetIRQSourceHandler(GPIO_enPORT1, GPIO_enPIN_NUMBER7);
        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) GPIO_enPIN_NUMBER7);
    }
    if(0xFFU != u16Status)
    {
        __low_power_mode_off_on_exit();
        __bis_SR_register_on_exit(u16Status);
        _NOP();
    }
}

__interrupt void PORT2_IRQVectorHandler(void)
{
    MCU__pu16fIRQSourceHandler_t IRQSourceHandlerReg = (MCU__pu16fIRQSourceHandler_t) 0UL;
    uint16_t u16Status = 0xFFU;
    uint8_t u8Flags = PORT2_IFG_R;
    uint8_t u8Enable = PORT2_IE_R;
    const uintptr_t optrBaseAddress = PORT2_BASE;

    u8Flags &= u8Enable;
    if(0U != (u8Flags & PORT_IFG_R_PIN0_MASK))
    {
        PORT2_IFG_R &= ~PORT_IFG_R_PIN0_MASK;
        IRQSourceHandlerReg = GPIO__pu16fGetIRQSourceHandler(GPIO_enPORT2, GPIO_enPIN_NUMBER0);
        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) GPIO_enPIN_NUMBER0);
    }
    if(0U != (u8Flags & PORT_IFG_R_PIN1_MASK))
    {
        PORT2_IFG_R &= ~PORT_IFG_R_PIN1_MASK;
        IRQSourceHandlerReg = GPIO__pu16fGetIRQSourceHandler(GPIO_enPORT2, GPIO_enPIN_NUMBER1);
        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) GPIO_enPIN_NUMBER1);
    }
    if(0U != (u8Flags & PORT_IFG_R_PIN2_MASK))
    {
        PORT2_IFG_R &= ~PORT_IFG_R_PIN2_MASK;
        IRQSourceHandlerReg = GPIO__pu16fGetIRQSourceHandler(GPIO_enPORT2, GPIO_enPIN_NUMBER2);
        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) GPIO_enPIN_NUMBER2);
    }
    if(0U != (u8Flags & PORT_IFG_R_PIN3_MASK))
    {
        PORT2_IFG_R &= ~PORT_IFG_R_PIN3_MASK;
        IRQSourceHandlerReg = GPIO__pu16fGetIRQSourceHandler(GPIO_enPORT2, GPIO_enPIN_NUMBER3);
        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) GPIO_enPIN_NUMBER3);
    }
    if(0U != (u8Flags & PORT_IFG_R_PIN4_MASK))
    {
        PORT2_IFG_R &= ~PORT_IFG_R_PIN4_MASK;
        IRQSourceHandlerReg = GPIO__pu16fGetIRQSourceHandler(GPIO_enPORT2, GPIO_enPIN_NUMBER4);
        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) GPIO_enPIN_NUMBER4);
    }
    if(0U != (u8Flags & PORT_IFG_R_PIN5_MASK))
    {
        PORT2_IFG_R &= ~PORT_IFG_R_PIN5_MASK;
        IRQSourceHandlerReg = GPIO__pu16fGetIRQSourceHandler(GPIO_enPORT2, GPIO_enPIN_NUMBER5);
        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) GPIO_enPIN_NUMBER5);
    }
    if(0U != (u8Flags & PORT_IFG_R_PIN6_MASK))
    {
        PORT2_IFG_R &= ~PORT_IFG_R_PIN6_MASK;
        IRQSourceHandlerReg = GPIO__pu16fGetIRQSourceHandler(GPIO_enPORT2, GPIO_enPIN_NUMBER6);
        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) GPIO_enPIN_NUMBER6);
    }
    if(0U != (u8Flags & PORT_IFG_R_PIN7_MASK))
    {
        PORT2_IFG_R &= ~PORT_IFG_R_PIN7_MASK;
        IRQSourceHandlerReg = GPIO__pu16fGetIRQSourceHandler(GPIO_enPORT2, GPIO_enPIN_NUMBER7);
        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) GPIO_enPIN_NUMBER7);
    }
    if(0xFFU != u16Status)
    {
        __low_power_mode_off_on_exit();
        __bis_SR_register_on_exit(u16Status);
        _NOP();
    }
}


