/*
 * main.h
 *
 *  Created on: 23/08/2017
 *      Author: Lalo
 */

#ifndef MAIN_H_
#define MAIN_H

#include "DriverLib/DriverLib.h"


void Conf_Reloj(void);
void Conf_LCD1602(void);
void LCD1602_Command(uint8_t u8Command);
void LCD1602_Data(uint8_t u8Data);
void LCD1602_Trigger(void);
void LCD1602_Pos(uint8_t u8Column, uint8_t u8Row);

/*DEfinciones de Comando*/
#define CLEAR 0x1 //limpia la pantalla

#define HOME  0x2 //manda cursor a Home 0,0

//Combinacion de los siguientes parametros para mandar comando
#define IncAdd  0x6 //Incrementa la direccion en cada escritura
#define DecAdd  0x4 //Decrementa la direccion en cada escritura

#define NSDisp 0x4 //no desplaza la pantalla
#define SDisp 0x5 //desplaza la pantalla 1 posicion

//combinacion de los siguientes parametros para mandar comando
#define ONDisp    0xC //enciende la pantalla
#define OFFDisp   0x8 //apaga la pantalla

#define ONCursor  0xA //prende el cursor visual
#define OFFCursor 0x8 //apaga el cursor visual

#define ONBlink   0x9 //hace que el cursor parpadee
#define OFFBlink  0x8 //El parpadeo se desactiva

//mandar solo una defincion en este comando
#define SRDisp  0x1C //Desplaza la pantalla a la der, la dir no cambia
#define SLDisp  0x18 //Desplaza la pantalla a la izq, la dir no cambia
#define CRDisp  0x14 //mueve el cursor a la der, la dir aumenta en 1
#define CLDisp  0x10 //mueve el cursor a la izq, la dir disminuye en 1

//combinacion de los siguientes parametros para mandar comando
#define M8BIT     0x30 //modo 8bit
#define M4BIT     0x20 //modo 4bit

#define M1LINE    0x20 //modo 1 linea
#define M2LINE    0x28 //modo 2 lineas

#define M5_8_Font 0x20 //fuente 5x8
#define M5_11_Font 0x24 //fuente 5x11 solo para 1 linea

#define PUERTO_RS GPIO_enPORT6
#define PUERTO_RW GPIO_enPORT6
#define PUERTO_E  GPIO_enPORT6
#define PUERTO_D4 GPIO_enPORT6
#define PUERTO_D5 GPIO_enPORT6
#define PUERTO_D6 GPIO_enPORT6
#define PUERTO_D7 GPIO_enPORT6


#define P_RS PORT6
#define P_RW PORT6
#define P_E  PORT6
#define P_D4 PORT6
#define P_D5 PORT6
#define P_D6 PORT6
#define P_D7 PORT6

#define RS GPIO_enPIN0
#define RW GPIO_enPIN1
#define E  GPIO_enPIN2
#define D4 GPIO_enPIN4
#define D5 GPIO_enPIN5
#define D6 GPIO_enPIN6
#define D7 GPIO_enPIN7

#define RS_POS GPIO_enPIN_NUMBER0
#define RW_POS GPIO_enPIN_NUMBER1
#define E_POS  GPIO_enPIN_NUMBER2
#define D4_POS GPIO_enPIN_NUMBER4
#define D5_POS GPIO_enPIN_NUMBER5
#define D6_POS GPIO_enPIN_NUMBER6
#define D7_POS GPIO_enPIN_NUMBER7

#define RS_P P0
#define RW_P P1
#define E_P  P2
#define D4_P P4
#define D5_P P5
#define D6_P P6
#define D7_P P7

#endif /* MAIN_H_ */
