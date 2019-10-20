/*
 * TimerB.c
 *
 * Created: 11/10/2019 12:39:23 p. m.
 *  Author: Lalo
 */ 

#include <TimerB.h>

uint16_t TimerB_u16CounterOV=0;
uint16_t TimerB_u8CompareValueOC0=0;
uint16_t TimerB_u8CompareValueOC1=0;
uint16_t TimerB_u8CompareValueOC2=0;
uint16_t TimerB_u8CompareValueOC3=0;
uint16_t TimerB_u8CompareValueOC4=0;
uint16_t TimerB_u8CompareValueOC5=0;
uint16_t TimerB_u8CompareValueOC6=0;
uint16_t TimerB_u8CompareValueOC7=0;

void TimerB__vInit(TimerB_nMode enMode, TimerB_nClock enClockSource, uint16_t u16Tick )
{
	TBCTL=TBSSEL_2;
    TBCTL|=((uint8_t)enClockSource&0x3)<<6;
    TBCTL|=((uint8_t)enMode&0x3)<<4;
    TBCCR0=u16Tick;
	TBR=0;
}


void TimerB__vSetOutputMode(TimerB_nCompareModule enModule,TimerB_nCompareOutput enOutMode)
{
	if(enModule&TimerB_enModule0)
	{
	    TBCCTL0=CLLD_1;
	    TBCCTL0|=(((uint8_t)enOutMode&7)<<5);
	}
	if(enModule&TimerB_enModule1)
	{
        TBCCTL1=CLLD_1;
        TBCCTL1|=(((uint8_t)enOutMode&7)<<5);
	}
    if(enModule&TimerB_enModule2)
    {
        TBCCTL2=CLLD_1;
        TBCCTL2|=(((uint8_t)enOutMode&7)<<5);
    }
    if(enModule&TimerB_enModule3)
    {
        TBCCTL3=CLLD_1;
        TBCCTL3|=(((uint8_t)enOutMode&7)<<5);
    }
    if(enModule&TimerB_enModule4)
    {
        TBCCTL4=CLLD_1;
        TBCCTL4|=(((uint8_t)enOutMode&7)<<5);
    }
    if(enModule&TimerB_enModule5)
    {
        TBCCTL5=CLLD_1;
        TBCCTL5|=(((uint8_t)enOutMode&7)<<5);
    }
    if(enModule&TimerB_enModule6)
    {
        TBCCTL6=CLLD_1;
        TBCCTL6|=(((uint8_t)enOutMode&7)<<5);
    }

	
}

void TimerB__vSetCompareValue(TimerB_nCompareModule enModule,uint16_t u16Value)
{

    if(enModule&TimerB_enModule0)
    {
        TimerB_u8CompareValueOC0=u16Value;
        TBCCR0=u16Value;
    }
    if(enModule&TimerB_enModule1)
    {
        TimerB_u8CompareValueOC1=u16Value;
        TBCCR1=u16Value;
    }
    if(enModule&TimerB_enModule2)
    {
        TimerB_u8CompareValueOC2=u16Value;
        TBCCR2=u16Value;
    }
    if(enModule&TimerB_enModule3)
    {
        TimerB_u8CompareValueOC3=u16Value;
        TBCCR3=u16Value;
    }
    if(enModule&TimerB_enModule4)
    {
        TimerB_u8CompareValueOC4=u16Value;
        TBCCR4=u16Value;
    }
    if(enModule&TimerB_enModule5)
    {
        TimerB_u8CompareValueOC5=u16Value;
        TBCCR5=u16Value;
    }
    if(enModule&TimerB_enModule6)
    {
        TimerB_u8CompareValueOC6=u16Value;
        TBCCR6=u16Value;
    }
}



void TimerB__vSetCount(uint16_t u16Count)
{	
    TBR=u16Count;
}

void TimerB__vClearCount(void)
{
    TBR=0;
}

void TimerB__vEnableInterrupt(TimerB_nInterrupt enInterrupt)
{
    if(enInterrupt&TimerB_enInterruptTB)
    {
        TBCTL|=TBIE;
    }
    if(enInterrupt&TimerB_enInterruptCC0)
    {
        TBCCTL0|=CCIE;
    }
    if(enInterrupt&TimerB_enInterruptCC1)
    {
        TBCCTL1|=CCIE;
    }
    if(enInterrupt&TimerB_enInterruptCC2)
    {
        TBCCTL2|=CCIE;
    }
    if(enInterrupt&TimerB_enInterruptCC3)
    {
        TBCCTL3|=CCIE;
    }
    if(enInterrupt&TimerB_enInterruptCC4)
    {
        TBCCTL4|=CCIE;
    }
    if(enInterrupt&TimerB_enInterruptCC5)
    {
        TBCCTL5|=CCIE;
    }
    if(enInterrupt&TimerB_enInterruptCC6)
    {
        TBCCTL6|=CCIE;
    }
	
}
void TimerB__vDisableInterrupt(TimerB_nInterrupt enInterrupt)
{
    if(enInterrupt&TimerB_enInterruptTB)
    {
        TBCTL&=~TBIE;
    }
    if(enInterrupt&TimerB_enInterruptCC0)
    {
        TBCCTL0&=~CCIE;
    }
    if(enInterrupt&TimerB_enInterruptCC1)
    {
        TBCCTL1&=~CCIE;
    }
    if(enInterrupt&TimerB_enInterruptCC2)
    {
        TBCCTL2&=~CCIE;
    }
    if(enInterrupt&TimerB_enInterruptCC3)
    {
        TBCCTL3&=~CCIE;
    }
    if(enInterrupt&TimerB_enInterruptCC4)
    {
        TBCCTL4&=~CCIE;
    }
    if(enInterrupt&TimerB_enInterruptCC5)
    {
        TBCCTL5&=~CCIE;
    }
    if(enInterrupt&TimerB_enInterruptCC6)
    {
        TBCCTL6&=~CCIE;
    }
}
void TimerB__vClearInterrupt(TimerB_nInterrupt enInterrupt)
{
    if(enInterrupt&TimerB_enInterruptTB)
    {
        TBCTL&=~TBIFG;
    }
    if(enInterrupt&TimerB_enInterruptCC0)
    {
        TBCCTL0&=~CCIFG;
    }
    if(enInterrupt&TimerB_enInterruptCC1)
    {
        TBCCTL1&=~CCIFG;
    }
    if(enInterrupt&TimerB_enInterruptCC2)
    {
        TBCCTL2&=~CCIFG;
    }
    if(enInterrupt&TimerB_enInterruptCC3)
    {
        TBCCTL3&=~CCIFG;
    }
    if(enInterrupt&TimerB_enInterruptCC4)
    {
        TBCCTL4&=~CCIFG;
    }
    if(enInterrupt&TimerB_enInterruptCC5)
    {
        TBCCTL5&=~CCIFG;
    }
    if(enInterrupt&TimerB_enInterruptCC6)
    {
        TBCCTL6&=~CCIFG;
    }
	
}void TimerB__vSetInterrupt(TimerB_nInterrupt enInterrupt)
{
    if(enInterrupt&TimerB_enInterruptTB)
    {
        TBCTL|=TBIFG;
    }
    if(enInterrupt&TimerB_enInterruptCC0)
    {
        TBCCTL0|=CCIFG;
    }
    if(enInterrupt&TimerB_enInterruptCC1)
    {
        TBCCTL1|=CCIFG;
    }
    if(enInterrupt&TimerB_enInterruptCC2)
    {
        TBCCTL2|=CCIFG;
    }
    if(enInterrupt&TimerB_enInterruptCC3)
    {
        TBCCTL3|=CCIFG;
    }
    if(enInterrupt&TimerB_enInterruptCC4)
    {
        TBCCTL4|=CCIFG;
    }
    if(enInterrupt&TimerB_enInterruptCC5)
    {
        TBCCTL5|=CCIFG;
    }
    if(enInterrupt&TimerB_enInterruptCC6)
    {
        TBCCTL6|=CCIFG;
    }

}
void TimerB__vClearCounterOV(void)
{
	TimerB_u16CounterOV=0;
	
}
uint16_t TimerB__u16GetCounterOV(void)
{
	return (uint16_t)TimerB_u16CounterOV;
}
