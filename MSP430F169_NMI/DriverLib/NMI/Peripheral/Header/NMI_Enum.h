/**
 *
 * @file NMI_Enum.h
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
 * @verbatim 24 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 24 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_NMI_PERIPHERAL_HEADER_NMI_ENUM_H_
#define DRIVERLIB_NMI_PERIPHERAL_HEADER_NMI_ENUM_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

typedef enum
{
    NMI_enSTATUS_OK = 0U,
    NMI_enSTATUS_ERROR = 1U,
}NMI_nSTATUS;

typedef enum
{
    NMI_enINT_ENABLE_DIS = 0U,
    NMI_enINT_ENABLE_ENA = 1U,
}NMI_nINT_ENABLE;

typedef enum
{
    NMI_enINT_STATUS_NOOCCUR = 0U,
    NMI_enINT_STATUS_OCCUR = 1U,
}NMI_nINT_STATUS;

typedef enum
{
    NMI_enINT_EDGE_RISING = 0U,
    NMI_enINT_EDGE_FALLING = 1U,
}NMI_nINT_EDGE;

typedef enum
{
    NMI_enMODE_RESET = 0U,
    NMI_enMODE_NMI = 1U,
}NMI_nMODE;

typedef MCU_Register8Bits_t NMI_Register8Bits_t;
typedef MCU_Register16Bits_t NMI_Register16Bits_t;

#endif /* DRIVERLIB_NMI_PERIPHERAL_HEADER_NMI_ENUM_H_ */
