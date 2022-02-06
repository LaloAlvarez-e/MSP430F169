/**
 *
 * @file MCU_ReadRegister.h
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

#ifndef MCU_HEADER_MCU_READREGISTER_H_
#define MCU_HEADER_MCU_READREGISTER_H_

#include "MCU/Header/MCU_Common.h"

uint8_t MCU__u8ReadRegister(uintptr_t uptrRegisterAddress,
                            uint8_t u8RegisterMask,
                            uint8_t u8RegisterShift);

uint16_t MCU__u16ReadRegister(uintptr_t uptrRegisterAddress,
                            uint16_t u16RegisterMask,
                            uint8_t u8RegisterShift);

#endif /* MCU_HEADER_MCU_READREGISTER_H_ */
