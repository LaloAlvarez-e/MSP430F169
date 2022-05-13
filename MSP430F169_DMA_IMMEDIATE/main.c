#include "DriverLib/DriverLib.h"

uint16_t MAIN_u16DACConversionComplete(uintptr_t uptrBlock, uint16_t u16Conversion);
void MAIN_vClockInit(void);
void MAIN_vDACInit(void);
void MAIN_vTIMERA1Init(void);
void MAIN_vDMAInit(void);

void main(void)

{
    WDT__vSetEnable(WDT_enENABLE_STOP);
    MAIN_vClockInit();
    MAIN_vDMAInit();
    MAIN_vDACInit();
    MAIN_vTIMERA1Init();
    _EINT();
 	while(1U)
	{
	}
}

void MAIN_vDMAInit(void)
{
    DMA_Config_t stDMAGlobalConfig =
    {
     DMA_enENABLE_DIS,
     DMA_enPRIORITY_STATIC,
     DMA_enFETCH_NEXT,
    };

    DMA_CH_ConfigExt_t stDMAChannelConfig =
    {
     32U,
     (uint16_t) u16SinLUT,
     DAC12_CH0_BASE + DAC12_CH_DAT_OFFSET,
     DMA_enCH_TRIGGER_DAC12_0,
     DMA_enCH_MODE_REPEAT_SINGLE,
     DMA_enCH_INCMODE_INCREMENT,
     DMA_enCH_INCMODE_UNCHANGED,
     DMA_enCH_DATASIZE_WORD,
     DMA_enCH_DATASIZE_WORD,
     DMA_enCH_SENSE_EDGE,
     DMA_enCH_ENABLE_ENA,
     DMA_enCH_ABORT_CLEAR,
     DMA_enCH_INT_ENABLE_DIS,
     DMA_enCH_INT_STATUS_NOOCCUR,
    };

    DMA__vSetConfig(&stDMAGlobalConfig);
    DMA_CH__vSetConfigExt(DMA_enCH0, &stDMAChannelConfig);
    stDMAChannelConfig.u16DestAddress = DAC12_CH1_BASE + DAC12_CH_DAT_OFFSET;
    stDMAChannelConfig.u16SourceAddress = (uint16_t) u16CosLUT;
    DMA_CH__vSetConfigExt(DMA_enCH1, &stDMAChannelConfig);
}

void MAIN_vTIMERA1Init(void)
{
    TIMERA_Config_t stTIMERAGlobalConfig =
    {
     250UL - 1UL,
     TIMERA_enCLOCK_SMCLK, /*8MHz*/
     TIMERA_enCLOCK_DIV_1, /*8MHz / 8  = 1MHz*/
     TIMERA_enMODE_UP,
    };

    TIMERA_Compare_Config_t stTIMERACompare1Config =
    {
     1UL,
     TIMERA_enCC_COMPAREMODE_RESET_SET,
     TIMERA_enCC_STATE_LOW,
    };

    TIMERA_CC__vSetCompareConfig(TIMERA_enCC1, &stTIMERACompare1Config);
    TIMERA__vSetConfig(&stTIMERAGlobalConfig);
}


void MAIN_vDACInit(void)
{
    DAC12_CH_ConfigExt_t stDACChannelConfig =
    {
     DAC12_enENABLE_ENA,
     DAC12_enFORMAT_UNSIGNED,
     DAC12_enMODE_HIGH_HIGH,
     DAC12_enAMPLIFIER_1x,
     DAC12_enTRIGGER_TACCR1,
     DAC12_enRESOLUTION_12BITS,
     DAC12_enVREF_VeREFP,
     DAC12_enINT_ENABLE_DIS,
     DAC12_enINT_STATUS_NOOCCUR,
    };

    GPIO__vSetConfig(GPIO_enDAC0_P66);
    GPIO__vSetConfig(GPIO_enDAC1_P67);

    ADC12__vSetVREFValue(ADC12_enVREF_2_5V);
    ADC12__vSetVREFState(ADC12_enSTATE_ON);

    DAC12_CH__vSetConfigExt(DAC12_enCH0, &stDACChannelConfig);
    DAC12_CH__vSetConfigExt(DAC12_enCH1, &stDACChannelConfig);
    DAC12_CH__vSetEnableConversion(DAC12_enCH0, DAC12_enENABLE_ENA);
    DAC12_CH__vSetEnableConversion(DAC12_enCH1, DAC12_enENABLE_ENA);

    DAC12_CH__vSetStatusInterruptSource(DAC12_enCH0, DAC12_enINT_STATUS_OCCUR);
}

void MAIN_vClockInit(void)
{
    CLOCK_nINT_STATUS enClockStatus = CLOCK_enINT_STATUS_NOOCCUR;
    uint16_t u16Iter = 0U;

    /** Rosc*/
    GPIO__vSetConfig(GPIO_enROSC_P25);

    CLOCK__vSetDCOFrequency(800000UL, CLOCK_enRESISTOR_EXTERNAL);
    CLOCK__vSetLFXT1FrequencyMode(CLOCK_enFREQMODE_LOW);
    CLOCK__vSetXT2Enable(CLOCK_enENABLE_ENA);
    do
    {
        CLOCK__vClearInterruptSource();
        for(u16Iter = 0U; u16Iter < 4000U; u16Iter++); /*At least 50us*/
        enClockStatus = CLOCK__enGetStatusInterruptSource();
    }while(CLOCK_enINT_STATUS_NOOCCUR != enClockStatus);

    CLOCK__enSetACLKSource(CLOCK_enSOURCE_LFXT1); /*32768 Hz*/
    CLOCK__enSetMCLKSource(CLOCK_enSOURCE_DCO); /*~8 MHz*/
    CLOCK__enSetSMCLKSource(CLOCK_enSOURCE_XT2); /*8 MHz*/
}

uint16_t MAIN_u16DACConversionComplete(uintptr_t uptrBlock, uint16_t u16Conversion)
{
    return (0xFFU);
}

