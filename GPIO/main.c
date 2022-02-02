#include <msp430.h> 
#include "stdint.h"

void MAIN_vInitInput(void);
void MAIN_vInitOutput(void);

/**
 * main.c
 */
void main(void)
{
    uint8_t u8SwitchValue = 0U;
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	MAIN_vInitInput();
	MAIN_vInitOutput();

	while(1U)
	{
	    u8SwitchValue = P1IN;
	    /*P1.4 check*/
	    if(0UL != (u8SwitchValue & BIT4)) /*SwitchNoPress (Pull-up)*/
	    {
	        P1OUT |= BIT3;
            P1OUT |= BIT0;
	    }
	    else /*SwitchPress*/
	    {
	        P1OUT &= ~BIT3;
            P1OUT &= ~BIT0;
	    }
	}
}

void MAIN_vInitInput(void)
{
    /*P1.4 - P1.7 como entradas*/
    P1DIR &= ~(BIT4 | BIT5 | BIT6 | BIT7);
    /*P1.4 - P1.7 configurar com I/O*/
    P1SEL &= ~(BIT4 | BIT5 | BIT6 | BIT7);

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
