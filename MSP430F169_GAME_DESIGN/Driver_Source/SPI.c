/*
 * SPI.c
 *
 * Created: 16/10/2019 08:32:09 p. m.
 *  Author: Lalo
 */ 

#include "SPI.h"
#include <DriverLib/DriverLib.h>

void SPI__vInit(SPI_nMode enMode,SPI_nDataOrder enDataOrder,SPI_nClockPolarity enPolarity, SPI_nClockPhase enPhase, uint16_t u16ClockDiv )
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
        U0TCTL&=~(CKPH);
	else
        U0TCTL|=(CKPH);


    U0RCTL=0;
    U0MCTL=0;

    if(u16ClockDiv < 2U)
    {
        u16ClockDiv = 2U;
    }
    U0BR0=u16ClockDiv & 0xFFU;
    U0BR1=(u16ClockDiv >> 8U) & 0xFFU;


    ME1|=USPIE0;
    U0CTL&=~SWRST;
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
}

void SPI__vSendByte(uint8_t u8DataOut)
{
    static uint8_t u8Dummy=0;
    while(0U == (IFG1 & UTXIFG0));
    U0TXBUF = u8DataOut;
}

void SPI__vSendMultiByte(uint8_t* pu8DataOut,uint16_t u16DataNumber)
{
    if(0U != (uintptr_t) pu8DataOut)
    {
        while(0UL < u16DataNumber)
        {
            SPI__vSendByte(*pu8DataOut);
            pu8DataOut++;
            u16DataNumber--;
        }
    }
}
