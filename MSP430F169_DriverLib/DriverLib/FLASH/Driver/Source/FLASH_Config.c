/**
 *
 * @file FLASH_Config.c
 * @copyright
 * @verbatim InDeviceMex 2021 @u16wverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @u16wverbatim
 *
 * @version
 * @verbatim 1.0 @u16wverbatim
 *
 * @date
 * @verbatim 26 feb. 2022 @u16wverbatim
 *
 * @author
 * @verbatim InDeviceMex @u16wverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 26 feb. 2022     InDeviceMex    1.0         initial Version@u16wverbatim
 */
#include "DriverLib/FLASH/Driver/Header/FLASH_Config.h"

#include "DriverLib/FLASH/Driver/Intrinsics/FLASH_Intrinsics.h"
#include "DriverLib/FLASH/Peripheral/FLASH_Peripheral.h"
#include "DriverLib/MCU/MCU.h"


void FLASH__vSetConfig(FLASH_Config_t* pstConfig)
{
    FLASH_Register16Bits_t pstRegisterData = {0UL};
    uint16_t u16EnableReg = 0U;
    FLASH_nINT_ENABLE enIntEnable = FLASH_enINT_ENABLE_DIS;
    uint16_t u16Mode = 0U;
    uint16_t u16Clock = 0U;
    uint16_t u16Interval = 0U;
    uint16_t u16Reg = 0U;
    if(0UL != (uintptr_t) pstConfig)
    {
        u16EnableReg = (uint16_t) (pstConfig->enEnable);
        u16EnableReg <<= FLASH_CTL_R_HOLD_BIT;

        u16Mode = (uint16_t) (pstConfig->enMode);
        u16Mode <<= FLASH_CTL_R_TMSEL_BIT;

        u16Clock = (uint16_t) (pstConfig->enClock);
        u16Clock <<= FLASH_CTL_R_SSEL_BIT;

        u16Interval = (uint16_t) (pstConfig->enInterval);
        u16Interval <<= FLASH_CTL_R_IS_BIT;
        u16Reg = FLASH_CTL_R_PW_WRITE;
        u16Reg |= FLASH_CTL_R_CNTCL_CLEAR;
        u16Reg |= u16EnableReg;
        u16Reg |= u16Mode;
        u16Reg |= u16Clock;
        u16Reg |= u16Interval;

        pstRegisterData.uptrAddress = FLASH_CTL_OFFSET;
        pstRegisterData.u16Value = u16Reg;
        pstRegisterData.u16Mask = 0xFFFFUL;
        pstRegisterData.u8Shift = 0U;


        enIntEnable = pstConfig->enIntEnable;

        FLASH__vWriteRegister_16bits(&pstRegisterData);
        FLASH__vClearInterruptSource();
        FLASH__vSetEnableInterruptSource(enIntEnable);
    }
}

