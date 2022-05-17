#include "DriverLib/DriverLib.h"

uint16_t MAIN_u16ADCConversionComplete(uintptr_t uptrBlock, uint16_t u16Conversion);
void MAIN_vClockInit(void);
void MAIN_vDACInit(void);
void MAIN_vADCInit(void);
void MAIN_vTIMERA1Init(void);
void MAIN_vTIMERB1Init(void);
void MAIN_vDMAInit(void);

#define SIN_LUT_SIZE (32U)

static uint16_t u16ADCValue = 0U;
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
    MAIN_vADCInit();
    MAIN_vDACInit();
    MAIN_vTIMERB1Init();
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
     DMA_enCH_INT_ENABLE_DIS,
     DMA_enCH_INT_STATUS_NOOCCUR,
    };

    DMA__vSetConfig(&stDMAGlobalConfig);
    DMA_CH__vSetConfigExt(DMA_enCH0, &stDMAChannelConfig);
    stDMAChannelConfig.u16SourceAddress = (uint16_t) u16CosLUT;
    stDMAChannelConfig.u16DestAddress = DAC12_CH1_BASE + DAC12_CH_DAT_OFFSET;
    DMA_CH__vSetConfigExt(DMA_enCH1, &stDMAChannelConfig);
    stDMAChannelConfig.u16TranferSize = 1U;
    stDMAChannelConfig.u16SourceAddress = ADC12_CH0_BASE + ADC12_CH_MEM_OFFSET;
    stDMAChannelConfig.u16DestAddress = (uint16_t) &u16ADCValue;
    stDMAChannelConfig.enTrigger = DMA_enCH_TRIGGER_ADC12x;
    stDMAChannelConfig.enDestIncMode = DMA_enCH_INCMODE_UNCHANGED;
    stDMAChannelConfig.enSourceIncMode = DMA_enCH_INCMODE_UNCHANGED;
    stDMAChannelConfig.enInterruptEnable = DMA_enCH_INT_ENABLE_ENA;
    DMA_CH__vRegisterIRQSourceHandler(DMA_enCH2, DMA_enCH_TRIGGER_ADC12x, &MAIN_u16ADCConversionComplete);
    DMA_CH__vSetConfigExt(DMA_enCH2, &stDMAChannelConfig);
}

uint16_t MAIN_u16ADCConversionComplete(uintptr_t uptrBlock, uint16_t u16Conversion)
{
    uint32_t u32Period = 0U;
    u32Period = u16ADCValue;
    u32Period *= 0x10000U;
    u32Period /= 0x1000U;
    if(u32Period < 125U)
    {
        u32Period = 125;
    }
    TIMERA->CC_R[0U] = (uint16_t) u32Period;
    return (0xFF);
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
     5UL,
     TIMERA_enCC_COMPAREMODE_RESET_SET,
     TIMERA_enCC_STATE_LOW,
     TIMERA_enINT_ENABLE_DIS,
     TIMERA_enINT_STATUS_NOOCCUR,
    };

    TIMERA_CC__vSetCompareConfigExt(TIMERA_enCC1, &stTIMERACompare1Config);
    TIMERA__vSetConfig(&stTIMERAGlobalConfig);
}


void MAIN_vTIMERB1Init(void)
{
    TIMERB_Config_t stTIMERBGlobalConfig =
    {
     32768U - 1UL,
     TIMERB_enCLOCK_ACLK, /*8MHz*/
     TIMERB_enCLOCK_DIV_1, /*8MHz / 2  = 4MHz*/
     TIMERB_enMODE_UP,
     TIMERB_enRESOLUTION_16BITS,
     TIMERB_enGROUPLOAD_INDEPENDENT,
    };

    TIMERB_Compare_ConfigExt_t stTIMERBCompare1Config =
    {
     2500UL,
     TIMERB_enCC_COMPAREMODE_RESET_SET,
     TIMERB_enCC_STATE_LOW,
     TIMERB_enINT_ENABLE_DIS,
     TIMERB_enINT_STATUS_NOOCCUR,
     TIMERB_enCC_COMPARELOAD_OV,
    };

    TIMERB_CC__vSetCompareConfigExt(TIMERB_enCC1, &stTIMERBCompare1Config);
    TIMERB__vSetConfig(&stTIMERBGlobalConfig);
}

void MAIN_vADCInit(void)
{
    ADC12_Config_t stADCGlobalConfig =
    {
        ADC12_enCH0,
        ADC12_enRATE_TRIGGER,
        ADC12_enMODE_REPEAT_SINGLE,
        ADC12_enTRIGGER_TBCRR1,
        ADC12_enEDGE_RISING,
        ADC12_enSAMPLEMODE_TIMER,
        ADC12_enSAMPLECYCLES_16,
        ADC12_enSAMPLECYCLES_256,
        ADC12_enCLOCK_ADC12OSC,
        ADC12_enCLOCKDIV_1,
    };

    ADC12_CH_ConfigExt_t stADCChannelConfig =
    {
        ADC12_enENABLE_DIS,
        ADC12_enVREFP_VCC,
        ADC12_enVREFN_GND,
        ADC12_enINPUT_A0,
        ADC12_enINT_ENABLE_DIS,
        ADC12_enINT_STATUS_NOOCCUR,
    };
    GPIO__vSetConfig(GPIO_enA0_P60);

    ADC12__vSetVREFValue(ADC12_enVREF_2_5V);
    ADC12__vPowerOnVREF();

    ADC12_CH__vSetConfigExt(ADC12_enCH0, &stADCChannelConfig);
    ADC12__vSetConfig(&stADCGlobalConfig);
    ADC12__vSetPowerCoreState(ADC12_enSTATE_ON);
    ADC12__vSetEnableConversion(ADC12_enENABLE_ENA);

}

void MAIN_vDACInit(void)
{
    DAC12_CH_ConfigExt_t stDAcChannelConfig =
    {
     DAC12_enENABLE_DIS,
     DAC12_enFORMAT_UNSIGNED,
     DAC12_enMODE_HIGH_HIGH,
     DAC12_enAMPLIFIER_1x,
     DAC12_enTRIGGER_TACCR1,
     DAC12_enRESOLUTION_12BITS,
     DAC12_enVREF_VREFP,
     DAC12_enINT_ENABLE_DIS,
     DAC12_enINT_STATUS_NOOCCUR,
    };

    GPIO__vSetConfig(GPIO_enDAC0_P66);

    DAC12_CH__vSetConfigExt(DAC12_enCH0, &stDAcChannelConfig);
    DAC12_CH__vSetEnableConversion(DAC12_enCH0, DAC12_enENABLE_ENA);

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


