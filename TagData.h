#pragma once
#include "Tags.h"

using namespace std;

class TagData
{
public:
	TagData();
	void ReadData(int *Integer, char *FileName, Tags *Tag);
	void OffsetToDataArea(int *Integer, bool Reverse, int TIFFPosition, unsigned int ExifOffset);
	~TagData();
};

