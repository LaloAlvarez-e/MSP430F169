#include "MCU/MCU.h"
#include "GPIO/GPIO.h"
#include "CLOCK/CLOCK.h"

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

void MAIN_vInitInput(void);
void MAIN_vInitOutput(void);

uint16_t MAIN_u16Switch(uintptr_t uptrPort, uint8_t u8PinNumber);

uint16_t u16Count = 0U;
/**
 * main.c
 */
void main(void)
{
    uint16_t u16Iter = 0U;
	WDTCTL = WDTPW | WDTHOLD;	/*  stop watchdog timer*/

	/**Configure DCO to max frequency ~5MHz*/

	CLOCK_BCSCTL2->DCOR = 1;
    CLOCK_DCOCTL->DCO = CLOCK_DCOCTL_DCO_6;
    CLOCK->BCSCTL1_bits.RSEL = CLOCK_BCSCTL1_RSEL_6;


    CLOCK__vSetXT2Enable(CLOCK_enENABLE_ENA);
	do
	{
	    CLOCK_IFG1_R &= ~ CLOCK_IFG1_R_OFIFG_MASK;
	    for(u16Iter = 0U; u16Iter < 400U; u16Iter++); /*At least 50us*/
	}while(0U != (CLOCK_IFG1_R_OFIFG_MASK & CLOCK_IFG1_R));
	CLOCK__enSetMCLKSource(CLOCK_enSOURCE_XT2);

    GPIO__vRegisterIRQSourceHandler(SWITCH1_PORT, SWITCH1_PIN, &MAIN_u16Switch);
    GPIO__vRegisterIRQSourceHandler(SWITCH2_PORT, SWITCH2_PIN, &MAIN_u16Switch);
    GPIO__vRegisterIRQSourceHandler(SWITCH3_PORT, SWITCH3_PIN, &MAIN_u16Switch);
    GPIO__vRegisterIRQSourceHandler(SWITCH4_PORT, SWITCH4_PIN, &MAIN_u16Switch);
	MAIN_vInitInput();
	MAIN_vInitOutput();
	_EINT();
	/*_enable_interrupt();*/
	/*LPM4;*/
	_NOP();

    /** Rosc*/
    GPIO__vSetDirectionByNumber(GPIO_enPORT2, GPIO_enPIN_NUMBER5, GPIO_enDIR_INPUT);
    GPIO__vSetSelectionByNumber(GPIO_enPORT2, GPIO_enPIN_NUMBER5, GPIO_enSEL_PERIPHERAL);

	/** ACLK*/
	GPIO__vSetDirectionByNumber(GPIO_enPORT5, GPIO_enPIN_NUMBER6, GPIO_enDIR_OUTPUT);
	GPIO__vSetSelectionByNumber(GPIO_enPORT5, GPIO_enPIN_NUMBER6, GPIO_enSEL_PERIPHERAL);
	/** MCLK*/
    GPIO__vSetDirectionByNumber(GPIO_enPORT5, GPIO_enPIN_NUMBER4, GPIO_enDIR_OUTPUT);
    GPIO__vSetSelectionByNumber(GPIO_enPORT5, GPIO_enPIN_NUMBER4, GPIO_enSEL_PERIPHERAL);
    /** SMCLK*/
    GPIO__vSetDirectionByNumber(GPIO_enPORT5, GPIO_enPIN_NUMBER5, GPIO_enDIR_OUTPUT);
    GPIO__vSetSelectionByNumber(GPIO_enPORT5, GPIO_enPIN_NUMBER5, GPIO_enSEL_PERIPHERAL);



	while(1U)
	{
	    u16Count++;
	}
}


uint16_t MAIN_u16Switch(uintptr_t uptrPort, uint8_t u8PinNumber)
{
    PORT_EXT_t* pstPort = (PORT_EXT_t*) uptrPort;
    GPIO_nPIN_NUMBER enPinNumber = (GPIO_nPIN_NUMBER) u8PinNumber;
    uint8_t u8Mask = 1U;
    uint8_t u8ShiftLed = 7U;
    uint8_t u8MaskLed = 1U;
    uint16_t u16Status = 0U;
    uint8_t u8Edge = pstPort->IES;
    u8Mask <<= (uint8_t) enPinNumber;
    u8ShiftLed -= u8PinNumber;
    u8MaskLed <<= u8ShiftLed;
    if(0UL != (u8Edge & u8Mask)) /*High-To-Low*/
    {
        pstPort->IES &= ~u8Mask;
        PORT1->OUT &= ~u8MaskLed;
        if(u8PinNumber == (uint8_t) SWITCH1_PIN)
        {
            CLOCK__vSetMCLKDividerByNumber(1U);
        }
        if(u8PinNumber == (uint8_t) SWITCH2_PIN)
        {
            CLOCK__vSetMCLKDividerByNumber(2U);
        }
        if(u8PinNumber == (uint8_t) SWITCH3_PIN)
        {
            CLOCK__vSetMCLKDividerByNumber(4U);
        }
        if(u8PinNumber == (uint8_t) SWITCH4_PIN)
        {
            CLOCK__vSetMCLKDividerByNumber(8U);
        }

        u16Status = 0U; /*Active Mode*/
    }
    else /*Low-To-High*/
    {
        pstPort->IES |= u8Mask;
        PORT1->OUT |= u8MaskLed;
        /*u16Status = LPM4_bits;*/
    }
    return (u16Status);
}

void MAIN_vInitInput(void)
{
    /*P1.4 - P1.7 como entradas*/
    GPIO__vSetDirectionByNumber(SWITCH1_PORT, SWITCH1_PIN, GPIO_enDIR_INPUT);
    GPIO__vSetDirectionByNumber(SWITCH2_PORT, SWITCH2_PIN, GPIO_enDIR_INPUT);
    GPIO__vSetDirectionByNumber(SWITCH3_PORT, SWITCH3_PIN, GPIO_enDIR_INPUT);
    GPIO__vSetDirectionByNumber(SWITCH4_PORT, SWITCH4_PIN, GPIO_enDIR_INPUT);

    /*P1.4 - P1.7 configurar com I/O*/
    GPIO__vSetSelectionByNumber(SWITCH1_PORT, SWITCH1_PIN, GPIO_enSEL_IO);
    GPIO__vSetSelectionByNumber(SWITCH2_PORT, SWITCH2_PIN, GPIO_enSEL_IO);
    GPIO__vSetSelectionByNumber(SWITCH3_PORT, SWITCH3_PIN, GPIO_enSEL_IO);
    GPIO__vSetSelectionByNumber(SWITCH4_PORT, SWITCH4_PIN, GPIO_enSEL_IO);

    /*P1.4 - P1.7 Edge select High-To-Low*/
    GPIO__vSetInterruptEdgeByNumber(SWITCH1_PORT, SWITCH1_PIN, GPIO_enINT_EDGE_FALLING);
    GPIO__vSetInterruptEdgeByNumber(SWITCH2_PORT, SWITCH2_PIN, GPIO_enINT_EDGE_FALLING);
    GPIO__vSetInterruptEdgeByNumber(SWITCH3_PORT, SWITCH3_PIN, GPIO_enINT_EDGE_FALLING);
    GPIO__vSetInterruptEdgeByNumber(SWITCH4_PORT, SWITCH4_PIN, GPIO_enINT_EDGE_FALLING);

    /*P1.4 - P1.7 Clear Interrupt Flags*/
    GPIO__vClearInterruptSourceByNumber(SWITCH1_PORT, SWITCH1_PIN);
    GPIO__vClearInterruptSourceByNumber(SWITCH2_PORT, SWITCH2_PIN);
    GPIO__vClearInterruptSourceByNumber(SWITCH3_PORT, SWITCH3_PIN);
    GPIO__vClearInterruptSourceByNumber(SWITCH4_PORT, SWITCH4_PIN);

    /*P1.4 - P1.7 Enable interrupt*/
    GPIO__vEnaInterruptSourceByNumber(SWITCH1_PORT, SWITCH1_PIN);
    GPIO__vEnaInterruptSourceByNumber(SWITCH2_PORT, SWITCH2_PIN);
    GPIO__vEnaInterruptSourceByNumber(SWITCH3_PORT, SWITCH3_PIN);
    GPIO__vEnaInterruptSourceByNumber(SWITCH4_PORT, SWITCH4_PIN);
}

void MAIN_vInitOutput(void)
{
    /*P1.0 - P1.3 como Salidas*/
    GPIO__vSetDirectionByNumber(LED1_PORT, LED1_PIN, GPIO_enDIR_OUTPUT);
    GPIO__vSetDirectionByNumber(LED2_PORT, LED2_PIN, GPIO_enDIR_OUTPUT);
    GPIO__vSetDirectionByNumber(LED3_PORT, LED3_PIN, GPIO_enDIR_OUTPUT);
    GPIO__vSetDirectionByNumber(LED4_PORT, LED4_PIN, GPIO_enDIR_OUTPUT);

    /*P1.0 - P1.3 configurar com I/O*/
    GPIO__vSetSelectionByNumber(LED1_PORT, LED1_PIN, GPIO_enSEL_IO);
    GPIO__vSetSelectionByNumber(LED2_PORT, LED2_PIN, GPIO_enSEL_IO);
    GPIO__vSetSelectionByNumber(LED3_PORT, LED3_PIN, GPIO_enSEL_IO);
    GPIO__vSetSelectionByNumber(LED4_PORT, LED4_PIN, GPIO_enSEL_IO);

    /*P1.0 - P1.3 logica invertida*/
    GPIO__vSetOutputByNumber(LED1_PORT, LED1_PIN, GPIO_enLEVEL_HIGH);
    GPIO__vSetOutputByNumber(LED2_PORT, LED2_PIN, GPIO_enLEVEL_HIGH);
    GPIO__vSetOutputByNumber(LED3_PORT, LED3_PIN, GPIO_enLEVEL_HIGH);
    GPIO__vSetOutputByNumber(LED4_PORT, LED4_PIN, GPIO_enLEVEL_HIGH);

}
