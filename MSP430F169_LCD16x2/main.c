#include <main.h>


#define LED1_PORT (GPIO_enPORT1)
#define LED1_PIN (GPIO_enPIN_NUMBER0)
#define LED3_PORT (GPIO_enPORT1)
#define LED3_PIN (GPIO_enPIN_NUMBER2)
#define LED4_PORT (GPIO_enPORT1)
#define LED4_PIN (GPIO_enPIN_NUMBER3)
#define TEST_PORT (GPIO_enPORT3)
#define TEST_PIN (GPIO_enPIN_NUMBER4)


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
    LCD1602_Command(SRDisp);
    LCD1602_Command(SRDisp);
    LCD1602_Command(SRDisp);
    LCD1602_Command(SRDisp);
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

/**
 * main.c
 */


void main(void)
{
    uint8_t u8Value = 0U;
    uint16_t u16Iter = 0U;
    SVS->CTL_bits.VLD = 0U;
    WDT__vSetEnable(WDT_enENABLE_STOP); /*  stop watchdog timer*/

    GPIO__vSetDirectionByNumber(TEST_PORT, TEST_PIN, GPIO_enDIR_OUTPUT);
    GPIO__vSetSelectionByNumber(TEST_PORT, TEST_PIN, GPIO_enSEL_IO);

    /** Rosc*/
    GPIO__vSetConfig(GPIO_enROSC);

    CLOCK__vSetDCOFrequency(800000UL, CLOCK_enRESISTOR_EXTERNAL);
    CLOCK__vSetLFXT1FrequencyMode(CLOCK_enFREQMODE_LOW);
    CLOCK__vSetXT2Enable(CLOCK_enENABLE_ENA);
    do
    {
        CLOCK_IFG1_R &= ~ CLOCK_IFG1_R_IFG_MASK;
        for(u16Iter = 0U; u16Iter < 4000U; u16Iter++); /*At least 50us*/
    }while(0U != (CLOCK_IFG1_R_IFG_MASK & CLOCK_IFG1_R));

    CLOCK__enSetACLKSource(CLOCK_enSOURCE_LFXT1); /*32768 Hz*/
    CLOCK__enSetMCLKSource(CLOCK_enSOURCE_DCO); /*~8 MHz*/
    CLOCK__enSetSMCLKSource(CLOCK_enSOURCE_XT2); /*8 MHz*/

    //4 bits , 2 lineas, 5x8 puntos, incr cursor
    Conf_LCD1602();//configuracion de la pantalla LCD1602
    LCD1602_Pos(3,0);
    LCD1602_Data('H');
    LCD1602_Data('O');
    LCD1602_Data('L');
    LCD1602_Data('A');
    LCD1602_Data(' ');
    LCD1602_Data('M');
    LCD1602_Data('U');
    LCD1602_Data('N');
    LCD1602_Data('D');
    LCD1602_Data('O');
    LCD1602_Pos(0,1);
    LCD1602_Data('L'); //escribe H en 0,0. Cursor 0,1
    LCD1602_Data('a');
    LCD1602_Data('l'); //escribe H en 0,0. Cursor 0,1
    LCD1602_Data('o');
    LCD1602_Data(' ');
    LCD1602_Data('A');
    LCD1602_Data('l');
    LCD1602_Data('v');
    LCD1602_Data('a');
    LCD1602_Data('r');
    LCD1602_Data('e');
    LCD1602_Data('z');
    while(1)
    {
        for(u16Iter = 0U; u16Iter < 0xFFFFU; u16Iter++)
        {
            _NOP();
        }
        LCD1602_Pos(13,1);
        LCD1602_Data('0' + u8Value);
        if(u8Value >= 9U)
        {
            u8Value = 0U;
        }
        else
        {
            u8Value++;
        }
    }
}
