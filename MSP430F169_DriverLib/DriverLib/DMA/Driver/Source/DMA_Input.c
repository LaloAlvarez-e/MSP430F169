/**
 *
 * @file DMA_Input.c
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
#include "DriverLib/DMA/Driver/Header/DMA_Input.h"

#include "DriverLib/DMA/Driver/Intrinsics/DMA_Intrinsics.h"
#include "DriverLib/DMA/Peripheral/DMA_Peripheral.h"

DMA_nPIN DMA__enGetInput(DMA_nPORT enPortArg,
                               DMA_nPIN enPinMask)
{
    DMA_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = PORT_IN_OFFSET;
    pstRegisterData.u8Value = (uint8_t) DMA_enPIN_NONE;
    pstRegisterData.u8Mask = (uint8_t) enPinMask;
    pstRegisterData.u8Shift = PORT_IN_R_PIN0_BIT;
    (void) DMA__u8ReadRegister(enPortArg, &pstRegisterData);
    return ((DMA_nPIN) pstRegisterData.u8Value);
}

DMA_nLEVEL DMA__enGetInputByNumber(DMA_nPORT enPortArg,
                                       DMA_nPIN_NUMBER enPinNumber)
{
    DMA_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = PORT_IN_OFFSET;
    pstRegisterData.u8Value = (uint8_t) DMA_enLEVEL_LOW;
    pstRegisterData.u8Mask = PORT_IN_PIN0_MASK;
    pstRegisterData.u8Shift = (uint8_t) enPinNumber;
    (void) DMA__u8ReadRegister(enPortArg, &pstRegisterData);
    return ((DMA_nLEVEL) pstRegisterData.u8Value);
}



