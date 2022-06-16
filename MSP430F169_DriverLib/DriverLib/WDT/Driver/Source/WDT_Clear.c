/**
 *
 * @file WDT_Clear.c
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
#include "DriverLib/WDT/Driver/Header/WDT_Clear.h"

#include "DriverLib/WDT/Driver/Intrinsics/Primitives/WDT_Primitives.h"
#include "DriverLib/WDT/Peripheral/WDT_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

void WDT__vSetClear(void)
{
    WDT_Register16Bits_t pstRegisterData;
    uint16_t u16Value;
    u16Value = 1UL;
    u16Value <<= WDT_CTL_R_CNTCL_BIT;
    u16Value |= WDT_CTL_R_PW_WRITE;
    pstRegisterData.uptrAddress = WDT_CTL_OFFSET;
    pstRegisterData.u16Value = u16Value;
    pstRegisterData.u16Mask = WDT_CTL_R_PW_MASK | WDT_CTL_R_CNTCL_MASK;
    pstRegisterData.u8Shift = 0UL;

    WDT__vWriteRegister_16bits(&pstRegisterData);
}

