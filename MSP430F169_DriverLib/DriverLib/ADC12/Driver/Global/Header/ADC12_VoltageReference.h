/**
 *
 * @file ADC12_VoltageReference.h
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

#ifndef DRIVERLIB_ADC12_DRIVER_GLOBAL_HEADER_ADC12_VOLTAGEREFERENCE_H_
#define DRIVERLIB_ADC12_DRIVER_GLOBAL_HEADER_ADC12_VOLTAGEREFERENCE_H_

#include "DriverLib/ADC12/Peripheral/Header/ADC12_Enum.h"

void ADC12__vSetVREFState(ADC12_nSTATE enStateArg);
void ADC12__vPowerOnVREF(void);
void ADC12__vPowerOffVREF(void);
ADC12_nSTATE ADC12__enGetVREFState(void);


void ADC12__vSetVREFValue(ADC12_nVREF enValueArg);
ADC12_nVREF ADC12__enGetVREFValue(void);





#endif /* DRIVERLIB_ADC12_DRIVER_GLOBAL_HEADER_ADC12_VOLTAGEREFERENCE_H_ */
