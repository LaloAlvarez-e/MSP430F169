/**
 *
 * @file Conversion_Enum.h
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
 * @verbatim 17 jul. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 17 jul. 2020     vyldram    1.0         initial Version@endverbatim
 */
#ifndef XUTILS_CONVERSION_XHEADER_CONVERSION_ENUM_H_
#define XUTILS_CONVERSION_XHEADER_CONVERSION_ENUM_H_

typedef enum
{
    CONV_enSTATUS_OK = 0U,
    CONV_enSTATUS_ERROR = 1U,
    CONV_enNAN = 0xFFFFFFFFU,
}CONV_nSTATUS;

typedef enum
{
    CONV_enSIGNED_POSITIVE = 0U,
    CONV_enSIGNED_NEGATIVE = 1U,
}CONV_nSIGNED;

typedef enum
{
    CONV_enBACKSPACE_OK = 0U,
    CONV_enBACKSPACE_NO = 1U,
}CONV_nBACKSPACE;

typedef enum
{
    CONV_enDIGIT_OK = 0U,
    CONV_enDIGIT_NO = 1U,
}CONV_nDIGIT;

typedef enum
{
    CONV_enNEGATIVE_SIGN_OK = 0U,
    CONV_enNEGATIVE_SIGN_NO = 1U,
}CONV_nNEGATIVE_SIGN;

typedef enum
{
    CONV_enPOSITIVE_SIGN_OK = 0U,
    CONV_enPOSITIVE_SIGN_NO = 1U,
}CONV_nPOSITIVE_SIGN;

typedef enum
{
    CONV_enNEWLINE_OK = 0U,
    CONV_enNEWLINE_NO = 1U,
}CONV_nNEWLINE;

typedef enum
{
    CONV_enNEWLINERETURN_OK = 0U,
    CONV_enNEWLINERETURN_NO = 1U,
}CONV_nNEWLINERETURN;

typedef enum
{
    CONV_enNULL_OK = 0U,
    CONV_enNULL_NO = 1U,
}CONV_nNULL;

typedef enum
{
    CONV_enRETURN_OK = 0U,
    CONV_enRETURN_NO = 1U,
}CONV_nRETURN;

typedef enum
{
    CONV_enSCAPE_OK = 0U,
    CONV_enSCAPE_NO = 1U,
}CONV_nSCAPE;

#endif /* XUTILS_CONVERSION_XHEADER_CONVERSION_ENUM_H_ */
