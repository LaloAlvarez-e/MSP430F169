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

__interrupt void DACDMA_IRQVectorHandler(void)
{
    MCU__pu16fIRQSourceHandler_t IRQSourceHandlerReg = (MCU__pu16fIRQSourceHandler_t) 0UL;
    uint16_t u16Status = LPM4_bits;
    uint16_t u16ControlDMA_CH0 = DMA_CH0_CTL_R;
    uint16_t u16ControlDMA_CH1 = DMA_CH1_CTL_R;
    uint16_t u16ControlDMA_CH2 = DMA_CH2_CTL_R;
    uint16_t u16Trigger = 0U;
    uint16_t u16Flag = 0U;
    uint16_t u16Enable = 0U;

    u16Flag = u16ControlDMA_CH0 & DMA_CH_CTL_R_IFG_MASK;
    u16Enable = u16ControlDMA_CH0 & DMA_CH_CTL_R_IE_MASK;
    u16Enable |= u16Flag;
    if((DMA_CH_CTL_R_IFG_MASK | DMA_CH_CTL_R_IE_MASK) == u16Enable)
    {
        DMA_CH0_CTL_R &= ~DMA_CH_CTL_R_IFG_MASK;
        u16Trigger = DMA_CTL0_R;
        u16Trigger >>= DMA_CTL0_R_CH0TSEL_BIT;
        u16Trigger &= DMA_CTL0_CHTSEL_MASK;
        IRQSourceHandlerReg = DMA__pu16fGetIRQSourceHandler(DMA_enCH0, (DMA_nCH_TRIGGER) u16Trigger);

        u16Status &= IRQSourceHandlerReg(DMA_CH0_BASE, (uint8_t) u16Trigger);
    }
    u16Flag = u16ControlDMA_CH1 & DMA_CH_CTL_R_IFG_MASK;
    u16Enable = u16ControlDMA_CH1 & DMA_CH_CTL_R_IE_MASK;
    u16Enable |= u16Flag;
    if((DMA_CH_CTL_R_IFG_MASK | DMA_CH_CTL_R_IE_MASK) == u16Enable)
    {
        DMA_CH1_CTL_R &= ~DMA_CH_CTL_R_IFG_MASK;
        u16Trigger = DMA_CTL0_R;
        u16Trigger >>= DMA_CTL0_R_CH1TSEL_BIT;
        u16Trigger &= DMA_CTL0_CHTSEL_MASK;
        IRQSourceHandlerReg = DMA__pu16fGetIRQSourceHandler(DMA_enCH1, (DMA_nCH_TRIGGER) u16Trigger);

        u16Status &= IRQSourceHandlerReg(DMA_CH1_BASE, (uint8_t) u16Trigger);
    }
    u16Flag = u16ControlDMA_CH2 & DMA_CH_CTL_R_IFG_MASK;
    u16Enable = u16ControlDMA_CH2 & DMA_CH_CTL_R_IE_MASK;
    u16Enable |= u16Flag;
    if((DMA_CH_CTL_R_IFG_MASK | DMA_CH_CTL_R_IE_MASK) == u16Enable)
    {
        DMA_CH2_CTL_R &= ~DMA_CH_CTL_R_IFG_MASK;
        u16Trigger = DMA_CTL0_R;
        u16Trigger >>= DMA_CTL0_R_CH2TSEL_BIT;
        u16Trigger &= DMA_CTL0_CHTSEL_MASK;
        IRQSourceHandlerReg = DMA__pu16fGetIRQSourceHandler(DMA_enCH2, (DMA_nCH_TRIGGER) u16Trigger);

        u16Status &= IRQSourceHandlerReg(DMA_CH2_BASE, (uint8_t) u16Trigger);
    }
    __low_power_mode_off_on_exit();
    __bis_SR_register_on_exit(u16Status);
    _NOP();
}


