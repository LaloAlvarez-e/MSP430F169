/**
 *
 * @file TIMERB_Enum.h
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

#ifndef TIMERB_PERIPHERAL_HEADER_TIMERB_ENUM_H_
#define TIMERB_PERIPHERAL_HEADER_TIMERB_ENUM_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

typedef enum
{
    TIMERB_enCC0 = 0U,
    TIMERB_enCC1 = 1U,
    TIMERB_enCC2 = 2U,
    TIMERB_enCC3 = 3U,
    TIMERB_enCC4 = 4U,
    TIMERB_enCC5 = 5U,
    TIMERB_enCC6 = 6U,
    TIMERB_enCC_MAX = 7U,
}TIMERB_nCC;

typedef enum
{
    TIMERB_enCC_MODE_COMPARE = 0U,
    TIMERB_enCC_MODE_CAPTURE = 1U,
    TIMERB_enCC_MODE_MAX = 2U,
}TIMERB_nCC_MODE;

typedef enum
{
    TIMERB_enCC_CAPTUREMODE_NONE = 0U,
    TIMERB_enCC_CAPTUREMODE_RISING = 1U,
    TIMERB_enCC_CAPTUREMODE_FALLING = 2U,
    TIMERB_enCC_CAPTUREMODE_BOTH = 3U,
}TIMERB_nCC_CAPTUREMODE;

typedef enum
{
    TIMERB_enCC_COMPAREMODE_OUT = 0U,
    TIMERB_enCC_COMPAREMODE_SET = 1U,
    TIMERB_enCC_COMPAREMODE_TOGGLE_RESET = 2U,
    TIMERB_enCC_COMPAREMODE_SET_RESET = 3U,
    TIMERB_enCC_COMPAREMODE_TOGGLE = 4U,
    TIMERB_enCC_COMPAREMODE_RESET = 5U,
    TIMERB_enCC_COMPAREMODE_TOGGLE_SET = 6U,
    TIMERB_enCC_COMPAREMODE_RESET_SET = 7U,
}TIMERB_nCC_COMPAREMODE;

typedef enum
{
    TIMERB_enCC_COMPARELOAD_IMMEDIATE = 0U,
    TIMERB_enCC_COMPARELOAD_OV = 1U,
    TIMERB_enCC_COMPARELOAD_OV_CCR0 = 2U,
    TIMERB_enCC_COMPARELOAD_CCRx = 3U,
}TIMERB_nCC_COMPARELOAD;


typedef enum
{
    TIMERB_enCC_CAPTUREINPUT_A = 0U,
    TIMERB_enCC_CAPTUREINPUT_B = 1U,
    TIMERB_enCC_CAPTUREINPUT_GND = 2U,
    TIMERB_enCC_CAPTUREINPUT_VCC = 3U,
}TIMERB_nCC_CAPTUREINPUT;

typedef enum
{
    TIMERB_enCC_CAPTURESYNC_ASYNC = 0U,
    TIMERB_enCC_CAPTURESYNC_SYNC = 1U,
}TIMERB_nCC_CAPTURESYNC;

typedef enum
{
    TIMERB_enCC_STATE_LOW = 0U,
    TIMERB_enCC_STATE_HIGH = 1U,
}TIMERB_nCC_STATE;


typedef enum
{
    TIMERB_enMODE_STOP = 0U,
    TIMERB_enMODE_UP = 1U,
    TIMERB_enMODE_CONTINUOS = 2U,
    TIMERB_enMODE_UP_DOWN = 3U,
    TIMERB_enMODE_MAX = 4U,
}TIMERB_nMODE;

typedef enum
{
    TIMERB_enRESOLUTION_16BITS = 0U,
    TIMERB_enRESOLUTION_12BITS = 1U,
    TIMERB_enRESOLUTION_10BITS = 2U,
    TIMERB_enRESOLUTION_8BITS = 3U,
    TIMERB_enRESOLUTION_MAX = 4U,
}TIMERB_nRESOLUTION;

typedef enum
{
    TIMERB_enGROUPLOAD_INDEPENDENT = 0U,
    TIMERB_enGROUPLOAD_PAIRS = 1U,
    TIMERB_enGROUPLOAD_THIRDS = 2U,
    TIMERB_enGROUPLOAD_ALL = 3U,
    TIMERB_enGROUPLOAD_MAX = 4U,
}TIMERB_nGROUPLOAD;

typedef enum
{
    TIMERB_enCLOCK_TBCLK = 0U,
    TIMERB_enCLOCK_ACLK = 1U,
    TIMERB_enCLOCK_SMCLK = 2U,
    TIMERB_enCLOCK_nTBCLK = 3U,
    TIMERB_enCLOCK_MAX = 4U,
}TIMERB_nCLOCK;

typedef enum
{
    TIMERB_enCLOCK_DIV_1 = 0U,
    TIMERB_enCLOCK_DIV_2 = 1U,
    TIMERB_enCLOCK_DIV_4 = 2U,
    TIMERB_enCLOCK_DIV_8 = 3U,
    TIMERB_enCLOCK_DIV_MAX = 4U,
}TIMERB_nCLOCK_DIV;

typedef enum
{
    TIMERB_enINT_ENABLE_DIS = 0U,
    TIMERB_enINT_ENABLE_ENA = 1U,
}TIMERB_nINT_ENABLE;

typedef enum
{
    TIMERB_enINT_STATUS_NOOCCUR = 0U,
    TIMERB_enINT_STATUS_OCCUR = 1U,
}TIMERB_nINT_STATUS;

typedef MCU_Register16Bits_t TIMERB_Register_t;

typedef struct
{
    TIMERB_nCLOCK enClockSource;
    TIMERB_nCLOCK_DIV enClockDivider;
    TIMERB_nMODE enOperationMode;
    TIMERB_nRESOLUTION enResolution;
    TIMERB_nGROUPLOAD enGroupLoad;
}TIMERB_Config_t;

typedef struct
{
    TIMERB_nCLOCK enClockSource;
    TIMERB_nCLOCK_DIV enClockDivider;
    TIMERB_nMODE enOperationMode;
    TIMERB_nINT_ENABLE enInterruptEnable;
    TIMERB_nINT_STATUS enInterruptStatus;
    TIMERB_nRESOLUTION enResolution;
    TIMERB_nGROUPLOAD enGroupLoad;
}TIMERB_ConfigExt_t;


typedef struct
{
    TIMERB_nCC_CAPTUREMODE enCaptureMode;
    TIMERB_nCC_CAPTURESYNC enSyncMode;
    TIMERB_nCC_CAPTUREINPUT enCaptureInput;
}TIMERB_Capture_Config_t;

typedef struct
{
    TIMERB_nCC_CAPTUREMODE enCaptureMode;
    TIMERB_nCC_CAPTURESYNC enSyncMode;
    TIMERB_nCC_CAPTUREINPUT enCaptureInput;
    TIMERB_nINT_ENABLE enInterruptEnable;
    TIMERB_nINT_STATUS enInterruptStatus;
}TIMERB_Capture_ConfigExt_t;


typedef struct
{
    uint16_t u16CompareValue;
    TIMERB_nCC_COMPAREMODE enCompareMode;
    TIMERB_nCC_STATE enCompareState;
    TIMERB_nCC_COMPARELOAD enCompareLoadMode;
}TIMERB_Compare_Config_t;

typedef struct
{
    uint16_t u16CompareValue;
    TIMERB_nCC_COMPAREMODE enCompareMode;
    TIMERB_nCC_STATE enCompareState;
    TIMERB_nINT_ENABLE enInterruptEnable;
    TIMERB_nINT_STATUS enInterruptStatus;
    TIMERB_nCC_COMPARELOAD enCompareLoadMode;
}TIMERB_Compare_ConfigExt_t;

#endif /* TIMERB_PERIPHERAL_HEADER_TIMERB_ENUM_H_ */
