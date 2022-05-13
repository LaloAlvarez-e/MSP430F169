/**
 *
 * @file DAC12_WriteRegister.h
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
 * @verbatim 7 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 7 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DAC12_DRIVER_INTRINSICS_PRIMITIVES_HEADER_DAC12_WRITEREGISTER_H_
#define DAC12_DRIVER_INTRINSICS_PRIMITIVES_HEADER_DAC12_WRITEREGISTER_H_

#include "DriverLib/DAC12/Peripheral/Header/DAC12_Enum.h"

void DAC12__vWriteRegister(DAC12_Register_t* pstRegisterData);
void DAC12_CH__vWriteRegister(DAC12_nCH enChannelArg,
                            DAC12_Register_t* pstRegisterData);

#endif /* DAC12_DRIVER_INTRINSICS_PRIMITIVES_HEADER_DAC12_WRITEREGISTER_H_ */
