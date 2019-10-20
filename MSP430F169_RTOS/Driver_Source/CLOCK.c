/*
 * CLOCK.h
 *
 *  Created on: 22/01/2019
 *      Author: InDev
 */


/*
 *   SMCLK, MCLK 8  MHz
 *   ACLK        32 KHz
 *
 */
#include "CLOCK.h"

void CLOCK__vConf(void)
{
    /* XT2 ON(highfrequency), LFXT1= Low Frequency, ACLK/1*/
    BCSCTL1&=~(XT2OFF|XTS|DIVA_3);

    /* MCLK= XT2/1 SMCLK= XT2/1*/
    BCSCTL2&=~(SELM_3 | DIVM_3 | DIVS_3);
    BCSCTL2|=SELM_2|SELS;

    /*Delay for OSC stabilitation */
    _delay_cycles(0xFFF);

    /*Enable interrupt*/
    IFG1&=~OFIFG;
    IE1|=OFIE;

}

/*
 *  SMCLK OUT ENABLE P5.5
 *
 */
void CLOCK__vEnOutSMCLK(void)
{
    P5SEL|=BIT5;
    P5DIR|=BIT5;
}

/*
 *  SMCLK OUT DISABLE P5.5
 *
 */
void CLOCK__vDisOutSMCLK(void)
{
    P5SEL&=~BIT5;
    P5DIR&=~BIT5;
}

/*
 *  MCLK OUT ENABLE P5.4
 *
 */
void CLOCK__vEnOutMCLK(void)
{
    P5SEL|=BIT4;
    P5DIR|=BIT4;
}

/*
 *  MCLK OUT DISABLE P5.4
 *
 */
void CLOCK__vDisOutMCLK(void)
{
    P5SEL&=~BIT4;
    P5DIR&=~BIT4;
}

/*
 *  ACLK OUT ENABLE P5.6
 *
 */
void CLOCK__vEnOutACLK(void)
{
    P5SEL|=BIT6;
    P5DIR|=BIT6;
}

/*
 *  ACLK OUT DISABLE P5.6
 *
 */
void CLOCK__vDisOutACLK(void)
{
    P5SEL&=~BIT6;
    P5DIR&=~BIT6;
}
#pragma vector = NMI_VECTOR
__interrupt void OSC_vISR(void)
{
    if(IFG1& OFIFG)
    {
    IFG1&=~OFIFG;
    _NOP();
    }
}


