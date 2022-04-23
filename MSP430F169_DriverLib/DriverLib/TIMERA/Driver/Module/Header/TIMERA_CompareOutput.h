/**
 *
 * @file TIMERA_CompareOutput.h
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

#ifndef DRIVERLIB_TIMERA_DRIVER_MODULE_HEADER_TIMERA_COMPAREOUTPUT_H_
#define DRIVERLIB_TIMERA_DRIVER_MODULE_HEADER_TIMERA_COMPAREOUTPUT_H_

#include "DriverLib/TIMERA/Peripheral/Header/TIMERA_Enum.h"

void TIMERA_CC__vSetCompareOutput(TIMERA_nCC enModuleArg,
                             TIMERA_nCC_STATE enCompareOutputArg);
TIMERA_nCC_STATE TIMERA_CC__enGetCompareOutput(TIMERA_nCC enModuleArg);

#endif /* DRIVERLIB_TIMERA_DRIVER_MODULE_HEADER_TIMERA_COMPAREOUTPUT_H_ */
