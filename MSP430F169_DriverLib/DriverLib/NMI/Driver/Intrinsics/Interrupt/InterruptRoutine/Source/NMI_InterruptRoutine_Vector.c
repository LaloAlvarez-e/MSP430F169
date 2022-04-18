/**
 *
 * @file NMI_InterruptRoutine_Vector.c
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
 * @verbatim 25 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 25 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/NMI/Driver/Intrinsics/Interrupt/InterruptRoutine/Header/NMI_InterruptRoutine_Vector.h"
#include "DriverLib/NMI/Driver/Intrinsics/Interrupt/InterruptRoutine/Header/NMI_InterruptRoutine_Source.h"

#include "DriverLib/CLOCK/CLOCK.h"
#include "DriverLib/FLASH/FLASH.h"

#include "DriverLib/NMI/Driver/Intrinsics/Primitives/NMI_Primitives.h"
#include "DriverLib/NMI/Peripheral/NMI_Peripheral.h"
#include <msp430.h>

__interrupt void NMI_IRQVectorHandler(void)
{
    MCU__pu16fIRQSourceHandler_t IRQSourceHandlerReg = (MCU__pu16fIRQSourceHandler_t) 0UL;
    uint16_t u16Status = 0xFFU;
    uint8_t u8FlagsNMI = NMI_IFG1_R;
    uint8_t u8EnableNMI = NMI_IE1_R;
    uint8_t u8FlagsCLOCK = CLOCK_IFG1_R;
    uint8_t u8EnableCLOCK = CLOCK_IE1_R;
    uint8_t u8FlagsFLASH = FLASH_CTL3_R;
    uint8_t u8EnableFLASH = FLASH_IE1_R;
    const uintptr_t optrBaseAddressNMI = NMI_BASE;
    const uintptr_t optrBaseAddressCLOCK = CLOCK_BASE;
    const uintptr_t optrBaseAddressFLASH = FLASH_BASE;

    u8FlagsNMI &= u8EnableNMI;
    u8FlagsCLOCK &= u8EnableCLOCK;
    u8FlagsFLASH &= FLASH_CTL3_R_ACCVIFG_MASK;
    u8EnableFLASH &= FLASH_IE1_R_ACCVIE_MASK;
    u8FlagsFLASH |= u8EnableFLASH;
    if(0UL != u8FlagsNMI)
    {
        NMI_IFG1_R &= ~NMI_IFG1_R_IFG_MASK;
        IRQSourceHandlerReg = NMI__pu16fGetIRQSourceHandler();
        u16Status &= IRQSourceHandlerReg(optrBaseAddressNMI, 0U);
    }
    if(0UL != u8FlagsCLOCK)
    {
        CLOCK_IFG1_R &= ~CLOCK_IFG1_R_IFG_MASK;
        IRQSourceHandlerReg = CLOCK__pu16fGetIRQSourceHandler();
        u16Status &= IRQSourceHandlerReg(optrBaseAddressCLOCK, 0U);
    }
    if((FLASH_CTL3_R_ACCVIFG_MASK | FLASH_IE1_R_ACCVIE_MASK)  == u8FlagsFLASH)
    {
        FLASH_CTL3_R &= ~FLASH_CTL3_R_ACCVIFG_MASK;
        IRQSourceHandlerReg = FLASH__pu16fGetIRQSourceHandler();
        u16Status &= IRQSourceHandlerReg(optrBaseAddressFLASH, 0U);
    }
    if(0xFFU != u16Status)
    {
        __low_power_mode_off_on_exit();
        __bis_SR_register_on_exit(u16Status);
        _NOP();
    }
}
