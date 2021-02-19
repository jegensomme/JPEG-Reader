#include "stdafx.h"
#include "MetaData.h"
#include "TagNumbers.h"
#include "ReverseByte.h"
#include <fstream>
#include <iostream>

using namespace std;

MetaData::MetaData()
{
}

void MetaData::ReadHead(bool *Reverse, char *FileName, int *TIFFPosition)//—читывание заголовков
{
	ifstream File(FileName, ios::binary);

	File.read((char*)&SOIMarker, 2);

	while ((unsigned short)APP1Marker != 0xffe1 && (unsigned short)APP1Marker != 0xe1ff)
	{
		File.read((char*)&APP1Marker, 2);
	}

	File.read((char*)&APP1DataSize, 2);

	File.read(ExifHead, 4);

	File.seekg(2, ios::cur);
	*TIFFPosition = (int)File.tellg();
	File.read(TIFFHead, 2);

	if (TIFFHead[0] == 'M' && TIFFHead[1] == 'M')//ќпредел€ем какой пор€док байт
		*Reverse = true;


	File.read((char*)&TIFFData, 4);
	Integer = (int)File.tellg() + 2;

	File.close();
}

void MetaData::ReadData(bool Reverse, Tags *TagArray, char *FileName, int TIFFPosition)//—читывание данных
{
	ifstream File;
	short NumberOfTags = 0;
	bool TagInfo_read = false;

	while (!TagInfo_read)
	{
		if (TagArray[ExifOffset_t].Availability)
		{
			//cout << "fefesefsfs" << endl;
			TagDataEditor.OffsetToDataArea(&Integer, Reverse, TIFFPosition, (unsigned int)TagArray[ExifOffset_t].DataArr_2);
			NumberOfTags = 0;
			TagInfo_read = true;
		}
		File.open(FileName, ios::binary);
		File.seekg(Integer, ios::beg);

		File.read((char*)&NumberOfTags, 2);
		if (Reverse)
			NumberOfTags = ShortReverse((unsigned short)NumberOfTags);
		//cout << NumberOfTags << endl;
		Integer = (int)File.tellg();
		File.close();

		for (int i = 0; i < (unsigned short)NumberOfTags; i++)
		{

			File.open(FileName, ios::binary);
			File.seekg(Integer, ios::beg);
			File.read((char*)&TagNumber, 2);
			Integer = (int)File.tellg();
			File.close();
			if (Reverse)
				TagNumber = (TagNumbers)ShortReverse((unsigned short)TagNumber);
			//cout << Integer << endl;

			switch ((unsigned short)TagNumber)
			{
			case ImageWidth_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[ImageWidth_t]);
		       	break;
			case ImageLength_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[ImageLength_t]);
		     	break;
			case BitsPerSample_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[BitsPerSample_t]);
			    break;
			case ImageDescription_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[ImageDescription_t]);
			    break;
			case Make_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[Make_t]);
			    break;
			case Model_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[Model_t]);
		    	break;
			case Orientation_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[Orientation_t]);
			    break;
			case XResolution_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[XResolution_t]);
			    break;
			case YResolution_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[YResolution_t]);
			    break;
			case ResolutionUnit_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[ResolutionUnit_t]);
			    break;
			case Software_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[Software_t]);
			    break;
			case DateTime_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[DateTime_t]);
			    break;
			case Artist_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[Artist_t]);
		     	break;
			case YCbCrCoefficients_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[YCbCrCoefficients_t]);
			    break;
			case ExifOffset_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[ExifOffset_t]);
			    break;
			case Indefined11_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[Indefined11_t]);
			    break;
			case Indefined0_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[Indefined0_t]);
			    break;
			case ExposureTime_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[ExposureTime_t]);
			    break;
			case FNumber_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[FNumber_t]);
				break;;
			case ExposureProgram_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[ExposureProgram_t]);
				break;;
			case ISOSpeedRetings_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[ISOSpeedRetings_t]);
				break;;
			case ExifVersion_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[ExifVersion_t]);
				break;;
			case DateTimeOriginal_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[DateTimeOriginal_t]);
				break;;
			case DateTimeDigitized_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[DateTimeDigitized_t]);
				break;;
			case ComponentConfiguration_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[ComponentConfiguration_t]);
				break;;
			case ShutterSpeedValue_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[ShutterSpeedValue_t]);
				break;;
			case ApertureValue_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[ApertureValue_t]);
				break;;
			case BrightnessValue_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[BrightnessValue_t]);
				break;;
			case ExposureBiasValue_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[ExposureBiasValue_t]);
				break;;
			case MaxApertureValue_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[MaxApertureValue_t]);
				break;;
			case MeteringMode_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[MeteringMode_t]);
				break;;
			case LightSource_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[LightSource_t]);
				break;;
			case Flash_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[Flash_t]);
				break;;
			case FocalLength_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[FocalLength_t]);
				break;;
			case MakerNote_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[MakerNote_t]);
				break;;
			case SubSecTime_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[SubSecTime_t]);
				break;;
			case SubSecTimeOriginal_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[SubSecTimeOriginal_t]);
				break;;
			case SubSecTimeDigitized_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[SubSecTimeDigitized_t]);
				break;;
			case FlashPixVersion_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[FlashPixVersion_t]);
				break;;
			case ColorSpace_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[ColorSpace_t]);
				break;;
			case ExifImageWidth_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[ExifImageWidth_t]);
			break;
			case ExifImageHeight_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[ExifImageHeight_t]);
				break;;
			case ExifInteroperabilityOffset_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[ExifInteroperabilityOffset_t]);
				break;;
			case FocalPlaneXResolution_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[FocalPlaneXResolution_t]);
				break;;
			case FocalPlaneYResolution_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[FocalPlaneYResolution_t]);
				break;;
			case FocalPlaneResolutionUnit_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[FocalPlaneResolutionUnit_t]);
				break;;
			case SensingMethod_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[SensingMethod_t]);
				break;;
			case FileSource_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[FileSource_t]);
				break;;
			case SceneType_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[SceneType_t]);
				break;;
			case Indefined1_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[Indefined1_t]);
				break;;
			case Indefined2_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[Indefined2_t]);
				break;;
			case WhiteBalance_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[WhiteBalance_t]);
				break;;
			case DigitalZoomRatio_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[DigitalZoomRatio_t]);
				break;;
			case Indefined5_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[Indefined5_t]);
				break;;
			case Indefined6_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[Indefined6_t]);
				break;;
			case Indefined7_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[Indefined7_t]);
				break;;
			case Contrast_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[Contrast_t]);
				break;;
			case Saturation_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[Saturation_t]);
				break;;
			case Sharpness_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[Sharpness_t]);
				break;;
			case Indefined12_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[Indefined12_t]);
				break;;
			case Indefined48_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[Indefined48_t]);
				break;;
			case Indefined49_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[Indefined49_t]);
				break;;
			case Indefined50_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[Indefined50_t]);
				break;;
			case Indefined52_n:
				TagDataEditor.ReadData(&Integer, FileName, &TagArray[Indefined52_t]);
				break;;
			}
		}
	}
}

MetaData::~MetaData()
{
}