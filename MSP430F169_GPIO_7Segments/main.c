#include "DriverLib/DriverLib.h"

#include "Modules/Segments/Segments.h"

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

static uint8_t u8Counter = 0U;
static uint8_t u8Mode = 0U;
/**
 * main.c
 */

void main(void)
{
    uint16_t u16Iter = 0U;
    uint8_t u8Value = 0U;
    uint8_t u8Digit = 0U;
    uint8_t u8ValueMod = 0U;
    uint8_t* pu8Char ="RED ";
    uint8_t* pu8CharTemp = pu8Char;
	WDTCTL = WDTPW | WDTHOLD;	/*  stop watchdog timer*/

    /** Rosc*/
    GPIO__vSetDirectionByNumber(GPIO_enPORT2, GPIO_enPIN_NUMBER5, GPIO_enDIR_INPUT);
    GPIO__vSetSelectionByNumber(GPIO_enPORT2, GPIO_enPIN_NUMBER5, GPIO_enSEL_PERIPHERAL);

	/**Configure DCO to max frequency ~5MHz*/
	CLOCK__vSetDCOFrequency(8000000UL, CLOCK_enRESISTOR_EXTERNAL);

    CLOCK__vSetLFXT1FrequencyMode(CLOCK_enFREQMODE_LOW);
    CLOCK__vSetXT2Enable(CLOCK_enENABLE_ENA);
	do
	{
	    CLOCK_IFG1_R &= ~ CLOCK_IFG1_R_OFIFG_MASK;
	    for(u16Iter = 0U; u16Iter < 4000U; u16Iter++); /*At least 50us*/
	}while(0U != (CLOCK_IFG1_R_OFIFG_MASK & CLOCK_IFG1_R));


    CLOCK__enSetACLKSource(CLOCK_enSOURCE_LFXT1);
	CLOCK__enSetMCLKSource(CLOCK_enSOURCE_DCO);
    CLOCK__enSetSMCLKSource(CLOCK_enSOURCE_XT2);

    GPIO__vRegisterIRQSourceHandler(SWITCH1_PORT, SWITCH1_PIN, &MAIN_u16Switch);
    GPIO__vRegisterIRQSourceHandler(SWITCH2_PORT, SWITCH2_PIN, &MAIN_u16Switch);
    GPIO__vRegisterIRQSourceHandler(SWITCH3_PORT, SWITCH3_PIN, &MAIN_u16Switch);
    GPIO__vRegisterIRQSourceHandler(SWITCH4_PORT, SWITCH4_PIN, &MAIN_u16Switch);
	MAIN_vInitInput();
	MAIN_vInitOutput();

	SEGMENTS__vInit();

	_EINT();
	/*_enable_interrupt();*/
	/*LPM4;*/
	_NOP();



	while(1U)
	{
        pu8CharTemp = pu8Char;
        u8Value = u8Counter;
        for(u8Digit = 0U ; u8Digit < (uint8_t) SEGMENTS_enDIGIT_MAX; u8Digit++)
        {
            if(0U == u8Mode)
            {
                u8ValueMod = u8Value;
                u8ValueMod %= 10U;
                u8Value/= 10U;
                SEGMENTS__vPrint(u8ValueMod, u8Digit, SEGMENTS_enCOMMON_ANODE);
            }
            else
            {
                SEGMENTS__vPrint(*pu8CharTemp, SEGMENTS_enDIGIT_MAX - u8Digit - 1U, SEGMENTS_enCOMMON_ANODE);
                pu8CharTemp++;
            }
            for(u16Iter = 0U; u16Iter < 7000U; u16Iter++); /*At least 50us*/
        }
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
            u8Counter++;
        }
        if(u8PinNumber == (uint8_t) SWITCH2_PIN)
        {
            u8Counter = 0U;
        }
        if(u8PinNumber == (uint8_t) SWITCH3_PIN)
        {
            u8Mode ^= 1U;
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
