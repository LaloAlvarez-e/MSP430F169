#include "DriverLib/MCU/MCU.h"
#include "DriverLib/GPIO/GPIO.h"

#include <msp430.h> 
#include <stdint.h>

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

uint16_t MAIN_u16Switch(uintptr_t uptrPort, uint16_t u16PinNumber);

uint16_t u16Count = 0U;

/**
 * main.c
 */
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	/*  stop watchdog timer*/
    GPIO__vRegisterIRQSourceHandler(SWITCH1_PORT, SWITCH1_PIN, &MAIN_u16Switch);
    GPIO__vRegisterIRQSourceHandler(SWITCH2_PORT, SWITCH2_PIN, &MAIN_u16Switch);
    GPIO__vRegisterIRQSourceHandler(SWITCH3_PORT, SWITCH3_PIN, &MAIN_u16Switch);
    GPIO__vRegisterIRQSourceHandler(SWITCH4_PORT, SWITCH4_PIN, &MAIN_u16Switch);
	MAIN_vInitInput();
	MAIN_vInitOutput();
	_EINT();
	/*_enable_interrupt();*/
	LPM4;
	_NOP();

	while(1U)
	{
	    u16Count++;
	}
}

uint16_t MAIN_u16Switch(uintptr_t uptrPort, uint16_t u16PinNumber)
{
    PORT_EXT_t* pstPort = (PORT_EXT_t*) uptrPort;
    GPIO_nPIN_NUMBER enPinNumber = (GPIO_nPIN_NUMBER) u16PinNumber;
    uint8_t u8Mask = 1U;
    uint8_t u8ShiftLed = 7U;
    uint8_t u8MaskLed = 1U;
    uint16_t u16Status = 0U;
    uint8_t u8Edge = pstPort->IES;
    u8Mask <<= (uint8_t) enPinNumber;
    u8ShiftLed -= u16PinNumber;
    u8MaskLed <<= u8ShiftLed;
    if(0UL != (u8Edge & u8Mask)) /*High-To-Low*/
    {
        pstPort->IES &= ~u8Mask;
        PORT1->OUT &= ~u8MaskLed;
        u16Status = 0U; /*Active Mode*/
    }
    else /*Low-To-High*/
    {
        pstPort->IES |= u8Mask;
        PORT1->OUT |= u8MaskLed;
        u16Status = LPM4_bits;
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
