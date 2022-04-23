/**
 *
 * @file TIMERA_CompareConfig.c
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
#include <DriverLib/TIMERA/Driver/Module/Config/Header/TIMERA_CompareConfig.h>


#include <DriverLib/TIMERA/Driver/Module/Header/TIMERA_CompareMode.h>
#include <DriverLib/TIMERA/Driver/Module/Header/TIMERA_CompareOutput.h>
#include <DriverLib/TIMERA/Driver/Module/Header/TIMERA_ModuleMode.h>
#include <DriverLib/TIMERA/Driver/Module/Header/TIMERA_ModuleValue.h>

#include "DriverLib/TIMERA/Driver/Intrinsics/TIMERA_Intrinsics.h"
#include "DriverLib/TIMERA/Peripheral/TIMERA_Peripheral.h"

void TIMERA_CC__vSetCompareConfig(TIMERA_nCC enModuleArg,
                               TIMERA_Compare_Config_t* pstCompareConfigArg)
{
    TIMERA_CC_CTL_t stConfigReg = {0};
    TIMERA_Register_t pstRegisterData;
    if(0UL != (uintptr_t) pstCompareConfigArg)
    {
        TIMERA_CC__vSetCompareOutput(enModuleArg, pstCompareConfigArg->enCompareState);

        stConfigReg.OUTMOD = (uint16_t) pstCompareConfigArg->enCompareMode;
        stConfigReg.OUT = (uint16_t) pstCompareConfigArg->enCompareState;
        stConfigReg.CAP = TIMERA_CC_CTL_CAP_COMPARE;

        pstRegisterData.uptrAddress = TIMERA_CC_CTL_OFFSET;
        pstRegisterData.u16Value = (*(uint16_t*) &stConfigReg);
        pstRegisterData.u16Mask = TIMERA_CC_CTL_R_OUTMOD_MASK |
                                    TIMERA_CC_CTL_R_OUT_MASK |
                                    TIMERA_CC_CTL_R_CAP_MASK;
        pstRegisterData.u8Shift = 0U;
        TIMERA_CC__vWriteRegister(enModuleArg, &pstRegisterData);

        TIMERA_CC__vSetValue(enModuleArg, pstCompareConfigArg->u16CompareValue);
    }
}


void TIMERA_CC__vGetCompareConfig(TIMERA_nCC enModuleArg,
                        TIMERA_Compare_Config_t* pstCompareConfigArg)
{
    if(0UL != (uintptr_t) pstCompareConfigArg)
    {
        pstCompareConfigArg->enCompareMode = TIMERA_CC__enGetCompareMode(enModuleArg);
        pstCompareConfigArg->enCompareState = TIMERA_CC__enGetCompareOutput(enModuleArg);
        pstCompareConfigArg->u16CompareValue = TIMERA_CC__u16GetValue(enModuleArg);
    }
}


void TIMERA_CC__vSetCompareConfigExt(TIMERA_nCC enModuleArg,
                                  TIMERA_Compare_ConfigExt_t* pstCompareConfigArg)
{
    static TIMERA_CC_CTL_t stConfigReg = {0};
    TIMERA_Register_t pstRegisterData;
    if(0UL != (uintptr_t) pstCompareConfigArg)
    {
        TIMERA_CC__vSetCompareOutput(enModuleArg, pstCompareConfigArg->enCompareState);

        stConfigReg.OUTMOD = (uint16_t) pstCompareConfigArg->enCompareMode;
        stConfigReg.OUT = (uint16_t) pstCompareConfigArg->enCompareState;
        stConfigReg.CAP = TIMERA_CC_CTL_CAP_COMPARE;
        stConfigReg.IE = (uint16_t) pstCompareConfigArg->enInterruptEnable;
        stConfigReg.IFG = (uint16_t) pstCompareConfigArg->enInterruptStatus;

        pstRegisterData.uptrAddress = TIMERA_CC_CTL_OFFSET;
        pstRegisterData.u16Value = (*(uint16_t*) &stConfigReg);
        pstRegisterData.u16Mask = TIMERA_CC_CTL_R_OUTMOD_MASK |
                                    TIMERA_CC_CTL_R_OUT_MASK |
                                    TIMERA_CC_CTL_R_IE_MASK |
                                    TIMERA_CC_CTL_R_IFG_MASK |
                                    TIMERA_CC_CTL_R_CAP_MASK;
        pstRegisterData.u8Shift = 0U;
        TIMERA_CC__vWriteRegister(enModuleArg, &pstRegisterData);

        TIMERA_CC__vSetValue(enModuleArg, pstCompareConfigArg->u16CompareValue);
    }
}


void TIMERA_CC__vGetCompareConfigExt(TIMERA_nCC enModuleArg,
                                  TIMERA_Compare_ConfigExt_t* pstCompareConfigArg)
{
    if(0UL != (uintptr_t) pstCompareConfigArg)
    {
        pstCompareConfigArg->enCompareMode = TIMERA_CC__enGetCompareMode(enModuleArg);
        pstCompareConfigArg->enCompareState = TIMERA_CC__enGetCompareOutput(enModuleArg);
        pstCompareConfigArg->u16CompareValue = TIMERA_CC__u16GetValue(enModuleArg);
        pstCompareConfigArg->enInterruptEnable = TIMERA_CC__enGetEnableInterruptSource(enModuleArg);
        pstCompareConfigArg->enInterruptStatus = TIMERA_CC__enGetStatusInterruptSource(enModuleArg);
    }
}




