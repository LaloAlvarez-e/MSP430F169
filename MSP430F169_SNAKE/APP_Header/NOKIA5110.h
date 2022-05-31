/*
 * NOKIA5110.h
 *
 *  Created on: 15 mar. 2018
 *      Author: InDev
 */

#ifndef NOKIA5110_H_
#define NOKIA5110_H_

#include "DriverLib/MCU/Header/MCU_Common.h"
#include "stdarg.h"

#define NOKIA5110_WIDTHTOTAL	(84u)
#define NOKIA5110_HEIGHTTOTAL	(48u)

#define NOKIA5110_DC_PIN	(BIT4)
#define NOKIA5110_DC_DIR	(P3DIR)
#define NOKIA5110_DC_OUT	(P3OUT)
#define NOKIA5110_DC_SEL    (P3SEL)

#define NOKIA5110_RST_PIN    (BIT5)
#define NOKIA5110_RST_DIR    (P3DIR)
#define NOKIA5110_RST_OUT    (P3OUT)
#define NOKIA5110_RST_SEL    (P3SEL)


#define NOKIA5110_DC_COMMAND()	NOKIA5110_DC_OUT&=~NOKIA5110_DC_PIN
#define NOKIA5110_DC_DATA()		NOKIA5110_DC_OUT|=NOKIA5110_DC_PIN

#define NOKIA5110_RST_LOW()  NOKIA5110_RST_OUT&=~NOKIA5110_RST_PIN
#define NOKIA5110_RST_HIGH()     NOKIA5110_RST_OUT|=NOKIA5110_RST_PIN


#define NOKIA5110_MAX_X 84
#define NOKIA5110_MAX_Y 48

#define NOKIA5110_COLUMN_SIZE 12
#define NOKIA5110_ROW_SIZE (NOKIA5110_MAX_Y / 8U)
#define NOKIA5110_TAB_SIZE 3


#define LCD_WIDTH (84U)
#define LCD_HEIGHT (48U)

#define LCD_CHAR_WIDTH (7U)
#define LCD_CHAR_HEIGHT (8U)
#define LCD_ROW_HEIGHT (8U)

typedef enum
{
	NOKIA5110_enOK   =0,
	NOKIA5110_enERROR  =1,
}NOKIA5110_nStatus;

void LCD__vPixelSection(uint8_t u8PixelValue, uint8_t* pu8Column, uint8_t* pu8Row,
                        uint8_t u8ColumnStart, uint8_t u8RowStart, uint8_t u8Width, uint8_t u8Height);
void LCD__vPixel(uint8_t u8PixelValue, uint8_t* pu8Column, uint8_t* pu8Row);

uint8_t LCD__u8ReadPixelSection(uint8_t* pu8Column, uint8_t* pu8Row,
                        uint8_t u8ColumnStart, uint8_t u8RowStart, uint8_t u8Width, uint8_t u8Height);
uint8_t LCD__u8ReadPixel(uint8_t* pu8Column, uint8_t* pu8Row);

void LCD__vRowPixelSection(uint8_t u8RowValue, uint8_t* pu8Column, uint8_t* pu8Row,
                    uint8_t u8ColumnStart, uint8_t u8RowStart, uint8_t u8Width, uint8_t u8Height);
void LCD__vRowPixel(uint8_t u8RowValue, uint8_t* pu8Column, uint8_t* pu8Row);

void LCD__vRefresh(void);
void LCD__vCharSection(char cChar, uint8_t* pu8Column, uint8_t* pu8Row,
                uint8_t u8ColumnStart, uint8_t u8RowStart, uint8_t u8Width, uint8_t u8Height);
void LCD__vChar(char cChar, uint8_t* pu8Column, uint8_t* pu8Row);
void LCD__vClearSection(uint8_t u8Value, uint8_t u8ColumnStart, uint8_t u8RowStart, uint8_t u8Width, uint8_t u8Height);
void LCD__vClear(uint8_t u8Value);
uint8_t LCD__u8StringSection(char* cString,uint8_t* u8Column, uint8_t* u8Row,
                             uint8_t u8ColumnStart, uint8_t u8RowStart, uint8_t u8Width, uint8_t u8Height);
uint8_t LCD__u8String(char* cString,uint8_t* u8Column, uint8_t* u8Row);
void LCD__vCommand(uint8_t u8Data);
void LCD__vData(uint8_t u8Data);
void LCD__vSetCursor(uint8_t u8Column, uint8_t u8Row);


uint16_t LCD__u16Print_Section(char* cString,uint8_t* pu8Column, uint8_t* pu8Row,
                       uint8_t u8ColumnStart, uint8_t u8RowStart, uint8_t u8Width, uint8_t u8Height);
uint16_t LCD__u16Print(char* cString,uint8_t* pu8Column, uint8_t* pu8Row);

uint32_t LCD__u32Printf_Section(const char* pcFormat,uint8_t* u8Column, uint8_t* u8Row,
                                 uint8_t u8ColumnStart, uint8_t u8RowStart, uint8_t u8Width, uint8_t u8Height, ... );
uint32_t LCD__u32Printf(const char* pcFormat,uint8_t* u8Column, uint8_t* u8Row, ... );

void NOKIA5110__vInit(void);

#if 0
//int NOKIA5110_BMPBinary(const unsigned char *ptr);

#endif

#endif /* NOKIA5110_H_ */
