/**
 *
 * @file TIMERB_ClockDivider.c
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

#include "DriverLib/TIMERB/Driver/Global/Header/TIMERB_ClockDivider.h"

#include "DriverLib/TIMERB/Driver/Intrinsics/Primitives/TIMERB_Primitives.h"
#include "DriverLib/TIMERB/Peripheral/TIMERB_Peripheral.h"


void TIMERB__vSetClockDivider(TIMERB_nCLOCK_DIV enClockDivider)
{
    TIMERB_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERB_CTL_OFFSET;
    pstRegisterData.u16Value = (uint8_t) enClockDivider;
    pstRegisterData.u16Mask = TIMERB_CTL_ID_MASK;
    pstRegisterData.u8Shift = TIMERB_CTL_R_ID_BIT;
    TIMERB__vWriteRegister(&pstRegisterData);
}

void TIMERB__vSetClockDividerByNumber(uint8_t u8ClockDivider)
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

        TIMERB__vSetClockDivider((TIMERB_nCLOCK_DIV) u8Value);
    }
}


TIMERB_nCLOCK_DIV TIMERB__enGetClockDivider(void)
{
    TIMERB_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERB_CTL_OFFSET;
    pstRegisterData.u16Value = (uint8_t) TIMERB_enCLOCK_DIV_1;
    pstRegisterData.u16Mask = TIMERB_CTL_ID_MASK;
    pstRegisterData.u8Shift = TIMERB_CTL_R_ID_BIT;
    (void) TIMERB__u16ReadRegister(&pstRegisterData);
    return ((TIMERB_nCLOCK_DIV) pstRegisterData.u16Value);
}


uint8_t TIMERB__u8GetClockDivider(void)
{
    uint8_t u8ClockDividerShift = 0U;
    uint8_t u8ClockDividerReg = 1U;

    u8ClockDividerShift = (uint8_t) TIMERB__enGetClockDivider();
    u8ClockDividerReg <<= u8ClockDividerShift;
    return (u8ClockDividerReg);
}


