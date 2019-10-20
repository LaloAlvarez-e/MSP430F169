/*
 * CLOCK.h
 *
 *  Created on: 22/01/2019
 *      Author: InDev
 */

#ifndef CLOCK_H_
#define CLOCK_H_

#include <msp430.h>
#include "stdint.h"

void CLOCK__vConf(void);
void CLOCK__vEnOutSMCLK(void);
void CLOCK__vDisOutSMCLK(void);
void CLOCK__vEnOutMCLK(void);
void CLOCK__vDisOutMCLK(void);
void CLOCK__vEnOutACLK(void);
void CLOCK__vDisOutACLK(void);
__interrupt void OSC_vISR(void);

#endif /* CLOCK_H_ */
