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
    FLASH_nSTATUS enStatusReg = FLASH_enSTATUS_ERROR;

    pstSegmentCallback->vStartProcess = &FLASH__vStartEraseProcess;
    enStatusReg = FLASH__enInitProcess(pstSegmentCallback,
                                       (uint8_t)enEraseModeArg,
                                       0U,
                                       uptrAddressArg);
    return (enStatusReg);
}



static FLASH_nSTATUS FLASH__enSegmentErase(FLASH_Segment_t* pstSegmentCallback ,
                                          uint16_t u16SegmentPosArg)
{
    FLASH_nSTATUS enStatusReg = FLASH_enSTATUS_ERROR;
    uintptr_t uptrFlashStartAddress = 0U;
    uint16_t u16FlashSegmentSize = 0U;
    uint32_t u32FlashAddressSegment = 0U;
    uintptr_t uptrFlashAddressSegment = 0U;

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

    return (enStatusReg);
}

FLASH_nSTATUS FLASH__enMassErase(void)
{
    FLASH_nSTATUS enStatusReg = FLASH_enSTATUS_ERROR;
    uintptr_t uptrStartAddressReg = 0U;
    FLASH_Segment_t stSegmentCallback = {0UL};
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
    FLASH_nSTATUS enStatusReg = FLASH_enSTATUS_ERROR;
    uintptr_t uptrStartAddressReg = 0U;
    FLASH_Segment_t stSegmentCallback = {0UL};
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
    FLASH_nSTATUS enStatusReg = FLASH_enSTATUS_ERROR;
    FLASH_Segment_t stSegmentCallback = {0UL};
    stSegmentCallback.uptrGetStartAddress = &FLASH__uptrGetMainStartAddress;
    stSegmentCallback.uptrGetEndAddress = &FLASH__uptrGetMainEndAddress;
    stSegmentCallback.u16GetSegmentSize = &FLASH__u16GetMainSegmentSize;
    enStatusReg = FLASH__enEraseByAddress(&stSegmentCallback, FLASH_enERASE_SEGMENT,
                                          uptrAddressArg);
    return (enStatusReg);
}

FLASH_nSTATUS FLASH__enInfoSegmentEraseByAddress(uintptr_t uptrAddressArg)
{
    FLASH_nSTATUS enStatusReg = FLASH_enSTATUS_ERROR;
    FLASH_Segment_t stSegmentCallback = {0UL};
    stSegmentCallback.uptrGetStartAddress = &FLASH__uptrGetInfoStartAddress;
    stSegmentCallback.uptrGetEndAddress = &FLASH__uptrGetInfoEndAddress;
    stSegmentCallback.u16GetSegmentSize = &FLASH__u16GetInfoSegmentSize;
    enStatusReg = FLASH__enEraseByAddress(&stSegmentCallback, FLASH_enERASE_SEGMENT,
                                          uptrAddressArg);
    return (enStatusReg);
}

FLASH_nSTATUS FLASH__enSegmentEraseByAddress(FLASH_nSECTION enSectionArg,
                                             uintptr_t uptrAddressArg)
{
    FLASH_nSTATUS enStatusReg = FLASH_enSTATUS_ERROR;
    switch(enSectionArg)
    {
    case FLASH_enSECTION_MAIN:
        enStatusReg = FLASH__enMainSegmentEraseByAddress(uptrAddressArg);
        break;
    case FLASH_enSECTION_INFO:
        enStatusReg = FLASH__enInfoSegmentEraseByAddress(uptrAddressArg);
        break;
    default:
        break;
    }
    return (enStatusReg);
}


FLASH_nSTATUS FLASH__enMainSegmentErase(uint16_t u16SegmentPosArg)
{
    FLASH_nSTATUS enStatusReg = FLASH_enSTATUS_ERROR;
    FLASH_Segment_t stSegmentCallback = {0UL};
    stSegmentCallback.uptrGetStartAddress = &FLASH__uptrGetMainStartAddress;
    stSegmentCallback.uptrGetEndAddress = &FLASH__uptrGetMainEndAddress;
    stSegmentCallback.u16GetSegmentSize = &FLASH__u16GetMainSegmentSize;
    enStatusReg = FLASH__enSegmentErase(&stSegmentCallback, u16SegmentPosArg);
    return (enStatusReg);
}

FLASH_nSTATUS FLASH__enInfoSegmentErase(uint16_t u16SegmentPosArg)
{
    FLASH_nSTATUS enStatusReg = FLASH_enSTATUS_ERROR;
    FLASH_Segment_t stSegmentCallback = {0UL};
    stSegmentCallback.uptrGetStartAddress = &FLASH__uptrGetInfoStartAddress;
    stSegmentCallback.uptrGetEndAddress = &FLASH__uptrGetInfoEndAddress;
    stSegmentCallback.u16GetSegmentSize = &FLASH__u16GetInfoSegmentSize;
    enStatusReg = FLASH__enSegmentErase(&stSegmentCallback, u16SegmentPosArg);
    return (enStatusReg);
}

FLASH_nSTATUS FLASH__enSegmentEraseByPosition(FLASH_nSECTION enSectionArg,
                                              uint16_t u16SegmentPosArg)
{
    FLASH_nSTATUS enStatusReg = FLASH_enSTATUS_ERROR;
    switch(enSectionArg)
    {
    case FLASH_enSECTION_MAIN:
        enStatusReg = FLASH__enMainSegmentErase(u16SegmentPosArg);
        break;
    case FLASH_enSECTION_INFO:
        enStatusReg = FLASH__enInfoSegmentErase(u16SegmentPosArg);
        break;
    default:
        break;
    }
    return (enStatusReg);
}

