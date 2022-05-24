#include <DriverLib/DriverLib.h>
#include <xUtils/Conversion/Conversion.h>
#include <xUtils/DataStructure/LinkedList/CircularSingleLinkedList/CircularSingleLinkedList.h>
#include <ClockFunctions.h>
#include <SlidePot.h>
#include <Button.h>
#include <Buzzer.h>
#include <Sounds.h>
#include <NOKIA5110.h>
#include "stdlib.h"

static uint16_t Scheduler_u16GameEngine(uintptr_t uptrBlock, uint16_t u16Pin);

typedef struct
{
    int8_t s8X;
    int8_t s8Y;
}Coord_t;

#define Screen_s8WidthStart (4)
#define Screen_s8HeightStart (8)
#define Screen_s8WidthSlots (18)
#define Screen_s8HeightSlots (8)
#define Screen_s8SpriteSize (4)
#define Screen_u8Width (Screen_s8WidthSlots * Screen_s8SpriteSize)
#define Screen_u8Height (Screen_s8HeightSlots * Screen_s8SpriteSize)

CSLinkedList_t Screen_stSnakeList;
CSLinkedListItem_t Screem_stSnakePoints[100U];
CSLinkedListItem_t* Screen_pstSnakeTailPointer;
CSLinkedListItem_t* Screen_pstSnakePointer;
CSLinkedListItem_t* Screen_pstLastSnakePointer;
CSLinkedListItem_t* Screen_pstSnakeHeadPointer;
int32_t Screen_s32SnakeHeadData;
int32_t Screen_s32SnakeTailData;
int32_t Screen_s32SnakeHeadDataTemp;
int32_t Screen_s32SnakeData;
Coord_t* Screen_pstSnakeData;
Coord_t* Screen_pstSnakeHeadData;
Coord_t* Screen_pstSnakeTailData;
Coord_t* Screen_pstSnakeHeadDataTemp;
Coord_t Screen_stData;
static uint16_t Screen_u16Number = 1U;
static Coord_t Screen_stFruit;

static boolean_t Scheduler_boRun = FALSE;
static uint8_t Screen_u8Direction = 0U;


static uint16_t Scheduler_u16Count = 0U;
static uint16_t Scheduler_u16GameEngine(uintptr_t uptrBlock, uint16_t u16Pin)
{
    uint16_t u16Status = 0xFFU;

    if(0U == (0x3U & Scheduler_u16Count))
    {
        Scheduler_boRun = TRUE;
        PORT4->OUT_bits.P7 = 1U;
        u16Status = 0U;
    }
    Scheduler_u16Count++;
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
    char pcConv[5U] = {0U};
    uint16_t u16Iter = 0U;
    uint8_t u8Column = 0U;
    uint8_t u8Row = 0U;
    uint16_t u16ADCValueOld = 0U;
    uint8_t u8Value = 0U;
    uint16_t u16TimeCurrent = 0U;
    WDT__vSetEnable(WDT_enENABLE_STOP);

    _EINT();
    Buzzer__vInit();
    Button__vInit();
    System__vClockInit();
    SlidePot__vInit();
    GPIO__vSetConfig(GPIO_enPORT47);
    GPIO__vSetDirectionByFunction(GPIO_enPORT47, GPIO_enDIR_OUTPUT);
    GPIO__vSetOutputByFunction(GPIO_enPORT47, GPIO_enLEVEL_LOW);
    WDT__vRegisterIRQSourceHandler(&Scheduler_u16GameEngine);
    WDT__vSetConfig(&stSchedulerConfig);

    NOKIA5110__vInit();
    LCD__vClear(0U);
    u8Column = 0U;
    u8Row = 0U;
    LCD__u16Print(":", &u8Column, &u8Row);
    Conv__u8Int2StringZeros(Screen_u16Number, 3U, pcConv);
    LCD__u16Print(pcConv, &u8Column, &u8Row);
    LCD__vClearSection(1U,  0U,  7U, 84U,  1U);
    LCD__vClearSection(1U,  0U, 44U, 84U,  4U);
    LCD__vClearSection(1U,  0U,  7U,  4U, 40U);
    LCD__vClearSection(1U, 80U,  7U,  4U, 40U);
    CSLinkedList__enInit(&Screen_stSnakeList, 0U, 0U);
    LCD__vRefresh();


    u16ADCValueOld = SlidePort__u16GetValue();
    do
    {
        u8Value = Button__u8GetAllValues();
    }while(0xFU == u8Value);
    do
    {
        u8Value = Button__u8GetAllValues();
    }while(0xFU != u8Value);
    srand((TIMERA->CC_R[1U]) + u16ADCValueOld);
    CSLinkedList__enInsertAtTail_WithData(&Screen_stSnakeList, &Screem_stSnakePoints[0U], 0U);
    CSLinkedList__enInsertAtTail_WithData(&Screen_stSnakeList, &Screem_stSnakePoints[1U], 0U);

    Screen_stData.s8X = rand() % Screen_s8WidthSlots;
    Screen_stData.s8Y = rand() % Screen_s8HeightSlots;
    CSLinkedList__enInsertAtTail_WithData(&Screen_stSnakeList, &Screem_stSnakePoints[0U], (void*) (*(uint16_t*) &Screen_stData));
    CSLinkedList__enInsertAtTail_WithData(&Screen_stSnakeList, &Screem_stSnakePoints[1U], (void*) (*(uint16_t*) &Screen_stData));

    Screen_stFruit.s8X = rand() % Screen_s8WidthSlots;
    Screen_stFruit.s8Y = rand() % Screen_s8HeightSlots;
    while(1U)
    {


        if(TRUE == Scheduler_boRun)
        {
            uint16_t u16TimeElapsed = Scheduler_u16Count;
            u8Value = Button__u8GetAllValues();

            if(0U == (u8Value & 4U))
            {
                Screen_u8Direction = 2U;
            }
            if(0U == (u8Value & 2U))
            {
                Screen_u8Direction = 3U;
            }
            if(0U == (u8Value & 1U))
            {
                Screen_u8Direction = 4U;
            }
            if(0U == (u8Value & 8U))
            {
                Screen_u8Direction = 1U;
            }

            if(4U < (u16TimeElapsed - u16TimeCurrent))
            {
                u16TimeCurrent = u16TimeElapsed;

                Screen_s32SnakeTailData = (int16_t) CSLinkedList__pvGetDataTail(&Screen_stSnakeList);
                Screen_pstSnakeTailData = (Coord_t*) &Screen_s32SnakeTailData;
                Screen_s32SnakeHeadData = (int16_t)  CSLinkedList__pvGetDataHead(&Screen_stSnakeList);
                Screen_pstSnakeHeadData = (Coord_t*) &Screen_s32SnakeHeadData;
                Screen_pstSnakeTailPointer = CSLinkedList__pstGetTail(&Screen_stSnakeList);
                CSLinkedList__enRemoveTail(&Screen_stSnakeList);
                LCD__vClearSection(0U,
                                   (Screen_pstSnakeTailData->s8X*Screen_s8SpriteSize) + Screen_s8WidthStart,
                                   (Screen_pstSnakeTailData->s8Y*Screen_s8SpriteSize) + Screen_s8HeightStart,
                                   Screen_s8SpriteSize,
                                   Screen_s8SpriteSize);


                if (Screen_u8Direction == 1U)
                {
                    Screen_pstSnakeHeadData->s8Y += 1;
                }
                if (Screen_u8Direction == 2U)
                {
                    Screen_pstSnakeHeadData->s8X -= 1;
                }
                if (Screen_u8Direction == 3U)
                {
                    Screen_pstSnakeHeadData->s8X += 1;
                }
                if (Screen_u8Direction == 4U)
                {
                    Screen_pstSnakeHeadData->s8Y -= 1;
                }

                if (Screen_pstSnakeHeadData->s8X > Screen_s8WidthSlots)
                {
                    Screen_pstSnakeHeadData->s8X = 0;
                }
                if (Screen_pstSnakeHeadData->s8X < 0)
                {
                    Screen_pstSnakeHeadData->s8X = Screen_s8WidthSlots;
                }
                if (Screen_pstSnakeHeadData->s8Y > Screen_s8HeightSlots)
                {
                    Screen_pstSnakeHeadData->s8Y = 0;
                }
                if (Screen_pstSnakeHeadData->s8Y < 0)
                {
                    Screen_pstSnakeHeadData->s8Y = Screen_s8HeightSlots;
                }

               LCD__vClearSection(1U,
                                   (Screen_pstSnakeHeadData->s8X*Screen_s8SpriteSize) + Screen_s8WidthStart,
                                   (Screen_pstSnakeHeadData->s8Y*Screen_s8SpriteSize) + Screen_s8HeightStart,
                                   Screen_s8SpriteSize,
                                   Screen_s8SpriteSize);
               if(0U == (Screen_u16Number & 1U) )
               {
               LCD__vClearSection(0U,
                                   (Screen_pstSnakeHeadData->s8X*Screen_s8SpriteSize) + Screen_s8WidthStart  + 0U,
                                   (Screen_pstSnakeHeadData->s8Y*Screen_s8SpriteSize) + Screen_s8HeightStart + 0U,
                                   1,
                                   1);
               LCD__vClearSection(0U,
                                   (Screen_pstSnakeHeadData->s8X*Screen_s8SpriteSize) + Screen_s8WidthStart  + 1U,
                                   (Screen_pstSnakeHeadData->s8Y*Screen_s8SpriteSize) + Screen_s8HeightStart + 1U,
                                   1,
                                   1);
               }
               else
               {
                   LCD__vClearSection(0U,
                                       (Screen_pstSnakeHeadData->s8X*Screen_s8SpriteSize) + Screen_s8WidthStart  + 1U,
                                       (Screen_pstSnakeHeadData->s8Y*Screen_s8SpriteSize) + Screen_s8HeightStart + 0U,
                                       1,
                                       1);
                   LCD__vClearSection(0U,
                                       (Screen_pstSnakeHeadData->s8X*Screen_s8SpriteSize) + Screen_s8WidthStart  + 0U,
                                       (Screen_pstSnakeHeadData->s8Y*Screen_s8SpriteSize) + Screen_s8HeightStart + 1U,
                                       1,
                                       1);
               }

               CSLinkedList__enInsertAtHead_WithData(&Screen_stSnakeList, Screen_pstSnakeTailPointer, (void*) (*(int16_t*) Screen_pstSnakeHeadData));
               Screen_pstLastSnakePointer = Screen_pstSnakeTailPointer;
                if ((Screen_pstSnakeHeadData->s8X == Screen_stFruit.s8X) &&
                    (Screen_pstSnakeHeadData->s8Y == Screen_stFruit.s8Y))
                {
                    Screen_u16Number++;
                    Screen_stFruit.s8X = rand() % Screen_s8WidthSlots;
                    Screen_stFruit.s8Y = rand() % Screen_s8HeightSlots;
                    Conv__u8Int2StringZeros(Screen_u16Number, 3U, pcConv);
                    u8Column = 8U *6U;
                    u8Row = 0U;
                    LCD__u16Print(pcConv, &u8Column, &u8Row);

                    CSLinkedList__enInsertAtTail(&Screen_stSnakeList, &Screem_stSnakePoints[Screen_u16Number - 1U]);
                    Screen_pstLastSnakePointer = &Screem_stSnakePoints[Screen_u16Number - 1U];
                }

                LCD__vClearSection(1U,
                                   (Screen_stFruit.s8X*Screen_s8SpriteSize) + Screen_s8WidthStart,
                                   (Screen_stFruit.s8Y*Screen_s8SpriteSize) + Screen_s8HeightStart,
                                   Screen_s8SpriteSize,
                                   Screen_s8SpriteSize);
                Screen_pstSnakePointer = CSLinkedList_Item__pstGetNextItem(Screen_pstSnakeTailPointer);
                while(Screen_pstLastSnakePointer != Screen_pstSnakePointer)
                {
                    Screen_s32SnakeData = (int16_t) CSLinkedList_Item__pvGetData(Screen_pstSnakePointer);
                    Screen_pstSnakeData = (Coord_t*) &Screen_s32SnakeData;
                    if ((Screen_pstSnakeHeadData->s8X == Screen_pstSnakeData->s8X) &&
                        (Screen_pstSnakeHeadData->s8Y == Screen_pstSnakeData->s8Y))
                    {
                        Screen_u16Number = 1U;
                        CSLinkedList__enInit(&Screen_stSnakeList, 0U, 0U);
                        CSLinkedList__enInsertAtTail_WithData(&Screen_stSnakeList, &Screem_stSnakePoints[0U], (void*) (*(int16_t*) Screen_pstSnakeHeadData));

                        LCD__vClear(0U);
                        u8Column = 0U;
                        u8Row = 0U;
                        LCD__u16Print("Score:", &u8Column, &u8Row);
                        Conv__u8Int2StringZeros(Screen_u16Number, 3U, pcConv);
                        u8Column = 8U *6U;
                        u8Row = 0U;
                        LCD__u16Print(pcConv, &u8Column, &u8Row);
                        LCD__vClearSection(1U,  0U,  7U, 84U,  1U);
                        LCD__vClearSection(1U,  0U, 44U, 84U,  4U);
                        LCD__vClearSection(1U,  0U,  7U,  4U, 40U);
                        LCD__vClearSection(1U, 80U,  7U,  4U, 40U);
                        LCD__vClearSection(1U,
                                           (Screen_pstSnakeHeadData->s8X*Screen_s8SpriteSize) + Screen_s8WidthStart,
                                           (Screen_pstSnakeHeadData->s8Y*Screen_s8SpriteSize) + Screen_s8HeightStart,
                                           Screen_s8SpriteSize,
                                           Screen_s8SpriteSize);

                        LCD__vClearSection(1U,
                                           (Screen_stFruit.s8X*Screen_s8SpriteSize) + Screen_s8WidthStart,
                                           (Screen_stFruit.s8Y*Screen_s8SpriteSize) + Screen_s8HeightStart,
                                           Screen_s8SpriteSize,
                                           Screen_s8SpriteSize);
                        break;
                    }
                    Screen_pstSnakePointer = CSLinkedList_Item__pstGetNextItem(Screen_pstSnakePointer);
                }
                LCD__vRefresh();
            }


            PORT4->OUT_bits.P7 = 0U;
            Scheduler_boRun = FALSE;

        }
        LPM3;
    }
}
