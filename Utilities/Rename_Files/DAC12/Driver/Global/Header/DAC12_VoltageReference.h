/**
 *
 * @file DAC12_VoltageReference.h
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

#ifndef DRIVERLIB_DAC12_DRIVER_GLOBAL_HEADER_DAC12_VOLTAGEREFERENCE_H_
#define DRIVERLIB_DAC12_DRIVER_GLOBAL_HEADER_DAC12_VOLTAGEREFERENCE_H_

#include "DriverLib/DAC12/Peripheral/Header/DAC12_Enum.h"

void DAC12__vSetVREFState(DAC12_nSTATE enStateArg);
void DAC12__vPowerOnVREF(void);
void DAC12__vPowerOffVREF(void);
DAC12_nSTATE DAC12__enGetVREFState(void);


void DAC12__vSetVREFValue(DAC12_nVREF enValueArg);
DAC12_nVREF DAC12__enGetVREFValue(void);





#endif /* DRIVERLIB_DAC12_DRIVER_GLOBAL_HEADER_DAC12_VOLTAGEREFERENCE_H_ */
