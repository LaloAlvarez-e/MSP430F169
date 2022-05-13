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
    DAC12_enMODE_OFF_OFF = 0U,
    DAC12_enMODE_OFF_0V = 1U,
    DAC12_enMODE_LOW_LOW = 2U,
    DAC12_enMODE_LOW_MEDIUM = 3U,
    DAC12_enMODE_LOW_HIGH = 4U,
    DAC12_enMODE_MEDIUM_MEDIUM = 5U,
    DAC12_enMODE_MEDIUM_HIGH = 6U,
    DAC12_enMODE_HIGH_HIGH = 7U,
}DAC12_nMODE;

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
    DAC12_enCH_MAX = 2U,
}DAC12_nCH;

typedef enum
{
    DAC12_enVREF_VREFP = 0U,
    DAC12_enVREF_VeREFP = 1U,
}DAC12_nVREF;

typedef enum
{
    DAC12_enRESOLUTION_12BITS = 0U,
    DAC12_enRESOLUTION_8BITS = 1U,
}DAC12_nRESOLUTION;

typedef enum
{
    DAC12_enFORMAT_UNSIGNED = 0U,
    DAC12_enFORMAT_SIGNED = 1U,
}DAC12_nFORMAT;

typedef enum
{
    DAC12_enAMPLIFIER_3x = 0U,
    DAC12_enAMPLIFIER_1x = 1U,
}DAC12_nAMPLIFIER;

typedef enum
{
    DAC12_enTRIGGER_IMMEDIATE = 0U,
    DAC12_enTRIGGER_GROUPED = 1U,
    DAC12_enTRIGGER_TACCR1 = 2U,
    DAC12_enTRIGGER_TBCRR2 = 3U,
}DAC12_nTRIGGER;


typedef MCU_Register16Bits_t DAC12_Register_t;

typedef struct
{
    DAC12_nENABLE enGroupMode;
    DAC12_nFORMAT enDataFormat;
    DAC12_nMODE enMode;
    DAC12_nAMPLIFIER enAmplifier;
    DAC12_nTRIGGER enTrigger;
    DAC12_nRESOLUTION enResolution;
    DAC12_nVREF enVoltageReference;
}DAC12_CH_Config_t;

typedef struct
{
    DAC12_nENABLE enGroupMode;
    DAC12_nFORMAT enDataFormat;
    DAC12_nMODE enMode;
    DAC12_nAMPLIFIER enAmplifier;
    DAC12_nTRIGGER enTrigger;
    DAC12_nRESOLUTION enResolution;
    DAC12_nVREF enVoltageReference;
    DAC12_nINT_ENABLE enInterruptEnable;
    DAC12_nINT_STATUS enInterruptStatus;
}DAC12_CH_ConfigExt_t;

#endif /* DAC12_PERIPHERAL_HEADER_DAC12_ENUM_H_ */
