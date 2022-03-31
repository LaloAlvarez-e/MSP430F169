/**
 *
 * @file Segments_Global.h
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
 * @verbatim 16 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 16 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef MODULES_SEGMENTS_HEADER_SEGMENTS_GLOBAL_H_
#define MODULES_SEGMENTS_HEADER_SEGMENTS_GLOBAL_H_

#include "Modules/Segments/Header/Segments_Defines.h"


GPIO_nPORT SEGMENTS__enGetDigitPort(SEGMENTS_nDIGIT enDigitNumber);
GPIO_nPORT SEGMENTS__enGetSegPort(SEGMENTS_nSEG enSegNumber);
GPIO_nPIN_NUMBER SEGMENTS__enGetDigitPin(SEGMENTS_nDIGIT enDigitNumber);
GPIO_nPIN_NUMBER SEGMENTS__enGetSegPin(SEGMENTS_nSEG enSegNumber);


#endif /* MODULES_SEGMENTS_HEADER_SEGMENTS_GLOBAL_H_ */
