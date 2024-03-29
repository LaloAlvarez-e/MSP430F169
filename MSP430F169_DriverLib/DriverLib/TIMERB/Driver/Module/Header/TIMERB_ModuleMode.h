/**
 *
 * @file TIMERB_ModuleMode.h
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
 * @verbatim 12 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 12 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_TIMERB_DRIVER_MODULE_HEADER_TIMERB_MODULEMODE_H_
#define DRIVERLIB_TIMERB_DRIVER_MODULE_HEADER_TIMERB_MODULEMODE_H_

#include "DriverLib/TIMERB/Peripheral/Header/TIMERB_Enum.h"

void TIMERB_CC__vSetModuleMode(TIMERB_nCC enModuleArg,
                             TIMERB_nCC_MODE enModuleModeArg);
TIMERB_nCC_MODE TIMERB_CC__enGetModuleMode(TIMERB_nCC enModuleArg);



#endif /* DRIVERLIB_TIMERB_DRIVER_MODULE_HEADER_TIMERB_MODULEMODE_H_ */
