/**
 *
 * @file DAC12_RegisterPeripheral.h
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
 * @verbatim 5 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 5 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DAC12_PERIPHERAL_REGISTERPERIPHERAL_DAC12_REGISTERPERIPHERAL_H_
#define DAC12_PERIPHERAL_REGISTERPERIPHERAL_DAC12_REGISTERPERIPHERAL_H_

#include "DriverLib/DAC12/Peripheral/RegisterPeripheral/Header/DAC12_RegisterPeripheral_CH0.h"
#include "DriverLib/DAC12/Peripheral/RegisterPeripheral/Header/DAC12_RegisterPeripheral_CH1.h"
#include "DriverLib/DAC12/Peripheral/Header/DAC12_Enum.h"

#define DAC12 ((DAC12_t*) DAC12_BASE)

uintptr_t DAC12_CH__uptrBlockBaseAddress(DAC12_nCH enChannelArg);
uintptr_t DAC12__uptrBlockBaseAddress(void);

#endif /* DAC12_PERIPHERAL_REGISTERPERIPHERAL_DAC12_REGISTERPERIPHERAL_H_ */
