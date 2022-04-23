#include "DriverLib/DriverLib.h"
#include "xUtils/Conversion/Conversion.h"
#include <main.h>


uint16_t MAIN_u16UltrasonicTrigger(uintptr_t ptrBlock, uint16_t u16Source);
uint16_t MAIN_u16UltrasonicCapture(uintptr_t ptrBlock, uint16_t u16Source);
uint16_t MAIN_u16TimerOverflow(uintptr_t ptrBlock, uint16_t u16Source);

#define TRIGGER_PORT (GPIO_enPORT4)
#define TRIGGER_PIN (GPIO_enPIN_NUMBER4)

/**
 * main.c
 */
uint32_t u32FirstTime = 0UL;
uint32_t u32FirstOverflowTime = 0UL;
uint32_t u32LastOverflowTime = 0UL;
uint32_t u32LastTime = 0UL;
uint16_t u16TimerOverflow = 0U;
uint8_t u8Complete = 0U;
volatile uint32_t u32CaptureTime = 0UL;



void Conf_LCD1602(void)
{
    long Delay=0;
     /*Conf para P1.0=RS P1.1=RW P1.2=E*/
    GPIO__vSetDirection(PUERTO_E, E, GPIO_enDIR_OUTPUT);
    GPIO__vSetSelection(PUERTO_E, E, GPIO_enSEL_IO);
    GPIO__vSetOutput(PUERTO_E, E, GPIO_enLEVEL_LOW);

    GPIO__vSetDirection(PUERTO_RS, RS, GPIO_enDIR_OUTPUT);
    GPIO__vSetSelection(PUERTO_RS, RS, GPIO_enSEL_IO);
    GPIO__vSetOutput(PUERTO_RS, RS, GPIO_enLEVEL_LOW);

    GPIO__vSetDirection(PUERTO_RW, RW, GPIO_enDIR_OUTPUT);
    GPIO__vSetSelection(PUERTO_RW, RW, GPIO_enSEL_IO);
    GPIO__vSetOutput(PUERTO_RW, RW, GPIO_enLEVEL_LOW);

    /*Conf para Datos D4-D7*/
    GPIO__vSetDirection(PUERTO_D4, D4, GPIO_enDIR_OUTPUT);
    GPIO__vSetSelection(PUERTO_D4, D4, GPIO_enSEL_IO);
    GPIO__vSetOutput(PUERTO_D4, D4, GPIO_enLEVEL_LOW);

    GPIO__vSetDirection(PUERTO_D5, D5, GPIO_enDIR_OUTPUT);
    GPIO__vSetSelection(PUERTO_D5, D5, GPIO_enSEL_IO);
    GPIO__vSetOutput(PUERTO_D5, D5, GPIO_enLEVEL_LOW);

    GPIO__vSetDirection(PUERTO_D6, D6, GPIO_enDIR_OUTPUT);
    GPIO__vSetSelection(PUERTO_D6, D6, GPIO_enSEL_IO);
    GPIO__vSetOutput(PUERTO_D6, D6, GPIO_enLEVEL_LOW);

    GPIO__vSetDirection(PUERTO_D7, D7, GPIO_enDIR_OUTPUT);
    GPIO__vSetSelection(PUERTO_D7, D7, GPIO_enSEL_IO);
    GPIO__vSetOutput(PUERTO_D7, D7, GPIO_enLEVEL_LOW);

    for(Delay=30000; Delay>0; Delay--);//20 ms aprox a 16MHz
    //manda 0x3 en la parte alta de la LCD
    GPIO__vSetOutputByMask(PUERTO_D4, D4, D4);
    GPIO__vSetOutputByMask(PUERTO_D5, D5, D5);
    LCD1602_Trigger(); //manda un pulso en el pin E (Enable)
    for(Delay=10000; Delay>0; Delay--);//7 ms aprox a 16MHz

    LCD1602_Trigger(); //manda un pulso en el pin E (Enable)
    for(Delay=500; Delay>0; Delay--);//100 us aprox a 16MHz

    LCD1602_Trigger(); //manda un pulso en el pin E (Enable)
    for(Delay=10000; Delay>0; Delay--);//7 ms aprox a 16MHz

    //primer comando 0x20 configuracion a 4 bits
    GPIO__vSetOutputByMask(PUERTO_D4, D4, GPIO_enPIN_NONE); //conf para los pines D4-7 = P1.4-7
    LCD1602_Trigger(); //manda un pulso en el pin E (Enable)
    for(Delay=240; Delay>0; Delay--);//40 us aprox a 16MHz

    /*M8BIT o M4BIT,M2LINE o M1LINE, M5_8_Font o M5_11_Font */
    LCD1602_Command(M4BIT|M2LINE|M5_8_Font);

    /*ONDisp o OFFDisp, ONCursor o OFFCursor,ONBlink o OFFBLink*/
    LCD1602_Command(ONDisp|OFFCursor|OFFBlink );

    LCD1602_Command(CLEAR); //limpia la pantalla
    for(Delay=3000; Delay>0; Delay--);//1.60 ms aprox a 16MHz

    /*IAdd o DAdd*/
    LCD1602_Command(IncAdd);

    LCD1602_Command(HOME);//Manda cursor a home
    for(Delay=3000; Delay>0; Delay--);//1.60 ms aprox a 16MHz
   /* LCD1602_Command(SRDisp);
    LCD1602_Command(SRDisp);
    LCD1602_Command(SRDisp);
    LCD1602_Command(SRDisp);
    */
}

PORT_t* pstDataPort[4U] = {P_D4, P_D5, P_D6, P_D7};
uint8_t pstDataPinMask[4U] = {(uint8_t) D4,(uint8_t) D5,(uint8_t) D6,(uint8_t) D7};

void LCD1602_TranferData(uint8_t u8Value)
{
    uint8_t u8BitMask = 0x80U;
    uint8_t u8Bits = 0x0U;
    uint8_t u8Section = 0x0U;
    for(u8Section = 0U; u8Section < 2U; u8Section++)
    {
        for(u8Bits = 0U; u8Bits < 4U; u8Bits++)
        {
            if(0UL == (u8Value & u8BitMask))
            {
                pstDataPort[3U - u8Bits]->OUT &= ~pstDataPinMask[3U - u8Bits];
            }
            else
            {
                pstDataPort[3U - u8Bits]->OUT |= pstDataPinMask[3U - u8Bits];
            }
            u8BitMask >>= 1U;
        }
        LCD1602_Trigger(); //manda un pulso en el pin E (Enable)
    }
}


void LCD1602_Command(uint8_t u8Command)
{
    P_RW->OUT_bits.RW_P = 0U; //RW para escritura 1=lectura 0=escritura
    P_RS->OUT_bits.RS_P = 0U; //RS 1=comando 0=comando
    LCD1602_TranferData(u8Command);
}

void LCD1602_Data(uint8_t u8Data)
{
    P_RW->OUT_bits.RW_P = 0U; //RW para escritura 1=lectura 0=escritura
    P_RS->OUT_bits.RS_P = 1U; //RS 1=comando 0=comando
    LCD1602_TranferData(u8Data);
}

void LCD1602_Trigger(void)
{
    P_E->OUT_bits.E_P = 1U;
    _NOP();
    P_E->OUT_bits.E_P = 0U;
}

void LCD1602_Pos(uint8_t u8Column, uint8_t u8Row)
{
    uint8_t u8Address=0x80U;
    u8Column &= 0xFU;
    u8Row &= 0x1;
    u8Row <<= 6U;
    u8Address |= u8Column;
    u8Address |= u8Row;
    LCD1602_Command(u8Address);
}


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
        WDT_enINTERVAL_32768,
    };

    TIMERA_ConfigExt_t stTIMERAConfig =
    {
        0U,
        TIMERA_enCLOCK_SMCLK,
        TIMERA_enCLOCK_DIV_8,
        TIMERA_enMODE_CONTINUOS,
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
    GPIO__vSetConfig(GPIO_enTA_CCI1A_P12);

    /** Rosc*/
    GPIO__vSetConfig(GPIO_enROSC_P25);

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


    Conf_LCD1602();//configuracion de la pantalla LCD1602

    TIMERA_CC__vRegisterIRQSourceHandler(TIMERA_enCC1,
                                         TIMERA_enCC_MODE_CAPTURE,
                                         &MAIN_u16UltrasonicCapture);
    TIMERA_CC__vSetCaptureConfigExt(TIMERA_enCC1, &stCC1Config);


    TIMERA__vRegisterIRQSourceHandler(&MAIN_u16TimerOverflow);
    TIMERA__vSetConfigExt(&stTIMERAConfig);

    _EINT();
	while(1U)
	{
	    if(1U == u8Complete)
	    {
	        uint32_t u32Value = 0U;
	        u32Value = u32CaptureTime;
	        char pcConv[30U] = {0U};
	        char* pcConvPrt = pcConv;
	        (void) Conv__u8UInt2String(u32Value, pcConv);
            LCD1602_Pos(0,1);
	        while(0U != *pcConvPrt)
	        {
                LCD1602_Data(*pcConvPrt);
                pcConvPrt++;
	        }
            LCD1602_Data(' ');
            LCD1602_Data('c');
            LCD1602_Data('m');
            LCD1602_Data(' ');
            LCD1602_Data(' ');
            LCD1602_Data(' ');
            LCD1602_Data(' ');
            u8Complete = 0U;
	    }

	}
}

uint16_t MAIN_u16UltrasonicTrigger(uintptr_t ptrBlock, uint16_t u16Source)
{
    if(0U == u8Complete)
    {
        PORT4_OUT_R |= PORT_OUT_R_PIN4_MASK;
        _NOP();
        PORT4_OUT_R &= ~PORT_OUT_R_PIN4_MASK;
    }

    return (0xFFU);
}

uint16_t MAIN_u16TimerOverflow(uintptr_t ptrBlock, uint16_t u16Source)
{
    u16TimerOverflow++;
    return (0xFFU);
}


uint16_t MAIN_u16UltrasonicCapture(uintptr_t ptrBlock, uint16_t u16Source)
{
    uint8_t u8Edge = u16Source;
    u8Edge &= TIMERA_CC_CTL_R_CCI_MASK;
    if(TIMERA_CC_CTL_R_CCI_HIGH == u8Edge) /*Rising Detection*/
    {
        u32FirstOverflowTime = u16TimerOverflow;
        u32FirstTime = TIMERA_CC1_R_R;
    }
    else /*Falling Detection*/
    {
        /*Reset timer*/
        u32LastOverflowTime = u16TimerOverflow;
        u32LastOverflowTime -= u32FirstOverflowTime;
        u32LastTime = u32LastOverflowTime;
        u32LastTime *= 0x10000;
        u32LastTime += TIMERA_CC1_R_R;

        u32CaptureTime = u32LastTime - u32FirstTime;
        u8Complete = 1U;
    }


    return (0xFFU);
}


