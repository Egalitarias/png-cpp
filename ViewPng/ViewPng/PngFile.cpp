#include <winsock.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "Log.h"

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
	imageData = stbi_load(filePath.c_str(), &pngWidth, &pngHeight, &pngChannels, 0);
	imgaeDataIndex = 0;

	return imageData != nullptr;
}

PngColor PngFile::NextColor() {
	PngColor pngColor;

	pngColor.r = imageData[imgaeDataIndex++];
	pngColor.g = imageData[imgaeDataIndex++];
	pngColor.b = imageData[imgaeDataIndex++];
	if (pngChannels >= 4) {
		pngColor.a = imageData[imgaeDataIndex++];
	} else {
		pngColor.a = 255;
	}

	return pngColor;
}

void PngFile::EndReadingColors() {
	stbi_image_free(imageData);
	imageData = nullptr;
	imgaeDataIndex = 0;
}

void PngFile::DrawImage(HDC hdc, const char* filePath) {
	if (filePath == nullptr || strlen(filePath) == 0) {
		return;
	}
	int width = 0;
	int height = 0;
	int channels = 0;
	unsigned char* imageData = stbi_load(filePath, &width, &height, &channels, STBI_rgb_alpha);
	if (imageData == nullptr) {
		Log::LogMessage("Failed to load image data from file: [%s]\n", filePath);
		return;
	}
	BITMAPINFO bmi;
	ZeroMemory(&bmi, sizeof(BITMAPINFO));
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth = width;
	bmi.bmiHeader.biHeight = -height; // Negative height to indicate top-down bitmap
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32; // 4 bytes per pixel (RGBA)
	bmi.bmiHeader.biCompression = BI_RGB;
	SetDIBitsToDevice(
		hdc,
		0, 0,
		width, height,
		0, 0,
		0, height,
		imageData,
		&bmi,
		DIB_RGB_COLORS
	);
	stbi_image_free(imageData);
}
