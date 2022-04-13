#include "DriverLib/DriverLib.h"


uint16_t MAIN_u16WDTInterval(uintptr_t ptrBlock, uint8_t u8Source);
uint16_t MAIN_u16TIMERAInterval(uintptr_t ptrBlock, uint8_t u8Source);
uint16_t MAIN_u16TIMERA_CC0(uintptr_t ptrBlock, uint8_t u8Source);
uint16_t MAIN_u16TIMERA_CC1(uintptr_t ptrBlock, uint8_t u8Source);
uint16_t MAIN_u16TIMERA_CC2(uintptr_t ptrBlock, uint8_t u8Source);

#define LED1_PORT (GPIO_enPORT1)
#define LED1_PIN (GPIO_enPIN_NUMBER0)
#define LED2_PORT (GPIO_enPORT1)
#define LED2_PIN (GPIO_enPIN_NUMBER1)
#define LED3_PORT (GPIO_enPORT1)
#define LED3_PIN (GPIO_enPIN_NUMBER2)
#define LED4_PORT (GPIO_enPORT1)
#define LED4_PIN (GPIO_enPIN_NUMBER3)
#define TEST_PORT (GPIO_enPORT3)
#define TEST_PIN (GPIO_enPIN_NUMBER4)

/**
 * main.c
 */
uint16_t u16WDTCount = 0U;
uint16_t u16TIMERACount = 0U;
uint16_t u16TIMERA_CC0Count = 0U;
uint16_t u16TIMERA_CC1Count = 0U;
uint16_t u16TIMERA_CC2Count = 0U;

void main(void)
{
    CLOCK_nINT_STATUS enClockStatus = CLOCK_enINT_STATUS_NOOCCUR;
    uint16_t u16Iter = 0U;
    WDT_Config_t stWDTConfig =
    {
        WDT_enENABLE_RUN,
        WDT_enINT_ENABLE_ENA,
        WDT_enMODE_INTERVAL,
        WDT_enCLOCK_ACLK,
        WDT_enINTERVAL_32768,
    };

    TIMERA_ConfigExt_t stTIMERAConfig =
    {
        TIMERA_enCLOCK_SMCLK,
        TIMERA_enCLOCK_DIV_8,
        TIMERA_enMODE_CONTINUOS,
        TIMERA_enINT_ENABLE_ENA,
        TIMERA_enINT_STATUS_NOOCCUR,
    };

    SVS->CTL_bits.VLD = 0U;
    WDT__vSetEnable(WDT_enENABLE_STOP); /*  stop watchdog timer*/

    GPIO__vSetDirectionByNumber(LED1_PORT, LED1_PIN, GPIO_enDIR_OUTPUT);
    GPIO__vSetSelectionByNumber(LED1_PORT, LED1_PIN, GPIO_enSEL_IO);
    GPIO__vSetDirectionByNumber(LED2_PORT, LED2_PIN, GPIO_enDIR_OUTPUT);
    GPIO__vSetSelectionByNumber(LED2_PORT, LED2_PIN, GPIO_enSEL_IO);
    GPIO__vSetDirectionByNumber(LED3_PORT, LED3_PIN, GPIO_enDIR_OUTPUT);
    GPIO__vSetSelectionByNumber(LED3_PORT, LED3_PIN, GPIO_enSEL_IO);
    GPIO__vSetDirectionByNumber(LED4_PORT, LED4_PIN, GPIO_enDIR_OUTPUT);
    GPIO__vSetSelectionByNumber(LED4_PORT, LED4_PIN, GPIO_enSEL_IO);
    GPIO__vSetDirectionByNumber(TEST_PORT, TEST_PIN, GPIO_enDIR_OUTPUT);
    GPIO__vSetSelectionByNumber(TEST_PORT, TEST_PIN, GPIO_enSEL_IO);

    /** Rosc*/
    GPIO__vSetConfig(GPIO_enROSC);

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

    WDT__vRegisterIRQSourceHandler(&MAIN_u16WDTInterval);
    WDT__vSetConfig(&stWDTConfig);


    TIMERA__vRegisterIRQSourceHandler(&MAIN_u16TIMERAInterval);
    TIMERA_CC__vRegisterIRQSourceHandler(TIMERA_enCC0, TIMERA_enCC_MODE_COMPARE,
                                         &MAIN_u16TIMERA_CC0);
    TIMERA_CC__vRegisterIRQSourceHandler(TIMERA_enCC1, TIMERA_enCC_MODE_COMPARE,
                                         &MAIN_u16TIMERA_CC1);
    TIMERA_CC__vRegisterIRQSourceHandler(TIMERA_enCC2, TIMERA_enCC_MODE_COMPARE,
                                         &MAIN_u16TIMERA_CC2);
    TIMERA__vSetModuleValue(TIMERA_enCC0, 10000U - 1U);
    TIMERA__vSetModuleValue(TIMERA_enCC1, 20000U - 1U);
    TIMERA__vSetModuleValue(TIMERA_enCC2, 40000U - 1U);
    TIMERA_CC__vClearInterruptSource(TIMERA_enCC0);
    TIMERA_CC__vClearInterruptSource(TIMERA_enCC1);
    TIMERA_CC__vClearInterruptSource(TIMERA_enCC2);
    TIMERA_CC__vEnaInterruptSource(TIMERA_enCC0);
    TIMERA_CC__vEnaInterruptSource(TIMERA_enCC1);
    TIMERA_CC__vEnaInterruptSource(TIMERA_enCC2);
    TIMERA__vSetConfigExt(&stTIMERAConfig);
    WDT_CTL_R = (WDT_CTL_R & ~WDT_CTL_R_PW_MASK) | WDT_CTL_R_PW_WRITE | WDT_CTL_R_CNTCL_CLEAR;
    _EINT();
	while(1U)
	{

	}
}

uint16_t MAIN_u16WDTInterval(uintptr_t ptrBlock, uint8_t u8Source)
{
    u16WDTCount++;
    PORT1_OUT_R ^= PORT_OUT_R_PIN0_MASK;
    return (0U);
}

uint16_t MAIN_u16TIMERAInterval(uintptr_t ptrBlock, uint8_t u8Source)
{
    u16TIMERACount++;
    PORT3_OUT_R ^= PORT_OUT_R_PIN4_MASK;
    return (0U);
}

uint16_t MAIN_u16TIMERA_CC0(uintptr_t ptrBlock, uint8_t u8Source)
{
    u16TIMERA_CC0Count++;
    TIMERA_CC0_R_R += 10000U;
    PORT1_OUT_R ^= PORT_OUT_R_PIN1_MASK;
    return (0U);
}

uint16_t MAIN_u16TIMERA_CC1(uintptr_t ptrBlock, uint8_t u8Source)
{
    u16TIMERA_CC1Count++;
    TIMERA_CC1_R_R += 20000U;
    PORT1_OUT_R ^= PORT_OUT_R_PIN2_MASK;
    return (0U);
}

uint16_t MAIN_u16TIMERA_CC2(uintptr_t ptrBlock, uint8_t u8Source)
{
    u16TIMERA_CC2Count++;
    TIMERA_CC2_R_R += 40000U;
    PORT1_OUT_R ^= PORT_OUT_R_PIN3_MASK;
    return (0U);
}

