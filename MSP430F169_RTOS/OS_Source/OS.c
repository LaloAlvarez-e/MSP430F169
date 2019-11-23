/*
 * OS.c
 *
 * Created: 12/10/2019 09:06:50 a. m.
 *  Author: Lalo
 */ 
#include "os.h"

void OS_vStartOS(void);
void OS_vScheduler(void);
void OS_vSetInitialStack(TCB_TypeDef*  psTCB,void(*pvTask)(void));


TCB_TypeDef* OS_psRunPt =0;


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

void OS_vSetInitialStack(TCB_TypeDef*  psTCB,void(*pvTask)(void))
{
    psTCB->topOfStack =psTCB->endOfStack-13; // thread stack pointer
    psTCB->endOfStack[0] = (int16_t)pvTask; // PC
    psTCB->endOfStack[-1] = 0x0008; // SR
    psTCB->endOfStack[-2] = 0x1515; // R15
    psTCB->endOfStack[-3] = 0x1414; // R14
    psTCB->endOfStack[-4] = 0x1313; // R13
    psTCB->endOfStack[-5] = 0x1212; // R12
    psTCB->endOfStack[-6] = 0x1111; // R11
    psTCB->endOfStack[-7] = 0x1010; // R10
    psTCB->endOfStack[-8] = 0x0909; // R9
    psTCB->endOfStack[-9] = 0x0808; // R8
    psTCB->endOfStack[-10] = 0x0707; // R7
    psTCB->endOfStack[-11] = 0x0606; // R6
    psTCB->endOfStack[-12] = 0x0505; // R5
    psTCB->endOfStack[-13] = 0x0404; // R4

}

void (*OS_vPeriodicTask[10])(void);
uint16_t OS_u16PeriodTask[10];
uint32_t OS_u32MaxPeriod=0;
int8_t OS_s8PeriodicTaskCount=0;
int8_t OS_s8MainTaskCount=0;
OS_nStatus OS__enAddPeriodicThreads(int8_t s8Cant,...)
{
    return OS_enOK;
}

TCB_TypeDef* OS__psAddMainThreads(void(*pvTask)(void),char* pcName,uint16_t u16StackSize)
{
	uint8_t u8Status;
	int8_t s8Pos=0;
	TCB_TypeDef * psNewTCB;

    u8Status = OS__u16StartCriticalSection();
	psNewTCB= (TCB_TypeDef*)malloc(sizeof(TCB_TypeDef));
	if(psNewTCB!=0)
	{
	    psNewTCB->stack= (int16_t*)malloc(u16StackSize*sizeof(int16_t));
	    psNewTCB->stack=(int16_t*)(((int16_t)psNewTCB->stack)&~(1)); //aligment a 2 bytes
	    if( psNewTCB->stack==0)
	    {
            free( psNewTCB );
            psNewTCB = 0;
            return 0;
	    }
	}

	while((*pcName!=0) && (s8Pos<(TASK_NAME_LENGHT-1)))
	{
	    psNewTCB->name[s8Pos]=pcName[s8Pos];
	    s8Pos++;
	    pcName++;
	}
	psNewTCB->name[s8Pos]=0;

	psNewTCB->nextblockedTask = OS_enUnblocked;
	psNewTCB->state= OS_enRunning;
	psNewTCB->sleep = OS_enAwake;

	psNewTCB->endOfStack=psNewTCB->stack+(u16StackSize-1);
	psNewTCB->endOfStack=(int16_t*)(((int16_t)psNewTCB->endOfStack)&~(1)); //aligment a 2 bytes


    OS_vSetInitialStack(psNewTCB,pvTask);



    OS_s8MainTaskCount++;
     if(OS_psRunPt==0)
     {
         OS_psRunPt = psNewTCB;
         OS_psRunPt->next=psNewTCB;
         OS_psRunPt->first=psNewTCB;
         OS_psRunPt->previous=0;

     }
     else
     {
         psNewTCB->next=OS_psRunPt->first;
         psNewTCB->first=OS_psRunPt->first;
         psNewTCB->previous=OS_psRunPt;
         OS_psRunPt->next=psNewTCB;
         OS_psRunPt=psNewTCB;
     }
	OS__vEndCriticalSection(u8Status);
	return psNewTCB; // successful
}

void OS_vScheduler(void)
{	
    TCB_TypeDef *psActualPt =OS_psRunPt;
    TCB_TypeDef *psBestPt=OS_psRunPt->next;

    do
    {
        psActualPt = psActualPt->next; // Round Robin scheduler
        if(psActualPt->state==OS_enRunning)
        {
                psBestPt=psActualPt;
                break;
        }

    }while(OS_psRunPt != psActualPt);
    OS_psRunPt=psBestPt;
}

/* SpinLock semaphore*/

void OS__vInitSemaphore(OS_Semaphore_TypeDef *psSemaphore, SEMAPHORE_nTypeInit enInitValue)
{
	psSemaphore->value=(int8_t)enInitValue;
    psSemaphore->firstBlockedTask=OS_enUnblocked;
    psSemaphore->lastBlockedTask=OS_enUnblocked;
}

void OS__vWaitSemaphore(OS_Semaphore_TypeDef *psSemaphore)
{
	uint16_t u16Status;
	u16Status = OS__u16StartCriticalSection();
    psSemaphore->value = (psSemaphore->value) - 1;

	if(psSemaphore->value < 0)
	{
	    if(psSemaphore->firstBlockedTask == OS_enUnblocked)
	        psSemaphore->firstBlockedTask=OS_psRunPt;
	    else
	        psSemaphore->lastBlockedTask->nextblockedTask=OS_psRunPt;

        psSemaphore->lastBlockedTask=OS_psRunPt;
        psSemaphore->lastBlockedTask->nextblockedTask=0;
        OS_psRunPt->state|=OS_enBlocked;
        OS__vEndCriticalSection(u16Status);
        OS__vSuspendMainThead();
	}
	OS__vEndCriticalSection(u16Status);
} 

void OS__vSignalSemaphore(OS_Semaphore_TypeDef *psSemaphore)
{
	uint16_t u16Status;
    TCB_TypeDef* psActualPt =psSemaphore->firstBlockedTask;
	u16Status = OS__u16StartCriticalSection();
	psSemaphore->value = (psSemaphore->value) + 1;
    if(psActualPt!=0)
    {


        psActualPt->state&=~OS_enBlocked;
        psSemaphore->firstBlockedTask=psActualPt->nextblockedTask;
        psActualPt=psActualPt->nextblockedTask;
        while(psActualPt!=0)
        {
            psSemaphore->lastBlockedTask=psActualPt;
            psActualPt=psActualPt->nextblockedTask;
        };
    }
	OS__vEndCriticalSection(u16Status);
}


void OS__vInitMailBox(OS_MailBox_TypeDef* psMailBox)
{
    psMailBox->data=0;  // shared data
    psMailBox->semaphore.firstBlockedTask=0; // semaphore
    psMailBox->semaphore.lastBlockedTask=0; // semaphore
    OS__vInitSemaphore(&psMailBox->semaphore,SEMAPHORE_enInitSYNC);
    psMailBox->lost=0; // lost data

}

void OS__vInitMailBoxFIFO(OS_MailBoxFIFO_TypeDef* psMailBoxFIFO)
{
    psMailBoxFIFO->get=psMailBoxFIFO->buffer;
    psMailBoxFIFO->put=psMailBoxFIFO->buffer;
    psMailBoxFIFO->lost=0;
    psMailBoxFIFO->init=0;
    OS__vInitSemaphore(&psMailBoxFIFO->semaphoreCOUNTER,SEMAPHORE_enInitSYNC);
    OS__vInitSemaphore(&psMailBoxFIFO->semaphoreMUTEX,SEMAPHORE_enInitMUTEX);
}



void OS__vSendMailBox_MAIN(OS_MailBox_TypeDef* psMailBox,uint32_t u32Data)
{
    uint16_t u16Status;
    u16Status = OS__u16StartCriticalSection();
    psMailBox->data= u32Data;
    OS__vEndCriticalSection(u16Status);
    if(psMailBox->semaphore.value > 0)
        psMailBox->lost++;
    else
      OS__vSignalSemaphore(&psMailBox->semaphore);
}

void OS__vSendMailBox_EVENT(OS_MailBox_TypeDef* psMailBox,uint32_t u32Data)
{
    OS__vSendMailBox_MAIN(psMailBox,u32Data);
}

OS_nFifo OS__enSendMailBoxFIFO_EVENT(OS_MailBoxFIFO_TypeDef* psMailBoxFIFO,uint32_t u32Data)
{
    if(psMailBoxFIFO->semaphoreCOUNTER.value == OS_FIFOSIZE)
    {
        psMailBoxFIFO->lost++;
        return OS_enFifoFULL;
    }
    *(psMailBoxFIFO->put)=u32Data;
    psMailBoxFIFO->put++;
    if(psMailBoxFIFO->put == &psMailBoxFIFO->buffer[OS_FIFOSIZE])
    {
        psMailBoxFIFO->put =psMailBoxFIFO->buffer;
    }
    OS__vSignalSemaphore(&psMailBoxFIFO->semaphoreCOUNTER);
    return OS_enFifoOK;
}

OS_nFifo OS__enSendMailBoxFIFO_MAIN(OS_MailBoxFIFO_TypeDef* psMailBoxFIFO,uint32_t u32Data)
{

    if(psMailBoxFIFO->semaphoreCOUNTER.value == OS_FIFOSIZE)
    {
        psMailBoxFIFO->lost++;
        return OS_enFifoFULL;
    }
    OS__vWaitSemaphore(&psMailBoxFIFO->semaphoreMUTEX);

    *(psMailBoxFIFO->put)=u32Data;
    psMailBoxFIFO->put++;
    if(psMailBoxFIFO->put == &psMailBoxFIFO->buffer[OS_FIFOSIZE])
    {
        psMailBoxFIFO->put =psMailBoxFIFO->buffer;
    }

    OS__vSignalSemaphore(&psMailBoxFIFO->semaphoreMUTEX);
    OS__vSignalSemaphore(&psMailBoxFIFO->semaphoreCOUNTER);
    return OS_enFifoOK;
}

OS_nFifo OS__enReadMailBox_MAIN(OS_MailBox_TypeDef* psMailBox, uint32_t* u32Value)
{
    uint16_t u16Status;
    OS__vWaitSemaphore(&psMailBox->semaphore);
    u16Status = OS__u16StartCriticalSection();
    *u32Value=psMailBox->data;
    OS__vEndCriticalSection(u16Status);
    return OS_enFifoOK; // read mail
}

OS_nFifo OS__enReadMailBox_EVENT(OS_MailBox_TypeDef* psMailBox, uint32_t* u32Value)
{
    uint16_t u16Status;
    if(psMailBox->semaphore.value <= 0)
        return OS_enFifoEMPTY;
    OS__vWaitSemaphore(&psMailBox->semaphore);
    u16Status = OS__u16StartCriticalSection();
    *u32Value=psMailBox->data;
    OS__vEndCriticalSection(u16Status);
    return OS_enFifoOK; // read mail
}

OS_nFifo OS__enReadMailBoxFIFO_EVENT(OS_MailBoxFIFO_TypeDef* psMailBoxFIFO,uint32_t* u32Data)
{
    if(psMailBoxFIFO->semaphoreCOUNTER.value <= 0)
    {
        return OS_enFifoEMPTY;
    }

    OS__vWaitSemaphore(&psMailBoxFIFO->semaphoreCOUNTER);

    *u32Data=*(psMailBoxFIFO->get);
    psMailBoxFIFO->get++;
    if(psMailBoxFIFO->get == &psMailBoxFIFO->buffer[OS_FIFOSIZE])
    {
        psMailBoxFIFO->get =psMailBoxFIFO->buffer;
    }

    return OS_enFifoOK;
}


OS_nFifo OS__enReadMailBoxFIFO_MAIN(OS_MailBoxFIFO_TypeDef* psMailBoxFIFO,uint32_t* u32Data)
{
    OS__vWaitSemaphore(&psMailBoxFIFO->semaphoreCOUNTER);
    OS__vWaitSemaphore(&psMailBoxFIFO->semaphoreMUTEX);

    *u32Data=*(psMailBoxFIFO->get);
    psMailBoxFIFO->get++;
    if(psMailBoxFIFO->get == &psMailBoxFIFO->buffer[OS_FIFOSIZE])
    {
        psMailBoxFIFO->get =psMailBoxFIFO->buffer;
    }
    OS__vSignalSemaphore(&psMailBoxFIFO->semaphoreMUTEX);
    return OS_enFifoOK;
}


uint32_t OS__u32GetDataMailBox(OS_MailBox_TypeDef* psMailBox)
{
    return psMailBox->data; // read mail
}

uint8_t OS__u8GetLostMailBox(OS_MailBox_TypeDef* psMailBox)
{
    return psMailBox->lost; // read mail
}

int8_t OS__u32GetSemaphoreMailBox(OS_MailBox_TypeDef* psMailBox)
{
    return psMailBox->semaphore.value; // read mail
}




void OS__vLaunch(void){

    Watchdog__vClearInterrupt(Watchdog_enInterruptWDT);
    Watchdog__vEnableInterrupt(Watchdog_enInterruptWDT);
    TimerB__vClearInterrupt(TimerB_enInterruptCC0);
    TimerB__vEnableInterrupt(TimerB_enInterruptCC0);
    TimerB__vInit(TimerB_enModeUp_TBCL0,TimerB_enClockDiv1,8000-1);
    Watchdog__vInit(Watchdog_enModeInterval,Watchdog_enClockSMCLK,Watchdog_enDiv8192);
	OS_vStartOS();                   // start on the first task
}



void OS__vSuspendMainThead(void)
{
    Watchdog__vClearCount();
    Watchdog__vSetInterrupt(Watchdog_enInterruptWDT);
}


uint16_t OS__u16GetStackUsedThread(void)
{
    return (uint16_t)OS_psRunPt->endOfStack-(uint16_t)OS_psRunPt->topOfStack;
}

uint16_t OS__u16GetStackSizeThread(void)
{
    return (uint16_t)OS_psRunPt->endOfStack-(uint16_t)OS_psRunPt->stack;
}

uint16_t OS__u16GetPorcentageStackThread(void)
{
    float fPorcentage=0.0;

    fPorcentage=(float)OS__u16GetStackUsedThread()*100.0;
    fPorcentage/=(float)OS__u16GetStackSizeThread();
    return fPorcentage;

}
/*
OS_Sleep_TypeDef OS_sSleep;
void OS__vInitSleep(void)
{
    OS_sSleep.firstSleepTask=OS_enAwake;
    OS_sSleep.lastSleepTask=OS_enAwake;

}
*/
void OS__vSleepMainThead(uint16_t u16Sleep)
{
    uint16_t u16Status;
    u16Status = OS__u16StartCriticalSection();
    OS_psRunPt->state|=OS_enSleep;
    OS_psRunPt->sleep=u16Sleep;
    OS__vEndCriticalSection(u16Status);
    OS__vSuspendMainThead();

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

    TCB_TypeDef* OS_psActual =OS_psRunPt;
    do{
        OS_psActual->sleep--;
        if(OS_psActual->sleep<=0)
        {
            OS_psActual->state&=~OS_enSleep;
            OS_psActual->sleep=0;

        }
        OS_psActual=OS_psActual->next;
    }while(OS_psActual!=OS_psRunPt);
}

#pragma vector=WDT_VECTOR
__interrupt void WDT_IRQ(void)
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
