#include <msp430.h> 
#include <stdint.h>

void MAIN_vInitInput(void);
void MAIN_vInitOutput(void);
uint8_t MAIN_u8Interrupt(void);

uint8_t(*MyUpdate)(void) = (uint8_t(*)(void)) 0UL;
/**
 * main.c
 */
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
    MyUpdate = &MAIN_u8Interrupt;
	MAIN_vInitInput();
	MAIN_vInitOutput();
	_EINT();
	/*_enable_interrupt();*/
	while(1U)
	{

	    LPM4;
	}
}

#pragma vector = PORT1_VECTOR
__interrupt void PORT1_IrqHandler(void)
{
    uint8_t u8Status = LPM4_bits;
    uint8_t u8Flags = P1IFG;
    uint8_t u8Enable = P1IE;
    uint8_t u8Edge = P1IES;

    u8Flags &= u8Enable;

    if(0U != (u8Flags & BIT0))
    {
        P1IFG &= ~BIT0;
    }
    if(0U != (u8Flags & BIT1))
    {
        P1IFG &= ~BIT1;
    }
    if(0U != (u8Flags & BIT2))
    {
        P1IFG &= ~BIT2;
    }
    if(0U != (u8Flags & BIT3))
    {
        P1IFG &= ~BIT3;
    }
    if(0U != (u8Flags & BIT4))
    {
        P1IFG &= ~BIT4;
        if(0UL != (u8Edge & BIT4)) /*High-To-Low*/
        {
            P1IES &= ~BIT4;
            P1OUT &= ~BIT3;
        }
        else /*Low-To-High*/
        {
            P1IES |= BIT4;
            P1OUT |= BIT3;
        }
    }
    if(0U != (u8Flags & BIT5))
    {
        P1IFG &= ~BIT5;
        u8Status &= MyUpdate();
    }
    if(0U != (u8Flags & BIT6))
    {
        P1IFG &= ~BIT6;
        if(0UL != (u8Edge & BIT6)) /*High-To-Low*/
        {
            P1IES &= ~BIT6;
            P1OUT &= ~BIT1;
        }
        else /*Low-To-High*/
        {
            P1IES |= BIT6;
            P1OUT |= BIT1;
        }
    }
    if(0U != (u8Flags & BIT7))
    {
        P1IFG &= ~BIT7;
        if(0UL != (u8Edge & BIT7)) /*High-To-Low*/
        {
            P1IES &= ~BIT7;
            P1OUT &= ~BIT0;
        }
        else /*Low-To-High*/
        {
            P1IES |= BIT7;
            P1OUT |= BIT0;
        }
    }
    __bic_SR_register_on_exit(u8Status);
}

uint8_t MAIN_u8Interrupt(void)
{
    uint8_t u8Edge = P1IES;
    uint8_t u8Interrupt = __get_interrupt_state();
    _EINT();
    if(0UL != (u8Edge & BIT5)) /*High-To-Low*/
    {
        P1IES &= ~BIT5;
        P1OUT &= ~BIT2;
    }
    else /*Low-To-High*/
    {
        P1IES |= BIT5;
        P1OUT |= BIT2;
    }
    __set_interrupt_state(u8Interrupt);
    return (LPM4_bits);
}

void MAIN_vInitInput(void)
{
    /*P1.4 - P1.7 como entradas*/
    P1DIR &= ~(BIT4 | BIT5 | BIT6 | BIT7);
    /*P1.4 - P1.7 configurar com I/O*/
    P1SEL &= ~(BIT4 | BIT5 | BIT6 | BIT7);

    /*P1.4 - P1.7 Edge select High-To-Low*/
    P1IES |= BIT4 | BIT5 | BIT6 | BIT7;

    /*P1.4 - P1.7 Clear Interrupt Flags*/
    P1IFG &= ~(BIT4 | BIT5 | BIT6 | BIT7);

    /*P1.4 - P1.7 Enable interrupt*/
    P1IE |= BIT4 | BIT5 | BIT6 | BIT7;

}

void MAIN_vInitOutput(void)
{
    /*P1.0 - P1.3 como Salidas*/
    P1DIR |= BIT0 | BIT1 | BIT2 | BIT3;
    /*P1.0 - P1.3 configurar com I/O*/
    P1SEL &= ~(BIT0 | BIT1 | BIT2 | BIT3);

    /*P1.0 - P1.3 logica invertida*/
    P1OUT |= BIT0 | BIT1 | BIT2 | BIT3;
}
