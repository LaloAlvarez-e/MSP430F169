/**
 *
 * @file SVS_Reset.h
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
 * @verbatim 10 mar. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 10 mar. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_SVS_DRIVER_HEADER_SVS_RESET_H_
#define DRIVERLIB_SVS_DRIVER_HEADER_SVS_RESET_H_

#include "DriverLib/SVS/Peripheral/Header/SVS_Enum.h"

void SVS__vSetResetCause(SVS_nSTATE enResetStateArg);
SVS_nSTATE SVS__enGetResetCause(void);

#endif /* DRIVERLIB_SVS_DRIVER_HEADER_SVS_RESET_H_ */
