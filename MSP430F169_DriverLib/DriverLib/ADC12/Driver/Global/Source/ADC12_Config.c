/**
 *
 * @file ADC12_Config.c
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
#include <DriverLib/ADC12/Driver/Global/Header/ADC12_Config.h>


#include <DriverLib/ADC12/Driver/Global/Header/ADC12_NMI.h>
#include <DriverLib/ADC12/Driver/Global/Header/ADC12_Fetch.h>
#include <DriverLib/ADC12/Driver/Global/Header/ADC12_Priority.h>

#include "DriverLib/ADC12/Driver/Intrinsics/ADC12_Intrinsics.h"
#include "DriverLib/ADC12/Peripheral/ADC12_Peripheral.h"

void ADC12__vSetConfig(ADC12_Config_t* pstConfigArg)
{
    ADC12_CTL1_t stConfigReg = {0};
    ADC12_Register16Bits_t pstRegisterData;
    if(0UL != (uintptr_t) pstConfigArg)
    {
        stConfigReg.ADC12ONFETCH = (uint16_t) pstConfigArg->enFetchMode;
        stConfigReg.ENNMI = (uint16_t) pstConfigArg->enNmiStop;
        stConfigReg.ROUNDROBIN = (uint16_t) pstConfigArg->enPriorityMode;

        pstRegisterData.uptrAddress = ADC12_CTL1_OFFSET;
        pstRegisterData.u16Value = (*(uint16_t*) &stConfigReg);
        pstRegisterData.u16Mask = 0xFFFFU;
        pstRegisterData.u8Shift = 0U;
        ADC12__vWriteRegister(&pstRegisterData);
    }
}


void ADC12__vGetConfig(ADC12_Config_t* pstConfigArg)
{
    if(0UL != (uintptr_t) pstConfigArg)
    {
        pstConfigArg->enFetchMode = ADC12__enGetFetchMode();
        pstConfigArg->enNmiStop = ADC12__enGetNMITranferStop();
        pstConfigArg->enPriorityMode = ADC12__enGetPriorityMode();
    }
}



