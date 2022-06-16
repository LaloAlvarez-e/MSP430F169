/**
 *
 * @file WDT_Clock.c
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
 * @verbatim 26 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 26 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/WDT/Driver/Header/WDT_Clock.h"

#include "DriverLib/WDT/Driver/Intrinsics/Primitives/WDT_Primitives.h"
#include "DriverLib/WDT/Peripheral/WDT_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

void WDT__vSetClock(WDT_nCLOCK enClockArg)
{
    WDT_Register16Bits_t pstRegisterData;
    uint16_t u16Value;
    u16Value = (uint16_t) enClockArg;
    u16Value <<= WDT_CTL_R_SSEL_BIT;
    u16Value |= WDT_CTL_R_PW_WRITE;
    pstRegisterData.uptrAddress = WDT_CTL_OFFSET;
    pstRegisterData.u16Value = u16Value;
    pstRegisterData.u16Mask = WDT_CTL_R_PW_MASK | WDT_CTL_R_SSEL_MASK;
    pstRegisterData.u8Shift = 0UL;

    WDT__vWriteRegister_16bits(&pstRegisterData);
}

WDT_nCLOCK WDT__enGetClock(void)
{
    WDT_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = WDT_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) WDT_enCLOCK_SMCLK;
    pstRegisterData.u16Mask = WDT_CTL_SSEL_MASK;
    pstRegisterData.u8Shift = WDT_CTL_R_SSEL_BIT;
    (void) WDT__u16ReadRegister(&pstRegisterData);

    return ((WDT_nCLOCK) pstRegisterData.u16Value);
}




