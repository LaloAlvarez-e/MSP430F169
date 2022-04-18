/**
 *
 * @file TIMERB_InterruptRoutine_Vector.c
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
#include "DriverLib/TIMERB/Driver/Intrinsics/Interrupt/InterruptRoutine/Header/TIMERB_InterruptRoutine_Vector.h"
#include "DriverLib/TIMERB/Driver/Intrinsics/Interrupt/InterruptRoutine/Header/TIMERB_InterruptRoutine_Source.h"

#include "DriverLib/TIMERB/Driver/Intrinsics/Primitives/TIMERB_Primitives.h"
#include "DriverLib/TIMERB/Peripheral/TIMERB_Peripheral.h"
#include <msp430.h>

__interrupt void TIMERB_CC0_IRQVectorHandler(void)
{
    MCU__pu16fIRQSourceHandler_t IRQSourceHandlerReg = (MCU__pu16fIRQSourceHandler_t) 0UL;
    uint16_t u16Status = 0xFFU;
    uint16_t u16Mode = TIMERB_CC0_CTL_R;
    uint16_t u16PinValue = 0U;
    u16PinValue = u16Mode;
    u16PinValue &= TIMERB_CC_CTL_R_CCI_MASK;
    u16Mode &= TIMERB_CC_CTL_R_CAP_MASK;


    if(TIMERB_CC_CTL_R_CAP_COMPARE == u16Mode)
    {
        IRQSourceHandlerReg = TIMERB_CC__pu16fGetIRQSourceHandler(TIMERB_enCC0, TIMERB_enCC_MODE_COMPARE);

        u16Status &= IRQSourceHandlerReg(TIMERB_CC0_BASE, u16PinValue | (uint8_t) TIMERB_enCC_MODE_COMPARE);
    }
    else
    {
        IRQSourceHandlerReg = TIMERB_CC__pu16fGetIRQSourceHandler(TIMERB_enCC0, TIMERB_enCC_MODE_CAPTURE);

        u16Status &= IRQSourceHandlerReg(TIMERB_CC0_BASE, u16PinValue | (uint8_t) TIMERB_enCC_MODE_CAPTURE);
    }
    if(0xFFU != u16Status)
    {
        __low_power_mode_off_on_exit();
        __bis_SR_register_on_exit(u16Status);
        _NOP();
    }
}



__interrupt void TIMERB_IRQVectorHandler(void)
{
    MCU__pu16fIRQSourceHandler_t IRQSourceHandlerReg = (MCU__pu16fIRQSourceHandler_t) 0UL;
    uint16_t u16Status = 0xFFU;
    uint16_t u16Mode = 0U;
    uint16_t u16PinValue = 0U;

    switch(TIMERB_IV_R)
    {
    case TIMERB_IV_R_IV_CC1:
        u16Mode = TIMERB_CC1_CTL_R;
        u16PinValue = u16Mode;
        u16PinValue &= TIMERB_CC_CTL_R_CCI_MASK;
        u16Mode &= TIMERB_CC_CTL_R_CAP_MASK;
        if(TIMERB_CC_CTL_R_CAP_COMPARE == u16Mode)
        {
            IRQSourceHandlerReg = TIMERB_CC__pu16fGetIRQSourceHandler(
                    TIMERB_enCC1, TIMERB_enCC_MODE_COMPARE);

            u16Status &= IRQSourceHandlerReg(TIMERB_CC1_BASE,  u16PinValue | (uint8_t) TIMERB_enCC_MODE_COMPARE);
        }
        else
        {
            IRQSourceHandlerReg = TIMERB_CC__pu16fGetIRQSourceHandler(
                    TIMERB_enCC1, TIMERB_enCC_MODE_CAPTURE);

            u16Status &= IRQSourceHandlerReg(TIMERB_CC1_BASE, u16PinValue | (uint8_t) TIMERB_enCC_MODE_CAPTURE);
        }
        break;
    case TIMERB_IV_R_IV_CC2:
        u16Mode = TIMERB_CC2_CTL_R;
        u16PinValue = u16Mode;
        u16PinValue &= TIMERB_CC_CTL_R_CCI_MASK;
        u16Mode &= TIMERB_CC_CTL_R_CAP_MASK;
        if(TIMERB_CC_CTL_R_CAP_COMPARE == u16Mode)
        {
            IRQSourceHandlerReg = TIMERB_CC__pu16fGetIRQSourceHandler(TIMERB_enCC2, TIMERB_enCC_MODE_COMPARE);

            u16Status &= IRQSourceHandlerReg(TIMERB_CC2_BASE, u16PinValue | (uint8_t) TIMERB_enCC_MODE_COMPARE);
        }
        else
        {
            IRQSourceHandlerReg = TIMERB_CC__pu16fGetIRQSourceHandler(TIMERB_enCC2, TIMERB_enCC_MODE_CAPTURE);

            u16Status &= IRQSourceHandlerReg(TIMERB_CC2_BASE, u16PinValue | (uint8_t) TIMERB_enCC_MODE_CAPTURE);
        }
        break;
    case TIMERB_IV_R_IV_CC3:
        u16Mode = TIMERB_CC3_CTL_R;
        u16PinValue = u16Mode;
        u16PinValue &= TIMERB_CC_CTL_R_CCI_MASK;
        u16Mode &= TIMERB_CC_CTL_R_CAP_MASK;
        if(TIMERB_CC_CTL_R_CAP_COMPARE == u16Mode)
        {
            IRQSourceHandlerReg = TIMERB_CC__pu16fGetIRQSourceHandler(
                    TIMERB_enCC3, TIMERB_enCC_MODE_COMPARE);

            u16Status &= IRQSourceHandlerReg(TIMERB_CC3_BASE,  u16PinValue | (uint8_t) TIMERB_enCC_MODE_COMPARE);
        }
        else
        {
            IRQSourceHandlerReg = TIMERB_CC__pu16fGetIRQSourceHandler(
                    TIMERB_enCC3, TIMERB_enCC_MODE_CAPTURE);

            u16Status &= IRQSourceHandlerReg(TIMERB_CC3_BASE, u16PinValue | (uint8_t) TIMERB_enCC_MODE_CAPTURE);
        }
        break;
    case TIMERB_IV_R_IV_CC4:
        u16Mode = TIMERB_CC4_CTL_R;
        u16PinValue = u16Mode;
        u16PinValue &= TIMERB_CC_CTL_R_CCI_MASK;
        u16Mode &= TIMERB_CC_CTL_R_CAP_MASK;
        if(TIMERB_CC_CTL_R_CAP_COMPARE == u16Mode)
        {
            IRQSourceHandlerReg = TIMERB_CC__pu16fGetIRQSourceHandler(
                    TIMERB_enCC4, TIMERB_enCC_MODE_COMPARE);

            u16Status &= IRQSourceHandlerReg(TIMERB_CC4_BASE,  u16PinValue | (uint8_t) TIMERB_enCC_MODE_COMPARE);
        }
        else
        {
            IRQSourceHandlerReg = TIMERB_CC__pu16fGetIRQSourceHandler(
                    TIMERB_enCC4, TIMERB_enCC_MODE_CAPTURE);

            u16Status &= IRQSourceHandlerReg(TIMERB_CC4_BASE, u16PinValue | (uint8_t) TIMERB_enCC_MODE_CAPTURE);
        }
        break;
    case TIMERB_IV_R_IV_CC5:
        u16Mode = TIMERB_CC5_CTL_R;
        u16PinValue = u16Mode;
        u16PinValue &= TIMERB_CC_CTL_R_CCI_MASK;
        u16Mode &= TIMERB_CC_CTL_R_CAP_MASK;
        if(TIMERB_CC_CTL_R_CAP_COMPARE == u16Mode)
        {
            IRQSourceHandlerReg = TIMERB_CC__pu16fGetIRQSourceHandler(
                    TIMERB_enCC5, TIMERB_enCC_MODE_COMPARE);

            u16Status &= IRQSourceHandlerReg(TIMERB_CC5_BASE,  u16PinValue | (uint8_t) TIMERB_enCC_MODE_COMPARE);
        }
        else
        {
            IRQSourceHandlerReg = TIMERB_CC__pu16fGetIRQSourceHandler(
                    TIMERB_enCC5, TIMERB_enCC_MODE_CAPTURE);

            u16Status &= IRQSourceHandlerReg(TIMERB_CC5_BASE, u16PinValue | (uint8_t) TIMERB_enCC_MODE_CAPTURE);
        }
        break;
    case TIMERB_IV_R_IV_CC6:
        u16Mode = TIMERB_CC6_CTL_R;
        u16PinValue = u16Mode;
        u16PinValue &= TIMERB_CC_CTL_R_CCI_MASK;
        u16Mode &= TIMERB_CC_CTL_R_CAP_MASK;
        if(TIMERB_CC_CTL_R_CAP_COMPARE == u16Mode)
        {
            IRQSourceHandlerReg = TIMERB_CC__pu16fGetIRQSourceHandler(
                    TIMERB_enCC6, TIMERB_enCC_MODE_COMPARE);

            u16Status &= IRQSourceHandlerReg(TIMERB_CC6_BASE,  u16PinValue | (uint8_t) TIMERB_enCC_MODE_COMPARE);
        }
        else
        {
            IRQSourceHandlerReg = TIMERB_CC__pu16fGetIRQSourceHandler(
                    TIMERB_enCC6, TIMERB_enCC_MODE_CAPTURE);

            u16Status &= IRQSourceHandlerReg(TIMERB_CC6_BASE, u16PinValue | (uint8_t) TIMERB_enCC_MODE_CAPTURE);
        }
        break;
    default:
        IRQSourceHandlerReg = TIMERB__pu16fGetIRQSourceHandler();

        u16Status &= IRQSourceHandlerReg(TIMERB_BASE, 0U);
        break;
    }
    if(0xFFU != u16Status)
    {
        __low_power_mode_off_on_exit();
        __bis_SR_register_on_exit(u16Status);
        _NOP();
    }
}


