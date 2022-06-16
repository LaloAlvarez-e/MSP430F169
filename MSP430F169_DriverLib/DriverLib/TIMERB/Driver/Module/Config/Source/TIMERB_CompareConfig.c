/**
 *
 * @file TIMERB_CompareConfig.c
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
#include <DriverLib/TIMERB/Driver/Module/Config/Header/TIMERB_CompareConfig.h>


#include <DriverLib/TIMERB/Driver/Module/Header/TIMERB_CompareLoad.h>
#include <DriverLib/TIMERB/Driver/Module/Header/TIMERB_CompareMode.h>
#include <DriverLib/TIMERB/Driver/Module/Header/TIMERB_CompareOutput.h>
#include <DriverLib/TIMERB/Driver/Module/Header/TIMERB_ModuleMode.h>
#include <DriverLib/TIMERB/Driver/Module/Header/TIMERB_ModuleValue.h>

#include "DriverLib/TIMERB/Driver/Intrinsics/TIMERB_Intrinsics.h"
#include "DriverLib/TIMERB/Peripheral/TIMERB_Peripheral.h"

void TIMERB_CC__vSetCompareConfig(TIMERB_nCC enModuleArg,
                               TIMERB_Compare_Config_t* pstCompareConfigArg)
{
    TIMERB_CC_CTL_t stConfigReg = {0};
    TIMERB_Register_t pstRegisterData;
    if(0UL != (uintptr_t) pstCompareConfigArg)
    {
        TIMERB_CC__vSetCompareOutput(enModuleArg, pstCompareConfigArg->enCompareState);

        stConfigReg.OUTMOD = (uint16_t) pstCompareConfigArg->enCompareMode;
        stConfigReg.OUT = (uint16_t) pstCompareConfigArg->enCompareState;
        stConfigReg.CAP = TIMERB_CC_CTL_CAP_COMPARE;
        stConfigReg.CLLD = (uint16_t) pstCompareConfigArg->enCompareLoadMode;

        pstRegisterData.uptrAddress = TIMERB_CC_CTL_OFFSET;
        pstRegisterData.u16Value = (*(uint16_t*) &stConfigReg);
        pstRegisterData.u16Mask = TIMERB_CC_CTL_R_OUTMOD_MASK |
                                    TIMERB_CC_CTL_R_OUT_MASK |
                                    TIMERB_CC_CTL_R_CAP_MASK |
                                    TIMERB_CC_CTL_R_CLLD_MASK;
        pstRegisterData.u8Shift = 0U;
        TIMERB_CC__vWriteRegister(enModuleArg, &pstRegisterData);

        TIMERB_CC__vSetValue(enModuleArg, pstCompareConfigArg->u16CompareValue);
    }
}


void TIMERB_CC__vGetCompareConfig(TIMERB_nCC enModuleArg,
                        TIMERB_Compare_Config_t* pstCompareConfigArg)
{
    if(0UL != (uintptr_t) pstCompareConfigArg)
    {
        pstCompareConfigArg->enCompareMode = TIMERB_CC__enGetCompareMode(enModuleArg);
        pstCompareConfigArg->enCompareState = TIMERB_CC__enGetCompareOutput(enModuleArg);
        pstCompareConfigArg->u16CompareValue = TIMERB_CC__u16GetValue(enModuleArg);
        pstCompareConfigArg->enCompareLoadMode = TIMERB_CC__enGetCompareLoadMode(enModuleArg);
    }
}


void TIMERB_CC__vSetCompareConfigExt(TIMERB_nCC enModuleArg,
                                  TIMERB_Compare_ConfigExt_t* pstCompareConfigArg)
{
    TIMERB_CC_CTL_t stConfigReg = {0};
    TIMERB_Register_t pstRegisterData;
    if(0UL != (uintptr_t) pstCompareConfigArg)
    {
        TIMERB_CC__vSetCompareOutput(enModuleArg, pstCompareConfigArg->enCompareState);

        stConfigReg.OUTMOD = (uint16_t) pstCompareConfigArg->enCompareMode;
        stConfigReg.OUT = (uint16_t) pstCompareConfigArg->enCompareState;
        stConfigReg.CAP = TIMERB_CC_CTL_CAP_COMPARE;
        stConfigReg.IE = (uint16_t) pstCompareConfigArg->enInterruptEnable;
        stConfigReg.IFG = (uint16_t) pstCompareConfigArg->enInterruptStatus;
        stConfigReg.CLLD = (uint16_t) pstCompareConfigArg->enCompareLoadMode;

        pstRegisterData.uptrAddress = TIMERB_CC_CTL_OFFSET;
        pstRegisterData.u16Value = (*(uint16_t*) &stConfigReg);
        pstRegisterData.u16Mask = TIMERB_CC_CTL_R_OUTMOD_MASK |
                                    TIMERB_CC_CTL_R_OUT_MASK |
                                    TIMERB_CC_CTL_R_IE_MASK |
                                    TIMERB_CC_CTL_R_IFG_MASK |
                                    TIMERB_CC_CTL_R_CAP_MASK |
                                    TIMERB_CC_CTL_R_CLLD_MASK;
        pstRegisterData.u8Shift = 0U;
        TIMERB_CC__vWriteRegister(enModuleArg, &pstRegisterData);

        TIMERB_CC__vSetValue(enModuleArg, pstCompareConfigArg->u16CompareValue);
    }
}


void TIMERB_CC__vGetCompareConfigExt(TIMERB_nCC enModuleArg,
                                  TIMERB_Compare_ConfigExt_t* pstCompareConfigArg)
{
    if(0UL != (uintptr_t) pstCompareConfigArg)
    {
        pstCompareConfigArg->enCompareMode = TIMERB_CC__enGetCompareMode(enModuleArg);
        pstCompareConfigArg->enCompareState = TIMERB_CC__enGetCompareOutput(enModuleArg);
        pstCompareConfigArg->u16CompareValue = TIMERB_CC__u16GetValue(enModuleArg);
        pstCompareConfigArg->enInterruptEnable = TIMERB_CC__enGetEnableInterruptSource(enModuleArg);
        pstCompareConfigArg->enInterruptStatus = TIMERB_CC__enGetStatusInterruptSource(enModuleArg);
        pstCompareConfigArg->enCompareLoadMode = TIMERB_CC__enGetCompareLoadMode(enModuleArg);
    }
}




