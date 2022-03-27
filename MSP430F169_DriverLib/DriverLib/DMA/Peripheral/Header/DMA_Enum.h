/**
 *
 * @file DMA_Enum.h
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

#ifndef DMA_PERIPHERAL_HEADER_DMA_ENUM_H_
#define DMA_PERIPHERAL_HEADER_DMA_ENUM_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

typedef enum
{
    DMA_enFETCH_IMMEDIATE = 0U,
    DMA_enFETCH_NEXT = 1U,
}DMA_nFETCH;

typedef enum
{
    DMA_enPRIORITY_STATIC = 0U,
    DMA_enPRIORITY_ROUND_ROBIN = 1U,
}DMA_nPRIORITY;

typedef enum
{
    DMA_enENABLE_DIS = 0U,
    DMA_enENABLE_ENA = 1U,
}DMA_nENABLE;

typedef enum
{
    DMA_enCH0 = 0U,
    DMA_enCH1 = 1U,
    DMA_enCH2 = 2U,
    DMA_enCH_MAX = 3U,
}DMA_nCH;

typedef enum
{
    DMA_enCH_TRIGGER_SW = 0U,
    DMA_enCH_TRIGGER_TACCR2 = 1U,
    DMA_enCH_TRIGGER_TBCCR2 = 2U,
    DMA_enCH_TRIGGER_USART0_RX = 3U,
    DMA_enCH_TRIGGER_USART0_TX = 4U,
    DMA_enCH_TRIGGER_DAC12_0 = 5U,
    DMA_enCH_TRIGGER_ADC12x = 6U,
    DMA_enCH_TRIGGER_TACCR0 = 7U,
    DMA_enCH_TRIGGER_TBCCR0 = 8U,
    DMA_enCH_TRIGGER_USART1_RX = 9U,
    DMA_enCH_TRIGGER_USART1_TX = 10U,
    DMA_enCH_TRIGGER_MULTIPLIER = 11U,
    DMA_enCH_TRIGGER_NO_TRIGGER0 = 12U,
    DMA_enCH_TRIGGER_NO_TRIGGER1 = 13U,
    DMA_enCH_TRIGGER_DMA = 14U,
    DMA_enCH_TRIGGER_EXTERNAL = 15U,
    DMA_enCH_TRIGGER_MAX = 16U,
}DMA_nCH_TRIGGER;

typedef enum
{
    DMA_enCH_MODE_SINGLE = 0U,
    DMA_enCH_MODE_BLOCK = 1U,
    DMA_enCH_MODE_BLOCK_BURST = 2U,
    DMA_enCH_MODE_BLOCK_BURST1 = 3U,
    DMA_enCH_MODE_REPEAT_SINGLE = 4U,
    DMA_enCH_MODE_REPEAT_BLOCK = 5U,
    DMA_enCH_MODE_REPEAT_BLOCK_BURST = 6U,
    DMA_enCH_MODE_REPEAT_BLOCK_BURST1 = 7U,
    DMA_enCH_MODE_MAX = 8U,
}DMA_nCH_MODE;

typedef enum
{
    DMA_enCH_INCMODE_UNCHANGED = 0U,
    DMA_enCH_INCMODE_UNCHANGED1 = 1U,
    DMA_enCH_INCMODE_DECREMENT = 2U,
    DMA_enCH_INCMODE_INCREMENT = 3U,
    DMA_enCH_INCMODE_MAX = 4U,
}DMA_nCH_INCMODE;

typedef enum
{
    DMA_enCH_WORDSIZE_WORD = 0U,
    DMA_enCH_WORDSIZE_BYTE = 1U,
    DMA_enCH_WORDSIZE_MAX = 2U,
}DMA_nCH_WORDSIZE;

typedef enum
{
    DMA_enCH_TRIGGERMODE_EDGE = 0U,
    DMA_enCH_TRIGGERMODE_LEVEL = 1U,
    DMA_enCH_TRIGGERMODE_MAX = 2U,
}DMA_nCH_TRIGGERMODE;

typedef enum
{
    DMA_enCH_ENABLE_DIS = 0U,
    DMA_enCH_ENABLE_ENA = 1U,
}DMA_nCH_ENABLE;

typedef enum
{
    DMA_enCH_REQ_NA = 0U,
    DMA_enCH_REQ_START = 1U,
}DMA_nCH_REQ;

typedef enum
{
    DMA_enCH_ABORT_NA = 0U,
    DMA_enCH_ABORT_ABORTED = 1U,
}DMA_nCH_ABORT;

typedef enum
{
    DMA_enCH_INT_ENABLE_DIS = 0U,
    DMA_enCH_INT_ENABLE_ENA = 1U,
}DMA_nCH_INT_ENABLE;

typedef enum
{
    DMA_enCH_INT_STATUS_NOOCCUR = 0U,
    DMA_enCH_INT_STATUS_OCCUR = 1U,
}DMA_nCH_INT_STATUS;

typedef MCU_Register16Bits_t DMA_Register_t;

typedef struct
{
    DMA_nENABLE enNmiStop;
    DMA_nPRIORITY enPriorityMode;
    DMA_nFETCH enFetchMode;
}DMA_Config_t;

#endif /* DMA_PERIPHERAL_HEADER_DMA_ENUM_H_ */
