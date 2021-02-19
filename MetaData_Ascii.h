#pragma once
#include "Tags.h"

using namespace std;

class MetaData_Ascii
{
public:
	MetaData_Ascii();
	void ReadData_Ascii(char *FileName, Tags Tag, int TIFFPosition, bool Reverse, char *AsciiData);
	~MetaData_Ascii();
};


