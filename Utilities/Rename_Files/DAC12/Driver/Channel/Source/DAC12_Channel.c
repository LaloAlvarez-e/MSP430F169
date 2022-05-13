/**
 *
 * @file DAC12_Channel.c
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
#include <DriverLib/DAC12/Driver/Channel/DAC12_Channel.h>

#include "DriverLib/DAC12/Driver/Intrinsics/DAC12_Intrinsics.h"
#include "DriverLib/DAC12/Peripheral/DAC12_Peripheral.h"

void DAC12_CH__vSetConfig(DAC12_nCH enChannelArg,
                            DAC12_CH_Config_t* pstConfigArg)
{
    DAC12_CH_CTL_t stConfigReg = {0};
    DAC12_Register8Bits_t pstRegisterData;
    if(0UL != (uintptr_t) pstConfigArg)
    {
        stConfigReg.EOS = (uint16_t) pstConfigArg->enEndOfSequence;
        stConfigReg.SREFP = (uint16_t) pstConfigArg->enVoltageRefPositive;
        stConfigReg.SREFN = (uint16_t) pstConfigArg->enVoltageRefNegative;
        stConfigReg.INCH = (uint16_t) pstConfigArg->enInputConversion;

        pstRegisterData.uptrAddress = DAC12_CH_CTL_OFFSET;
        pstRegisterData.u8Value = (*(uint8_t*) &stConfigReg);
        pstRegisterData.u8Mask = DAC12_CH_CTL_R_EOS_MASK|
                                  DAC12_CH_CTL_R_SREFP_MASK|
                                  DAC12_CH_CTL_R_SREFN_MASK|
                                  DAC12_CH_CTL_R_INCH_MASK;
        pstRegisterData.u8Shift = 0U;
        DAC12_CH__vWriteRegister_8bits(enChannelArg, &pstRegisterData);
    }
}


void DAC12_CH__vSetConfigExt(DAC12_nCH enChannelArg,
                             DAC12_CH_ConfigExt_t* pstConfigArg)
{
    DAC12_CH_CTL_t stConfigReg = {0};
    DAC12_Register8Bits_t pstRegisterData;
    if(0UL != (uintptr_t) pstConfigArg)
    {
        stConfigReg.EOS = (uint16_t) pstConfigArg->enEndOfSequence;
        stConfigReg.SREFP = (uint16_t) pstConfigArg->enVoltageRefPositive;
        stConfigReg.SREFN = (uint16_t) pstConfigArg->enVoltageRefNegative;
        stConfigReg.INCH = (uint16_t) pstConfigArg->enInputConversion;

        pstRegisterData.uptrAddress = DAC12_CH_CTL_OFFSET;
        pstRegisterData.u8Value = (*(uint8_t*) &stConfigReg);
        pstRegisterData.u8Mask = DAC12_CH_CTL_R_EOS_MASK|
                                  DAC12_CH_CTL_R_SREFP_MASK|
                                  DAC12_CH_CTL_R_SREFN_MASK|
                                  DAC12_CH_CTL_R_INCH_MASK;
        pstRegisterData.u8Shift = 0U;
        DAC12_CH__vWriteRegister_8bits(enChannelArg, &pstRegisterData);

        DAC12_CH__vSetStatusInterruptSource(enChannelArg, pstConfigArg->enInterruptStatus);
        DAC12_CH__vSetEnableInterruptSource(enChannelArg, pstConfigArg->enInterruptEnable);
    }
}

void DAC12_CH__vGetConfig(DAC12_nCH enChannelArg,
                          DAC12_CH_Config_t* pstConfigArg)
{
    if(0UL != (uintptr_t) pstConfigArg)
    {
        pstConfigArg->enEndOfSequence = DAC12_CH__enGetEndOfSequence(enChannelArg);
        pstConfigArg->enVoltageRefPositive = DAC12_CH__enGetVoltageRefPositive(enChannelArg);
        pstConfigArg->enVoltageRefNegative = DAC12_CH__enGetVoltageRefNegative(enChannelArg);
        pstConfigArg->enInputConversion = DAC12_CH__enGetInputConversion(enChannelArg);
    }
}


void DAC12_CH__vGetConfigExt(DAC12_nCH enChannelArg,
                                DAC12_CH_ConfigExt_t* pstConfigArg)
{
    if(0UL != (uintptr_t) pstConfigArg)
    {
        pstConfigArg->enEndOfSequence = DAC12_CH__enGetEndOfSequence(enChannelArg);
        pstConfigArg->enVoltageRefPositive = DAC12_CH__enGetVoltageRefPositive(enChannelArg);
        pstConfigArg->enVoltageRefNegative = DAC12_CH__enGetVoltageRefNegative(enChannelArg);
        pstConfigArg->enInputConversion = DAC12_CH__enGetInputConversion(enChannelArg);
        pstConfigArg->enInterruptEnable = DAC12_CH__enGetEnableInterruptSource(enChannelArg);
        pstConfigArg->enInterruptStatus = DAC12_CH__enGetStatusInterruptSource(enChannelArg);

    }
}



