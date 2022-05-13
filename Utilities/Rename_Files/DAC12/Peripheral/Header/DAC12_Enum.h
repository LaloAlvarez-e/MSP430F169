/**
 *
 * @file DAC12_Enum.h
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

#ifndef DAC12_PERIPHERAL_HEADER_DAC12_ENUM_H_
#define DAC12_PERIPHERAL_HEADER_DAC12_ENUM_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

typedef enum
{
    DAC12_enENABLE_DIS = 0U,
    DAC12_enENABLE_ENA = 1U,
}DAC12_nENABLE;

typedef enum
{
    DAC12_enSTATE_OFF = 0U,
    DAC12_enSTATE_ON = 1U,
}DAC12_nSTATE;


typedef enum
{
    DAC12_enBUSY_IDLE = 0U,
    DAC12_enBUSY_BUSY = 1U,
}DAC12_nBUSY;

typedef enum
{
    DAC12_enVREF_1_5V = 0U,
    DAC12_enVREF_2_5V = 1U,
}DAC12_nVREF;

typedef enum
{
    DAC12_enRATE_TRIGGER = 0U,
    DAC12_enRATE_CONTINUOS = 1U,
}DAC12_nRATE;

typedef enum
{
    DAC12_enSAMPLECYCLES_4 = 0U,
    DAC12_enSAMPLECYCLES_8 = 1U,
    DAC12_enSAMPLECYCLES_16 = 2U,
    DAC12_enSAMPLECYCLES_32 = 3U,
    DAC12_enSAMPLECYCLES_64 = 4U,
    DAC12_enSAMPLECYCLES_96 = 5U,
    DAC12_enSAMPLECYCLES_128 = 6U,
    DAC12_enSAMPLECYCLES_192 = 7U,
    DAC12_enSAMPLECYCLES_256 = 8U,
    DAC12_enSAMPLECYCLES_384 = 9U,
    DAC12_enSAMPLECYCLES_512 = 10U,
    DAC12_enSAMPLECYCLES_768 = 11U,
    DAC12_enSAMPLECYCLES_1024 = 12U,
}DAC12_nSAMPLECYCLES;

typedef enum
{
    DAC12_enSAMPLEMODE_TRIGGER = 0U,
    DAC12_enSAMPLEMODE_TIMER = 1U,
}DAC12_nSAMPLEMODE;

typedef enum
{
    DAC12_enINT_ENABLE_DIS = 0U,
    DAC12_enINT_ENABLE_ENA = 1U,
}DAC12_nINT_ENABLE;

typedef enum
{
    DAC12_enINT_STATUS_NOOCCUR = 0U,
    DAC12_enINT_STATUS_OCCUR = 1U,
}DAC12_nINT_STATUS;

typedef enum
{
    DAC12_enCH0 = 0U,
    DAC12_enCH1 = 1U,
    DAC12_enCH2 = 2U,
    DAC12_enCH3 = 3U,
    DAC12_enCH4 = 4U,
    DAC12_enCH5 = 5U,
    DAC12_enCH6 = 6U,
    DAC12_enCH7 = 7U,
    DAC12_enCH8 = 8U,
    DAC12_enCH9 = 9U,
    DAC12_enCH10 = 10U,
    DAC12_enCH11 = 11U,
    DAC12_enCH12 = 12U,
    DAC12_enCH13 = 13U,
    DAC12_enCH14 = 14U,
    DAC12_enCH15 = 15U,
    DAC12_enCH_MAX = 16U,
}DAC12_nCH;

typedef enum
{
    DAC12_enVREFP_VCC = 0U,
    DAC12_enVREFP_VREFP = 1U,
    DAC12_enVREFP_VeREFP = 2U,
}DAC12_nVREFP;

typedef enum
{
    DAC12_enVREFN_GND = 0U,
    DAC12_enVREFN_VREFN = 1U,
    DAC12_enVREFN_VeREFN = 1U,
}DAC12_nVREFN;


typedef enum
{
    DAC12_enINPUT_A0 = 0U,
    DAC12_enINPUT_A1 = 1U,
    DAC12_enINPUT_A2 = 2U,
    DAC12_enINPUT_A3 = 3U,
    DAC12_enINPUT_A4 = 4U,
    DAC12_enINPUT_A5 = 5U,
    DAC12_enINPUT_A6 = 6U,
    DAC12_enINPUT_A7 = 7U,
    DAC12_enINPUT_VeREFP = 8U,
    DAC12_enINPUT_VREFN = 9U,
    DAC12_enINPUT_VeREFN = 9U,
    DAC12_enINPUT_TEMP = 10U,
    DAC12_enINPUT_VCC_2 = 11U,
}DAC12_nINPUT;

typedef enum
{
    DAC12_enINTERRUPT_TOV = 0U,
    DAC12_enINTERRUPT_OV = 1U,
    DAC12_enINTERRUPT_MAX = 2U,
}DAC12_nINTERRUPT;

typedef enum
{
    DAC12_enTRIGGER_SW = 0U,
    DAC12_enTRIGGER_TACCR1 = 1U,
    DAC12_enTRIGGER_TBCCR0 = 2U,
    DAC12_enTRIGGER_TBCRR1 = 3U,
}DAC12_nTRIGGER;

typedef enum
{
    DAC12_enEDGE_RISING = 0U,
    DAC12_enEDGE_FALLING = 1U,
}DAC12_nEDGE;

typedef enum
{
    DAC12_enMODE_SINGLE = 0U,
    DAC12_enMODE_SEQUENCE = 1U,
    DAC12_enMODE_REPEAT_SINGLE = 2U,
    DAC12_enMODE_REPEAT_SEQUENCE = 3U,
    DAC12_enMODE_MAX = 4U,
}DAC12_nMODE;

typedef enum
{
    DAC12_enCLOCK_DAC12OSC = 0U,
    DAC12_enCLOCK_ACLK = 1U,
    DAC12_enCLOCK_MCLK = 2U,
    DAC12_enCLOCK_SMCLK = 3U,
}DAC12_nCLOCK;

typedef enum
{
    DAC12_enCLOCKDIV_1 = 0U,
    DAC12_enCLOCKDIV_2 = 1U,
    DAC12_enCLOCKDIV_3 = 2U,
    DAC12_enCLOCKDIV_4 = 3U,
    DAC12_enCLOCKDIV_5 = 4U,
    DAC12_enCLOCKDIV_6 = 5U,
    DAC12_enCLOCKDIV_7 = 6U,
    DAC12_enCLOCKDIV_8 = 7U,
}DAC12_nCLOCKDIV;


typedef MCU_Register16Bits_t DAC12_Register16Bits_t;
typedef MCU_Register8Bits_t DAC12_Register8Bits_t;

typedef struct
{
    DAC12_nCH enConversionStartChannel;
    DAC12_nRATE enConversionRate;
    DAC12_nMODE enConversionMode;
    DAC12_nTRIGGER enConversionTrigger;
    DAC12_nEDGE enConversionTriggerEdge;
    DAC12_nSAMPLEMODE enSamplingMode;
    DAC12_nSAMPLECYCLES enSamplingCyclesLow;
    DAC12_nSAMPLECYCLES enSamplingCyclesHigh;
    DAC12_nCLOCK enClockSource;
    DAC12_nCLOCKDIV enClockDivider;
}DAC12_Config_t;

typedef struct
{
    DAC12_nCH enConversionStartChannel;
    DAC12_nRATE enConversionRate;
    DAC12_nMODE enConversionMode;
    DAC12_nTRIGGER enConversionTrigger;
    DAC12_nEDGE enConversionTriggerEdge;
    DAC12_nSAMPLEMODE enSamplingMode;
    DAC12_nSAMPLECYCLES enSamplingCyclesLow;
    DAC12_nSAMPLECYCLES enSamplingCyclesHigh;
    DAC12_nCLOCK enClockSource;
    DAC12_nCLOCKDIV enClockDivider;
    DAC12_nINT_ENABLE enOVInterruptEnable;
    DAC12_nINT_ENABLE enTOVInterruptEnable;
}DAC12_ConfigExt_t;


typedef struct
{
    DAC12_nENABLE enEndOfSequence;
    DAC12_nVREFP enVoltageRefPositive;
    DAC12_nVREFN enVoltageRefNegative;
    DAC12_nINPUT enInputConversion;
}DAC12_CH_Config_t;

typedef struct
{
    DAC12_nENABLE enEndOfSequence;
    DAC12_nVREFP enVoltageRefPositive;
    DAC12_nVREFN enVoltageRefNegative;
    DAC12_nINPUT enInputConversion;
    DAC12_nINT_ENABLE enInterruptEnable;
    DAC12_nINT_STATUS enInterruptStatus;
}DAC12_CH_ConfigExt_t;

#endif /* DAC12_PERIPHERAL_HEADER_DAC12_ENUM_H_ */
