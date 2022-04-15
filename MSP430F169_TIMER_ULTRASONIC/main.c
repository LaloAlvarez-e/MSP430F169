#include "DriverLib/DriverLib.h"


uint16_t MAIN_u16UltrasonicTrigger(uintptr_t ptrBlock, uint8_t u8Source);
uint16_t MAIN_u16UltrasonicCapture(uintptr_t ptrBlock, uint8_t u8Source);
uint16_t MAIN_u16TimerOverflow(uintptr_t ptrBlock, uint8_t u8Source);

#define TRIGGER_PORT (GPIO_enPORT4)
#define TRIGGER_PIN (GPIO_enPIN_NUMBER4)

/**
 * main.c
 */
uint32_t u32FirstTime = 0UL;
uint32_t u32LastTime = 0UL;
uint16_t u16TimerOverflow = 0U;
uint32_t u32CaptureTime = 0UL;


void main(void)

{
    CLOCK_nINT_STATUS enClockStatus = CLOCK_enINT_STATUS_NOOCCUR;
    uint32_t u32Iter = 0U;
    WDT_Config_t stWDTConfig =
    {
        WDT_enENABLE_RUN,
        WDT_enINT_ENABLE_ENA,
        WDT_enMODE_INTERVAL,
        WDT_enCLOCK_ACLK,
        WDT_enINTERVAL_8192,
    };

    TIMERA_ConfigExt_t stTIMERAConfig =
    {
        TIMERA_enCLOCK_SMCLK,
        TIMERA_enCLOCK_DIV_8,
        TIMERA_enMODE_STOP,
        TIMERA_enINT_ENABLE_ENA,
        TIMERA_enINT_STATUS_NOOCCUR,
    };

    TIMERA_Capture_ConfigExt_t stCC1Config =
    {
        TIMERA_enCC_CAPTUREMODE_BOTH,
        TIMERA_enCC_CAPTURESYNC_SYNC,
        TIMERA_enCC_CAPTUREINPUT_A,
        TIMERA_enINT_ENABLE_ENA,
        TIMERA_enINT_STATUS_NOOCCUR,
    };
    WDT__vSetEnable(WDT_enENABLE_STOP); /*  stop watchdog timer*/

    GPIO__vSetDirectionByNumber(TRIGGER_PORT, TRIGGER_PIN, GPIO_enDIR_OUTPUT);
    GPIO__vSetSelectionByNumber(TRIGGER_PORT, TRIGGER_PIN, GPIO_enSEL_IO);
    GPIO__vSetOutputByNumber(TRIGGER_PORT, TRIGGER_PIN, GPIO_enLEVEL_LOW);
    GPIO__vSetConfig(GPIO_enTA_CCI1A);

    /** Rosc*/
    GPIO__vSetConfig(GPIO_enROSC);

    CLOCK__vSetDCOFrequency(800000UL, CLOCK_enRESISTOR_EXTERNAL);
    CLOCK__vSetLFXT1FrequencyMode(CLOCK_enFREQMODE_LOW);
    CLOCK__vSetXT2Enable(CLOCK_enENABLE_ENA);
	do
	{
	    CLOCK__vClearInterruptSource();
	    for(u32Iter = 0U; u32Iter < 4000U; u32Iter++); /*At least 50us*/
	    enClockStatus = CLOCK__enGetStatusInterruptSource();
	}while(CLOCK_enINT_STATUS_NOOCCUR != enClockStatus);

    CLOCK__enSetACLKSource(CLOCK_enSOURCE_LFXT1); /*32768 Hz*/
	CLOCK__enSetMCLKSource(CLOCK_enSOURCE_DCO); /*~8 MHz*/
    CLOCK__enSetSMCLKSource(CLOCK_enSOURCE_XT2); /*8 MHz*/

    WDT__vRegisterIRQSourceHandler(&MAIN_u16UltrasonicTrigger);
    WDT__vSetConfig(&stWDTConfig);






    TIMERA_CC__vRegisterIRQSourceHandler(TIMERA_enCC1,
                                         TIMERA_enCC_MODE_CAPTURE,
                                         &MAIN_u16UltrasonicCapture);
    TIMERA__vSetCaptureConfigExt(TIMERA_enCC1, &stCC1Config);


    TIMERA__vRegisterIRQSourceHandler(&MAIN_u16TimerOverflow);
    TIMERA__vSetConfigExt(&stTIMERAConfig);

    _EINT();
	while(1U)
	{
	}
}

uint16_t MAIN_u16UltrasonicTrigger(uintptr_t ptrBlock, uint8_t u8Source)
{
    TIMERA_CTL->MC = TIMERA_CTL_MC_CONTINUOS;
    PORT4_OUT_R |= PORT_OUT_R_PIN4_MASK;
    _NOP();
    PORT4_OUT_R &= ~PORT_OUT_R_PIN4_MASK;

    return (0U);
}

uint16_t MAIN_u16TimerOverflow(uintptr_t ptrBlock, uint8_t u8Source)
{
    u16TimerOverflow++;
    return (0U);
}


uint16_t MAIN_u16UltrasonicCapture(uintptr_t ptrBlock, uint8_t u8Source)
{
    uint8_t u8Edge = u8Source;
    u8Edge &= TIMERA_CC_CTL_R_CCI_MASK;
    if(TIMERA_CC_CTL_R_CCI_HIGH == u8Edge) /*Rising Detection*/
    {
        u32FirstTime = TIMERA_CC1_R_R;
    }
    else /*Falling Detection*/
    {
        /*Reset timer*/
        TIMERA_CTL->MC = TIMERA_CTL_MC_STOP;
        TIMERA_R_R = 0U;
        u32LastTime = u16TimerOverflow * 0x10000;
        u32LastTime += TIMERA_CC1_R_R;

        u32CaptureTime = u32LastTime;
        u32CaptureTime -= u32FirstTime;
        u16TimerOverflow = 0U;
    }


    return (0U);
}


