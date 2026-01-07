#include <winsock.h>

#include "PngFile.h"

void PngFile::SetFilePath(const char* theFilePath)
{
	filePath = theFilePath;
}

PngIHDRChunk PngFile::ReadIHDRChunk() {
	PngIHDRChunk chunk;
	chunk.width = 0;
	chunk.height = 0;
	char chunkType[5] = { 0 };

	FILE* in;
	fopen_s(&in, filePath.c_str(), "rb");
	if (!in) {
		return chunk;
	}
	fseek(in, 12, SEEK_SET);
	fread(chunkType, 1, 4, in);
	chunkType[4] = '\0';
	if (strcmp(chunkType, "IHDR") != 0) {
		fclose(in);
		return chunk;
	}
	fseek(in, 16, SEEK_SET);
	fread(&chunk.width, sizeof(unsigned int), 1, in);
	fread(&chunk.height, sizeof(unsigned int), 1, in);
	fread(&chunk.bitDepth, 1, 1, in);
	fread(&chunk.colorType, 1, 1, in);
	fread(&chunk.compressionMethod, 1, 1, in);
	fread(&chunk.filterMethod, 1, 1, in);
	fread(&chunk.interlaceMethod, 1, 1, in);
	fclose(in);
	chunk.width = ntohl(chunk.width);
	chunk.height = ntohl(chunk.height);
	return chunk;
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
PngColor PngFile::GetColorAt(int x, int y)
{
	PngColor color = { 0, 0, 0, 255 };
	// Placeholder implementation
	return color;
}

bool PngFile::StartReadingColors() {
	fopen_s(&in, filePath.c_str(), "rb");
	if (in) {
		fseek(in, 16, SEEK_SET);
	}

	return in != nullptr;
}

PngColor PngFile::NextColor() {
	PngColor pngColor;

	if (in) {
		fread(&pngColor.r, sizeof(unsigned char), 1, in);
		fread(&pngColor.g, sizeof(unsigned char), 1, in);
		fread(&pngColor.b, sizeof(unsigned char), 1, in);
		fread(&pngColor.a, sizeof(unsigned char), 1, in);
	}

	return pngColor;
}

void PngFile::EndReadingColors() {
	fclose(in);
}
