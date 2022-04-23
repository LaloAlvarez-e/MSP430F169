/**
 *
 * @file TIMERA_Config.c
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
#include <DriverLib/TIMERA/Driver/Global/Header/TIMERA_Config.h>


#include <DriverLib/TIMERA/Driver/Module/Header/TIMERA_ModuleValue.h>
#include <DriverLib/TIMERA/Driver/Global/Header/TIMERA_Reset.h>
#include <DriverLib/TIMERA/Driver/Global/Header/TIMERA_Clock.h>
#include <DriverLib/TIMERA/Driver/Global/Header/TIMERA_ClockDivider.h>
#include <DriverLib/TIMERA/Driver/Global/Header/TIMERA_OperationMode.h>

#include "DriverLib/TIMERA/Driver/Intrinsics/TIMERA_Intrinsics.h"
#include "DriverLib/TIMERA/Peripheral/TIMERA_Peripheral.h"

void TIMERA__vSetConfig(TIMERA_Config_t* pstConfigArg)
{
    TIMERA_CTL_t stConfigReg = {0};
    TIMERA_Register_t pstRegisterData;
    if(0UL != (uintptr_t) pstConfigArg)
    {
        TIMERA__vReset();

        if((TIMERA_enMODE_UP == pstConfigArg->enOperationMode) ||
           (TIMERA_enMODE_UP_DOWN == pstConfigArg->enOperationMode))
        {
            TIMERA_CC__vSetValue(TIMERA_enCC0, pstConfigArg->u16PeriodTicks);
        }

        stConfigReg.MC = (uint16_t) pstConfigArg->enOperationMode;
        stConfigReg.ID = (uint16_t) pstConfigArg->enClockDivider;
        stConfigReg.SSEL = (uint16_t) pstConfigArg->enClockSource;

        pstRegisterData.uptrAddress = TIMERA_CTL_OFFSET;
        pstRegisterData.u16Value = (*(uint16_t*) &stConfigReg);
        pstRegisterData.u16Mask = TIMERA_CTL_R_MC_MASK |
                                    TIMERA_CTL_R_ID_MASK |
                                    TIMERA_CTL_R_SSEL_MASK;
        pstRegisterData.u8Shift = 0U;
        TIMERA__vWriteRegister(&pstRegisterData);
    }
}


void TIMERA__vGetConfig(TIMERA_Config_t* pstConfigArg)
{
    if(0UL != (uintptr_t) pstConfigArg)
    {
        pstConfigArg->enOperationMode = TIMERA__enGetOperationMode();
        pstConfigArg->enClockDivider = TIMERA__enGetClockDivider();
        pstConfigArg->enClockSource = TIMERA__enGetClockSource();
    }
}


void TIMERA__vSetConfigExt(TIMERA_ConfigExt_t* pstConfigArg)
{
    TIMERA_CTL_t stConfigReg = {0};
    TIMERA_Register_t pstRegisterData;
    if(0UL != (uintptr_t) pstConfigArg)
    {
        TIMERA__vReset();

        if((TIMERA_enMODE_UP == pstConfigArg->enOperationMode) ||
           (TIMERA_enMODE_UP_DOWN == pstConfigArg->enOperationMode))
        {
            TIMERA_CC__vSetValue(TIMERA_enCC0, pstConfigArg->u16PeriodTicks);
        }

        stConfigReg.MC = (uint16_t) pstConfigArg->enOperationMode;
        stConfigReg.ID = (uint16_t) pstConfigArg->enClockDivider;
        stConfigReg.SSEL = (uint16_t) pstConfigArg->enClockSource;
        stConfigReg.IE = (uint16_t) pstConfigArg->enInterruptEnable;
        stConfigReg.IFG = (uint16_t) pstConfigArg->enInterruptStatus;

        pstRegisterData.uptrAddress = TIMERA_CTL_OFFSET;
        pstRegisterData.u16Value = (*(uint16_t*) &stConfigReg);
        pstRegisterData.u16Mask = 0xFFFFU;
        pstRegisterData.u8Shift = 0U;
        TIMERA__vWriteRegister(&pstRegisterData);
    }
}


void TIMERA__vGetConfigExt(TIMERA_ConfigExt_t* pstConfigArg)
{
    if(0UL != (uintptr_t) pstConfigArg)
    {
        pstConfigArg->enOperationMode = TIMERA__enGetOperationMode();
        pstConfigArg->enClockDivider = TIMERA__enGetClockDivider();
        pstConfigArg->enClockSource = TIMERA__enGetClockSource();
        pstConfigArg->enInterruptEnable = TIMERA__enGetEnableInterruptSource();
        pstConfigArg->enInterruptStatus = TIMERA__enGetStatusInterruptSource();
    }
}



