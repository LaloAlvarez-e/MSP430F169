/**
 *
 * @file TIMERB_Config.c
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
 * @verbatim 27 mar. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 27 mar. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <DriverLib/TIMERB/Driver/Global/Header/TIMERB_Config.h>

#include <DriverLib/TIMERB/Driver/Module/Header/TIMERB_ModuleValue.h>
#include <DriverLib/TIMERB/Driver/Global/Header/TIMERB_Reset.h>
#include <DriverLib/TIMERB/Driver/Global/Header/TIMERB_Clock.h>
#include <DriverLib/TIMERB/Driver/Global/Header/TIMERB_ClockDivider.h>
#include <DriverLib/TIMERB/Driver/Global/Header/TIMERB_OperationMode.h>
#include <DriverLib/TIMERB/Driver/Global/Header/TIMERB_Resolution.h>
#include <DriverLib/TIMERB/Driver/Global/Header/TIMERB_GroupLoad.h>

#include "DriverLib/TIMERB/Driver/Intrinsics/TIMERB_Intrinsics.h"
#include "DriverLib/TIMERB/Peripheral/TIMERB_Peripheral.h"

void TIMERB__vSetConfig(TIMERB_Config_t* pstConfigArg)
{
    TIMERB_CTL_t stConfigReg = {0};
    TIMERB_Register_t pstRegisterData;
    if(0UL != (uintptr_t) pstConfigArg)
    {
        TIMERB__vReset();

        if((TIMERB_enMODE_UP == pstConfigArg->enOperationMode) ||
           (TIMERB_enMODE_UP_DOWN == pstConfigArg->enOperationMode))
        {
            TIMERB_CC__vSetValue(TIMERB_enCC0, pstConfigArg->u16PeriodTicks);
        }

        stConfigReg.MC = (uint16_t) pstConfigArg->enOperationMode;
        stConfigReg.ID = (uint16_t) pstConfigArg->enClockDivider;
        stConfigReg.SSEL = (uint16_t) pstConfigArg->enClockSource;
        stConfigReg.CNTL = (uint16_t) pstConfigArg->enResolution;
        stConfigReg.CLGRP = (uint16_t) pstConfigArg->enGroupLoad;

        pstRegisterData.uptrAddress = TIMERB_CTL_OFFSET;
        pstRegisterData.u16Value = (*(uint16_t*) &stConfigReg);
        pstRegisterData.u16Mask = TIMERB_CTL_R_MC_MASK |
                                    TIMERB_CTL_R_ID_MASK |
                                    TIMERB_CTL_R_SSEL_MASK |
                                    TIMERB_CTL_R_CNTL_MASK |
                                    TIMERB_CTL_R_CLGRP_MASK;
        pstRegisterData.u8Shift = 0U;
        TIMERB__vWriteRegister(&pstRegisterData);
    }
}


void TIMERB__vGetConfig(TIMERB_Config_t* pstConfigArg)
{
    if(0UL != (uintptr_t) pstConfigArg)
    {
        pstConfigArg->enOperationMode = TIMERB__enGetOperationMode();
        pstConfigArg->enClockDivider = TIMERB__enGetClockDivider();
        pstConfigArg->enClockSource = TIMERB__enGetClockSource();
        pstConfigArg->enClockSource = TIMERB__enGetClockSource();
        pstConfigArg->enResolution = TIMERB__enGetResolution();
        pstConfigArg->enGroupLoad = TIMERB__enGetGroupLoad();
    }
}


void TIMERB__vSetConfigExt(TIMERB_ConfigExt_t* pstConfigArg)
{
    TIMERB_CTL_t stConfigReg = {0};
    TIMERB_Register_t pstRegisterData;
    if(0UL != (uintptr_t) pstConfigArg)
    {
        TIMERB__vReset();

        if((TIMERB_enMODE_UP == pstConfigArg->enOperationMode) ||
           (TIMERB_enMODE_UP_DOWN == pstConfigArg->enOperationMode))
        {
            TIMERB_CC__vSetValue(TIMERB_enCC0, pstConfigArg->u16PeriodTicks);
        }

        stConfigReg.MC = (uint16_t) pstConfigArg->enOperationMode;
        stConfigReg.ID = (uint16_t) pstConfigArg->enClockDivider;
        stConfigReg.SSEL = (uint16_t) pstConfigArg->enClockSource;
        stConfigReg.IE = (uint16_t) pstConfigArg->enInterruptEnable;
        stConfigReg.IFG = (uint16_t) pstConfigArg->enInterruptStatus;
        stConfigReg.CNTL = (uint16_t) pstConfigArg->enResolution;
        stConfigReg.CLGRP = (uint16_t) pstConfigArg->enGroupLoad;

        pstRegisterData.uptrAddress = TIMERB_CTL_OFFSET;
        pstRegisterData.u16Value = (*(uint16_t*) &stConfigReg);
        pstRegisterData.u16Mask = 0xFFFFU;
        pstRegisterData.u8Shift = 0U;
        TIMERB__vWriteRegister(&pstRegisterData);
    }
}


void TIMERB__vGetConfigExt(TIMERB_ConfigExt_t* pstConfigArg)
{
    if(0UL != (uintptr_t) pstConfigArg)
    {
        pstConfigArg->enOperationMode = TIMERB__enGetOperationMode();
        pstConfigArg->enClockDivider = TIMERB__enGetClockDivider();
        pstConfigArg->enClockSource = TIMERB__enGetClockSource();
        pstConfigArg->enInterruptEnable = TIMERB__enGetEnableInterruptSource();
        pstConfigArg->enInterruptStatus = TIMERB__enGetStatusInterruptSource();
        pstConfigArg->enResolution = TIMERB__enGetResolution();
        pstConfigArg->enGroupLoad = TIMERB__enGetGroupLoad();
    }
}



