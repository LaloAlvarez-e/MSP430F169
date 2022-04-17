/**
 *
 * @file TIMERB_OperationMode.h
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
 * @verbatim 9 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 9 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_TIMERB_DRIVER_GLOBAL_HEADER_TIMERB_OPERATIONMODE_H_
#define DRIVERLIB_TIMERB_DRIVER_GLOBAL_HEADER_TIMERB_OPERATIONMODE_H_

#include "DriverLib/TIMERB/Peripheral/Header/TIMERB_Enum.h"

void TIMERB__vSetOperationMode(TIMERB_nMODE enOperationModeArg);
TIMERB_nMODE TIMERB__enGetOperationMode(void);

#endif /* DRIVERLIB_TIMERB_DRIVER_GLOBAL_HEADER_TIMERB_OPERATIONMODE_H_ */
