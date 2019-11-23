/*
 * GPIO.h
 *
 * Created: 11/10/2019 12:27:10 p. m.
 *  Author: Lalo
 */ 


#ifndef GPIO_H_

#define GPIO_H_



#include <msp430f169.h>
#include <intrinsics.h>
#include <stdint.h>
#include <OS.h>

#define LEDRED_PIN	(BIT0)
#define LEDRED_DIR	(P6DIR)
#define LEDRED_OUT	(P6OUT)
#define LEDRED_SEL  (P6SEL)

#define LEDAMBER_PIN	(BIT1)
#define LEDAMBER_DIR	(P6DIR)
#define LEDAMBER_OUT	(P6OUT)
#define LEDAMBER_SEL    (P6SEL)

#define LEDBLUE_PIN	(BIT2)
#define LEDBLUE_DIR	(P6DIR)
#define LEDBLUE_OUT	(P6OUT)
#define LEDBLUE_SEL (P6SEL)

#define PBUTTON1_READPIN	(BIT2)
#define PBUTTON1_READPORT	(P1IN)
#define PBUTTON1_DIR		(P1DIR)
#define PBUTTON1_SEL        (P1SEL)
#define PBUTTON1_INT        (P1IE)
#define PBUTTON1_IFG        (P1IFG)
#define PBUTTON1_EDGE        (P1IES)

#define PBUTTON2_READPIN	(BIT1)
#define PBUTTON2_READPORT	(P1IN)
#define PBUTTON2_DIR		(P1DIR)
#define PBUTTON2_SEL		(P1SEL)
#define PBUTTON2_INT        (P1IE)
#define PBUTTON2_IFG        (P1IFG)
#define PBUTTON2_EDGE        (P1IES)

#define PBUTTON3_READPIN	(BIT0)
#define PBUTTON3_READPORT	(P1IN)
#define PBUTTON3_DIR		(P1DIR)
#define PBUTTON3_SEL		(P1SEL)

typedef enum
{
	PBUTTON1_enPRESS = 0,
	PBUTTON1_enRELEASE = PBUTTON1_READPIN,
	
}PBUTTON1_nState;

typedef enum
{
	PBUTTON2_enPRESS = 0,
	PBUTTON2_enRELEASE = PBUTTON2_READPIN,
	
}PBUTTON2_nState;

typedef enum
{
	PBUTTON3_enPRESS = 0,
	PBUTTON3_enRELEASE = PBUTTON3_READPIN,
	
}PBUTTON3_nState;

#define PBUTTON1_READSTATE  (PBUTTON1_READPORT & PBUTTON1_READPIN)
#define PBUTTON2_READSTATE  (PBUTTON2_READPORT & PBUTTON2_READPIN)
#define PBUTTON3_READSTATE  (PBUTTON3_READPORT & PBUTTON3_READPIN)

void GPIO__vInitPort(void);

#endif /* GPIO_H_ */
