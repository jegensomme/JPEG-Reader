//Курсовая работа на тему: "Считывание и редактирование метаданных графических изображений
//Выполняют: Кублицкий В.О. и Кудинов И.А.

#include "stdafx.h"
#include "Menu.h"
#include <fstream>
#include "ConsoleColor.h"
#include <iostream>

using namespace std;

int main()
{
	bool ProgramWork = true;
	Menu User(ProgramWork, START);

	while (ProgramWork)
	{
		User.Input();
		User.Action();
	}

	return 0;
}
