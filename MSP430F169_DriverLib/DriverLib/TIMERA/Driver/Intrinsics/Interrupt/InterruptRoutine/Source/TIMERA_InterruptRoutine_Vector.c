/**
 *
 * @file TIMERA_InterruptRoutine_Vector.c
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
#include "DriverLib/TIMERA/Driver/Intrinsics/Interrupt/InterruptRoutine/Header/TIMERA_InterruptRoutine_Vector.h"
#include "DriverLib/TIMERA/Driver/Intrinsics/Interrupt/InterruptRoutine/Header/TIMERA_InterruptRoutine_Source.h"

#include "DriverLib/TIMERA/Driver/Intrinsics/Primitives/TIMERA_Primitives.h"
#include "DriverLib/TIMERA/Peripheral/TIMERA_Peripheral.h"
#include <msp430.h>

__interrupt void TIMERA_CC0_IRQVectorHandler(void)
{
    MCU__pu16fIRQSourceHandler_t IRQSourceHandlerReg = (MCU__pu16fIRQSourceHandler_t) 0UL;
    uint16_t u16Status = LPM4_bits;
    uint16_t u16Mode = TIMERA_CC0_CTL_R;
    uint16_t u16PinValue = 0U;
    u16PinValue = u16Mode;
    u16PinValue &= TIMERA_CC_CTL_R_CCI_MASK;
    u16Mode &= TIMERA_CC_CTL_R_CAP_MASK;


    if(TIMERA_CC_CTL_R_CAP_COMPARE == u16Mode)
    {
        IRQSourceHandlerReg = TIMERA_CC__pu16fGetIRQSourceHandler(TIMERA_enCC0, TIMERA_enCC_MODE_COMPARE);

        u16Status &= IRQSourceHandlerReg(TIMERA_CC0_BASE, u16PinValue | (uint8_t) TIMERA_enCC_MODE_COMPARE);
    }
    else
    {
        IRQSourceHandlerReg = TIMERA_CC__pu16fGetIRQSourceHandler(TIMERA_enCC0, TIMERA_enCC_MODE_CAPTURE);

        u16Status &= IRQSourceHandlerReg(TIMERA_CC0_BASE, u16PinValue | (uint8_t) TIMERA_enCC_MODE_CAPTURE);
    }
    __low_power_mode_off_on_exit();
    __bis_SR_register_on_exit(u16Status);
    _NOP();
}



__interrupt void TIMERA_IRQVectorHandler(void)
{
    MCU__pu16fIRQSourceHandler_t IRQSourceHandlerReg = (MCU__pu16fIRQSourceHandler_t) 0UL;
    uint16_t u16Status = LPM4_bits;
    uint16_t u16Mode = 0U;
    uint16_t u16PinValue = 0U;

    switch(TIMERA_IV_R)
    {
    case TIMERA_IV_R_IV_CC1:
        u16Mode = TIMERA_CC1_CTL_R;
        u16PinValue = u16Mode;
        u16PinValue &= TIMERA_CC_CTL_R_CCI_MASK;
        u16Mode &= TIMERA_CC_CTL_R_CAP_MASK;
        if(TIMERA_CC_CTL_R_CAP_COMPARE == u16Mode)
        {
            IRQSourceHandlerReg = TIMERA_CC__pu16fGetIRQSourceHandler(
                    TIMERA_enCC1, TIMERA_enCC_MODE_COMPARE);

            u16Status &= IRQSourceHandlerReg(TIMERA_CC1_BASE,  u16PinValue | (uint8_t) TIMERA_enCC_MODE_COMPARE);
        }
        else
        {
            IRQSourceHandlerReg = TIMERA_CC__pu16fGetIRQSourceHandler(
                    TIMERA_enCC1, TIMERA_enCC_MODE_CAPTURE);

            u16Status &= IRQSourceHandlerReg(TIMERA_CC1_BASE, u16PinValue | (uint8_t) TIMERA_enCC_MODE_CAPTURE);
        }
        break;
    case TIMERA_IV_R_IV_CC2:
        u16Mode = TIMERA_CC2_CTL_R;
        u16PinValue = u16Mode;
        u16PinValue &= TIMERA_CC_CTL_R_CCI_MASK;
        u16Mode &= TIMERA_CC_CTL_R_CAP_MASK;
        if(TIMERA_CC_CTL_R_CAP_COMPARE == u16Mode)
        {
            IRQSourceHandlerReg = TIMERA_CC__pu16fGetIRQSourceHandler(TIMERA_enCC2, TIMERA_enCC_MODE_COMPARE);

            u16Status &= IRQSourceHandlerReg(TIMERA_CC2_BASE, u16PinValue | (uint8_t) TIMERA_enCC_MODE_COMPARE);
        }
        else
        {
            IRQSourceHandlerReg = TIMERA_CC__pu16fGetIRQSourceHandler(TIMERA_enCC2, TIMERA_enCC_MODE_CAPTURE);

            u16Status &= IRQSourceHandlerReg(TIMERA_CC2_BASE, u16PinValue | (uint8_t) TIMERA_enCC_MODE_CAPTURE);
        }
        break;
    default:
        IRQSourceHandlerReg = TIMERA__pu16fGetIRQSourceHandler();

        u16Status &= IRQSourceHandlerReg(TIMERA_BASE, 0U);
        break;
    }
    __low_power_mode_off_on_exit();
    __bis_SR_register_on_exit(u16Status);
    _NOP();
}


