/*
 * GPIO.c
 *
 * Created: 11/10/2019 12:26:54 p. m.
 *  Author: Lalo
 */ 

#include <GPIO.h>


void GPIO__vInitPort(void)
{
	PBUTTON1_DIR   &=~PBUTTON1_READPIN;   /*PD.2 (Push Button1) as Input*/
	PBUTTON1_SEL   &=~ PBUTTON1_READPIN;   /*PD.2 (Push Button1) with Pull-Up*/
	
	PBUTTON2_DIR   &=~PBUTTON2_READPIN;   /*PB.2 (Push Button2) as Input*/
	PBUTTON2_SEL   &=~ PBUTTON2_READPIN;   /*PB.2 (Push Button2) with Pull-Up*/
	
	PBUTTON3_DIR   &=~PBUTTON3_READPIN;   /*PB.1 (Push Button2) as Input*/
	PBUTTON3_SEL   &=~ PBUTTON3_READPIN;  /*PB.1 (Push Button2) with Pull-Up*/
	
	LEDRED_DIR   |= LEDRED_PIN;		/*PB.5 (Led RED) as Output*/
	LEDAMBER_DIR |= LEDAMBER_PIN;		/*PC.4 (Led AMBER) as Output*/
	LEDBLUE_DIR |= LEDBLUE_PIN;		/*PC.3 (Led BLUE) as Output*/
	
	LEDRED_OUT  &=~LEDRED_PIN;		/*PC.5 (Led RED) Output Low*/
	LEDAMBER_OUT&=~LEDAMBER_PIN;		/*PC.4 (Led AMBER) Output Low*/
	LEDBLUE_OUT&=~LEDBLUE_PIN;		/*PC.4 (Led BLUE) Output Low*/

    LEDRED_SEL  &=~LEDRED_PIN;      /*PC.5 (Led RED) Output Low*/
    LEDAMBER_SEL&=~LEDAMBER_PIN;        /*PC.4 (Led AMBER) Output Low*/
    LEDBLUE_SEL&=~LEDBLUE_PIN;      /*PC.4 (Led BLUE) Output Low*/
	
}
