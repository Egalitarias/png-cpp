#pragma once

#include <string>
#include <vector>

class FindFiles
{
public:
	bool Find();
	std::vector<std::string> GetFiles() const { return files; }
	void ClearFiles() { files.clear(); }

private:
	std::vector<std::string> files;
};

