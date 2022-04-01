/**
 *
 * @file FLASH_StructRegister.h
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
 * @verbatim 24 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 24 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_FLASH_PERIPHERAL_HEADER_FLASH_STRUCTREGISTER_H_
#define DRIVERLIB_FLASH_PERIPHERAL_HEADER_FLASH_STRUCTREGISTER_H_

typedef volatile struct
{
    const unsigned short reserved1 : 1;
    volatile unsigned short ERASE : 2;
    const unsigned short reserved2 : 3;
    volatile unsigned short WRT : 1;
    volatile unsigned short BLKWRT : 1;
    volatile unsigned short KEY : 8;
}FLASH_CTL1_t;

typedef volatile struct
{
    volatile unsigned short FN : 6;
    volatile unsigned short SSEL : 2;
    volatile unsigned short KEY : 8;
}FLASH_CTL2_t;

typedef volatile struct
{
    volatile const unsigned short BUSY : 1;
    volatile unsigned short KEYV : 1;
    volatile unsigned short ACCVIFG : 1;
    volatile const unsigned short WAIT : 1;
    volatile unsigned short LOCK : 1;
    volatile unsigned short EMEX : 1;
    const unsigned short reserved1 : 2;
    volatile unsigned short KEY : 8;
}FLASH_CTL3_t;

typedef volatile struct
{
    const unsigned char reserved1 : 5;
    volatile unsigned char ACCVIE : 1;
    const unsigned char reserved2 : 2;
}FLASH_IE1_t;

#endif /* DRIVERLIB_FLASH_PERIPHERAL_HEADER_FLASH_STRUCTREGISTER_H_ */
