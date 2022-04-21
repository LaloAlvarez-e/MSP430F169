/**
 *
 * @file ADC12_Trigger.h
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
 * @verbatim 25 mar. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 25 mar. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_ADC12_DRIVER_HEADER_ADC12_TRIGGER_H_
#define DRIVERLIB_ADC12_DRIVER_HEADER_ADC12_TRIGGER_H_

#include "DriverLib/ADC12/Peripheral/Header/ADC12_Enum.h"

void ADC12__vSetTrigger(ADC12_nCH enChannelArg,
                      ADC12_nCH_TRIGGER enTriggerArg);

ADC12_nCH_TRIGGER ADC12__enGetTrigger(ADC12_nCH enChannelArg);

#endif /* DRIVERLIB_ADC12_DRIVER_HEADER_ADC12_TRIGGER_H_ */
