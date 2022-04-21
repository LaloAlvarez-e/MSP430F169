/**
 *
 * @file ADC12_Fetch.h
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

#ifndef DRIVERLIB_ADC12_DRIVER_HEADER_ADC12_FETCH_H_
#define DRIVERLIB_ADC12_DRIVER_HEADER_ADC12_FETCH_H_

#include "DriverLib/ADC12/Peripheral/Header/ADC12_Enum.h"

void ADC12__vSetFetchMode(ADC12_nFETCH enFetchModeArg);
ADC12_nFETCH ADC12__enGetFetchMode(void);

#endif /* DRIVERLIB_ADC12_DRIVER_HEADER_ADC12_FETCH_H_ */
