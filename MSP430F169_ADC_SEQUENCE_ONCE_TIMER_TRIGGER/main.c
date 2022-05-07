#include "DriverLib/DriverLib.h"

uint16_t MAIN_u16ADCConversionComplete(uintptr_t uptrBlock, uint16_t u16Conversion);
void MAIN_vClockInit(void);
void MAIN_vADCInit(void);
void MAIN_vTIMERA1Init(void);

uint16_t u16LDRValue = 0U;
uint16_t u16LM35Value = 0U;
uint16_t u16POTValue = 0U;

void main(void)
{
    WDT__vSetEnable(WDT_enENABLE_STOP);
    MAIN_vClockInit();
    MAIN_vTIMERA1Init();
    MAIN_vADCInit();
    _EINT();
	while(1U)
	{

	}
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
        ADC12_enMODE_SEQUENCE,
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

    ADC12_CH__vRegisterIRQSourceHandler(ADC12_enCH2, &MAIN_u16ADCConversionComplete);
    ADC12_CH__vSetConfigExt(ADC12_enCH0, &stADCChannelConfig);
    stADCChannelConfig.enInputConversion = ADC12_enINPUT_A1;
    ADC12_CH__vSetConfigExt(ADC12_enCH1, &stADCChannelConfig);
    stADCChannelConfig.enInputConversion = ADC12_enINPUT_A2;
    stADCChannelConfig.enInterruptEnable = ADC12_enINT_ENABLE_ENA;
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

    u16LDRValue = ADC12_CH0->MEM;
    u16POTValue = ADC12_CH1->MEM;
    u16LM35Value = u16Conversion;
    ADC12->CTL0_bits.ENC = 0U;
    ADC12->CTL0_bits.ENC = 1U;
    return (0xFFU);
}

