/**
 *
 * @file ADC12_WriteRegister.h
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

#ifndef ADC12_DRIVER_INTRINSICS_PRIMITIVES_HEADER_ADC12_WRITEREGISTER_H_
#define ADC12_DRIVER_INTRINSICS_PRIMITIVES_HEADER_ADC12_WRITEREGISTER_H_

#include "DriverLib/ADC12/Peripheral/Header/ADC12_Enum.h"

void ADC12__vWriteRegister(ADC12_Register16Bits_t* pstRegisterData);
void ADC12_CH__vWriteRegister_16bits(ADC12_nCH enChannelArg,
                            ADC12_Register16Bits_t* pstRegisterData);
void ADC12_CH__vWriteRegister_8bits(ADC12_nCH enChannelArg,
                            ADC12_Register8Bits_t* pstRegisterData);
#endif /* ADC12_DRIVER_INTRINSICS_PRIMITIVES_HEADER_ADC12_WRITEREGISTER_H_ */
