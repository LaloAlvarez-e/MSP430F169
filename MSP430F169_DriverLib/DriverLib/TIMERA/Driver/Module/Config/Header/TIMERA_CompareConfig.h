/**
 *
 * @file TIMERA_CompareConfig.h
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

#ifndef DRIVERLIB_TIMERA_DRIVER_MODULE_CONFIG_HEADER_TIMERA_COMPARECONFIG_H_
#define DRIVERLIB_TIMERA_DRIVER_MODULE_CONFIG_HEADER_TIMERA_COMPARECONFIG_H_

#include "DriverLib/TIMERA/Peripheral/Header/TIMERA_Enum.h"

void TIMERA__vSetCompareConfig(TIMERA_nCC enModuleArg,
                               TIMERA_Compare_Config_t* pstCompareConfigArg);
void TIMERA__vGetCompareConfig(TIMERA_nCC enModuleArg,
                        TIMERA_Compare_Config_t* pstCompareConfigArg);
void TIMERA__vSetCompareConfigExt(TIMERA_nCC enModuleArg,
                                  TIMERA_Compare_ConfigExt_t* pstCompareConfigArg);
void TIMERA__vGetCompareConfigExt(TIMERA_nCC enModuleArg,
                                  TIMERA_Compare_ConfigExt_t* pstCompareConfigArg);



#endif /* DRIVERLIB_TIMERA_DRIVER_MODULE_CONFIG_HEADER_TIMERA_COMPARECONFIG_H_ */
