/**
 *
 * @file DMA_Selection.c
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
 * @verbatim 10 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 10 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/DMA/Driver/Header/DMA_Selection.h"

#include "DriverLib/DMA/Driver/Intrinsics/DMA_Intrinsics.h"
#include "DriverLib/DMA/Peripheral/DMA_Peripheral.h"

void DMA__vSetSelection(DMA_nPORT enPortArg,
                         DMA_nPIN enPinMask,
                         DMA_nSEL enSelection)
{
    DMA_Register_t pstRegisterData = {0UL};
    uint8_t u8Value = 0U;
    if(DMA_enSEL_IO != enSelection)
    {
        u8Value = (uint8_t) enPinMask;
    }
    pstRegisterData.uptrAddress = PORT_SEL_OFFSET;
    pstRegisterData.u8Value = u8Value;
    pstRegisterData.u8Mask = (uint8_t) enPinMask;
    pstRegisterData.u8Shift = PORT_SEL_R_PIN0_BIT;
    DMA__vWriteRegister(enPortArg,
                         &pstRegisterData);
}


void DMA__vSetSelectionByNumber(DMA_nPORT enPortArg,
                             DMA_nPIN_NUMBER enPinNumber,
                             DMA_nSEL enSelection)
{
    DMA_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = PORT_SEL_OFFSET;
    pstRegisterData.u8Value = (uint8_t) enSelection;
    pstRegisterData.u8Mask = PORT_SEL_PIN0_MASK;
    pstRegisterData.u8Shift = (uint8_t) enPinNumber;
    DMA__vWriteRegister(enPortArg,
                         &pstRegisterData);
}

DMA_nPIN DMA__enGetSelection(DMA_nPORT enPortArg,
                               DMA_nPIN enPinMask)
{
    DMA_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = PORT_SEL_OFFSET;
    pstRegisterData.u8Value = (uint8_t) DMA_enPIN_NONE;
    pstRegisterData.u8Mask = (uint8_t) enPinMask;
    pstRegisterData.u8Shift = PORT_SEL_R_PIN0_BIT;
    (void) DMA__u8ReadRegister(enPortArg,&pstRegisterData);
    return ((DMA_nPIN) pstRegisterData.u8Value);
}

DMA_nSEL DMA__enGetSelectionByNumber(DMA_nPORT enPortArg,
                                       DMA_nPIN_NUMBER enPinNumber)
{
    DMA_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = PORT_SEL_OFFSET;
    pstRegisterData.u8Value = (uint8_t) DMA_enSEL_IO;
    pstRegisterData.u8Mask = PORT_SEL_PIN0_MASK;
    pstRegisterData.u8Shift = (uint8_t) enPinNumber;
    (void) DMA__u8ReadRegister(enPortArg, &pstRegisterData);
    return ((DMA_nSEL) pstRegisterData.u8Value);
}



