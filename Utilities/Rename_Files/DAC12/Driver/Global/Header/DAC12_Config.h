/**
 *
 * @file DAC12_Config.h
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

#ifndef DRIVERLIB_DAC12_DRIVER_HEADER_DAC12_CONFIG_H_
#define DRIVERLIB_DAC12_DRIVER_HEADER_DAC12_CONFIG_H_

#include "DriverLib/DAC12/Peripheral/Header/DAC12_Enum.h"

void DAC12__vSetConfig(DAC12_Config_t* pstConfigArg);
void DAC12__vSetConfigExt(DAC12_ConfigExt_t* pstConfigArg);

void DAC12__vGetConfig(DAC12_Config_t* pstConfigArg);
void DAC12__vGetConfigExt(DAC12_ConfigExt_t* pstConfigArg);

#endif /* DRIVERLIB_DAC12_DRIVER_HEADER_DAC12_CONFIG_H_ */
