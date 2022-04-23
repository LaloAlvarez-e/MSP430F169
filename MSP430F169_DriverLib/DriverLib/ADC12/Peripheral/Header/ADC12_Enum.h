/**
 *
 * @file ADC12_Enum.h
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
 * @verbatim 5 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 5 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef ADC12_PERIPHERAL_HEADER_ADC12_ENUM_H_
#define ADC12_PERIPHERAL_HEADER_ADC12_ENUM_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

typedef enum
{
    ADC12_enENABLE_DIS = 0U,
    ADC12_enENABLE_ENA = 1U,
}ADC12_nENABLE;

typedef enum
{
    ADC12_enSTATE_OFF = 0U,
    ADC12_enSTATE_ON = 1U,
}ADC12_nSTATE;


typedef enum
{
    ADC12_enBUSY_IDLE = 0U,
    ADC12_enBUSY_BUSY = 1U,
}ADC12_nBUSY;

typedef enum
{
    ADC12_enVREF_1_5V = 0U,
    ADC12_enVREF_2_5V = 1U,
}ADC12_nVREF;

typedef enum
{
    ADC12_enRATE_TRIGGER = 0U,
    ADC12_enRATE_CONTINUOS = 1U,
}ADC12_nRATE;

typedef enum
{
    ADC12_enSAMPLECYCLES_4 = 0U,
    ADC12_enSAMPLECYCLES_8 = 1U,
    ADC12_enSAMPLECYCLES_16 = 2U,
    ADC12_enSAMPLECYCLES_32 = 3U,
    ADC12_enSAMPLECYCLES_64 = 4U,
    ADC12_enSAMPLECYCLES_96 = 5U,
    ADC12_enSAMPLECYCLES_128 = 6U,
    ADC12_enSAMPLECYCLES_192 = 7U,
    ADC12_enSAMPLECYCLES_256 = 8U,
    ADC12_enSAMPLECYCLES_384 = 9U,
    ADC12_enSAMPLECYCLES_512 = 10U,
    ADC12_enSAMPLECYCLES_768 = 11U,
    ADC12_enSAMPLECYCLES_1024 = 12U,
}ADC12_nSAMPLECYCLES;

typedef enum
{
    ADC12_enSAMPLEMODE_TRIGGER = 0U,
    ADC12_enSAMPLEMODE_TIMER = 1U,
}ADC12_nSAMPLEMODE;

typedef enum
{
    ADC12_enINT_ENABLE_DIS = 0U,
    ADC12_enINT_ENABLE_ENA = 1U,
}ADC12_nINT_ENABLE;

typedef enum
{
    ADC12_enINT_STATUS_NOOCCUR = 0U,
    ADC12_enINT_STATUS_OCCUR = 1U,
}ADC12_nINT_STATUS;

typedef enum
{
    ADC12_enCH0 = 0U,
    ADC12_enCH1 = 1U,
    ADC12_enCH2 = 2U,
    ADC12_enCH3 = 3U,
    ADC12_enCH4 = 4U,
    ADC12_enCH5 = 5U,
    ADC12_enCH6 = 6U,
    ADC12_enCH7 = 7U,
    ADC12_enCH8 = 8U,
    ADC12_enCH9 = 9U,
    ADC12_enCH10 = 10U,
    ADC12_enCH11 = 11U,
    ADC12_enCH12 = 12U,
    ADC12_enCH13 = 13U,
    ADC12_enCH14 = 14U,
    ADC12_enCH15 = 15U,
    ADC12_enCH_MAX = 16U,
}ADC12_nCH;

typedef enum
{
    ADC12_enVREFP_VCC = 0U,
    ADC12_enVREFP_VREFP = 1U,
    ADC12_enVREFP_VeREFP = 2U,
}ADC12_nVREFP;

typedef enum
{
    ADC12_enVREFN_GND = 0U,
    ADC12_enVREFN_VREFN = 1U,
    ADC12_enVREFN_VeREFN = 1U,
}ADC12_nVREFN;


typedef enum
{
    ADC12_enINPUT_A0 = 0U,
    ADC12_enINPUT_A1 = 1U,
    ADC12_enINPUT_A2 = 2U,
    ADC12_enINPUT_A3 = 3U,
    ADC12_enINPUT_A4 = 4U,
    ADC12_enINPUT_A5 = 5U,
    ADC12_enINPUT_A6 = 6U,
    ADC12_enINPUT_A7 = 7U,
    ADC12_enINPUT_VeREFP = 8U,
    ADC12_enINPUT_VREFN = 9U,
    ADC12_enINPUT_VeREFN = 9U,
    ADC12_enINPUT_TEMP = 10U,
    ADC12_enINPUT_VCC_2 = 11U,
}ADC12_nINPUT;

typedef enum
{
    ADC12_enINTERRUPT_TOV = 0U,
    ADC12_enINTERRUPT_OV = 1U,
    ADC12_enINTERRUPT_MAX = 2U,
}ADC12_nINTERRUPT;

typedef enum
{
    ADC12_enTRIGGER_SW = 0U,
    ADC12_enTRIGGER_TACCR1 = 1U,
    ADC12_enTRIGGER_TBCCR0 = 2U,
    ADC12_enTRIGGER_TBCRR1 = 3U,
}ADC12_nTRIGGER;

typedef enum
{
    ADC12_enEDGE_RISING = 0U,
    ADC12_enEDGE_FALLING = 1U,
}ADC12_nEDGE;

typedef enum
{
    ADC12_enMODE_SINGLE = 0U,
    ADC12_enMODE_SEQUENCE = 1U,
    ADC12_enMODE_REPEAT_SINGLE = 2U,
    ADC12_enMODE_REPEAT_SEQUENCE = 3U,
    ADC12_enMODE_MAX = 4U,
}ADC12_nMODE;

typedef enum
{
    ADC12_enCLOCK_ADC12OSC = 0U,
    ADC12_enCLOCK_ACLK = 1U,
    ADC12_enCLOCK_MCLK = 2U,
    ADC12_enCLOCK_SMCLK = 3U,
}ADC12_nCLOCK;

typedef enum
{
    ADC12_enCLOCKDIV_1 = 0U,
    ADC12_enCLOCKDIV_2 = 1U,
    ADC12_enCLOCKDIV_3 = 2U,
    ADC12_enCLOCKDIV_4 = 3U,
    ADC12_enCLOCKDIV_5 = 4U,
    ADC12_enCLOCKDIV_6 = 5U,
    ADC12_enCLOCKDIV_7 = 6U,
    ADC12_enCLOCKDIV_8 = 7U,
}ADC12_nCLOCKDIV;


typedef MCU_Register16Bits_t ADC12_Register16Bits_t;
typedef MCU_Register8Bits_t ADC12_Register8Bits_t;

typedef struct
{
    ADC12_nCH enConversionStartChannel;
    ADC12_nRATE enConversionRate;
    ADC12_nMODE enConversionMode;
    ADC12_nTRIGGER enConversionTrigger;
    ADC12_nEDGE enConversionTriggerEdge;
    ADC12_nSAMPLEMODE enSamplingMode;
    ADC12_nSAMPLECYCLES enSamplingCyclesLow;
    ADC12_nSAMPLECYCLES enSamplingCyclesHigh;
    ADC12_nCLOCK enClockSource;
    ADC12_nCLOCKDIV enClockDivider;
}ADC12_Config_t;

typedef struct
{
    ADC12_nCH enConversionStartChannel;
    ADC12_nRATE enConversionRate;
    ADC12_nMODE enConversionMode;
    ADC12_nTRIGGER enConversionTrigger;
    ADC12_nEDGE enConversionTriggerEdge;
    ADC12_nSAMPLEMODE enSamplingMode;
    ADC12_nSAMPLECYCLES enSamplingCyclesLow;
    ADC12_nSAMPLECYCLES enSamplingCyclesHigh;
    ADC12_nCLOCK enClockSource;
    ADC12_nCLOCKDIV enClockDivider;
    ADC12_nINT_ENABLE enOVInterruptEnable;
    ADC12_nINT_ENABLE enTOVInterruptEnable;
}ADC12_ConfigExt_t;


typedef struct
{
    ADC12_nENABLE enEndOfSequence;
    ADC12_nVREFP enVoltageRefPositive;
    ADC12_nVREFN enVoltageRefNegative;
    ADC12_nINPUT enInputConversion;
}ADC12_CH_Config_t;

typedef struct
{
    ADC12_nENABLE enEndOfSequence;
    ADC12_nVREFP enVoltageRefPositive;
    ADC12_nVREFN enVoltageRefNegative;
    ADC12_nINPUT enInputConversion;
    ADC12_nINT_ENABLE enInterruptEnable;
    ADC12_nINT_STATUS enInterruptStatus;
}ADC12_CH_ConfigExt_t;

#endif /* ADC12_PERIPHERAL_HEADER_ADC12_ENUM_H_ */
