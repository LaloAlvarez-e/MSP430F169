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
void Task7 (void);

OS_Semaphore_TypeDef MAIN_sSemaphoreSPI={0,0,0};

OS_MailBox_TypeDef MAIN_sMailBoxBUTTON1={0,0,0};
OS_MailBox_TypeDef MAIN_sMailBoxBUTTON2={0,0,0};

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
    //OS__vInitSleep();
    OS__vInitMailBox(&MAIN_sMailBoxBUTTON1);
    OS__vInitMailBox(&MAIN_sMailBoxBUTTON2);
    OS__vSendMailBox_EVENT(&MAIN_sMailBoxBUTTON1,0);
    OS__vSendMailBox_EVENT(&MAIN_sMailBoxBUTTON2,0);
    OS__vInitSemaphore(&MAIN_sSemaphoreSPI,SEMAPHORE_enInitMUTEX);
    //OS__enAddPeriodicThreads(2,&Task5,50,&Task6,80);
    OS__enAddMainThreads(7,&Task1,&Task2,&Task3,&Task4,&Task5,&Task6,&Task7);
    NOKIA5110__vSetCursor(0,0);
    NOKIA5110__vClear();
    u8Column=0, u8Row=0;
    NOKIA5110__u16Print("InDev RTOS\n\rBoton 1:\n\rBoton 2:\n\r\nTemp:\r\nRTOS",&u8Column,&u8Row);

    OS__vLaunch();
}



void Task1(void)
{
    char TASK1_cConv[10]="0";
    uint8_t u8Column=9, u8Row=1;
    uint32_t u32ValueBoton=0;

    while(1)
    {

        LEDAMBER_OUT^=LEDAMBER_PIN;
        OS__enReadMailBox_MAIN(&MAIN_sMailBoxBUTTON1,&u32ValueBoton);
        u8Column=9;
        u8Row=1;

        CONV__u8IntToStringCeros(u32ValueBoton,3,&TASK1_cConv[0]);

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
    uint32_t u32ValueBoton=0;
    while(1)
    {
        OS__enReadMailBox_MAIN(&MAIN_sMailBoxBUTTON2,&u32ValueBoton);
        u8Column=9;
        u8Row=2;

        CONV__u8IntToStringCeros(u32ValueBoton,3,&TASK2_cConv[0]);
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

        if(u8Previous!=u8Actual)
        {
            if(u8Actual==0)
            {
                LEDRED_OUT&=~LEDRED_PIN;
                OS__vSendMailBox_MAIN(&MAIN_sMailBoxBUTTON1,0);
                OS__vSendMailBox_MAIN(&MAIN_sMailBoxBUTTON2,0);
                u8Column=0;
                u8Row=3;

                OS__vWaitSemaphore(&MAIN_sSemaphoreSPI);
                NOKIA5110__u8SendString((char*)"Count Reset",&u8Column,&u8Row);
                OS__vSignalSemaphore(&MAIN_sSemaphoreSPI);

            }
            else
            {

                LEDRED_OUT|=LEDRED_PIN;
                u8Column=0;
                u8Row=3;

                OS__vWaitSemaphore(&MAIN_sSemaphoreSPI);
                NOKIA5110__u8SendString((char*)"           ",&u8Column,&u8Row);
                OS__vSignalSemaphore(&MAIN_sSemaphoreSPI);
            }

        }
        u8Previous=u8Actual;
        OS__vSleepMainThead(33);
     }
}

void Task4 (void)
{
    uint16_t u16Data=0;
    uint8_t u8Data[2]={0};
    float fTemperature=0;

    uint8_t u8Column=5, u8Row=4;
    char TASK4_cConv[10]="0";

    P2DIR|=BIT7;
    P2OUT|=BIT7;
    P2SEL&=~BIT7;

    while(1)
    {
        P2OUT&=~BIT7;
        OS__vWaitSemaphore(&MAIN_sSemaphoreSPI);
        SPI__vReceiveDataMaster(u8Data,2);
        OS__vSignalSemaphore(&MAIN_sSemaphoreSPI);
        u16Data=u8Data[1];
        u16Data|=u8Data[0]<<8;

        P2OUT|=BIT7;
        u8Column=5;
        u8Row=4;
        if((u16Data&2)==0)
        {
             if(u16Data&4)
             {
                 OS__vWaitSemaphore(&MAIN_sSemaphoreSPI);
                 NOKIA5110__u8SendString("Z     ",&u8Column,&u8Row);
                 OS__vSignalSemaphore(&MAIN_sSemaphoreSPI);

             }
             else
             {
                 u16Data>>=3;
                 fTemperature=u16Data*0.25;

                 CONV__u8FloatToString(fTemperature,1,1,3,2,&TASK4_cConv[0]);

                 OS__vWaitSemaphore(&MAIN_sSemaphoreSPI);
                 NOKIA5110__u8SendString((char*)TASK4_cConv,&u8Column,&u8Row);
                 OS__vSignalSemaphore(&MAIN_sSemaphoreSPI);
             }
        }
        OS__vSleepMainThead(1000);
    }
}


void Task5 (void)
{
    uint8_t u8Value=0;
    static uint8_t u8Previous=PBUTTON2_READPIN;
    static uint8_t u8Actual=PBUTTON2_READPIN;
    while(1)
    {
        u8Actual=PBUTTON2_READPORT & PBUTTON2_READPIN;

        if(u8Previous!=u8Actual)
        {
            if(u8Actual==0)
            {
                u8Value=OS__u32GetDataMailBox(&MAIN_sMailBoxBUTTON2);
                u8Value++;
                OS__vSendMailBox_EVENT(&MAIN_sMailBoxBUTTON2,u8Value);
            }

        }
        u8Previous=u8Actual;
        OS__vSleepMainThead(80);
    }
}
void Task6 (void)
{
    uint8_t u8Value=0;
    static uint8_t u8Previous=PBUTTON1_READPIN;
    static uint8_t u8Actual=PBUTTON1_READPIN;

    while(1)
    {
        u8Actual=PBUTTON1_READPORT & PBUTTON1_READPIN;

        LEDBLUE_OUT^=LEDBLUE_PIN;
        if(u8Previous!=u8Actual)
        {
            if(u8Actual==0)
            {
                u8Value=OS__u32GetDataMailBox(&MAIN_sMailBoxBUTTON1);
                u8Value++;
                OS__vSendMailBox_MAIN(&MAIN_sMailBoxBUTTON1,u8Value);
            }
        }
        u8Previous=u8Actual;
        OS__vSleepMainThead(60);
    }
}

void Task7 (void)
{
    while(1)
    {

    }
}
