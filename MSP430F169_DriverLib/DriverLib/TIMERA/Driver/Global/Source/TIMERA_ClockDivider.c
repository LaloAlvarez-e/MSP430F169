/**
 *
 * @file TIMERA_ClockDivider.c
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
 * @verbatim 9 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 9 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#include "DriverLib/TIMERA/Driver/Global/Header/TIMERA_ClockDivider.h"

#include "DriverLib/TIMERA/Driver/Intrinsics/Primitives/TIMERA_Primitives.h"
#include "DriverLib/TIMERA/Peripheral/TIMERA_Peripheral.h"


void TIMERA__vSetClockDivider(TIMERA_nCLOCK_DIV enClockDivider)
{
    TIMERA_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERA_CTL_OFFSET;
    pstRegisterData.u16Value = (uint8_t) enClockDivider;
    pstRegisterData.u16Mask = TIMERA_CTL_ID_MASK;
    pstRegisterData.u8Shift = TIMERA_CTL_R_ID_BIT;
    TIMERA__vWriteRegister(&pstRegisterData);
}

void TIMERA__vSetClockDividerByNumber(uint8_t u8ClockDivider)
{
    uint8_t u8Value = 0U;
    uint8_t u8Count = 0U;
    u8ClockDivider &= 0xFU;
    if(0U != u8ClockDivider)
    {
        do
        {
            if(0U != (1U & u8ClockDivider))
            {
                u8Value = u8Count;
            }
            u8ClockDivider >>= 1U;
            u8Count++;
        }while(0U != u8ClockDivider);

        TIMERA__vSetClockDivider((TIMERA_nCLOCK_DIV) u8Value);
    }
}


TIMERA_nCLOCK_DIV TIMERA__enGetClockDivider(void)
{
    TIMERA_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERA_CTL_OFFSET;
    pstRegisterData.u16Value = (uint8_t) TIMERA_enCLOCK_DIV_1;
    pstRegisterData.u16Mask = TIMERA_CTL_ID_MASK;
    pstRegisterData.u8Shift = TIMERA_CTL_R_ID_BIT;
    (void) TIMERA__u16ReadRegister(&pstRegisterData);
    return ((TIMERA_nCLOCK_DIV) pstRegisterData.u16Value);
}


uint8_t TIMERA__u8GetClockDivider(void)
{
    uint8_t u8ClockDividerShift;
    uint8_t u8ClockDividerReg;

    u8ClockDividerShift = (uint8_t) TIMERA__enGetClockDivider();
    u8ClockDividerReg = 1U;
    u8ClockDividerReg <<= u8ClockDividerShift;
    return (u8ClockDividerReg);
}


