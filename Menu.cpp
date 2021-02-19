#include "stdafx.h"
#include "Menu.h"
#include <conio.h>
#include "ConsoleColor.h"
#include "ProgramRealisation.h"
#include "SetFileName.h"
#include <fstream>
#include <iostream>

using namespace std;

char MenuPoints[3][100]{ "Выбрать файл", "Просмотреть информацию", "Выход", };//Пункты меню

void ShowMenu(int MenuPointer)
{
	system("cls");
	for (int i = 0; i < 3; i++)
	{
		if (i == MenuPointer)
			SetTextColor(LightMagenta);
		else
			SetTextColor(White);
		cout << MenuPoints[i] << endl;
	}
}

Menu::Menu(bool &ProgWork, Modes m)
	:ProgramWork(ProgWork), mode(m)
{
}

void Menu::Action()
{
	switch (mode)
	{
	case START:
		system("cls");
		setlocale(LC_ALL, "rus");
		SetTextColor(White);
		cout << "Здравствуй!" << endl;
		cout << "Нажмите 'x', чтобы попасть в меню." << endl << "Инструкция:" << endl << "Движение по меню осуществляется с помощью стрелок;" << endl << "Для выбора нажимайте enter;" << endl << "Для возврата в меню нажимайте 'x'" << endl;
		mode = PAUSE;
		break;
	case MENU://Возврат к меню
		switch (dir)
		{
		case OPEN://Открыть файл
			FileName = SetFileName();
			File_selected = true;
			dir = STOP;
			ShowMenu(MenuPointer);
			break;;
		case SHOW://Просмотреть информацию
			if (File_selected)
			{
				ifstream File(FileName, ios::binary);
				if (File.is_open())
					File.close();
				else
				{
					system("cls");
					cout << "Не удалось открыть файл! Не правильно указан путь к файлу." << endl;
				}
				ProgramRealisation Realisator(FileName);
				Realisator.ReadFile();
				Realisator.OutputResult();
			}
			else
			{
				system("cls");
				cout << "Файл не найден! Нажмите 'x', чтобы вернуться в меню." << endl;
			}
			dir = STOP;
			mode = PAUSE;
			break;;
		case EXIT://Выход из программы
			ProgramWork = false;
			break;;
		}
		break;
	}

}

void Menu::Input()
{
	if (_kbhit())
		switch (_getch())
		{
		case 72:
			if (MenuPointer != 0 && mode == MENU)
			{
				MenuPointer--;
				ShowMenu(MenuPointer);
			}
			break;;
		case 80:
			if (MenuPointer != 2 && mode == MENU)
			{
				MenuPointer++;
				ShowMenu(MenuPointer);
			}
			break;;
		case 13:
			if (mode == MENU)
				dir = (Comands)MenuPointer;
			break;;
		case 'x':
			mode = MENU;
			ShowMenu(MenuPointer);
			break;;
		}
}

Menu::~Menu()
{
}
