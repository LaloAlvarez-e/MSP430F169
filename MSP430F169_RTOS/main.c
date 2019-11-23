#include <msp430f169.h>
#include <intrinsics.h>
#include <stdint.h>
#include <os.h>
#include <CLOCK.h>
#include <GPIO.h>
#include <Watchdog.h>
#include <NOKIA5110.h>

__interrupt void PORT1_ISR(void);
void Task1 (void);
void Task2 (void);
void Task3 (void);
void Task4 (void);
void Task7 (void);

OS_Semaphore_TypeDef MAIN_sSemaphoreRESET={0,0,0};
OS_Semaphore_TypeDef MAIN_sSemaphoreNOKIA={0,0,0};
OS_Semaphore_TypeDef MAIN_sSemaphoreMAX6675={0,0,0};

OS_MailBox_TypeDef MAIN_sMailBoxBUTTON1={0,0,0};
OS_MailBox_TypeDef MAIN_sMailBoxBUTTON2={0,0,0};

TCB_TypeDef* Task1_TCB,*Task2_TCB,*Task3_TCB,*Task4_TCB,*Task5_TCB,*Task6_TCB,*Task7_TCB;

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
    OS__vInitSemaphore(&MAIN_sSemaphoreRESET,SEMAPHORE_enInitSYNC);
    OS__vInitSemaphore(&MAIN_sSemaphoreNOKIA,SEMAPHORE_enInitMUTEX);
    OS__vInitSemaphore(&MAIN_sSemaphoreMAX6675,SEMAPHORE_enInitMUTEX);
    //OS__enAddPeriodicThreads(2,&Task5,50,&Task6,80);
    Task1_TCB=OS__psAddMainThreads(&Task1,"Disp Boton 1", 120);
    Task2_TCB=OS__psAddMainThreads(&Task2,"Disp Boton 2", 120);
    Task3_TCB=OS__psAddMainThreads(&Task3,"Reset Count", 120);
    Task4_TCB=OS__psAddMainThreads(&Task4,"Temp", 120);
    Task7_TCB=OS__psAddMainThreads(&Task7,"Idle", 20);
    NOKIA5110__vSetCursor(0,0);
    NOKIA5110__vClear();
    u8Column=0, u8Row=0;
    NOKIA5110__u16Print("InDev RTOS\n\rBoton 1:\n\rBoton 2:\n\r\nTemp:\r\nMAX6675",&u8Column,&u8Row);

    OS__vLaunch();
}



void Task1(void)
{
    char TASK1_cConv[10]="0";
    uint8_t u8Column=9, u8Row=1;
    uint32_t u32ValueBoton=0;
    uint16_t u16Porcentage=0;

    while(1)
    {

        LEDAMBER_OUT^=LEDAMBER_PIN;
        OS__enReadMailBox_MAIN(&MAIN_sMailBoxBUTTON1,&u32ValueBoton);

        PBUTTON1_INT|=PBUTTON1_READPIN;
        u8Column=9;
        u8Row=1;

        CONV__u8IntToStringCeros(u32ValueBoton,3,&TASK1_cConv[0]);

        OS__vWaitSemaphore(&MAIN_sSemaphoreNOKIA);
        NOKIA5110__u8SendString((char*)TASK1_cConv,&u8Column,&u8Row);
        OS__vSignalSemaphore(&MAIN_sSemaphoreNOKIA);



        u16Porcentage=(uint16_t)OS__u16GetPorcentageStackThread();
        u8Column=8;
        u8Row=5;

        CONV__u8IntToStringCeros(u16Porcentage,3,&TASK1_cConv[0]);

        OS__vWaitSemaphore(&MAIN_sSemaphoreNOKIA);
        NOKIA5110__u8SendString((char*)TASK1_cConv,&u8Column,&u8Row);
        OS__vSignalSemaphore(&MAIN_sSemaphoreNOKIA);

        OS__vSuspendMainThead();

    }
}

void Task2 (void)
{
    char TASK2_cConv[10]="0";
    uint8_t u8Column=9, u8Row=2;
    uint32_t u32ValueBoton=0;
    uint16_t u16Porcentage=0;
    while(1)
    {
        OS__enReadMailBox_MAIN(&MAIN_sMailBoxBUTTON2,&u32ValueBoton);
        PBUTTON2_INT|=PBUTTON2_READPIN;
        u8Column=9;
        u8Row=2;

        CONV__u8IntToStringCeros(u32ValueBoton,3,&TASK2_cConv[0]);
        OS__vWaitSemaphore(&MAIN_sSemaphoreNOKIA);
        NOKIA5110__u8SendString((char*)TASK2_cConv,&u8Column,&u8Row);
        OS__vSignalSemaphore(&MAIN_sSemaphoreNOKIA);

        u16Porcentage=(uint16_t)OS__u16GetPorcentageStackThread();
        u8Column=8;
        u8Row=5;

        CONV__u8IntToStringCeros(u16Porcentage,3,&TASK2_cConv[0]);

        OS__vWaitSemaphore(&MAIN_sSemaphoreNOKIA);
        NOKIA5110__u8SendString((char*)TASK2_cConv,&u8Column,&u8Row);
        OS__vSignalSemaphore(&MAIN_sSemaphoreNOKIA);

        OS__vSuspendMainThead();

    }
}

void Task3 (void)
{
    char TASK3_cConv[10]="0";
    uint8_t u8Column=9, u8Row=3;
    static uint8_t u8Previous=PBUTTON3_READPIN;
    static uint8_t u8Actual=PBUTTON3_READPIN;
    uint16_t u16Porcentage=0;

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

                OS__vWaitSemaphore(&MAIN_sSemaphoreNOKIA);
                NOKIA5110__u8SendString((char*)"Count Reset",&u8Column,&u8Row);
                OS__vSignalSemaphore(&MAIN_sSemaphoreNOKIA);

            }
            else
            {

                LEDRED_OUT|=LEDRED_PIN;
                u8Column=0;
                u8Row=3;

                OS__vWaitSemaphore(&MAIN_sSemaphoreNOKIA);
                NOKIA5110__u8SendString((char*)"           ",&u8Column,&u8Row);
                OS__vSignalSemaphore(&MAIN_sSemaphoreNOKIA);
            }

        }
        u8Previous=u8Actual;


        u16Porcentage=(uint16_t)OS__u16GetPorcentageStackThread();
        u8Column=8;
        u8Row=5;

        CONV__u8IntToStringCeros(u16Porcentage,3,&TASK3_cConv[0]);

        OS__vWaitSemaphore(&MAIN_sSemaphoreNOKIA);
        NOKIA5110__u8SendString((char*)TASK3_cConv,&u8Column,&u8Row);
        OS__vSignalSemaphore(&MAIN_sSemaphoreNOKIA);

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
    uint16_t u16Porcentage=0;

    P2DIR|=BIT7;
    P2OUT|=BIT7;
    P2SEL&=~BIT7;

    while(1)
    {
        OS__vWaitSemaphore(&MAIN_sSemaphoreMAX6675);
        SPI__vReceiveDataMaster(u8Data,2,&P2OUT,BIT7);
        OS__vSignalSemaphore(&MAIN_sSemaphoreMAX6675);
        u16Data=u8Data[1];
        u16Data|=u8Data[0]<<8;

        u8Column=5;
        u8Row=4;
        if((u16Data&2)==0)
        {
             if(u16Data&4)
             {
                 OS__vWaitSemaphore(&MAIN_sSemaphoreNOKIA);
                 NOKIA5110__u8SendString(" Z     ",&u8Column,&u8Row);
                 OS__vSignalSemaphore(&MAIN_sSemaphoreNOKIA);

             }
             else
             {
                 u16Data>>=3;
                 fTemperature=u16Data*0.25;

                 CONV__u8FloatToString(fTemperature,1,1,3,2,&TASK4_cConv[0]);

                 OS__vWaitSemaphore(&MAIN_sSemaphoreNOKIA);
                 NOKIA5110__u8SendString((char*)TASK4_cConv,&u8Column,&u8Row);
                 OS__vSignalSemaphore(&MAIN_sSemaphoreNOKIA);
             }
        }

        u16Porcentage=(uint16_t)OS__u16GetPorcentageStackThread();
        u8Column=8;
        u8Row=5;

        CONV__u8IntToStringCeros(u16Porcentage,3,&TASK4_cConv[0]);

        OS__vWaitSemaphore(&MAIN_sSemaphoreNOKIA);
        NOKIA5110__u8SendString((char*)TASK4_cConv,&u8Column,&u8Row);
        OS__vSignalSemaphore(&MAIN_sSemaphoreNOKIA);

        OS__vSleepMainThead(1000);
    }
}


void Task7 (void)
{
    while(1)
    {

    }
}



#pragma vector = PORT1_VECTOR;
__interrupt void PORT1_ISR(void)
{
    uint8_t u8Value=0;
    if(PBUTTON1_INT&PBUTTON1_READPIN)
    {
        if(PBUTTON1_IFG&PBUTTON1_READPIN)
        {
            PBUTTON1_INT&=~PBUTTON1_READPIN;
            u8Value=OS__u32GetDataMailBox(&MAIN_sMailBoxBUTTON1);
            u8Value++;
            OS__vSendMailBox_EVENT(&MAIN_sMailBoxBUTTON1,u8Value);

            PBUTTON1_IFG&=~PBUTTON1_READPIN;
        }
    }
    if(PBUTTON2_INT&PBUTTON2_READPIN)
    {
        if(PBUTTON2_IFG&PBUTTON2_READPIN)
        {
            PBUTTON2_INT&=~PBUTTON2_READPIN;
            u8Value=OS__u32GetDataMailBox(&MAIN_sMailBoxBUTTON2);
            u8Value++;
            OS__vSendMailBox_EVENT(&MAIN_sMailBoxBUTTON2,u8Value);
            PBUTTON2_IFG&=~PBUTTON2_READPIN;
        }
    }

}
