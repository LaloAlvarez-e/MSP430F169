/**
 *
 * @file TIMERA_OperationMode.h
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

#ifndef DRIVERLIB_TIMERA_DRIVER_GLOBAL_HEADER_TIMERA_OPERATIONMODE_H_
#define DRIVERLIB_TIMERA_DRIVER_GLOBAL_HEADER_TIMERA_OPERATIONMODE_H_

#include "DriverLib/TIMERA/Peripheral/Header/TIMERA_Enum.h"

void TIMERA__vSetOperationMode(TIMERA_nMODE enOperationModeArg);
TIMERA_nMODE TIMERA__enGetOperationMode(void);

#endif /* DRIVERLIB_TIMERA_DRIVER_GLOBAL_HEADER_TIMERA_OPERATIONMODE_H_ */
