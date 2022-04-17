/**
 *
 * @file TIMERB_CompareConfig.h
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

#ifndef DRIVERLIB_TIMERB_DRIVER_MODULE_CONFIG_HEADER_TIMERB_COMPARECONFIG_H_
#define DRIVERLIB_TIMERB_DRIVER_MODULE_CONFIG_HEADER_TIMERB_COMPARECONFIG_H_

#include "DriverLib/TIMERB/Peripheral/Header/TIMERB_Enum.h"

void TIMERB__vSetCompareConfig(TIMERB_nCC enModuleArg,
                               TIMERB_Compare_Config_t* pstCompareConfigArg);
void TIMERB__vGetCompareConfig(TIMERB_nCC enModuleArg,
                        TIMERB_Compare_Config_t* pstCompareConfigArg);
void TIMERB__vSetCompareConfigExt(TIMERB_nCC enModuleArg,
                                  TIMERB_Compare_ConfigExt_t* pstCompareConfigArg);
void TIMERB__vGetCompareConfigExt(TIMERB_nCC enModuleArg,
                                  TIMERB_Compare_ConfigExt_t* pstCompareConfigArg);



#endif /* DRIVERLIB_TIMERB_DRIVER_MODULE_CONFIG_HEADER_TIMERB_COMPARECONFIG_H_ */
