/**
 *
 * @file TIMERA_Enum.h
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

#ifndef TIMERA_PERIPHERAL_HEADER_TIMERA_ENUM_H_
#define TIMERA_PERIPHERAL_HEADER_TIMERA_ENUM_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

typedef enum
{
    TIMERA_enCC0 = 0U,
    TIMERA_enCC1 = 1U,
    TIMERA_enCC2 = 2U,
    TIMERA_enCC_MAX = 3U,
}TIMERA_nCC;

typedef enum
{
    TIMERA_enCC_MODE_COMPARE = 0U,
    TIMERA_enCC_MODE_CAPTURE = 1U,
    TIMERA_enCC_MODE_MAX = 2U,
}TIMERA_nCC_MODE;

typedef enum
{
    TIMERA_enCC_CAPTUREMODE_NONE = 0U,
    TIMERA_enCC_CAPTUREMODE_RISING = 1U,
    TIMERA_enCC_CAPTUREMODE_FALLING = 2U,
    TIMERA_enCC_CAPTUREMODE_BOTH = 3U,
}TIMERA_nCC_CAPTUREMODE;

typedef enum
{
    TIMERA_enCC_COMPAREMODE_OUT = 0U,
    TIMERA_enCC_COMPAREMODE_SET = 1U,
    TIMERA_enCC_COMPAREMODE_TOGGLE_RESET = 2U,
    TIMERA_enCC_COMPAREMODE_SET_RESET = 3U,
    TIMERA_enCC_COMPAREMODE_TOGGLE = 4U,
    TIMERA_enCC_COMPAREMODE_RESET = 5U,
    TIMERA_enCC_COMPAREMODE_TOGGLE_SET = 6U,
    TIMERA_enCC_COMPAREMODE_RESET_SET = 7U,
}TIMERA_nCC_COMPAREMODE;

typedef enum
{
    TIMERA_enCC_CAPTUREINPUT_A = 0U,
    TIMERA_enCC_CAPTUREINPUT_B = 1U,
    TIMERA_enCC_CAPTUREINPUT_GND = 2U,
    TIMERA_enCC_CAPTUREINPUT_VCC = 3U,
}TIMERA_nCC_CAPTUREINPUT;

typedef enum
{
    TIMERA_enCC_CAPTURESYNC_ASYNC = 0U,
    TIMERA_enCC_CAPTURESYNC_SYNC = 1U,
}TIMERA_nCC_CAPTURESYNC;

typedef enum
{
    TIMERA_enCC_STATE_LOW = 0U,
    TIMERA_enCC_STATE_HIGH = 1U,
}TIMERA_nCC_STATE;


typedef enum
{
    TIMERA_enMODE_STOP = 0U,
    TIMERA_enMODE_UP = 1U,
    TIMERA_enMODE_CONTINUOS = 2U,
    TIMERA_enMODE_UP_DOWN = 3U,
    TIMERA_enMODE_MAX = 4U,
}TIMERA_nMODE;


typedef enum
{
    TIMERA_enCLOCK_TACLK = 0U,
    TIMERA_enCLOCK_ACLK = 1U,
    TIMERA_enCLOCK_SMCLK = 2U,
    TIMERA_enCLOCK_INCLK = 3U,
    TIMERA_enCLOCK_MAX = 4U,
}TIMERA_nCLOCK;

typedef enum
{
    TIMERA_enCLOCK_DIV_1 = 0U,
    TIMERA_enCLOCK_DIV_2 = 1U,
    TIMERA_enCLOCK_DIV_4 = 2U,
    TIMERA_enCLOCK_DIV_8 = 3U,
    TIMERA_enCLOCK_DIV_MAX = 4U,
}TIMERA_nCLOCK_DIV;

typedef enum
{
    TIMERA_enINT_ENABLE_DIS = 0U,
    TIMERA_enINT_ENABLE_ENA = 1U,
}TIMERA_nINT_ENABLE;

typedef enum
{
    TIMERA_enINT_STATUS_NOOCCUR = 0U,
    TIMERA_enINT_STATUS_OCCUR = 1U,
}TIMERA_nINT_STATUS;

typedef MCU_Register16Bits_t TIMERA_Register_t;

typedef struct
{
    TIMERA_nCLOCK enClockSource;
    TIMERA_nCLOCK_DIV enClockDivider;
    TIMERA_nMODE enOperationMode;
}TIMERA_Config_t;

typedef struct
{
    TIMERA_nCLOCK enClockSource;
    TIMERA_nCLOCK_DIV enClockDivider;
    TIMERA_nMODE enOperationMode;
    TIMERA_nINT_ENABLE enInterruptEnable;
    TIMERA_nINT_STATUS enInterruptStatus;
}TIMERA_ConfigExt_t;


typedef struct
{
    TIMERA_nCC_CAPTUREMODE enCaptureMode;
    TIMERA_nCC_CAPTURESYNC enSyncMode;
    TIMERA_nCC_CAPTUREINPUT enCaptureInput;
}TIMERA_Capture_Config_t;

typedef struct
{
    TIMERA_nCC_CAPTUREMODE enCaptureMode;
    TIMERA_nCC_CAPTURESYNC enSyncMode;
    TIMERA_nCC_CAPTUREINPUT enCaptureInput;
    TIMERA_nINT_ENABLE enInterruptEnable;
    TIMERA_nINT_STATUS enInterruptStatus;
}TIMERA_Capture_ConfigExt_t;


typedef struct
{
    uint16_t u16CompareValue;
    TIMERA_nCC_COMPAREMODE enCompareMode;
    TIMERA_nCC_STATE enCompareState;
}TIMERA_Compare_Config_t;

typedef struct
{
    uint16_t u16CompareValue;
    TIMERA_nCC_COMPAREMODE enCompareMode;
    TIMERA_nCC_STATE enCompareState;
    TIMERA_nINT_ENABLE enInterruptEnable;
    TIMERA_nINT_STATUS enInterruptStatus;
}TIMERA_Compare_ConfigExt_t;

#endif /* TIMERA_PERIPHERAL_HEADER_TIMERA_ENUM_H_ */
