/**
 *
 * @file TIMERA_CaptureConfig.h
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

#ifndef DRIVERLIB_TIMERA_DRIVER_MODULE_CONFIG_HEADER_TIMERA_CAPTURECONFIG_H_
#define DRIVERLIB_TIMERA_DRIVER_MODULE_CONFIG_HEADER_TIMERA_CAPTURECONFIG_H_

#include "DriverLib/TIMERA/Peripheral/Header/TIMERA_Enum.h"

void TIMERA__vSetCaptureConfig(TIMERA_nCC enModuleArg,
                               TIMERA_Capture_Config_t* pstCaptureConfigArg);
void TIMERA__vGetCaptureConfig(TIMERA_nCC enModuleArg,
                        TIMERA_Capture_Config_t* pstCaptureConfigArg);
void TIMERA__vSetCaptureConfigExt(TIMERA_nCC enModuleArg,
                                  TIMERA_Capture_ConfigExt_t* pstCaptureConfigArg);
void TIMERA__vGetCaptureConfigExt(TIMERA_nCC enModuleArg,
                                  TIMERA_Capture_ConfigExt_t* pstCaptureConfigArg);


#endif /* DRIVERLIB_TIMERA_DRIVER_MODULE_CONFIG_HEADER_TIMERA_CAPTURECONFIG_H_ */
