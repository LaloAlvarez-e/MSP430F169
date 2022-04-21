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

void ADC12__vSetChannelConfig(ADC12_nCH enChannelArg,
                            ADC12_CH_Config_t* pstConfigArg)
{
    ADC12_CH_CTL_t stConfigReg = {0};
    ADC12_Register16Bits_t pstRegisterData;
    if(0UL != (uintptr_t) pstConfigArg)
    {
        ADC12__vSetEnable(enChannelArg, ADC12_enCH_ENABLE_DIS);
        ADC12__vSetTrigger(enChannelArg, pstConfigArg->enTrigger);
        ADC12__vSetTransferSize(enChannelArg, pstConfigArg->u16TranferSize);
        ADC12__vSetSourceAddress(enChannelArg, pstConfigArg->u16SourceAddress);
        ADC12__vSetDestAddress(enChannelArg, pstConfigArg->u16DestAddress);


        stConfigReg.DT = (uint16_t) pstConfigArg->enTransferMode;
        stConfigReg.DSTINCR = (uint16_t) pstConfigArg->enDestIncMode;
        stConfigReg.SRCINCR = (uint16_t) pstConfigArg->enSourceIncMode;
        stConfigReg.DSTBYTE = (uint16_t) pstConfigArg->enDestDataSize;
        stConfigReg.SRCBYTE = (uint16_t) pstConfigArg->enSourceDataSize;
        stConfigReg.LEVEL = (uint16_t) pstConfigArg->enSense;
        stConfigReg.EN = (uint16_t) pstConfigArg->enEnable;
        stConfigReg.ABORT = (uint16_t) pstConfigArg->enAbort;

        pstRegisterData.uptrAddress = ADC12_CH_CTL_OFFSET;
        pstRegisterData.u16Value = (*(uint16_t*) &stConfigReg);
        pstRegisterData.u16Mask = ADC12_CH_CTL_R_DT_MASK |
                                  ADC12_CH_CTL_R_DSTINCR_MASK |
                                  ADC12_CH_CTL_R_SRCINCR_MASK |
                                  ADC12_CH_CTL_R_DSTBYTE_MASK |
                                  ADC12_CH_CTL_R_SRCBYTE_MASK |
                                  ADC12_CH_CTL_R_LEVEL_MASK |
                                  ADC12_CH_CTL_R_EN_MASK |
                                  ADC12_CH_CTL_R_ABORT_MASK;
        pstRegisterData.u8Shift = 0U;
        ADC12_CH__vWriteRegister_16bits(enChannelArg, &pstRegisterData);
    }
}


void ADC12__vSetChannelExtendedConfig(ADC12_nCH enChannelArg,
                                    ADC12_CH_ConfigExt_t* pstConfigArg)
{
    ADC12_CH_CTL_t stConfigReg = {0};
    ADC12_Register16Bits_t pstRegisterData;
    if(0UL != (uintptr_t) pstConfigArg)
    {
        ADC12__vSetEnable(enChannelArg, ADC12_enCH_ENABLE_DIS);
        ADC12__vSetTrigger(enChannelArg, pstConfigArg->enTrigger);
        ADC12__vSetTransferSize(enChannelArg, pstConfigArg->u16TranferSize);
        ADC12__vSetSourceAddress(enChannelArg, pstConfigArg->u16SourceAddress);
        ADC12__vSetDestAddress(enChannelArg, pstConfigArg->u16DestAddress);

        stConfigReg.DT = (uint16_t) pstConfigArg->enTransferMode;
        stConfigReg.DSTINCR = (uint16_t) pstConfigArg->enDestIncMode;
        stConfigReg.SRCINCR = (uint16_t) pstConfigArg->enSourceIncMode;
        stConfigReg.DSTBYTE = (uint16_t) pstConfigArg->enDestDataSize;
        stConfigReg.SRCBYTE = (uint16_t) pstConfigArg->enSourceDataSize;
        stConfigReg.LEVEL = (uint16_t) pstConfigArg->enSense;
        stConfigReg.EN = (uint16_t) pstConfigArg->enEnable;
        stConfigReg.IE = (uint16_t) pstConfigArg->enInterruptEnable;
        stConfigReg.IFG = (uint16_t) pstConfigArg->enInterruptStatus;
        stConfigReg.ABORT = (uint16_t) pstConfigArg->enAbort;

        pstRegisterData.uptrAddress = ADC12_CH_CTL_OFFSET;
        pstRegisterData.u16Value = (*(uint16_t*) &stConfigReg);
        pstRegisterData.u16Mask = ADC12_CH_CTL_R_DT_MASK |
                                  ADC12_CH_CTL_R_DSTINCR_MASK |
                                  ADC12_CH_CTL_R_SRCINCR_MASK |
                                  ADC12_CH_CTL_R_DSTBYTE_MASK |
                                  ADC12_CH_CTL_R_SRCBYTE_MASK |
                                  ADC12_CH_CTL_R_LEVEL_MASK |
                                  ADC12_CH_CTL_R_EN_MASK |
                                  ADC12_CH_CTL_R_IE_MASK |
                                  ADC12_CH_CTL_R_IFG_MASK |
                                  ADC12_CH_CTL_R_ABORT_MASK;
        pstRegisterData.u8Shift = 0U;
        ADC12_CH__vWriteRegister_16bits(enChannelArg, &pstRegisterData);
    }
}

void ADC12__vGetChannelConfig(ADC12_nCH enChannelArg,
                            ADC12_CH_Config_t* pstConfigArg)
{
    if(0UL != (uintptr_t) pstConfigArg)
    {
        pstConfigArg->enTrigger = ADC12__enGetTrigger(enChannelArg);
        pstConfigArg->u16TranferSize = ADC12__u16GetTransferSize(enChannelArg);
        pstConfigArg->u16SourceAddress = ADC12__u16GetSourceAddress(enChannelArg);
        pstConfigArg->u16DestAddress = ADC12__u16GetDestAddress(enChannelArg);
        pstConfigArg->enTransferMode = ADC12__enGetTransferMode(enChannelArg);
        pstConfigArg->enDestIncMode = ADC12__enGetDestIncrementMode(enChannelArg);
        pstConfigArg->enSourceIncMode = ADC12__enGetSourceIncrementMode(enChannelArg);
        pstConfigArg->enDestDataSize = ADC12__enGetDestDataSize(enChannelArg);
        pstConfigArg->enSourceDataSize = ADC12__enGetSourceDataSize(enChannelArg);
        pstConfigArg->enSense = ADC12__enGetSense(enChannelArg);
        pstConfigArg->enEnable = ADC12__enGetEnable(enChannelArg);
        pstConfigArg->enAbort = ADC12__enGetAbort(enChannelArg);
    }
}


    void ADC12__vGetChannelExtendedConfig(ADC12_nCH enChannelArg,
                                ADC12_CH_ConfigExt_t* pstConfigArg)
{
    if(0UL != (uintptr_t) pstConfigArg)
    {
        pstConfigArg->enTrigger = ADC12__enGetTrigger(enChannelArg);
        pstConfigArg->u16TranferSize = ADC12__u16GetTransferSize(enChannelArg);
        pstConfigArg->u16SourceAddress = ADC12__u16GetSourceAddress(enChannelArg);
        pstConfigArg->u16DestAddress = ADC12__u16GetDestAddress(enChannelArg);
        pstConfigArg->enTransferMode = ADC12__enGetTransferMode(enChannelArg);
        pstConfigArg->enDestIncMode = ADC12__enGetDestIncrementMode(enChannelArg);
        pstConfigArg->enSourceIncMode = ADC12__enGetSourceIncrementMode(enChannelArg);
        pstConfigArg->enDestDataSize = ADC12__enGetDestDataSize(enChannelArg);
        pstConfigArg->enSourceDataSize = ADC12__enGetSourceDataSize(enChannelArg);
        pstConfigArg->enSense = ADC12__enGetSense(enChannelArg);
        pstConfigArg->enEnable = ADC12__enGetEnable(enChannelArg);
        pstConfigArg->enAbort = ADC12__enGetAbort(enChannelArg);
        pstConfigArg->enInterruptEnable = ADC12__enGetEnableInterruptSource(enChannelArg);
        pstConfigArg->enInterruptStatus = ADC12__enGetStatusInterruptSource(enChannelArg);
    }
}



