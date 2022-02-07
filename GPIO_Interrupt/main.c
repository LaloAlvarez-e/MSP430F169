#include "MCU/MCU.h"
#include "GPIO/GPIO.h"

#include <msp430.h> 
#include <stdint.h>

void MAIN_vInitInput(void);
void MAIN_vInitOutput(void);

uint16_t MAIN_u16SwitchP1_4(void);
uint16_t MAIN_u16SwitchP1_4_0(void);
uint16_t MAIN_u16SwitchP1_4_1(void);
uint16_t MAIN_u16SwitchP1_4_2(void);
uint16_t MAIN_u16SwitchP1_5(void);
uint16_t MAIN_u16SwitchP1_6(void);
uint16_t MAIN_u16SwitchP1_7(void);

uint16_t u16Count = 0U;

/**
 * main.c
 */
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	/*  stop watchdog timer*/
	GPIO__vSetInterruptSource(4UL, &MAIN_u16SwitchP1_4);
	GPIO__vSetInterruptSource(5UL, &MAIN_u16SwitchP1_5);
	GPIO__vSetInterruptSource(6UL, &MAIN_u16SwitchP1_6);
	GPIO__vSetInterruptSource(7UL, &MAIN_u16SwitchP1_7);
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

uint16_t MAIN_u16SwitchP1_4(void)
{
    uint16_t u16Status = 0U;
    uint8_t u8Edge = PORT1_IES_R;
    if(0UL != (u8Edge & PORT_IES_R_PIN4_MASK)) /*High-To-Low*/
    {
        PORT1_IES_R &= ~PORT_IES_R_PIN4_MASK;
        PORT1_OUT_R &= ~PORT_OUT_R_PIN3_MASK;
        u16Status = 0U; /*Active Mode*/
    }
    else /*Low-To-High*/
    {
        PORT1_IES_R |= PORT_IES_R_PIN4_MASK;
        PORT1_OUT_R |= PORT_OUT_R_PIN3_MASK;
        u16Status = LPM4_bits;
        GPIO__vSetInterruptSource(4UL, &MAIN_u16SwitchP1_4_0);
    }
    return (u16Status);
}

uint16_t MAIN_u16SwitchP1_4_0(void)
{
    uint16_t u16Status = 0U;
    uint8_t u8Edge = PORT1_IES_R;
    if(0UL != (u8Edge & PORT_IES_R_PIN4_MASK)) /*High-To-Low*/
    {
        PORT1_IES_R &= ~PORT_IES_R_PIN4_MASK;
        PORT1_OUT_R &= ~PORT_OUT_R_PIN2_MASK;
        u16Status = 0U; /*Active Mode*/
    }
    else /*Low-To-High*/
    {
        PORT1_IES_R |= PORT_IES_R_PIN4_MASK;
        PORT1_OUT_R |= PORT_OUT_R_PIN2_MASK;
        u16Status = LPM4_bits;
        GPIO__vSetInterruptSource(4UL, &MAIN_u16SwitchP1_4_1);
    }
    return (u16Status);
}

uint16_t MAIN_u16SwitchP1_4_1(void)
{
    uint16_t u16Status = 0U;
    uint8_t u8Edge = PORT1_IES_R;
    if(0UL != (u8Edge & PORT_IES_R_PIN4_MASK)) /*High-To-Low*/
    {
        PORT1_IES_R &= ~PORT_IES_R_PIN4_MASK;
        PORT1_OUT_R &= ~PORT_OUT_R_PIN1_MASK;
        u16Status = 0U; /*Active Mode*/
    }
    else /*Low-To-High*/
    {
        PORT1_IES_R |= PORT_IES_R_PIN4_MASK;
        PORT1_OUT_R |= PORT_OUT_R_PIN1_MASK;
        u16Status = LPM4_bits;
        GPIO__vSetInterruptSource(4UL, &MAIN_u16SwitchP1_4_2);
    }
    return (u16Status);
}

uint16_t MAIN_u16SwitchP1_4_2(void)
{
    uint16_t u16Status = 0U;
    uint8_t u8Edge = PORT1_IES_R;
    if(0UL != (u8Edge & PORT_IES_R_PIN4_MASK)) /*High-To-Low*/
    {
        PORT1_IES_R &= ~PORT_IES_R_PIN4_MASK;
        PORT1_OUT_R &= ~PORT_OUT_R_PIN0_MASK;
        u16Status = 0U; /*Active Mode*/
    }
    else /*Low-To-High*/
    {
        PORT1_IES_R |= PORT_IES_R_PIN4_MASK;
        PORT1_OUT_R |= PORT_OUT_R_PIN0_MASK;
        u16Status = LPM4_bits;
        GPIO__vSetInterruptSource(4UL, &MAIN_u16SwitchP1_4);
    }
    return (u16Status);
}
uint16_t MAIN_u16SwitchP1_5(void)
{
    uint16_t u16Status = 0U;
    uint8_t u8Edge = PORT1_IES_R;
    if(0UL != (u8Edge & PORT_IES_R_PIN5_MASK)) /*High-To-Low*/
    {
        PORT1_IES_R &= ~PORT_IES_R_PIN5_MASK;
        PORT1_OUT_R &= ~PORT_OUT_R_PIN2_MASK;
        u16Status = 0U; /*Active Mode*/
    }
    else /*Low-To-High*/
    {
        PORT1_IES_R |= PORT_IES_R_PIN5_MASK;
        PORT1_OUT_R |= PORT_OUT_R_PIN2_MASK;
        u16Status = LPM4_bits;
    }
    return (u16Status);
}

uint16_t MAIN_u16SwitchP1_6(void)
{
    uint16_t u16Status = 0U;
    uint8_t u8Edge = PORT1_IES_R;
    if(0UL != (u8Edge & PORT_IES_R_PIN6_MASK)) /*High-To-Low*/
    {
        PORT1_IES_R &= ~PORT_IES_R_PIN6_MASK;
        PORT1_OUT_R &= ~PORT_OUT_R_PIN1_MASK;
        u16Status = 0U; /*Active Mode*/
    }
    else /*Low-To-High*/
    {
        PORT1_IES_R |= PORT_IES_R_PIN6_MASK;
        PORT1_OUT_R |= PORT_OUT_R_PIN1_MASK;
        u16Status = LPM4_bits;
    }
    return (u16Status);
}

uint16_t MAIN_u16SwitchP1_7(void)
{
    uint16_t u16Status = 0U;
    uint8_t u8Edge = PORT1_IES_R;
    if(0UL != (u8Edge & PORT_IES_R_PIN7_MASK)) /*High-To-Low*/
    {
        PORT1_IES_R &= ~PORT_IES_R_PIN7_MASK;
        PORT1_OUT_R &= ~PORT_OUT_R_PIN0_MASK;
        u16Status = 0U; /*Active Mode*/
    }
    else /*Low-To-High*/
    {
        PORT1_IES_R |= PORT_IES_R_PIN7_MASK;
        PORT1_OUT_R |= PORT_OUT_R_PIN0_MASK;
        u16Status = LPM4_bits;
    }
    return (u16Status);
}

void MAIN_vInitInput(void)
{
    /*P1.4 - P1.7 como entradas*/
    GPIO__vWriteRegister(GPIO_enPORT1,
                         PORT_DIR_OFFSET,
                         0U,
                         (PORT_DIR_R_PIN4_MASK |
                         PORT_DIR_R_PIN5_MASK |
                         PORT_DIR_R_PIN6_MASK |
                         PORT_DIR_R_PIN7_MASK),
                         0U);
    /*P1.4 - P1.7 configurar com I/O*/
    GPIO__vWriteRegister(GPIO_enPORT1,
                         PORT_EXT_SEL_OFFSET,
                         0U,
                         (PORT_DIR_R_PIN4_MASK |
                         PORT_DIR_R_PIN5_MASK |
                         PORT_DIR_R_PIN6_MASK |
                         PORT_DIR_R_PIN7_MASK),
                         0U);

    /*P1.4 - P1.7 Edge select High-To-Low*/
    GPIO__vWriteRegister(GPIO_enPORT1,
                         PORT_IES_OFFSET,
                         (PORT_DIR_R_PIN4_MASK |
                         PORT_DIR_R_PIN5_MASK |
                         PORT_DIR_R_PIN6_MASK |
                         PORT_DIR_R_PIN7_MASK),
                         (PORT_DIR_R_PIN4_MASK |
                         PORT_DIR_R_PIN5_MASK |
                         PORT_DIR_R_PIN6_MASK |
                         PORT_DIR_R_PIN7_MASK),
                         0U);

    /*P1.4 - P1.7 Clear Interrupt Flags*/
    GPIO__vClearInterruptSource(GPIO_enPORT1,
          (GPIO_nPIN)(GPIO_enPIN4 | GPIO_enPIN5 | GPIO_enPIN6 | GPIO_enPIN7));
    /*
    GPIO__vClearInterruptSourceByNumber(GPIO_enPORT1, GPIO_enPIN_NUMBER4);
    GPIO__vClearInterruptSourceByNumber(GPIO_enPORT1, GPIO_enPIN_NUMBER5);
    GPIO__vClearInterruptSourceByNumber(GPIO_enPORT1, GPIO_enPIN_NUMBER6);
    GPIO__vClearInterruptSourceByNumber(GPIO_enPORT1, GPIO_enPIN_NUMBER7);
    */

    /*P1.4 - P1.7 Enable interrupt*/
    GPIO__vEnaInterruptSource(GPIO_enPORT1,
          (GPIO_nPIN)(GPIO_enPIN4 | GPIO_enPIN5 | GPIO_enPIN6 | GPIO_enPIN7));
    /*
    GPIO__vEnaInterruptSourceByNumber(GPIO_enPORT1, GPIO_enPIN_NUMBER4);
    GPIO__vEnaInterruptSourceByNumber(GPIO_enPORT1, GPIO_enPIN_NUMBER5);
    GPIO__vEnaInterruptSourceByNumber(GPIO_enPORT1, GPIO_enPIN_NUMBER6);
    GPIO__vEnaInterruptSourceByNumber(GPIO_enPORT1, GPIO_enPIN_NUMBER7);
    */
}

void MAIN_vInitOutput(void)
{
    /*P1.0 - P1.3 como Salidas*/
    GPIO__vWriteRegister(GPIO_enPORT1,
                         PORT_DIR_OFFSET,
                         (PORT_DIR_R_PIN0_MASK | PORT_DIR_R_PIN1_MASK |
                         PORT_DIR_R_PIN2_MASK | PORT_DIR_R_PIN3_MASK),
                         (PORT_DIR_R_PIN0_MASK | PORT_DIR_R_PIN1_MASK |
                         PORT_DIR_R_PIN2_MASK | PORT_DIR_R_PIN3_MASK),
                         0U);
    /*P1.0 - P1.3 configurar com I/O*/
    GPIO__vWriteRegister(GPIO_enPORT1,
                         PORT_EXT_SEL_OFFSET,
                         0U,
                         (PORT_DIR_R_PIN0_MASK | PORT_DIR_R_PIN1_MASK |
                         PORT_DIR_R_PIN2_MASK | PORT_DIR_R_PIN3_MASK),
                         0U);

    /*P1.0 - P1.3 logica invertida*/
    GPIO__vWriteRegister(GPIO_enPORT1,
                         PORT_OUT_OFFSET,
                         (PORT_DIR_R_PIN0_MASK | PORT_DIR_R_PIN1_MASK |
                         PORT_DIR_R_PIN2_MASK | PORT_DIR_R_PIN3_MASK),
                         (PORT_DIR_R_PIN0_MASK | PORT_DIR_R_PIN1_MASK |
                         PORT_DIR_R_PIN2_MASK | PORT_DIR_R_PIN3_MASK),
                         0U);
}
