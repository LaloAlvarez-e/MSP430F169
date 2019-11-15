/*
 * OS.h
 *
 * Created: 12/10/2019 01:54:22 a. m.
 *  Author: Lalo
 */ 


#ifndef OS_H_
#define OS_H_

#include <msp430f169.h>
#include <intrinsics.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include "Watchdog.h"
#include "TimerB.h"
#include "GPIO.h"

#define NUMTHREADS  (7)        // maximum number of threads
#define STACKSIZE   (130)      // number of 8-bit words in stack per thread

typedef enum
{
    OS_enRunning =0,
    OS_enSleep =1,
    OS_enBlocked=2,
}OS_nStates;

#define TASK_NAME_LENGHT (24u)
struct TCB{ //Thread control block
/*

    uint8_t priority;   // static priority of the task, 0 is the lowest
    uint8_t basePriority;   //pririty at moment

*/

    int16_t *topOfStack;    //actual stack pointer
    int16_t *stack;         // start of the stack (first location)
    int16_t *endOfStack;    //end of the stack (last location)


    struct TCB *first;  // linked-list pointer
    struct TCB *next;  // linked-list pointer
    struct TCB *previous;  // linked-list pointer

    uint8_t state;      //state of task
    struct TCB *nextblockedTask;// linked-list pointer to blocked
    struct TCB *previousblockedTask;// linked-list pointer to blocked
    uint16_t sleep;

    char name[TASK_NAME_LENGHT];      //name of the task
};
typedef struct TCB TCB_TypeDef;

typedef int8_t OS_u8Semaphore;

#define OS_FIFOSIZE (30u)

typedef struct
{
    int8_t   value;
    TCB_TypeDef*  firstBlockedTask  ;
    TCB_TypeDef*  lastBlockedTask  ;
}OS_Semaphore_TypeDef;

typedef struct
{
    TCB_TypeDef*  firstSleepTask  ;
    TCB_TypeDef*  lastSleepTask  ;
}OS_Sleep_TypeDef;


typedef struct
{
    uint32_t data;
    OS_Semaphore_TypeDef   semaphore;
    uint8_t  lost  ;
}OS_MailBox_TypeDef;

typedef struct
{
    uint32_t* put;
    uint32_t* get;
    int8_t   init;
    OS_Semaphore_TypeDef   semaphoreMUTEX;
    OS_Semaphore_TypeDef   semaphoreCOUNTER;
    uint8_t  lost;
    uint32_t  buffer[OS_FIFOSIZE];
}OS_MailBoxFIFO_TypeDef;

typedef enum
{
	OS_enOK  =0,
	OS_enERROR,
}OS_nStatus;

typedef enum
{
    OS_enFifoOK =0,
    OS_enFifoFULL,
    OS_enFifoEMPTY,
}OS_nFifo;

typedef enum
{
    OS_enUnblocked  =0,
}OS_nBlocked;

typedef enum
{
    OS_enAwake  =0,
}OS_nSleep;

void OS__vLaunch(void);

/*Threads*/
TCB_TypeDef* OS__psAddMainThreads(void(*pvTask)(void),char* pcName,uint16_t u16StackSize);

/*,
void(*vTask2)(void),
void(*vTask3)(void));
*/
OS_nStatus OS__enAddPeriodicThreads(int8_t s8Cant,...);

typedef enum
{
	SEMAPHORE_enInitSYNC =0, /* 0 means event not occurs, 1 event occurs*/
	SEMAPHORE_enInitMUTEX=1, /* 1 means free, 0 busy*/
}SEMAPHORE_nTypeInit;

/*SpinLock Semaphore (MUTEX MUTual EXclusion)*/
void OS__vInitSemaphore(OS_Semaphore_TypeDef *ps8Semaphore, SEMAPHORE_nTypeInit enInitValue);
void OS__vWaitSemaphore(OS_Semaphore_TypeDef *ps8Semaphore);
void OS__vSignalSemaphore(OS_Semaphore_TypeDef *ps8Semaphore);

/* MailBox*/
void OS__vInitMailBox(OS_MailBox_TypeDef* psMailBox);
void OS__vSendMailBox_MAIN(OS_MailBox_TypeDef* psMailBox,uint32_t u32Data);
void OS__vSendMailBox_EVENT(OS_MailBox_TypeDef* psMailBox,uint32_t u32Data);
OS_nFifo OS__enReadMailBox_MAIN(OS_MailBox_TypeDef* psMailBox, uint32_t* u32Value);
OS_nFifo OS__enReadMailBox_EVENT(OS_MailBox_TypeDef* psMailBox, uint32_t* u32Value);


uint32_t OS__u32GetDataMailBox(OS_MailBox_TypeDef* psMailBox);
uint8_t OS__u8GetLostMailBox(OS_MailBox_TypeDef* psMailBox);
int8_t OS__u32GetSemaphoreMailBox(OS_MailBox_TypeDef* psMailBox);

/* MailBox FIFO*/
void OS__vInitMailBoxFIFO(OS_MailBoxFIFO_TypeDef* psMailBoxFIFO);
OS_nFifo OS__enSendMailBoxFIFO_EVENT(OS_MailBoxFIFO_TypeDef* psMailBoxFIFO,uint32_t u32Data);
OS_nFifo OS__enSendMailBoxFIFO_MAIN(OS_MailBoxFIFO_TypeDef* psMailBoxFIFO,uint32_t u32Data);

OS_nFifo OS__enReadMailBoxFIFO_EVENT(OS_MailBoxFIFO_TypeDef* psMailBoxFIFO,uint32_t* u32Data);
OS_nFifo OS__enReadMailBoxFIFO_MAIN(OS_MailBoxFIFO_TypeDef* psMailBoxFIFO,uint32_t* u32Data);


/*Critical Sections*/
uint16_t OS__u16StartCriticalSection(void);
void OS__vEndCriticalSection(uint16_t u16Status);


void OS__vSuspendMainThead(void);
void OS__vInitSleep(void);
void OS__vSleepMainThead(uint16_t u16Sleep);


#endif /* OS_H_ */
