#include "stdafx.h"
#include "ProgramRealisation.h"
#include <conio.h>
#include "ConsoleColor.h"
#include <iostream>

using namespace std;

ProgramRealisation::ProgramRealisation(char *FName)
	:FileName(FName)
{
}

void ProgramRealisation::ReadFile()//���������� �����
{
		MetaDataEditor.ReadHead(&Reverse, FileName, &TIFFPosition);
		MetaDataEditor.ReadData(Reverse, TagArray, FileName, TIFFPosition);
		File_read = true;
}
void ProgramRealisation::OutputResult()//����� ����������
{
		MetaInfEditor.ReadInformation(Reverse, TagArray, FileName, TIFFPosition);
		MetaInfEditor.ShowInformation(FileName);
}

ProgramRealisation::~ProgramRealisation()
{
}
