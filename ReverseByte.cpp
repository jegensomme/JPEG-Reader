#include "stdafx.h"
#include "ReverseByte.h"

unsigned short ShortReverse(unsigned short x)//Изменение порядка для 2 байт
{
	x = (x & 0xFF) << 8 | (x & 0xFF00) >> 8;
	return x;
}

unsigned int LongReverse(unsigned int x)//Изменение порядка для 4 байт
{
	x = (x & 0x00FF00FF) << 8 | (x & 0xFF00FF00) >> 8;
	x = (x & 0x0000FFFF) << 16 | (x & 0xFFFF0000) >> 16;
	return x;
}
