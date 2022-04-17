/**
 *
 * @file TIMERB_CaptureInputSelection.c
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
#include <DriverLib/TIMERB/Driver/Module/Header/TIMERB_CaptureInputSelection.h>

#include "DriverLib/TIMERB/Driver/Intrinsics/TIMERB_Intrinsics.h"
#include "DriverLib/TIMERB/Peripheral/TIMERB_Peripheral.h"

void TIMERB__vSetCaptureInputSelection(TIMERB_nCC enModuleArg,
                             TIMERB_nCC_CAPTUREINPUT enCaptureInputSelectionArg)
{
    TIMERB_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERB_CC_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enCaptureInputSelectionArg;
    pstRegisterData.u16Mask = TIMERB_CC_CTL_CCIS_MASK;
    pstRegisterData.u8Shift = TIMERB_CC_CTL_R_CCIS_BIT;
    TIMERB_CC__vWriteRegister(enModuleArg,
                         &pstRegisterData);
}

TIMERB_nCC_CAPTUREINPUT TIMERB__enGetCaptureInputSelection(TIMERB_nCC enModuleArg)
{
    TIMERB_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERB_CC_CTL_OFFSET;
    pstRegisterData.u16Value = 0U;
    pstRegisterData.u16Mask = TIMERB_CC_CTL_CCIS_MASK;
    pstRegisterData.u8Shift = TIMERB_CC_CTL_R_CCIS_BIT;
    (void) TIMERB_CC__u16ReadRegister(enModuleArg, &pstRegisterData);
    return ((TIMERB_nCC_CAPTUREINPUT) pstRegisterData.u16Value);
}




