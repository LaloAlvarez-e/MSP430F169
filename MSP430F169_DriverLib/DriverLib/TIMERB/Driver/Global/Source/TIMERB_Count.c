/**
 *
 * @file TIMERB_Count.c
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
#include <DriverLib/TIMERB/Driver/Global/Header/TIMERB_Count.h>

#include "DriverLib/TIMERB/Driver/Intrinsics/TIMERB_Intrinsics.h"
#include "DriverLib/TIMERB/Peripheral/TIMERB_Peripheral.h"

void TIMERB__vSetCount(uint16_t u16CountArg)
{
    TIMERB_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERB_R_OFFSET;
    pstRegisterData.u16Value = u16CountArg;
    pstRegisterData.u16Mask = TIMERB_R_R_MASK;
    pstRegisterData.u8Shift = TIMERB_R_R_R_BIT;
    TIMERB__vWriteRegister(&pstRegisterData);
}

void TIMERB__vClearCount(void)
{
    TIMERB_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERB_R_OFFSET;
    pstRegisterData.u16Value = 0U;
    pstRegisterData.u16Mask = TIMERB_R_R_MASK;
    pstRegisterData.u8Shift = TIMERB_R_R_R_BIT;
    TIMERB__vWriteRegister(&pstRegisterData);
}

uint16_t TIMERB__enGetCount(void)
{
    TIMERB_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERB_R_OFFSET;
    pstRegisterData.u16Value = 0U;
    pstRegisterData.u16Mask = TIMERB_R_R_MASK;
    pstRegisterData.u8Shift = TIMERB_R_R_R_BIT;
    (void) TIMERB__u16ReadRegister(&pstRegisterData);
    return (pstRegisterData.u16Value);
}



