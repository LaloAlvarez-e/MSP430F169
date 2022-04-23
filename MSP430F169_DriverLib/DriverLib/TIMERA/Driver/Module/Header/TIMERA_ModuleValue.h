/**
 *
 * @file TIMERA_ModuleValue.h
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

#ifndef DRIVERLIB_TIMERA_DRIVER_MODULE_HEADER_TIMERA_MODULEVALUE_H_
#define DRIVERLIB_TIMERA_DRIVER_MODULE_HEADER_TIMERA_MODULEVALUE_H_

#include "DriverLib/TIMERA/Peripheral/Header/TIMERA_Enum.h"

void TIMERA_CC__vSetValue(TIMERA_nCC enModuleArg,
                            uint16_t u16ModuleValueArg);
uint16_t TIMERA_CC__u16GetValue(TIMERA_nCC enModuleArg);



#endif /* DRIVERLIB_TIMERA_DRIVER_MODULE_HEADER_TIMERA_MODULEVALUE_H_ */
