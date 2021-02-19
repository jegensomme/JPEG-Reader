#include "stdafx.h"
#include "ConsoleColor.h"

void SetTextColor(Color text)//Установить цвет текста
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, text);
}