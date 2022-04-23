/**
 *
 * @file TIMERA_CaptureConfig.c
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
#include <DriverLib/TIMERA/Driver/Module/Config/Header/TIMERA_CaptureConfig.h>


#include <DriverLib/TIMERA/Driver/Module/Header/TIMERA_CaptureInputSelection.h>
#include <DriverLib/TIMERA/Driver/Module/Header/TIMERA_CaptureMode.h>
#include <DriverLib/TIMERA/Driver/Module/Header/TIMERA_CaptureSyncMode.h>
#include <DriverLib/TIMERA/Driver/Module/Header/TIMERA_ModuleMode.h>

#include "DriverLib/TIMERA/Driver/Intrinsics/TIMERA_Intrinsics.h"
#include "DriverLib/TIMERA/Peripheral/TIMERA_Peripheral.h"

void TIMERA_CC__vSetCaptureConfig(TIMERA_nCC enModuleArg,
                               TIMERA_Capture_Config_t* pstCaptureConfigArg)
{
    TIMERA_CC_CTL_t stConfigReg = {0};
    TIMERA_Register_t pstRegisterData;
    if(0UL != (uintptr_t) pstCaptureConfigArg)
    {

        stConfigReg.CM = (uint16_t) pstCaptureConfigArg->enCaptureMode;
        stConfigReg.SCS = (uint16_t) pstCaptureConfigArg->enSyncMode;
        stConfigReg.CCIS = (uint16_t) pstCaptureConfigArg->enCaptureInput;
        stConfigReg.COV = TIMERA_CC_CTL_COV_NOOCCUR;
        stConfigReg.CAP = TIMERA_CC_CTL_CAP_CAPTURE;

        pstRegisterData.uptrAddress = TIMERA_CC_CTL_OFFSET;
        pstRegisterData.u16Value = (*(uint16_t*) &stConfigReg);
        pstRegisterData.u16Mask = TIMERA_CC_CTL_R_CM_MASK |
                                    TIMERA_CC_CTL_R_SCS_MASK |
                                    TIMERA_CC_CTL_R_CCIS_MASK |
                                    TIMERA_CC_CTL_R_COV_MASK |
                                    TIMERA_CC_CTL_R_CAP_MASK;
        pstRegisterData.u8Shift = 0U;
        TIMERA_CC__vWriteRegister(enModuleArg, &pstRegisterData);
    }
}


void TIMERA_CC__vGetCaptureConfig(TIMERA_nCC enModuleArg,
                        TIMERA_Capture_Config_t* pstCaptureConfigArg)
{
    if(0UL != (uintptr_t) pstCaptureConfigArg)
    {
        pstCaptureConfigArg->enCaptureMode = TIMERA_CC__enGetCaptureMode(enModuleArg);
        pstCaptureConfigArg->enSyncMode = TIMERA_CC__enGetCaptureSyncMode(enModuleArg);
        pstCaptureConfigArg->enCaptureInput = TIMERA_CC__enGetCaptureInputSelection(enModuleArg);
    }
}


void TIMERA_CC__vSetCaptureConfigExt(TIMERA_nCC enModuleArg,
                                  TIMERA_Capture_ConfigExt_t* pstCaptureConfigArg)
{
    TIMERA_CC_CTL_t stConfigReg = {0};
    TIMERA_Register_t pstRegisterData;
    if(0UL != (uintptr_t) pstCaptureConfigArg)
    {

        stConfigReg.CM = (uint16_t) pstCaptureConfigArg->enCaptureMode;
        stConfigReg.SCS = (uint16_t) pstCaptureConfigArg->enSyncMode;
        stConfigReg.CCIS = (uint16_t) pstCaptureConfigArg->enCaptureInput;
        stConfigReg.COV = TIMERA_CC_CTL_COV_NOOCCUR;
        stConfigReg.CAP = TIMERA_CC_CTL_CAP_CAPTURE;
        stConfigReg.IE = (uint16_t) pstCaptureConfigArg->enInterruptEnable;
        stConfigReg.IFG = (uint16_t) pstCaptureConfigArg->enInterruptStatus;

        pstRegisterData.uptrAddress = TIMERA_CC_CTL_OFFSET;
        pstRegisterData.u16Value = (*(uint16_t*) &stConfigReg);
        pstRegisterData.u16Mask = TIMERA_CC_CTL_R_CM_MASK |
                                    TIMERA_CC_CTL_R_SCS_MASK |
                                    TIMERA_CC_CTL_R_CCIS_MASK |
                                    TIMERA_CC_CTL_R_COV_MASK |
                                    TIMERA_CC_CTL_R_IE_MASK |
                                    TIMERA_CC_CTL_R_IFG_MASK |
                                    TIMERA_CC_CTL_R_CAP_MASK;
        pstRegisterData.u8Shift = 0U;
        TIMERA_CC__vWriteRegister(enModuleArg, &pstRegisterData);
    }
}


void TIMERA_CC__vGetCaptureConfigExt(TIMERA_nCC enModuleArg,
                                  TIMERA_Capture_ConfigExt_t* pstCaptureConfigArg)
{
    if(0UL != (uintptr_t) pstCaptureConfigArg)
    {
        pstCaptureConfigArg->enCaptureMode = TIMERA_CC__enGetCaptureMode(enModuleArg);
        pstCaptureConfigArg->enSyncMode = TIMERA_CC__enGetCaptureSyncMode(enModuleArg);
        pstCaptureConfigArg->enCaptureInput = TIMERA_CC__enGetCaptureInputSelection(enModuleArg);
        pstCaptureConfigArg->enInterruptEnable = TIMERA_CC__enGetEnableInterruptSource(enModuleArg);
        pstCaptureConfigArg->enInterruptStatus = TIMERA_CC__enGetStatusInterruptSource(enModuleArg);
    }
}





