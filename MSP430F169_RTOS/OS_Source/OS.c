/*
 * OS.c
 *
 * Created: 12/10/2019 09:06:50 a. m.
 *  Author: Lalo
 */ 
#include "os.h"

void OS_vStartOS(void);
void OS_vScheduler(void);
void OS_vSetInitialStack(uint8_t i);


TCB_TypeDef  OS_sTCBs[NUMTHREADS];
TCB_TypeDef* OS_psRunPt;
int16_t   OS_ps16Stacks[NUMTHREADS][STACKSIZE];


uint16_t OS__u16StartCriticalSection(void)
{
	uint16_t u16State=_get_interrupt_state();
	_disable_interrupt();
	return u16State;
}

void OS__vEndCriticalSection(uint16_t u16Status)
{
    _set_interrupt_state(u16Status);
}

void OS_vSetInitialStack(uint8_t i){
	OS_sTCBs[i].sp = &OS_ps16Stacks[i][STACKSIZE-14]; // thread stack pointer
	OS_ps16Stacks[i][STACKSIZE-1] = 0x0101; // PC
	OS_ps16Stacks[i][STACKSIZE-2] = 0x0008; // SR
	OS_ps16Stacks[i][STACKSIZE-3] = 0x1515; // R15
	OS_ps16Stacks[i][STACKSIZE-4] = 0x1414; // R14
	OS_ps16Stacks[i][STACKSIZE-5] = 0x1313; // R13
	OS_ps16Stacks[i][STACKSIZE-6] = 0x1212; // R12
	OS_ps16Stacks[i][STACKSIZE-7] = 0x1111; // R11
	OS_ps16Stacks[i][STACKSIZE-8] = 0x1010; // R10
	OS_ps16Stacks[i][STACKSIZE-9] = 0x0909; // R9
	OS_ps16Stacks[i][STACKSIZE-10] = 0x0808; // R8
	OS_ps16Stacks[i][STACKSIZE-11] = 0x0707; // R7
	OS_ps16Stacks[i][STACKSIZE-12] = 0x0606; // R6
	OS_ps16Stacks[i][STACKSIZE-13] = 0x0505; // R5
	OS_ps16Stacks[i][STACKSIZE-14] = 0x0404; // R4

}

void (*OS_vPeriodicTask0)(void);
void (*OS_vPeriodicTask1)(void);
uint16_t OS_u16PeriodTask0=0, OS_u16PeriodTask1=0;
uint32_t OS_u32MaxPeriod=0;
OS_nStatus OS__enAddPeriodicThreads(void(*vPeriodicTask0)(void), 
uint16_t u16PeriodTask0, void(*vPeriodicTask1)(void), uint16_t u16PeriodTask1)
{
	OS_vPeriodicTask0=vPeriodicTask0;
	OS_vPeriodicTask1=vPeriodicTask1;
	if(u16PeriodTask0!=0)
		OS_u16PeriodTask0=u16PeriodTask0;
	else
		OS_u16PeriodTask0=1;
	if(u16PeriodTask1!=0)
		OS_u16PeriodTask1=u16PeriodTask1;
	else
		OS_u16PeriodTask1=1;
		
	OS_u32MaxPeriod= (OS_u16PeriodTask0*OS_u16PeriodTask1);
	return OS_enOK;
}

OS_nStatus OS__enAddMainThreads(int8_t s8Cant,...)
{
	uint8_t u8Status;
	int8_t s8Pos=0;
	void(*pvTask)(void);
    void(vTask)(void);
	u8Status = OS__u16StartCriticalSection();
	va_list ap; //crea puntero de los argumentos
	va_start(ap, s8Cant);//maneja la memoria de los argumentos empezando desde el ultimo conocido ingresado

	if(s8Cant<1)
	    return OS_enERROR;

	for(s8Pos=0; s8Pos<s8Cant-1; s8Pos++)
	{
	    OS_sTCBs[s8Pos].next = &OS_sTCBs[s8Pos+1]; // 0 points to 1
	}
	OS_sTCBs[s8Cant-1].next= &OS_sTCBs[0];

    for(s8Pos=0; s8Pos<s8Cant; s8Pos++)
    {
        pvTask=(void (*)(void))va_arg(ap,void*);
        OS_vSetInitialStack(s8Pos);
        OS_ps16Stacks[s8Pos][STACKSIZE-1] =((int16_t)pvTask); // PC
    }

    va_end(ap); //reinicia el puntero
	OS_psRunPt = &OS_sTCBs[0];        // thread 0 will run first
	OS__vEndCriticalSection(u8Status);
	return OS_enOK; // successful
}

void OS_vScheduler(void)
{	
	static uint32_t u32Count= 0;
	u32Count%=OS_u32MaxPeriod;
	 if(((uint32_t)u32Count%(uint32_t)OS_u16PeriodTask0) == 0)
	 { 
		 OS_vPeriodicTask0();
	 }
	 if(((uint32_t)u32Count%(uint32_t)OS_u16PeriodTask1) == 0)
	 { 
		 OS_vPeriodicTask1();
	 }	
	u32Count++;
	OS_psRunPt = OS_psRunPt->next; // Round Robin scheduler
}

/* SpinLock semaphore*/

void OS__vInitSemaphore(int8_t *ps8Semaphore, SEMAPHORE_nTypeInit enInitValue)
{
	*ps8Semaphore=(int8_t)enInitValue;
}

void OS__vWaitSemaphore(int8_t *ps8Semaphore)
{
	uint16_t u16Status;
	u16Status = OS__u16StartCriticalSection();
	/*Wait until data are available*/
	while(*ps8Semaphore == 0){
	_enable_interrupt(); /* interrupts can occur here*/
	_nop();
	_disable_interrupt();
	}
	*ps8Semaphore = (*ps8Semaphore) - 1;
	OS__vEndCriticalSection(u16Status);
} 

void OS__vSignalSemaphore(int8_t *ps8Semaphore)
{
	uint16_t u16Status;
	u16Status = OS__u16StartCriticalSection();
	*ps8Semaphore = (*ps8Semaphore) + 1;
	OS__vEndCriticalSection(u16Status);
}



void OS__vLaunch(void){

	/*Clear pending Interrupt of Timer Overflow*/
	TimerB__vClearInterrupt(TimerB_enInterruptCC0);
	/*Enable Interrupt of Timer Overflow*/
	TimerB__vEnableInterrupt(TimerB_enInterruptCC0);
	
	/*Intialization of Timer: Normal Mode MAX and CLK div64 ~~ 1ms*/
	TimerB__vInit(TimerB_enModeUp_TBCL0,TimerB_enClockDiv1,8000-1);

	OS_vStartOS();                   // start on the first task
}

void OS_vStartOS(void)
{
    asm volatile (
            " mov &OS_psRunPt,R15 \n"
            " mov 0(R15),SP \n"
            " nop \n "
            " pop R4 \n"
            " pop R5 \n"
            " pop R6 \n"
            " pop R7 \n"
            " pop R8 \n"
            " pop R9 \n"
            " pop R10 \n"
            " pop R11 \n"
            " pop R12 \n"
            " pop R13 \n"
            " pop R14 \n"
            " pop R15 \n"
            " pop SR \n"
            );
}





#pragma vector=TIMERB0_VECTOR
__interrupt void TIMERB0_IRQ(void)
{
	asm volatile (
    " push R15 \n"
    " push R14 \n"
    " push R13 \n"
    " push R12 \n"
    " push R11 \n"
    " push R10 \n"
    " push R9 \n"
    " push R8 \n"
    " push R7 \n"
    " push R6 \n"
    " push R5 \n"
    " push R4 \n"
    " mov &OS_psRunPt,R15 \n"
    " mov SP,0(R15) \n"
	" push R15 \n "

	" mov.w #OS_vScheduler,R15 \n"
	" CALL   R15 ; \n\t"

    " pop R15 \n "
    " mov.w &OS_psRunPt,R15 \n"
    " mov.w 0(R15),SP \n"
	
    " nop \n "
    " pop R4 \n"
    " pop R5 \n"
    " pop R6 \n"
    " pop R7 \n"
    " pop R8 \n"
    " pop R9 \n"
    " pop R10 \n"
    " pop R11 \n"
    " pop R12 \n"
    " pop R13 \n"
    " pop R14 \n"
    " pop R15 \n"
	);
}
