#include "DriverLib/DriverLib.h"

uint16_t MAIN_u16SwitchInterrupt(uintptr_t uptrModule, uint16_t u16IntSource);

#define SWITCH1_PORT (GPIO_enPORT1)
#define SWITCH2_PORT (GPIO_enPORT1)
#define SWITCH3_PORT (GPIO_enPORT1)
#define SWITCH4_PORT (GPIO_enPORT1)

#define SWITCH1_PIN (GPIO_enPIN_NUMBER4)
#define SWITCH2_PIN (GPIO_enPIN_NUMBER5)
#define SWITCH3_PIN (GPIO_enPIN_NUMBER6)
#define SWITCH4_PIN (GPIO_enPIN_NUMBER7)

#define LED1_PORT (GPIO_enPORT1)
#define LED2_PORT (GPIO_enPORT1)
#define LED3_PORT (GPIO_enPORT1)
#define LED4_PORT (GPIO_enPORT1)

#define LED1_PIN (GPIO_enPIN_NUMBER0)
#define LED2_PIN (GPIO_enPIN_NUMBER1)
#define LED3_PIN (GPIO_enPIN_NUMBER2)
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
	    CLOCK_IFG1_R &= ~ CLOCK_IFG1_R_IFG_MASK;
	    for(u16Iter = 0U; u16Iter < 4000U; u16Iter++); /*At least 50us*/
	}while(0U != (CLOCK_IFG1_R_IFG_MASK & CLOCK_IFG1_R));

    CLOCK__enSetACLKSource(CLOCK_enSOURCE_LFXT1); /*32768 Hz*/
	CLOCK__enSetMCLKSource(CLOCK_enSOURCE_DCO); /*~8 MHz*/
    CLOCK__enSetSMCLKSource(CLOCK_enSOURCE_XT2); /*8 MHz*/

    GPIO__vSetDirectionByNumber(LED1_PORT, LED1_PIN, GPIO_enDIR_OUTPUT);
    GPIO__vSetSelectionByNumber(LED1_PORT, LED1_PIN, GPIO_enSEL_IO);
    GPIO__vSetOutputByNumber(LED1_PORT, LED1_PIN, GPIO_enLEVEL_HIGH);

    GPIO__vSetDirectionByNumber(LED2_PORT, LED2_PIN, GPIO_enDIR_OUTPUT);
    GPIO__vSetSelectionByNumber(LED2_PORT, LED2_PIN, GPIO_enSEL_IO);
    GPIO__vSetOutputByNumber(LED2_PORT, LED2_PIN, GPIO_enLEVEL_HIGH);

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

    if(CLOCK_IFG1_R & (0x01))
    {
        CLOCK_IFG1_R &= ~ (0x1U);
        GPIO__vSetOutputByNumber(LED1_PORT, LED1_PIN, GPIO_enLEVEL_LOW);
    }
    else
    {
        GPIO__vSetOutputByNumber(LED2_PORT, LED2_PIN, GPIO_enLEVEL_LOW);
    }

    _EINT();
	while(1U)
	{
	    if(0U == u8Activate)
	    {
	        WDTCTL = WDTPW | WDTCNTCL;
	    }
	}
}


uint16_t MAIN_u16SwitchInterrupt(uintptr_t uptrModule, uint16_t u16IntSource)
{
    GPIO_nPIN_NUMBER enPinNumber = (GPIO_nPIN_NUMBER) u16IntSource;

    if(SWITCH1_PIN == enPinNumber)
    {
        u8Activate = 1UL;
    }
    return (0U);
}



