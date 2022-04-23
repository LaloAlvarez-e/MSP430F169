/**
 *
 * @file ADC12_Channel.c
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
 * @verbatim 28 mar. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 28 mar. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <DriverLib/ADC12/Driver/Channel/ADC12_Channel.h>

#include "DriverLib/ADC12/Driver/Intrinsics/ADC12_Intrinsics.h"
#include "DriverLib/ADC12/Peripheral/ADC12_Peripheral.h"

void ADC12_CH__vSetConfig(ADC12_nCH enChannelArg,
                            ADC12_CH_Config_t* pstConfigArg)
{
    ADC12_CH_CTL_t stConfigReg = {0};
    ADC12_Register8Bits_t pstRegisterData;
    if(0UL != (uintptr_t) pstConfigArg)
    {
        stConfigReg.EOS = (uint16_t) pstConfigArg->enEndOfSequence;
        stConfigReg.SREFP = (uint16_t) pstConfigArg->enVoltageRefPositive;
        stConfigReg.SREFN = (uint16_t) pstConfigArg->enVoltageRefNegative;
        stConfigReg.INCH = (uint16_t) pstConfigArg->enInputConversion;

        pstRegisterData.uptrAddress = ADC12_CH_CTL_OFFSET;
        pstRegisterData.u8Value = (*(uint8_t*) &stConfigReg);
        pstRegisterData.u8Mask = ADC12_CH_CTL_R_EOS_MASK|
                                  ADC12_CH_CTL_R_SREFP_MASK|
                                  ADC12_CH_CTL_R_SREFN_MASK|
                                  ADC12_CH_CTL_R_INCH_MASK;
        pstRegisterData.u8Shift = 0U;
        ADC12_CH__vWriteRegister_8bits(enChannelArg, &pstRegisterData);
    }
}


void ADC12_CH__vSetConfigExt(ADC12_nCH enChannelArg,
                             ADC12_CH_ConfigExt_t* pstConfigArg)
{
    ADC12_CH_CTL_t stConfigReg = {0};
    ADC12_Register8Bits_t pstRegisterData;
    if(0UL != (uintptr_t) pstConfigArg)
    {
        stConfigReg.EOS = (uint16_t) pstConfigArg->enEndOfSequence;
        stConfigReg.SREFP = (uint16_t) pstConfigArg->enVoltageRefPositive;
        stConfigReg.SREFN = (uint16_t) pstConfigArg->enVoltageRefNegative;
        stConfigReg.INCH = (uint16_t) pstConfigArg->enInputConversion;

        pstRegisterData.uptrAddress = ADC12_CH_CTL_OFFSET;
        pstRegisterData.u8Value = (*(uint8_t*) &stConfigReg);
        pstRegisterData.u8Mask = ADC12_CH_CTL_R_EOS_MASK|
                                  ADC12_CH_CTL_R_SREFP_MASK|
                                  ADC12_CH_CTL_R_SREFN_MASK|
                                  ADC12_CH_CTL_R_INCH_MASK;
        pstRegisterData.u8Shift = 0U;
        ADC12_CH__vWriteRegister_8bits(enChannelArg, &pstRegisterData);

        ADC12_CH__vSetStatusInterruptSource(enChannelArg, pstConfigArg->enInterruptStatus);
        ADC12_CH__vSetEnableInterruptSource(enChannelArg, pstConfigArg->enInterruptEnable);
    }
}

void ADC12_CH__vGetConfig(ADC12_nCH enChannelArg,
                          ADC12_CH_Config_t* pstConfigArg)
{
    if(0UL != (uintptr_t) pstConfigArg)
    {
        pstConfigArg->enEndOfSequence = ADC12_CH__enGetEndOfSequence(enChannelArg);
        pstConfigArg->enVoltageRefPositive = ADC12_CH__enGetVoltageRefPositive(enChannelArg);
        pstConfigArg->enVoltageRefNegative = ADC12_CH__enGetVoltageRefNegative(enChannelArg);
        pstConfigArg->enInputConversion = ADC12_CH__enGetInputConversion(enChannelArg);
    }
}


void ADC12_CH__vGetConfigExt(ADC12_nCH enChannelArg,
                                ADC12_CH_ConfigExt_t* pstConfigArg)
{
    if(0UL != (uintptr_t) pstConfigArg)
    {
        pstConfigArg->enEndOfSequence = ADC12_CH__enGetEndOfSequence(enChannelArg);
        pstConfigArg->enVoltageRefPositive = ADC12_CH__enGetVoltageRefPositive(enChannelArg);
        pstConfigArg->enVoltageRefNegative = ADC12_CH__enGetVoltageRefNegative(enChannelArg);
        pstConfigArg->enInputConversion = ADC12_CH__enGetInputConversion(enChannelArg);
        pstConfigArg->enInterruptEnable = ADC12_CH__enGetEnableInterruptSource(enChannelArg);
        pstConfigArg->enInterruptStatus = ADC12_CH__enGetStatusInterruptSource(enChannelArg);

    }
}



