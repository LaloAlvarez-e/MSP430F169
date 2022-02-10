/**
 *
 * @file MCU_WriteRegister.h
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

#ifndef MCU_HEADER_MCU_WRITEREGISTER_H_
#define MCU_HEADER_MCU_WRITEREGISTER_H_

#include "MCU/Header/MCU_Common.h"

void MCU__vWriteRegister_8bits(uintptr_t uptrRegisterAddress,
                               uint8_t u8RegisterValue,
                               uint8_t u8RegisterMask,
                               uint8_t u8RegisterShift);
void MCU__vWriteRegister_16bits(uintptr_t uptrRegisterAddress,
                               uint16_t u16RegisterValue,
                               uint16_t u16RegisterMask,
                               uint8_t u8RegisterShift);

#endif /* MCU_HEADER_MCU_WRITEREGISTER_H_ */
