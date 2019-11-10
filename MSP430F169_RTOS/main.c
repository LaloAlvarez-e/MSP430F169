#include <msp430f169.h>
#include <intrinsics.h>
#include <stdint.h>
#include <os.h>
#include <CLOCK.h>
#include <GPIO.h>
#include <Watchdog.h>
#include <NOKIA5110.h>

void Task1 (void);
void Task2 (void);
void Task3 (void);
void Task4 (void);
void Task5 (void);
void Task6 (void);

OS_sSemaphore MAIN_sSemaphoreSPI={0,0,0};

OS_sMailBox MAIN_sMailBoxBUTTON1={0,0,0};
OS_sMailBox MAIN_sMailBoxBUTTON2={0,0,0};

void main(void)
{
    uint8_t
    u8Column=0, u8Row=0;
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	CLOCK__vConf();
	CLOCK__vEnOutACLK();
    GPIO__vInitPort();
    NOKIA5110__vInit();
    NOKIA5110__vSetCursor(0,0);
    NOKIA5110__vClear();


    u8Column=0, u8Row=0;
    NOKIA5110__u16Print("InDev\n\rInitializing\n\rRTOS ",&u8Column,&u8Row);

    OS__vInitMailBox(&MAIN_sMailBoxBUTTON1);
    OS__vInitMailBox(&MAIN_sMailBoxBUTTON2);
    OS__vSendMailBox(&MAIN_sMailBoxBUTTON1,0);
    OS__vSendMailBox(&MAIN_sMailBoxBUTTON2,0);
    OS__vInitSemaphore(&MAIN_sSemaphoreSPI,SEMAPHORE_enInitMUTEX);
    OS__enAddPeriodicThreads(2,&Task5,50,&Task6,80);
    OS__enAddMainThreads(3,&Task1, &Task2,&Task3);
    NOKIA5110__vSetCursor(0,0);
    NOKIA5110__vClear();
    u8Column=0, u8Row=0;
    NOKIA5110__u16Print("InDev RTOS\n\rBoton 1:\n\rBoton 2:\n\r\n\rMailBox ",&u8Column,&u8Row);

    OS__vLaunch();
}



void Task1(void)
{
    char TASK1_cConv[10]="0";
    uint8_t u8Column=9, u8Row=1;
    uint16_t u16ValueBoton=0;

    while(1)
    {
        u16ValueBoton=OS__u32ReadMailBox(&MAIN_sMailBoxBUTTON1);
        u8Column=9;
        u8Row=1;

        CONV__u8IntToStringCeros(u16ValueBoton,3,&TASK1_cConv[0]);
        OS__vWaitSemaphore(&MAIN_sSemaphoreSPI);
        NOKIA5110__u8SendString((char*)TASK1_cConv,&u8Column,&u8Row);
        OS__vSignalSemaphore(&MAIN_sSemaphoreSPI);
        OS__vSuspendMainThead();

    }
}

void Task2 (void)
{
    char TASK2_cConv[10]="0";
    uint8_t u8Column=9, u8Row=2;
    uint16_t u16ValueBoton=0;
    while(1)
    {
        u16ValueBoton=OS__u32ReadMailBox(&MAIN_sMailBoxBUTTON2);
        u8Column=9;
        u8Row=2;

        CONV__u8IntToStringCeros(u16ValueBoton,3,&TASK2_cConv[0]);
        OS__vWaitSemaphore(&MAIN_sSemaphoreSPI);
        NOKIA5110__u8SendString((char*)TASK2_cConv,&u8Column,&u8Row);
        OS__vSignalSemaphore(&MAIN_sSemaphoreSPI);
        OS__vSuspendMainThead();

    }
}

void Task3 (void)
{
    uint8_t u8Column=9, u8Row=3;
    static uint8_t u8Previous=PBUTTON3_READPIN;
    static uint8_t u8Actual=PBUTTON3_READPIN;

    while(1)
    {
        u8Actual=PBUTTON3_READPORT & PBUTTON3_READPIN;

        LEDRED_OUT|=LEDRED_PIN;
        if(u8Previous!=u8Actual)
        {
            if(u8Actual==0)
            {
                LEDRED_OUT&=~LEDRED_PIN;
                OS__vSendMailBox(&MAIN_sMailBoxBUTTON1,0);
                OS__vSendMailBox(&MAIN_sMailBoxBUTTON2,0);
                u8Column=0;
                u8Row=3;

                OS__vWaitSemaphore(&MAIN_sSemaphoreSPI);
                NOKIA5110__u8SendString((char*)"Count Reset",&u8Column,&u8Row);
                OS__vSignalSemaphore(&MAIN_sSemaphoreSPI);

            }
            else
            {

                u8Column=0;
                u8Row=3;

                OS__vWaitSemaphore(&MAIN_sSemaphoreSPI);
                NOKIA5110__u8SendString((char*)"           ",&u8Column,&u8Row);
                OS__vSignalSemaphore(&MAIN_sSemaphoreSPI);
            }

        }
        u8Previous=u8Actual;
        OS__vSuspendMainThead();
     }
}

void Task4 (void)
{
    while(1)
    {
    }
}


void Task5 (void)
{
    uint8_t u8Value=0;
    static uint8_t u8Previous=PBUTTON2_READPIN;
    static uint8_t u8Actual=PBUTTON2_READPIN;
    u8Actual=PBUTTON2_READPORT & PBUTTON2_READPIN;

    if(u8Previous!=u8Actual)
    {
        if(u8Actual==0)
        {
            u8Value=OS__u32GetDataMailBox(&MAIN_sMailBoxBUTTON2);
            u8Value++;
            OS__vSendMailBox(&MAIN_sMailBoxBUTTON2,u8Value);
        }

    }
    u8Previous=u8Actual;
}
void Task6 (void)
{
    uint8_t u8Value=0;
    static uint8_t u8Previous=PBUTTON1_READPIN;
    static uint8_t u8Actual=PBUTTON1_READPIN;
    u8Actual=PBUTTON1_READPORT & PBUTTON1_READPIN;

    LEDBLUE_OUT^=LEDBLUE_PIN;
   if(u8Previous!=u8Actual)
    {
        if(u8Actual==0)
        {
            u8Value=OS__u32GetDataMailBox(&MAIN_sMailBoxBUTTON1);
            u8Value++;
            OS__vSendMailBox(&MAIN_sMailBoxBUTTON1,u8Value);
        }

    }
    u8Previous=u8Actual;

}
