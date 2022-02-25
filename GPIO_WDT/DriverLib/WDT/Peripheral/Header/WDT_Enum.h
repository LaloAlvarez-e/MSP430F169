/**
 *
 * @file WDT_Enum.h
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

#ifndef DRIVERLIB_WDT_PERIPHERAL_HEADER_WDT_ENUM_H_
#define DRIVERLIB_WDT_PERIPHERAL_HEADER_WDT_ENUM_H_

typedef enum
{
    WDT_enSTATUS_OK = 0U,
    WDT_enSTATUS_ERROR = 1U,
}WDT_nSTATUS;

typedef enum
{
    WDT_enINT_ENABLE_DIS = 0U,
    WDT_enINT_ENABLE_ENA = 1U,
}WDT_nINT_ENABLE;

typedef enum
{
    WDT_enINT_STATUS_NOOCCUR = 0U,
    WDT_enINT_STATUS_OCCUR = 1U,
}WDT_nINT_STATUS;

typedef enum
{
    WDT_enENABLE_RUN = 0U,
    WDT_enENABLE_STOP = 1U,
}WDT_nENABLE;

typedef enum
{
    WDT_enMODE_WDT = 0U,
    WDT_enMODE_INTERVAL = 1U,
}WDT_nMODE;

typedef enum
{
    WDT_enCLOCK_SMCLK = 0U,
    WDT_enCLOCK_ACLK = 1U,
}WDT_nCLOCK;

typedef enum
{
    WDT_enPERIOD_32768 = 0U,
    WDT_enPERIOD_8192 = 1U,
    WDT_enPERIOD_512 = 2U,
    WDT_enPERIOD_64 = 3U,
}WDT_nPERIOD;


#endif /* DRIVERLIB_WDT_PERIPHERAL_HEADER_WDT_ENUM_H_ */
