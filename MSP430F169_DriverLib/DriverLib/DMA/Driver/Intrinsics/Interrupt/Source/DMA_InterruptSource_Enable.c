/**
 *
 * @file DMA_InterruptSource_Enable.c
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
 * @verbatim 7 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 7 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/DMA/Driver/Intrinsics/Interrupt/Header/DMA_InterruptSource_Enable.h"

#include "DriverLib/DMA/Driver/Intrinsics/Primitives/DMA_Primitives.h"
#include "DriverLib/DMA/Peripheral/DMA_Peripheral.h"

void DMA__vSetEnableInterruptSource(DMA_nPORT enPortArg,
                                     DMA_nPIN enPinMask,
                                     DMA_nINT_ENABLE enState)
{
    DMA_Register_t pstRegisterData = {0UL};
    uint8_t u8Value = 0U;
    if((DMA_enPORT1 == enPortArg) || (DMA_enPORT2 == enPortArg))
    {
        if(DMA_enINT_ENABLE_DIS != enState)
        {
            u8Value = (uint8_t) enPinMask;
        }
        pstRegisterData.uptrAddress = PORT_IE_OFFSET;
        pstRegisterData.u8Value = u8Value;
        pstRegisterData.u8Mask = (uint8_t) enPinMask;
        pstRegisterData.u8Shift = PORT_IE_R_PIN0_BIT;

        DMA__vWriteRegister(enPortArg,
                             &pstRegisterData);
    }
}

void DMA__vEnaInterruptSource(DMA_nPORT enPortArg,
                               DMA_nPIN enPinMask)
{
    DMA__vSetEnableInterruptSource(enPortArg, enPinMask, DMA_enINT_ENABLE_ENA);
}

void DMA__vDisInterruptSource(DMA_nPORT enPortArg,
                               DMA_nPIN enPinMask)
{
    DMA__vSetEnableInterruptSource(enPortArg, enPinMask, DMA_enINT_ENABLE_DIS);
}

void DMA__vSetEnableInterruptSourceByNumber(DMA_nPORT enPortArg,
                                             DMA_nPIN_NUMBER enPinNumber,
                                             DMA_nINT_ENABLE enState)
{
    DMA_Register_t pstRegisterData = {0UL};
    if((DMA_enPORT1 == enPortArg) || (DMA_enPORT2 == enPortArg))
    {
        pstRegisterData.uptrAddress = PORT_IE_OFFSET;
        pstRegisterData.u8Value = (uint8_t) enState;
        pstRegisterData.u8Mask = PORT_IE_PIN0_MASK;
        pstRegisterData.u8Shift = (uint8_t) enPinNumber;
        DMA__vWriteRegister(enPortArg,
                             &pstRegisterData);
    }
}

void DMA__vEnaInterruptSourceByNumber(DMA_nPORT enPortArg,
                                       DMA_nPIN_NUMBER enPinNumber)
{
    DMA__vSetEnableInterruptSourceByNumber(enPortArg, enPinNumber, DMA_enINT_ENABLE_ENA);
}

void DMA__vDisInterruptSourceByNumber(DMA_nPORT enPortArg,
                                       DMA_nPIN_NUMBER enPinNumber)
{
    DMA__vSetEnableInterruptSourceByNumber(enPortArg, enPinNumber, DMA_enINT_ENABLE_DIS);
}


DMA_nPIN DMA__enGetEnableInterruptSource(DMA_nPORT enPortArg,
                                           DMA_nPIN enPinMask)
{
    DMA_Register_t pstRegisterData = {0UL};
    DMA_nPIN enEnable = DMA_enPIN_NONE;
    if((DMA_enPORT1 == enPortArg) || (DMA_enPORT2 == enPortArg))
    {
        pstRegisterData.uptrAddress = PORT_IE_OFFSET;
        pstRegisterData.u8Mask = (uint8_t) enPinMask;
        pstRegisterData.u8Shift = PORT_IE_R_PIN0_BIT;
        enEnable = (DMA_nPIN) DMA__u8ReadRegister(enPortArg,
                                                    &pstRegisterData);
    }
    return (enEnable);
}

DMA_nINT_ENABLE DMA__enGetEnableInterruptSourceByNumber(DMA_nPORT enPortArg,
                                           DMA_nPIN_NUMBER enPinNumber)
{
    DMA_Register_t pstRegisterData = {0UL};
    DMA_nINT_ENABLE enEnable = DMA_enINT_ENABLE_DIS;
    if((DMA_enPORT1 == enPortArg) || (DMA_enPORT2 == enPortArg))
    {
        pstRegisterData.uptrAddress = PORT_IE_OFFSET;
        pstRegisterData.u8Mask = PORT_IE_PIN0_MASK;
        pstRegisterData.u8Shift = PORT_IE_R_PIN0_BIT;
        enEnable = (DMA_nINT_ENABLE) DMA__u8ReadRegister(enPortArg,
                                                    &pstRegisterData);
    }
    return (enEnable);
}
