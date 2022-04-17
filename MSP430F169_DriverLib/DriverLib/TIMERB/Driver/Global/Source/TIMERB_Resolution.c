/**
 *
 * @file TIMERB_Resolution.c
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
 * @verbatim 17 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 17 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <DriverLib/TIMERB/Driver/Global/Header/TIMERB_Resolution.h>

#include "DriverLib/TIMERB/Driver/Intrinsics/TIMERB_Intrinsics.h"
#include "DriverLib/TIMERB/Peripheral/TIMERB_Peripheral.h"

void TIMERB__vSetResolution(TIMERB_nRESOLUTION enResolutionArg)
{
    TIMERB_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERB_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enResolutionArg;
    pstRegisterData.u16Mask = TIMERB_CTL_CNTL_MASK;
    pstRegisterData.u8Shift = TIMERB_CTL_R_CNTL_BIT;
    TIMERB__vWriteRegister(&pstRegisterData);
}

TIMERB_nRESOLUTION TIMERB__enGetResolution(void)
{
    TIMERB_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERB_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) TIMERB_enRESOLUTION_16BITS;
    pstRegisterData.u16Mask = TIMERB_CTL_CNTL_MASK;
    pstRegisterData.u8Shift = TIMERB_CTL_R_CNTL_BIT;
    (void) TIMERB__u16ReadRegister(&pstRegisterData);
    return ((TIMERB_nRESOLUTION) pstRegisterData.u16Value);
}

