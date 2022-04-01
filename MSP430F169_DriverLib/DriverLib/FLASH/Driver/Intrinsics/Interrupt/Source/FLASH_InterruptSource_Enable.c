/**
 *
 * @file FLASH_InterruptSource_Enable.c
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
#include "DriverLib/FLASH/Driver/Intrinsics/Interrupt/Header/FLASH_InterruptSource_Enable.h"

#include "DriverLib/FLASH/Driver/Intrinsics/Primitives/FLASH_Primitives.h"
#include "DriverLib/FLASH/Peripheral/FLASH_Peripheral.h"

void FLASH__vSetEnableInterruptSource(FLASH_nINT_ENABLE enState)
{
    FLASH_Register8Bits_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = FLASH_IE1_OFFSET;
    pstRegisterData.u8Value = (uint8_t) enState;
    pstRegisterData.u8Mask = FLASH_IE1_ACCVIE_MASK;
    pstRegisterData.u8Shift = FLASH_IE1_R_ACCVIE_BIT;

    FLASH__vWriteRegister_8bits(&pstRegisterData);
}

void FLASH__vEnaInterruptSource(void)
{
    FLASH__vSetEnableInterruptSource(FLASH_enINT_ENABLE_ENA);
}

void FLASH__vDisInterruptSource(void)
{
    FLASH__vSetEnableInterruptSource(FLASH_enINT_ENABLE_DIS);
}

FLASH_nINT_ENABLE FLASH__enGetEnableInterruptSource(void)
{
    FLASH_Register8Bits_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = FLASH_IE1_OFFSET;
    pstRegisterData.u8Value = (uint8_t) FLASH_enINT_ENABLE_DIS;
    pstRegisterData.u8Mask = FLASH_IE1_ACCVIE_MASK;
    pstRegisterData.u8Shift = FLASH_IE1_R_ACCVIE_BIT;

    (void) FLASH__u8ReadRegister(&pstRegisterData);
    return ((FLASH_nINT_ENABLE) pstRegisterData.u8Value);
}

void FLASH__vSetEnableInterruptSource_RAM(FLASH_nINT_ENABLE enState)
{
    FLASH_Register8Bits_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = FLASH_IE1_OFFSET;
    pstRegisterData.u8Value = (uint8_t) enState;
    pstRegisterData.u8Mask = FLASH_IE1_ACCVIE_MASK;
    pstRegisterData.u8Shift = FLASH_IE1_R_ACCVIE_BIT;

    FLASH__vWriteRegister_8bits_RAM(&pstRegisterData);
}

void FLASH__vEnaInterruptSource_RAM(void)
{
    FLASH__vSetEnableInterruptSource_RAM(FLASH_enINT_ENABLE_ENA);
}

void FLASH__vDisInterruptSource_RAM(void)
{
    FLASH__vSetEnableInterruptSource_RAM(FLASH_enINT_ENABLE_DIS);
}

FLASH_nINT_ENABLE FLASH__enGetEnableInterruptSource_RAM(void)
{
    FLASH_Register8Bits_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = FLASH_IE1_OFFSET;
    pstRegisterData.u8Value = (uint8_t) FLASH_enINT_ENABLE_DIS;
    pstRegisterData.u8Mask = FLASH_IE1_ACCVIE_MASK;
    pstRegisterData.u8Shift = FLASH_IE1_R_ACCVIE_BIT;

    (void) FLASH__u8ReadRegister_RAM(&pstRegisterData);
    return ((FLASH_nINT_ENABLE) pstRegisterData.u8Value);
}

