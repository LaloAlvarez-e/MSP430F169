/**
 *
 * @file SVS_Enum.h
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

#ifndef DRIVERLIB_SVS_PERIPHERAL_HEADER_SVS_ENUM_H_
#define DRIVERLIB_SVS_PERIPHERAL_HEADER_SVS_ENUM_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

typedef enum
{
    SVS_enSTATUS_OK = 0U,
    SVS_enSTATUS_ERROR = 1U,
}SVS_nSTATUS;

typedef enum
{
    SVS_enTHRESHOLD_OFF = 0U,
    SVS_enTHRESHOLD_1_9V = 1U,
    SVS_enTHRESHOLD_2_1V = 2U,
    SVS_enTHRESHOLD_2_2V = 3U,
    SVS_enTHRESHOLD_2_3V = 4U,
    SVS_enTHRESHOLD_2_4V = 5U,
    SVS_enTHRESHOLD_2_5V = 6U,
    SVS_enTHRESHOLD_2_65V = 7U,
    SVS_enTHRESHOLD_2_8V = 8U,
    SVS_enTHRESHOLD_2_9V = 9U,
    SVS_enTHRESHOLD_3_05V = 10U,
    SVS_enTHRESHOLD_3_2V = 11U,
    SVS_enTHRESHOLD_3_35V = 12U,
    SVS_enTHRESHOLD_3_5V = 13U,
    SVS_enTHRESHOLD_3_7V = 14U,
    SVS_enTHRESHOLD_1_2V_EXT = 15U,
}SVS_nTHRESHOLD;

typedef enum
{
    SVS_enSTATE_OFF = 0U,
    SVS_enSTATE_ON = 1U,
}SVS_nSTATE;

typedef enum
{
    SVS_enLEVEL_LOW = 0U,
    SVS_enLEVEL_HIGH = 1U,
}SVS_nLEVEL;

typedef enum
{
    SVS_enFLAG_CLEAR = 0U,
    SVS_enFLAG_SET = 1U,
}SVS_nFLAG;

typedef MCU_Register8Bits_t SVS_Register_t;

#endif /* DRIVERLIB_SVS_PERIPHERAL_HEADER_SVS_ENUM_H_ */
