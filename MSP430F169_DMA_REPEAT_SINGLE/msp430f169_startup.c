/**
 *
 * @file msp430f169_startup.c
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
 * @verbatim 25 mar. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 25 mar. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/DriverLib.h"

__interrupt void IntDefaultHandler(void);

#pragma RETAIN (INTERRUPT__pfvVector)
#pragma DATA_SECTION(INTERRUPT__pfvVector, ".intvecs")
void (* const INTERRUPT__pfvVector[15U])(void) =
{
    &DACDMA_IRQVectorHandler,                      /* The DACDMA handler*/
    &PORT2_IRQVectorHandler,                      /* The PORT2 handler*/
    &IntDefaultHandler,                      /* The USART1TX handler*/
    &IntDefaultHandler,                      /* The USART1RX handler*/
    &PORT1_IRQVectorHandler,                      /* The PORT1 handler*/
    &IntDefaultHandler,                      /* The TIMERA1 handler*/
    &IntDefaultHandler,                      /* The TIMERA0 handler*/
    &IntDefaultHandler,                      /* The ADC12 handler*/
    &IntDefaultHandler,                      /* The USART0TX handler*/
    &IntDefaultHandler,                      /* The USART0RX handler*/
    &WDT_IRQVectorHandler,                      /* The WDT handler*/
    &IntDefaultHandler,                      /* The COMPARATORA handler*/
    &IntDefaultHandler,                      /* The TIMERB1 handler*/
    &IntDefaultHandler,                      /* The TIMERB0 handler*/
    &NMI_IRQVectorHandler,                      /* The NMI handler*/
};

__interrupt void IntDefaultHandler(void)
{
    while(1)
    {

    }
}


