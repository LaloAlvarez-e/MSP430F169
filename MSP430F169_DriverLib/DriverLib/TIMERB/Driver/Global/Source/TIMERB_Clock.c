/**
 *
 * @file TIMERB_Clock.c
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
#include "DriverLib/TIMERB/Driver/Global/Header/TIMERB_Clock.h"

#include "DriverLib/TIMERB/Driver/Intrinsics/TIMERB_Intrinsics.h"
#include "DriverLib/TIMERB/Peripheral/TIMERB_Peripheral.h"

void TIMERB__vSetClockSource(TIMERB_nCLOCK enClockArg)
{
    TIMERB_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERB_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enClockArg;
    pstRegisterData.u16Mask = TIMERB_CTL_SSEL_MASK;
    pstRegisterData.u8Shift = TIMERB_CTL_R_SSEL_BIT;
    TIMERB__vWriteRegister(&pstRegisterData);
}

TIMERB_nCLOCK TIMERB__enGetClockSource(void)
{
    TIMERB_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERB_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) TIMERB_enCLOCK_TBCLK;
    pstRegisterData.u16Mask = TIMERB_CTL_SSEL_MASK;
    pstRegisterData.u8Shift = TIMERB_CTL_R_SSEL_BIT;
    (void) TIMERB__u16ReadRegister(&pstRegisterData);
    return ((TIMERB_nCLOCK) pstRegisterData.u16Value);
}
