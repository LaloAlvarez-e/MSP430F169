/**
 *
 * @file DAC12_PowerCoreState.h
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
 * @verbatim 21 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 21 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_DAC12_DRIVER_GLOBAL_HEADER_DAC12_POWERSTATE_H_
#define DRIVERLIB_DAC12_DRIVER_GLOBAL_HEADER_DAC12_POWERSTATE_H_

#include "DriverLib/DAC12/Peripheral/Header/DAC12_Enum.h"

void DAC12__vSetPowerCoreState(DAC12_nSTATE enStateArg);
void DAC12__vPowerOnCore(void);
void DAC12__vPowerOffCore(void);

DAC12_nSTATE DAC12__enGetPowerCoreState(void);

#endif /* DRIVERLIB_DAC12_DRIVER_GLOBAL_HEADER_DAC12_POWERSTATE_H_ */
