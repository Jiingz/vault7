#pragma once
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <vector>
#include <string>

#define BUF_SIZE 256

namespace core
{
	typedef struct DebugInfo
	{
	public:
		DWORD addr_;
		std::string message_;
	};

	class Debugger
	{
	public:
		Debugger();
		~Debugger();

		void WriteDebugMessage(DebugInfo* debug_info);
		bool IsElevated();
	private:
		HANDLE map_file_;
		DebugInfo* buffer_;
		bool not_elevated_;
	};
}