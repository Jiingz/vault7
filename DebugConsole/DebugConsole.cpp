// DebugConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <windows.h>
#include <tchar.h>
#include <string>

#pragma comment(lib, "user32.lib")
#pragma warning(disable : 4996)

#define BUF_SIZE 256
TCHAR szName[] = TEXT("Global\\MyFileMappingObject");

int main()
{
	HANDLE hMapFile;

	LPCTSTR debug_message;
	LPCTSTR last_message;

	while (true)
	{
		hMapFile = OpenFileMapping(
			FILE_MAP_ALL_ACCESS,   // read/write access
			FALSE,                 // do not inherit the name
			szName);               // name of mapping object

		debug_message = (LPTSTR)MapViewOfFile(hMapFile, // handle to map object
			FILE_MAP_ALL_ACCESS,  // read/write permission
			0,
			0,
			0);

		if (debug_message)
		{
			_tprintf(TEXT("%s \n"), debug_message);
			ZeroMemory((PVOID)debug_message, sizeof(debug_message));
		}
	}

	return 0;
}
