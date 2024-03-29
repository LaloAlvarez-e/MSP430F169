#include "DriverLib/DriverLib.h"


uint16_t MAIN_u16WDTInterval(uintptr_t ptrBlock, uint16_t u16Source);
uint16_t MAIN_u16DMASoftware(uintptr_t ptrBlock, uint16_t u16Source);

#define LED1_PORT (GPIO_enPORT1)
#define LED1_PIN (GPIO_enPIN_NUMBER0)
#define LED3_PORT (GPIO_enPORT1)
#define LED3_PIN (GPIO_enPIN_NUMBER2)
#define LED4_PORT (GPIO_enPORT1)
#define LED4_PIN (GPIO_enPIN_NUMBER3)
#define TEST_PORT (GPIO_enPORT3)
#define TEST_PIN (GPIO_enPIN_NUMBER4)


uint8_t pu8BufferOut[100U] = {0U};

/**
 * main.c
 */
uint8_t u8Activate = 0U;

void main(void)
{
    uint16_t u16Iter = 0U;
    WDT_Config_t stWDTConfig =
    {
        WDT_enENABLE_RUN,
        WDT_enINT_ENABLE_ENA,
        WDT_enMODE_INTERVAL,
        WDT_enCLOCK_ACLK,
        WDT_enINTERVAL_32768,
    };

    DMA_Config_t stDMAConfig =
    {
        DMA_enENABLE_DIS,
        DMA_enPRIORITY_STATIC,
        DMA_enFETCH_NEXT,
    };

    DMA_CH_ConfigExt_t stDMAChannelConfig =
    {
        4U,
        0x1100U,
        (uint16_t) &pu8BufferOut[0U],
        DMA_enCH_TRIGGER_SW,
        DMA_enCH_MODE_SINGLE,
        DMA_enCH_INCMODE_INCREMENT,
        DMA_enCH_INCMODE_INCREMENT,
        DMA_enCH_DATASIZE_BYTE,
        DMA_enCH_DATASIZE_BYTE,
        DMA_enCH_SENSE_EDGE,
        DMA_enCH_ENABLE_ENA,
        DMA_enCH_ABORT_CLEAR,
        DMA_enCH_INT_ENABLE_ENA,
        DMA_enCH_INT_STATUS_NOOCCUR,
    };

    SVS->CTL_bits.VLD = 0U;
    WDT__vSetEnable(WDT_enENABLE_STOP); /*  stop watchdog timer*/

    GPIO__vSetDirectionByNumber(TEST_PORT, TEST_PIN, GPIO_enDIR_OUTPUT);
    GPIO__vSetSelectionByNumber(TEST_PORT, TEST_PIN, GPIO_enSEL_IO);

    /** Rosc*/
    GPIO__vSetDirectionByNumber(GPIO_enPORT2, GPIO_enPIN_NUMBER5, GPIO_enDIR_INPUT);
    GPIO__vSetSelectionByNumber(GPIO_enPORT2, GPIO_enPIN_NUMBER5, GPIO_enSEL_PERIPHERAL);


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

    WDT__vRegisterIRQSourceHandler(&MAIN_u16WDTInterval);
    WDT__vSetConfig(&stWDTConfig);


    DMA_CH__vRegisterIRQSourceHandler(DMA_enCH0, DMA_enCH_TRIGGER_SW, &MAIN_u16DMASoftware);

    DMA__vSetConfig(&stDMAConfig);
    DMA_CH__vSetConfigExt(DMA_enCH0, &stDMAChannelConfig);

    _EINT();
	while(1U)
	{
	}
}

uint16_t MAIN_u16WDTInterval(uintptr_t ptrBlock, uint16_t u16Source)
{
    static uint8_t u8Level = 1U;
    u8Level ^= 1U;
    GPIO__vSetOutputByNumber(TEST_PORT, TEST_PIN, (GPIO_nLEVEL) u8Level);
    DMA_CH__vRequestSWTransfer(DMA_enCH0);
    return (0U);
}


uint16_t MAIN_u16DMASoftware(uintptr_t ptrBlock, uint16_t u16Source)
{
    return (0U);
}

