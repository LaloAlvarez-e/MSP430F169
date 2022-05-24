/**
 *
 * @file Graphics_ClearSection.h
 * @copyright
 * @verbatim InDeviceMex 2020 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 19 feb. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 19 feb. 2021     vyldram    1.0         initial Version@endverbatim
 */
#ifndef XUTILS_GRAPHICS_XHEADER_GRAPHICS_CLEARSECTION_H_
#define XUTILS_GRAPHICS_XHEADER_GRAPHICS_CLEARSECTION_H_

#include <xUtils/Graphics/Common/Graphics_Common.h>

void Graphics__vClearSection (void (*pvfCallback)(Graphics_Layer_t* restrict pstLayerArg, Graphics_DIMENSIONS_t stDimensionsArg, uint32_t  u32Color), Graphics_Layer_t* restrict pstLayerArg, Graphics_DIMENSIONS_t stDimensionsArg, uint32_t  u32Color);

#endif /* XUTILS_GRAPHICS_XHEADER_GRAPHICS_CLEARSECTION_H_ */
