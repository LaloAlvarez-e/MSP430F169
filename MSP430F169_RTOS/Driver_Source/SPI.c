/*
 * SPI.c
 *
 * Created: 16/10/2019 08:32:09 p. m.
 *  Author: Lalo
 */ 

#include "SPI.h"
void SPI__vDeInit(void)
{
    U0CTL=SWRST;
    U0BR0=0;
    U0BR1=0;
    U0MCTL=0;
    U0RCTL=0;
    U0TCTL=0;
    ME1=0;
    IE1&=~(UTXIE0|URXIE0);
}

void SPI__vInit(SPI_nMode enMode,SPI_nDataOrder enDataOrder,SPI_nClockPolarity enPolarity, SPI_nClockPhase enPhase, SPI_nClock enClockSource )
{

    /* SPI MODE, 8bit, MASTER*/
    U0CTL|=SWRST;
    U0CTL|=SYNC|CHAR;
    U0CTL&=~(I2C|LISTEN);
	if(enMode == SPI_enModeSlave)
	{
	    U0CTL&=~(MM);
	    U0TCTL=0;
	}
	else
	{
	    U0CTL|=MM;
        U0TCTL=SSEL1|SSEL0|STC;
	}
		
	if(enPolarity == SPI_enClockIdleLow)
	    U0TCTL&=~(CKPL);
	else
	    U0TCTL|=(CKPL);
		
	if(enPhase == SPI_enClockSampleFirst)
        U0TCTL|=(CKPH);
	else
        U0TCTL&=~(CKPH);


    U0RCTL=0;
    U0MCTL=0;

	switch(enClockSource)
	{
		case SPI_enClockDiv2:
		    U0BR0=2;
		    U0BR1=0;
			break;
		case SPI_enClockDiv4:
		    U0BR0=4;
		    U0BR1=0;
			break;
		case SPI_enClockDiv8:
		    U0BR0=8;
		    U0BR1=0;
			break;
		case SPI_enClockDiv16:
		    U0BR0=16;
		    U0BR1=0;
			break;
		case SPI_enClockDiv32:
		    U0BR0=32;
		    U0BR1=0;
			break;
		case SPI_enClockDiv64:
		    U0BR0=64;
		    U0BR1=0;
			break;
		case SPI_enClockDiv64_1:
		    U0BR0=64;
		    U0BR1=0;
			break;
		case SPI_enClockDiv128:
		    U0BR0=128;
		    U0BR1=0;
			break;
		default:
			break;
	}



    ME1|=USPIE0;
    U0CTL&=~SWRST;
}


void SPI__vEnableInterrupt(void)
{
    IFG1=0;
    IE1|=UTXIE0|URXIE0;
}

void SPI__vDisableInterrupt(void)
{
    IFG1=0;
    IE1&=~(UTXIE0|URXIE0);
}


void SPI__vInitPin(SPI_nPin enPin)
{
	if((enPin&SPI_enPinCLK)==SPI_enPinCLK)
	{
		P3SEL|=BIT3;
	}
	
	if((enPin&SPI_enPinMISO)==SPI_enPinMISO)
	{
        P3SEL|=BIT2;
	}
			
	if((enPin&SPI_enPinMOSI)==SPI_enPinMOSI)
	{
        P3SEL|=BIT1;
	}
	if((enPin&SPI_enPinSS)==SPI_enPinSS)
	{
	    P3DIR|=BIT0;
	    P3OUT|=BIT0;
	    P3SEL&=~BIT0;
	}		
}
void SPI__vDeInitPin(SPI_nPin enPin)
{
	if((enPin&SPI_enPinCLK)==SPI_enPinCLK)
	{
        P3SEL&=~BIT3;
	}
	
	if((enPin&SPI_enPinMISO)==SPI_enPinMISO)
	{
        P3SEL&=~BIT2;
	}
	
	if((enPin&SPI_enPinMOSI)==SPI_enPinMOSI)
	{
        P3SEL&=~BIT1;
	}
	if((enPin&SPI_enPinSS)==SPI_enPinSS)
	{
        P3DIR&=~BIT0;
	}	
}

void SPI__vSendReceiveDataMaster(uint8_t* pu8DataOut, uint8_t* pu8DataIn, int16_t s16DataNumber )
{
	IFG1&=~(UTXIFG0|URXIFG0);
	*pu8DataIn=U0RXBUF;
    P3OUT&=~BIT0;
	while((uint16_t)s16DataNumber>0)
	{
	    U0TXBUF=*pu8DataOut;
		while((IFG1&(UTXIFG0))==0);
	    IFG1&=~(UTXIFG0);
		*pu8DataIn=U0RXBUF;
		pu8DataIn++;
		pu8DataOut++;
		s16DataNumber--;
	}

    P3OUT|=BIT0;
}

void SPI__vSendDataMaster(uint8_t* pu8DataOut,int16_t s16DataNumber )
{
	uint8_t u8Dummy=0;
    IFG1&=~(UTXIFG0|URXIFG0);
    u8Dummy=U0RXBUF;

    P3OUT&=~BIT0;
	while((uint16_t)s16DataNumber>0)
	{
	    U0TXBUF=*pu8DataOut;
        while((IFG1&(UTXIFG0))==0);
        IFG1&=~(UTXIFG0);
		u8Dummy=U0RXBUF;
		pu8DataOut++;
		s16DataNumber--;
	}

    P3OUT|=BIT0;
}
