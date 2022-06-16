/**
 *
 * @file FLASH_Erase.c
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
 * @verbatim 1 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 1 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/FLASH/App/Header/FLASH_Erase.h"

#include "DriverLib/FLASH/App/Intrinsics/Header/FLASH_InitProcess.h"
#include "DriverLib/FLASH/App/Header/FLASH_Init.h"
#include "DriverLib/FLASH/FLASH.h"
#include "DriverLib/WDT/WDT.h"

static FLASH_nSTATUS FLASH__enSegmentErase(FLASH_Segment_t* pstSegmentCallback ,
                                              uint16_t u16SegmentPosArg);
static FLASH_nSTATUS FLASH__enEraseByAddress(FLASH_Segment_t* pstSegmentCallback ,
                                             FLASH_nERASE enEraseModeArg,
                                             uintptr_t uptrAddressArg);

static FLASH_nSTATUS FLASH__enEraseByAddress(FLASH_Segment_t* pstSegmentCallback ,
                                             FLASH_nERASE enEraseModeArg,
                                             uintptr_t uptrAddressArg)
{
    FLASH_nSTATUS enStatusReg;

    pstSegmentCallback->vStartProcess = (void (*)(uint8_t u8Value)) &FLASH__vStartEraseProcess;
    enStatusReg = FLASH__enInitProcess(pstSegmentCallback,
                                       (uint8_t)enEraseModeArg,
                                       (void*) 0U,
                                       (uint16_t*) 0U,
                                       uptrAddressArg,
                                       FLASH_enWORDSIZE_WORD);
    return (enStatusReg);
}



static FLASH_nSTATUS FLASH__enSegmentErase(FLASH_Segment_t* pstSegmentCallback ,
                                          uint16_t u16SegmentPosArg)
{
    uintptr_t uptrFlashStartAddress;
    uint16_t u16FlashSegmentSize;
    uint32_t u32FlashAddressSegment;
    uintptr_t uptrFlashAddressSegment;
    FLASH_nSTATUS enStatusReg;

    if(0UL != (uintptr_t) pstSegmentCallback)
    {
        uptrFlashStartAddress = pstSegmentCallback->uptrGetStartAddress();
        u16FlashSegmentSize = pstSegmentCallback->u16GetSegmentSize();
        u32FlashAddressSegment = u16FlashSegmentSize * u16SegmentPosArg;
        u32FlashAddressSegment += uptrFlashStartAddress;
        uptrFlashAddressSegment = (uintptr_t) u32FlashAddressSegment;
        enStatusReg = FLASH__enEraseByAddress(pstSegmentCallback, FLASH_enERASE_SEGMENT,
                                              uptrFlashAddressSegment);
    }
    else
    {
        enStatusReg = FLASH_enSTATUS_ERROR;
    }

    return (enStatusReg);
}

FLASH_nSTATUS FLASH__enMassErase(void)
{
    FLASH_nSTATUS enStatusReg;
    uintptr_t uptrStartAddressReg;
    FLASH_Segment_t stSegmentCallback;
    stSegmentCallback.uptrGetStartAddress = &FLASH__uptrGetMainStartAddress;
    stSegmentCallback.uptrGetEndAddress = &FLASH__uptrGetMainEndAddress;
    stSegmentCallback.u16GetSegmentSize = &FLASH__u16GetMainSegmentSize;
    uptrStartAddressReg = stSegmentCallback.uptrGetStartAddress();
    enStatusReg = FLASH__enEraseByAddress(&stSegmentCallback, FLASH_enERASE_MAIN,
                                          uptrStartAddressReg);
    return (enStatusReg);
}

FLASH_nSTATUS FLASH__enFullErase(void)
{
    FLASH_nSTATUS enStatusReg;
    uintptr_t uptrStartAddressReg;
    FLASH_Segment_t stSegmentCallback;
    stSegmentCallback.uptrGetStartAddress = &FLASH__uptrGetMainStartAddress;
    stSegmentCallback.uptrGetEndAddress = &FLASH__uptrGetMainEndAddress;
    stSegmentCallback.u16GetSegmentSize = &FLASH__u16GetMainSegmentSize;
    uptrStartAddressReg = stSegmentCallback.uptrGetStartAddress();
    enStatusReg = FLASH__enEraseByAddress(&stSegmentCallback, FLASH_enERASE_MAIN_INFO,
                                          uptrStartAddressReg);
    return (enStatusReg);
}



FLASH_nSTATUS FLASH__enMainSegmentEraseByAddress(uintptr_t uptrAddressArg)
{
    FLASH_nSTATUS enStatusReg;
    FLASH_Segment_t stSegmentCallback;
    stSegmentCallback.uptrGetStartAddress = &FLASH__uptrGetMainStartAddress;
    stSegmentCallback.uptrGetEndAddress = &FLASH__uptrGetMainEndAddress;
    stSegmentCallback.u16GetSegmentSize = &FLASH__u16GetMainSegmentSize;
    enStatusReg = FLASH__enEraseByAddress(&stSegmentCallback, FLASH_enERASE_SEGMENT,
                                          uptrAddressArg);
    return (enStatusReg);
}

FLASH_nSTATUS FLASH__enInfoSegmentEraseByAddress(uintptr_t uptrAddressArg)
{
    FLASH_nSTATUS enStatusReg;
    FLASH_Segment_t stSegmentCallback;
    stSegmentCallback.uptrGetStartAddress = &FLASH__uptrGetInfoStartAddress;
    stSegmentCallback.uptrGetEndAddress = &FLASH__uptrGetInfoEndAddress;
    stSegmentCallback.u16GetSegmentSize = &FLASH__u16GetInfoSegmentSize;
    enStatusReg = FLASH__enEraseByAddress(&stSegmentCallback, FLASH_enERASE_SEGMENT,
                                          uptrAddressArg);
    return (enStatusReg);
}

FLASH_nSTATUS FLASH__enSegmentEraseByAddress(uintptr_t uptrAddressArg)
{
    FLASH_nSTATUS enStatusReg;

    enStatusReg = FLASH__enInfoSegmentEraseByAddress(uptrAddressArg);
    if(FLASH_enSTATUS_ERROR == enStatusReg)
    {
        enStatusReg = FLASH__enMainSegmentEraseByAddress(uptrAddressArg);
    }
    return (enStatusReg);
}


FLASH_nSTATUS FLASH__enMainSegmentErase(uint16_t u16SegmentPosArg)
{
    FLASH_nSTATUS enStatusReg;
    FLASH_Segment_t stSegmentCallback;
    stSegmentCallback.uptrGetStartAddress = &FLASH__uptrGetMainStartAddress;
    stSegmentCallback.uptrGetEndAddress = &FLASH__uptrGetMainEndAddress;
    stSegmentCallback.u16GetSegmentSize = &FLASH__u16GetMainSegmentSize;
    enStatusReg = FLASH__enSegmentErase(&stSegmentCallback, u16SegmentPosArg);
    return (enStatusReg);
}

FLASH_nSTATUS FLASH__enInfoSegmentErase(uint16_t u16SegmentPosArg)
{
    FLASH_nSTATUS enStatusReg;
    FLASH_Segment_t stSegmentCallback;
    stSegmentCallback.uptrGetStartAddress = &FLASH__uptrGetInfoStartAddress;
    stSegmentCallback.uptrGetEndAddress = &FLASH__uptrGetInfoEndAddress;
    stSegmentCallback.u16GetSegmentSize = &FLASH__u16GetInfoSegmentSize;
    enStatusReg = FLASH__enSegmentErase(&stSegmentCallback, u16SegmentPosArg);
    return (enStatusReg);
}

FLASH_nSTATUS FLASH__enSegmentEraseByPosition(FLASH_nSECTION enSectionArg,
                                              uint16_t u16SegmentPosArg)
{
    FLASH_nSTATUS enStatusReg;
    switch(enSectionArg)
    {
    case FLASH_enSECTION_MAIN:
        enStatusReg = FLASH__enMainSegmentErase(u16SegmentPosArg);
        break;
    case FLASH_enSECTION_INFO:
        enStatusReg = FLASH__enInfoSegmentErase(u16SegmentPosArg);
        break;
    default:
        enStatusReg = FLASH_enSTATUS_ERROR;
        break;
    }
    return (enStatusReg);
}

