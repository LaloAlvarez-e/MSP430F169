#include "DriverLib/DriverLib.h"

uint16_t ADC12_vConversionComplete(uintptr_t ptrBlock, uint16_t u16Source);


uint16_t u16ADCValue[10U] = {0U};

void main(void)
{
    ADC12_ConfigExt_t stADCConfig =
    {
        ADC12_enCH0,
        ADC12_enRATE_CONTINUOS,
        ADC12_enMODE_REPEAT_SEQUENCE,
        ADC12_enTRIGGER_TACCR1,
        ADC12_enEDGE_RISING,
        ADC12_enSAMPLEMODE_TIMER,
        ADC12_enSAMPLECYCLES_16,
        ADC12_enSAMPLECYCLES_192,
        ADC12_enCLOCK_ADC12OSC,
        ADC12_enCLOCKDIV_1,
        ADC12_enINT_ENABLE_DIS,
        ADC12_enINT_ENABLE_DIS,
    };

    ADC12_CH_ConfigExt_t stADC_CHConfig =
    {
        ADC12_enENABLE_DIS,
        ADC12_enVREFP_VCC,
        ADC12_enVREFN_GND,
        ADC12_enINPUT_A0,
        ADC12_enINT_ENABLE_DIS,
        ADC12_enINT_STATUS_NOOCCUR,
    };

    TIMERA_ConfigExt_t stTIMERAConfig =
    {
         10000U - 1U,
         TIMERA_enCLOCK_SMCLK,
         TIMERA_enCLOCK_DIV_8,
         TIMERA_enMODE_UP,
         TIMERA_enINT_ENABLE_DIS,
         TIMERA_enINT_STATUS_NOOCCUR,
    };

    TIMERA_Compare_ConfigExt_t stTIMERA_CCR1Config =
    {
        9000U - 1U,
        TIMERA_enCC_COMPAREMODE_SET_RESET,
        TIMERA_enCC_STATE_LOW,
        TIMERA_enINT_ENABLE_DIS,
        TIMERA_enINT_STATUS_NOOCCUR,
    };

    CLOCK_nINT_STATUS enClockStatus = CLOCK_enINT_STATUS_NOOCCUR;
    uint16_t u16Iter = 0U;
    WDT__vSetEnable(WDT_enENABLE_STOP);

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

    TIMERA__vSetConfigExt(&stTIMERAConfig);
    TIMERA_CC__vSetCompareConfigExt(TIMERA_enCC1, &stTIMERA_CCR1Config);

    GPIO__vSetConfig(GPIO_enA0_P60);
    GPIO__vSetConfig(GPIO_enA1_P61);
    GPIO__vSetConfig(GPIO_enA2_P62);
    ADC12_CH__vRegisterIRQSourceHandler(ADC12_enCH2, &ADC12_vConversionComplete);

    ADC12_CH__vSetConfigExt(ADC12_enCH0, &stADC_CHConfig);
    stADC_CHConfig.enInputConversion = ADC12_enINPUT_A1;
    ADC12_CH__vSetConfigExt(ADC12_enCH1, &stADC_CHConfig);
    stADC_CHConfig.enInputConversion = ADC12_enINPUT_A2;
    stADC_CHConfig.enEndOfSequence = ADC12_enENABLE_ENA;
    stADC_CHConfig.enInterruptEnable = ADC12_enINT_ENABLE_ENA;
    ADC12_CH__vSetConfigExt(ADC12_enCH2, &stADC_CHConfig);

    ADC12__vSetConfigExt(&stADCConfig);
    ADC12__vSetPowerCoreState(ADC12_enSTATE_ON);
    ADC12__vSetEnableConversion(ADC12_enENABLE_ENA);

    _EINT();
	while(1U)
	{

	}
}


uint16_t ADC12_vConversionComplete(uintptr_t ptrBlock, uint16_t u16Source)
{
    u16ADCValue[0U] = ADC12_CH0_MEM_R;
    u16ADCValue[1U] = ADC12_CH1_MEM_R;
    u16ADCValue[2U] = u16Source;
    return (0xFFU);
}
