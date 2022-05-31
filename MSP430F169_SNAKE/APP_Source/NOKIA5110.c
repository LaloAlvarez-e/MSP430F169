/*
 * NOKIA5110.c
 *
 *  Created on: 15 mar. 2018
 *      Author: InDev
 */



//cada envio de datos son  bits que se  acomodan en las siuientes 8 filas,(6*8)
//luego se pasa automaticmente a la siguiente columna (12*7)

#include <NOKIA5110.h>
#include <DriverLib/DriverLib.h>
#include <SPI.h>
#include "xUtils/Font/Font.h"
#include <xApplication/Printf/Printf.h>

static void LCD_vDmaInit(void);
static void LCD_vClearDmaInit(void);

static uint8_t NOKIA5110_u8ImageBuffer[NOKIA5110_MAX_X*(NOKIA5110_MAX_Y/8)];
static const uint8_t NOKIA5110_u8ASCII[96U][LCD_CHAR_WIDTH] = {
   {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} // 20
  ,{0x00, 0x00, 0x00, 0x5f, 0x00, 0x00, 0x00} // 21 !
  ,{0x00, 0x00, 0x07, 0x00, 0x07, 0x00, 0x00} // 22 "
  ,{0x00, 0x14, 0x7f, 0x14, 0x7f, 0x14, 0x00} // 23 #
  ,{0x00, 0x24, 0x2a, 0x7f, 0x2a, 0x12, 0x00} // 24 $
  ,{0x00, 0x23, 0x13, 0x08, 0x64, 0x62, 0x00} // 25 %
  ,{0x00, 0x36, 0x49, 0x55, 0x22, 0x50, 0x00} // 26 &
  ,{0x00, 0x00, 0x05, 0x03, 0x00, 0x00, 0x00} // 27 '
  ,{0x00, 0x00, 0x1c, 0x22, 0x41, 0x00, 0x00} // 28 (
  ,{0x00, 0x00, 0x41, 0x22, 0x1c, 0x00, 0x00} // 29 )
  ,{0x00, 0x14, 0x08, 0x3e, 0x08, 0x14, 0x00} // 2a *
  ,{0x00, 0x08, 0x08, 0x3e, 0x08, 0x08, 0x00} // 2b +
  ,{0x00, 0x00, 0x50, 0x30, 0x00, 0x00, 0x00} // 2c ,
  ,{0x00, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00} // 2d -
  ,{0x00, 0x00, 0x60, 0x60, 0x00, 0x00, 0x00} // 2e .
  ,{0x00, 0x20, 0x10, 0x08, 0x04, 0x02, 0x00} // 2f /
  ,{0x00, 0x3e, 0x51, 0x49, 0x45, 0x3e, 0x00} // 30 0
  ,{0x00, 0x00, 0x42, 0x7f, 0x40, 0x00, 0x00} // 31 1
  ,{0x00, 0x42, 0x61, 0x51, 0x49, 0x46, 0x00} // 32 2
  ,{0x00, 0x21, 0x41, 0x45, 0x4b, 0x31, 0x00} // 33 3
  ,{0x00, 0x18, 0x14, 0x12, 0x7f, 0x10, 0x00} // 34 4
  ,{0x00, 0x27, 0x45, 0x45, 0x45, 0x39, 0x00} // 35 5
  ,{0x00, 0x3c, 0x4a, 0x49, 0x49, 0x30, 0x00} // 36 6
  ,{0x00, 0x01, 0x71, 0x09, 0x05, 0x03, 0x00} // 37 7
  ,{0x00, 0x36, 0x49, 0x49, 0x49, 0x36, 0x00} // 38 8
  ,{0x00, 0x06, 0x49, 0x49, 0x29, 0x1e, 0x00} // 39 9
  ,{0x00, 0x00, 0x36, 0x36, 0x00, 0x00, 0x00} // 3a :
  ,{0x00, 0x00, 0x56, 0x36, 0x00, 0x00, 0x00} // 3b ;
  ,{0x00, 0x08, 0x14, 0x22, 0x41, 0x00, 0x00} // 3c <
  ,{0x00, 0x14, 0x14, 0x14, 0x14, 0x14, 0x00} // 3d =
  ,{0x00, 0x00, 0x41, 0x22, 0x14, 0x08, 0x00} // 3e >
  ,{0x00, 0x02, 0x01, 0x51, 0x09, 0x06, 0x00} // 3f ?
  ,{0x00, 0x32, 0x49, 0x79, 0x41, 0x3e, 0x00} // 40 @
  ,{0x00, 0x7e, 0x11, 0x11, 0x11, 0x7e, 0x00} // 41 A
  ,{0x00, 0x7f, 0x49, 0x49, 0x49, 0x36, 0x00} // 42 B
  ,{0x00, 0x3e, 0x41, 0x41, 0x41, 0x22, 0x00} // 43 C
  ,{0x00, 0x7f, 0x41, 0x41, 0x22, 0x1c, 0x00} // 44 D
  ,{0x00, 0x7f, 0x49, 0x49, 0x49, 0x41, 0x00} // 45 E
  ,{0x00, 0x7f, 0x09, 0x09, 0x09, 0x01, 0x00} // 46 F
  ,{0x00, 0x3e, 0x41, 0x49, 0x49, 0x7a, 0x00} // 47 G
  ,{0x00, 0x7f, 0x08, 0x08, 0x08, 0x7f, 0x00} // 48 H
  ,{0x00, 0x00, 0x41, 0x7f, 0x41, 0x00, 0x00} // 49 I
  ,{0x00, 0x20, 0x40, 0x41, 0x3f, 0x01, 0x00} // 4a J
  ,{0x00, 0x7f, 0x08, 0x14, 0x22, 0x41, 0x00} // 4b K
  ,{0x00, 0x7f, 0x40, 0x40, 0x40, 0x40, 0x00} // 4c L
  ,{0x00, 0x7f, 0x02, 0x0c, 0x02, 0x7f, 0x00} // 4d M
  ,{0x00, 0x7f, 0x04, 0x08, 0x10, 0x7f, 0x00} // 4e N
  ,{0x00, 0x3e, 0x41, 0x41, 0x41, 0x3e, 0x00} // 4f O
  ,{0x00, 0x7f, 0x09, 0x09, 0x09, 0x06, 0x00} // 50 P
  ,{0x00, 0x3e, 0x41, 0x51, 0x21, 0x5e, 0x00} // 51 Q
  ,{0x00, 0x7f, 0x09, 0x19, 0x29, 0x46, 0x00} // 52 R
  ,{0x00, 0x46, 0x49, 0x49, 0x49, 0x31, 0x00} // 53 S
  ,{0x00, 0x01, 0x01, 0x7f, 0x01, 0x01, 0x00} // 54 T
  ,{0x00, 0x3f, 0x40, 0x40, 0x40, 0x3f, 0x00} // 55 U
  ,{0x00, 0x1f, 0x20, 0x40, 0x20, 0x1f, 0x00} // 56 V
  ,{0x00, 0x3f, 0x40, 0x38, 0x40, 0x3f, 0x00} // 57 W
  ,{0x00, 0x63, 0x14, 0x08, 0x14, 0x63, 0x00} // 58 X
  ,{0x00, 0x07, 0x08, 0x70, 0x08, 0x07, 0x00} // 59 Y
  ,{0x00, 0x61, 0x51, 0x49, 0x45, 0x43, 0x00} // 5a Z
  ,{0x00, 0x00, 0x7f, 0x41, 0x41, 0x00, 0x00} // 5b [
  ,{0x00, 0x02, 0x04, 0x08, 0x10, 0x20, 0x00} // 5c '\'
  ,{0x00, 0x00, 0x41, 0x41, 0x7f, 0x00, 0x00} // 5d ]
  ,{0x00, 0x04, 0x02, 0x01, 0x02, 0x04, 0x00} // 5e ^
  ,{0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00} // 5f _
  ,{0x00, 0x00, 0x01, 0x02, 0x04, 0x00, 0x00} // 60 `
  ,{0x00, 0x20, 0x54, 0x54, 0x54, 0x78, 0x00} // 61 a
  ,{0x00, 0x7f, 0x48, 0x44, 0x44, 0x38, 0x00} // 62 b
  ,{0x00, 0x38, 0x44, 0x44, 0x44, 0x20, 0x00} // 63 c
  ,{0x00, 0x38, 0x44, 0x44, 0x48, 0x7f, 0x00} // 64 d
  ,{0x00, 0x38, 0x54, 0x54, 0x54, 0x18, 0x00} // 65 e
  ,{0x00, 0x08, 0x7e, 0x09, 0x01, 0x02, 0x00} // 66 f
  ,{0x00, 0x0c, 0x52, 0x52, 0x52, 0x3e, 0x00} // 67 g
  ,{0x00, 0x7f, 0x08, 0x04, 0x04, 0x78, 0x00} // 68 h
  ,{0x00, 0x00, 0x44, 0x7d, 0x40, 0x00, 0x00} // 69 i
  ,{0x00, 0x20, 0x40, 0x44, 0x3d, 0x00, 0x00} // 6a j
  ,{0x00, 0x7f, 0x10, 0x28, 0x44, 0x00, 0x00} // 6b k
  ,{0x00, 0x00, 0x41, 0x7f, 0x40, 0x00, 0x00} // 6c l
  ,{0x00, 0x7c, 0x04, 0x18, 0x04, 0x78, 0x00} // 6d m
  ,{0x00, 0x7c, 0x08, 0x04, 0x04, 0x78, 0x00} // 6e n
  ,{0x00, 0x38, 0x44, 0x44, 0x44, 0x38, 0x00} // 6f o
  ,{0x00, 0x7c, 0x14, 0x14, 0x14, 0x08, 0x00} // 70 p
  ,{0x00, 0x08, 0x14, 0x14, 0x18, 0x7c, 0x00} // 71 q
  ,{0x00, 0x7c, 0x08, 0x04, 0x04, 0x08, 0x00} // 72 r
  ,{0x00, 0x48, 0x54, 0x54, 0x54, 0x20, 0x00} // 73 s
  ,{0x00, 0x04, 0x3f, 0x44, 0x40, 0x20, 0x00} // 74 t
  ,{0x00, 0x3c, 0x40, 0x40, 0x20, 0x7c, 0x00} // 75 u
  ,{0x00, 0x1c, 0x20, 0x40, 0x20, 0x1c, 0x00} // 76 v
  ,{0x00, 0x3c, 0x40, 0x30, 0x40, 0x3c, 0x00} // 77 w
  ,{0x00, 0x44, 0x28, 0x10, 0x28, 0x44, 0x00} // 78 x
  ,{0x00, 0x0c, 0x50, 0x50, 0x50, 0x3c, 0x00} // 79 y
  ,{0x00, 0x44, 0x64, 0x54, 0x4c, 0x44, 0x00} // 7a z
  ,{0x00, 0x00, 0x08, 0x36, 0x41, 0x00, 0x00} // 7b {
  ,{0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00} // 7c |
  ,{0x00, 0x00, 0x41, 0x36, 0x08, 0x00, 0x00} // 7d , 0x00}
  ,{0x00, 0x10, 0x08, 0x08, 0x10, 0x08, 0x00} // 7e ~
//,{0x00, 0x78, 0x46, 0x41, 0x46, 0x78, 0x00} // 7f DEL
  ,{0x00, 0x1f, 0x24, 0x7c, 0x24, 0x1f, 0x00} // 7f UT sign
};


void LCD__vPixelSection(uint8_t u8PixelValue, uint8_t* pu8Column, uint8_t* pu8Row,
                        uint8_t u8ColumnStart, uint8_t u8RowStart, uint8_t u8Width, uint8_t u8Height)
{
    uint8_t u8RowBit;
    uint8_t u8RowByte;
    uint16_t u16Address;
    uint16_t u16TotalWidth = u8ColumnStart + u8Width;
    uint16_t u16TotalHeight = u8RowStart + u8Height;

    if(*pu8Column >= u16TotalWidth)
    {
        *pu8Column -= u16TotalWidth;
    }
    if(*pu8Column < u8ColumnStart)
    {
        *pu8Column = u16TotalWidth - (u8ColumnStart - *pu8Column);
    }
    if(*pu8Row >= u16TotalHeight)
    {
        *pu8Row -= u16TotalHeight;
    }
    if(*pu8Row < u8RowStart)
    {
        *pu8Row = u16TotalHeight - (u8RowStart - *pu8Row);
    }

    u8RowByte = (*pu8Row) >> 3U;
    u8RowBit = (*pu8Row) & 0x7U;
    u16Address = u8RowByte * NOKIA5110_MAX_X;
    u16Address += (*pu8Column);

    if(0U == u8PixelValue)
    {
        NOKIA5110_u8ImageBuffer[u16Address] &= ~ (1U << u8RowBit);
    }
    else
    {
        NOKIA5110_u8ImageBuffer[u16Address] |= (1U << u8RowBit);
    }
    (*pu8Column)++;
    if(*pu8Column >= u16TotalWidth)
    {
        *pu8Column = u8ColumnStart;
        (*pu8Row)++;
        if(*pu8Row >= u16TotalHeight)
        {
            *pu8Row = u8RowStart;
        }
    }
}


void LCD__vPixel(uint8_t u8PixelValue, uint8_t* pu8Column, uint8_t* pu8Row)
{
    LCD__vPixelSection(u8PixelValue, pu8Column, pu8Row,
                            0U, 0U, LCD_WIDTH, LCD_HEIGHT);
}


uint8_t LCD__u8ReadPixelSection(uint8_t* pu8Column, uint8_t* pu8Row,
                        uint8_t u8ColumnStart, uint8_t u8RowStart, uint8_t u8Width, uint8_t u8Height)
{
    uint8_t u8PixelValue;
    uint8_t u8RowBit;
    uint8_t u8RowByte;
    uint16_t u16Address;
    uint16_t u16TotalWidth = u8ColumnStart + u8Width;
    uint16_t u16TotalHeight = u8RowStart + u8Height;

    if(*pu8Column >= u16TotalWidth)
    {
        *pu8Column -= u16TotalWidth;
    }
    if(*pu8Column < u8ColumnStart)
    {
        *pu8Column = u16TotalWidth - (u8ColumnStart - *pu8Column);
    }
    if(*pu8Row >= u16TotalHeight)
    {
        *pu8Row -= u16TotalHeight;
    }
    if(*pu8Row < u8RowStart)
    {
        *pu8Row = u16TotalHeight - (u8RowStart - *pu8Row);
    }

    u8RowByte = (*pu8Row) >> 3U;
    u8RowBit = (*pu8Row) & 0x7U;
    u16Address = u8RowByte * NOKIA5110_MAX_X;
    u16Address += (*pu8Column);

    u8PixelValue = NOKIA5110_u8ImageBuffer[u16Address];
    u8PixelValue &= (1U << u8RowBit);
    u8PixelValue >>= u8RowBit;
    (*pu8Column)++;
    if(*pu8Column >= u16TotalWidth)
    {
        *pu8Column = u8ColumnStart;
        (*pu8Row)++;
        if(*pu8Row >= u16TotalHeight)
        {
            *pu8Row = u8RowStart;
        }
    }
}


uint8_t LCD__u8ReadPixel(uint8_t* pu8Column, uint8_t* pu8Row)
{
    uint8_t u8PixelValue = 0U;
    u8PixelValue = LCD__u8ReadPixelSection(pu8Column, pu8Row,
                            0U, 0U, LCD_WIDTH, LCD_HEIGHT);
}

void LCD__vRowPixelSection(uint8_t u8RowValue, uint8_t* pu8Column, uint8_t* pu8Row,
                    uint8_t u8ColumnStart, uint8_t u8RowStart, uint8_t u8Width, uint8_t u8Height)
{
    uint8_t u8RowStartBit;
    uint8_t u8RowStartByte;
    uint8_t u8RowDifferential;
    uint8_t u8RowDifferential2;
    uint8_t u8BitsLeft;
    uint8_t u8Mask;
    uint8_t u8RowTemp;
    uint8_t u8RowInit;
    uint16_t u16Address;
    uint8_t u8TempValue;
    uint16_t u16TotalWidth = u8ColumnStart + u8Width;
    uint16_t u16TotalHeight = u8RowStart + u8Height;


    if(*pu8Column >= u16TotalWidth)
    {
        *pu8Column -= u16TotalWidth;
    }
    if(*pu8Column < u8ColumnStart)
    {
        *pu8Column = u8ColumnStart;
    }
    if(*pu8Row >= u16TotalHeight)
    {
        *pu8Row -= u16TotalHeight;
    }
    if(*pu8Row < u8RowStart)
    {
        *pu8Row = u8RowStart;
    }
    u8BitsLeft = 8U;
    u8RowInit = *pu8Row;
    while(u8BitsLeft != 0U)
    {
        u8RowStartByte = u8RowInit >> 3U;
        u8RowStartBit = u8RowInit & 0x7U;
        u16Address = u8RowStartByte * NOKIA5110_MAX_X;
        u16Address += (*pu8Column);

        u8TempValue = NOKIA5110_u8ImageBuffer[u16Address];
        u8RowDifferential = u16TotalHeight - u8RowInit;
        if(u8RowDifferential < u8BitsLeft)
        {
            u8RowDifferential2 = (LCD_CHAR_HEIGHT * (u8RowStartByte + 1)) - u8RowInit;
            if(u8RowDifferential2 < u8RowDifferential)
            {
                u8Mask = 0xFFU >> (LCD_CHAR_HEIGHT - u8RowDifferential2);
                u8BitsLeft -= u8RowDifferential2;
                u8RowTemp = u8RowValue;
                u8RowValue >>= u8RowDifferential2;
                u8RowInit += u8RowDifferential2;
                if(u8RowInit >= u16TotalHeight)
                {
                    u8RowInit -= u8Height;
                }
            }
            else
            {
                u8Mask = 0xFFU >> (LCD_CHAR_HEIGHT - u8RowDifferential);
                u8BitsLeft -= u8RowDifferential;
                u8RowTemp = u8RowValue;
                u8RowValue >>= u8RowDifferential;
                u8RowInit += u8RowDifferential;
                if(u8RowInit >= u16TotalHeight)
                {
                    u8RowInit -= u8Height;
                }
            }
        }
        else
        {
            u8RowDifferential = LCD_CHAR_HEIGHT - u8RowStartBit;
            if(u8RowDifferential < u8BitsLeft)
            {
                u8Mask = 0xFFU >> (LCD_CHAR_HEIGHT - u8RowDifferential);
                u8BitsLeft -= u8RowDifferential;
                u8RowTemp = u8RowValue;
                u8RowValue >>= u8RowDifferential;
                u8RowInit += u8RowDifferential;
                if(u8RowInit >= u16TotalHeight)
                {
                    u8RowInit -= u8Height;
                }
            }
            else
            {
                u8Mask = 0xFFU >> (LCD_CHAR_HEIGHT - u8BitsLeft);
                u8BitsLeft = 0U;
                u8RowTemp = u8RowValue;
            }
        }
        u8Mask <<= u8RowStartBit;
        u8RowTemp <<= u8RowStartBit;
        u8TempValue &= ~u8Mask;
        u8TempValue |= u8RowTemp & u8Mask;
        NOKIA5110_u8ImageBuffer[u16Address] = u8TempValue;
    }

    (*pu8Column)++;
    if(*pu8Column >= u16TotalWidth)
    {
        *pu8Column = u8ColumnStart;
        (*pu8Row) += LCD_ROW_HEIGHT;
        if(*pu8Row >= u16TotalHeight)
        {
            (*pu8Row) -= u8Height;
        }
    }
}
void LCD__vRowPixel(uint8_t u8RowValue, uint8_t* pu8Column, uint8_t* pu8Row)
{
    LCD__vRowPixelSection(u8RowValue, pu8Column, pu8Row,
                        0U, 0U, LCD_WIDTH, LCD_HEIGHT);
}

void LCD__vCharSection(char cChar, uint8_t* pu8Column, uint8_t* pu8Row,
                uint8_t u8ColumnStart, uint8_t u8RowStart, uint8_t u8Width, uint8_t u8Height)
{
    uint8_t u8Iter;
    if(0x20 <= cChar)
    {
        cChar -= 0x20U;
        for(u8Iter = 0U; u8Iter < LCD_CHAR_WIDTH; u8Iter++)
        {
            LCD__vRowPixelSection(NOKIA5110_u8ASCII[cChar][u8Iter], pu8Column, pu8Row,
                                  u8ColumnStart, u8RowStart, u8Width, u8Height);
        }
    }
}

void LCD__vChar(char cChar, uint8_t* pu8Column, uint8_t* pu8Row)
{
    uint8_t u8Iter;
    if(0x20 <= cChar)
    {
        cChar -= 0x20U;
        for(u8Iter = 0U; u8Iter < LCD_CHAR_WIDTH; u8Iter++)
        {
            LCD__vRowPixel(NOKIA5110_u8ASCII[cChar][u8Iter], pu8Column, pu8Row);
        }
    }
}

void LCD__vClearSection(uint8_t u8Value, uint8_t u8ColumnStart, uint8_t u8RowStart, uint8_t u8Width, uint8_t u8Height)
{
    uint16_t u16Iter;
    static uint8_t u8Row = 0U;
    static uint8_t u8Column = 0U;
    u8Row = u8RowStart;
    u8Column = u8ColumnStart;
    for(u16Iter = 0U; u16Iter < (u8Width*u8Height); u16Iter++)
    {
        LCD__vPixelSection(u8Value, &u8Column, &u8Row,
                           u8ColumnStart, u8RowStart, u8Width, u8Height);
    }
}

uint8_t u8ClearValue = 0U;
void LCD__vClear(uint8_t u8Value)
{
    if(0U != u8Value)
    {
        u8Value = 0xFFU;
    }
    u8ClearValue = u8Value;
    while(DMA_CH_CTL_EN_DIS != DMA->CH[1U].CTL_bits.EN);
    DMA->CH[1U].SA = (uint16_t) &u8ClearValue;
    DMA->CH[1U].CTL_bits.EN = DMA_CH_CTL_EN_ENA;
    DMA->CH[1U].CTL_bits.REQ = DMA_CH_CTL_REQ_REQUEST;
    while(DMA_CH_CTL_EN_DIS != DMA->CH[1U].CTL_bits.EN);
}

void LCD__vRefresh(void)
{
    LCD__vSetCursor(0,0);
    NOKIA5110_DC_DATA();
    P3OUT&=~BIT0;
    while(DMA_CH_CTL_EN_DIS != DMA->CH[0U].CTL_bits.EN);
    while(0U == (IFG1 & UTXIFG0));
    IFG1 &= ~UTXIFG0;
    DMA->CH[0U].CTL_bits.EN = DMA_CH_CTL_EN_ENA;
    IFG1 |= UTXIFG0;
    while(DMA_CH_CTL_EN_DIS != DMA->CH[0U].CTL_bits.EN);
    P3OUT|=BIT0;
}

uint8_t LCD__u8StringSection(char* cString,uint8_t* u8Column, uint8_t* u8Row,
                             uint8_t u8ColumnStart, uint8_t u8RowStart, uint8_t u8Width, uint8_t u8Height)
{
    uint8_t u8Count = 0U;

    while(*cString != 0U)
    {
        LCD__vCharSection(*cString, u8Column, u8Row,
                          u8ColumnStart, u8RowStart, u8Width, u8Height);
        cString++;
        u8Count++;
    }
    return u8Count;
}

uint8_t LCD__u8String(char* cString,uint8_t* u8Column, uint8_t* u8Row)
{
    uint8_t u8Count = 0U;

    while(*cString != 0U)
    {
        LCD__vChar(*cString, u8Column, u8Row );
        cString++;
        u8Count++;
    }
    return u8Count;
}

void LCD__vCommand(uint8_t u8Data)
{
    NOKIA5110_DC_COMMAND();
    P3OUT&=~BIT0;
    SPI__vSendByte(u8Data);
    P3OUT|=BIT0;
}

void LCD__vData(uint8_t u8Data)
{
    NOKIA5110_DC_DATA();
    P3OUT&=~BIT0;
    SPI__vSendByte(u8Data);
    P3OUT|=BIT0;
}

void LCD__vSetCursor(uint8_t u8Column, uint8_t u8Row)
{
    if(u8Column >= LCD_WIDTH)
    {
        u8Column = 0U;
    }
    if(u8Row >= LCD_HEIGHT)
    {
        u8Row = 0U;
    }

    LCD__vCommand(0x80U|u8Column);
    LCD__vCommand(0x40U|u8Row);
}

static void LCD_vDmaInit(void)
{
    DMA_CH_ConfigExt_t stDMAChannelConfig =
    {
        NOKIA5110_MAX_X*(NOKIA5110_MAX_Y/8),
        (uint16_t) NOKIA5110_u8ImageBuffer,
        (uint16_t) &U0TXBUF,
        DMA_enCH_TRIGGER_USART0_TX,
        DMA_enCH_MODE_SINGLE,
        DMA_enCH_INCMODE_INCREMENT,
        DMA_enCH_INCMODE_UNCHANGED,
        DMA_enCH_DATASIZE_BYTE,
        DMA_enCH_DATASIZE_BYTE,
        DMA_enCH_SENSE_EDGE,
        DMA_enCH_ENABLE_DIS,
        DMA_enCH_ABORT_CLEAR,
        DMA_enCH_INT_ENABLE_DIS,
        DMA_enCH_INT_STATUS_NOOCCUR,
    };

    DMA_Config_t stDMAGlobalConfig =
    {
     DMA_enENABLE_DIS,
     DMA_enPRIORITY_STATIC,
     DMA_enFETCH_NEXT,
    };

    DMA__vSetConfig(&stDMAGlobalConfig);
    DMA_CH__vSetConfigExt(DMA_enCH0, &stDMAChannelConfig);
}


static void LCD_vClearDmaInit(void)
{
    DMA_CH_ConfigExt_t stDMAChannelConfig =
    {
        NOKIA5110_MAX_X*(NOKIA5110_MAX_Y/8),
        (uint16_t) &u8ClearValue,
        (uint16_t) NOKIA5110_u8ImageBuffer,
        DMA_enCH_TRIGGER_SW,
        DMA_enCH_MODE_BLOCK,
        DMA_enCH_INCMODE_UNCHANGED,
        DMA_enCH_INCMODE_INCREMENT,
        DMA_enCH_DATASIZE_BYTE,
        DMA_enCH_DATASIZE_BYTE,
        DMA_enCH_SENSE_EDGE,
        DMA_enCH_ENABLE_DIS,
        DMA_enCH_ABORT_CLEAR,
        DMA_enCH_INT_ENABLE_DIS,
        DMA_enCH_INT_STATUS_NOOCCUR,
    };

    DMA_Config_t stDMAGlobalConfig =
    {
     DMA_enENABLE_DIS,
     DMA_enPRIORITY_STATIC,
     DMA_enFETCH_NEXT,
    };

    DMA__vSetConfig(&stDMAGlobalConfig);
    DMA_CH__vSetConfigExt(DMA_enCH1, &stDMAChannelConfig);
}

void NOKIA5110__vInit(void)
{
	uint32_t u32Delay = 0U;
	NOKIA5110_DC_DIR|=NOKIA5110_DC_PIN;
	NOKIA5110_DC_OUT&=~NOKIA5110_DC_PIN;
    NOKIA5110_DC_SEL&=~NOKIA5110_DC_PIN;

    NOKIA5110_RST_DIR|=NOKIA5110_RST_PIN;
    NOKIA5110_RST_OUT|=NOKIA5110_RST_PIN;
    NOKIA5110_RST_SEL&=~NOKIA5110_RST_PIN;

    P3DIR|=BIT0;
    P3OUT|=BIT0;
    P3SEL&=~BIT0;
    LCD_vDmaInit();
    LCD_vClearDmaInit();
	SPI__vInit(SPI_enModeMaster, SPI_enMSBFirst,SPI_enClockIdleLow,SPI_enClockSampleLast,6U);
	SPI__vInitPin((SPI_nPin) (SPI_enPinCLK|SPI_enPinMOSI|SPI_enPinMISO));
	for(u32Delay=0; u32Delay<0x7FF; u32Delay++);
    LCD__vCommand(0x21);
    LCD__vCommand(0xB0);
    LCD__vCommand(0x04);
    LCD__vCommand(0x14);
    LCD__vCommand(0x20);
    LCD__vCommand(0x0C);

}

uint16_t LCD__u16Print_Section(char* cString,uint8_t* pu8Column, uint8_t* pu8Row,
                       uint8_t u8ColumnStart, uint8_t u8RowStart, uint8_t u8Width, uint8_t u8Height)
{
    uint16_t u16Count = 0U;//variable usada para saber cuantos caracteres se mandaron a la LCD
    uint16_t u16TotalWidth = u8ColumnStart + u8Width;
    uint16_t u16TotalHeight = u8RowStart + u8Height;

    if(*pu8Column >= u16TotalWidth)
    {
        *pu8Column -= u16TotalWidth;
    }
    if(*pu8Column < u8ColumnStart)
    {
        *pu8Column = u8ColumnStart;
    }
    if(*pu8Row >= u16TotalHeight)
    {
        *pu8Row -= u16TotalHeight;
    }
    if(*pu8Row < u8RowStart)
    {
        *pu8Row = u8RowStart;
    }

    while(*cString)// realiza el ciclo mientras la cString tenga algun valor
           //el valor 0 o '\0' es fin de cString
    {
        switch (*cString) //detecta si existe un caracter especial
        {
        case '\n': //salto de linea
            (*pu8Row) += LCD_CHAR_HEIGHT;
            if(*pu8Row >= u16TotalHeight)
            {
                (*pu8Row) -= u8Height;
            }
            break;
        case '\r': //retorno de carro
            *pu8Column = u8RowStart; //actualiza el valor de la u8Column a la primera posicion
            break;
        case '\f': //nueva pagina
            *pu8Column = u8ColumnStart;
            *pu8Row = u8RowStart;//reinicia los valores
            LCD__vClearSection(0U, u8ColumnStart, u8RowStart, u8Width, u8Height); //limpia la pantalla
            break;
        default :
            LCD__vCharSection(*(cString), pu8Column, pu8Row, u8ColumnStart, u8RowStart, u8Width, u8Height); //envia el caracter correspondiente
            break;
        }
        cString++; //el puntero apunta al siguiente caracter
        u16Count++; //suma 1 al u16Count total de caracter enviados a la LCD
    }
     return (u16Count); //regresa el u16Count de caracteres y caracteres especiales
}


uint16_t LCD__u16Print(char* cString,uint8_t* pu8Column, uint8_t* pu8Row)
{
    uint16_t u16Count=0;//variable usada para saber cuantos caracteres se mandaron a la LCD

    while(*cString)// realiza el ciclo mientras la cString tenga algun valor
           //el valor 0 o '\0' es fin de cString
    {
        switch (*cString) //detecta si existe un caracter especial
        {
        case '\n': //salto de linea
            (*pu8Row) += LCD_CHAR_HEIGHT;
            if(*pu8Row >= LCD_HEIGHT)
            {
                (*pu8Row) -= LCD_HEIGHT;
            }
            break;
        case '\r': //retorno de carro
            *pu8Column = 0U; //actualiza el valor de la u8Column a la primera posicion
            break;
        case '\f': //nueva pagina
            *pu8Column = 0U;
            *pu8Row = 0U;//reinicia los valores
            LCD__vClear(0U); //limpia la pantalla
            break;
        default :
            LCD__vChar(*(cString), pu8Column, pu8Row); //envia el caracter correspondiente
            break;
        }
        cString++; //el puntero apunta al siguiente caracter
        u16Count++; //suma 1 al u16Count total de caracter enviados a la LCD
    }
     return (u16Count); //regresa el u16Count de caracteres y caracteres especiales
}


static char pcBufferReg[40UL] = {0};
uint32_t LCD__u32Printf_Section(const char* pcFormat,uint8_t* u8Column, uint8_t* u8Row,
                                 uint8_t u8ColumnStart, uint8_t u8RowStart, uint8_t u8Width, uint8_t u8Height, ... )
{
    uint32_t u32Lengtht = 0UL;
    char* pcBufferRegPointer = 0UL;
    va_list vaList;
    va_start(vaList, u8Height);
    u32Lengtht = vsnprintf__u32User(pcBufferReg, 40UL, pcFormat,vaList);
    va_end(vaList);
    pcBufferRegPointer = pcBufferReg;
    LCD__u16Print_Section(pcBufferRegPointer,u8Column, u8Row,
                                 u8ColumnStart, u8RowStart, u8Width, u8Height);
    return  (u32Lengtht);
}

uint32_t LCD__u32Printf(const char* pcFormat,uint8_t* u8Column, uint8_t* u8Row, ... )
{
    uint32_t u32Lengtht = 0UL;
    char* pcBufferRegPointer = 0UL;
    va_list vaList;
    va_start(vaList, u8Row);
    u32Lengtht = vsnprintf__u32User(pcBufferReg, 40UL, pcFormat,vaList);
    va_end(vaList);
    pcBufferRegPointer = pcBufferReg;
    LCD__u16Print(pcBufferRegPointer,u8Column, u8Row);
    return  (u32Lengtht);
}

#if 0
/*
int NOKIA5110_BMPBinary(const unsigned char *ptr)
{
  long width,height,bitsPerPixel;
  long widthMax,heightMax,k;
  long bitsTotal;
  unsigned char mask1bit[8]=
  {
   0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01
  };
  unsigned char mask4bit[2]=
  {
   0xF0,0x0F
  };
  unsigned char mask8bit[1]=
  {
   0xFF
  };
  unsigned char mask16bit[2]=
  {
   0xFF, 0xFF
  };
  unsigned char mask24bit[4]=
  {
   0xFF, 0xFF, 0xFF, 0x00
  };
  unsigned char mask32bit[4]=
  {
   0xFF, 0xFF, 0xFF, 0xFF
  };
  unsigned char* mask=mask1bit;
  unsigned long actualX, actualXi;
  bitmapV1x_t* bitmapV1= (bitmapV1x_t*)(ptr);
  bitmapV2x_t* bitmapV2= (bitmapV2x_t*)(ptr-2);
  bitmapV3x_t* bitmapV3x= (bitmapV3x_t*)(ptr-2);
  bitmapV3_t* bitmapV3=(bitmapV3_t*) (ptr-2);
  bitmapV4x_t* bitmapV4x= (bitmapV4x_t*)(ptr-2);
  bitmapV4_t* bitmapV4= (bitmapV4_t*)(ptr-2);
  unsigned char* image=0;
  if(bitmapV1->bitmapHeader.type==0)
  {
      if(bitmapV1->bitmapHeader.planes==1)
      {
          width=bitmapV1->bitmapHeader.width;
          height=bitmapV1->bitmapHeader.height;
          bitsPerPixel=bitmapV1->bitmapHeader.bitsPerPixel;
      }
      else
          return 0;
  }
  else if(bitmapV2->bitmapFileHeader.fileType==0x4D42 )
  {
      image=(unsigned char*)&ptr[bitmapV2->bitmapFileHeader.bitmapOffset];
      switch(bitmapV2->bitmapHeader.size)
      {
      case 12:
          if(bitmapV2->bitmapHeader.planes==1)
          {
              width=bitmapV2->bitmapHeader.width;
              height=bitmapV2->bitmapHeader.height;
              bitsPerPixel=bitmapV2->bitmapHeader.bitsPerPixel;
          }
          else
              return 0;
          break;
      case 40:
          if(bitmapV3x->bitmapHeader.compression==0)
          {
              if(bitmapV3x->bitmapHeader.planes==1)
              {
                  width=bitmapV3x->bitmapHeader.width;
                  height=bitmapV3x->bitmapHeader.height;
                  bitsPerPixel=bitmapV3x->bitmapHeader.bitsPerPixel;
              }
              else
                  return 0;
          }
          else if(bitmapV3x->bitmapHeader.compression==3)
          {
              if(bitmapV3->bitmapHeader.planes==1)
              {
                  width=bitmapV3->bitmapHeader.width;
                  height=bitmapV3->bitmapHeader.height;
                  bitsPerPixel=bitmapV3->bitmapHeader.bitsPerPixel;
              }
              else
                  return 0;

          }
          else
              return 0;
          break;
      case 108:
          if(bitmapV4x->bitmapHeader.compression==0)
          {
              if(bitmapV4x->bitmapHeader.planes==1)
              {
                  width=bitmapV4x->bitmapHeader.width;
                  height=bitmapV4x->bitmapHeader.height;
                  bitsPerPixel=bitmapV4x->bitmapHeader.bitsPerPixel;
              }
              else
                  return 0;
          }
          else if(bitmapV4x->bitmapHeader.compression==3)
          {
              if(bitmapV4->bitmapHeader.planes==1)
              {
                  width=bitmapV4->bitmapHeader.width;
                  height=bitmapV4->bitmapHeader.height;
                  bitsPerPixel=bitmapV4->bitmapHeader.bitsPerPixel;
              }
              else
                  return 0;

          }
          else
              return 0;
      default:
          return 0;
      }
  }
  else
  {
      return 0;
  }
//
//  widthTemp=width/zoom;
//  heightTemp=height/zoom;
//  while((widthTemp>MAX_X) || (heightTemp>MAX_Y))
//  {
//      zoom++;
//      widthTemp=width/zoom;
//      heightTemp=height/zoom;
//  }
//

  if(bitsPerPixel<=8)
  {
      if(bitsPerPixel==1)
          mask=mask1bit;
      if(bitsPerPixel==4)
          mask=mask4bit;
      if(bitsPerPixel==8)
          mask=mask8bit;
      bitsTotal=(8/bitsPerPixel);
      actualX = MAX_X*((MAX_Y/8)-1);
      actualXi=0;
      if(MAX_Y>height)
          heightMax=height;
      else
          heightMax=MAX_Y;

      heightMax/=8;

      if(MAX_X>width)
          widthMax=width;
      else
          widthMax=MAX_X;

      widthMax/=bitsTotal;


      for(long f=0; f<heightMax; f++)
      {
          for(long l=0; l<8; l++)
          {
              for(long i=0;i<widthMax; i++)
              {
                  for(long j=0; j<(bitsTotal); j++)
                  {
                      k=(i*(bitsTotal))+j;
                      if(image[actualXi+i]&mask[j])
                          Image[actualX+k]&=~mask1bit[l];
                      else
                          Image[actualX+k]|=mask1bit[l];
                  }
              }
              switch((width/(bitsTotal))%4)
              {      // skip any padding
                case 0: actualXi = actualXi + 0; break;
                case 1: actualXi = actualXi + 3; break;
                case 2: actualXi = actualXi + 2; break;
                case 3: actualXi = actualXi + 1; break;
              }
              actualXi+=width/(bitsTotal);
          }
          actualX-=MAX_X;
      }
      return 1;

  }
  else if(bitsPerPixel==16)
  {

  }
  else if(bitsPerPixel==24)
  {

  }
  else if(bitsPerPixel==32)
  {

  }

*/


/*
  long width = ptr[18], height = ptr[22], i, j;
  unsigned short Arreglox, Arregloy;
  unsigned char mask;
  // check for clipping
  if((height <= 0) ||              // bitmap is unexpectedly encoded in top-to-bottom pixel order
     ((width%2) != 0) ||           // must be even number of columns
     ((xpos + width) > MAX_X) || // right side cut off
     (ypos < (height - 1)) ||      // top cut off
     (ypos > MAX_Y))           { // bottom cut off
    return;
  }
  if(threshold > 14){
    threshold = 14;             // only full 'on' turns pixel on
  }
  // bitmaps are encoded backwards, so start at the bottom left corner of the image
  Arregloy = ypos/8;
  Arreglox = xpos + MAX_X*Arregloy;
  mask = ypos%8;                // row 0 to 7
  mask = 0x01<<mask;            // now stores a mask 0x01 to 0x80
  j = ptr[10];                  // byte 10 contains the offset where image data can be found
  for(i=1; i<=(width*height/2); i=i+1){
    // the left pixel is in the upper 4 bits
    if(((ptr[j]>>4)&0xF) > threshold){
      Arreglo[Arreglox] |= mask;
    } else{
      Arreglo[Arreglox] &= ~mask;
    }
    Arreglox = Arreglox + 1;
    // the right pixel is in the lower 4 bits
    if((ptr[j]&0xF) > threshold){
      Arreglo[Arreglox] |= mask;
    } else{
      Arreglo[Arreglox] &= ~mask;
    }
    Arreglox = Arreglox + 1;
    j = j + 1;
    if((i%(width/2)) == 0){     // at the end of a row
      if(mask > 0x01){
        mask = mask>>1;
      } else{
        mask = 0x80;
        Arregloy = Arregloy - 1;
      }
      Arreglox = xpos + MAX_X*Arregloy;
      // bitmaps are 32-bit word aligned
      switch((width/2)%4){      // skip any padding
        case 0: j = j + 0; break;
        case 1: j = j + 3; break;
        case 2: j = j + 2; break;
        case 3: j = j + 1; break;
      }
    }
  }
  */
//}

#endif
