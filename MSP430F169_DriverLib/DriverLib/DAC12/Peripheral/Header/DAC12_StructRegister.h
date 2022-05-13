/**
 *
 * @file DAC12_StructRegister.h
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
 * @verbatim 5 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 5 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DAC12_PERIPHERAL_HEADER_DAC12_STRUCTREGISTER_H_
#define DAC12_PERIPHERAL_HEADER_DAC12_STRUCTREGISTER_H_

typedef volatile struct
{
    volatile unsigned short DATA : 16;
}DAC12_CH_DAT_t;

typedef volatile struct
{
    volatile unsigned short GRP : 1;
    volatile unsigned short ENC : 1;
    volatile unsigned short IFG : 1;
    volatile unsigned short IE : 1;
    volatile unsigned short DF : 1;
    volatile unsigned short AMP : 3;
    volatile unsigned short IR : 1;
    volatile unsigned short CALON : 1;
    volatile unsigned short LSEL : 2;
    volatile unsigned short RES : 1;
    volatile unsigned short SREF : 2;
    const unsigned short reserved0 : 1;
}DAC12_CH_CTL_t;

#endif /* DAC12_PERIPHERAL_HEADER_DAC12_STRUCTREGISTER_H_ */
