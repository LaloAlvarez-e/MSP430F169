/**
 *
 * @file DAC12_Config.c
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
#include <DriverLib/DAC12/Driver/Global/Header/DAC12_Config.h>


#include <DriverLib/DAC12/Driver/Global/Header/DAC12_EnableConversion.h>
#include <DriverLib/DAC12/Driver/Global/Header/DAC12_ClockDivider.h>
#include <DriverLib/DAC12/Driver/Global/Header/DAC12_ClockSource.h>
#include <DriverLib/DAC12/Driver/Global/Header/DAC12_ConversionMode.h>
#include <DriverLib/DAC12/Driver/Global/Header/DAC12_ConversionRate.h>
#include <DriverLib/DAC12/Driver/Global/Header/DAC12_ConversionStartChannel.h>
#include <DriverLib/DAC12/Driver/Global/Header/DAC12_ConversionTrigger.h>
#include <DriverLib/DAC12/Driver/Global/Header/DAC12_SamplingCycles.h>
#include <DriverLib/DAC12/Driver/Global/Header/DAC12_SamplingMode.h>

#include "DriverLib/DAC12/Driver/Intrinsics/DAC12_Intrinsics.h"
#include "DriverLib/DAC12/Peripheral/DAC12_Peripheral.h"

void DAC12__vSetConfig(DAC12_Config_t* pstConfigArg)
{
    DAC12_CTL0_t stConfig0Reg = {0};
    DAC12_CTL1_t stConfig1Reg = {0};
    DAC12_Register16Bits_t pstRegisterData;
    DAC12_nENABLE enEnableReg = DAC12_enENABLE_DIS;
    if(0UL != (uintptr_t) pstConfigArg)
    {
        enEnableReg = DAC12__enGetEnableConversion();
        DAC12__vDisableConversion();

        stConfig0Reg.MSC = (uint16_t) pstConfigArg->enConversionRate;
        stConfig0Reg.SHT0 = (uint16_t) pstConfigArg->enSamplingCyclesLow;
        stConfig0Reg.SHT1 = (uint16_t) pstConfigArg->enSamplingCyclesHigh;

        pstRegisterData.uptrAddress = DAC12_CTL0_OFFSET;
        pstRegisterData.u16Value = (*(uint16_t*) &stConfig0Reg);
        pstRegisterData.u16Mask = DAC12_CTL0_R_MSC_MASK |
                                  DAC12_CTL0_R_SHT0_MASK |
                                  DAC12_CTL0_R_SHT1_MASK;
        pstRegisterData.u8Shift = 0U;
        DAC12__vWriteRegister(&pstRegisterData);


        stConfig1Reg.CONSEQ = (uint16_t) pstConfigArg->enConversionMode;
        stConfig1Reg.SHS = (uint16_t) pstConfigArg->enConversionTrigger;
        stConfig1Reg.ISSH = (uint16_t) pstConfigArg->enConversionTriggerEdge;
        stConfig1Reg.SHP = (uint16_t) pstConfigArg->enSamplingMode;
        stConfig1Reg.CSTARTADD = (uint16_t) pstConfigArg->enConversionStartChannel;
        stConfig1Reg.SSEL = (uint16_t) pstConfigArg->enClockSource;
        stConfig1Reg.DIV = (uint16_t) pstConfigArg->enClockDivider;

        pstRegisterData.uptrAddress = DAC12_CTL1_OFFSET;
        pstRegisterData.u16Value = (*(uint16_t*) &stConfig1Reg);
        pstRegisterData.u16Mask = DAC12_CTL1_R_CONSEQ_MASK |
                                DAC12_CTL1_R_SHS_MASK |
                                DAC12_CTL1_R_ISSH_MASK |
                                DAC12_CTL1_R_SHP_MASK |
                                DAC12_CTL1_R_CSTARTADD_MASK |
                                DAC12_CTL1_R_SSEL_MASK |
                                DAC12_CTL1_R_DIV_MASK;
        pstRegisterData.u8Shift = 0U;
        DAC12__vWriteRegister(&pstRegisterData);

        DAC12__vSetEnableConversion(enEnableReg);
    }
}

void DAC12__vSetConfigExt(DAC12_ConfigExt_t* pstConfigArg)
{
    DAC12_CTL0_t stConfig0Reg = {0};
    DAC12_CTL1_t stConfig1Reg = {0};
    DAC12_Register16Bits_t pstRegisterData;
    DAC12_nENABLE enEnableReg = DAC12_enENABLE_DIS;
    if(0UL != (uintptr_t) pstConfigArg)
    {
        enEnableReg = DAC12__enGetEnableConversion();
        DAC12__vDisableConversion();

        stConfig0Reg.TOVIE = (uint16_t) pstConfigArg->enTOVInterruptEnable;
        stConfig0Reg.OVIE = (uint16_t) pstConfigArg->enOVInterruptEnable;
        stConfig0Reg.MSC = (uint16_t) pstConfigArg->enConversionRate;
        stConfig0Reg.SHT0 = (uint16_t) pstConfigArg->enSamplingCyclesLow;
        stConfig0Reg.SHT1 = (uint16_t) pstConfigArg->enSamplingCyclesHigh;

        pstRegisterData.uptrAddress = DAC12_CTL0_OFFSET;
        pstRegisterData.u16Value = (*(uint16_t*) &stConfig0Reg);
        pstRegisterData.u16Mask = DAC12_CTL0_R_MSC_MASK |
                                  DAC12_CTL0_R_SHT0_MASK |
                                  DAC12_CTL0_R_SHT1_MASK|
                                  DAC12_CTL0_R_OVIE_MASK|
                                  DAC12_CTL0_R_TOVIE_MASK;
        pstRegisterData.u8Shift = 0U;
        DAC12__vWriteRegister(&pstRegisterData);


        stConfig1Reg.CONSEQ = (uint16_t) pstConfigArg->enConversionMode;
        stConfig1Reg.SHS = (uint16_t) pstConfigArg->enConversionTrigger;
        stConfig1Reg.ISSH = (uint16_t) pstConfigArg->enConversionTriggerEdge;
        stConfig1Reg.SHP = (uint16_t) pstConfigArg->enSamplingMode;
        stConfig1Reg.CSTARTADD = (uint16_t) pstConfigArg->enConversionStartChannel;
        stConfig1Reg.SSEL = (uint16_t) pstConfigArg->enClockSource;
        stConfig1Reg.DIV = (uint16_t) pstConfigArg->enClockDivider;

        pstRegisterData.uptrAddress = DAC12_CTL1_OFFSET;
        pstRegisterData.u16Value = (*(uint16_t*) &stConfig1Reg);
        pstRegisterData.u16Mask = DAC12_CTL1_R_CONSEQ_MASK |
                                DAC12_CTL1_R_SHS_MASK |
                                DAC12_CTL1_R_ISSH_MASK |
                                DAC12_CTL1_R_SHP_MASK |
                                DAC12_CTL1_R_CSTARTADD_MASK |
                                DAC12_CTL1_R_SSEL_MASK |
                                DAC12_CTL1_R_DIV_MASK;
        pstRegisterData.u8Shift = 0U;
        DAC12__vWriteRegister(&pstRegisterData);

        DAC12__vSetEnableConversion(enEnableReg);
    }
}

void DAC12__vGetConfig(DAC12_Config_t* pstConfigArg)
{
    if(0UL != (uintptr_t) pstConfigArg)
    {
        pstConfigArg->enClockDivider = DAC12__enGetClockDivider();
        pstConfigArg->enClockSource= DAC12__enGetClockSource();
        pstConfigArg->enConversionMode = DAC12__enGetConversionMode();
        pstConfigArg->enConversionRate = DAC12__enGetConversionRate();
        pstConfigArg->enConversionStartChannel = DAC12__enGetConversionStartChannel();
        pstConfigArg->enConversionTrigger = DAC12__enGetConversionTrigger();
        pstConfigArg->enConversionTriggerEdge = DAC12__enGetConversionTriggerEdge();
        pstConfigArg->enSamplingCyclesHigh = DAC12__enGetTimerSamplingCycles_HighChannels();
        pstConfigArg->enSamplingCyclesLow = DAC12__enGetTimerSamplingCycles_LowChannels();
        pstConfigArg->enSamplingMode = DAC12__enGetSamplingMode();
    }
}


void DAC12__vGetConfigExt(DAC12_ConfigExt_t* pstConfigArg)
{
    if(0UL != (uintptr_t) pstConfigArg)
    {
        pstConfigArg->enClockDivider = DAC12__enGetClockDivider();
        pstConfigArg->enClockSource= DAC12__enGetClockSource();
        pstConfigArg->enConversionMode = DAC12__enGetConversionMode();
        pstConfigArg->enConversionRate = DAC12__enGetConversionRate();
        pstConfigArg->enConversionStartChannel = DAC12__enGetConversionStartChannel();
        pstConfigArg->enConversionTrigger = DAC12__enGetConversionTrigger();
        pstConfigArg->enConversionTriggerEdge = DAC12__enGetConversionTriggerEdge();
        pstConfigArg->enSamplingCyclesHigh = DAC12__enGetTimerSamplingCycles_HighChannels();
        pstConfigArg->enSamplingCyclesLow = DAC12__enGetTimerSamplingCycles_LowChannels();
        pstConfigArg->enSamplingMode = DAC12__enGetSamplingMode();
        pstConfigArg->enOVInterruptEnable = DAC12__enGetEnableInterruptSource(DAC12_enINTERRUPT_OV);
        pstConfigArg->enTOVInterruptEnable = DAC12__enGetEnableInterruptSource(DAC12_enINTERRUPT_TOV);
    }
}

