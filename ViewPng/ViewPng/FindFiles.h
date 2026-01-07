#pragma once

#include <string>
#include <vector>

class FindFiles
{
public:
	void SetPath(const std::string& path);
	void AddPattern(const std::string& pattern) { patterns.push_back(pattern); }
	bool Find();
	std::vector<std::string> GetFiles() const { return files; }
	void ClearFiles() { files.clear(); }

private:
	std::vector<std::string> files;
	std::vector<std::string> patterns;
	std::string path = ".\\";
};

