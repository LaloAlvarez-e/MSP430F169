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
#include "DriverLib/MCU/Header/MCU_ReadRegister.h"

uint8_t MCU__u8ReadRegister(MCU_Register8Bits_t* pstRegisterDataArg)
{
    volatile uint8_t* pu8RegisterAddress = (volatile uint8_t*) 0UL;
    uintptr_t uptrRegisterAddress = 0U;
    uint8_t u8RegisterValue = 0U;
    uint8_t u8RegisterMask = 0U;
    uint8_t u8RegisterShift = 0U;

    if(0UL != (uintptr_t) pstRegisterDataArg)
    {
        u8RegisterMask = pstRegisterDataArg->u8Mask;
        u8RegisterShift = pstRegisterDataArg->u8Shift;
        uptrRegisterAddress = pstRegisterDataArg->uptrAddress;

        pu8RegisterAddress = (volatile uint8_t*) uptrRegisterAddress;
        u8RegisterValue = *pu8RegisterAddress;
        if(MCU_MASK_8 != u8RegisterMask)
        {
            u8RegisterValue >>= u8RegisterShift;
            u8RegisterValue &= u8RegisterMask;
        }
    }
    pstRegisterDataArg->u8Value = u8RegisterValue;
    return (u8RegisterValue);
}

uint16_t MCU__u16ReadRegister(MCU_Register16Bits_t* pstRegisterDataArg)
{
    volatile uint16_t* pu16RegisterAddress = (volatile uint16_t*) 0UL;
    uintptr_t uptrRegisterAddress = 0U;
    uint16_t u16RegisterValue = 0U;
    uint16_t u16RegisterMask = 0U;
    uint8_t u8RegisterShift = 0U;

    if(0UL != (uintptr_t) pstRegisterDataArg)
    {
        u16RegisterMask = pstRegisterDataArg->u16Mask;
        u8RegisterShift = pstRegisterDataArg->u8Shift;
        uptrRegisterAddress = pstRegisterDataArg->uptrAddress;

        pu16RegisterAddress = (volatile uint16_t*) uptrRegisterAddress;
        u16RegisterValue = *pu16RegisterAddress;
        if(MCU_MASK_16 != u16RegisterMask)
        {
            u16RegisterValue >>= u8RegisterShift;
            u16RegisterValue &= u16RegisterMask;
        }
    }
    pstRegisterDataArg->u16Value = u16RegisterValue;
    return (u16RegisterValue);
}
