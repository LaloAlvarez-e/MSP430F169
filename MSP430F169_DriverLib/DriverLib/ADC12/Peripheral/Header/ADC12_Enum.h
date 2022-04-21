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
    ADC12_nINT_ENABLE_DIS = 0U,
    ADC12_nINT_ENABLE_ENA = 1U,
}ADC12_nINT_ENABLE;

typedef enum
{
    ADC12_nINT_STATUS_NOOCCUR = 0U,
    ADC12_nINT_STATUS_OCCUR = 1U,
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
    ADC12_enINTERRUPT_TOV = 0U,
    ADC12_enINTERRUPT_OV = 1U,
    ADC12_enINTERRUPT_MAX = 2U,
}ADC12_nINTERRUPT;

typedef enum
{
    ADC12_enCH_TRIGGER_SW = 0U,
    ADC12_enCH_TRIGGER_TACCR2 = 1U,
    ADC12_enCH_TRIGGER_TBCCR2 = 2U,
    ADC12_enCH_TRIGGER_USART0_RX = 3U,
    ADC12_enCH_TRIGGER_MAX = 4U,
}ADC12_nCH_TRIGGER;

typedef enum
{
    ADC12_enCH_MODE_SINGLE = 0U,
    ADC12_enCH_MODE_BLOCK = 1U,
    ADC12_enCH_MODE_BLOCK_BURST = 2U,
    ADC12_enCH_MODE_BLOCK_BURST1 = 3U,
    ADC12_enCH_MODE_MAX = 4U,
}ADC12_nCH_MODE;


typedef MCU_Register16Bits_t ADC12_Register16Bits_t;
typedef MCU_Register8Bits_t ADC12_Register8Bits_t;

typedef struct
{
    ADC12_nENABLE enNmiStop;
    ADC12_nPRIORITY enPriorityMode;
    ADC12_nFETCH enFetchMode;
}ADC12_Config_t;

typedef struct
{
    uint16_t u16TranferSize;
    uint16_t u16SourceAddress;
    uint16_t u16DestAddress;
    ADC12_nCH_TRIGGER enTrigger;
    ADC12_nCH_MODE enTransferMode;
    ADC12_nCH_INCMODE enSourceIncMode;
    ADC12_nCH_INCMODE enDestIncMode;
    ADC12_nCH_DATASIZE enSourceDataSize;
    ADC12_nCH_DATASIZE enDestDataSize;
    ADC12_nCH_SENSE enSense;
    ADC12_nCH_ENABLE enEnable;
    ADC12_nCH_ABORT enAbort;
}ADC12_CH_Config_t;

typedef struct
{
    uint16_t u16TranferSize;
    uint16_t u16SourceAddress;
    uint16_t u16DestAddress;
    ADC12_nCH_TRIGGER enTrigger;
    ADC12_nCH_MODE enTransferMode;
    ADC12_nCH_INCMODE enSourceIncMode;
    ADC12_nCH_INCMODE enDestIncMode;
    ADC12_nCH_DATASIZE enSourceDataSize;
    ADC12_nCH_DATASIZE enDestDataSize;
    ADC12_nCH_SENSE enSense;
    ADC12_nCH_ENABLE enEnable;
    ADC12_nCH_ABORT enAbort;
    ADC12_nINT_ENABLE enInterruptEnable;
    ADC12_nINT_STATUS enInterruptStatus;
}ADC12_CH_ConfigExt_t;

#endif /* ADC12_PERIPHERAL_HEADER_ADC12_ENUM_H_ */
