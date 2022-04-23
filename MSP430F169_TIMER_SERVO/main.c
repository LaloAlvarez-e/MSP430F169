#include "DriverLib/DriverLib.h"


uint16_t MAIN_u16WDTInterval(uintptr_t ptrBlock, uint16_t u16Source);
uint16_t MAIN_u16SWITCH1(uintptr_t ptrBlock, uint16_t u16Source);

#define SWITCH1_PORT (GPIO_enPORT1)
#define SWITCH1_PIN (GPIO_enPIN_NUMBER4)

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
uint16_t u16DegreeBase = 850U;
uint16_t u16Degree = 0U;
#define MAX_DEGREE_VALUE (1200U)
#define MAX_DEGREE_PORCENTAGE (100U)
#define DEGREE_INCREASE (MAX_DEGREE_VALUE/MAX_DEGREE_PORCENTAGE)

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
        WDT_enINTERVAL_512,
    };

    TIMERA_ConfigExt_t stTIMERAConfig =
    {
        TIMERA_enCLOCK_SMCLK,
        TIMERA_enCLOCK_DIV_8,
        TIMERA_enMODE_UP,
        TIMERA_enINT_ENABLE_DIS,
        TIMERA_enINT_STATUS_NOOCCUR,
    };

    TIMERA_Compare_ConfigExt_t stCC1Config =
    {
        u16DegreeBase - 1U,
        TIMERA_enCC_COMPAREMODE_RESET_SET,
        TIMERA_enCC_STATE_HIGH,
        TIMERA_enINT_ENABLE_DIS,
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
    GPIO__vSetDirectionByNumber(SWITCH1_PORT, SWITCH1_PIN, GPIO_enDIR_INPUT);
    GPIO__vSetSelectionByNumber(SWITCH1_PORT, SWITCH1_PIN, GPIO_enSEL_IO);
    GPIO__vSetConfig(GPIO_enTA_OUT1_P23);

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

    WDT__vRegisterIRQSourceHandler(&MAIN_u16WDTInterval);
    WDT__vSetConfig(&stWDTConfig);

    TIMERA__vSetModuleValue(TIMERA_enCC0, 20000U - 1U);
    TIMERA__vSetCompareConfigExt(TIMERA_enCC1, &stCC1Config);

    TIMERA__vSetConfigExt(&stTIMERAConfig);
    WDT_CTL_R = (WDT_CTL_R & ~WDT_CTL_R_PW_MASK) | WDT_CTL_R_PW_WRITE | WDT_CTL_R_CNTCL_CLEAR;

    GPIO__vRegisterIRQSourceHandler(SWITCH1_PORT, SWITCH1_PIN, &MAIN_u16SWITCH1);
    GPIO__vSetInterruptEdgeByNumber(SWITCH1_PORT, SWITCH1_PIN, GPIO_enINT_EDGE_FALLING);
    GPIO__vClearInterruptSourceByNumber(SWITCH1_PORT, SWITCH1_PIN);
    GPIO__vEnaInterruptSourceByNumber(SWITCH1_PORT, SWITCH1_PIN);

    _EINT();
	while(1U)
	{

	}
}

uint16_t MAIN_u16WDTInterval(uintptr_t ptrBlock, uint16_t u16Source)
{
    static int8_t s8Direction = DEGREE_INCREASE;
    static int16_t s16Degree = 0U;
    if((s16Degree >= MAX_DEGREE_VALUE) && (s8Direction == DEGREE_INCREASE))
    {
        s8Direction = (int8_t) -DEGREE_INCREASE;
    }
    else if((s16Degree == 0U) && (s8Direction == (int8_t) -DEGREE_INCREASE))
    {
        s8Direction = (int8_t) DEGREE_INCREASE;
    }
    s16Degree += s8Direction;
    u16Degree = (uint16_t) s16Degree;


    TIMERA_CC1_R_R = u16Degree + u16DegreeBase - 1U;
    u16WDTCount++;
    PORT1_OUT_R ^= PORT_OUT_R_PIN0_MASK;
    return (0U);
}

uint16_t MAIN_u16SWITCH1(uintptr_t ptrBlock, uint16_t u16Source)
{
    PORT1_OUT_R ^= PORT_OUT_R_PIN2_MASK;
    return (0U);
}


