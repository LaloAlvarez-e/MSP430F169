/**
 *
 * @file DAC12_ConversionTrigger.h
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

#ifndef DRIVERLIB_DAC12_DRIVER_GLOBAL_HEADER_DAC12_CONVERSIONTRIGGER_H_
#define DRIVERLIB_DAC12_DRIVER_GLOBAL_HEADER_DAC12_CONVERSIONTRIGGER_H_

#include "DriverLib/DAC12/Peripheral/Header/DAC12_Enum.h"

void DAC12__vSetConversionTrigger(DAC12_nTRIGGER enTriggerArg);
DAC12_nTRIGGER DAC12__enGetConversionTrigger(void);


void DAC12__vSetConversionTriggerEdge(DAC12_nEDGE enEdgeArg);
DAC12_nEDGE DAC12__enGetConversionTriggerEdge(void);

#endif /* DRIVERLIB_DAC12_DRIVER_GLOBAL_HEADER_DAC12_CONVERSIONTRIGGER_H_ */
