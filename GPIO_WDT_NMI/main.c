#include "DriverLib/DriverLib.h"

#define LED4_PORT (GPIO_enPORT1)
#define LED4_PIN (GPIO_enPIN_NUMBER3)
/**
 * main.c
 */
uint8_t u8Activate = 0U;

void main(void)
{
    uint16_t u16Iter = 0U;
	WDTCTL = WDTPW | WDTHOLD;	/*  stop watchdog timer*/

    /** Rosc*/
    GPIO__vSetDirectionByNumber(GPIO_enPORT2, GPIO_enPIN_NUMBER5, GPIO_enDIR_INPUT);
    GPIO__vSetSelectionByNumber(GPIO_enPORT2, GPIO_enPIN_NUMBER5, GPIO_enSEL_PERIPHERAL);

	/**Configure DCO to max frequency ~8MHz*/
	CLOCK__vSetDCOFrequency(8000000UL, CLOCK_enRESISTOR_EXTERNAL);

    CLOCK__vSetLFXT1FrequencyMode(CLOCK_enFREQMODE_LOW);
    CLOCK__vSetXT2Enable(CLOCK_enENABLE_ENA);
	do
	{
	    CLOCK_IFG1_R &= ~ CLOCK_IFG1_R_OFIFG_MASK;
	    for(u16Iter = 0U; u16Iter < 4000U; u16Iter++); /*At least 50us*/
	}while(0U != (CLOCK_IFG1_R_OFIFG_MASK & CLOCK_IFG1_R));

    CLOCK__enSetACLKSource(CLOCK_enSOURCE_LFXT1); /*32768 Hz*/
	CLOCK__enSetMCLKSource(CLOCK_enSOURCE_DCO); /*~8 MHz*/
    CLOCK__enSetSMCLKSource(CLOCK_enSOURCE_XT2); /*8 MHz*/

    GPIO__vSetDirectionByNumber(LED4_PORT, LED4_PIN, GPIO_enDIR_OUTPUT);
    GPIO__vSetSelectionByNumber(LED4_PORT, LED4_PIN, GPIO_enSEL_IO);
    GPIO__vSetOutputByNumber(LED4_PORT, LED4_PIN, GPIO_enLEVEL_HIGH);

    WDTCTL = WDTPW | WDTNMIES | WDTHOLD;   /*  stop watchdog timer*/
    WDTCTL = WDTPW | WDTNMIES | WDTNMI | WDTHOLD;   /*  stop watchdog timer*/
    CLOCK_IFG1_R &= ~(0x10);
    CLOCK_IE1_R |= (0x10);

	while(1U)
	{
	}
}


#pragma vector = NMI_VECTOR
__interrupt void NMI_vIRQHandler(void)
{
    static uint8_t u8Value = 1UL;
    if(CLOCK_IFG1_R & 0x10)
    {
        CLOCK_IFG1_R &= ~ (0x10);
        CLOCK_IE1_R |= (0x10);
        u8Value ^= 1UL;
        GPIO__vSetOutputByNumber(LED4_PORT, LED4_PIN, (GPIO_nLEVEL) u8Value);
    }
}


