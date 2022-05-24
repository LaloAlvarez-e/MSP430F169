/**
 *
 * @file Graphics_Defines.h
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
#ifndef XUTILS_GRAPHICS_COMMON_XHEADER_GRAPHICS_DEFINES_H_
#define XUTILS_GRAPHICS_COMMON_XHEADER_GRAPHICS_DEFINES_H_

#include <xUtils/Graphics/Common/xHeader/Graphics_Enum.h>
#include <xUtils/Font/Font.h>

typedef volatile struct
{
    uint32_t u32CoordX_Initial;
    uint32_t u32CoordY_Initial;
    uint32_t u32CoordX [4U];
    uint32_t u32CoordY [4U];
    uint32_t u32Radius [3U];
    uint32_t u32Radius_Initial;
    uint32_t u32Width;
    uint32_t u32Height;
    uint32_t u32WidthTotal;
    uint32_t u32HeightTotal;
}Graphics_DIMENSIONS_t;

typedef struct GraphicsLayer_t Graphics_Layer_t;
struct GraphicsLayer_t
{
    FONT_t* pstFontType;
    char* pcString;

    uint32_t u32WidthTotal;
    uint32_t u32HeightTotal;
    uint32_t u32Width;
    uint32_t u32Height;
    /*
     * ToDo: This typedef will be increase in parameters when the system can create buffers for layers
     * */
} ;


#endif /* XUTILS_GRAPHICS_COMMON_XHEADER_GRAPHICS_DEFINES_H_ */
