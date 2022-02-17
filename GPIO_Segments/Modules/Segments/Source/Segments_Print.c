/**
 *
 * @file Segments_Print.c
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
 * @verbatim 16 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 16 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "Modules/Segments/Header/Segments_Print.h"
#include "Modules/Segments/Header/Segments_Global.h"

#define SEGMENTS_CODIFICATION_NUMBER (10U)

/*
  A
  _
F|G|B
  _
E|_|C
  D
OGFEDCBA Anode common
0: 1100 0000
1: 1111 1001
2: 1010 0100
3: 1011 0000
4: 1001 1001
5: 1001 0010
6: 1000 0010
7: 1111 1000
8: 1000 0000
9: 1001 1000
*/

static uint8_t SEGMENTS_u8Codification[SEGMENTS_CODIFICATION_NUMBER] =
{
   0xC0,
   0xF9,
   0xA4,
   0xB0,
   0x99,
   0x92,
   0x82,
   0xF8,
   0x80,
   0x98,
};


void SEGMENTS__vPrint(uint8_t u8Number, SEGMENTS_nDIGIT enDigit, SEGMENTS_nCOMMON enCommon)
{
    uint8_t u8Count = 0U;
    uint8_t u8Bit0 = 0U;
    uint8_t u8Level = 0U;
    uint8_t u8LevelNeg = 0U;
    uint8_t u8Codification = 0U;
    GPIO_nPORT enPort = GPIO_enPORT1;
    GPIO_nPIN_NUMBER enPin = GPIO_enPIN_NUMBER0;

    u8Level = (uint8_t) enCommon;
    u8LevelNeg = ~u8Level;
    u8Codification = SEGMENTS_u8Codification[u8Number];
    if(SEGMENTS_enCOMMON_CATHODE == enCommon)
    {
        u8Codification = ~u8Codification;
    }

    for(u8Count = 0U; u8Count < (uint8_t) SEGMENTS_enSEG_MAX; u8Count++)
    {
        u8Bit0 = u8Codification & 1U;
        enPort = SEGMENTS__enGetSegPort((SEGMENTS_nSEG) u8Count);
        enPin = SEGMENTS__enGetSegPin((SEGMENTS_nSEG) u8Count);
        GPIO__vSetOutputByNumber(enPort, enPin, (GPIO_nLEVEL) u8Bit0);
        u8Codification >>= 1U;
    }


    for(u8Count = 0U; u8Count < (uint8_t) SEGMENTS_enDIGIT_MAX; u8Count++)
    {
        enPort = SEGMENTS__enGetDigitPort((SEGMENTS_nDIGIT) u8Count);
        enPin = SEGMENTS__enGetDigitPin((SEGMENTS_nDIGIT) u8Count);
        GPIO__vSetOutputByNumber(enPort, enPin, (GPIO_nLEVEL) u8Level);
    }

    enPort = SEGMENTS__enGetDigitPort(enDigit);
    enPin = SEGMENTS__enGetDigitPin(enDigit);
    GPIO__vSetOutputByNumber(enPort, enPin, u8LevelNeg);
}



