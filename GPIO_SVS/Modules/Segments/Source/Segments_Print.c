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

/*
  A
  _
F|G|B
  _
E|_|C
  D
OGFEDCBA Anode common
*/

#define SEGMENT_SEGA_BIT (0U)
#define SEGMENT_SEGB_BIT (1U)
#define SEGMENT_SEGC_BIT (2U)
#define SEGMENT_SEGD_BIT (3U)
#define SEGMENT_SEGE_BIT (4U)
#define SEGMENT_SEGF_BIT (5U)
#define SEGMENT_SEGG_BIT (6U)
#define SEGMENT_DOT_BIT  (7U)

#define SEGMENT_COD(dot,g,f,e,d,c,b,a) (dot << SEGMENT_DOT_BIT)  | (g << SEGMENT_SEGG_BIT) | \
                                       (f << SEGMENT_SEGF_BIT) | (e << SEGMENT_SEGE_BIT) | \
                                       (d << SEGMENT_SEGD_BIT) | (c << SEGMENT_SEGC_BIT) | \
                                       (b << SEGMENT_SEGB_BIT) | (a << SEGMENT_SEGA_BIT) \


#define SEGMENTS_CODIFICATION_NUMBER   (128U)


static uint8_t SEGMENTS_u8Codification[SEGMENTS_CODIFICATION_NUMBER] =
{
    SEGMENT_COD(1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U) ,
    SEGMENT_COD(1U, 1U, 1U, 1U, 1U, 0U, 0U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 0U, 0U, 1U, 0U, 0U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 0U, 0U, 0U, 0U) ,
    SEGMENT_COD(1U, 0U, 0U, 1U, 1U, 0U, 0U, 1U) ,
    SEGMENT_COD(1U, 0U, 0U, 1U, 0U, 0U, 1U, 0U) ,
    SEGMENT_COD(1U, 0U, 0U, 0U, 0U, 0U, 1U, 0U) ,
    SEGMENT_COD(1U, 1U, 1U, 1U, 1U, 0U, 0U, 0U) ,
    SEGMENT_COD(1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U) ,
    SEGMENT_COD(1U, 0U, 0U, 1U, 1U, 0U, 0U, 0U) ,
    SEGMENT_COD(1U, 0U, 0U, 0U, 1U, 0U, 0U, 0U) ,
    SEGMENT_COD(1U, 0U, 0U, 0U, 0U, 0U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 0U, 0U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 0U, 0U, 0U, 0U, 1U) ,
    SEGMENT_COD(1U, 0U, 0U, 0U, 0U, 1U, 1U, 0U) ,
    SEGMENT_COD(1U, 0U, 0U, 0U, 1U, 1U, 1U, 0U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(0U, 1U, 1U, 1U, 1U, 1U, 0U, 1U) ,
    SEGMENT_COD(1U, 1U, 0U, 1U, 1U, 1U, 0U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 1U, 1U, 1U, 1U, 1U, 0U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 1U, 1U, 1U, 1U, 1U, 0U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(0U, 1U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(0U, 1U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 0U, 1U, 1U, 0U, 1U) ,
    SEGMENT_COD(1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U) ,
    SEGMENT_COD(1U, 1U, 1U, 1U, 1U, 0U, 0U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 0U, 0U, 1U, 0U, 0U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 0U, 0U, 0U, 0U) ,
    SEGMENT_COD(1U, 0U, 0U, 1U, 1U, 0U, 0U, 1U) ,
    SEGMENT_COD(1U, 0U, 0U, 1U, 0U, 0U, 1U, 0U) ,
    SEGMENT_COD(1U, 0U, 0U, 0U, 0U, 0U, 1U, 0U) ,
    SEGMENT_COD(1U, 1U, 1U, 1U, 1U, 0U, 0U, 0U) ,
    SEGMENT_COD(1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U) ,
    SEGMENT_COD(1U, 0U, 0U, 1U, 1U, 0U, 0U, 0U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 0U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(0U, 1U, 0U, 1U, 1U, 1U, 0U, 0U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 0U, 0U, 1U, 0U, 0U, 0U) ,
    SEGMENT_COD(1U, 0U, 0U, 0U, 0U, 0U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 0U, 0U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 0U, 0U, 0U, 0U, 1U) ,
    SEGMENT_COD(1U, 0U, 0U, 0U, 0U, 1U, 1U, 0U) ,
    SEGMENT_COD(1U, 0U, 0U, 0U, 1U, 1U, 1U, 0U) ,
    SEGMENT_COD(1U, 0U, 0U, 1U, 0U, 0U, 0U, 0U) ,
    SEGMENT_COD(1U, 0U, 0U, 0U, 1U, 0U, 0U, 1U) ,
    SEGMENT_COD(1U, 1U, 0U, 0U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 1U, 1U, 1U, 0U, 0U, 0U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 1U, 0U, 0U, 0U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 0U, 0U, 0U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 0U, 0U, 1U, 1U, 0U, 0U) ,
    SEGMENT_COD(0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U) ,
    SEGMENT_COD(1U, 0U, 0U, 0U, 1U, 1U, 0U, 1U) ,
    SEGMENT_COD(1U, 0U, 0U, 1U, 0U, 0U, 1U, 0U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 1U, 0U, 0U, 0U, 0U, 0U, 1U) ,
    SEGMENT_COD(1U, 1U, 0U, 0U, 0U, 0U, 0U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 0U, 0U, 1U, 0U, 0U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 0U, 0U, 1U, 0U, 0U) ,
    SEGMENT_COD(1U, 1U, 0U, 0U, 0U, 1U, 1U, 0U) ,
    SEGMENT_COD(1U, 0U, 0U, 1U, 1U, 0U, 1U, 1U) ,
    SEGMENT_COD(1U, 1U, 1U, 1U, 0U, 0U, 0U, 0U) ,
    SEGMENT_COD(1U, 1U, 0U, 1U, 1U, 1U, 0U, 0U) ,
    SEGMENT_COD(1U, 1U, 1U, 1U, 0U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 1U, 0U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 0U, 0U, 1U, 0U, 0U, 0U) ,
    SEGMENT_COD(1U, 0U, 0U, 0U, 0U, 0U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 0U, 0U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 0U, 0U, 0U, 0U, 1U) ,
    SEGMENT_COD(1U, 0U, 0U, 0U, 0U, 1U, 1U, 0U) ,
    SEGMENT_COD(1U, 0U, 0U, 0U, 1U, 1U, 1U, 0U) ,
    SEGMENT_COD(1U, 0U, 0U, 1U, 0U, 0U, 0U, 0U) ,
    SEGMENT_COD(1U, 0U, 0U, 0U, 1U, 0U, 0U, 1U) ,
    SEGMENT_COD(1U, 1U, 0U, 0U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 1U, 1U, 1U, 0U, 0U, 0U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 1U, 0U, 0U, 0U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 0U, 0U, 0U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 0U, 0U, 1U, 1U, 0U, 0U) ,
    SEGMENT_COD(0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U) ,
    SEGMENT_COD(1U, 0U, 0U, 0U, 1U, 1U, 0U, 1U) ,
    SEGMENT_COD(1U, 0U, 0U, 1U, 0U, 0U, 1U, 0U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 1U, 0U, 0U, 0U, 0U, 0U, 1U) ,
    SEGMENT_COD(1U, 1U, 0U, 0U, 0U, 0U, 0U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 0U, 0U, 1U, 0U, 0U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 0U, 1U, 0U, 0U, 1U, 0U, 0U) ,
    SEGMENT_COD(1U, 1U, 0U, 0U, 0U, 1U, 1U, 0U) ,
    SEGMENT_COD(1U, 0U, 0U, 1U, 1U, 0U, 1U, 1U) ,
    SEGMENT_COD(1U, 1U, 1U, 1U, 0U, 0U, 0U, 0U) ,
    SEGMENT_COD(1U, 0U, 1U, 1U, 1U, 1U, 1U, 1U) ,
    SEGMENT_COD(1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U) ,
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

    for(u8Count = 0U; u8Count < (uint8_t) SEGMENTS_enDIGIT_MAX; u8Count++)
    {
        enPort = SEGMENTS__enGetDigitPort((SEGMENTS_nDIGIT) u8Count);
        enPin = SEGMENTS__enGetDigitPin((SEGMENTS_nDIGIT) u8Count);
        GPIO__vSetOutputByNumber(enPort, enPin, (GPIO_nLEVEL) u8Level);
    }

    for(u8Count = 0U; u8Count < (uint8_t) SEGMENTS_enSEG_MAX; u8Count++)
    {
        u8Bit0 = u8Codification & 1U;
        enPort = SEGMENTS__enGetSegPort((SEGMENTS_nSEG) u8Count);
        enPin = SEGMENTS__enGetSegPin((SEGMENTS_nSEG) u8Count);
        GPIO__vSetOutputByNumber(enPort, enPin, (GPIO_nLEVEL) u8Bit0);
        u8Codification >>= 1U;
    }

    enPort = SEGMENTS__enGetDigitPort(enDigit);
    enPin = SEGMENTS__enGetDigitPin(enDigit);
    GPIO__vSetOutputByNumber(enPort, enPin, (GPIO_nLEVEL) u8LevelNeg);
}
