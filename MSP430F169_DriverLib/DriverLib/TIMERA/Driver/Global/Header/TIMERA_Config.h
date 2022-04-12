/**
 *
 * @file TIMERA_Config.h
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
 * @verbatim 27 mar. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 27 mar. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_TIMERA_DRIVER_HEADER_TIMERA_CONFIG_H_
#define DRIVERLIB_TIMERA_DRIVER_HEADER_TIMERA_CONFIG_H_

#include "DriverLib/TIMERA/Peripheral/Header/TIMERA_Enum.h"

void TIMERA__vSetConfig(TIMERA_Config_t* pstConfigArg);
void TIMERA__vGetConfig(TIMERA_Config_t* pstConfigArg);

void TIMERA__vSetConfigExt(TIMERA_ConfigExt_t* pstConfigArg);
void TIMERA__vGetConfigExt(TIMERA_ConfigExt_t* pstConfigArg);

#endif /* DRIVERLIB_TIMERA_DRIVER_HEADER_TIMERA_CONFIG_H_ */
