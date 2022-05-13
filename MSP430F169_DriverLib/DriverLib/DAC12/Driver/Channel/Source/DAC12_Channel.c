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
    DAC12_Register_t pstRegisterData;
    DAC12_nENABLE enEnableReg = DAC12_enENABLE_DIS;
    DAC12_nENABLE enCalibReg = DAC12_enENABLE_DIS;
    if(0UL != (uintptr_t) pstConfigArg)
    {
        enEnableReg = DAC12_CH__enGetEnableConversion(enChannelArg);
        DAC12_CH__vDisableConversion(enChannelArg);

        stConfigReg.GRP = (uint16_t) pstConfigArg->enGroupMode;
        stConfigReg.DF = (uint16_t) pstConfigArg->enDataFormat;
        stConfigReg.AMP = (uint16_t) pstConfigArg->enMode;
        stConfigReg.IR = (uint16_t) pstConfigArg->enAmplifier;
        stConfigReg.LSEL = (uint16_t) pstConfigArg->enTrigger;
        stConfigReg.RES = (uint16_t) pstConfigArg->enResolution;
        stConfigReg.SREF = (uint16_t) (pstConfigArg->enVoltageReference << 1U);

        pstRegisterData.uptrAddress = DAC12_CH_CTL_OFFSET;
        pstRegisterData.u16Value = (*(uint16_t*) &stConfigReg);
        pstRegisterData.u16Mask = DAC12_CH_CTL_R_GRP_MASK|
                                  DAC12_CH_CTL_R_DF_MASK|
                                  DAC12_CH_CTL_R_AMP_MASK|
                                  DAC12_CH_CTL_R_IR_MASK|
                                  DAC12_CH_CTL_R_LSEL_MASK|
                                  DAC12_CH_CTL_R_RES_MASK|
                                  DAC12_CH_CTL_R_SREF_MASK;
        pstRegisterData.u8Shift = 0U;
        DAC12_CH__vWriteRegister(enChannelArg, &pstRegisterData);

        DAC12_CH__vStartCalibration(enChannelArg);
        do
        {
            enCalibReg = DAC12_CH__enGetCalibrationStatus(enChannelArg);
        }while(DAC12_enENABLE_ENA == enCalibReg);

        DAC12_CH__vSetEnableConversion(enChannelArg, enEnableReg);
    }
}


void DAC12_CH__vSetConfigExt(DAC12_nCH enChannelArg,
                             DAC12_CH_ConfigExt_t* pstConfigArg)
{
    DAC12_CH_CTL_t stConfigReg = {0};
    DAC12_Register_t pstRegisterData;
    DAC12_nENABLE enEnableReg = DAC12_enENABLE_DIS;
    DAC12_nENABLE enCalibReg = DAC12_enENABLE_DIS;
    if(0UL != (uintptr_t) pstConfigArg)
    {
        enEnableReg = DAC12_CH__enGetEnableConversion(enChannelArg);
        DAC12_CH__vDisableConversion(enChannelArg);

        stConfigReg.GRP = (uint16_t) pstConfigArg->enGroupMode;
        stConfigReg.DF = (uint16_t) pstConfigArg->enDataFormat;
        stConfigReg.AMP = (uint16_t) pstConfigArg->enMode;
        stConfigReg.IR = (uint16_t) pstConfigArg->enAmplifier;
        stConfigReg.LSEL = (uint16_t) pstConfigArg->enTrigger;
        stConfigReg.RES = (uint16_t) pstConfigArg->enResolution;
        stConfigReg.SREF = (uint16_t) (pstConfigArg->enVoltageReference << 1U);
        stConfigReg.IE = (uint16_t) pstConfigArg->enInterruptEnable;
        stConfigReg.IFG = (uint16_t) pstConfigArg->enInterruptStatus;

        pstRegisterData.uptrAddress = DAC12_CH_CTL_OFFSET;
        pstRegisterData.u16Value = (*(uint16_t*) &stConfigReg);
        pstRegisterData.u16Mask = DAC12_CH_CTL_R_GRP_MASK|
                                  DAC12_CH_CTL_R_DF_MASK|
                                  DAC12_CH_CTL_R_IFG_MASK|
                                  DAC12_CH_CTL_R_IE_MASK|
                                  DAC12_CH_CTL_R_AMP_MASK|
                                  DAC12_CH_CTL_R_IR_MASK|
                                  DAC12_CH_CTL_R_LSEL_MASK|
                                  DAC12_CH_CTL_R_RES_MASK|
                                  DAC12_CH_CTL_R_SREF_MASK;
        pstRegisterData.u8Shift = 0U;
        DAC12_CH__vWriteRegister(enChannelArg, &pstRegisterData);

        DAC12_CH__vStartCalibration(enChannelArg);
        do
        {
            enCalibReg = DAC12_CH__enGetCalibrationStatus(enChannelArg);
        }while(DAC12_enENABLE_ENA == enCalibReg);

        DAC12_CH__vSetEnableConversion(enChannelArg, enEnableReg);
    }
}

void DAC12_CH__vGetConfig(DAC12_nCH enChannelArg,
                          DAC12_CH_Config_t* pstConfigArg)
{
    if(0UL != (uintptr_t) pstConfigArg)
    {

        pstConfigArg->enGroupMode = DAC12_CH__enGetGroupMode(enChannelArg);
        pstConfigArg->enDataFormat = DAC12_CH__enGetDataFormat(enChannelArg);
        pstConfigArg->enMode = DAC12_CH__enGetMode(enChannelArg);
        pstConfigArg->enAmplifier = DAC12_CH__enGetAmplifier(enChannelArg);
        pstConfigArg->enTrigger = DAC12_CH__enGetTrigger(enChannelArg);
        pstConfigArg->enResolution = DAC12_CH__enGetResolution(enChannelArg);
        pstConfigArg->enVoltageReference = DAC12_CH__enGetVoltageRef(enChannelArg);
    }
}


void DAC12_CH__vGetConfigExt(DAC12_nCH enChannelArg,
                                DAC12_CH_ConfigExt_t* pstConfigArg)
{
    if(0UL != (uintptr_t) pstConfigArg)
    {
        pstConfigArg->enGroupMode = DAC12_CH__enGetGroupMode(enChannelArg);
        pstConfigArg->enDataFormat = DAC12_CH__enGetDataFormat(enChannelArg);
        pstConfigArg->enMode = DAC12_CH__enGetMode(enChannelArg);
        pstConfigArg->enAmplifier = DAC12_CH__enGetAmplifier(enChannelArg);
        pstConfigArg->enTrigger = DAC12_CH__enGetTrigger(enChannelArg);
        pstConfigArg->enResolution = DAC12_CH__enGetResolution(enChannelArg);
        pstConfigArg->enVoltageReference = DAC12_CH__enGetVoltageRef(enChannelArg);
        pstConfigArg->enInterruptEnable = DAC12_CH__enGetEnableInterruptSource(enChannelArg);
        pstConfigArg->enInterruptStatus =  DAC12_CH__enGetStatusInterruptSource(enChannelArg);
    }
}



