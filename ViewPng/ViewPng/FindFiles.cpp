#include "FindFiles.h"

#include <windows.h>

#include <algorithm>

void FindFiles::SetPath(const std::string& thePath) {
	path = thePath;
}

bool FindFiles::Find()
{
	files.clear();

	/* Could be used to get current directory if needed
	char cwd[MAX_PATH];
	DWORD len = GetCurrentDirectoryA(MAX_PATH, cwd);
	if (len == 0 || len > MAX_PATH)
		return false;

	std::string dir(cwd);
	*/

	for (auto pattern : patterns)
	{
		std::string search = path + pattern;
		WIN32_FIND_DATAA fd;
		HANDLE hFind = FindFirstFileA(search.c_str(), &fd);
		if (hFind == INVALID_HANDLE_VALUE)
			continue;

		do
		{
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				files.push_back(fd.cFileName);
			}
		} while (FindNextFileA(hFind, &fd));

		FindClose(hFind);
	}

	// Remove duplicates (case-insensitive filesystems may return duplicates)
	std::sort(files.begin(), files.end());
	files.erase(std::unique(files.begin(), files.end()), files.end());

	return !files.empty();
}