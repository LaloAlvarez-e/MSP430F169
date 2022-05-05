/**
 *
 * @file uart.c
 * @copyright
 * @verbatim InDeviceMex 2021 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 4 may. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 4 may. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#include "uart.h"
#include "DriverLib/DriverLib.h"

#define BitTime_5  (1307U)                      // ~ 0.5 bit length + small adjustment
#define BitTime    (3333U)                      // 427us bit length ~ 2341 baud

uint16_t UART_u16Handler_TX(uintptr_t uptrModule, uint16_t u16IntSource);
uint16_t UART_u16Handler_RX(uintptr_t uptrModule, uint16_t u16IntSource);
uint16_t UART_u16Handler_StartRx(uintptr_t uptrModule, uint16_t u16IntSource);

static uint8_t u8TXBitCount = 0U;
static uint8_t u8RXBitCount = 0U;
static uint16_t u16TXData = 0U;
static uint8_t u8RXData = 0U;

void UART__vInit(void)
{

    PORT1->OUT_bits.P5 = PORT_OUT_PIN1_HIGH;
    PORT1->SEL_bits.P1 = PORT_SEL_PIN1_PERIPHERAL;
    PORT1->SEL_bits.P5 = PORT_SEL_PIN5_PERIPHERAL;

    PORT1->DIR_bits.P1 = PORT_DIR_PIN1_INPUT;
    PORT1->DIR_bits.P5 = PORT_DIR_PIN1_OUTPUT;

    TIMERA_CC0_CTL_R = TIMERA_CC_CTL_R_OUT_HIGH;
    TIMERA->CTL_bits.SSEL = TIMERA_CTL_SSEL_SMCLK;
    TIMERA->CTL_bits.MC = TIMERA_CTL_MC_CONTINUOS;

    TIMERA_CC__vRegisterIRQSourceHandler(TIMERA_enCC0, TIMERA_enCC_MODE_CAPTURE, &UART_u16Handler_StartRx);
}

uint8_t UART__u8RxReady(void)
{
    u8RXBitCount = 8U;
    u8RXData = 0U;
    TIMERA_CC__vRegisterIRQSourceHandler(TIMERA_enCC0,
                                       TIMERA_enCC_MODE_COMPARE,
                                       &UART_u16Handler_RX);
    TIMERA_CC0_CTL_R = TIMERA_CC_CTL_R_SCS_SYNC |
                         TIMERA_CC_CTL_R_OUTMOD_SET |
                         TIMERA_CC_CTL_R_CM_FALLING |
                         TIMERA_CC_CTL_R_CAP_CAPTURE |
                         TIMERA_CC_CTL_R_IE_ENA |
                         TIMERA_CC_CTL_R_CCIS_CCIA;
    while(TIMERA_CC0_CTL_R & TIMERA_CC_CTL_R_IE_ENA)
    {
        __bis_SR_register(LPM1_bits);
    }
    return (u8RXData);
}



void UART__vTxByte(uint8_t u8DataArg)
{
    u8TXBitCount = 10U;                             // Load Bit counter, 8data + ST/SP
    TIMERA_CC__vRegisterIRQSourceHandler(TIMERA_enCC0,
                                         TIMERA_enCC_MODE_COMPARE,
                                         &UART_u16Handler_TX);
    //while(TIMERA_CC0_R_R != TIMERA_R_R)
    {// Prevent async capture
        TIMERA_CC0_R_R = TIMERA_R_R;                             // Current state of TA counter
    }
    TIMERA_CC0_R_R += BitTime;
    u16TXData = u8DataArg;
    u16TXData |= 0x100;                        // Add mark stop bit to RXTXData
    u16TXData = u16TXData << 1;                 // Add space start bit
    TIMERA_CC0_CTL_R =  TIMERA_CC_CTL_R_CCIS_CCIB |
                        TIMERA_CC_CTL_R_OUTMOD_SET |
                        TIMERA_CC_CTL_R_IE_ENA;
    while (TIMERA_CC0_CTL_R & TIMERA_CC_CTL_R_IE_MASK)
    {
        __bis_SR_register(LPM1_bits);
    }
}

uint16_t UART_u16Handler_StartRx(uintptr_t uptrModule, uint16_t u16IntSource)
{
    /**
     *  If the system enters to this interrupt,
     *  the user has sent the first bit
     */


    /**
     * Add next bit offset time
     * */
    TIMERA_CC0_R_R += BitTime + BitTime_5;

    /**
     * Switch to compare mode, so every time the system detect the next bit time,
     * the system will capture the value of the input.
     */
    TIMERA_CC0_CTL_R &= ~TIMERA_CC_CTL_R_CAP_CAPTURE;

    return (0xFFU);
}


uint16_t UART_u16Handler_TX(uintptr_t uptrModule, uint16_t u16IntSource)
{
    uint16_t u16Status = 0xFFU;

    /**
     * Add next bit offset time
     * */
    TIMERA_CC0_R_R += BitTime;

    /**
     * If the input CCIB is selected,
     * it means that the system is transmitting info to the tester
     */
    if (0U == u8TXBitCount)
    {
        TIMERA_CC0_CTL_R &= ~ TIMERA_CC_CTL_R_IE_MASK;
        u16Status = 0U;
    }// All bits TXed, disable interrupt
    else
    {
        TIMERA_CC0_CTL_R |=  TIMERA_CC_CTL_R_OUTMOD_RESET;                    // TX Space
        if (0x1U & u16TXData)
        {
            TIMERA_CC0_CTL_R &= ~ TIMERA_CC_CTL_R_OUTMOD_TOGGLE;
        }// TX Mark
        u16TXData = u16TXData >> 1;
        u8TXBitCount--;
    }
    return (u16Status);
}

uint16_t UART_u16Handler_RX(uintptr_t uptrModule, uint16_t u16IntSource)
{
    uint16_t u16Status = 0xFFU;

    /**
     * Add next bit offset time
     * */
    TIMERA_CC0_R_R += BitTime;

    u8RXData = u8RXData >> 1;
    if (u16IntSource & TIMERA_CC_CTL_R_SCCI_MASK)
    {// Get bit waiting in receive latch
        u8RXData |= 0x80U;
    }
    u8RXBitCount--;   // All bits RXed?
    if (0U == u8RXBitCount)
    {
        TIMERA_CC0_CTL_R &= ~TIMERA_CC_CTL_R_IE_MASK;    // All bits RXed, disable interrupt
        u16Status = 0U;
    }
    return (u16Status);
}
