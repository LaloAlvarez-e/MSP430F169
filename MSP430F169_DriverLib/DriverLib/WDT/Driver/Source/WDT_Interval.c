/**
 *
 * @file WDT_Interval.c
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
#include "DriverLib/WDT/Driver/Header/WDT_Interval.h"

#include "DriverLib/WDT/Driver/Intrinsics/Primitives/WDT_Primitives.h"
#include "DriverLib/WDT/Peripheral/WDT_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

void WDT__vSetInterval(WDT_nINTERVAL enIntervalArg)
{
    WDT_Register16Bits_t pstRegisterData;
    uint16_t u16Value = 0U;
    u16Value = (uint16_t) enIntervalArg;
    u16Value <<= WDT_CTL_R_IS_BIT;
    u16Value |= WDT_CTL_R_PW_WRITE;
    u16Value |= WDT_CTL_R_CNTCL_CLEAR;
    pstRegisterData.uptrAddress = WDT_CTL_OFFSET;
    pstRegisterData.u16Value = u16Value;
    pstRegisterData.u16Mask = WDT_CTL_R_PW_MASK | WDT_CTL_R_CNTCL_CLEAR | WDT_CTL_R_IS_MASK;
    pstRegisterData.u8Shift = 0UL;

    WDT__vWriteRegister_16bits(&pstRegisterData);
}

WDT_nINTERVAL WDT__enGetInterval(void)
{
    WDT_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = WDT_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) WDT_enINTERVAL_32768;
    pstRegisterData.u16Mask = WDT_CTL_IS_MASK;
    pstRegisterData.u8Shift = WDT_CTL_R_IS_BIT;
    (void) WDT__u16ReadRegister(&pstRegisterData);

    return ((WDT_nINTERVAL) pstRegisterData.u16Value);
}

uint16_t WDT__u16GetInterval(void)
{
    const uint16_t pu16LUTInterval[4UL] = {32768U, 8192U, 512U, 64U};
    WDT_nINTERVAL enIntervalReg = WDT_enINTERVAL_32768;
    uint16_t u16Reg = 0U;
    uint16_t u16Index = 0U;
    enIntervalReg = WDT__enGetInterval();
    u16Index = (uint8_t) enIntervalReg;
    u16Reg = pu16LUTInterval[u16Index];
    return (u16Reg);
}



