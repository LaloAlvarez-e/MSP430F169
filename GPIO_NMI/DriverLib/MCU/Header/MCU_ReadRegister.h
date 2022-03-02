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

#include "DriverLib/MCU/Header/MCU_Common.h"

uint8_t MCU__u8ReadRegister(MCU_Register8Bits_t* pstRegisterDataArg);
uint16_t MCU__u16ReadRegister(MCU_Register16Bits_t* pstRegisterDataArg);

#endif /* MCU_HEADER_MCU_READREGISTER_H_ */
