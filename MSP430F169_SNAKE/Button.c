/**
 *
 * @file Button.c
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
 * @verbatim 17 may. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 17 may. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <Button.h>
#include <DriverLib/DriverLib.h>

static uint16_t Button_u16UpDetection(uintptr_t uptrBlock, uint16_t u16Pin);
static uint16_t Button_u16RightDetection(uintptr_t uptrBlock, uint16_t u16Pin);
static uint16_t Button_u16DownDetection(uintptr_t uptrBlock, uint16_t u16Pin);
static uint16_t Button_u16LeftDetection(uintptr_t uptrBlock, uint16_t u16Pin);

static uint8_t Button_u8RightValue = 0U;
static uint8_t Button_u8LeftValue = 0U;
static uint8_t Button_u8UpValue = 0U;
static uint8_t Button_u8DownValue = 0U;


void Button__vInit(void)
{
    GPIO__vRegisterIRQSourceHandler(GPIO_enPORT1, GPIO_enPIN_NUMBER4, &Button_u16UpDetection);
    GPIO__vRegisterIRQSourceHandler(GPIO_enPORT1, GPIO_enPIN_NUMBER0, &Button_u16RightDetection);
    GPIO__vRegisterIRQSourceHandler(GPIO_enPORT2, GPIO_enPIN_NUMBER0, &Button_u16DownDetection);
    GPIO__vRegisterIRQSourceHandler(GPIO_enPORT2, GPIO_enPIN_NUMBER1, &Button_u16LeftDetection);
    GPIO__vSetConfig(GPIO_enPORT10);
    GPIO__vSetConfig(GPIO_enPORT14);
    GPIO__vSetConfig(GPIO_enPORT20);
    GPIO__vSetConfig(GPIO_enPORT21);

    Button_u8RightValue = GPIO->P1.IN_bits.P0;
    GPIO__vSetInterruptEdgeByNumber(GPIO_enPORT1, GPIO_enPIN_NUMBER0, (GPIO_nINT_EDGE) Button_u8RightValue);
    GPIO__vClearInterruptSourceByNumber(GPIO_enPORT1, GPIO_enPIN_NUMBER0);
    GPIO__vSetEnableInterruptSourceByNumber(GPIO_enPORT1, GPIO_enPIN_NUMBER0, GPIO_enINT_ENABLE_ENA);

    Button_u8UpValue = GPIO->P1.IN_bits.P4;
    GPIO__vSetInterruptEdgeByNumber(GPIO_enPORT1, GPIO_enPIN_NUMBER4, (GPIO_nINT_EDGE) Button_u8UpValue);
    GPIO__vClearInterruptSourceByNumber(GPIO_enPORT1, GPIO_enPIN_NUMBER4);
    GPIO__vSetEnableInterruptSourceByNumber(GPIO_enPORT1, GPIO_enPIN_NUMBER4, GPIO_enINT_ENABLE_ENA);

    Button_u8DownValue = GPIO->P2.IN_bits.P0;
    GPIO__vSetInterruptEdgeByNumber(GPIO_enPORT2, GPIO_enPIN_NUMBER0, (GPIO_nINT_EDGE) Button_u8DownValue);
    GPIO__vClearInterruptSourceByNumber(GPIO_enPORT2, GPIO_enPIN_NUMBER0);
    GPIO__vSetEnableInterruptSourceByNumber(GPIO_enPORT2, GPIO_enPIN_NUMBER0, GPIO_enINT_ENABLE_ENA);

    Button_u8LeftValue = GPIO->P2.IN_bits.P1;
    GPIO__vSetInterruptEdgeByNumber(GPIO_enPORT2, GPIO_enPIN_NUMBER1, (GPIO_nINT_EDGE) Button_u8LeftValue);
    GPIO__vClearInterruptSourceByNumber(GPIO_enPORT2, GPIO_enPIN_NUMBER1);
    GPIO__vSetEnableInterruptSourceByNumber(GPIO_enPORT2, GPIO_enPIN_NUMBER1, GPIO_enINT_ENABLE_ENA);
}

uint8_t Button__u8GetUpValue(void)
{
    return (Button_u8UpValue);
}

uint8_t Button__u8GetRightValue(void)
{
    return (Button_u8RightValue);
}

uint8_t Button__u8GetLeftValue(void)
{
    return (Button_u8LeftValue);
}

uint8_t Button__u8GetDownValue(void)
{
    return (Button_u8DownValue);
}

uint8_t Button__u8GetAllValues(void)
{
    uint8_t u8Value = 0U;
    u8Value = (Button_u8UpValue << 0U)|
            (Button_u8RightValue << 1U)|
            (Button_u8LeftValue << 2U)|
            (Button_u8DownValue << 3U);
    return (u8Value);
}
static uint16_t Button_u16UpDetection(uintptr_t uptrBlock, uint16_t u16Pin)
{
    PORT_EXT_t* pstPort = (PORT_EXT_t*) uptrBlock;
    Button_u8UpValue = pstPort->IN_bits.P4;
    pstPort->IES_bits.P4 = Button_u8UpValue;
    return (0xFFU);
}

static uint16_t Button_u16RightDetection(uintptr_t uptrBlock, uint16_t u16Pin)
{
    PORT_EXT_t* pstPort = (PORT_EXT_t*) uptrBlock;
    Button_u8RightValue = pstPort->IN_bits.P0;
    pstPort->IES_bits.P0 = Button_u8RightValue;
    return (0xFFU);
}

static uint16_t Button_u16LeftDetection(uintptr_t uptrBlock, uint16_t u16Pin)
{
    PORT_EXT_t* pstPort = (PORT_EXT_t*) uptrBlock;
    Button_u8LeftValue = pstPort->IN_bits.P1;
    pstPort->IES_bits.P1 = Button_u8LeftValue;
    return (0xFFU);
}

static uint16_t Button_u16DownDetection(uintptr_t uptrBlock, uint16_t u16Pin)
{
    PORT_EXT_t* pstPort = (PORT_EXT_t*) uptrBlock;
    Button_u8DownValue = pstPort->IN_bits.P0;
    pstPort->IES_bits.P0 = Button_u8DownValue;
    return (0xFFU);
}

