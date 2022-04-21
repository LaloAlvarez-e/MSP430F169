/**
 *
 * @file ADC12_ReadRegister.h
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

#ifndef ADC12_DRIVER_INTRINSICS_PRIMITIVES_HEADER_ADC12_READREGISTER_H_
#define ADC12_DRIVER_INTRINSICS_PRIMITIVES_HEADER_ADC12_READREGISTER_H_

#include "DriverLib/ADC12/Peripheral/Header/ADC12_Enum.h"

uint16_t ADC12__u16ReadRegister(ADC12_Register16Bits_t* pstRegisterData);

uint16_t ADC12_CH__u16ReadRegister(ADC12_nCH enChannelArg,
                                 ADC12_Register16Bits_t* pstRegisterData);
uint8_t ADC12_CH__u8ReadRegister(ADC12_nCH enChannelArg,
                                 ADC12_Register8Bits_t* pstRegisterData);

#endif /* ADC12_DRIVER_INTRINSICS_PRIMITIVES_HEADER_ADC12_READREGISTER_H_ */
