/**
 *
 * @file MCU_ReadRegister.c
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
#include "MCU/Header/MCU_ReadRegister.h"

uint8_t MCU__u8ReadRegister(uint32_t u32RegisterAddress,
                            uint8_t u8RegisterMask,
                            uint8_t u8RegisterShift)
{
    uint8_t u8RegisterValue = 0U;
    volatile uint8_t* pu8RegisterAddress = (volatile uint8_t*) u32RegisterAddress;

    u8RegisterValue = *pu8RegisterAddress;
    if(MCU_MASK_8 != u8RegisterMask)
    {
        u8RegisterValue >>= u8RegisterShift;
        u8RegisterValue &= u8RegisterMask;
    }
    return (u8RegisterValue);
}

uint16_t MCU__u16ReadRegister(uint32_t u32RegisterAddress,
                            uint16_t u16RegisterMask,
                            uint8_t u8RegisterShift)
{
    uint16_t u16RegisterValue = 0U;
    volatile uint16_t* pu16RegisterAddress = (volatile uint16_t*) u32RegisterAddress;

    u16RegisterValue = *pu16RegisterAddress;
    if(MCU_MASK_16 != u16RegisterMask)
    {
        u16RegisterValue >>= u8RegisterShift;
        u16RegisterValue &= u16RegisterMask;
    }
    return (u16RegisterValue);
}
