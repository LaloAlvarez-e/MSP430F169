#include "DriverLib/DriverLib.h"

void MAIN_vClockInit(void);
void MAIN_vDACInit(void);
void MAIN_vTIMERA1Init(void);
void MAIN_vDMAInit(void);

#define SIN_LUT_SIZE (32U)

static const uint16_t u16SinLUT[SIN_LUT_SIZE] =
{
    2048U, 2447U, 2831U, 3185U, 3495U, 3750U, 3939U, 4056U,
    4095U, 4056U, 3939U, 3750U, 3495U, 3185U, 2831U, 2447U,
    2048U, 1648U, 1264U, 910U , 600U , 345U , 156U , 39U  ,
    0U   , 39U  , 156U , 345U , 600U , 910U , 1264U, 1648U
};


static const uint16_t u16CosLUT[SIN_LUT_SIZE] =
{
    4095U, 4056U, 3939U, 3750U, 3495U, 3185U, 2831U, 2447U,
    2048U, 1648U, 1264U,  910U,  600U,  345U,  156U,   39U,
    0U   ,   39U,  156U,  345U,  600U,  910U, 1264U, 1648U,
    2048U, 2447U, 2831U, 3185U, 3495U, 3750U, 3939U, 4056U,
};



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
     SIN_LUT_SIZE,
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
     DMA_enCH_INT_ENABLE_ENA,
     DMA_enCH_INT_STATUS_NOOCCUR,
    };

    DMA__vSetConfig(&stDMAGlobalConfig);
    DMA_CH__vSetConfigExt(DMA_enCH0, &stDMAChannelConfig);
    stDMAChannelConfig.u16SourceAddress = (uint16_t) u16CosLUT;
    stDMAChannelConfig.u16DestAddress = DAC12_CH1_BASE + DAC12_CH_DAT_OFFSET;
    DMA_CH__vSetConfigExt(DMA_enCH1, &stDMAChannelConfig);
}


void MAIN_vTIMERA1Init(void)
{
    TIMERA_Config_t stTIMERAGlobalConfig =
    {
     125U - 1UL,
     TIMERA_enCLOCK_SMCLK, /*8MHz*/
     TIMERA_enCLOCK_DIV_2, /*8MHz / 2  = 4MHz*/
     TIMERA_enMODE_UP,
    };

    TIMERA_Compare_ConfigExt_t stTIMERACompare1Config =
    {
     25UL,
     TIMERA_enCC_COMPAREMODE_RESET_SET,
     TIMERA_enCC_STATE_LOW,
     TIMERA_enINT_ENABLE_ENA,
     TIMERA_enINT_STATUS_NOOCCUR,
    };

    TIMERA_CC__vSetCompareConfigExt(TIMERA_enCC1, &stTIMERACompare1Config);
    TIMERA__vSetConfig(&stTIMERAGlobalConfig);
}


void MAIN_vDACInit(void)
{
    DAC12_CH_ConfigExt_t stDAcChannelConfig =
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

    DAC12_CH__vSetConfigExt(DAC12_enCH0, &stDAcChannelConfig);
    DAC12_CH__vSetConfigExt(DAC12_enCH1, &stDAcChannelConfig);
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


