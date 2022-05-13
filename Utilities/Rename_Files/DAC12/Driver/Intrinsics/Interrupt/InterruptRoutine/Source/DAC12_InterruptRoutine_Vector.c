/**
 *
 * @file DAC12_InterruptRoutine_Vector.c
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
#include "DriverLib/DAC12/Driver/Intrinsics/Interrupt/InterruptRoutine/Header/DAC12_InterruptRoutine_Vector.h"
#include "DriverLib/DAC12/Driver/Intrinsics/Interrupt/InterruptRoutine/Header/DAC12_InterruptRoutine_Source.h"

#include "DriverLib/DAC12/Driver/Intrinsics/Primitives/DAC12_Primitives.h"
#include "DriverLib/DAC12/Peripheral/DAC12_Peripheral.h"
#include <msp430.h>

__interrupt void DAC12_IRQVectorHandler(void)
{
    MCU__pu16fIRQSourceHandler_t IRQSourceHandlerReg = (MCU__pu16fIRQSourceHandler_t) 0UL;
    uint16_t u16Status = 0xFFU;
    uint16_t u16Conversion = 0U;

    switch(DAC12_IV_R)
    {
    case DAC12_IV_R_IV_OV:
        IRQSourceHandlerReg = DAC12__pu16fGetIRQSourceHandler(DAC12_enINTERRUPT_OV);
        u16Status &= IRQSourceHandlerReg(DAC12_BASE, (uint16_t) DAC12_enINTERRUPT_OV);
        break;
    case DAC12_IV_R_IV_TOV:
        IRQSourceHandlerReg = DAC12__pu16fGetIRQSourceHandler(DAC12_enINTERRUPT_TOV);
        u16Status &= IRQSourceHandlerReg(DAC12_BASE, (uint16_t) DAC12_enINTERRUPT_TOV);
        break;
    case DAC12_IV_R_IV_CH0:
        u16Conversion = DAC12_CH0_MEM_R;
    IRQSourceHandlerReg = DAC12_CH__pu16fGetIRQSourceHandler(DAC12_enCH0);
        u16Status &= IRQSourceHandlerReg(DAC12_CH0_BASE, u16Conversion);
        break;
    case DAC12_IV_R_IV_CH1:
        u16Conversion = DAC12_CH1_MEM_R;
        IRQSourceHandlerReg = DAC12_CH__pu16fGetIRQSourceHandler(DAC12_enCH1);
        u16Status &= IRQSourceHandlerReg(DAC12_CH1_BASE, u16Conversion);
        break;
    case DAC12_IV_R_IV_CH2:
        u16Conversion = DAC12_CH2_MEM_R;
        IRQSourceHandlerReg = DAC12_CH__pu16fGetIRQSourceHandler(DAC12_enCH2);
        u16Status &= IRQSourceHandlerReg(DAC12_CH2_BASE, u16Conversion);
        break;
    case DAC12_IV_R_IV_CH3:
        u16Conversion = DAC12_CH3_MEM_R;
        IRQSourceHandlerReg = DAC12_CH__pu16fGetIRQSourceHandler(DAC12_enCH3);
        u16Status &= IRQSourceHandlerReg(DAC12_CH3_BASE, u16Conversion);
        break;
    case DAC12_IV_R_IV_CH4:
        u16Conversion = DAC12_CH4_MEM_R;
        IRQSourceHandlerReg = DAC12_CH__pu16fGetIRQSourceHandler(DAC12_enCH4);
        u16Status &= IRQSourceHandlerReg(DAC12_CH4_BASE, u16Conversion);
        break;
    case DAC12_IV_R_IV_CH5:
        u16Conversion = DAC12_CH5_MEM_R;
        IRQSourceHandlerReg = DAC12_CH__pu16fGetIRQSourceHandler(DAC12_enCH5);
        u16Status &= IRQSourceHandlerReg(DAC12_CH5_BASE, u16Conversion);
        break;
    case DAC12_IV_R_IV_CH6:
        u16Conversion = DAC12_CH6_MEM_R;
        IRQSourceHandlerReg = DAC12_CH__pu16fGetIRQSourceHandler(DAC12_enCH6);
        u16Status &= IRQSourceHandlerReg(DAC12_CH6_BASE, u16Conversion);
        break;
    case DAC12_IV_R_IV_CH7:
        u16Conversion = DAC12_CH7_MEM_R;
        IRQSourceHandlerReg = DAC12_CH__pu16fGetIRQSourceHandler(DAC12_enCH7);
        u16Status &= IRQSourceHandlerReg(DAC12_CH7_BASE, u16Conversion);
        break;
    case DAC12_IV_R_IV_CH8:
        u16Conversion = DAC12_CH8_MEM_R;
        IRQSourceHandlerReg = DAC12_CH__pu16fGetIRQSourceHandler(DAC12_enCH8);
        u16Status &= IRQSourceHandlerReg(DAC12_CH8_BASE, u16Conversion);
        break;
    case DAC12_IV_R_IV_CH9:
        u16Conversion = DAC12_CH9_MEM_R;
        IRQSourceHandlerReg = DAC12_CH__pu16fGetIRQSourceHandler(DAC12_enCH9);
        u16Status &= IRQSourceHandlerReg(DAC12_CH9_BASE, u16Conversion);
        break;
    case DAC12_IV_R_IV_CH10:
        u16Conversion = DAC12_CH10_MEM_R;
        IRQSourceHandlerReg = DAC12_CH__pu16fGetIRQSourceHandler(DAC12_enCH10);
        u16Status &= IRQSourceHandlerReg(DAC12_CH10_BASE, u16Conversion);
        break;
    case DAC12_IV_R_IV_CH11:
        u16Conversion = DAC12_CH11_MEM_R;
        IRQSourceHandlerReg = DAC12_CH__pu16fGetIRQSourceHandler(DAC12_enCH11);
        u16Status &= IRQSourceHandlerReg(DAC12_CH11_BASE, u16Conversion);
        break;
    case DAC12_IV_R_IV_CH12:
        u16Conversion = DAC12_CH12_MEM_R;
        IRQSourceHandlerReg = DAC12_CH__pu16fGetIRQSourceHandler(DAC12_enCH12);
        u16Status &= IRQSourceHandlerReg(DAC12_CH12_BASE, u16Conversion);
        break;
    case DAC12_IV_R_IV_CH13:
        u16Conversion = DAC12_CH13_MEM_R;
        IRQSourceHandlerReg = DAC12_CH__pu16fGetIRQSourceHandler(DAC12_enCH13);
        u16Status &= IRQSourceHandlerReg(DAC12_CH13_BASE, u16Conversion);
        break;
    case DAC12_IV_R_IV_CH14:
        u16Conversion = DAC12_CH14_MEM_R;
        IRQSourceHandlerReg = DAC12_CH__pu16fGetIRQSourceHandler(DAC12_enCH14);
        u16Status &= IRQSourceHandlerReg(DAC12_CH14_BASE, u16Conversion);
        break;
    default:
        u16Conversion = DAC12_CH15_MEM_R;
        IRQSourceHandlerReg = DAC12_CH__pu16fGetIRQSourceHandler(DAC12_enCH15);
        u16Status &= IRQSourceHandlerReg(DAC12_CH15_BASE, u16Conversion);
        break;
    }
    if(0xFFU != u16Status)
    {
        __low_power_mode_off_on_exit();
        __bis_SR_register_on_exit(u16Status);
        _NOP();
    }
}


