#include "stdafx.h"
#include "MetaInformation.h"
#include "TypeMetaInf.h"
#include "MetaInfPointers.h"
#include "ConsoleColor.h"
#include "ReverseByte.h"
#include "MetaData.h"
#include <iostream>
#include <conio.h>

using namespace std;

MetaInformation::MetaInformation()
{
}

void MetaInformation::ReadInformation(bool Reverse, Tags *TagArray, char *FileName, int TIFFPosition)//Обработка данных тегов
{
	for (int i = 0; i < 27; i++)
		switch ((MetaInfPointers)i)
		{
		case Name:
			if (TagArray[ImageDescription_t].Availability)
				MetaDataEditor_Ascii.ReadData_Ascii(FileName, TagArray[ImageDescription_t], TIFFPosition, Reverse, MetaInfList[i]);
			else
				strcpy_s(MetaInfList[i], "нет данных");
		break;
		case Authors:
			if (TagArray[Artist_t].Availability)
				MetaDataEditor_Ascii.ReadData_Ascii(FileName, TagArray[Artist_t], TIFFPosition, Reverse, MetaInfList[i]);
			else
				strcpy_s(MetaInfList[i], "нет данных");
		break;
		case Date:
			if (TagArray[DateTimeOriginal_t].Availability)
				MetaDataEditor_Ascii.ReadData_Ascii(FileName, TagArray[DateTimeOriginal_t], TIFFPosition, Reverse, MetaInfList[i]);
			else
				strcpy_s(MetaInfList[i], "нет данных");
		break;
		case ProgramName:
			if (TagArray[Software_t].Availability)
				MetaDataEditor_Ascii.ReadData_Ascii(FileName, TagArray[Software_t], TIFFPosition, Reverse, MetaInfList[i]);
			else
				strcpy_s(MetaInfList[i], "нет данных");
		break;
		case Width:
			if (TagArray[ImageWidth_t].Availability)
			{
				if (Reverse)
					sprintf_s(MetaInfList[i], "%d", ShortReverse((unsigned short)TagArray[ImageWidth_t].DataArr_2));
				else
					sprintf_s(MetaInfList[i], "%d", TagArray[ImageWidth_t].DataArr_2);
			}
			else
				strcpy_s(MetaInfList[i], "нет данных");
		break;
		case Height:
			if (TagArray[ImageLength_t].Availability)
			{
				if (Reverse)
					sprintf_s(MetaInfList[i], "%d", ShortReverse((unsigned short)TagArray[ImageLength_t].DataArr_2));
				else
					sprintf_s(MetaInfList[i], "%d", TagArray[ImageLength_t].DataArr_2);
			}
			else
				strcpy_s(MetaInfList[i], "нет данных");
		break;
		case XResolution:
			if (TagArray[XResolution_t].Availability)
			{
				if (Reverse)
					sprintf_s(MetaInfList[i], "%d", LongReverse((unsigned int)TagArray[XResolution_t].DataArr_2));
				else
					sprintf_s(MetaInfList[i], "%d", TagArray[XResolution_t].DataArr_2);

				strcat_s(MetaInfList[i], " точек на дюйм");
			}
			else
				strcpy_s(MetaInfList[i], "нет данных");
		break;
		case YResolution:
			if (TagArray[YResolution_t].Availability)
			{
				if (Reverse)
					sprintf_s(MetaInfList[i], "%d", LongReverse((unsigned int)TagArray[YResolution_t].DataArr_2));
				else
					sprintf_s(MetaInfList[i], "%d", TagArray[YResolution_t].DataArr_2);

				strcat_s(MetaInfList[i], " точек на дюйм");
			}
			else
				strcpy_s(MetaInfList[i], "нет данных");
		break;
		case ResolutionUnit:
			if (TagArray[ResolutionUnit_t].Availability)
			{
				unsigned short Data = (unsigned short)TagArray[ResolutionUnit_t].DataArr_2;
				if (Reverse)
					Data = ShortReverse((unsigned short)TagArray[ResolutionUnit_t].DataArr_2);
				switch (Data)
				{
				case 1:
					strcpy_s(MetaInfList[i], "нет");
				    break;
				case 2:
					strcpy_s(MetaInfList[i], "дюйм");
				    break;
				case 3:
					strcpy_s(MetaInfList[i], "сантиметр");
				    break;
				}
			}
			else
				strcpy_s(MetaInfList[i], "нет данных");
		break;
		case ColorSpace:
			if (TagArray[ColorSpace_t].Availability)
			{
				unsigned short Data = (unsigned short)TagArray[ColorSpace_t].DataArr_2;
				if (Reverse)
					Data = ShortReverse((unsigned short)TagArray[ColorSpace_t].DataArr_2);
				if (Data == 1)
					strcpy_s(MetaInfList[i], "sRGB");
			}
			else
				strcpy_s(MetaInfList[i], "нет данных");
		break;
		case CameraMake:
			if (TagArray[Make_t].Availability)
				MetaDataEditor_Ascii.ReadData_Ascii(FileName, TagArray[Make_t], TIFFPosition, Reverse, MetaInfList[i]);
			else
				strcpy_s(MetaInfList[i], "нет данных");
		break;
		case CameraModel:
			if (TagArray[Model_t].Availability)
				MetaDataEditor_Ascii.ReadData_Ascii(FileName, TagArray[Model_t], TIFFPosition, Reverse, MetaInfList[i]);
			else
				strcpy_s(MetaInfList[i], "нет данных");
		break;
		case Aperture:
			if (TagArray[ApertureValue_t].Availability)
			{
				char str[20];

				if (Reverse)
				{
					sprintf_s(MetaInfList[i], "%d", LongReverse((unsigned int)TagArray[ApertureValue_t].DataArr_1));
					sprintf_s(str, "%d", LongReverse((unsigned int)TagArray[ApertureValue_t].DataArr_2));
				}
				else
				{
					sprintf_s(MetaInfList[i], "%d", TagArray[ApertureValue_t].DataArr_1);
					sprintf_s(str, "%d", TagArray[ApertureValue_t].DataArr_2);
				}

				strcat_s(MetaInfList[i], "/");
				strcat_s(MetaInfList[i], str);
			}
			else
				strcpy_s(MetaInfList[i], "нет данных");
		break;
		case ShutterSpeed:
			if (TagArray[ApertureValue_t].Availability)
			{
				char str[20];

				if (Reverse)
				{
					sprintf_s(MetaInfList[i], "%d", LongReverse((unsigned int)TagArray[ShutterSpeedValue_t].DataArr_1));
					sprintf_s(str, "%d", LongReverse((unsigned int)TagArray[ShutterSpeedValue_t].DataArr_2));
				}
				else
				{
					sprintf_s(MetaInfList[i], "%d", TagArray[ShutterSpeedValue_t].DataArr_1);
					sprintf_s(str, "%d", TagArray[ShutterSpeedValue_t].DataArr_2);
				}

				strcat_s(MetaInfList[i], "/");
				strcat_s(MetaInfList[i], str);
				strcat_s(MetaInfList[i], " c");
			}
			else
				strcpy_s(MetaInfList[i], "нет данных");
		break;
		case ISOSpeed:
			if (TagArray[ISOSpeedRetings_t].Availability)
			{
				char str[20];

				strcpy_s(MetaInfList[i], "ISO-");

				if (Reverse)
					sprintf_s(str, "%d", ShortReverse((unsigned short)TagArray[ISOSpeedRetings_t].DataArr_2));
				else
					sprintf_s(str, "%d", (unsigned short)TagArray[ISOSpeedRetings_t].DataArr_2);

				strcat_s(MetaInfList[i], str);
			}
			else
				strcpy_s(MetaInfList[i], "нет данных");
		break;
		case ExposureBias:
			if (TagArray[ExposureBiasValue_t].Availability)
			{
				char str[20];

				if (Reverse)
				{
					sprintf_s(MetaInfList[i], "%d", LongReverse((unsigned int)TagArray[ExposureBiasValue_t].DataArr_1));
					sprintf_s(str, "%d", LongReverse((unsigned int)TagArray[ExposureBiasValue_t].DataArr_2));
				}
				else
				{
					sprintf_s(MetaInfList[i], "%d", TagArray[ExposureBiasValue_t].DataArr_1);
					sprintf_s(str, "%d", TagArray[ExposureBiasValue_t].DataArr_2);
				}

				strcat_s(MetaInfList[i], "/");
				strcat_s(MetaInfList[i], str);
				strcat_s(MetaInfList[i], " EV");
			}
			else
				strcpy_s(MetaInfList[i], "нет данных");
		break;
		case MeteringMode:
			if (TagArray[MeteringMode_t].Availability)
			{
				unsigned short Data = (unsigned short)TagArray[MeteringMode_t].DataArr_2;
				if (Reverse)
					Data = ShortReverse((unsigned short)TagArray[MeteringMode_t].DataArr_2);
				switch (Data)
				{
				case 1:
					strcpy_s(MetaInfList[i], "усредненный");
				    break;
				case 2:
					strcpy_s(MetaInfList[i], "средневзвешенный");
			    	break;
				case 3:
					strcpy_s(MetaInfList[i], "точечный");
				    break;
				case 4:
					strcpy_s(MetaInfList[i], "многоточечный");
			    	break;
				case 5:
					strcpy_s(MetaInfList[i], "по шаблону");
			     	break;
			 	case 6:
					strcpy_s(MetaInfList[i], "частичный");
				    break;
				default:
					strcpy_s(MetaInfList[i], "нет данных");
				    break;
				}
			}
			else
				strcpy_s(MetaInfList[i], "нет данных");
		break;
		case Flash:
			if (TagArray[Flash_t].Availability)
			{
				unsigned short Data = (unsigned short)TagArray[Flash_t].DataArr_2;
				if (Reverse)
					Data = ShortReverse((unsigned short)TagArray[Flash_t].DataArr_2);
				if (Data == 1)
					strcpy_s(MetaInfList[i], "со вспышкой");
				else
					strcpy_s(MetaInfList[i], "без вспышки");
			}
			else
				strcpy_s(MetaInfList[i], "нет данных");
		break;
		case Contrast:
			if (TagArray[Contrast_t].Availability)
			{
				unsigned short Data = (unsigned short)TagArray[Contrast_t].DataArr_2;
				if (Reverse)
					Data = ShortReverse((unsigned short)TagArray[Contrast_t].DataArr_2);
				switch (Data)
				{
				case 1:
					strcpy_s(MetaInfList[i], "размытый");
				    break;
				case 2:
					strcpy_s(MetaInfList[i], "жесткий");
				    break;
				default:
					strcpy_s(MetaInfList[i], "обычный");
				    break;
				}
			}
			else
				strcpy_s(MetaInfList[i], "нет данных");
		break;
		case LightSource:
			if (TagArray[LightSource_t].Availability)
			{
				unsigned short Data = (unsigned short)TagArray[LightSource_t].DataArr_2;
				if (Reverse)
					Data = ShortReverse((unsigned short)TagArray[LightSource_t].DataArr_2);
				switch (Data)
				{
				case 1:
					strcpy_s(MetaInfList[i], "дневное");
				    break;
				case 2:
					strcpy_s(MetaInfList[i], "флюоресцентное");
			        break;
				case 3:
					strcpy_s(MetaInfList[i], "вольфрам");
				    break;
				case 4:
					strcpy_s(MetaInfList[i], "стандартное");
				    break;
				case 5:
					strcpy_s(MetaInfList[i], "стандартное");
			     	break;
				   case 6:
					strcpy_s(MetaInfList[i], "стандартное");
				    break;
				default:
					strcpy_s(MetaInfList[i], "нет данных");
				    break;
				}
			}
			else
				strcpy_s(MetaInfList[i], "нет данных");
		break;
		case ExposureProgram:
			if (TagArray[ExposureProgram_t].Availability)
			{
				unsigned short Data = (unsigned short)TagArray[ExposureProgram_t].DataArr_2;
				if (Reverse)
					Data = ShortReverse((unsigned short)TagArray[ExposureProgram_t].DataArr_2);
				switch (Data)
				{
				case 1:
					strcpy_s(MetaInfList[i], "вручную");
				break;
				case 2:
					strcpy_s(MetaInfList[i], "обычный");
				break;
				case 3:
					strcpy_s(MetaInfList[i], "приоритет диафрагмы");
				break;
				case 4:
					strcpy_s(MetaInfList[i], "приоритет выдержки");
				break;
				case 5:
					strcpy_s(MetaInfList[i], "художественая съемка");
				break;
				case 6:
					strcpy_s(MetaInfList[i], "спортивная съемка");
				break;
				case 7:
					strcpy_s(MetaInfList[i], "портретный режим");
				break;
				case 8:
					strcpy_s(MetaInfList[i], "пейзажный режим");
				break;
				default:
					strcpy_s(MetaInfList[i], "нет данных");
				break;
				}
			}
			else
				strcpy_s(MetaInfList[i], "нет данных");
		break;
		case Saturation:
			if (TagArray[Saturation_t].Availability)
			{
				unsigned short Data = (unsigned short)TagArray[Saturation_t].DataArr_2;
				if (Reverse)
					Data = ShortReverse((unsigned short)TagArray[Saturation_t].DataArr_2);
				switch (Data)
				{
				case 1:
					strcpy_s(MetaInfList[i], "низкая");
				    break;
				case 2:
					strcpy_s(MetaInfList[i], "высокая");
				    break;
				default:
					strcpy_s(MetaInfList[i], "обычная");
				    break;
				}
			}
			else
				strcpy_s(MetaInfList[i], "нет данных");
		break;
		case Sharpness:
			if (TagArray[Sharpness_t].Availability)
			{
				unsigned short Data = (unsigned short)TagArray[Sharpness_t].DataArr_2;
				if (Reverse)
					Data = ShortReverse((unsigned short)TagArray[Sharpness_t].DataArr_2);
				switch (Data)
				{
				case 1:
					strcpy_s(MetaInfList[i], "пониженная");
				    break;
				case 2:
					strcpy_s(MetaInfList[i], "повышенная");
				    break;
				default:
					strcpy_s(MetaInfList[i], "обычная");
				    break;
				}
			}
			else
				strcpy_s(MetaInfList[i], "нет данных");
		break;
		case WhiteBalance:
			if (TagArray[WhiteBalance_t].Availability)
			{
				unsigned short Data = (unsigned short)TagArray[WhiteBalance_t].DataArr_2;
				if (Reverse)
					Data = ShortReverse((unsigned short)TagArray[WhiteBalance_t].DataArr_2);
				if (Data == 1)
					strcpy_s(MetaInfList[i], "вручную");
				else
					strcpy_s(MetaInfList[i], "авто");
			}
			else
				strcpy_s(MetaInfList[i], "нет данных");
		break;
		case ExifVersion:
			if (TagArray[ExifVersion_t].Availability)
				MetaDataEditor_Ascii.ReadData_Ascii(FileName, TagArray[ExifVersion_t], TIFFPosition, Reverse, MetaInfList[i]);
			else
				strcpy_s(MetaInfList[i], "нет данных");
		break;
		case DateTimeDigizated:
			if (TagArray[DateTimeDigitized_t].Availability)
				MetaDataEditor_Ascii.ReadData_Ascii(FileName, TagArray[DateTimeDigitized_t], TIFFPosition, Reverse, MetaInfList[i]);
			else
				strcpy_s(MetaInfList[i], "нет данных");
		break;
		case DateTimeEdited:
			if (TagArray[DateTime_t].Availability)
				MetaDataEditor_Ascii.ReadData_Ascii(FileName, TagArray[DateTime_t], TIFFPosition, Reverse, MetaInfList[i]);
			else
				strcpy_s(MetaInfList[i], "нет данных");
		break;
		}
}
void MetaInformation::ShowInformation(char *FileName)//Вывод информации
{
	system("cls");

	SetTextColor(Yellow);
	cout << "  Описание:" << endl;
	SetTextColor(White);

	for (int i = 0; i < 1; i++)
	{
		cout << TypeMetaInf[i];
		for (int j = 0; (unsigned)j < (unsigned)(40 - strlen(TypeMetaInf[i])); j++)
			cout << " ";
		cout << MetaInfList[i] << endl;
	}

	SetTextColor(Yellow);
	cout << "  Источник:" << endl;
	SetTextColor(White);

	for (int i = 1; i < 4; i++)
	{
		cout << TypeMetaInf[i];
		for (int j = 0; (unsigned)j < (unsigned)(40 - strlen(TypeMetaInf[i])); j++)
			cout << " ";
		cout << MetaInfList[i] << endl;
	}

	SetTextColor(Yellow);
	cout << "  Изображение:" << endl;
	SetTextColor(White);

	for (int i = 4; i < 10; i++)
	{
		cout << TypeMetaInf[i];
		for (int j = 0; (unsigned)j < (unsigned)(40 - strlen(TypeMetaInf[i])); j++)
			cout << " ";
		cout << MetaInfList[i] << endl;
	}

	SetTextColor(Yellow);
	cout << "  Камера:" << endl;
	SetTextColor(White);

	for (int i = 10; i < 18; i++)
	{
		cout << TypeMetaInf[i];
		for (int j = 0; (unsigned)j < (unsigned)(40 - strlen(TypeMetaInf[i])); j++)
			cout << " ";
		cout << MetaInfList[i] << endl;
	}

	SetTextColor(Yellow);
	cout << "  Улучшенное фото:" << endl;
	SetTextColor(White);

	for (int i = 18; i < 25; i++)
	{
		cout << TypeMetaInf[i];
		for (int j = 0; (unsigned)j < (unsigned)(40 - strlen(TypeMetaInf[i])); j++)
			cout << " ";
		cout << MetaInfList[i] << endl;
	}

	SetTextColor(Yellow);
	cout << "  Файл:" << endl;
	SetTextColor(White);

	for (int i = 25; i < 27; i++)
	{
		cout << TypeMetaInf[i];
		for (int j = 0; (unsigned)j < (unsigned)(40 - strlen(TypeMetaInf[i])); j++)
			cout << " ";
		cout << MetaInfList[i] << endl;
	}

	cout << "Путь к файлу";
	for (int j = 0; (unsigned)j < 28; j++)
		cout << " ";
	cout << FileName << endl;
}

MetaInformation::~MetaInformation()
{
}
