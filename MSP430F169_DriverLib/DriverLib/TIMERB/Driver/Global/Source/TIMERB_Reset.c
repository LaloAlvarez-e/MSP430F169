/**
 *
 * @file TIMERB_Reset.c
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
#include <DriverLib/TIMERB/Driver/Global/Header/TIMERB_Reset.h>
#include "DriverLib/TIMERB/Driver/Intrinsics/TIMERB_Intrinsics.h"
#include "DriverLib/TIMERB/Peripheral/TIMERB_Peripheral.h"

void TIMERB__vReset(void)
{
    TIMERB_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERB_CTL_OFFSET;
    pstRegisterData.u16Value = TIMERB_CTL_CLR_CLEAR;
    pstRegisterData.u16Mask = TIMERB_CTL_CLR_MASK;
    pstRegisterData.u8Shift = TIMERB_CTL_R_CLR_BIT;
    TIMERB__vWriteRegister(&pstRegisterData);
}
