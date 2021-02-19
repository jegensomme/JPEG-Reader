#pragma once

struct Tags
{
	bool Availability = false;//Считатан ли тег
	short DataFormat = 0;//Формат данных
	int DataArr_1 = 0;//Кол-во компонентов
	int DataArr_2 = 0;//Информация о теге или смещение к ней
	int TagPosition;
};

enum TagPointers
{
	ImageWidth_t = 0,
	ImageLength_t,
	BitsPerSample_t,
	ImageDescription_t,
	Make_t,
	Model_t,
	Orientation_t,
	XResolution_t,
	YResolution_t,
	ResolutionUnit_t,
	Software_t,
	DateTime_t,
	Artist_t,
	YCbCrCoefficients_t,
	ExifOffset_t,
	Indefined0_t,
	ExposureTime_t,
	FNumber_t,
	ExposureProgram_t,
	ISOSpeedRetings_t,
	ExifVersion_t,
	DateTimeOriginal_t,
	DateTimeDigitized_t,
	ComponentConfiguration_t,
	ShutterSpeedValue_t,
	ApertureValue_t,
	BrightnessValue_t,
	ExposureBiasValue_t,
	MaxApertureValue_t,
	MeteringMode_t,
	LightSource_t,
	Flash_t,
	FocalLength_t,
	MakerNote_t,
	SubSecTime_t,
	SubSecTimeOriginal_t,
	SubSecTimeDigitized_t,
	FlashPixVersion_t,
	ColorSpace_t,
	ExifImageWidth_t,
	ExifImageHeight_t,
	ExifInteroperabilityOffset_t,
	FocalPlaneXResolution_t,
	FocalPlaneYResolution_t,
	FocalPlaneResolutionUnit_t,
	SensingMethod_t,
	FileSource_t,
	SceneType_t,
	Indefined1_t,
	Indefined2_t,
	WhiteBalance_t,
	DigitalZoomRatio_t,
	Indefined5_t,
	Indefined6_t,
	Indefined7_t,
	Contrast_t,
	Saturation_t,
	Sharpness_t,
	Indefined11_t,
	Indefined12_t,
	Indefined48_t,
	Indefined49_t,
	Indefined50_t,
	Indefined52_t
};