/**
 *
 * @file CLOCK_DCO.c
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
 * @verbatim 15 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 15 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/CLOCK/Driver/DCO/CLOCK_DCO.h"
#include "DriverLib/MCU/MCU.h"

#define CLOCK_MAXINDEX (8U * 8U)

/*(4 << 4U) | 3*/
static uint8_t CLOCK_u8DCOIndex = 35U;

/*(RSEL << 4U) | DCO*/
static const uint8_t CLOCK_u8CodificationLUT_Internal[CLOCK_MAXINDEX] =
{
 (0U << 4U) | 0U, (0U << 4U) | 1U, (0U << 4U) | 2U, (0U << 4U) | 3U,
 (1U << 4U) | 0U, (0U << 4U) | 4U, (1U << 4U) | 1U, (0U << 4U) | 5U,
 (1U << 4U) | 2U, (0U << 4U) | 6U, (1U << 4U) | 3U, (0U << 4U) | 7U,
 (1U << 4U) | 4U, (2U << 4U) | 0U, (1U << 4U) | 5U, (2U << 4U) | 1U,
 (1U << 4U) | 6U, (2U << 4U) | 2U, (1U << 4U) | 7U, (2U << 4U) | 3U,
 (2U << 4U) | 4U, (3U << 4U) | 0U, (2U << 4U) | 5U, (3U << 4U) | 1U,
 (2U << 4U) | 6U, (3U << 4U) | 2U, (2U << 4U) | 7U, (3U << 4U) | 3U,
 (3U << 4U) | 4U, (4U << 4U) | 0U, (3U << 4U) | 5U, (4U << 4U) | 1U,
 (3U << 4U) | 6U, (4U << 4U) | 2U, (3U << 4U) | 7U, (4U << 4U) | 3U,
 (4U << 4U) | 4U, (5U << 4U) | 0U, (4U << 4U) | 5U, (5U << 4U) | 1U,
 (4U << 4U) | 6U, (5U << 4U) | 2U, (4U << 4U) | 7U, (5U << 4U) | 3U,
 (5U << 4U) | 4U, (6U << 4U) | 0U, (5U << 4U) | 5U, (6U << 4U) | 1U,
 (5U << 4U) | 6U, (6U << 4U) | 2U, (5U << 4U) | 7U, (6U << 4U) | 3U,
 (6U << 4U) | 4U, (7U << 4U) | 0U, (6U << 4U) | 5U, (7U << 4U) | 1U,
 (6U << 4U) | 6U, (7U << 4U) | 2U, (6U << 4U) | 7U, (7U << 4U) | 3U,
 (7U << 4U) | 4U, (7U << 4U) | 5U, (7U << 4U) | 6U, (7U << 4U) | 7U,
};
static const uint8_t CLOCK_u8CodificationLUT_External[CLOCK_MAXINDEX] =
{
 (0U << 4U) | 0U, (0U << 4U) | 1U, (0U << 4U) | 2U, (0U << 4U) | 3U,
 (0U << 4U) | 4U, (1U << 4U) | 0U, (0U << 4U) | 5U, (1U << 4U) | 1U,
 (0U << 4U) | 6U, (1U << 4U) | 2U, (0U << 4U) | 7U, (1U << 4U) | 3U,
 (1U << 4U) | 4U, (2U << 4U) | 0U, (1U << 4U) | 5U, (2U << 4U) | 1U,
 (1U << 4U) | 6U, (2U << 4U) | 2U, (1U << 4U) | 7U, (2U << 4U) | 3U,
 (2U << 4U) | 4U, (2U << 4U) | 5U, (3U << 4U) | 0U, (2U << 4U) | 6U,
 (3U << 4U) | 1U, (2U << 4U) | 7U, (3U << 4U) | 2U, (3U << 4U) | 3U,
 (3U << 4U) | 4U, (4U << 4U) | 0U, (3U << 4U) | 5U, (4U << 4U) | 1U,
 (3U << 4U) | 6U, (4U << 4U) | 2U, (3U << 4U) | 7U, (4U << 4U) | 3U,
 (4U << 4U) | 4U, (4U << 4U) | 5U, (5U << 4U) | 0U, (4U << 4U) | 6U,
 (5U << 4U) | 1U, (4U << 4U) | 7U, (5U << 4U) | 2U, (5U << 4U) | 3U,
 (6U << 4U) | 0U, (5U << 4U) | 4U, (6U << 4U) | 1U, (5U << 4U) | 5U,
 (6U << 4U) | 2U, (5U << 4U) | 6U, (7U << 4U) | 0U, (6U << 4U) | 3U,
 (5U << 4U) | 7U, (6U << 4U) | 4U, (7U << 4U) | 1U, (7U << 4U) | 2U,
 (6U << 4U) | 5U, (7U << 4U) | 3U, (6U << 4U) | 6U, (7U << 4U) | 4U,
 (6U << 4U) | 7U, (7U << 4U) | 5U, (7U << 4U) | 6U, (7U << 4U) | 7U,
};

/* Resistor external 300 KOhms*/
static const uint32_t CLOCK_u32FrequencyLUT_Internal[CLOCK_MAXINDEX] =
{
   93943UL,  104503UL,  116249UL,  129315UL,  130075UL,  143851UL,  144696UL,  160020UL,
  160960UL,  178006UL,  179052UL,  198014UL,  199178UL,  210325UL,  221566UL,  233965UL,
  246470UL,  260263UL,  274174UL,  289517UL,  322059UL,  340083UL,  358259UL,  378309UL,
  398528UL,  420831UL,  443323UL,  468133UL,  520752UL,  549895UL,  579286UL,  611704UL,
  644398UL,  680461UL,  716829UL,  756946UL,  842027UL,  889150UL,  936672UL,  989092UL,
 1041956UL, 1100267UL, 1159073UL, 1223939UL, 1361512UL, 1437707UL, 1514547UL, 1599307UL,
 1684785UL, 1779071UL, 1874157UL, 1979041UL, 2201488UL, 2324692UL, 2448939UL, 2585991UL,
 2724203UL, 2876659UL, 3030407UL, 3200000UL, 3559684UL, 3959798UL, 4404885UL, 4900000UL
};

/* Resistor external 100 KOhms*/
static const uint32_t CLOCK_u32FrequencyLUT_External[CLOCK_MAXINDEX] =
{
  227300UL,  248800UL,  274000UL,  299400UL,  328900UL,  354600UL,  362300UL,  386100UL,
  400000UL,  427400UL,  454500UL,  467300UL,  515500UL,  549500UL,  561800UL,  602400UL,
  617300UL,  657900UL,  704200UL,  724600UL,  793700UL,  877200UL,  943400UL,  961500UL,
 1042000UL, 1087000UL, 1136000UL, 1220000UL, 1389000UL, 1429000UL, 1515000UL, 1613000UL,
 1667000UL, 1724000UL, 1887000UL, 1923000UL, 2174000UL, 2381000UL, 2441000UL, 2500000UL,
 2625000UL, 2778000UL, 2841000UL, 3155000UL, 3401000UL, 3460000UL, 3731000UL, 3846000UL,
 4065000UL, 4292000UL, 4444000UL, 4545000UL, 4854000UL, 4950000UL, 5000000UL, 5376000UL,
 5495000UL, 5882000UL, 6173000UL, 6494000UL, 6944000UL, 7246000UL, 8163000UL, 9400000UL,
};


void CLOCK__vSetDCOFrequency(uint32_t u32FrequencyHz, CLOCK_nRESISTOR enResistorSelect)
{
    uint8_t u8CurrentIndex = 0UL;
    uint8_t u8Codification = 0U;
    const uint32_t* pu32LUTPointerFreq = (uint32_t*) 0U;
    const uint8_t* pu8LUTPointerCod = (uint8_t*) 0U;

    if(CLOCK_enRESISTOR_INTERNAL == enResistorSelect)
    {
        pu32LUTPointerFreq = CLOCK_u32FrequencyLUT_Internal;
        pu8LUTPointerCod = CLOCK_u8CodificationLUT_Internal;
    }
    else
    {
        pu32LUTPointerFreq = CLOCK_u32FrequencyLUT_External;
        pu8LUTPointerCod = CLOCK_u8CodificationLUT_External;
    }
    u8CurrentIndex = MCU__u16GetNearArrayIndex_32Bits(pu32LUTPointerFreq, u32FrequencyHz, CLOCK_MAXINDEX);

    if(CLOCK_MAXINDEX <= u8CurrentIndex)
    {
        u8CurrentIndex = CLOCK_MAXINDEX;
        u8CurrentIndex -= 1U;
    }
    CLOCK_u8DCOIndex = u8CurrentIndex;
    u8Codification = pu8LUTPointerCod[u8CurrentIndex];
    CLOCK__vSetDCOFreqSelect(u8Codification & 0xFU);
    u8Codification >>= 4U;
    u8Codification &= 0xFU;
    CLOCK__vSetResistorSelect(u8Codification);
    CLOCK__vSetDCOResistorSelect(enResistorSelect);
}

uint32_t CLOCK__u32GetDCOFrequency(void)
{
    CLOCK_nRESISTOR enResistorSelectReg = CLOCK_enRESISTOR_INTERNAL;
    uint32_t u32FrequencyReg = 0UL;
    const uint32_t* pu32LUTPointerFreq = (uint32_t*) 0U;

    enResistorSelectReg = CLOCK__enGetDCOResistorSelect();
    if(CLOCK_enRESISTOR_INTERNAL == enResistorSelectReg)
    {
        pu32LUTPointerFreq = CLOCK_u32FrequencyLUT_Internal;
    }
    else
    {
        pu32LUTPointerFreq = CLOCK_u32FrequencyLUT_External;
    }

    u32FrequencyReg = *(pu32LUTPointerFreq + CLOCK_u8DCOIndex);
    return (u32FrequencyReg);
}

