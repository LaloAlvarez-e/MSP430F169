#include "DriverLib/DriverLib.h"

uint16_t MAIN_u16ADCConversionComplete(uintptr_t uptrBlock, uint16_t u16Conversion);
void MAIN_vClockInit(void);
void MAIN_vADCInit(void);

uint16_t u16ADCChannelValue = 0U;

void main(void)
{
    WDT__vSetEnable(WDT_enENABLE_STOP);
    MAIN_vClockInit();
    MAIN_vADCInit();
    ADC12__vRequestSWConversion();
    _EINT();
	while(1U)
	{

	}
}

void MAIN_vADCInit(void)
{
    ADC12_Config_t stADCGlobalConfig =
    {
        ADC12_enCH0,
        ADC12_enRATE_TRIGGER,
        ADC12_enMODE_SINGLE,
        ADC12_enTRIGGER_SW,
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
        ADC12_enINT_ENABLE_ENA,
        ADC12_enINT_STATUS_NOOCCUR,
    };
    GPIO__vSetConfig(GPIO_enA0_P60);
    GPIO__vSetConfig(GPIO_enA1_P61);
    GPIO__vSetConfig(GPIO_enA2_P62);

    ADC12_CH__vRegisterIRQSourceHandler(ADC12_enCH0, &MAIN_u16ADCConversionComplete);
    ADC12_CH__vSetConfigExt(ADC12_enCH0, &stADCChannelConfig);
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
    u16ADCChannelValue = u16Conversion;
    ADC12_CTL0->SC = ADC12_CTL0_SC_START;
    return (0xFFU);
}

