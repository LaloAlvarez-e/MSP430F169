/**
 *
 * @file GPIO_Enum.h
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

#ifndef GPIO_PERIPHERAL_HEADER_GPIO_ENUM_H_
#define GPIO_PERIPHERAL_HEADER_GPIO_ENUM_H_

#include "MCU/Header/MCU_Common.h"

typedef enum
{
    GPIO_enPORT1 = 0U,
    GPIO_enPORT2 = 1U,
    GPIO_enPORT3 = 2U,
    GPIO_enPORT4 = 3U,
    GPIO_enPORT5 = 4U,
    GPIO_enPORT6 = 5U,
    GPIO_enPORT_MAX = 6U,
}GPIO_nPORT;

typedef enum
{
    GPIO_enPIN_NUMBER0 = 0U,
    GPIO_enPIN_NUMBER1 = 1U,
    GPIO_enPIN_NUMBER2 = 2U,
    GPIO_enPIN_NUMBER3 = 3U,
    GPIO_enPIN_NUMBER4 = 4U,
    GPIO_enPIN_NUMBER5 = 5U,
    GPIO_enPIN_NUMBER6 = 6U,
    GPIO_enPIN_NUMBER7 = 7U,
    GPIO_enPIN_NUMBER_MAX = 8U,
}GPIO_nPIN_NUMBER;

typedef enum
{
    GPIO_enPIN_NONE = 0x0U,
    GPIO_enPIN0 = 0x1U,
    GPIO_enPIN1 = 0x2U,
    GPIO_enPIN2 = 0x4U,
    GPIO_enPIN3 = 0x8U,
    GPIO_enPIN4 = 0x10U,
    GPIO_enPIN5 = 0x20U,
    GPIO_enPIN6 = 0x40U,
    GPIO_enPIN7 = 0x80U,
    GPIO_enPIN_ALL = 0xFFU,
}GPIO_nPIN;

typedef enum
{
    GPIO_enDIR_INPUT = 0U,
    GPIO_enDIR_OUTPUT = 1U,
}GPIO_nDIR;

typedef enum
{
    GPIO_enSEL_IO = 0U,
    GPIO_enSEL_PERIPHERAL = 1U,
}GPIO_nSEL;

typedef enum
{
    GPIO_enLEVEL_LOW = 0U,
    GPIO_enLEVEL_HIGH = 1U,
}GPIO_nLEVEL;

typedef enum
{
    GPIO_enINT_ENABLE_DIS = 0U,
    GPIO_enINT_ENABLE_ENA = 1U,
}GPIO_nINT_ENABLE;

typedef enum
{
    GPIO_enINT_STATUS_NOOCCUR = 0U,
    GPIO_enINT_STATUS_OCCUR = 1U,
}GPIO_nINT_STATUS;

typedef enum
{
    GPIO_enINT_EDGE_RISING = 0U,
    GPIO_enINT_EDGE_FALLING = 1U,
}GPIO_nINT_EDGE;

#endif /* GPIO_PERIPHERAL_HEADER_GPIO_ENUM_H_ */