#include "DriverLib/DriverLib.h"
#include "uart.h"
#include "delay.h"

#define SIZE_FRAME_TX (13U)
#define START_FRAME_TX  (2U)
#define START_INDEX_TX  (0U)

#define END_FRAME_TX  (3U)
#define END_INDEX_TX  (SIZE_FRAME_TX - 1U)


#define COMMAND_INDEX_TX  (1U)

#define ACK_OK (0xFFU)

static uint8_t u8RXData = 0U;
static uint8_t u8Index = 0U;
static uint8_t pu8ReceivedArray[SIZE_FRAME_TX] = {0U};
static uint16_t u16ACKSum = 0U;
static uint32_t u32TAG = 0U;
static uint32_t u32TAGTemp = 0U;
uint8_t u8Iter = 0U;
void MAIN_vClockInit(void);
void MAIN_vProcessData(void);
void MAIN_vReply(void);

void main(void)
{
    boolean_t boCaptureState = FALSE;
    WDT__vSetEnable(WDT_enENABLE_STOP);
    MAIN_vClockInit();
    Delay__vInit();
    UART__vInit();
    _EINT();
	while(1U)
	{
	    u8RXData = UART__u8RxReady();
	    UART__vTxByte(u8RXData);
	    if(START_FRAME_TX == u8RXData)
	    {
	        boCaptureState = TRUE;
	    }
	    if(TRUE == boCaptureState)
	    {
	        pu8ReceivedArray[u8Index] = u8RXData;
	        u8Index++;
	        if(SIZE_FRAME_TX == u8Index)
            {
                if((START_FRAME_TX == pu8ReceivedArray[START_INDEX_TX]) &&
                   (END_FRAME_TX == pu8ReceivedArray[END_INDEX_TX]))
                {
                    uint8_t Sack = 0U;
                    boCaptureState = FALSE;
                    u8Index = 0U;
                    u8RXData = 0U;

                    for(u8Iter = 0U; u8Iter < SIZE_FRAME_TX; u8Iter++)
                    {
                        u16ACKSum += pu8ReceivedArray[u8Iter];
                    }
                    Sack = (uint8_t) u16ACKSum;
                    if(ACK_OK == Sack )
                    {
                        MAIN_vProcessData();
                    }
                }
            }
	    }
	}
}


void MAIN_vProcessData(void)
{
    switch(pu8ReceivedArray[COMMAND_INDEX_TX])
    {
    case 'A':
        MAIN_vReply();
        break;
    case 'B':
        break;
    case 'C':
        break;
    case 'D':
        break;
    case 'E':
        break;
    case 'F':
        break;
    default:
        break;
    }
}

void MAIN_vReply(void)
{
    uint16_t u16ACK = 0U;
    uint8_t pu16ACKArray[2U] = {0U};

    u16ACK = START_FRAME_TX;
    UART__vTxByte(START_FRAME_TX);
    for(u8Iter = 1U; u8Iter < (SIZE_FRAME_TX - 3U); u8Iter++)
    {
        u16ACK += pu8ReceivedArray[u8Iter];
        UART__vTxByte(pu8ReceivedArray[u8Iter]);
    }
    u16ACK += END_FRAME_TX;
    pu16ACKArray[1U] =  u16ACK & 0xFFU;
    u16ACK >>= 8U;
    pu16ACKArray[0U] = u16ACK & 0xFFU;
    UART__vTxByte(pu16ACKArray[0U]);
    UART__vTxByte(pu16ACKArray[1U]);
    UART__vTxByte(END_FRAME_TX);
    u32TAG  = (uint32_t) pu8ReceivedArray[2U] << 24U;
    u32TAG |= (uint32_t) pu8ReceivedArray[3U] << 16U;
    u32TAG |= (uint32_t) pu8ReceivedArray[4U] << 8U;
    u32TAG |= (uint32_t) pu8ReceivedArray[5U];

}

void MAIN_vClockInit(void)
{
    CLOCK_nINT_STATUS enClockStatus = CLOCK_enINT_STATUS_NOOCCUR;
    uint16_t u16Iter = 0U;

    /** Rosc*/
    GPIO__vSetConfig(GPIO_enROSC_P25);

    CLOCK__vSetDCOFrequency(800000UL, CLOCK_enRESISTOR_EXTERNAL);
    CLOCK__vSetLFXT1FrequencyMode(CLOCK_enFREQMODE_LOW);
    CLOCK__vSetXT2Enable(CLOCK_enENABLE_ENA);
    do
    {
        CLOCK__vClearInterruptSource();
        for(u16Iter = 0U; u16Iter < 4000U; u16Iter++); /*At least 50us*/
        enClockStatus = CLOCK__enGetStatusInterruptSource();
    }while(CLOCK_enINT_STATUS_NOOCCUR != enClockStatus);

    CLOCK__enSetACLKSource(CLOCK_enSOURCE_LFXT1); /*32768 Hz*/
    CLOCK__enSetMCLKSource(CLOCK_enSOURCE_DCO); /*~8 MHz*/
    CLOCK__enSetSMCLKSource(CLOCK_enSOURCE_XT2); /*8 MHz*/
}

