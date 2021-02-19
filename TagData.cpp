#include "stdafx.h"
#include "TagData.h"
#include "ReverseByte.h"
#include <fstream>
#include <iostream>

using namespace std;

TagData::TagData()
{
}

void TagData::ReadData(int *Integer, char *FileName, Tags *Tag)//—читывание информации с тегов
{
	ifstream File(FileName, ios::binary);
	File.seekg(*Integer, ios::beg);

	Tag->Availability = true;
	Tag->TagPosition = (int)File.tellg();
	File.read((char*)&Tag->DataFormat, 2);
	File.read((char*)&Tag->DataArr_1, 4);
	File.read((char*)&Tag->DataArr_2, 4);

	*Integer = (int)File.tellg();

	File.close();
}

void TagData::OffsetToDataArea(int *Integer, bool Reverse, int TIFFPosition, unsigned int ExifOffset)//—мещение к следующей области данных
{
	if (Reverse)
		*Integer = LongReverse((unsigned int)ExifOffset) + TIFFPosition;
	else
		*Integer = (unsigned)ExifOffset + TIFFPosition;
}

TagData::~TagData()
{
}
