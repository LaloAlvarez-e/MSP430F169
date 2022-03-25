/**
 *
 * @file DMA_ReadRegister.h
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

#ifndef DMA_DRIVER_INTRINSICS_PRIMITIVES_HEADER_DMA_READREGISTER_H_
#define DMA_DRIVER_INTRINSICS_PRIMITIVES_HEADER_DMA_READREGISTER_H_

#include "DriverLib/DMA/Peripheral/Header/DMA_Enum.h"

uint16_t DMA__u16ReadRegister(DMA_Register_t* pstRegisterData);
uint16_t DMA_CH__u16ReadRegister(DMA_nCH enChannelArg,
                                 DMA_Register_t* pstRegisterData);

#endif /* DMA_DRIVER_INTRINSICS_PRIMITIVES_HEADER_DMA_READREGISTER_H_ */
