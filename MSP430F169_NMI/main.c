#include "DriverLib/DriverLib.h"

uint16_t MAIN_u16WDTInterval(uintptr_t ptrBlock, uint8_t u8Source);

#define LED4_PORT (GPIO_enPORT1)
#define LED4_PIN (GPIO_enPIN_NUMBER3)
/**
 * main.c
 */
uint8_t u8Activate = 0U;

void main(void)
{
    uint16_t u16Iter = 0U;
    WDT_CONFIG_t stWDTConfig =
    {
     WDT_enENABLE_RUN,
     WDT_enINT_ENABLE_ENA,
     WDT_enMODE_INTERVAL,
     WDT_enCLOCK_ACLK,
     WDT_enINTERVAL_32768,
    };
    WDT__vSetEnable(WDT_enENABLE_STOP); /*  stop watchdog timer*/

    /** Rosc*/
    GPIO__vSetDirectionByNumber(GPIO_enPORT2, GPIO_enPIN_NUMBER5, GPIO_enDIR_INPUT);
    GPIO__vSetSelectionByNumber(GPIO_enPORT2, GPIO_enPIN_NUMBER5, GPIO_enSEL_PERIPHERAL);

	/**Configure DCO to max frequency ~8MHz*/
	CLOCK__vSetDCOFrequency(8000000UL, CLOCK_enRESISTOR_EXTERNAL);

    CLOCK__vSetLFXT1FrequencyMode(CLOCK_enFREQMODE_LOW);
    CLOCK__vSetXT2Enable(CLOCK_enENABLE_ENA);
	do
	{
	    CLOCK_IFG1_R &= ~ CLOCK_IFG1_R_IFG_MASK;
	    for(u16Iter = 0U; u16Iter < 4000U; u16Iter++); /*At least 50us*/
	}while(0U != (CLOCK_IFG1_R_IFG_MASK & CLOCK_IFG1_R));

    CLOCK__enSetACLKSource(CLOCK_enSOURCE_LFXT1); /*32768 Hz*/
	CLOCK__enSetMCLKSource(CLOCK_enSOURCE_DCO); /*~8 MHz*/
    CLOCK__enSetSMCLKSource(CLOCK_enSOURCE_XT2); /*8 MHz*/

    GPIO__vSetDirectionByNumber(LED4_PORT, LED4_PIN, GPIO_enDIR_OUTPUT);
    GPIO__vSetSelectionByNumber(LED4_PORT, LED4_PIN, GPIO_enSEL_IO);
    GPIO__vSetOutputByNumber(LED4_PORT, LED4_PIN, GPIO_enLEVEL_HIGH);

    WDT__vRegisterIRQSourceHandler(&MAIN_u16WDTInterval);
    WDT__vSetConfig(&stWDTConfig);

    _EINT();
	while(1U)
	{
	}
}

uint16_t MAIN_u16WDTInterval(uintptr_t ptrBlock, uint8_t u8Source)
{
    static uint8_t u8Level = 1U;
    u8Level ^= 1U;
    GPIO__vSetOutputByNumber(LED4_PORT, LED4_PIN, (GPIO_nLEVEL) u8Level);
    return (0U);
}


