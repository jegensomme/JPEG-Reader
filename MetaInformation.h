#pragma once
#include "MetaData_Ascii.h"
#include "Tags.h"

class MetaInformation
{
public:
	MetaInformation();
	void ReadInformation(bool Reverse, Tags *TagArray , char *FileName, int TIFFPosition);
	void ShowInformation(char *FileName);
	~MetaInformation();
private:
	char MetaInfList[100][100];

	MetaData_Ascii MetaDataEditor_Ascii;
};


