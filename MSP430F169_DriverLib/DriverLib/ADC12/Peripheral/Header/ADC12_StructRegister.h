/**
 *
 * @file ADC12_StructRegister.h
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

#ifndef ADC12_PERIPHERAL_HEADER_ADC12_STRUCTREGISTER_H_
#define ADC12_PERIPHERAL_HEADER_ADC12_STRUCTREGISTER_H_

typedef volatile struct
{
    volatile unsigned short SC : 1;
    volatile unsigned short ENC : 1;
    volatile unsigned short TOVIE : 1;
    volatile unsigned short OVIE : 1;
    volatile unsigned short ON : 1;
    volatile unsigned short REFON : 1;
    volatile unsigned short REF2_5V : 1;
    volatile unsigned short MSC : 1;
    volatile unsigned short SHT0 : 4;
    volatile unsigned short SHT1 : 4;
}ADC12_CTL0_t;

typedef volatile struct
{
    volatile unsigned short BUSY : 1;
    volatile unsigned short CONSEQ : 2;
    volatile unsigned short SSEL : 2;
    volatile unsigned short DIV : 3;
    volatile unsigned short ISSH : 1;
    volatile unsigned short SHP : 1;
    volatile unsigned short SHS : 2;
    volatile unsigned short CSTARTADD : 4;
}ADC12_CTL1_t;

typedef volatile struct
{
    volatile unsigned short IE0 : 1;
    volatile unsigned short IE1 : 1;
    volatile unsigned short IE2 : 1;
    volatile unsigned short IE3 : 1;
    volatile unsigned short IE4 : 1;
    volatile unsigned short IE5 : 1;
    volatile unsigned short IE6 : 1;
    volatile unsigned short IE7 : 1;
    volatile unsigned short IE8 : 1;
    volatile unsigned short IE9 : 1;
    volatile unsigned short IE10 : 1;
    volatile unsigned short IE11 : 1;
    volatile unsigned short IE12 : 1;
    volatile unsigned short IE13 : 1;
    volatile unsigned short IE14 : 1;
    volatile unsigned short IE15 : 1;
}ADC12_IE_t;

typedef volatile struct
{
    volatile unsigned short IFG0 : 1;
    volatile unsigned short IFG1 : 1;
    volatile unsigned short IFG2 : 1;
    volatile unsigned short IFG3 : 1;
    volatile unsigned short IFG4 : 1;
    volatile unsigned short IFG5 : 1;
    volatile unsigned short IFG6 : 1;
    volatile unsigned short IFG7 : 1;
    volatile unsigned short IFG8 : 1;
    volatile unsigned short IFG9 : 1;
    volatile unsigned short IFG10 : 1;
    volatile unsigned short IFG11 : 1;
    volatile unsigned short IFG12 : 1;
    volatile unsigned short IFG13 : 1;
    volatile unsigned short IFG14 : 1;
    volatile unsigned short IFG15 : 1;
}ADC12_IFG_t;

typedef volatile struct
{
    volatile unsigned short IV : 16;
}ADC12_IV_t;

typedef volatile struct
{
    volatile unsigned short MEM : 16;
}ADC12_CH_MEM_t;

typedef volatile struct
{
    volatile unsigned char INCH : 4;
    volatile unsigned char SREFP : 2;
    volatile unsigned char SREFN : 1;
    volatile unsigned char EOS : 1;
}ADC12_CH_CTL_t;

#endif /* ADC12_PERIPHERAL_HEADER_ADC12_STRUCTREGISTER_H_ */
