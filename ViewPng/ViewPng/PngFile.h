#pragma once

#include <string>

struct PngIHDRChunk
{
	unsigned int width;
	unsigned int height;
	unsigned char bitDepth;
	unsigned char colorType;
	unsigned char compressionMethod;
	unsigned char filterMethod;
	unsigned char interlaceMethod;
};	

struct PngColor {
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
};

class PngFile
{
public:
	void SetFilePath(const char* filePath);
	bool ReadDimensions();
	PngIHDRChunk ReadIHDRChunk();
	int width() const { return pngWidth; }
	int height() const { return pngHeight; }
	PngColor GetColorAt(int x, int y);

	bool StartReadingColors();
	PngColor NextColor();
	void EndReadingColors();

private:
	FILE* in;
	std::string filePath;
	int pngWidth;
	int pngHeight;

};

