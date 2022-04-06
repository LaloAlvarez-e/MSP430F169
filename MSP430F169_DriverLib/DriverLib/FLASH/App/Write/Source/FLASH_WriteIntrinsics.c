/**
 *
 * @file FLASH_WriteIntrinsics.c
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
 * @verbatim 3 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 3 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/FLASH/App/Write/Header/FLASH_WriteIntrinsics.h"

#include "DriverLib/FLASH/App/Intrinsics/Header/FLASH_InitProcess.h"
#include "DriverLib/FLASH/FLASH.h"


FLASH_nSTATUS FLASH__enMainWriteWord(uint16_t u16DataArg, uintptr_t uptrAddressArg)
{
    FLASH_nSTATUS enStatusReg = FLASH_enSTATUS_ERROR;
    FLASH_Segment_t stSegmentCallback = {0U};

    stSegmentCallback.uptrGetStartAddress = &FLASH__uptrGetMainStartAddress;
    stSegmentCallback.uptrGetEndAddress = &FLASH__uptrGetMainEndAddress;
    stSegmentCallback.vStartProcess = &FLASH__vStartWriteProcess;
    enStatusReg = FLASH__enInitProcess(&stSegmentCallback,
                                       (uint8_t) FLASH_enWRITE_SINGLE,
                                       u16DataArg,
                                       uptrAddressArg);
    return (enStatusReg);
}

FLASH_nSTATUS FLASH__enMainWriteByte(uint8_t u8DataArg, uintptr_t uptrAddressArg)
{
    FLASH_nSTATUS enStatusReg = FLASH_enSTATUS_ERROR;
    uintptr_t uptrAddressReg = 0U;
    static uint16_t u16DataReg = 0U;
    uint16_t* pu16DataReg = (uint16_t*) 0U;
    uint8_t* pu8DataReg = (uint8_t*) 0U;
    uint16_t u16Offset = 0U;

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
    FLASH_nSTATUS enStatusReg = FLASH_enSTATUS_ERROR;
    FLASH_Segment_t stSegmentCallback = {0U};

    stSegmentCallback.uptrGetStartAddress = &FLASH__uptrGetInfoStartAddress;
    stSegmentCallback.uptrGetEndAddress = &FLASH__uptrGetInfoEndAddress;
    stSegmentCallback.vStartProcess = &FLASH__vStartWriteProcess;
    enStatusReg = FLASH__enInitProcess(&stSegmentCallback,
                                       (uint8_t) FLASH_enWRITE_SINGLE,
                                       u16DataArg,
                                       uptrAddressArg);
    return (enStatusReg);
}


FLASH_nSTATUS FLASH__enInfoWriteByte(uint8_t u8DataArg, uintptr_t uptrAddressArg)
{
    FLASH_nSTATUS enStatusReg = FLASH_enSTATUS_ERROR;
    uintptr_t uptrAddressReg = 0U;
    static uint16_t u16DataReg = 0U;
    uint16_t* pu16DataReg = (uint16_t*) 0U;
    uint8_t* pu8DataReg = (uint8_t*) 0U;
    uint16_t u16Offset = 0U;

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


FLASH_nSTATUS FLASH__enWriteWord(FLASH_nSECTION enSectionArg,
                                 uint16_t u16DataArg,
                                 uintptr_t uptrAddressArg)
{
    FLASH_nSTATUS enStatusReg = FLASH_enSTATUS_ERROR;
    switch(enSectionArg)
    {
    case FLASH_enSECTION_MAIN:
        enStatusReg = FLASH__enMainWriteWord(u16DataArg, uptrAddressArg);
        break;
    case FLASH_enSECTION_INFO:
        enStatusReg = FLASH__enInfoWriteWord(u16DataArg, uptrAddressArg);
        break;
    default:
        break;
    }
    return (enStatusReg);
}

FLASH_nSTATUS FLASH__enWriteByte(FLASH_nSECTION enSectionArg,
                                 uint8_t u8DataArg,
                                 uintptr_t uptrAddressArg)
{
    FLASH_nSTATUS enStatusReg = FLASH_enSTATUS_ERROR;
    switch(enSectionArg)
    {
    case FLASH_enSECTION_MAIN:
        enStatusReg = FLASH__enMainWriteByte(u8DataArg, uptrAddressArg);
        break;
    case FLASH_enSECTION_INFO:
        enStatusReg = FLASH__enInfoWriteByte(u8DataArg, uptrAddressArg);
        break;
    default:
        break;
    }
    return (enStatusReg);
}


