/**
 *
 * @file TIMERB_CaptureOverflow.c
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
 * @verbatim 12 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 12 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <DriverLib/TIMERB/Driver/Module/Header/TIMERB_CaptureOverflow.h>

#include "DriverLib/TIMERB/Driver/Intrinsics/TIMERB_Intrinsics.h"
#include "DriverLib/TIMERB/Peripheral/TIMERB_Peripheral.h"

void TIMERB__vSetCaptureOverflow(TIMERB_nCC enModuleArg,
                                 TIMERB_nINT_STATUS enCaptureOverflowArg)
{
    TIMERB_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERB_CC_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enCaptureOverflowArg;
    pstRegisterData.u16Mask = TIMERB_CC_CTL_COV_MASK;
    pstRegisterData.u8Shift = TIMERB_CC_CTL_R_COV_BIT;
    TIMERB_CC__vWriteRegister(enModuleArg,
                         &pstRegisterData);
}

void TIMERB__vClearCaptureOverflow(TIMERB_nCC enModuleArg)
{
    TIMERB__vSetCaptureOverflow(enModuleArg, TIMERB_enINT_STATUS_NOOCCUR);
}

TIMERB_nINT_STATUS TIMERB__enGetCaptureOverflow(TIMERB_nCC enModuleArg)
{
    TIMERB_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERB_CC_CTL_OFFSET;
    pstRegisterData.u16Value = 0U;
    pstRegisterData.u16Mask = TIMERB_CC_CTL_COV_MASK;
    pstRegisterData.u8Shift = TIMERB_CC_CTL_R_COV_BIT;
    (void) TIMERB_CC__u16ReadRegister(enModuleArg, &pstRegisterData);
    return ((TIMERB_nINT_STATUS) pstRegisterData.u16Value);
}



