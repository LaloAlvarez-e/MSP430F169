#include <DriverLib/DriverLib.h>
#include <xUtils/Conversion/Conversion.h>
#include <ClockFunctions.h>
#include <SlidePot.h>
#include <Button.h>
#include <Buzzer.h>
#include <Sounds.h>
#include <NOKIA5110.h>

static boolean_t Scheduler_boRun = FALSE;
static uint16_t Scheduler_u16GameEngine(uintptr_t uptrBlock, uint16_t u16Pin);


static uint16_t Scheduler_u16GameEngine(uintptr_t uptrBlock, uint16_t u16Pin)
{
    static uint8_t u8Count = 0U;
    uint16_t u16Status = 0xFFU;

    if(0U == (1U & u8Count))
    {
        Scheduler_boRun = TRUE;
        PORT4->OUT_bits.P7 = 1U;
        u16Status = 0U;
    }
    u8Count++;
    return (u16Status);
}

const uint8_t* pu8Array[4U] =
{
 Sounds__pu8shoot,
 Sounds__pu8invaderkilled,
 Sounds__pu8fastinvader4,
 Sounds__pu8highpitch,

};

uint16_t pu16ArraySize[4U] =
{
 SOUND_SHOOT_SIZE,
 SOUND_INVADERKILLED_SIZE,
 SOUND_FASTINVADER_SIZE,
 SOUND_HIGHPITCH_SIZE,

};
void main(void)
{
    WDT_Config_t stSchedulerConfig =
    {
        WDT_enENABLE_RUN,
        WDT_enINT_ENABLE_ENA,
        WDT_enMODE_INTERVAL,
        WDT_enCLOCK_ACLK,
        WDT_enINTERVAL_512,
    };
    char BufferConv[20U] = {0U};
    uint16_t u16ADCValueOld = 0U;
    uint8_t u8Value = 0U;
    uint8_t u8Iter = 0U;
    uint8_t u8Count = 0U;
    uint8_t u8ArrayCount = 0U;
    const char* pcState[2U] = {"ON ", "OFF"};
    uint8_t pu8ButtonTemp[4U] = {0U,0U,0U,0U};
    uint8_t u8Column=0, u8Row=0;
    WDT__vSetEnable(WDT_enENABLE_STOP);
    Buzzer__vInit();
    System__vClockInit();
    SlidePot__vInit();
    Button__vInit();
    GPIO__vSetConfig(GPIO_enPORT47);
    GPIO__vSetDirectionByFunction(GPIO_enPORT47, GPIO_enDIR_OUTPUT);
    GPIO__vSetOutputByFunction(GPIO_enPORT47, GPIO_enLEVEL_LOW);
    WDT__vRegisterIRQSourceHandler(&Scheduler_u16GameEngine);
    WDT__vSetConfig(&stSchedulerConfig);
    _EINT();


    NOKIA5110__vInit();
    NOKIA5110__vSetCursor(0,0);
    NOKIA5110__vClear();


    u8Column=0, u8Row=0;
    NOKIA5110__u16Print("InDev\n\rInitializing\n\rRTOS ",&u8Column,&u8Row);
    NOKIA5110__vSetCursor(0,0);
    NOKIA5110__vClear();
    u8Column=0, u8Row=0;
    NOKIA5110__u16Print("Btn U:\n\rBtn R:\n\rBtn L:\n\rBtn D:\n\rPot   :",&u8Column,&u8Row);


    u8Value = Button__u8GetAllValues();
    for(u8Iter = 0U; u8Iter < 4U; u8Iter++)
    {
        u8Column=7, u8Row=u8Iter;
        pu8ButtonTemp[u8Iter] = u8Value & 1U;
        u8Value >>= 1U;
        NOKIA5110__u16Print((char*) pcState[pu8ButtonTemp[u8Iter]],&u8Column,&u8Row);
    }
    u16ADCValueOld = SlidePort__u16GetValue();


    while(1U)
    {
        if(TRUE == Scheduler_boRun)
        {
            uint8_t u8Temp = 0U;
            uint16_t u16Temp = 0U;
            if(u8Count >= 128)
            {
                u8Count = 0U;
                Buzzer__vPlaySound(pu8Array[u8ArrayCount], pu16ArraySize[u8ArrayCount]);
                u8ArrayCount++;
                if(u8ArrayCount >= 4U)
                {
                    u8ArrayCount = 0U;
                }
            }
            else
            {
                u8Count++;
            }
            u8Value = Button__u8GetAllValues();
            for(u8Iter = 0U; u8Iter < 4U; u8Iter++)
            {
                u8Temp = (u8Value & 1U);
                pu8ButtonTemp[u8Iter] = u8Temp;
                u8Column=7, u8Row=u8Iter;
                //NOKIA5110__u16Print((char*) pcState[pu8ButtonTemp[u8Iter]],&u8Column,&u8Row);

                u8Value >>= 1U;
            }
            u16Temp = SlidePort__u16GetValue();
            u16ADCValueOld = u16Temp;
            u8Column=7, u8Row=4;
            //Conv__u8Int2StringZeros(u16ADCValueOld, 4U, BufferConv);
            //NOKIA5110__u16Print(BufferConv,&u8Column,&u8Row);
            PORT4->OUT_bits.P7 = 0U;
            Scheduler_boRun = FALSE;
            LPM1;
        }
    }
}
