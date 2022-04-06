#include "DriverLib/DriverLib.h"


uint16_t MAIN_u16WDTInterval(uintptr_t ptrBlock, uint8_t u8Source);
uint16_t MAIN_u16DMASoftware(uintptr_t ptrBlock, uint8_t u8Source);

#define LED1_PORT (GPIO_enPORT1)
#define LED1_PIN (GPIO_enPIN_NUMBER0)
#define LED3_PORT (GPIO_enPORT1)
#define LED3_PIN (GPIO_enPIN_NUMBER2)
#define LED4_PORT (GPIO_enPORT1)
#define LED4_PIN (GPIO_enPIN_NUMBER3)
#define TEST_PORT (GPIO_enPORT3)
#define TEST_PIN (GPIO_enPIN_NUMBER4)

/**
 * main.c
 */
uint32_t u32FlashFreq = 0U;

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

    SVS->CTL_bits.VLD = 0U;
    WDT__vSetEnable(WDT_enENABLE_STOP); /*  stop watchdog timer*/

    GPIO__vSetDirectionByNumber(TEST_PORT, TEST_PIN, GPIO_enDIR_OUTPUT);
    GPIO__vSetSelectionByNumber(TEST_PORT, TEST_PIN, GPIO_enSEL_IO);

    /** Rosc*/
    GPIO__vSetConfig(GPIO_enROSC);

    CLOCK__vSetDCOFrequency(500000UL, CLOCK_enRESISTOR_EXTERNAL);
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

    u32FlashFreq = FLASH__u32Init(FLASH_enCLOCK_MCLK);

    _EINT();
	while(1U)
	{

	}
}

uint16_t MAIN_u16WDTInterval(uintptr_t ptrBlock, uint8_t u8Source)
{
    static uint8_t u8Level = 1U;
    u8Level ^= 1U;
    GPIO__vSetOutputByNumber(TEST_PORT, TEST_PIN, (GPIO_nLEVEL) u8Level);
    DMA__vRequestSWTransfer(DMA_enCH0);
    return (0U);
}

