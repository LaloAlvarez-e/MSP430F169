/**
 *
 * @file ADC12_ConversionTrigger.h
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

#ifndef DRIVERLIB_ADC12_DRIVER_GLOBAL_HEADER_ADC12_CONVERSIONTRIGGER_H_
#define DRIVERLIB_ADC12_DRIVER_GLOBAL_HEADER_ADC12_CONVERSIONTRIGGER_H_

#include "DriverLib/ADC12/Peripheral/Header/ADC12_Enum.h"

void ADC12__vSetConversionTrigger(ADC12_nTRIGGER enTriggerArg);
ADC12_nTRIGGER ADC12__enGetConversionTrigger(void);


void ADC12__vSetConversionTriggerEdge(ADC12_nEDGE enEdgeArg);
ADC12_nEDGE ADC12__enGetConversionTriggerEdge(void);

#endif /* DRIVERLIB_ADC12_DRIVER_GLOBAL_HEADER_ADC12_CONVERSIONTRIGGER_H_ */
