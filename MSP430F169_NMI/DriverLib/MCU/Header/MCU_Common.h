/**
 *
 * @file MCU_Common.h
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

#ifndef MCU_HEADER_MCU_COMMON_H_
#define MCU_HEADER_MCU_COMMON_H_

#include "MSP430.h"
#include <stdint.h>

#define MCU_MASK_8 (0xFFU)
#define MCU_MASK_16 (0xFFFFU)

typedef uint16_t (*MCU__pu16fIRQSourceHandler_t)(uintptr_t uptrModule, uint8_t u8IntSource);

typedef struct
{
    uintptr_t uptrAddress;
    uint8_t u8Value;
    uint8_t u8Mask;
    uint8_t u8Shift;
}MCU_Register8Bits_t;

typedef struct
{
    uintptr_t uptrAddress;
    uint16_t u16Value;
    uint16_t u16Mask;
    uint8_t u8Shift;
}MCU_Register16Bits_t;

#endif /* MCU_HEADER_MCU_COMMON_H_ */
