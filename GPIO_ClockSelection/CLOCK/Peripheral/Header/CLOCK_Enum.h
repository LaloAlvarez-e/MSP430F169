/**
 *
 * @file CLOCK_Enum.h
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
 * @verbatim 12 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 12 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef CLOCK_PERIPHERAL_HEADER_CLOCK_ENUM_H_
#define CLOCK_PERIPHERAL_HEADER_CLOCK_ENUM_H_


typedef enum
{
    CLOCK_enSTATUS_OK = 0U,
    CLOCK_enSTATUS_ERROR = 1U,
}CLOCK_nSTATUS;

typedef enum
{
    CLOCK_enINT_ENABLE_DIS = 0U,
    CLOCK_enINT_ENABLE_ENA = 1U,
}CLOCK_nINT_ENABLE;

typedef enum
{
    CLOCK_enINT_STATUS_NOOCCUR = 0U,
    CLOCK_enINT_STATUS_OCCUR = 1U,
}CLOCK_nINT_STATUS;

typedef enum
{
    CLOCK_enSIGNAL_ACLK = 0U,
    CLOCK_enSIGNAL_SMCLK = 1U,
    CLOCK_enSIGNAL_MCLK = 2U,
}CLOCK_nSIGNAL;

typedef enum
{
    CLOCK_enSOURCE_LFXT1 = 0U,
    CLOCK_enSOURCE_XT2 = 1U,
    CLOCK_enSOURCE_DCO = 2U,
}CLOCK_nSOURCE;

typedef enum
{
    CLOCK_nDIV_1 = 0U,
    CLOCK_nDIV_2 = 1U,
    CLOCK_nDIV_4 = 2U,
    CLOCK_nDIV_8 = 3U,
}CLOCK_nDIV;

typedef enum
{
    CLOCK_enENABLE_ENA = 0U,
    CLOCK_enENABLE_DIS = 1U,
}CLOCK_nENABLE;

typedef enum
{
    CLOCK_enFREQMODE_LOW = 0U,
    CLOCK_enFREQMODE_HIGH = 1U,
}CLOCK_nFREQMODE;

#endif /* CLOCK_PERIPHERAL_HEADER_CLOCK_ENUM_H_ */
