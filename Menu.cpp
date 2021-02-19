#include "stdafx.h"
#include "Menu.h"
#include <conio.h>
#include "ConsoleColor.h"
#include "ProgramRealisation.h"
#include "SetFileName.h"
#include <fstream>
#include <iostream>

using namespace std;

char MenuPoints[3][100]{ "������� ����", "����������� ����������", "�����", };//������ ����

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
		cout << "����������!" << endl;
		cout << "������� 'x', ����� ������� � ����." << endl << "����������:" << endl << "�������� �� ���� �������������� � ������� �������;" << endl << "��� ������ ��������� enter;" << endl << "��� �������� � ���� ��������� 'x'" << endl;
		mode = PAUSE;
		break;
	case MENU://������� � ����
		switch (dir)
		{
		case OPEN://������� ����
			FileName = SetFileName();
			File_selected = true;
			dir = STOP;
			ShowMenu(MenuPointer);
			break;;
		case SHOW://����������� ����������
			if (File_selected)
			{
				ifstream File(FileName, ios::binary);
				if (File.is_open())
					File.close();
				else
				{
					system("cls");
					cout << "�� ������� ������� ����! �� ��������� ������ ���� � �����." << endl;
				}
				ProgramRealisation Realisator(FileName);
				Realisator.ReadFile();
				Realisator.OutputResult();
			}
			else
			{
				system("cls");
				cout << "���� �� ������! ������� 'x', ����� ��������� � ����." << endl;
			}
			dir = STOP;
			mode = PAUSE;
			break;;
		case EXIT://����� �� ���������
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
