/**
 *
 * @file TIMERB_Config.h
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

#ifndef DRIVERLIB_TIMERB_DRIVER_HEADER_TIMERB_CONFIG_H_
#define DRIVERLIB_TIMERB_DRIVER_HEADER_TIMERB_CONFIG_H_

#include "DriverLib/TIMERB/Peripheral/Header/TIMERB_Enum.h"

void TIMERB__vSetConfig(TIMERB_Config_t* pstConfigArg);
void TIMERB__vGetConfig(TIMERB_Config_t* pstConfigArg);

void TIMERB__vSetConfigExt(TIMERB_ConfigExt_t* pstConfigArg);
void TIMERB__vGetConfigExt(TIMERB_ConfigExt_t* pstConfigArg);

#endif /* DRIVERLIB_TIMERB_DRIVER_HEADER_TIMERB_CONFIG_H_ */
