/**
 *
 * @file SlidePot.c
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
#include <SlidePot.h>
#include <DriverLib/DriverLib.h>

static uint16_t SlidePot_u16Conversion(uintptr_t uptrBlock, uint16_t u16Conversion);
static void SlidePot_vTimerBaseInit(void);

static uint16_t SlidePot_u16Value = 0U;

uint16_t SlidePort__u16GetValue(void)
{
    return (SlidePot_u16Value);
}


void SlidePot__vInit(void)
{
    ADC12_Config_t stADCGlobalConfig =
    {
        ADC12_enCH0,
        ADC12_enRATE_TRIGGER,
        ADC12_enMODE_REPEAT_SINGLE,
        ADC12_enTRIGGER_TACCR1,
        ADC12_enEDGE_RISING,
        ADC12_enSAMPLEMODE_TIMER,
        ADC12_enSAMPLECYCLES_1024,
        ADC12_enSAMPLECYCLES_1024,
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

    ADC12__vSetVREFValue(ADC12_enVREF_2_5V);
    ADC12__vPowerOnVREF();

    ADC12_CH__vRegisterIRQSourceHandler(ADC12_enCH0, &SlidePot_u16Conversion);
    ADC12_CH__vSetConfigExt(ADC12_enCH0, &stADCChannelConfig);
    ADC12__vSetConfig(&stADCGlobalConfig);
    ADC12__vSetPowerCoreState(ADC12_enSTATE_ON);
    ADC12__vSetEnableConversion(ADC12_enENABLE_ENA);
    SlidePot_vTimerBaseInit();
}

static void SlidePot_vTimerBaseInit(void)
{
    TIMERA_Config_t stTIMERAGlobalConfig =
    {
     1024U - 1UL, /*32.768KHz / 1024 = 32Hz*/
     TIMERA_enCLOCK_ACLK, /*32.768KHz*/
     TIMERA_enCLOCK_DIV_1, /*32.768KHz / 1  = 32.768KHz*/
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

static uint16_t SlidePot_u16Conversion(uintptr_t uptrBlock, uint16_t u16Conversion)
{
    uint32_t u32Value = 0U;
    u32Value = u16Conversion;
    u32Value *= 83U;
    u32Value /= 4095U;
    SlidePot_u16Value = u32Value;
    return (0xFF);
}

