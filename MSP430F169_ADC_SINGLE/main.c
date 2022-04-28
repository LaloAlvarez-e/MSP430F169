#include "DriverLib/DriverLib.h"

void main(void)
{
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
    _EINT();
	while(1U)
	{

	}
}
