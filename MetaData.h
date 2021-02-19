#pragma once
#include "TagData.h"

class MetaData
{
public:
	MetaData();
	void ReadHead(bool *Reverse, char *FileName, int *TIFFPosition);//—читывание заголовков
	void ReadData(bool Reverse, Tags *TagArray, char *FileName, int TIFFPosition);//—читывание информации после тегов
	~MetaData();
private:
	TagData TagDataEditor;

	char ExifHead[5];
	char TIFFHead[3];

	short SOIMarker;
	short APP1Marker;
	short APP1DataSize;

	int TIFFData;
	int Integer;
};

