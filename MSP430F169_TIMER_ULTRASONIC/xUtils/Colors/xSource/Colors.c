/**
 *
 * @file Colors.c
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
 * @verbatim 17 feb. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 17 feb. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xUtils/Colors/Colors.h>

#include <xUtils/Colors/xHeader/Colors_Defines.h>

uint16_t COLORS__u16GetValues(uint32_t u32IndexArg)
{
    const uint16_t COLORS_u16Values[COLORS_MAX] = {
        COLORS_enBLACK,
        COLORS_enBROWN,
        COLORS_enGOLD,
        COLORS_enFUCHSIA,
        COLORS_enDARKGRAY,
        COLORS_enDARKRED,
        COLORS_enANTIQUEWHITE,
        COLORS_enAQUA,
        COLORS_enAQUAMARINE,
        COLORS_enAZURE,
        COLORS_enBEIGE,
        COLORS_enBISQUE,
        COLORS_enBLANCHEDALMOND,
        COLORS_enBLUE,
        COLORS_enBLUEVIOLET,
        COLORS_enALICEBLUE,
        COLORS_enBURLYWOOD,
        COLORS_enCADETBLUE,
        COLORS_enCHARTREUSE,
        COLORS_enCHOCOLATE,
        COLORS_enCORAL,
        COLORS_enCORNFLOWERBLUE,
        COLORS_enCORNSILK,
        COLORS_enCRIMSON,
        COLORS_enCYAN,
        COLORS_enDARKBLUE,
        COLORS_enDARKCYAN,
        COLORS_enDARKGOLDENROD,
        COLORS_enDARKGREEN,
        COLORS_enDARKKHAKI,
        COLORS_enDARKMAGENTA,
        COLORS_enDARKOLIVEGREEN,
        COLORS_enDARKORANGE,
        COLORS_enDARKORCHID,
        COLORS_enDARKSALMON,
        COLORS_enDARKSEAGREEN,
        COLORS_enDARKSLATEBLUE,
        COLORS_enDARKSLATEGRAY,
        COLORS_enDARKTURQUOISE,
        COLORS_enDARKVIOLET,
        COLORS_enDEEPPINK,
        COLORS_enDEEPSKYBLUE,
        COLORS_enDIMGRAY,
        COLORS_enDODGERBLUE,
        COLORS_enFIREBRICK,
        COLORS_enFLORALWHITE,
        COLORS_enFORESTGREEN,
        COLORS_enGAINSBORO,
        COLORS_enGHOSTWHITE,
        COLORS_enGOLDENROD,
        COLORS_enGRAY,
        COLORS_enGREEN,
        COLORS_enGREENYELLOW,
        COLORS_enHONEYDEW,
        COLORS_enHOTPINK,
        COLORS_enINDIANRED,
        COLORS_enINDIGO,
        COLORS_enIVORY,
        COLORS_enKHAKI,
        COLORS_enLAVENDER,
        COLORS_enLAVENDERBLUSH,
        COLORS_enLAWNGREEN,
        COLORS_enLEMONCHIFFON,
        COLORS_enLIGHTBLUE,
        COLORS_enLIGHTCORAL,
        COLORS_enLIGHTCYAN ,
        COLORS_enLIGHTGOLDENRODYELLOW,
        COLORS_enLIGHTGREEN,
        COLORS_enLIGHTGREY,
        COLORS_enLIGHTPINK,
        COLORS_enLIGHTSALMON,
        COLORS_enLIGHTSEAGREEN,
        COLORS_enLIGHTSKYBLUE,
        COLORS_enLIGHTSLATEGRAY,
        COLORS_enLIGHTSTEELBLUE,
        COLORS_enLIGHTYELLOW,
        COLORS_enLIME,
        COLORS_enLIMEGREEN,
        COLORS_enLINEN,
        COLORS_enMAGENTA,
        COLORS_enMAROON,
        COLORS_enMEDIUMAQUAMARINE,
        COLORS_enMEDIUMBLUE,
        COLORS_enMEDIUMORCHID,
        COLORS_enMEDIUMPURPLE,
        COLORS_enMEDIUMSEAGREEN,
        COLORS_enMEDIUMSLATEBLUE,
        COLORS_enMEDIUMSPRINGGREEN,
        COLORS_enMEDIUMTURQUOISE,
        COLORS_enMEDIUMVIOLETRED,
        COLORS_enMIDNIGHTBLUE,
        COLORS_enMINTCREAM,
        COLORS_enMISTYROSE ,
        COLORS_enMOCCASIN,
        COLORS_enNAVAJOWHITE,
        COLORS_enNAVY  ,
        COLORS_enOLDLACE,
        COLORS_enOLIVE,
        COLORS_enOLIVEDRAB,
        COLORS_enORANGE,
        COLORS_enORANGERED,
        COLORS_enORCHID,
        COLORS_enPALEGOLDENROD,
        COLORS_enPALEGREEN,
        COLORS_enPALETURQUOISE,
        COLORS_enPALEVIOLETRED,
        COLORS_enPAPAYAWHIP,
        COLORS_enPEACHPUFF,
        COLORS_enPERU,
        COLORS_enPINK,
        COLORS_enPLUM,
        COLORS_enPOWDERBLUE,
        COLORS_enPURPLE,
        COLORS_enRED,
        COLORS_enROSYBROWN,
        COLORS_enROYALBLUE,
        COLORS_enSADDLEBROWN,
        COLORS_enSALMON,
        COLORS_enSANDYBROWN,
        COLORS_enSEAGREEN,
        COLORS_enSEASHELL ,
        COLORS_enSIENNA,
        COLORS_enSILVER,
        COLORS_enSKYBLUE,
        COLORS_enSLATEBLUE,
        COLORS_enSLATEGRAY,
        COLORS_enSNOW,
        COLORS_enSPRINGGREEN,
        COLORS_enSTEELBLUE,
        COLORS_enTAN ,
        COLORS_enTEAL,
        COLORS_enTHISTLE,
        COLORS_enTOMATO,
        COLORS_enTURQUOISE,
        COLORS_enVIOLET,
        COLORS_enWHEAT,
        COLORS_enWHITE,
        COLORS_enWHITESMOKE,
        COLORS_enYELLOW,
        COLORS_enYELLOWGREEN
    }; /*140*/
    uint16_t u16ValueReg = 0UL;
    u32IndexArg %= COLORS_MAX;
    u16ValueReg = COLORS_u16Values[u32IndexArg];
    return (u16ValueReg);
}

