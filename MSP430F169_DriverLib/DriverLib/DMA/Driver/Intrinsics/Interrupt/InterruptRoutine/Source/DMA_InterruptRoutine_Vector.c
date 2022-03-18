/**
 *
 * @file DMA_InterruptRoutine_Vector.c
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
#include "DriverLib/DMA/Driver/Intrinsics/Interrupt/InterruptRoutine/Header/DMA_InterruptRoutine_Vector.h"
#include "DriverLib/DMA/Driver/Intrinsics/Interrupt/InterruptRoutine/Header/DMA_InterruptRoutine_Source.h"

#include "DriverLib/DMA/Driver/Intrinsics/Primitives/DMA_Primitives.h"
#include "DriverLib/DMA/Peripheral/DMA_Peripheral.h"
#include <msp430.h>

#pragma vector = PORT1_VECTOR
__interrupt void PORT1_IRQVectorHandler(void)
{
    MCU__pu16fIRQSourceHandler_t IRQSourceHandlerReg = (MCU__pu16fIRQSourceHandler_t) 0UL;
    uint16_t u16Status = LPM4_bits;
    uint8_t u8Flags = PORT1_IFG_R;
    uint8_t u8Enable = PORT1_IE_R;
    const uintptr_t optrBaseAddress = PORT1_BASE;

    u8Flags &= u8Enable;
    if(0U != (u8Flags & PORT_IFG_R_PIN0_MASK))
    {
        PORT1_IFG_R &= ~PORT_IFG_R_PIN0_MASK;
        IRQSourceHandlerReg = DMA__pu16fGetIRQSourceHandler(DMA_enPORT1, DMA_enPIN_NUMBER0);

        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) DMA_enPIN_NUMBER0);
    }
    if(0U != (u8Flags & PORT_IFG_R_PIN1_MASK))
    {
        PORT1_IFG_R &= ~PORT_IFG_R_PIN1_MASK;
        IRQSourceHandlerReg = DMA__pu16fGetIRQSourceHandler(DMA_enPORT1, DMA_enPIN_NUMBER1);
        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) DMA_enPIN_NUMBER1);
    }
    if(0U != (u8Flags & PORT_IFG_R_PIN2_MASK))
    {
        PORT1_IFG_R &= ~PORT_IFG_R_PIN2_MASK;
        IRQSourceHandlerReg = DMA__pu16fGetIRQSourceHandler(DMA_enPORT1, DMA_enPIN_NUMBER2);
        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) DMA_enPIN_NUMBER2);
    }
    if(0U != (u8Flags & PORT_IFG_R_PIN3_MASK))
    {
        PORT1_IFG_R &= ~PORT_IFG_R_PIN3_MASK;
        IRQSourceHandlerReg = DMA__pu16fGetIRQSourceHandler(DMA_enPORT1, DMA_enPIN_NUMBER3);
        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) DMA_enPIN_NUMBER3);
    }
    if(0U != (u8Flags & PORT_IFG_R_PIN4_MASK))
    {
        PORT1_IFG_R &= ~PORT_IFG_R_PIN4_MASK;
        IRQSourceHandlerReg = DMA__pu16fGetIRQSourceHandler(DMA_enPORT1, DMA_enPIN_NUMBER4);
        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) DMA_enPIN_NUMBER4);
    }
    if(0U != (u8Flags & PORT_IFG_R_PIN5_MASK))
    {
        PORT1_IFG_R &= ~PORT_IFG_R_PIN5_MASK;
        IRQSourceHandlerReg = DMA__pu16fGetIRQSourceHandler(DMA_enPORT1, DMA_enPIN_NUMBER5);
        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) DMA_enPIN_NUMBER5);
    }
    if(0U != (u8Flags & PORT_IFG_R_PIN6_MASK))
    {
        PORT1_IFG_R &= ~PORT_IFG_R_PIN6_MASK;
        IRQSourceHandlerReg = DMA__pu16fGetIRQSourceHandler(DMA_enPORT1, DMA_enPIN_NUMBER6);
        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) DMA_enPIN_NUMBER6);
    }
    if(0U != (u8Flags & PORT_IFG_R_PIN7_MASK))
    {
        PORT1_IFG_R &= ~PORT_IFG_R_PIN7_MASK;
        IRQSourceHandlerReg = DMA__pu16fGetIRQSourceHandler(DMA_enPORT1, DMA_enPIN_NUMBER7);
        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) DMA_enPIN_NUMBER7);
    }
    __low_power_mode_off_on_exit();
    __bis_SR_register_on_exit(u16Status);
    _NOP();
}


#pragma vector = PORT2_VECTOR
__interrupt void PORT2_IRQVectorHandler(void)
{
    MCU__pu16fIRQSourceHandler_t IRQSourceHandlerReg = (MCU__pu16fIRQSourceHandler_t) 0UL;
    uint16_t u16Status = LPM4_bits;
    uint8_t u8Flags = PORT2_IFG_R;
    uint8_t u8Enable = PORT2_IE_R;
    const uintptr_t optrBaseAddress = PORT2_BASE;

    u8Flags &= u8Enable;
    if(0U != (u8Flags & PORT_IFG_R_PIN0_MASK))
    {
        PORT2_IFG_R &= ~PORT_IFG_R_PIN0_MASK;
        IRQSourceHandlerReg = DMA__pu16fGetIRQSourceHandler(DMA_enPORT2, DMA_enPIN_NUMBER0);
        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) DMA_enPIN_NUMBER0);
    }
    if(0U != (u8Flags & PORT_IFG_R_PIN1_MASK))
    {
        PORT2_IFG_R &= ~PORT_IFG_R_PIN1_MASK;
        IRQSourceHandlerReg = DMA__pu16fGetIRQSourceHandler(DMA_enPORT2, DMA_enPIN_NUMBER1);
        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) DMA_enPIN_NUMBER1);
    }
    if(0U != (u8Flags & PORT_IFG_R_PIN2_MASK))
    {
        PORT2_IFG_R &= ~PORT_IFG_R_PIN2_MASK;
        IRQSourceHandlerReg = DMA__pu16fGetIRQSourceHandler(DMA_enPORT2, DMA_enPIN_NUMBER2);
        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) DMA_enPIN_NUMBER2);
    }
    if(0U != (u8Flags & PORT_IFG_R_PIN3_MASK))
    {
        PORT2_IFG_R &= ~PORT_IFG_R_PIN3_MASK;
        IRQSourceHandlerReg = DMA__pu16fGetIRQSourceHandler(DMA_enPORT2, DMA_enPIN_NUMBER3);
        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) DMA_enPIN_NUMBER3);
    }
    if(0U != (u8Flags & PORT_IFG_R_PIN4_MASK))
    {
        PORT2_IFG_R &= ~PORT_IFG_R_PIN4_MASK;
        IRQSourceHandlerReg = DMA__pu16fGetIRQSourceHandler(DMA_enPORT2, DMA_enPIN_NUMBER4);
        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) DMA_enPIN_NUMBER4);
    }
    if(0U != (u8Flags & PORT_IFG_R_PIN5_MASK))
    {
        PORT2_IFG_R &= ~PORT_IFG_R_PIN5_MASK;
        IRQSourceHandlerReg = DMA__pu16fGetIRQSourceHandler(DMA_enPORT2, DMA_enPIN_NUMBER5);
        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) DMA_enPIN_NUMBER5);
    }
    if(0U != (u8Flags & PORT_IFG_R_PIN6_MASK))
    {
        PORT2_IFG_R &= ~PORT_IFG_R_PIN6_MASK;
        IRQSourceHandlerReg = DMA__pu16fGetIRQSourceHandler(DMA_enPORT2, DMA_enPIN_NUMBER6);
        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) DMA_enPIN_NUMBER6);
    }
    if(0U != (u8Flags & PORT_IFG_R_PIN7_MASK))
    {
        PORT2_IFG_R &= ~PORT_IFG_R_PIN7_MASK;
        IRQSourceHandlerReg = DMA__pu16fGetIRQSourceHandler(DMA_enPORT2, DMA_enPIN_NUMBER7);
        u16Status &= IRQSourceHandlerReg(optrBaseAddress, (uint8_t) DMA_enPIN_NUMBER7);
    }
    __low_power_mode_off_on_exit();
    __bis_SR_register_on_exit(u16Status);
    _NOP();
}


