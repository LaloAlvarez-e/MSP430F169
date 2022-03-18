/**
 *
 * @file DMA_Direction.c
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
 * @verbatim 9 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 9 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/DMA/Driver/Header/DMA_Direction.h"

#include "DriverLib/DMA/Driver/Intrinsics/DMA_Intrinsics.h"
#include "DriverLib/DMA/Peripheral/DMA_Peripheral.h"

void DMA__vSetDirection(DMA_nPORT enPortArg,
                         DMA_nPIN enPinMask,
                         DMA_nDIR enDirection)
{
    DMA_Register_t pstRegisterData = {0UL};
    uint8_t u8Value = 0U;
    if(DMA_enDIR_INPUT != enDirection)
    {
        u8Value = (uint8_t) enPinMask;
    }
    pstRegisterData.uptrAddress = PORT_DIR_OFFSET;
    pstRegisterData.u8Value = u8Value;
    pstRegisterData.u8Mask = (uint8_t) enPinMask;
    pstRegisterData.u8Shift = PORT_DIR_R_PIN0_BIT;
    DMA__vWriteRegister(enPortArg,
                         &pstRegisterData);
}


void DMA__vSetDirectionByNumber(DMA_nPORT enPortArg,
                                 DMA_nPIN_NUMBER enPinNumber,
                                 DMA_nDIR enDirection)
{
    DMA_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = PORT_DIR_OFFSET;
    pstRegisterData.u8Value = (uint8_t) enDirection;
    pstRegisterData.u8Mask = PORT_DIR_PIN0_MASK;
    pstRegisterData.u8Shift = (uint8_t) enPinNumber;
    DMA__vWriteRegister(enPortArg,
                         &pstRegisterData);
}

DMA_nPIN DMA__enGetDirection(DMA_nPORT enPortArg,
                               DMA_nPIN enPinMask)
{
    DMA_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = PORT_DIR_OFFSET;
    pstRegisterData.u8Value = (uint8_t) DMA_enPIN_NONE;
    pstRegisterData.u8Mask = (uint8_t) enPinMask;
    pstRegisterData.u8Shift = PORT_DIR_R_PIN0_BIT;
    (void) DMA__u8ReadRegister(enPortArg, &pstRegisterData);
    return ((DMA_nPIN) pstRegisterData.u8Value);
}

DMA_nDIR DMA__enGetDirectionByNumber(DMA_nPORT enPortArg,
                                       DMA_nPIN_NUMBER enPinNumber)
{
    DMA_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = PORT_DIR_OFFSET;
    pstRegisterData.u8Value = (uint8_t) DMA_enDIR_INPUT;
    pstRegisterData.u8Mask = PORT_DIR_PIN0_MASK;
    pstRegisterData.u8Shift = (uint8_t) enPinNumber;
    (void) DMA__u8ReadRegister(enPortArg, &pstRegisterData);
    return ((DMA_nDIR) pstRegisterData.u8Value);
}

