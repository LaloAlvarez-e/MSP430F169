/**
 *
 * @file TIMERB_CaptureSyncMode.h
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

#ifndef DRIVERLIB_TIMERB_DRIVER_MODULE_HEADER_TIMERB_CAPTURESYNCMODE_H_
#define DRIVERLIB_TIMERB_DRIVER_MODULE_HEADER_TIMERB_CAPTURESYNCMODE_H_

#include "DriverLib/TIMERB/Peripheral/Header/TIMERB_Enum.h"

void TIMERB_CC__vSetCaptureSyncMode(TIMERB_nCC enModuleArg,
                             TIMERB_nCC_CAPTURESYNC enCaptureSyncModeArg);
TIMERB_nCC_CAPTURESYNC TIMERB_CC__enGetCaptureSyncMode(TIMERB_nCC enModuleArg);

#endif /* DRIVERLIB_TIMERB_DRIVER_MODULE_HEADER_TIMERB_CAPTURESYNCMODE_H_ */
