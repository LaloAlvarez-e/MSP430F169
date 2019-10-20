/*
 * TimerB.h
 *
 * Created: 11/10/2019 12:39:08 p. m.
 *  Author: Lalo
 */ 


#ifndef TimerB_H_
#define TimerB_H_

#include <msp430f169.h>
#include <intrinsics.h>
#include <stdint.h>
#include <GPIO.h>
typedef enum
{
	TimerB_enModeDisable   =0,
	TimerB_enModeUp_TBCL0 ,
	TimerB_enModeUp_MAX,
	TimerB_enModeUpDown_TBCL0,
}TimerB_nMode;

typedef enum
{
	TimerB_enCompareOUT   =0,
	TimerB_enCompareSet=1,
	TimerB_enCompareToggle_Reset=2,
	TimerB_enCompareSet_Reset=3,
    TimerB_enCompareToggle=4,
    TimerB_enCompareReset=5,
    TimerB_enCompareToggle_Set=6,
    TimerB_enCompareReset_Set=7,
}TimerB_nCompareOutput;

typedef enum
{
	TimerB_enModule0  =1,
	TimerB_enModule1  =2,
    TimerB_enModule2  =4,
    TimerB_enModule3  =8,
    TimerB_enModule4  =0x10,
    TimerB_enModule5  =0x20,
    TimerB_enModule6  =0x40,
    TimerB_enModule7  =0x80,
}TimerB_nCompareModule;

typedef enum
{
    TimerB_enClockDiv1   =0,
	TimerB_enClockDiv2,
	TimerB_enClockDiv4,
	TimerB_enClockDiv8,
}TimerB_nClock;

typedef enum
{
	TimerB_enInterruptTB   =1,
	TimerB_enInterruptCC0	 =2,
	TimerB_enInterruptCC1  =4,
    TimerB_enInterruptCC2  =8,
    TimerB_enInterruptCC3  =0x10,
    TimerB_enInterruptCC4  =0x20,
    TimerB_enInterruptCC5  =0x40,
    TimerB_enInterruptCC6  =0x80,
    TimerB_enInterruptCC7  =0x100,
}TimerB_nInterrupt;

void TimerB__vInit(TimerB_nMode enMode, TimerB_nClock enClockSource, uint16_t u16Tick );

void TimerB__vSetOutputMode(TimerB_nCompareModule enModule,TimerB_nCompareOutput enOutMode);
void TimerB__vSetCompareValue(TimerB_nCompareModule enModule,uint16_t u16Value);

void TimerB__vSetCount(uint16_t u16Count);
void TimerB__vClearCount(void);

void TimerB__vEnableInterrupt(TimerB_nInterrupt enInterrupt);
void TimerB__vDisableInterrupt(TimerB_nInterrupt enInterrupt);
void TimerB__vSetInterrupt(TimerB_nInterrupt enInterrupt);
void TimerB__vClearInterrupt(TimerB_nInterrupt enInterrupt);


void TimerB__vClearCounterOV(void);
uint16_t TimerB__u16GetCounterOV(void);

#endif /* TimerB_H_ */
