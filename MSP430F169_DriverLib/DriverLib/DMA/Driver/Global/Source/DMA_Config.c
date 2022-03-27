/**
 *
 * @file DMA_Config.c
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
 * @verbatim 27 mar. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 27 mar. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <DriverLib/DMA/Driver/Global/Header/DMA_Config.h>


#include <DriverLib/DMA/Driver/Global/Header/DMA_NMI.h>
#include <DriverLib/DMA/Driver/Global/Header/DMA_Fetch.h>
#include <DriverLib/DMA/Driver/Global/Header/DMA_Priority.h>

#include "DriverLib/DMA/Driver/Intrinsics/DMA_Intrinsics.h"
#include "DriverLib/DMA/Peripheral/DMA_Peripheral.h"

void DMA__vSetConfig(DMA_Config_t* pstConfigArg)
{
    DMA_CTL1_t stConfigReg = {0};
    DMA_Register_t pstRegisterData = {0UL};
    if(0UL != (uintptr_t) pstConfigArg)
    {
        stConfigReg.DMAONFETCH = (uint16_t) pstConfigArg->enFetchMode;
        stConfigReg.ENNMI = (uint16_t) pstConfigArg->enNmiStop;
        stConfigReg.ROUNDROBIN = (uint16_t) pstConfigArg->enPriorityMode;

        pstRegisterData.uptrAddress = DMA_CTL1_OFFSET;
        pstRegisterData.u16Value = (*(uint16_t*) &stConfigReg);
        pstRegisterData.u16Mask = 0xFFFFU;
        pstRegisterData.u8Shift = 0U;
        DMA__vWriteRegister(&pstRegisterData);
    }
}


void DMA__vGetConfig(DMA_Config_t* pstConfigArg)
{
    if(0UL != (uintptr_t) pstConfigArg)
    {
        pstConfigArg->enFetchMode = DMA__enGetFetchMode();
        pstConfigArg->enNmiStop = DMA__enGetNMITranferStop();
        pstConfigArg->enPriorityMode = DMA__enGetPriorityMode();
    }
}



