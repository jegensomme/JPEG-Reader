#pragma once
#include "MetaData.h"
#include "MetaInformation.h"

class ProgramRealisation
{
public:
	ProgramRealisation(char *FName);
	void ReadFile();
	void OutputResult();
	~ProgramRealisation();
private:
	Tags TagArray[100];

	bool Reverse = false;
	bool File_read = false;

	int TIFFPosition;

	char *FileName;

	MetaData MetaDataEditor;

	MetaInformation MetaInfEditor;
};


