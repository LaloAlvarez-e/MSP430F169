/**
 *
 * @file ADC12_Config.c
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
#include <DriverLib/ADC12/Driver/Global/Header/ADC12_Config.h>


#include <DriverLib/ADC12/Driver/Global/Header/ADC12_EnableConversion.h>
#include <DriverLib/ADC12/Driver/Global/Header/ADC12_ClockDivider.h>
#include <DriverLib/ADC12/Driver/Global/Header/ADC12_ClockSource.h>
#include <DriverLib/ADC12/Driver/Global/Header/ADC12_ConversionMode.h>
#include <DriverLib/ADC12/Driver/Global/Header/ADC12_ConversionRate.h>
#include <DriverLib/ADC12/Driver/Global/Header/ADC12_ConversionStartChannel.h>
#include <DriverLib/ADC12/Driver/Global/Header/ADC12_ConversionTrigger.h>
#include <DriverLib/ADC12/Driver/Global/Header/ADC12_SamplingCycles.h>
#include <DriverLib/ADC12/Driver/Global/Header/ADC12_SamplingMode.h>

#include "DriverLib/ADC12/Driver/Intrinsics/ADC12_Intrinsics.h"
#include "DriverLib/ADC12/Peripheral/ADC12_Peripheral.h"

void ADC12__vSetConfig(ADC12_Config_t* pstConfigArg)
{
    ADC12_CTL0_t stConfig0Reg = {0};
    ADC12_CTL1_t stConfig1Reg = {0};
    ADC12_Register16Bits_t pstRegisterData;
    ADC12_nENABLE enEnableReg = ADC12_enENABLE_DIS;
    if(0UL != (uintptr_t) pstConfigArg)
    {
        enEnableReg = ADC12__enGetEnableConversion();
        ADC12__vDisableConversion();

        stConfig0Reg.MSC = (uint16_t) pstConfigArg->enConversionRate;
        stConfig0Reg.SHT0 = (uint16_t) pstConfigArg->enSamplingCyclesLow;
        stConfig0Reg.SHT1 = (uint16_t) pstConfigArg->enSamplingCyclesHigh;

        pstRegisterData.uptrAddress = ADC12_CTL0_OFFSET;
        pstRegisterData.u16Value = (*(uint16_t*) &stConfig0Reg);
        pstRegisterData.u16Mask = ADC12_CTL0_R_MSC_MASK |
                                  ADC12_CTL0_R_SHT0_MASK |
                                  ADC12_CTL0_R_SHT1_MASK;
        pstRegisterData.u8Shift = 0U;
        ADC12__vWriteRegister(&pstRegisterData);


        stConfig1Reg.CONSEQ = (uint16_t) pstConfigArg->enConversionMode;
        stConfig1Reg.SHS = (uint16_t) pstConfigArg->enConversionTrigger;
        stConfig1Reg.ISSH = (uint16_t) pstConfigArg->enConversionTriggerEdge;
        stConfig1Reg.SHP = (uint16_t) pstConfigArg->enSamplingMode;
        stConfig1Reg.CSTARTADD = (uint16_t) pstConfigArg->enConversionStartChannel;
        stConfig1Reg.SSEL = (uint16_t) pstConfigArg->enClockSource;
        stConfig1Reg.DIV = (uint16_t) pstConfigArg->enClockDivider;

        pstRegisterData.uptrAddress = ADC12_CTL1_OFFSET;
        pstRegisterData.u16Value = (*(uint16_t*) &stConfig1Reg);
        pstRegisterData.u16Mask = ADC12_CTL1_R_CONSEQ_MASK |
                                ADC12_CTL1_R_SHS_MASK |
                                ADC12_CTL1_R_ISSH_MASK |
                                ADC12_CTL1_R_SHP_MASK |
                                ADC12_CTL1_R_CSTARTADD_MASK |
                                ADC12_CTL1_R_SSEL_MASK |
                                ADC12_CTL1_R_DIV_MASK;
        pstRegisterData.u8Shift = 0U;
        ADC12__vWriteRegister(&pstRegisterData);

        ADC12__vSetEnableConversion(enEnableReg);
    }
}

void ADC12__vSetConfigExt(ADC12_ConfigExt_t* pstConfigArg)
{
    ADC12_CTL0_t stConfig0Reg = {0};
    ADC12_CTL1_t stConfig1Reg = {0};
    ADC12_Register16Bits_t pstRegisterData;
    ADC12_nENABLE enEnableReg = ADC12_enENABLE_DIS;
    if(0UL != (uintptr_t) pstConfigArg)
    {
        enEnableReg = ADC12__enGetEnableConversion();
        ADC12__vDisableConversion();

        stConfig0Reg.MSC = (uint16_t) pstConfigArg->enConversionRate;
        stConfig0Reg.SHT0 = (uint16_t) pstConfigArg->enSamplingCyclesLow;
        stConfig0Reg.SHT1 = (uint16_t) pstConfigArg->enSamplingCyclesHigh;
        stConfig0Reg.OVIE = (uint16_t) pstConfigArg->enOVInterruptEnable;
        stConfig0Reg.TOVIE = (uint16_t) pstConfigArg->enTOVInterruptEnable;

        pstRegisterData.uptrAddress = ADC12_CTL0_OFFSET;
        pstRegisterData.u16Value = (*(uint16_t*) &stConfig0Reg);
        pstRegisterData.u16Mask = ADC12_CTL0_R_MSC_MASK |
                                  ADC12_CTL0_R_SHT0_MASK |
                                  ADC12_CTL0_R_SHT1_MASK|
                                  ADC12_CTL0_R_OVIE_MASK|
                                  ADC12_CTL0_R_TOVIE_MASK;
        pstRegisterData.u8Shift = 0U;
        ADC12__vWriteRegister(&pstRegisterData);


        stConfig1Reg.CONSEQ = (uint16_t) pstConfigArg->enConversionMode;
        stConfig1Reg.SHS = (uint16_t) pstConfigArg->enConversionTrigger;
        stConfig1Reg.ISSH = (uint16_t) pstConfigArg->enConversionTriggerEdge;
        stConfig1Reg.SHP = (uint16_t) pstConfigArg->enSamplingMode;
        stConfig1Reg.CSTARTADD = (uint16_t) pstConfigArg->enConversionStartChannel;
        stConfig1Reg.SSEL = (uint16_t) pstConfigArg->enClockSource;
        stConfig1Reg.DIV = (uint16_t) pstConfigArg->enClockDivider;

        pstRegisterData.uptrAddress = ADC12_CTL1_OFFSET;
        pstRegisterData.u16Value = (*(uint16_t*) &stConfig1Reg);
        pstRegisterData.u16Mask = ADC12_CTL1_R_CONSEQ_MASK |
                                ADC12_CTL1_R_SHS_MASK |
                                ADC12_CTL1_R_ISSH_MASK |
                                ADC12_CTL1_R_SHP_MASK |
                                ADC12_CTL1_R_CSTARTADD_MASK |
                                ADC12_CTL1_R_SSEL_MASK |
                                ADC12_CTL1_R_DIV_MASK;
        pstRegisterData.u8Shift = 0U;
        ADC12__vWriteRegister(&pstRegisterData);

        ADC12__vSetEnableConversion(enEnableReg);
    }
}

void ADC12__vGetConfig(ADC12_Config_t* pstConfigArg)
{
    if(0UL != (uintptr_t) pstConfigArg)
    {
        pstConfigArg->enClockDivider = ADC12__enGetClockDivider();
        pstConfigArg->enClockSource= ADC12__enGetClockSource();
        pstConfigArg->enConversionMode = ADC12__enGetConversionMode();
        pstConfigArg->enConversionRate = ADC12__enGetConversionRate();
        pstConfigArg->enConversionStartChannel = ADC12__enGetConversionStartChannel();
        pstConfigArg->enConversionTrigger = ADC12__enGetConversionTrigger();
        pstConfigArg->enConversionTriggerEdge = ADC12__enGetConversionTriggerEdge();
        pstConfigArg->enSamplingCyclesHigh = ADC12__enGetTimerSamplingCycles_HighChannels();
        pstConfigArg->enSamplingCyclesLow = ADC12__enGetTimerSamplingCycles_LowChannels();
        pstConfigArg->enSamplingMode = ADC12__enGetSamplingMode();
    }
}


void ADC12__vGetConfigExt(ADC12_ConfigExt_t* pstConfigArg)
{
    if(0UL != (uintptr_t) pstConfigArg)
    {
        pstConfigArg->enClockDivider = ADC12__enGetClockDivider();
        pstConfigArg->enClockSource= ADC12__enGetClockSource();
        pstConfigArg->enConversionMode = ADC12__enGetConversionMode();
        pstConfigArg->enConversionRate = ADC12__enGetConversionRate();
        pstConfigArg->enConversionStartChannel = ADC12__enGetConversionStartChannel();
        pstConfigArg->enConversionTrigger = ADC12__enGetConversionTrigger();
        pstConfigArg->enConversionTriggerEdge = ADC12__enGetConversionTriggerEdge();
        pstConfigArg->enSamplingCyclesHigh = ADC12__enGetTimerSamplingCycles_HighChannels();
        pstConfigArg->enSamplingCyclesLow = ADC12__enGetTimerSamplingCycles_LowChannels();
        pstConfigArg->enSamplingMode = ADC12__enGetSamplingMode();
        pstConfigArg->enOVInterruptEnable = ADC12__enGetEnableInterruptSource(ADC12_enINTERRUPT_OV);
        pstConfigArg->enTOVInterruptEnable = ADC12__enGetEnableInterruptSource(ADC12_enINTERRUPT_TOV);
    }
}

