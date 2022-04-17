/**
 *
 * @file TIMERB_CaptureConfig.h
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

#ifndef DRIVERLIB_TIMERB_DRIVER_MODULE_CONFIG_HEADER_TIMERB_CAPTURECONFIG_H_
#define DRIVERLIB_TIMERB_DRIVER_MODULE_CONFIG_HEADER_TIMERB_CAPTURECONFIG_H_

#include "DriverLib/TIMERB/Peripheral/Header/TIMERB_Enum.h"

void TIMERB__vSetCaptureConfig(TIMERB_nCC enModuleArg,
                               TIMERB_Capture_Config_t* pstCaptureConfigArg);
void TIMERB__vGetCaptureConfig(TIMERB_nCC enModuleArg,
                        TIMERB_Capture_Config_t* pstCaptureConfigArg);
void TIMERB__vSetCaptureConfigExt(TIMERB_nCC enModuleArg,
                                  TIMERB_Capture_ConfigExt_t* pstCaptureConfigArg);
void TIMERB__vGetCaptureConfigExt(TIMERB_nCC enModuleArg,
                                  TIMERB_Capture_ConfigExt_t* pstCaptureConfigArg);


#endif /* DRIVERLIB_TIMERB_DRIVER_MODULE_CONFIG_HEADER_TIMERB_CAPTURECONFIG_H_ */
