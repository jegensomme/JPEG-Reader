#include "stdafx.h"
#include "SetFileName.h"
#include "ConsoleColor.h"
#include "FileCatalog.h"
#include <iostream>
#include <conio.h> 

using namespace std;

void ShowList(int StringPointer)//Показать список файлов
{
	system("cls");
	for (int i = 0; i < 5; i++)
	{
		if (i == StringPointer)
			SetTextColor(LightMagenta);
		else
			SetTextColor(White);
		cout << Files[i] << endl;
	}
}

char* SetFileName()//Выбрать файл
{
	int StringPointer = 0;
	bool File_selected = false;

	ShowList(StringPointer);

	while (!File_selected)
	{
		if (_kbhit())
			switch (_getch())
			{
			case 72:
				if (StringPointer != 0)
					StringPointer--;
				ShowList(StringPointer);
			break;
			case 80:
				if (StringPointer != 4)
					StringPointer++;
				ShowList(StringPointer);
			break;
			case 13:
				File_selected = true;
			break;
			}
	}
	return Files[StringPointer];
}

