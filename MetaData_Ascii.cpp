#include "stdafx.h"
#include "MetaData_Ascii.h"
#include <fstream>
#include "ReverseByte.h"

using namespace std;

MetaData_Ascii::MetaData_Ascii()
{
}

void MetaData_Ascii::ReadData_Ascii(char *FileName, Tags Tag, int TIFFPosition, bool Reverse, char *AsciiData)//—читывание данных типа строк Ascii
{
	ifstream File(FileName, ios::binary);

	if (Reverse)
	{
		Tag.DataArr_2 = LongReverse((unsigned int)Tag.DataArr_2);
		Tag.DataArr_1 = LongReverse((unsigned int)Tag.DataArr_1);
	}

	if (Tag.DataArr_1 == 4)
		File.seekg(Tag.TagPosition + 6, ios::beg);
	else
		File.seekg(Tag.DataArr_2 + TIFFPosition, ios::beg);
	File.read(AsciiData, (unsigned int)Tag.DataArr_1);

	File.close();
}


MetaData_Ascii::~MetaData_Ascii()
{
}
