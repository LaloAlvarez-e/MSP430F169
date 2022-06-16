/**
 *
 * @file WDT_ReadRegister.c
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
 * @verbatim 25 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 25 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/WDT/Driver/Intrinsics/Primitives/Header/WDT_ReadRegister.h"

#include "DriverLib/WDT/Peripheral/WDT_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

uint8_t WDT__u8ReadRegister(WDT_Register8Bits_t* pstRegisterData)
{
    uint8_t u8RegisterValue;

    pstRegisterData->uptrAddress += WDT_BASE;
    u8RegisterValue = MCU__u8ReadRegister(pstRegisterData);
    return (u8RegisterValue);
}


uint16_t WDT__u16ReadRegister(WDT_Register16Bits_t* pstRegisterData)
{
    uint8_t u16RegisterValue;

    pstRegisterData->uptrAddress += WDT_BASE;
    u16RegisterValue = MCU__u16ReadRegister(pstRegisterData);
    return (u16RegisterValue);
}

uint16_t WDT__u16ReadRegister_RAM(WDT_Register16Bits_t* pstRegisterData)
{
    uint8_t u16RegisterValue;

    pstRegisterData->uptrAddress += WDT_BASE;
    u16RegisterValue = MCU__u16ReadRegister_RAM(pstRegisterData);
    return (u16RegisterValue);
}


