#include "MCU/MCU.h"
#include "GPIO/GPIO.h"

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

uint16_t MAIN_u16Switch(uintptr_t uptrPort, uint8_t u8PinNumber);

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
    GPIO__vWriteRegister(SWITCH1_PORT, PORT_DIR_OFFSET, 0U, 1U, SWITCH1_PIN);
    GPIO__vWriteRegister(SWITCH2_PORT, PORT_DIR_OFFSET, 0U, 1U, SWITCH2_PIN);
    GPIO__vWriteRegister(SWITCH3_PORT, PORT_DIR_OFFSET, 0U, 1U, SWITCH3_PIN);
    GPIO__vWriteRegister(SWITCH4_PORT, PORT_DIR_OFFSET, 0U, 1U, SWITCH4_PIN);

    /*P1.4 - P1.7 configurar com I/O*/
    GPIO__vWriteRegister(SWITCH1_PORT, PORT_EXT_SEL_OFFSET, 0U, 1U, SWITCH1_PIN);
    GPIO__vWriteRegister(SWITCH2_PORT, PORT_EXT_SEL_OFFSET, 0U, 1U, SWITCH2_PIN);
    GPIO__vWriteRegister(SWITCH3_PORT, PORT_EXT_SEL_OFFSET, 0U, 1U, SWITCH3_PIN);
    GPIO__vWriteRegister(SWITCH4_PORT, PORT_EXT_SEL_OFFSET, 0U, 1U, SWITCH4_PIN);

    /*P1.4 - P1.7 Edge select High-To-Low*/
    GPIO__vWriteRegister(SWITCH1_PORT, PORT_IES_OFFSET, 1U, 1U, SWITCH1_PIN);
    GPIO__vWriteRegister(SWITCH2_PORT, PORT_IES_OFFSET, 1U, 1U, SWITCH2_PIN);
    GPIO__vWriteRegister(SWITCH3_PORT, PORT_IES_OFFSET, 1U, 1U, SWITCH3_PIN);
    GPIO__vWriteRegister(SWITCH4_PORT, PORT_IES_OFFSET, 1U, 1U, SWITCH4_PIN);

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
    GPIO__vWriteRegister(LED1_PORT, PORT_DIR_OFFSET, 1U, 1U, LED1_PIN);
    GPIO__vWriteRegister(LED2_PORT, PORT_DIR_OFFSET, 1U, 1U, LED2_PIN);
    GPIO__vWriteRegister(LED3_PORT, PORT_DIR_OFFSET, 1U, 1U, LED3_PIN);
    GPIO__vWriteRegister(LED4_PORT, PORT_DIR_OFFSET, 1U, 1U, LED4_PIN);

    /*P1.0 - P1.3 configurar com I/O*/
    GPIO__vWriteRegister(LED1_PORT, PORT_EXT_SEL_OFFSET, 0U, 1U, LED1_PIN);
    GPIO__vWriteRegister(LED2_PORT, PORT_EXT_SEL_OFFSET, 0U, 1U, LED2_PIN);
    GPIO__vWriteRegister(LED3_PORT, PORT_EXT_SEL_OFFSET, 0U, 1U, LED3_PIN);
    GPIO__vWriteRegister(LED4_PORT, PORT_EXT_SEL_OFFSET, 0U, 1U, LED4_PIN);

    /*P1.0 - P1.3 logica invertida*/
    GPIO__vWriteRegister(LED1_PORT, PORT_OUT_OFFSET, 1U, 1U, LED1_PIN);
    GPIO__vWriteRegister(LED2_PORT, PORT_OUT_OFFSET, 1U, 1U, LED2_PIN);
    GPIO__vWriteRegister(LED3_PORT, PORT_OUT_OFFSET, 1U, 1U, LED3_PIN);
    GPIO__vWriteRegister(LED4_PORT, PORT_OUT_OFFSET, 1U, 1U, LED4_PIN);

}
