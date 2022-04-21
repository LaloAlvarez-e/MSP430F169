/**
 *
 * @file ADC12_Priority.h
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
 * @verbatim 27 mar. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 27 mar. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_ADC12_DRIVER_HEADER_ADC12_PRIORITY_H_
#define DRIVERLIB_ADC12_DRIVER_HEADER_ADC12_PRIORITY_H_

#include "DriverLib/ADC12/Peripheral/Header/ADC12_Enum.h"

void ADC12__vSetPriorityMode(ADC12_nPRIORITY enPriorityArg);
ADC12_nPRIORITY ADC12__enGetPriorityMode(void);


#endif /* DRIVERLIB_ADC12_DRIVER_HEADER_ADC12_PRIORITY_H_ */
