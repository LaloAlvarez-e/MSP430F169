#include <msp430.h> 
void InitPort(void);

int GlobalVariable;

/**
 * main.c
 */
void main(void)
{
    long int retardo = 0U;
	WDTCTL = WDTPW | WDTHOLD;	/* stop watchdog timer */
	InitPort();

	while(1U) /*for( ; ; )*/
	{
	    GlobalVariable++;
	    P3OUT &= ~BIT4; /*P3.4 Bajo*/
	    for(retardo = 0U; retardo < 80000U; retardo++);
	    P3OUT |= BIT4; /*P3.4 Alto*/
	    for(retardo = 0U; retardo < 80000U; retardo++);
	}
}


void InitPort(void)
{
    /*PxDIR indica direccion 0= entrada , 1= salida
     * 1Byte = 8Bits
     * 1Bit = 1Pin
     * bit0 = Pin0 0x1U  00000001
     * bit1 = Pin1 0x2U  00000010
     * bit2 = Pin2 0x4U  00000100
     * bit3 = Pin3 0x8U  00001000
     * bit4 = Pin4 0x10U 00010000
     * bit5 = Pin5 0x20U 00100000
     * bit6 = Pin6 0x40U 01000000
     * bit7 = Pin7 0x80U 10000000
     *
     * 0bxxxxxxxx
     *
     * OR: (|) Setea los bits en 1
     *      0bxxxxxxxx (valor)
     *    | 0b00010000 (mascara)
     *      __________
     *      0bxxx1xxxx
     * AND: (&) Setea los bits en 0
     * NOT: (~) invierte bits
     *
     * 0b00010000 (mascara) invertido = 0b11101111
     *      0bxxxxxxxx (valor)
     *  & ~(0b00010000) (mascara)
     *      0b11101111
     *      __________
     *      0bxxx0xxxx
     *
     *
     * AND = &
     * NOT = ~
     * XOR = ^
     * */
    /*P3DIR = P3DIR | BIT4;*/
    P3DIR |= BIT4; /*Setea com salida el pin P3.4*/
    /*P3SEL = P3SEL & (~BIT4);*/
    P3SEL &= ~BIT4; /*Seleccion como I/O el pin P3.4*/
    /*P3OUT = P3OUT & (~BIT4);*/
    P3OUT &= ~BIT4; /*Estado inicial del pin P3.4 en GND o Bajo*/
}
