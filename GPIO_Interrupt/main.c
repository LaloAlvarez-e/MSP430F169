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
    if(0UL != (u8Edge & BIT4)) /*High-To-Low*/
    {
        PORT1_IES_R &= ~BIT4;
        PORT1_OUT_R &= ~BIT3;
        u16Status = 0U; /*Active Mode*/
    }
    else /*Low-To-High*/
    {
        PORT1_IES_R |= BIT4;
        PORT1_OUT_R |= BIT3;
        u16Status = LPM4_bits;
        GPIO__vSetInterruptSource(4UL, &MAIN_u16SwitchP1_4_0);
    }
    return (u16Status);
}

uint16_t MAIN_u16SwitchP1_4_0(void)
{
    uint16_t u16Status = 0U;
    uint8_t u8Edge = PORT1_IES_R;
    if(0UL != (u8Edge & BIT4)) /*High-To-Low*/
    {
        PORT1_IES_R &= ~BIT4;
        PORT1_OUT_R &= ~BIT2;
        u16Status = 0U; /*Active Mode*/
    }
    else /*Low-To-High*/
    {
        PORT1_IES_R |= BIT4;
        PORT1_OUT_R |= BIT2;
        u16Status = LPM4_bits;
        GPIO__vSetInterruptSource(4UL, &MAIN_u16SwitchP1_4_1);
    }
    return (u16Status);
}

uint16_t MAIN_u16SwitchP1_4_1(void)
{
    uint16_t u16Status = 0U;
    uint8_t u8Edge = PORT1_IES_R;
    if(0UL != (u8Edge & BIT4)) /*High-To-Low*/
    {
        PORT1_IES_R &= ~BIT4;
        PORT1_OUT_R &= ~BIT1;
        u16Status = 0U; /*Active Mode*/
    }
    else /*Low-To-High*/
    {
        PORT1_IES_R |= BIT4;
        PORT1_OUT_R |= BIT1;
        u16Status = LPM4_bits;
        GPIO__vSetInterruptSource(4UL, &MAIN_u16SwitchP1_4_2);
    }
    return (u16Status);
}

uint16_t MAIN_u16SwitchP1_4_2(void)
{
    uint16_t u16Status = 0U;
    uint8_t u8Edge = PORT1_IES_R;
    if(0UL != (u8Edge & BIT4)) /*High-To-Low*/
    {
        PORT1_IES_R &= ~BIT4;
        PORT1_OUT_R &= ~BIT0;
        u16Status = 0U; /*Active Mode*/
    }
    else /*Low-To-High*/
    {
        PORT1_IES_R |= BIT4;
        PORT1_OUT_R |= BIT0;
        u16Status = LPM4_bits;
        GPIO__vSetInterruptSource(4UL, &MAIN_u16SwitchP1_4);
    }
    return (u16Status);
}
uint16_t MAIN_u16SwitchP1_5(void)
{
    uint16_t u16Status = 0U;
    uint8_t u8Edge = PORT1_IES_R;
    if(0UL != (u8Edge & BIT5)) /*High-To-Low*/
    {
        PORT1_IES_R &= ~BIT5;
        PORT1_OUT_R &= ~BIT2;
        u16Status = 0U; /*Active Mode*/
    }
    else /*Low-To-High*/
    {
        PORT1_IES_R |= BIT5;
        PORT1_OUT_R |= BIT2;
        u16Status = LPM4_bits;
    }
    return (u16Status);
}

uint16_t MAIN_u16SwitchP1_6(void)
{
    uint16_t u16Status = 0U;
    uint8_t u8Edge = PORT1_IES_R;
    if(0UL != (u8Edge & BIT6)) /*High-To-Low*/
    {
        PORT1_IES_R &= ~BIT6;
        PORT1_OUT_R &= ~BIT1;
        u16Status = 0U; /*Active Mode*/
    }
    else /*Low-To-High*/
    {
        PORT1_IES_R |= BIT6;
        PORT1_OUT_R |= BIT1;
        u16Status = LPM4_bits;
    }
    return (u16Status);
}

uint16_t MAIN_u16SwitchP1_7(void)
{
    uint16_t u16Status = 0U;
    uint8_t u8Edge = PORT1_IES_R;
    if(0UL != (u8Edge & BIT7)) /*High-To-Low*/
    {
        PORT1_IES_R &= ~BIT7;
        PORT1_OUT_R &= ~BIT0;
        u16Status = 0U; /*Active Mode*/
    }
    else /*Low-To-High*/
    {
        PORT1_IES_R |= BIT7;
        PORT1_OUT_R |= BIT0;
        u16Status = LPM4_bits;
    }
    return (u16Status);
}

void MAIN_vInitInput(void)
{
    /*P1.4 - P1.7 como entradas*/
    PORT1_DIR_R &= ~(BIT4 | BIT5 | BIT6 | BIT7);
    /*P1.4 - P1.7 configurar com I/O*/
    PORT1_SEL_R &= ~(BIT4 | BIT5 | BIT6 | BIT7);

    /*P1.4 - P1.7 Edge select High-To-Low*/
    PORT1_IES_R |= BIT4 | BIT5 | BIT6 | BIT7;

    /*P1.4 - P1.7 Clear Interrupt Flags*/
    PORT1_IFG_R &= ~(BIT4 | BIT5 | BIT6 | BIT7);

    /*P1.4 - P1.7 Enable interrupt*/
    PORT1_IE_R |= BIT4 | BIT5 | BIT6 | BIT7;

}

void MAIN_vInitOutput(void)
{
    /*P1.0 - P1.3 como Salidas*/
    MCU__vWriteRegister_8bits(0x22UL,
                              (BIT0 | BIT1 | BIT2 | BIT3),
                              (BIT0 | BIT1 | BIT2 | BIT3),
                              0U);
    /*P1.0 - P1.3 configurar com I/O*/
    PORT1->SEL &= ~(BIT0 | BIT1 | BIT2 | BIT3);

    /*P1.0 - P1.3 logica invertida*/
    PORT1_OUT_R |= BIT1 | BIT2 | BIT3;
    PORT1->OUT_bits.P0 = 1U;
}
