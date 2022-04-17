/**
 *
 * @file TIMERB_CaptureConfig.c
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
#include <DriverLib/TIMERB/Driver/Module/Config/Header/TIMERB_CaptureConfig.h>


#include <DriverLib/TIMERB/Driver/Module/Header/TIMERB_CaptureInputSelection.h>
#include <DriverLib/TIMERB/Driver/Module/Header/TIMERB_CaptureMode.h>
#include <DriverLib/TIMERB/Driver/Module/Header/TIMERB_CaptureSyncMode.h>
#include <DriverLib/TIMERB/Driver/Module/Header/TIMERB_ModuleMode.h>

#include "DriverLib/TIMERB/Driver/Intrinsics/TIMERB_Intrinsics.h"
#include "DriverLib/TIMERB/Peripheral/TIMERB_Peripheral.h"

void TIMERB__vSetCaptureConfig(TIMERB_nCC enModuleArg,
                               TIMERB_Capture_Config_t* pstCaptureConfigArg)
{
    TIMERB_CC_CTL_t stConfigReg = {0};
    TIMERB_Register_t pstRegisterData;
    if(0UL != (uintptr_t) pstCaptureConfigArg)
    {

        stConfigReg.CM = (uint16_t) pstCaptureConfigArg->enCaptureMode;
        stConfigReg.SCS = (uint16_t) pstCaptureConfigArg->enSyncMode;
        stConfigReg.CCIS = (uint16_t) pstCaptureConfigArg->enCaptureInput;
        stConfigReg.COV = TIMERB_CC_CTL_COV_NOOCCUR;
        stConfigReg.CAP = TIMERB_CC_CTL_CAP_CAPTURE;

        pstRegisterData.uptrAddress = TIMERB_CC_CTL_OFFSET;
        pstRegisterData.u16Value = (*(uint16_t*) &stConfigReg);
        pstRegisterData.u16Mask = TIMERB_CC_CTL_R_CM_MASK |
                                    TIMERB_CC_CTL_R_SCS_MASK |
                                    TIMERB_CC_CTL_R_CCIS_MASK |
                                    TIMERB_CC_CTL_R_COV_MASK |
                                    TIMERB_CC_CTL_R_CAP_MASK;
        pstRegisterData.u8Shift = 0U;
        TIMERB_CC__vWriteRegister(enModuleArg, &pstRegisterData);
    }
}


void TIMERB__vGetCaptureConfig(TIMERB_nCC enModuleArg,
                        TIMERB_Capture_Config_t* pstCaptureConfigArg)
{
    if(0UL != (uintptr_t) pstCaptureConfigArg)
    {
        pstCaptureConfigArg->enCaptureMode = TIMERB__enGetCaptureMode(enModuleArg);
        pstCaptureConfigArg->enSyncMode = TIMERB__enGetCaptureSyncMode(enModuleArg);
        pstCaptureConfigArg->enCaptureInput = TIMERB__enGetCaptureInputSelection(enModuleArg);
    }
}


void TIMERB__vSetCaptureConfigExt(TIMERB_nCC enModuleArg,
                                  TIMERB_Capture_ConfigExt_t* pstCaptureConfigArg)
{
    TIMERB_CC_CTL_t stConfigReg = {0};
    TIMERB_Register_t pstRegisterData;
    if(0UL != (uintptr_t) pstCaptureConfigArg)
    {

        stConfigReg.CM = (uint16_t) pstCaptureConfigArg->enCaptureMode;
        stConfigReg.SCS = (uint16_t) pstCaptureConfigArg->enSyncMode;
        stConfigReg.CCIS = (uint16_t) pstCaptureConfigArg->enCaptureInput;
        stConfigReg.COV = TIMERB_CC_CTL_COV_NOOCCUR;
        stConfigReg.CAP = TIMERB_CC_CTL_CAP_CAPTURE;
        stConfigReg.IE = (uint16_t) pstCaptureConfigArg->enInterruptEnable;
        stConfigReg.IFG = (uint16_t) pstCaptureConfigArg->enInterruptStatus;

        pstRegisterData.uptrAddress = TIMERB_CC_CTL_OFFSET;
        pstRegisterData.u16Value = (*(uint16_t*) &stConfigReg);
        pstRegisterData.u16Mask = TIMERB_CC_CTL_R_CM_MASK |
                                    TIMERB_CC_CTL_R_SCS_MASK |
                                    TIMERB_CC_CTL_R_CCIS_MASK |
                                    TIMERB_CC_CTL_R_COV_MASK |
                                    TIMERB_CC_CTL_R_IE_MASK |
                                    TIMERB_CC_CTL_R_IFG_MASK |
                                    TIMERB_CC_CTL_R_CAP_MASK;
        pstRegisterData.u8Shift = 0U;
        TIMERB_CC__vWriteRegister(enModuleArg, &pstRegisterData);
    }
}


void TIMERB__vGetCaptureConfigExt(TIMERB_nCC enModuleArg,
                                  TIMERB_Capture_ConfigExt_t* pstCaptureConfigArg)
{
    if(0UL != (uintptr_t) pstCaptureConfigArg)
    {
        pstCaptureConfigArg->enCaptureMode = TIMERB__enGetCaptureMode(enModuleArg);
        pstCaptureConfigArg->enSyncMode = TIMERB__enGetCaptureSyncMode(enModuleArg);
        pstCaptureConfigArg->enCaptureInput = TIMERB__enGetCaptureInputSelection(enModuleArg);
        pstCaptureConfigArg->enInterruptEnable = TIMERB_CC__enGetEnableInterruptSource(enModuleArg);
        pstCaptureConfigArg->enInterruptStatus = TIMERB_CC__enGetStatusInterruptSource(enModuleArg);
    }
}





