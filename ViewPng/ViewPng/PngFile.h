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

class PngFile
{
public:
	void SetFilePath(const char* filePath);
	bool ReadDimensions();
	PngIHDRChunk ReadIHDRChunk();
	int width() const { return pngWidth; }
	int height() const { return pngHeight; }

private:
	std::string filePath;
	int pngWidth;
	int pngHeight;

};

