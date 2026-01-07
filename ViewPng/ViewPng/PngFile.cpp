#include "PngFile.h"

void PngFile::SetFilePath(const char* theFilePath)
{
	filePath = theFilePath;
}

bool PngFile::ReadDimensions()
{
	FILE* in;
	fopen_s(&in, filePath.c_str(), "rb");
	if (!in) {
		return false;
	}


	fseek(in, 16, SEEK_SET);
	fread(&pngWidth, sizeof(int), 1, in);
	fread(&pngHeight, sizeof(int), 1, in);

	fclose(in);
	
	return true;
}