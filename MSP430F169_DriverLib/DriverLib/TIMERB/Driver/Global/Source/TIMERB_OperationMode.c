/**
 *
 * @file TIMERB_OperationMode.c
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
#include <DriverLib/TIMERB/Driver/Global/Header/TIMERB_OperationMode.h>

#include "DriverLib/TIMERB/Driver/Intrinsics/TIMERB_Intrinsics.h"
#include "DriverLib/TIMERB/Peripheral/TIMERB_Peripheral.h"

void TIMERB__vSetOperationMode(TIMERB_nMODE enOperationModeArg)
{
    TIMERB_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERB_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enOperationModeArg;
    pstRegisterData.u16Mask = TIMERB_CTL_MC_MASK;
    pstRegisterData.u8Shift = TIMERB_CTL_R_MC_BIT;
    TIMERB__vWriteRegister(&pstRegisterData);
}

TIMERB_nMODE TIMERB__enGetOperationMode(void)
{
    TIMERB_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERB_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) TIMERB_enMODE_STOP;
    pstRegisterData.u16Mask = TIMERB_CTL_MC_MASK;
    pstRegisterData.u8Shift = TIMERB_CTL_R_MC_BIT;
    (void) TIMERB__u16ReadRegister(&pstRegisterData);
    return ((TIMERB_nMODE) pstRegisterData.u16Value);
}



