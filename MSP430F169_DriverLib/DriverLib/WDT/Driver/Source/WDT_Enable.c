/**
 *
 * @file WDT_Enable.c
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
#include "DriverLib/WDT/Driver/Header/WDT_Enable.h"

#include "DriverLib/WDT/Driver/Intrinsics/Primitives/WDT_Primitives.h"
#include "DriverLib/WDT/Peripheral/WDT_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

void WDT__vSetEnable(WDT_nENABLE enEnableArg)
{
    WDT_Register16Bits_t pstRegisterData = {0UL};
    uint16_t u16Value = 0U;
    u16Value = (uint16_t) enEnableArg;
    u16Value <<= WDT_CTL_R_HOLD_BIT;
    u16Value |= WDT_CTL_R_PW_WRITE;
    pstRegisterData.uptrAddress = WDT_CTL_OFFSET;
    pstRegisterData.u16Value = u16Value;
    pstRegisterData.u16Mask = WDT_CTL_R_PW_MASK | WDT_CTL_R_HOLD_MASK;
    pstRegisterData.u8Shift = 0UL;

    WDT__vWriteRegister_16bits(&pstRegisterData);
}

WDT_nENABLE WDT__enGetEnable(void)
{
    WDT_Register16Bits_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = WDT_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) WDT_enENABLE_RUN;
    pstRegisterData.u16Mask = WDT_CTL_HOLD_MASK;
    pstRegisterData.u8Shift = WDT_CTL_R_HOLD_BIT;
    (void) WDT__u16ReadRegister(&pstRegisterData);

    return ((WDT_nENABLE) pstRegisterData.u16Value);
}


void WDT__vSetEnable_RAM(WDT_nENABLE enEnableArg)
{
    WDT_Register16Bits_t pstRegisterData = {0UL};
    uint16_t u16Value = 0U;
    u16Value = (uint16_t) enEnableArg;
    u16Value <<= WDT_CTL_R_HOLD_BIT;
    u16Value |= WDT_CTL_R_PW_WRITE;
    pstRegisterData.uptrAddress = WDT_CTL_OFFSET;
    pstRegisterData.u16Value = u16Value;
    pstRegisterData.u16Mask = WDT_CTL_R_PW_MASK | WDT_CTL_R_HOLD_MASK;
    pstRegisterData.u8Shift = 0UL;

    WDT__vWriteRegister_16bits_RAM(&pstRegisterData);
}

WDT_nENABLE WDT__enGetEnable_RAM(void)
{
    WDT_Register16Bits_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = WDT_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) WDT_enENABLE_RUN;
    pstRegisterData.u16Mask = WDT_CTL_HOLD_MASK;
    pstRegisterData.u8Shift = WDT_CTL_R_HOLD_BIT;
    (void) WDT__u16ReadRegister_RAM(&pstRegisterData);

    return ((WDT_nENABLE) pstRegisterData.u16Value);
}

