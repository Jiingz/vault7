// DebugConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <tchar.h>
#pragma comment(lib, "user32.lib")

#define BUF_SIZE 256
TCHAR szName[] = TEXT("Global\\MyFileMappingObject");

struct DebugInfo
{
public:
	DWORD addr_;
	std::string message_;
};

int main()
{
	HANDLE hMapFile;
	DebugInfo* dbg_info;

	while (true)
	{
		hMapFile = OpenFileMapping(
			FILE_MAP_ALL_ACCESS,   // read/write access
			FALSE,                 // do not inherit the name
			szName);               // name of mapping object

		dbg_info = (DebugInfo*)MapViewOfFile(hMapFile, // handle to map object
			FILE_MAP_ALL_ACCESS,  // read/write permission
			0,
			0,
			0);

		if (dbg_info)
		{
			_tprintf(TEXT("%s \n"), dbg_info->message_.c_str());
		}
	}

	return 0;
}
