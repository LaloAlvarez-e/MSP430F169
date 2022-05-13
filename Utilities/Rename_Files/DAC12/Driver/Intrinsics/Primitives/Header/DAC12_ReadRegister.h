/**
 *
 * @file DAC12_ReadRegister.h
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

#ifndef DAC12_DRIVER_INTRINSICS_PRIMITIVES_HEADER_DAC12_READREGISTER_H_
#define DAC12_DRIVER_INTRINSICS_PRIMITIVES_HEADER_DAC12_READREGISTER_H_

#include "DriverLib/DAC12/Peripheral/Header/DAC12_Enum.h"

uint16_t DAC12__u16ReadRegister(DAC12_Register16Bits_t* pstRegisterData);

uint16_t DAC12_CH__u16ReadRegister(DAC12_nCH enChannelArg,
                                 DAC12_Register16Bits_t* pstRegisterData);
uint8_t DAC12_CH__u8ReadRegister(DAC12_nCH enChannelArg,
                                 DAC12_Register8Bits_t* pstRegisterData);

#endif /* DAC12_DRIVER_INTRINSICS_PRIMITIVES_HEADER_DAC12_READREGISTER_H_ */
