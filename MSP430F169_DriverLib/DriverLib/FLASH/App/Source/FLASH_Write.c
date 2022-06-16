/**
 *
 * @file FLASH_Write.c
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
 * @verbatim 8 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 8 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/FLASH/App/Header/FLASH_Write.h"

#include "DriverLib/FLASH/App/Intrinsics/Header/FLASH_InitProcess.h"
#include "DriverLib/FLASH/FLASH.h"


FLASH_nSTATUS FLASH__enMainWriteWord(uint16_t u16DataArg, uintptr_t uptrAddressArg)
{
    FLASH_nSTATUS enStatusReg;
    FLASH_Segment_t stSegmentCallback;

    stSegmentCallback.uptrGetStartAddress = &FLASH__uptrGetMainStartAddress;
    stSegmentCallback.uptrGetEndAddress = &FLASH__uptrGetMainEndAddress;
    stSegmentCallback.vStartProcess = (void (*)(uint8_t u8Value)) &FLASH__vStartWriteProcess;
    enStatusReg = FLASH__enInitProcess(&stSegmentCallback,
                                       (uint8_t) FLASH_enWRITE_SINGLE,
                                       (void*) u16DataArg,
                                       (uint16_t*) 0U,
                                       uptrAddressArg,
                                       FLASH_enWORDSIZE_WORD);
    return (enStatusReg);
}

FLASH_nSTATUS FLASH__enMainWriteByte(uint8_t u8DataArg, uintptr_t uptrAddressArg)
{
    FLASH_nSTATUS enStatusReg;
    uintptr_t uptrAddressReg;
    static uint16_t u16DataReg;
    uint16_t* pu16DataReg;
    uint8_t* pu8DataReg;
    uint16_t u16Offset;

    u16Offset = uptrAddressArg;
    u16Offset &= 0x1;
    uptrAddressReg = uptrAddressArg;
    uptrAddressReg &= ~0x1;
    pu16DataReg = ((uint16_t*) uptrAddressReg);
    u16DataReg =  *pu16DataReg;
    pu8DataReg = (uint8_t*) &u16DataReg;
    pu8DataReg += u16Offset;
    *pu8DataReg = u8DataArg;

    enStatusReg = FLASH__enMainWriteWord(u16DataReg, uptrAddressReg);
    return (enStatusReg);
}


FLASH_nSTATUS FLASH__enInfoWriteWord(uint16_t u16DataArg, uintptr_t uptrAddressArg)
{
    FLASH_nSTATUS enStatusReg;
    FLASH_Segment_t stSegmentCallback;

    stSegmentCallback.uptrGetStartAddress = &FLASH__uptrGetInfoStartAddress;
    stSegmentCallback.uptrGetEndAddress = &FLASH__uptrGetInfoEndAddress;
    stSegmentCallback.vStartProcess = (void (*)(uint8_t u8Value)) &FLASH__vStartWriteProcess;
    enStatusReg = FLASH__enInitProcess(&stSegmentCallback,
                                       (uint8_t) FLASH_enWRITE_SINGLE,
                                       (void*) u16DataArg,
                                       (uint16_t*) 0U,
                                       uptrAddressArg,
                                       FLASH_enWORDSIZE_WORD);
    return (enStatusReg);
}


FLASH_nSTATUS FLASH__enInfoWriteByte(uint8_t u8DataArg, uintptr_t uptrAddressArg)
{
    FLASH_nSTATUS enStatusReg;
    uintptr_t uptrAddressReg;
    static uint16_t u16DataReg;
    uint16_t* pu16DataReg ;
    uint8_t* pu8DataReg;
    uint16_t u16Offset;

    u16Offset = uptrAddressArg;
    u16Offset &= 0x1;
    uptrAddressReg = uptrAddressArg;
    uptrAddressReg &= ~0x1;
    pu16DataReg = ((uint16_t*) uptrAddressReg);
    u16DataReg =  *pu16DataReg;
    pu8DataReg = (uint8_t*) &u16DataReg;
    pu8DataReg += u16Offset;
    *pu8DataReg = u8DataArg;

    enStatusReg = FLASH__enInfoWriteWord(u16DataReg, uptrAddressReg);
    return (enStatusReg);
}


FLASH_nSTATUS FLASH__enWriteWord(uint16_t u16DataArg,
                                 uintptr_t uptrAddressArg)
{
    FLASH_nSTATUS enStatusReg;

    enStatusReg = FLASH__enInfoWriteWord(u16DataArg, uptrAddressArg);
    if(FLASH_enSTATUS_ERROR == enStatusReg)
    {
        enStatusReg = FLASH__enMainWriteWord(u16DataArg, uptrAddressArg);
    }
    return (enStatusReg);
}

FLASH_nSTATUS FLASH__enWriteByte(uint8_t u8DataArg,
                                 uintptr_t uptrAddressArg)
{
    FLASH_nSTATUS enStatusReg;

    enStatusReg = FLASH__enInfoWriteByte(u8DataArg, uptrAddressArg);
    if(FLASH_enSTATUS_ERROR == enStatusReg)
    {
        enStatusReg = FLASH__enMainWriteByte(u8DataArg, uptrAddressArg);
    }
    return (enStatusReg);
}




