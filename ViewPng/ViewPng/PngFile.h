#pragma once

#include <string>

class PngFile
{
public:
	void SetFilePath(const char* filePath);
	bool ReadDimensions();
	int width() const { return pngWidth; }
	int height() const { return pngHeight; }

private:
	std::string filePath;
	int pngWidth;
	int pngHeight;

};

