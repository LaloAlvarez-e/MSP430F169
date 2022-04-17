#include "DriverLib/DriverLib.h"

uint16_t MAIN_u16SwitchInterrupt(uintptr_t uptrModule, uint8_t u8IntSource);

#define SWITCH1_PORT (GPIO_enPORT1)
#define SWITCH2_PORT (GPIO_enPORT1)
#define SWITCH3_PORT (GPIO_enPORT1)
#define SWITCH4_PORT (GPIO_enPORT1)

#define SWITCH1_PIN (GPIO_enPIN_NUMBER4)
#define SWITCH2_PIN (GPIO_enPIN_NUMBER5)
#define SWITCH3_PIN (GPIO_enPIN_NUMBER6)
#define SWITCH4_PIN (GPIO_enPIN_NUMBER7)

/**
 * main.c
 */

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
	    CLOCK_IFG1_R &= ~ CLOCK_IFG1_R_IFG_MASK;
	    for(u16Iter = 0U; u16Iter < 4000U; u16Iter++); /*At least 50us*/
	}while(0U != (CLOCK_IFG1_R_IFG_MASK & CLOCK_IFG1_R));

    CLOCK__enSetACLKSource(CLOCK_enSOURCE_LFXT1); /*32768 Hz*/
	CLOCK__enSetMCLKSource(CLOCK_enSOURCE_DCO); /*~8 MHz*/
    CLOCK__enSetSMCLKSource(CLOCK_enSOURCE_XT2); /*8 MHz*/

    GPIO__vSetDirectionByNumber(GPIO_enPORT3, GPIO_enPIN_NUMBER4, GPIO_enDIR_OUTPUT);
    GPIO__vSetSelectionByNumber(GPIO_enPORT3, GPIO_enPIN_NUMBER4, GPIO_enSEL_IO);
    GPIO__vSetOutputByNumber(GPIO_enPORT3, GPIO_enPIN_NUMBER4, GPIO_enLEVEL_LOW);

    GPIO__vSetDirectionByNumber(SWITCH1_PORT, SWITCH1_PIN, GPIO_enDIR_INPUT);
    GPIO__vSetSelectionByNumber(SWITCH1_PORT, SWITCH1_PIN, GPIO_enSEL_IO);
    GPIO__vSetInterruptEdgeByNumber(SWITCH1_PORT, SWITCH1_PIN, GPIO_enINT_EDGE_FALLING);
    GPIO__vClearInterruptSourceByNumber(SWITCH1_PORT, SWITCH1_PIN);
    GPIO__vEnaInterruptSourceByNumber(SWITCH1_PORT, SWITCH1_PIN);

    GPIO__vSetDirectionByNumber(SWITCH2_PORT, SWITCH2_PIN, GPIO_enDIR_INPUT);
    GPIO__vSetSelectionByNumber(SWITCH2_PORT, SWITCH2_PIN, GPIO_enSEL_IO);
    GPIO__vSetInterruptEdgeByNumber(SWITCH2_PORT, SWITCH2_PIN, GPIO_enINT_EDGE_FALLING);
    GPIO__vClearInterruptSourceByNumber(SWITCH2_PORT, SWITCH2_PIN);
    GPIO__vEnaInterruptSourceByNumber(SWITCH2_PORT, SWITCH2_PIN);

    GPIO__vRegisterIRQSourceHandler(SWITCH1_PORT, SWITCH1_PIN, &MAIN_u16SwitchInterrupt);
    GPIO__vRegisterIRQSourceHandler(SWITCH2_PORT, SWITCH2_PIN, &MAIN_u16SwitchInterrupt);

    CLOCK_IFG1_R &= ~(0x01); /*0x01 = WDTIFG*/
    CLOCK_IE1_R |= (0x01); /*0x01 = WDTIE*/
    WDTCTL = WDTPW | WDTTMSEL | WDTCNTCL | WDTSSEL;
    _EINT();


	while(1U)
	{

	}
}


uint16_t MAIN_u16SwitchInterrupt(uintptr_t uptrModule, uint8_t u8IntSource)
{
    uint16_t u16WDTReg = 0U;
    uint16_t u16Period = 0U;
    GPIO_nPIN_NUMBER enPinNumber = (GPIO_nPIN_NUMBER) u8IntSource;

    if(SWITCH1_PIN == enPinNumber)
    {
        u16WDTReg = WDTCTL;
        u16Period = u16WDTReg & (WDTIS1 | WDTIS0);
        u16WDTReg &= ~(WDTIS1 | WDTIS0);
        u16Period++;
        if((WDTIS1 | WDTIS0) < u16Period)
        {
            u16Period = 0U;
        }
        u16WDTReg |= u16Period;
        u16WDTReg &= ~0xFF00U;
        u16WDTReg |= WDTPW;
        u16WDTReg |= WDTCNTCL;

        WDTCTL = u16WDTReg;
    }
    if(SWITCH2_PIN == enPinNumber)
    {
        u16WDTReg = WDTCTL;
        u16WDTReg ^= WDTSSEL;
        u16WDTReg &= ~0xFF00U;
        u16WDTReg |= WDTPW;
        u16WDTReg |= WDTCNTCL;
        WDTCTL = u16WDTReg;
    }
    return (0U);
}

#pragma vector = WDT_VECTOR
__interrupt void WDT_vIRQHandler(void)
{
    static uint8_t u8Value = 0U;
    u8Value ^= 0x1;
    GPIO__vSetOutputByNumber(GPIO_enPORT3, GPIO_enPIN_NUMBER4, (GPIO_nLEVEL) u8Value);
}


