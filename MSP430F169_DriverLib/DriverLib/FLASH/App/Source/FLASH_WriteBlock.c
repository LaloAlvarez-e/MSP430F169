/**
 *
 * @file FLASH_WriteBlock.c
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
#include "DriverLib/FLASH/App/Header/FLASH_WriteBlock.h"

#include "DriverLib/FLASH/App/Intrinsics/Header/FLASH_InitProcess.h"
#include "DriverLib/FLASH/FLASH.h"

FLASH_nSTATUS FLASH__enMainWriteBlock(void* pvDataArg, uint16_t u16DataCountArg,
                                      uintptr_t uptrAddressArg, FLASH_nWORDSIZE enWordSizeArg)
{
    FLASH_nSTATUS enStatusReg = FLASH_enSTATUS_ERROR;
    FLASH_Segment_t stSegmentCallback;

    if(0UL != (uintptr_t) pvDataArg)
    {
        stSegmentCallback.u16GetSegmentSize = &FLASH__u16GetMainSegmentSize;
        stSegmentCallback.uptrGetStartAddress = &FLASH__uptrGetMainStartAddress;
        stSegmentCallback.uptrGetEndAddress = &FLASH__uptrGetMainEndAddress;

        enStatusReg = FLASH__enInitProcess(&stSegmentCallback,
                                           (uint8_t) FLASH_enWRITE_BLOCK,
                                           pvDataArg,
                                           u16DataCountArg,
                                           uptrAddressArg,
                                           enWordSizeArg);
    }
    return (enStatusReg);
}

FLASH_nSTATUS FLASH__enMainWriteBlockWord(uint16_t* pu16DataArg, uint16_t u16DataCountArg,
                                      uintptr_t uptrAddressArg)
{
    FLASH_nSTATUS enStatusReg = FLASH_enSTATUS_ERROR;
    enStatusReg = FLASH__enMainWriteBlock((void*) pu16DataArg, u16DataCountArg, uptrAddressArg, FLASH_enWORDSIZE_WORD);
    return (enStatusReg);
}

FLASH_nSTATUS FLASH__enMainWriteBlockByte(uint8_t* pu8DataArg, uint16_t u16DataCountArg,
                                      uintptr_t uptrAddressArg)
{
    FLASH_nSTATUS enStatusReg = FLASH_enSTATUS_ERROR;
    enStatusReg = FLASH__enMainWriteBlock((void*) pu8DataArg, u16DataCountArg, uptrAddressArg, FLASH_enWORDSIZE_BYTE);
    return (enStatusReg);
}

FLASH_nSTATUS FLASH__enInfoWriteBlock(void* pvDataArg, uint16_t u16DataCountArg,
                                      uintptr_t uptrAddressArg, FLASH_nWORDSIZE enWordSizeArg)
{
    FLASH_nSTATUS enStatusReg = FLASH_enSTATUS_ERROR;
    FLASH_Segment_t stSegmentCallback;

    if(0UL != (uintptr_t) pvDataArg)
    {
        stSegmentCallback.u16GetSegmentSize = &FLASH__u16GetInfoSegmentSize;
        stSegmentCallback.uptrGetStartAddress = &FLASH__uptrGetInfoStartAddress;
        stSegmentCallback.uptrGetEndAddress = &FLASH__uptrGetInfoEndAddress;

        enStatusReg = FLASH__enInitProcess(&stSegmentCallback,
                                           (uint8_t) FLASH_enWRITE_BLOCK,
                                           pvDataArg,
                                           u16DataCountArg,
                                           uptrAddressArg,
                                           enWordSizeArg);
    }
    return (enStatusReg);

}

FLASH_nSTATUS FLASH__enInfoWriteBlockWord(uint16_t* pu16DataArg, uint16_t u16DataCountArg,
                                      uintptr_t uptrAddressArg)
{
    FLASH_nSTATUS enStatusReg = FLASH_enSTATUS_ERROR;
    enStatusReg = FLASH__enInfoWriteBlock((void*) pu16DataArg, u16DataCountArg, uptrAddressArg, FLASH_enWORDSIZE_WORD);
    return (enStatusReg);
}

FLASH_nSTATUS FLASH__enInfoWriteBlockByte(uint8_t* pu8DataArg, uint16_t u16DataCountArg,
                                      uintptr_t uptrAddressArg)
{
    FLASH_nSTATUS enStatusReg = FLASH_enSTATUS_ERROR;
    enStatusReg = FLASH__enInfoWriteBlock((void*) pu8DataArg, u16DataCountArg, uptrAddressArg, FLASH_enWORDSIZE_BYTE);
    return (enStatusReg);
}

FLASH_nSTATUS FLASH__enWriteBlock(void* pvDataArg, uint16_t u16DataCountArg,
                                  uintptr_t uptrAddressArg, FLASH_nWORDSIZE enWordSizeArg)
{
    FLASH_nSTATUS enStatusReg = FLASH_enSTATUS_ERROR;
     FLASH_Segment_t stSegmentCallback;

     if(0UL != (uintptr_t) pvDataArg)
     {
         stSegmentCallback.u16GetSegmentSize = &FLASH__u16GetInfoSegmentSize;
         stSegmentCallback.uptrGetStartAddress = &FLASH__uptrGetInfoStartAddress;
         stSegmentCallback.uptrGetEndAddress = &FLASH__uptrGetMainEndAddress;

         enStatusReg = FLASH__enInitProcess(&stSegmentCallback,
                                            (uint8_t) FLASH_enWRITE_BLOCK,
                                            pvDataArg,
                                            u16DataCountArg,
                                            uptrAddressArg,
                                            enWordSizeArg);
     }
     return (enStatusReg);
}


FLASH_nSTATUS FLASH__enWriteBlockWord(uint16_t* pu16DataArg, uint16_t u16DataCountArg,
                                      uintptr_t uptrAddressArg)
{
    FLASH_nSTATUS enStatusReg = FLASH_enSTATUS_ERROR;
    enStatusReg = FLASH__enWriteBlock((void*) pu16DataArg, u16DataCountArg, uptrAddressArg, FLASH_enWORDSIZE_WORD);
    return (enStatusReg);
}

FLASH_nSTATUS FLASH__enWriteBlockByte(uint8_t* pu8DataArg, uint16_t u16DataCountArg,
                                      uintptr_t uptrAddressArg)
{
    FLASH_nSTATUS enStatusReg = FLASH_enSTATUS_ERROR;
    enStatusReg = FLASH__enWriteBlock((void*) pu8DataArg, u16DataCountArg, uptrAddressArg, FLASH_enWORDSIZE_BYTE);
    return (enStatusReg);
}
