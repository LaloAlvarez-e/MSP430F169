/**
 *
 * @file FLASH_InitProcess.c
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
 * @verbatim 5 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 5 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/FLASH/App/Intrinsics/Header/FLASH_InitProcess.h"

#include "DriverLib/FLASH/App/Header/FLASH_Init.h"
#include "DriverLib/FLASH/FLASH.h"
#include "DriverLib/WDT/WDT.h"

FLASH_nSTATUS FLASH__enInitProcess(FLASH_Segment_t* pstSegmentCallback ,
                                     uint8_t u8ModeArg,
                                     uint16_t u16DataArg,
                                     uintptr_t uptrAddressArg)
{
    FLASH_nSTATUS enStatusReg = FLASH_enSTATUS_ERROR;
    FLASH_nBUSY enBusyStateReg = FLASH_enBUSY_NOBUSY;
    WDT_nENABLE enWDTEnableReg = WDT_enENABLE_RUN;
    WDT_nMODE enWDTModeReg = WDT_enMODE_WDT;
    uint32_t u32FlashFreqReg = 0U;
    uint16_t u16StatusRegister = 0U;
    uintptr_t uptrFlashStartAddress = 0U;
    uintptr_t uptrFlashEndAddress = 0U;
    uint16_t* pu16DataReg = (uint16_t*) 0U;

    if(0UL != (uintptr_t) pstSegmentCallback)
    {
        u32FlashFreqReg = FLASH__u32Frequency();
        if(0UL != u32FlashFreqReg)
        {
            uptrAddressArg &= ~1U;
            uptrFlashStartAddress = pstSegmentCallback->uptrGetStartAddress();
            uptrFlashEndAddress = pstSegmentCallback->uptrGetEndAddress();
            if((uptrAddressArg >= uptrFlashStartAddress) && (uptrAddressArg <= uptrFlashEndAddress))
            {
                enStatusReg = FLASH_enSTATUS_OK;
                enWDTEnableReg = WDT__enGetEnable();
                u16StatusRegister = _get_interrupt_state();
                enWDTModeReg = WDT__enGetMode();
                if(WDT_enMODE_WDT == enWDTModeReg)
                {
                    WDT__vSetEnable(WDT_enENABLE_STOP);
                }
                _DINT();
                do
                {
                    enBusyStateReg = FLASH__enGetBusyState();
                }while(FLASH_enBUSY_NOBUSY != enBusyStateReg);
                FLASH__vUnlock();
                pu16DataReg = ((uint16_t*) uptrAddressArg);
                pstSegmentCallback->vStartProcess(u8ModeArg);
                *pu16DataReg = u16DataArg;
                FLASH__vLock();
                WDT__vSetEnable(enWDTEnableReg);
                _set_interrupt_state(u16StatusRegister);
            }
        }
    }
    return (enStatusReg);
}



FLASH_nSTATUS FLASH__enInitWriteBlockProcess(FLASH_Segment_t* pstSegmentCallback,
                                         uint16_t* pu16DataArg,
                                         uint16_t u16DataCountArg,
                                         uintptr_t uptrAddressArg)
{
    FLASH_nSTATUS enStatusReg = FLASH_enSTATUS_ERROR;
    FLASH_nBUSY enBusyStateReg = FLASH_enBUSY_NOBUSY;
    WDT_nENABLE enWDTEnableReg = WDT_enENABLE_RUN;
    WDT_nMODE enWDTModeReg = WDT_enMODE_WDT;
    uint32_t u32FlashFreqReg = 0U;
    uint16_t u16StatusRegister = 0U;
    uintptr_t uptrFlashStartAddress = 0U;
    uintptr_t uptrFlashEndAddress = 0U;
    uint16_t u16BlockSize = 0U;
    uint16_t u16BlockMask = 0U;

    if(0UL != (uintptr_t) pstSegmentCallback)
    {
        u32FlashFreqReg = FLASH__u32Frequency();
        if(0UL != u32FlashFreqReg)
        {
            uptrAddressArg &= ~1U;
            u16BlockSize = FLASH__u16GetBlockSize();
            u16BlockMask = u16BlockSize;
            u16BlockMask -= 1U;
            uptrFlashStartAddress = pstSegmentCallback->uptrGetStartAddress();
            uptrFlashEndAddress = pstSegmentCallback->uptrGetEndAddress();
            if((uptrAddressArg >= uptrFlashStartAddress) && (uptrAddressArg <= uptrFlashEndAddress))
            {
                enStatusReg = FLASH_enSTATUS_OK;
                enWDTEnableReg = WDT__enGetEnable();
                u16StatusRegister = _get_interrupt_state();
                enWDTModeReg = WDT__enGetMode();
                if(WDT_enMODE_WDT == enWDTModeReg)
                {
                    WDT__vSetEnable(WDT_enENABLE_STOP);
                }
                _DINT();
                do
                {
                    enBusyStateReg = FLASH__enGetBusyState();
                }while(FLASH_enBUSY_NOBUSY != enBusyStateReg);
                FLASH__vUnlock();
                FLASH__u16WriteBlockProcess_RAM(pu16DataArg, u16DataCountArg,
                                                uptrAddressArg, uptrFlashEndAddress,
                                                u16BlockMask);
                FLASH__vLock();
                WDT__vSetEnable(enWDTEnableReg);
                _set_interrupt_state(u16StatusRegister);
            }
        }
    }
    return (enStatusReg);
}


uint16_t FLASH__u16WriteBlockProcess_RAM(uint16_t* pu16DataArg,
                                       uint16_t u16DataCountArg,
                                       uintptr_t uptrAddressArg,
                                       uintptr_t uptrFlashEndAddressArg,
                                       uint16_t u16BlockMaskArg)
{
    uint16_t u16BusyStateReg = 0U;
    uint16_t u16ReadyStateReg = 0U;
    uint16_t u16AddressMask = 0U;
    uint16_t* pu16DataReg = (uint16_t*) 0U;
    pu16DataReg = ((uint16_t*) uptrAddressArg);
    while((0UL != u16DataCountArg) &&  (uptrFlashEndAddressArg >= (uintptr_t) pu16DataReg))
    {
        FLASH_CTL1_R = FLASH_CTL1_R_KEY_WRITE | FLASH_CTL1_R_WRITE_BLOCK;
        do
        {
            *pu16DataReg = *pu16DataArg;
            do
            {
                u16ReadyStateReg = FLASH_CTL3_R;
                u16ReadyStateReg &= FLASH_CTL3_R_WAIT_MASK;
            }while(FLASH_CTL3_R_WAIT_NOREADY == u16ReadyStateReg);
            pu16DataReg += 1U;
            pu16DataArg += 1U;
            u16DataCountArg--;
            u16AddressMask = (uintptr_t) pu16DataReg;
            u16AddressMask &= u16BlockMaskArg;
        }while((0UL != u16DataCountArg) &&
            (uptrFlashEndAddressArg >= (uintptr_t) pu16DataReg) &&
            (0UL != u16AddressMask));

        FLASH_CTL1_R = FLASH_CTL1_R_KEY_WRITE | FLASH_CTL1_R_WRITE_SINGLE;
        do
        {
            u16BusyStateReg = FLASH_CTL3_R;
            u16BusyStateReg &= FLASH_CTL3_R_BUSY_MASK;
        }while (FLASH_CTL3_R_BUSY_NOBUSY != u16BusyStateReg);
    }
    FLASH_CTL1_R = FLASH_CTL1_R_KEY_WRITE;
    return (u16DataCountArg);
}



