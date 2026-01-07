#include <winsock.h>

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
	size_t j = sizeof(int);
	fread(&pngWidth, sizeof(int), 1, in);
	fread(&pngHeight, sizeof(int), 1, in);

	pngWidth = ntohl(pngWidth);
	pngHeight = ntohl(pngHeight);

	fclose(in);
	
	return true;
}