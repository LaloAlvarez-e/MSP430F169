#include "DriverLib/DriverLib.h"

uint16_t MAIN_u16ADCConversionComplete(uintptr_t uptrBlock, uint16_t u16Conversion);
void MAIN_vClockInit(void);
void MAIN_vADCInit(void);
void MAIN_vTIMERA1Init(void);
void MAIN_vDMAInit(void);

uint16_t pu16ADCValue[3U] = {0U};

void main(void)
{
    WDT__vSetEnable(WDT_enENABLE_STOP);
    MAIN_vClockInit();
    MAIN_vDMAInit();
    MAIN_vTIMERA1Init();
    MAIN_vADCInit();
    _EINT();
	while(1U)
	{
	    LPM1;
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
     3U,
     ADC12_CH0_BASE + ADC12_CH_MEM_OFFSET,
     (uint16_t) &pu16ADCValue[0U],
     DMA_enCH_TRIGGER_ADC12x,
     DMA_enCH_MODE_REPEAT_BLOCK,
     DMA_enCH_INCMODE_INCREMENT,
     DMA_enCH_INCMODE_INCREMENT,
     DMA_enCH_DATASIZE_WORD,
     DMA_enCH_DATASIZE_WORD,
     DMA_enCH_SENSE_EDGE,
     DMA_enCH_ENABLE_ENA,
     DMA_enCH_ABORT_CLEAR,
     DMA_enCH_INT_ENABLE_ENA,
     DMA_enCH_INT_STATUS_NOOCCUR,
    };

    DMA_CH__vRegisterIRQSourceHandler(DMA_enCH0,
                                      DMA_enCH_TRIGGER_ADC12x,
                                      &MAIN_u16ADCConversionComplete);
    DMA__vSetConfig(&stDMAGlobalConfig);
    DMA_CH__vSetConfigExt(DMA_enCH0, &stDMAChannelConfig);
}


void MAIN_vTIMERA1Init(void)
{
    TIMERA_Config_t stTIMERAGlobalConfig =
    {
     10000UL - 1UL,
     TIMERA_enCLOCK_SMCLK, /*8MHz*/
     TIMERA_enCLOCK_DIV_8, /*8MHz / 8  = 1MHz*/
     TIMERA_enMODE_UP,
    };

    TIMERA_Compare_Config_t stTIMERACompare1Config =
    {
     1000UL,
     TIMERA_enCC_COMPAREMODE_RESET_SET,
     TIMERA_enCC_STATE_LOW,
    };

    TIMERA_CC__vSetCompareConfig(TIMERA_enCC1, &stTIMERACompare1Config);
    TIMERA__vSetConfig(&stTIMERAGlobalConfig);
}


void MAIN_vADCInit(void)
{
    ADC12_Config_t stADCGlobalConfig =
    {
        ADC12_enCH0,
        ADC12_enRATE_CONTINUOS,
        ADC12_enMODE_REPEAT_SEQUENCE,
        ADC12_enTRIGGER_TACCR1,
        ADC12_enEDGE_RISING,
        ADC12_enSAMPLEMODE_TIMER,
        ADC12_enSAMPLECYCLES_1024,
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
    GPIO__vSetConfig(GPIO_enA1_P61);
    GPIO__vSetConfig(GPIO_enA2_P62);

    ADC12_CH__vSetConfigExt(ADC12_enCH0, &stADCChannelConfig);
    stADCChannelConfig.enInputConversion = ADC12_enINPUT_A1;
    ADC12_CH__vSetConfigExt(ADC12_enCH1, &stADCChannelConfig);
    stADCChannelConfig.enInputConversion = ADC12_enINPUT_A2;
    stADCChannelConfig.enEndOfSequence = ADC12_enENABLE_ENA;
    ADC12_CH__vSetConfigExt(ADC12_enCH2, &stADCChannelConfig);
    ADC12__vSetConfig(&stADCGlobalConfig);
    ADC12__vSetPowerCoreState(ADC12_enSTATE_ON);
    ADC12__vSetEnableConversion(ADC12_enENABLE_ENA);
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

uint16_t MAIN_u16ADCConversionComplete(uintptr_t uptrBlock, uint16_t u16Conversion)
{
    return (0xFFU);
}

