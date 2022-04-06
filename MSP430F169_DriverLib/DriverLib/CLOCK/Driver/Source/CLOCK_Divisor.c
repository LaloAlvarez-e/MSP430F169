/**
 *
 * @file CLOCK_Divisor.c
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
 * @verbatim 13 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 13 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/CLOCK/Driver/Header/CLOCK_Divisor.h"

#include "DriverLib/CLOCK/Driver/Intrinsics/Primitives/CLOCK_Primitives.h"
#include "DriverLib/CLOCK/Peripheral/CLOCK_Peripheral.h"

void CLOCK__vSetDivider(CLOCK_nSIGNAL enClockSignal, CLOCK_nDIV enDivider)
{
    switch (enClockSignal)
    {
    case CLOCK_enSIGNAL_ACLK:
        CLOCK__vSetACLKDivider(enDivider);
        break;
    case CLOCK_enSIGNAL_SMCLK:
        CLOCK__vSetSMCLKDivider(enDivider);
        break;
    case CLOCK_enSIGNAL_MCLK:
        CLOCK__vSetMCLKDivider(enDivider);
        break;
    default:
        break;
    }
}

void CLOCK__vSetACLKDivider(CLOCK_nDIV enDivider)
{
    CLOCK_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = CLOCK_BCSCTL1_OFFSET;
    pstRegisterData.u8Value = (uint8_t) enDivider;
    pstRegisterData.u8Mask = CLOCK_BCSCTL1_DIVA_MASK;
    pstRegisterData.u8Shift = CLOCK_BCSCTL1_R_DIVA_BIT;
    CLOCK__vWriteRegister(&pstRegisterData);
}

void CLOCK__vSetMCLKDivider(CLOCK_nDIV enDivider)
{
    CLOCK_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = CLOCK_BCSCTL2_OFFSET;
    pstRegisterData.u8Value = (uint8_t) enDivider;
    pstRegisterData.u8Mask = CLOCK_BCSCTL2_DIVM_MASK;
    pstRegisterData.u8Shift = CLOCK_BCSCTL2_R_DIVM_BIT;
    CLOCK__vWriteRegister(&pstRegisterData);
}

void CLOCK__vSetSMCLKDivider(CLOCK_nDIV enDivider)
{
    CLOCK_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = CLOCK_BCSCTL2_OFFSET;
    pstRegisterData.u8Value = (uint8_t) enDivider;
    pstRegisterData.u8Mask = CLOCK_BCSCTL2_DIVS_MASK;
    pstRegisterData.u8Shift = CLOCK_BCSCTL2_R_DIVS_BIT;
    CLOCK__vWriteRegister(&pstRegisterData);
}

void CLOCK__vSetDividerByNumber(CLOCK_nSIGNAL enClockSignal, uint8_t u8Divider)
{
    uint8_t u8Value = 0U;
    uint8_t u8Count = 0U;
    u8Divider &= 0xFU;
    if(0U != u8Divider)
    {
        do
        {
            if(0U != (1U & u8Divider))
            {
                u8Value = u8Count;
            }
            u8Divider >>= 1U;
            u8Count++;
        }while(0U != u8Divider);

        CLOCK__vSetDivider(enClockSignal, (CLOCK_nDIV) u8Value);
    }
}


void CLOCK__vSetACLKDividerByNumber(uint8_t u8Divider)
{
    CLOCK__vSetDividerByNumber(CLOCK_enSIGNAL_ACLK, u8Divider);
}

void CLOCK__vSetSMCLKDividerByNumber(uint8_t u8Divider)
{
    CLOCK__vSetDividerByNumber(CLOCK_enSIGNAL_SMCLK, u8Divider);
}

void CLOCK__vSetMCLKDividerByNumber(uint8_t u8Divider)
{
    CLOCK__vSetDividerByNumber(CLOCK_enSIGNAL_MCLK, u8Divider);
}

CLOCK_nDIV CLOCK__enGetDivider(CLOCK_nSIGNAL enClockSignal)
{
    CLOCK_nDIV enDividerReg = CLOCK_nDIV_1;
    switch (enClockSignal)
    {
    case CLOCK_enSIGNAL_ACLK:
        enDividerReg = CLOCK__enGetACLKDivider();
        break;
    case CLOCK_enSIGNAL_SMCLK:
        enDividerReg = CLOCK__enGetSMCLKDivider();
        break;
    case CLOCK_enSIGNAL_MCLK:
        enDividerReg = CLOCK__enGetMCLKDivider();
        break;
    default:
        break;
    }
    return (enDividerReg);
}

CLOCK_nDIV CLOCK__enGetACLKDivider(void)
{
    CLOCK_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = CLOCK_BCSCTL1_OFFSET;
    pstRegisterData.u8Value = (uint8_t) CLOCK_nDIV_1;
    pstRegisterData.u8Mask = CLOCK_BCSCTL1_DIVA_MASK;
    pstRegisterData.u8Shift = CLOCK_BCSCTL1_R_DIVA_BIT;
    (void) CLOCK__u8ReadRegister(&pstRegisterData);
    return ((CLOCK_nDIV) pstRegisterData.u8Value);
}

CLOCK_nDIV CLOCK__enGetSMCLKDivider(void)
{
    CLOCK_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = CLOCK_BCSCTL2_OFFSET;
    pstRegisterData.u8Value = (uint8_t) CLOCK_nDIV_1;
    pstRegisterData.u8Mask = CLOCK_BCSCTL2_DIVS_MASK;
    pstRegisterData.u8Shift = CLOCK_BCSCTL2_R_DIVS_BIT;
    (void) CLOCK__u8ReadRegister(&pstRegisterData);
    return ((CLOCK_nDIV) pstRegisterData.u8Value);
}

CLOCK_nDIV CLOCK__enGetMCLKDivider(void)
{
    CLOCK_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = CLOCK_BCSCTL2_OFFSET;
    pstRegisterData.u8Value = (uint8_t) CLOCK_nDIV_1;
    pstRegisterData.u8Mask = CLOCK_BCSCTL2_DIVM_MASK;
    pstRegisterData.u8Shift = CLOCK_BCSCTL2_R_DIVM_BIT;
    (void) CLOCK__u8ReadRegister(&pstRegisterData);
    return ((CLOCK_nDIV) pstRegisterData.u8Value);
}

uint8_t CLOCK__u8GetDivider(CLOCK_nSIGNAL enClockSignal)
{
    uint8_t u8DividerShift = 0U;
    uint8_t u8DividerReg = 1U;

    u8DividerShift = (uint8_t) CLOCK__enGetDivider(enClockSignal);
    u8DividerReg <<= u8DividerShift;
    return (u8DividerReg);
}

uint8_t CLOCK__u8GetACLKDivider(void)
{
    uint8_t u8DividerReg = 0U;
    u8DividerReg = CLOCK__u8GetDivider(CLOCK_enSIGNAL_ACLK);
    return (u8DividerReg);
}

uint8_t CLOCK__u8GetSMCLKDivider(void)
{
    uint8_t u8DividerReg = 0U;
    u8DividerReg = CLOCK__u8GetDivider(CLOCK_enSIGNAL_SMCLK);
    return (u8DividerReg);
}

uint8_t CLOCK__u8GetMCLKDivider(void)
{
    uint8_t u8DividerReg = 0U;
    u8DividerReg = CLOCK__u8GetDivider(CLOCK_enSIGNAL_MCLK);
    return (u8DividerReg);
}
