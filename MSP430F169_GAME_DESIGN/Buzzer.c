/**
 *
 * @file Buzzer.c
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
 * @verbatim 17 may. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 17 may. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <Buzzer.h>
#include <DriverLib/DriverLib.h>

static void Buzzer_vTimerBaseInit(void);
static void Buzzer_vDmaInit(void);


void Buzzer__vInit(void)
{
    DAC12_CH_ConfigExt_t stDAcChannelConfig =
    {
     DAC12_enENABLE_DIS,
     DAC12_enFORMAT_UNSIGNED,
     DAC12_enMODE_HIGH_HIGH,
     DAC12_enAMPLIFIER_1x,
     DAC12_enTRIGGER_TBCRR2,
     DAC12_enRESOLUTION_8BITS,
     DAC12_enVREF_VREFP,
     DAC12_enINT_ENABLE_DIS,
     DAC12_enINT_STATUS_NOOCCUR,
    };

    GPIO__vSetConfig(GPIO_enDAC0_P66);
    Buzzer_vDmaInit();
    Buzzer_vTimerBaseInit();

    DAC12_CH__vSetConfigExt(DAC12_enCH0, &stDAcChannelConfig);
    DAC12_CH__vSetEnableConversion(DAC12_enCH0, DAC12_enENABLE_DIS);
}


static void Buzzer_vTimerBaseInit(void)
{
    TIMERB_Config_t stTIMERBGlobalConfig =
    {
     3U - 1UL, /*32.768KHz /3 = 10.922KHz*/
     TIMERB_enCLOCK_ACLK, /*32.768KHz*/
     TIMERB_enCLOCK_DIV_1, /*32.768KHz / 1  = 32.768KHz*/
     TIMERB_enMODE_STOP,
     TIMERB_enRESOLUTION_8BITS,
     TIMERB_enGROUPLOAD_INDEPENDENT,
    };

    TIMERB_Compare_ConfigExt_t stTIMERBCompare2Config =
    {
     1UL,
     TIMERB_enCC_COMPAREMODE_RESET_SET,
     TIMERB_enCC_STATE_LOW,
     TIMERB_enINT_ENABLE_DIS,
     TIMERB_enINT_STATUS_NOOCCUR,
     TIMERB_enCC_COMPARELOAD_OV,
    };
    TIMERB_CC__vSetValue(TIMERB_enCC0, 3U - 1UL);
    TIMERB_CC__vSetCompareConfigExt(TIMERB_enCC2, &stTIMERBCompare2Config);
    TIMERB__vSetConfig(&stTIMERBGlobalConfig);
}

static void Buzzer_vDmaInit(void)
{
    DMA_CH_ConfigExt_t stDMAChannelConfig =
    {
        0U,
        0U,
        DAC12_CH0_BASE + DAC12_CH_DAT_OFFSET,
        DMA_enCH_TRIGGER_DAC12_0,
        DMA_enCH_MODE_SINGLE,
        DMA_enCH_INCMODE_INCREMENT,
        DMA_enCH_INCMODE_UNCHANGED,
        DMA_enCH_DATASIZE_BYTE,
        DMA_enCH_DATASIZE_BYTE,
        DMA_enCH_SENSE_EDGE,
        DMA_enCH_ENABLE_DIS,
        DMA_enCH_ABORT_CLEAR,
        DMA_enCH_INT_ENABLE_DIS,
        DMA_enCH_INT_STATUS_NOOCCUR,
    };

    DMA_Config_t stDMAGlobalConfig =
    {
     DMA_enENABLE_DIS,
     DMA_enPRIORITY_STATIC,
     DMA_enFETCH_NEXT,
    };

    DMA__vSetConfig(&stDMAGlobalConfig);
    DMA_CH__vSetConfigExt(DMA_enCH2, &stDMAChannelConfig);
}

void Buzzer__vPlaySound(const uint8_t *pu8SoundToPlay, uint16_t u16SoundSize)
{
    TIMERB->CTL_bits.MC = TIMERB_CTL_MC_STOP;
    TIMERB->CTL_bits.CLR = TIMERB_CTL_CLR_CLEAR;

    DAC12->CH_CTL_bits[0U].ENC = DAC12_CH_CTL_ENC_OFF;
    DAC12->CH_CTL_bits[0U].IFG = DAC12_CH_CTL_IFG_NOOCCUR;

    DMA->CH[2U].CTL_bits.EN = DMA_CH_CTL_EN_DIS;

    DMA->CH[2U].SZ = u16SoundSize;
    DMA->CH[2U].SA = (uint16_t) pu8SoundToPlay;
    DMA->CH[2U].CTL_bits.EN = DMA_CH_CTL_EN_ENA;

    DAC12->CH_CTL_bits[0U].ENC = DAC12_CH_CTL_ENC_ON;
    DAC12->CH_CTL_bits[0U].IFG = DAC12_CH_CTL_IFG_OCCUR;

    TIMERB->CTL_bits.MC = TIMERB_CTL_MC_UP;
}


