// 请勿更改此文件编码！
// 必须保持为默认编码GB2312，否则编译器会报array溢出错误！

#ifndef __FONT_H
#define __FONT_H

/****************************************8*16的点阵************************************/
const char code Ascll_16[][8]=	  
{
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// 0
  0x00,0x00,0x00,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x33,0x30,0x00,0x00,0x00,//! 1
  0x00,0x10,0x0C,0x06,0x10,0x0C,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//" 2
  0x40,0xC0,0x78,0x40,0xC0,0x78,0x40,0x00,0x04,0x3F,0x04,0x04,0x3F,0x04,0x04,0x00,//# 3
  0x00,0x70,0x88,0xFC,0x08,0x30,0x00,0x00,0x00,0x18,0x20,0xFF,0x21,0x1E,0x00,0x00,//$ 4
  0xF0,0x08,0xF0,0x00,0xE0,0x18,0x00,0x00,0x00,0x21,0x1C,0x03,0x1E,0x21,0x1E,0x00,//% 5
  0x00,0xF0,0x08,0x88,0x70,0x00,0x00,0x00,0x1E,0x21,0x23,0x24,0x19,0x27,0x21,0x10,//& 6
  0x10,0x16,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//' 7
  0x00,0x00,0x00,0xE0,0x18,0x04,0x02,0x00,0x00,0x00,0x00,0x07,0x18,0x20,0x40,0x00,//( 8
  0x00,0x02,0x04,0x18,0xE0,0x00,0x00,0x00,0x00,0x40,0x20,0x18,0x07,0x00,0x00,0x00,//) 9
  0x40,0x40,0x80,0xF0,0x80,0x40,0x40,0x00,0x02,0x02,0x01,0x0F,0x01,0x02,0x02,0x00,//* 10
  0x00,0x00,0x00,0xF0,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x1F,0x01,0x01,0x01,0x00,//+ 11
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xB0,0x70,0x00,0x00,0x00,0x00,0x00,//, 12
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,//- 13
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00,0x00,0x00,//. 14
  0x00,0x00,0x00,0x00,0x80,0x60,0x18,0x04,0x00,0x60,0x18,0x06,0x01,0x00,0x00,0x00,/// 15
  0x00,0xE0,0x10,0x08,0x08,0x10,0xE0,0x00,0x00,0x0F,0x10,0x20,0x20,0x10,0x0F,0x00,//0 16
  0x00,0x10,0x10,0xF8,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,//1 17
  0x00,0x70,0x08,0x08,0x08,0x88,0x70,0x00,0x00,0x30,0x28,0x24,0x22,0x21,0x30,0x00,//2 18
  0x00,0x30,0x08,0x88,0x88,0x48,0x30,0x00,0x00,0x18,0x20,0x20,0x20,0x11,0x0E,0x00,//3 19
  0x00,0x00,0xC0,0x20,0x10,0xF8,0x00,0x00,0x00,0x07,0x04,0x24,0x24,0x3F,0x24,0x00,//4 20
  0x00,0xF8,0x08,0x88,0x88,0x08,0x08,0x00,0x00,0x19,0x21,0x20,0x20,0x11,0x0E,0x00,//5 21
  0x00,0xE0,0x10,0x88,0x88,0x18,0x00,0x00,0x00,0x0F,0x11,0x20,0x20,0x11,0x0E,0x00,//6 22
  0x00,0x38,0x08,0x08,0xC8,0x38,0x08,0x00,0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x00,//7 23
  0x00,0x70,0x88,0x08,0x08,0x88,0x70,0x00,0x00,0x1C,0x22,0x21,0x21,0x22,0x1C,0x00,//8 24
  0x00,0xE0,0x10,0x08,0x08,0x10,0xE0,0x00,0x00,0x00,0x31,0x22,0x22,0x11,0x0F,0x00,//9 25
  0x00,0x00,0x00,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00,//: 26
  0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x60,0x00,0x00,0x00,0x00,//; 27
  0x00,0x00,0x80,0x40,0x20,0x10,0x08,0x00,0x00,0x01,0x02,0x04,0x08,0x10,0x20,0x00,//< 28
  0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x00,//= 29
  0x00,0x08,0x10,0x20,0x40,0x80,0x00,0x00,0x00,0x20,0x10,0x08,0x04,0x02,0x01,0x00,//> 30
  0x00,0x70,0x48,0x08,0x08,0x08,0xF0,0x00,0x00,0x00,0x00,0x30,0x36,0x01,0x00,0x00,//? 31
  0xC0,0x30,0xC8,0x28,0xE8,0x10,0xE0,0x00,0x07,0x18,0x27,0x24,0x23,0x14,0x0B,0x00,//@ 32
  0x00,0x00,0xC0,0x38,0xE0,0x00,0x00,0x00,0x20,0x3C,0x23,0x02,0x02,0x27,0x38,0x20,//A 33
  0x08,0xF8,0x88,0x88,0x88,0x70,0x00,0x00,0x20,0x3F,0x20,0x20,0x20,0x11,0x0E,0x00,//B 34
  0xC0,0x30,0x08,0x08,0x08,0x08,0x38,0x00,0x07,0x18,0x20,0x20,0x20,0x10,0x08,0x00,//C 35
  0x08,0xF8,0x08,0x08,0x08,0x10,0xE0,0x00,0x20,0x3F,0x20,0x20,0x20,0x10,0x0F,0x00,//D 36
  0x08,0xF8,0x88,0x88,0xE8,0x08,0x10,0x00,0x20,0x3F,0x20,0x20,0x23,0x20,0x18,0x00,//E 37
  0x08,0xF8,0x88,0x88,0xE8,0x08,0x10,0x00,0x20,0x3F,0x20,0x00,0x03,0x00,0x00,0x00,//F 38
  0xC0,0x30,0x08,0x08,0x08,0x38,0x00,0x00,0x07,0x18,0x20,0x20,0x22,0x1E,0x02,0x00,//G 39
  0x08,0xF8,0x08,0x00,0x00,0x08,0xF8,0x08,0x20,0x3F,0x21,0x01,0x01,0x21,0x3F,0x20,//H 40
  0x00,0x08,0x08,0xF8,0x08,0x08,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,//I 41
  0x00,0x00,0x08,0x08,0xF8,0x08,0x08,0x00,0xC0,0x80,0x80,0x80,0x7F,0x00,0x00,0x00,//J 42
  0x08,0xF8,0x88,0xC0,0x28,0x18,0x08,0x00,0x20,0x3F,0x20,0x01,0x26,0x38,0x20,0x00,//K 43
  0x08,0xF8,0x08,0x00,0x00,0x00,0x00,0x00,0x20,0x3F,0x20,0x20,0x20,0x20,0x30,0x00,//L 44
  0x08,0xF8,0xF8,0x00,0xF8,0xF8,0x08,0x00,0x20,0x3F,0x00,0x3F,0x00,0x3F,0x20,0x00,//M 45
  0x08,0xF8,0x30,0xC0,0x00,0x08,0xF8,0x08,0x20,0x3F,0x20,0x00,0x07,0x18,0x3F,0x00,//N 46
  0xE0,0x10,0x08,0x08,0x08,0x10,0xE0,0x00,0x0F,0x10,0x20,0x20,0x20,0x10,0x0F,0x00,//O 47
  0x08,0xF8,0x08,0x08,0x08,0x08,0xF0,0x00,0x20,0x3F,0x21,0x01,0x01,0x01,0x00,0x00,//P 48
  0xE0,0x10,0x08,0x08,0x08,0x10,0xE0,0x00,0x0F,0x18,0x24,0x24,0x38,0x50,0x4F,0x00,//Q 49
  0x08,0xF8,0x88,0x88,0x88,0x88,0x70,0x00,0x20,0x3F,0x20,0x00,0x03,0x0C,0x30,0x20,//R 50
  0x00,0x70,0x88,0x08,0x08,0x08,0x38,0x00,0x00,0x38,0x20,0x21,0x21,0x22,0x1C,0x00,//S 51
  0x18,0x08,0x08,0xF8,0x08,0x08,0x18,0x00,0x00,0x00,0x20,0x3F,0x20,0x00,0x00,0x00,//T 52
  0x08,0xF8,0x08,0x00,0x00,0x08,0xF8,0x08,0x00,0x1F,0x20,0x20,0x20,0x20,0x1F,0x00,//U 53
  0x08,0x78,0x88,0x00,0x00,0xC8,0x38,0x08,0x00,0x00,0x07,0x38,0x0E,0x01,0x00,0x00,//V 54
  0xF8,0x08,0x00,0xF8,0x00,0x08,0xF8,0x00,0x03,0x3C,0x07,0x00,0x07,0x3C,0x03,0x00,//W 55
  0x08,0x18,0x68,0x80,0x80,0x68,0x18,0x08,0x20,0x30,0x2C,0x03,0x03,0x2C,0x30,0x20,//X 56
  0x08,0x38,0xC8,0x00,0xC8,0x38,0x08,0x00,0x00,0x00,0x20,0x3F,0x20,0x00,0x00,0x00,//Y 57
  0x10,0x08,0x08,0x08,0xC8,0x38,0x08,0x00,0x20,0x38,0x26,0x21,0x20,0x20,0x18,0x00,//Z 58
  0x00,0x00,0x00,0xFE,0x02,0x02,0x02,0x00,0x00,0x00,0x00,0x7F,0x40,0x40,0x40,0x00,//[ 59
  0x00,0x0C,0x30,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x06,0x38,0xC0,0x00,//\ 60
  0x00,0x02,0x02,0x02,0xFE,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x7F,0x00,0x00,0x00,//] 61
  0x00,0x00,0x04,0x02,0x02,0x02,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//^ 62
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,//_ 63
  0x00,0x02,0x02,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//` 64
  0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x19,0x24,0x22,0x22,0x22,0x3F,0x20,//a 65
  0x08,0xF8,0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x3F,0x11,0x20,0x20,0x11,0x0E,0x00,//b 66
  0x00,0x00,0x00,0x80,0x80,0x80,0x00,0x00,0x00,0x0E,0x11,0x20,0x20,0x20,0x11,0x00,//c 67
  0x00,0x00,0x00,0x80,0x80,0x88,0xF8,0x00,0x00,0x0E,0x11,0x20,0x20,0x10,0x3F,0x20,//d 68
  0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x1F,0x22,0x22,0x22,0x22,0x13,0x00,//e 69
  0x00,0x80,0x80,0xF0,0x88,0x88,0x88,0x18,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,//f 70
  0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x6B,0x94,0x94,0x94,0x93,0x60,0x00,//g 71
  0x08,0xF8,0x00,0x80,0x80,0x80,0x00,0x00,0x20,0x3F,0x21,0x00,0x00,0x20,0x3F,0x20,//h 72
  0x00,0x80,0x98,0x98,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,//i 73
  0x00,0x00,0x00,0x80,0x98,0x98,0x00,0x00,0x00,0xC0,0x80,0x80,0x80,0x7F,0x00,0x00,//j 74
  0x08,0xF8,0x00,0x00,0x80,0x80,0x80,0x00,0x20,0x3F,0x24,0x02,0x2D,0x30,0x20,0x00,//k 75
  0x00,0x08,0x08,0xF8,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,//l 76
  0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x20,0x3F,0x20,0x00,0x3F,0x20,0x00,0x3F,//m 77
  0x80,0x80,0x00,0x80,0x80,0x80,0x00,0x00,0x20,0x3F,0x21,0x00,0x00,0x20,0x3F,0x20,//n 78
  0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x1F,0x20,0x20,0x20,0x20,0x1F,0x00,//o 79
  0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0x80,0xFF,0xA1,0x20,0x20,0x11,0x0E,0x00,//p 80
  0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x0E,0x11,0x20,0x20,0xA0,0xFF,0x80,//q 81
  0x80,0x80,0x80,0x00,0x80,0x80,0x80,0x00,0x20,0x20,0x3F,0x21,0x20,0x00,0x01,0x00,//r 82
  0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x33,0x24,0x24,0x24,0x24,0x19,0x00,//s 83
  0x00,0x80,0x80,0xE0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x1F,0x20,0x20,0x00,0x00,//t 84
  0x80,0x80,0x00,0x00,0x00,0x80,0x80,0x00,0x00,0x1F,0x20,0x20,0x20,0x10,0x3F,0x20,//u 85
  0x80,0x80,0x80,0x00,0x00,0x80,0x80,0x80,0x00,0x01,0x0E,0x30,0x08,0x06,0x01,0x00,//v 86
  0x80,0x80,0x00,0x80,0x00,0x80,0x80,0x80,0x0F,0x30,0x0C,0x03,0x0C,0x30,0x0F,0x00,//w 87
  0x00,0x80,0x80,0x00,0x80,0x80,0x80,0x00,0x00,0x20,0x31,0x2E,0x0E,0x31,0x20,0x00,//x 88
  0x80,0x80,0x80,0x00,0x00,0x80,0x80,0x80,0x80,0x81,0x8E,0x70,0x18,0x06,0x01,0x00,//y 89
  0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x21,0x30,0x2C,0x22,0x21,0x30,0x00,//z 90
  0x00,0x00,0x00,0x00,0x80,0x7C,0x02,0x02,0x00,0x00,0x00,0x00,0x00,0x3F,0x40,0x40,//{ 91
  0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,//| 92
  0x00,0x02,0x02,0x7C,0x80,0x00,0x00,0x00,0x00,0x40,0x40,0x3F,0x00,0x00,0x00,0x00,//} 93
  0x00,0x06,0x01,0x01,0x02,0x02,0x04,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//~ 94
};

/* ========= 时间显示字库16*32 ========= */
const char code  lib_num1632[12][64]={
/*---0---*/

{0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0x40,0x40,0x40,0x80,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0xF0,0xFE,0x0F,0x01,0x00,0x00,0x00,0x00,0x01,0x07,0xFE,0xF0,0x00,0x00,
0x00,0x00,0x3F,0xFF,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xFF,0x3F,0x00,0x00,
0x00,0x00,0x00,0x01,0x03,0x06,0x0C,0x08,0x08,0x08,0x06,0x03,0x01,0x00,0x00,0x00},/*"0",0*/


/*---1---*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x01,0x01,0x01,0x01,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x08,0x08,0x08,0x0C,0x0F,0x0F,0x0C,0x08,0x08,0x08,0x00,0x00,0x00},/*"1",0*/

/*---2---*/
{0x00,0x00,0x00,0x00,0x80,0x40,0x40,0x40,0x40,0x40,0xC0,0x80,0x80,0x00,0x00,0x00,
0x00,0x00,0x1E,0x19,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC1,0xFF,0x3E,0x00,0x00,
0x00,0x00,0x00,0x00,0x80,0x40,0x30,0x18,0x0C,0x06,0x03,0x01,0x00,0xC0,0x00,0x00,
0x00,0x00,0x0E,0x0D,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0E,0x03,0x00,0x00},/*"2",0*/

{0x00,0x00,0x00,0x80,0x80,0x40,0x40,0x40,0x40,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x0F,0x0F,0x00,0x00,0x00,0x00,0x00,0x80,0xC1,0x7F,0x3E,0x00,0x00,0x00,
0x00,0x00,0xC0,0xC0,0x00,0x00,0x01,0x01,0x01,0x03,0x02,0x06,0xFC,0xF0,0x00,0x00,
0x00,0x00,0x03,0x07,0x04,0x08,0x08,0x08,0x08,0x08,0x04,0x06,0x03,0x00,0x00,0x00},/*"3",1*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x80,0x60,0x10,0x0C,0x03,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,
0x00,0x30,0x2C,0x26,0x21,0x20,0x20,0x20,0x20,0xFF,0xFF,0x20,0x20,0x20,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x08,0x08,0x0F,0x0F,0x08,0x08,0x08,0x00,0x00},/*"4",2*/

{0x00,0x00,0x00,0x00,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x00,0x00,
0x00,0x00,0x00,0xFF,0x00,0x80,0x40,0x40,0x40,0x40,0xC0,0x80,0x00,0x00,0x00,0x00,
0x00,0x00,0xC0,0xC3,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFF,0xFC,0x00,0x00,
0x00,0x00,0x03,0x04,0x04,0x08,0x08,0x08,0x08,0x08,0x04,0x07,0x03,0x00,0x00,0x00},/*"5",3*/

{0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x40,0x40,0x40,0x40,0x80,0x80,0x00,0x00,0x00,
0x00,0x00,0xE0,0xFC,0x07,0x81,0xC0,0x40,0x40,0x40,0xC0,0x83,0x03,0x00,0x00,0x00,
0x00,0x00,0x7F,0xFF,0x83,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFF,0xFC,0x00,0x00,
0x00,0x00,0x00,0x01,0x07,0x06,0x0C,0x08,0x08,0x08,0x0C,0x06,0x03,0x00,0x00,0x00},/*"6",4*/

{0x00,0x00,0x00,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x00,0x00,
0x00,0x00,0x0E,0x03,0x00,0x00,0x00,0x00,0x00,0xE0,0x18,0x06,0x01,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xFC,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"7",5*/

{0x00,0x00,0x00,0x00,0x80,0xC0,0x40,0x40,0x40,0x40,0xC0,0x80,0x00,0x00,0x00,0x00,
0x00,0x00,0x3E,0x7F,0xF1,0xC0,0xC0,0x80,0x00,0x00,0x80,0x41,0x7F,0x1E,0x00,0x00,
0x00,0xF0,0xFC,0x0E,0x02,0x01,0x01,0x01,0x03,0x07,0x0E,0x1E,0xFC,0xF0,0x00,0x00,
0x00,0x01,0x03,0x06,0x04,0x08,0x08,0x08,0x08,0x08,0x04,0x06,0x03,0x01,0x00,0x00},/*"8",6*/

{0x00,0x00,0x00,0x80,0x80,0x40,0x40,0x40,0x40,0x40,0x80,0x00,0x00,0x00,0x00,0x00,
0x00,0xFC,0xFF,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xFE,0xF8,0x00,0x00,
0x00,0x01,0x03,0x07,0x0C,0x08,0x08,0x08,0x08,0x04,0x06,0xE1,0x7F,0x1F,0x00,0x00,
0x00,0x00,0x07,0x07,0x08,0x08,0x08,0x08,0x0C,0x06,0x03,0x01,0x00,0x00,0x00,0x00},/*"9",7*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xE0,0xE0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x0F,0x0F,0x06,0x00,0x00,0x00,0x00,0x00,0x00},/*":",8*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*" ",8*/

};

struct s_font
{
    unsigned char gbk_font[32];
    unsigned char gbn_bum[2];
};

const struct s_font code GBK16[]=	
{    
    0x00,0x80,0x60,0xF8,0x07,0x40,0x20,0x18,0x0F,0x08,0xC8,0x08,0x08,0x28,0x18,0x00,
    0x01,0x00,0x00,0xFF,0x00,0x10,0x0C,0x03,0x40,0x80,0x7F,0x00,0x01,0x06,0x18,0x00,"你",//0

    0x10,0x10,0xF0,0x1F,0x10,0xF0,0x00,0x80,0x82,0x82,0xE2,0x92,0x8A,0x86,0x80,0x00,
    0x40,0x22,0x15,0x08,0x16,0x61,0x00,0x00,0x40,0x80,0x7F,0x00,0x00,0x00,0x00,0x00,"好",//1

    0x04,0x24,0x44,0x84,0x64,0x9C,0x40,0x30,0x0F,0xC8,0x08,0x08,0x28,0x18,0x00,0x00,
    0x10,0x08,0x06,0x01,0x82,0x4C,0x20,0x18,0x06,0x01,0x06,0x18,0x20,0x40,0x80,0x00,"欢",//2

    0x40,0x40,0x42,0xCC,0x00,0x00,0xFC,0x04,0x02,0x00,0xFC,0x04,0x04,0xFC,0x00,0x00,
    0x00,0x40,0x20,0x1F,0x20,0x40,0x4F,0x44,0x42,0x40,0x7F,0x42,0x44,0x43,0x40,0x00,"迎",//3

    0x80,0x60,0xF8,0x07,0x04,0xE4,0x24,0x24,0x24,0xFF,0x24,0x24,0x24,0xE4,0x04,0x00,
    0x00,0x00,0xFF,0x00,0x80,0x81,0x45,0x29,0x11,0x2F,0x41,0x41,0x81,0x81,0x80,0x00,"使",//4

    0x00,0x00,0xFE,0x22,0x22,0x22,0x22,0xFE,0x22,0x22,0x22,0x22,0xFE,0x00,0x00,0x00,
    0x80,0x60,0x1F,0x02,0x02,0x02,0x02,0x7F,0x02,0x02,0x42,0x82,0x7F,0x00,0x00,0x00,"用",//5

    0x02,0xFA,0x82,0x82,0xFE,0x80,0x00,0xFE,0x02,0x12,0x62,0x82,0x62,0x1A,0x02,0x00,
    0x08,0x18,0x48,0x84,0x44,0x3F,0x00,0x7F,0x50,0x48,0x46,0x41,0x46,0x58,0x40,0x00,"驱\xfd",//6

    0x40,0x44,0xC4,0x44,0x44,0x44,0x40,0x10,0x10,0xFF,0x10,0x10,0x10,0xF0,0x00,0x00,
    0x10,0x3C,0x13,0x10,0x14,0xB8,0x40,0x30,0x0E,0x01,0x40,0x80,0x40,0x3F,0x00,0x00,"动",//7

    0x00,0xF8,0x0C,0x0B,0x08,0x08,0xF8,0x40,0x30,0x8F,0x08,0x08,0x08,0xF8,0x00,0x00,
    0x00,0x7F,0x21,0x21,0x21,0x21,0x7F,0x00,0x00,0x00,0x43,0x80,0x40,0x3F,0x00,0x00,"的",//8

    0x00,0x00,0xFE,0x02,0x42,0x42,0x42,0x42,0xFA,0x42,0x42,0x42,0x42,0xC2,0x02,0x00,
    0x80,0x60,0x1F,0x80,0x40,0x20,0x18,0x06,0x01,0x00,0x40,0x80,0x40,0x3F,0x00,0x00,"历",//9

    0x24,0x24,0xA4,0xFE,0x23,0x22,0x00,0x3E,0x22,0x22,0x22,0x22,0x22,0x3E,0x00,0x00,
    0x08,0x06,0x01,0xFF,0x01,0x06,0x40,0x49,0x49,0x49,0x7F,0x49,0x49,0x49,0x41,0x00,"程",//10

    0x02,0xF2,0x02,0x02,0xF2,0x92,0x92,0xF2,0x92,0x92,0xF2,0x02,0x02,0xF2,0x02,0x00,
    0x00,0x7F,0x40,0x40,0x4F,0x48,0x48,0x4F,0x48,0x48,0x4F,0x40,0x40,0xFF,0x00,0x00,"画",//11

    0x00,0x00,0xC0,0x40,0x40,0x40,0x7F,0x48,0x48,0x48,0x48,0xC8,0x08,0x08,0x00,0x00,
    0x80,0x40,0x37,0x04,0x04,0x14,0x64,0x04,0x14,0x64,0x04,0x07,0x10,0xE0,0x00,0x00,"点",//12

    0x10,0x60,0x02,0x8C,0x00,0xFE,0x02,0xF2,0x02,0xFE,0x00,0xF8,0x00,0xFF,0x00,0x00,
    0x04,0x04,0x7E,0x01,0x80,0x47,0x30,0x0F,0x10,0x27,0x00,0x47,0x80,0x7F,0x00,0x00,"测",//13

    0x40,0x40,0x42,0xCC,0x00,0x90,0x90,0x90,0x90,0x90,0xFF,0x10,0x11,0x16,0x10,0x00,
    0x00,0x00,0x00,0x3F,0x10,0x28,0x60,0x3F,0x10,0x10,0x01,0x0E,0x30,0x40,0xF0,0x00,"试",//14

    0x20,0x30,0xAC,0x63,0x20,0x18,0x80,0x90,0x90,0xFF,0x90,0x49,0x4A,0x48,0x40,0x00,
    0x22,0x67,0x22,0x12,0x12,0x12,0x40,0x40,0x20,0x13,0x0C,0x14,0x22,0x41,0xF8,0x00,"线",//15
    
    0x00,0xFE,0x02,0x82,0xBA,0xAA,0xAA,0xAA,0xAA,0xAA,0xBA,0x82,0x02,0xFE,0x00,0x00,
    0x00,0xFF,0x40,0x4F,0x60,0x50,0x48,0x46,0x48,0x50,0x60,0x4F,0x40,0xFF,0x00,0x00,"圆",//16   

    0x20,0x20,0x20,0x20,0x20,0x20,0x20,0xFF,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x00,
    0x80,0x80,0x40,0x20,0x10,0x0C,0x03,0x00,0x03,0x0C,0x10,0x20,0x40,0x80,0x80,0x00,"大",//17

    0x10,0x0C,0x04,0x24,0x24,0x24,0x25,0x26,0xA4,0x64,0x24,0x04,0x04,0x14,0x0C,0x00,
    0x02,0x02,0x02,0x02,0x02,0x42,0x82,0x7F,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x00,"字",//18
    
    0x00,0x00,0xFC,0x24,0x24,0xE4,0x24,0x24,0x22,0x22,0x22,0xA3,0x62,0x00,0x00,0x00,
    0x40,0x30,0x8F,0x80,0x40,0x40,0x23,0x14,0x08,0x14,0x22,0x41,0x40,0x80,0x80,0x00,"反",//19

    0x00,0x00,0x00,0xFE,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0xFE,0x00,0x00,0x00,0x00,
    0x40,0x42,0x44,0x58,0x40,0x7F,0x40,0x40,0x40,0x7F,0x40,0x50,0x48,0x46,0x40,0x00,"显",//20

    0x40,0x40,0x42,0xCC,0x00,0x08,0x28,0x48,0x89,0x0E,0xC8,0x38,0x08,0x08,0x00,0x00,
    0x00,0x40,0x20,0x1F,0x20,0x50,0x48,0x44,0x42,0x41,0x42,0x44,0x58,0x40,0x40,0x00,"这",//21

    0x00,0x00,0x00,0x7F,0x49,0x49,0x49,0x49,0x49,0x49,0x49,0x7F,0x00,0x00,0x00,0x00,
    0x81,0x41,0x21,0x1D,0x21,0x41,0x81,0xFF,0x89,0x89,0x89,0x89,0x89,0x81,0x81,0x00,"是",//22

    0x00,0x02,0x02,0xC2,0x02,0x02,0x02,0xFE,0x82,0x82,0x82,0x82,0x82,0x02,0x00,0x00,
    0x40,0x40,0x40,0x7F,0x40,0x40,0x40,0x7F,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,"正\xfd",//23

    0x04,0x44,0x24,0x14,0x04,0x7C,0x05,0x06,0x04,0x7C,0x04,0x14,0x24,0x44,0x04,0x00,
    0x80,0x80,0x81,0x41,0x43,0x25,0x29,0x11,0x29,0x25,0x43,0x41,0x80,0x80,0x80,0x00,"变",//24

    0x20,0x20,0x20,0xBE,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xBE,0x20,0x20,0x20,0x00,
    0x00,0x80,0x80,0xAF,0xAA,0xAA,0xAA,0xFF,0xAA,0xAA,0xAA,0xAF,0x80,0x80,0x00,0x00,"量",//25

    0x00,0x00,0x00,0xFE,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0xFE,0x00,0x00,0x00,0x00,
    0x40,0x42,0x44,0x58,0x40,0x7F,0x40,0x40,0x40,0x7F,0x40,0x50,0x48,0x46,0x40,0x00,"显",//26

    0x40,0x40,0x42,0x42,0x42,0x42,0x42,0xC2,0x42,0x42,0x42,0x42,0x42,0x40,0x40,0x00,
    0x20,0x10,0x08,0x06,0x00,0x40,0x80,0x7F,0x00,0x00,0x00,0x02,0x04,0x08,0x30,0x00,"示",//27
};

#endif 