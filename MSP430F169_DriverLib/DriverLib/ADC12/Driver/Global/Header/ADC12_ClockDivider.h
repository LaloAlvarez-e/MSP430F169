/**
 *
 * @file ADC12_ClockDivider.h
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
 * @verbatim 22 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 22 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_ADC12_DRIVER_GLOBAL_HEADER_ADC12_CLOCKDIVIDER_H_
#define DRIVERLIB_ADC12_DRIVER_GLOBAL_HEADER_ADC12_CLOCKDIVIDER_H_

#include "DriverLib/ADC12/Peripheral/Header/ADC12_Enum.h"

void ADC12__vSetClockDivider(ADC12_nCLOCKDIV enClockDivArg);
ADC12_nCLOCKDIV ADC12__enGetClockDivider(void);


void ADC12__vSetClockDividerByNumber(uint8_t u8ClockDivArg);
uint8_t ADC12__u8GetClockDividerByNumber(void);

#endif /* DRIVERLIB_ADC12_DRIVER_GLOBAL_HEADER_ADC12_CLOCKDIVIDER_H_ */
