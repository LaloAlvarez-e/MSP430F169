/**
 *
 * @file DMA_Channel.c
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
#include <DriverLib/DMA/Driver/Channel/DMA_Channel.h>

#include "DriverLib/DMA/Driver/Intrinsics/DMA_Intrinsics.h"
#include "DriverLib/DMA/Peripheral/DMA_Peripheral.h"

void DMA__vSetChannelConfig(DMA_nCH enChannelArg,
                            DMA_CH_Config_t* pstConfigArg)
{
    DMA_CH_CTL_t stConfigReg = {0};
    DMA_Register_t pstRegisterData;
    if(0UL != (uintptr_t) pstConfigArg)
    {
        DMA__vSetEnable(enChannelArg, DMA_enCH_ENABLE_DIS);
        DMA__vSetTrigger(enChannelArg, pstConfigArg->enTrigger);
        DMA__vSetTransferSize(enChannelArg, pstConfigArg->u16TranferSize);
        DMA__vSetSourceAddress(enChannelArg, pstConfigArg->u16SourceAddress);
        DMA__vSetDestAddress(enChannelArg, pstConfigArg->u16DestAddress);


        stConfigReg.DT = (uint16_t) pstConfigArg->enTransferMode;
        stConfigReg.DSTINCR = (uint16_t) pstConfigArg->enDestIncMode;
        stConfigReg.SRCINCR = (uint16_t) pstConfigArg->enSourceIncMode;
        stConfigReg.DSTBYTE = (uint16_t) pstConfigArg->enDestDataSize;
        stConfigReg.SRCBYTE = (uint16_t) pstConfigArg->enSourceDataSize;
        stConfigReg.LEVEL = (uint16_t) pstConfigArg->enSense;
        stConfigReg.EN = (uint16_t) pstConfigArg->enEnable;
        stConfigReg.ABORT = (uint16_t) pstConfigArg->enAbort;

        pstRegisterData.uptrAddress = DMA_CH_CTL_OFFSET;
        pstRegisterData.u16Value = (*(uint16_t*) &stConfigReg);
        pstRegisterData.u16Mask = DMA_CH_CTL_R_DT_MASK |
                                  DMA_CH_CTL_R_DSTINCR_MASK |
                                  DMA_CH_CTL_R_SRCINCR_MASK |
                                  DMA_CH_CTL_R_DSTBYTE_MASK |
                                  DMA_CH_CTL_R_SRCBYTE_MASK |
                                  DMA_CH_CTL_R_LEVEL_MASK |
                                  DMA_CH_CTL_R_EN_MASK |
                                  DMA_CH_CTL_R_ABORT_MASK;
        pstRegisterData.u8Shift = 0U;
        DMA_CH__vWriteRegister(enChannelArg, &pstRegisterData);
    }
}


void DMA__vSetChannelExtendedConfig(DMA_nCH enChannelArg,
                                    DMA_CH_ConfigExt_t* pstConfigArg)
{
    DMA_CH_CTL_t stConfigReg = {0};
    DMA_Register_t pstRegisterData;
    if(0UL != (uintptr_t) pstConfigArg)
    {
        DMA__vSetEnable(enChannelArg, DMA_enCH_ENABLE_DIS);
        DMA__vSetTrigger(enChannelArg, pstConfigArg->enTrigger);
        DMA__vSetTransferSize(enChannelArg, pstConfigArg->u16TranferSize);
        DMA__vSetSourceAddress(enChannelArg, pstConfigArg->u16SourceAddress);
        DMA__vSetDestAddress(enChannelArg, pstConfigArg->u16DestAddress);

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

        pstRegisterData.uptrAddress = DMA_CH_CTL_OFFSET;
        pstRegisterData.u16Value = (*(uint16_t*) &stConfigReg);
        pstRegisterData.u16Mask = DMA_CH_CTL_R_DT_MASK |
                                  DMA_CH_CTL_R_DSTINCR_MASK |
                                  DMA_CH_CTL_R_SRCINCR_MASK |
                                  DMA_CH_CTL_R_DSTBYTE_MASK |
                                  DMA_CH_CTL_R_SRCBYTE_MASK |
                                  DMA_CH_CTL_R_LEVEL_MASK |
                                  DMA_CH_CTL_R_EN_MASK |
                                  DMA_CH_CTL_R_IE_MASK |
                                  DMA_CH_CTL_R_IFG_MASK |
                                  DMA_CH_CTL_R_ABORT_MASK;
        pstRegisterData.u8Shift = 0U;
        DMA_CH__vWriteRegister(enChannelArg, &pstRegisterData);
    }
}

void DMA__vGetChannelConfig(DMA_nCH enChannelArg,
                            DMA_CH_Config_t* pstConfigArg)
{
    if(0UL != (uintptr_t) pstConfigArg)
    {
        pstConfigArg->enTrigger = DMA__enGetTrigger(enChannelArg);
        pstConfigArg->u16TranferSize = DMA__u16GetTransferSize(enChannelArg);
        pstConfigArg->u16SourceAddress = DMA__u16GetSourceAddress(enChannelArg);
        pstConfigArg->u16DestAddress = DMA__u16GetDestAddress(enChannelArg);
        pstConfigArg->enTransferMode = DMA__enGetTransferMode(enChannelArg);
        pstConfigArg->enDestIncMode = DMA__enGetDestIncrementMode(enChannelArg);
        pstConfigArg->enSourceIncMode = DMA__enGetSourceIncrementMode(enChannelArg);
        pstConfigArg->enDestDataSize = DMA__enGetDestDataSize(enChannelArg);
        pstConfigArg->enSourceDataSize = DMA__enGetSourceDataSize(enChannelArg);
        pstConfigArg->enSense = DMA__enGetSense(enChannelArg);
        pstConfigArg->enEnable = DMA__enGetEnable(enChannelArg);
        pstConfigArg->enAbort = DMA__enGetAbort(enChannelArg);
    }
}


    void DMA__vGetChannelExtendedConfig(DMA_nCH enChannelArg,
                                DMA_CH_ConfigExt_t* pstConfigArg)
{
    if(0UL != (uintptr_t) pstConfigArg)
    {
        pstConfigArg->enTrigger = DMA__enGetTrigger(enChannelArg);
        pstConfigArg->u16TranferSize = DMA__u16GetTransferSize(enChannelArg);
        pstConfigArg->u16SourceAddress = DMA__u16GetSourceAddress(enChannelArg);
        pstConfigArg->u16DestAddress = DMA__u16GetDestAddress(enChannelArg);
        pstConfigArg->enTransferMode = DMA__enGetTransferMode(enChannelArg);
        pstConfigArg->enDestIncMode = DMA__enGetDestIncrementMode(enChannelArg);
        pstConfigArg->enSourceIncMode = DMA__enGetSourceIncrementMode(enChannelArg);
        pstConfigArg->enDestDataSize = DMA__enGetDestDataSize(enChannelArg);
        pstConfigArg->enSourceDataSize = DMA__enGetSourceDataSize(enChannelArg);
        pstConfigArg->enSense = DMA__enGetSense(enChannelArg);
        pstConfigArg->enEnable = DMA__enGetEnable(enChannelArg);
        pstConfigArg->enAbort = DMA__enGetAbort(enChannelArg);
        pstConfigArg->enInterruptEnable = DMA__enGetEnableInterruptSource(enChannelArg);
        pstConfigArg->enInterruptStatus = DMA__enGetStatusInterruptSource(enChannelArg);
    }
}



