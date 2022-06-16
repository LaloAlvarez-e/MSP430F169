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
                                 void* pvDataArg,
                                 uint16_t* pu16DataCountArg,
                                 uintptr_t uptrAddressArg,
                                 FLASH_nWORDSIZE enWordSize)
{
    FLASH_nBUSY enBusyStateReg;
    WDT_nENABLE enWDTEnableReg;
    WDT_nMODE enWDTModeReg;
    uint32_t u32FlashFreqReg;
    uint16_t u16StatusRegister;
    uint16_t u16Temp;
    uintptr_t uptrFlashStartAddress;
    uintptr_t uptrFlashEndAddress;
    FLASH_nSTATUS enStatusReg;

    enStatusReg = FLASH_enSTATUS_ERROR;
    if(0UL != (uintptr_t) pstSegmentCallback)
    {
        u32FlashFreqReg = FLASH__u32Frequency();
        if(0UL != u32FlashFreqReg)
        {
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
                if((3U == u8ModeArg) &&
                   (0UL != (uintptr_t) pu16DataCountArg) &&
                   (0UL != (uintptr_t) pvDataArg))
                {
                    uint16_t u16BlockSize = 0U;
                    uint16_t u16BlockMask = 0U;
                    u16BlockSize = FLASH__u16GetBlockSize();
                    u16BlockMask = u16BlockSize;
                    u16BlockMask -= 1U;
                    FLASH__u16WriteBlockProcess_RAM(pvDataArg, pu16DataCountArg,
                                                    uptrAddressArg, uptrFlashEndAddress,
                                                    u16BlockMask, enWordSize);
                    if(0UL != *pu16DataCountArg)
                    {
                        enStatusReg = FLASH_enSTATUS_ERROR;
                    }
                }
                else if(0U != u8ModeArg)
                {
                    uint16_t* pu16DataReg = (uint16_t*) 0U;
                    uint8_t* pu8DataReg = (uint8_t*) 0U;
                    pstSegmentCallback->vStartProcess(u8ModeArg);
                    switch(enWordSize)
                    {
                    case FLASH_enWORDSIZE_BYTE:
                        pu8DataReg = ((uint8_t*) uptrAddressArg);
                        u16Temp =  (uint16_t) pvDataArg;
                        *pu8DataReg = (uint8_t) u16Temp;
                        break;
                    case FLASH_enWORDSIZE_WORD:
                        uptrAddressArg &= ~1U;
                        pu16DataReg = ((uint16_t*) uptrAddressArg);
                        *pu16DataReg = (uint16_t) pvDataArg;
                        break;
                    default:
                        break;
                    }
                }
                FLASH__vLock();
                WDT__vSetEnable(enWDTEnableReg);
                _set_interrupt_state(u16StatusRegister);
            }
        }
    }
    return (enStatusReg);
}



uint16_t FLASH__u16WriteBlockProcess_RAM(void* pvDataArg,
                                       uint16_t* pu16DataCountArg,
                                       uintptr_t uptrAddressArg,
                                       uintptr_t uptrFlashEndAddressArg,
                                       uint16_t u16BlockMaskArg,
                                       FLASH_nWORDSIZE enWordSize)
{
    uint16_t u16BusyStateReg;
    uint16_t u16ReadyStateReg;
    uint16_t u16AddressMask;
    uint16_t* pu16DataReg;
    uint8_t* pu8DataReg;
    uint16_t* pu16DataInReg;
    uint8_t* pu8DataInReg;
    uint16_t u16DataCountReg;
    uint16_t u16DataCountWriteReg = 0U;
    if((0U != (uintptr_t) pvDataArg) && (0UL != (uintptr_t) pu16DataCountArg))
    {
        u16DataCountReg = *pu16DataCountArg;
        switch(enWordSize)
        {
        case FLASH_enWORDSIZE_BYTE:
            pu8DataReg = ((uint8_t*) uptrAddressArg);
            pu8DataInReg = ((uint8_t*) pvDataArg);
            while((0UL != u16DataCountReg) &&  (uptrFlashEndAddressArg >= (uintptr_t) pu8DataReg))
            {
                FLASH_CTL1_R = FLASH_CTL1_R_KEY_WRITE | FLASH_CTL1_R_WRITE_BLOCK;
                do
                {
                    *pu8DataReg = *pu8DataInReg;
                    do
                    {
                        u16ReadyStateReg = FLASH_CTL3_R;
                        u16ReadyStateReg &= FLASH_CTL3_R_WAIT_MASK;
                    }while(FLASH_CTL3_R_WAIT_NOREADY == u16ReadyStateReg);
                    pu8DataReg += 1U;
                    pu8DataInReg += 1U;
                    u16DataCountReg--;
                    u16AddressMask = (uintptr_t) pu8DataReg;
                    u16AddressMask &= u16BlockMaskArg;
                }while((0UL != u16DataCountReg) &&
                    (uptrFlashEndAddressArg >= (uintptr_t) pu8DataReg) &&
                    (0UL != u16AddressMask));
                FLASH_CTL1_R = FLASH_CTL1_R_KEY_WRITE | FLASH_CTL1_R_WRITE_SINGLE;
                do
                {
                    u16BusyStateReg = FLASH_CTL3_R;
                    u16BusyStateReg &= FLASH_CTL3_R_BUSY_MASK;
                }while (FLASH_CTL3_R_BUSY_NOBUSY != u16BusyStateReg);
            }
            FLASH_CTL1_R = FLASH_CTL1_R_KEY_WRITE;
            u16DataCountWriteReg = *pu16DataCountArg - u16DataCountReg;
            *pu16DataCountArg = u16DataCountReg;
            break;
        case FLASH_enWORDSIZE_WORD:
            uptrAddressArg &= ~1U;
            pu16DataReg = ((uint16_t*) uptrAddressArg);
            pu16DataInReg = ((uint16_t*) pvDataArg);
            while((0UL != u16DataCountReg) &&  (uptrFlashEndAddressArg >= (uintptr_t) pu16DataReg))
            {
                FLASH_CTL1_R = FLASH_CTL1_R_KEY_WRITE | FLASH_CTL1_R_WRITE_BLOCK;
                do
                {
                    *pu16DataReg = *pu16DataInReg;
                    do
                    {
                        u16ReadyStateReg = FLASH_CTL3_R;
                        u16ReadyStateReg &= FLASH_CTL3_R_WAIT_MASK;
                    }while(FLASH_CTL3_R_WAIT_NOREADY == u16ReadyStateReg);
                    pu16DataReg += 1U;
                    pu16DataInReg += 1U;
                    u16DataCountReg--;
                    u16AddressMask = (uintptr_t) pu16DataReg;
                    u16AddressMask &= u16BlockMaskArg;
                }while((0UL != u16DataCountReg) &&
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
            u16DataCountWriteReg = *pu16DataCountArg - u16DataCountReg;
            *pu16DataCountArg = u16DataCountReg;
            break;
        default:
            break;
        }
    }
    return (u16DataCountWriteReg);
}



