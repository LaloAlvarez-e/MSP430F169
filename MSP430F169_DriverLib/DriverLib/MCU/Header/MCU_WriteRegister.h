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

#include "DriverLib/MCU/Header/MCU_Common.h"

#pragma CODE_SECTION(MCU__vWriteRegister_8bits_RAM, ".TI.ramfunc")
#pragma CODE_SECTION(MCU__vWriteRegister_16bits_RAM, ".TI.ramfunc")

void MCU__vWriteRegister_8bits_RAM(MCU_Register8Bits_t* pstRegisterDataArg);
void MCU__vWriteRegister_16bits_RAM(MCU_Register16Bits_t* pstRegisterDataArg);

void MCU__vWriteRegister_8bits(MCU_Register8Bits_t* pstRegisterDataArg);
void MCU__vWriteRegister_16bits(MCU_Register16Bits_t* pstRegisterDataArg);

#endif /* MCU_HEADER_MCU_WRITEREGISTER_H_ */
