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
#include <stdarg.h>
#include "Watchdog.h"
#include "TimerB.h"
#include "GPIO.h"

#define NUMTHREADS  (3)        // maximum number of threads
#define STACKSIZE   (0x100)      // number of 8-bit words in stack per thread

struct TCB{ //Thread control block
	int16_t *sp;       // pointer to stack (valid for threads not running)
	struct TCB *next;  // linked-list pointer
    struct TCB *nextblockedTCB;
	int8_t  blockedValue;
};
typedef struct TCB TCB_TypeDef;

typedef int8_t OS_u8Semaphore;

typedef struct
{
    int8_t   value;
    TCB_TypeDef*  initBlockTCB  ;
    TCB_TypeDef*  lastBlockTCB  ;
}OS_sSemaphore;


typedef struct
{
    uint32_t data;
    OS_sSemaphore   semaphore;
    uint8_t  lost  ;
}OS_sMailBox;

typedef enum
{
	OS_enOK  =0,
	OS_enERROR,
}OS_nStatus;

typedef enum
{
    OS_enUnblocked  =0,
}OS_nBlocked;


void OS__vLaunch(void);

/*Threads*/
OS_nStatus OS__enAddMainThreads(int8_t s8Cant,...);
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
void OS__vInitSemaphore(OS_sSemaphore *ps8Semaphore, SEMAPHORE_nTypeInit enInitValue);
void OS__vWaitSemaphore(OS_sSemaphore *ps8Semaphore);
void OS__vSignalSemaphore(OS_sSemaphore *ps8Semaphore);

/* MailBox*/
void OS__vInitMailBox(OS_sMailBox* psMailBox);
void OS__vSendMailBox(OS_sMailBox* psMailBox,uint32_t u32Data);
uint32_t OS__u32ReadMailBox(OS_sMailBox* psMailBox);

uint32_t OS__u32GetDataMailBox(OS_sMailBox* psMailBox);
uint8_t OS__u8GetLostMailBox(OS_sMailBox* psMailBox);
int8_t OS__u32GetSemaphoreMailBox(OS_sMailBox* psMailBox);

/*Critical Sections*/
uint16_t OS__u16StartCriticalSection(void);
void OS__vEndCriticalSection(uint16_t u16Status);


void OS__vSuspendMainThead(void);


#endif /* OS_H_ */
