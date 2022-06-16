/**
 *
 * @file MCU_WriteRegister.c
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
#include "DriverLib/MCU/Header/MCU_WriteRegister.h"

void MCU__vWriteRegister_8bits(MCU_Register8Bits_t* pstRegisterDataArg)
{
    volatile uint8_t* pu8RegisterAddress;
    uint8_t u8RegisterValue;
    uint8_t u8RegisterMask;
    uint8_t u8RegisterShift;
    uint8_t u8Reg;
    uint16_t u16StatusRegister;
    uintptr_t uptrRegisterAddress;

    if(0UL != (uintptr_t) pstRegisterDataArg)
    {
        u8RegisterValue = pstRegisterDataArg->u8Value;
        u8RegisterMask = pstRegisterDataArg->u8Mask;
        u8RegisterShift = pstRegisterDataArg->u8Shift;
        uptrRegisterAddress = pstRegisterDataArg->uptrAddress;

        u16StatusRegister = _get_interrupt_state();
        _DINT();
        u8Reg = u8RegisterValue;
        pu8RegisterAddress = (volatile uint8_t*) uptrRegisterAddress;
        if(MCU_MASK_8 != u8RegisterMask)
        {
            u8Reg = *pu8RegisterAddress;
            u8RegisterValue &= u8RegisterMask;
            if(0U != u8RegisterShift)
            {
                u8RegisterValue <<= u8RegisterShift;
                u8RegisterMask <<= u8RegisterShift;
            }
            u8Reg &= ~u8RegisterMask;
            u8Reg |= u8RegisterValue;
        }
        *pu8RegisterAddress = u8Reg;
        _set_interrupt_state(u16StatusRegister);
    }
}

void MCU__vWriteRegister_16bits(MCU_Register16Bits_t* pstRegisterDataArg)
{
    volatile uint16_t* pu16RegisterAddress;
    uintptr_t uptrRegisterAddress;
    uint16_t u16StatusRegister;
    uint16_t u16Reg;
    uint16_t u16RegisterValue;
    uint16_t u16RegisterMask;
    uint8_t u8RegisterShift;

    if(0UL != (uintptr_t) pstRegisterDataArg)
    {
        u16RegisterValue = pstRegisterDataArg->u16Value;
        u16RegisterMask = pstRegisterDataArg->u16Mask;
        u8RegisterShift = pstRegisterDataArg->u8Shift;
        uptrRegisterAddress = pstRegisterDataArg->uptrAddress;

        u16StatusRegister = _get_interrupt_state();
        _DINT();
        u16Reg = u16RegisterValue;
        pu16RegisterAddress = (volatile uint16_t*) uptrRegisterAddress;
        if(MCU_MASK_16 != u16RegisterMask)
        {
            u16Reg = *pu16RegisterAddress;
            u16RegisterValue &= u16RegisterMask;
            if(0U != u8RegisterShift)
            {
                u16RegisterValue <<= u8RegisterShift;
                u16RegisterMask <<= u8RegisterShift;
            }
            u16Reg &= ~u16RegisterMask;
            u16Reg |= u16RegisterValue;
        }
        *pu16RegisterAddress = u16Reg;
        _set_interrupt_state(u16StatusRegister);
    }
}

void MCU__vWriteRegister_8bits_RAM(MCU_Register8Bits_t* pstRegisterDataArg)
{
    volatile uint8_t* pu8RegisterAddress;
    uint8_t u8RegisterValue;
    uint8_t u8RegisterMask;
    uint8_t u8RegisterShift;
    uint8_t u8Reg;
    uint16_t u16StatusRegister;
    uintptr_t uptrRegisterAddress;

    if(0UL != (uintptr_t) pstRegisterDataArg)
    {
        u8RegisterValue = pstRegisterDataArg->u8Value;
        u8RegisterMask = pstRegisterDataArg->u8Mask;
        u8RegisterShift = pstRegisterDataArg->u8Shift;
        uptrRegisterAddress = pstRegisterDataArg->uptrAddress;

        u16StatusRegister = _get_interrupt_state();
        _DINT();
        u8Reg = u8RegisterValue;
        pu8RegisterAddress = (volatile uint8_t*) uptrRegisterAddress;
        if(MCU_MASK_8 != u8RegisterMask)
        {
            u8Reg = *pu8RegisterAddress;
            u8RegisterValue &= u8RegisterMask;
            if(0U != u8RegisterShift)
            {
                u8RegisterValue <<= u8RegisterShift;
                u8RegisterMask <<= u8RegisterShift;
            }
            u8Reg &= ~u8RegisterMask;
            u8Reg |= u8RegisterValue;
        }
        *pu8RegisterAddress = u8Reg;
        _set_interrupt_state(u16StatusRegister);
    }
}

void MCU__vWriteRegister_16bits_RAM(MCU_Register16Bits_t* pstRegisterDataArg)
{
    volatile uint16_t* pu16RegisterAddress;
    uintptr_t uptrRegisterAddress;
    uint16_t u16StatusRegister;
    uint16_t u16Reg;
    uint16_t u16RegisterValue;
    uint16_t u16RegisterMask;
    uint8_t u8RegisterShift;

    if(0UL != (uintptr_t) pstRegisterDataArg)
    {
        u16RegisterValue = pstRegisterDataArg->u16Value;
        u16RegisterMask = pstRegisterDataArg->u16Mask;
        u8RegisterShift = pstRegisterDataArg->u8Shift;
        uptrRegisterAddress = pstRegisterDataArg->uptrAddress;

        u16StatusRegister = _get_interrupt_state();
        _DINT();
        u16Reg = u16RegisterValue;
        pu16RegisterAddress = (volatile uint16_t*) uptrRegisterAddress;
        if(MCU_MASK_16 != u16RegisterMask)
        {
            u16Reg = *pu16RegisterAddress;
            u16RegisterValue &= u16RegisterMask;
            if(0U != u8RegisterShift)
            {
                u16RegisterValue <<= u8RegisterShift;
                u16RegisterMask <<= u8RegisterShift;
            }
            u16Reg &= ~u16RegisterMask;
            u16Reg |= u16RegisterValue;
        }
        *pu16RegisterAddress = u16Reg;
        _set_interrupt_state(u16StatusRegister);
    }
}
