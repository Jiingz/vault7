#include <core/memory/debugger.h>
#include <core/locator.h>
#include <mutex>

using namespace core;

std::mutex unique_call_;
Debugger::Debugger()
{
	//We need Admin priviliges in order to proceed
	if (!IsElevated())
	{
		this->not_elevated_ = true;
		DWORD* chatInstance = (DWORD*)((DWORD)GetModuleHandle(NULL) + Offsets::ChatInstance); //Move this into "Engine" or smth
		core::Locator::GetFunctionAccessor()->PrintChat(*chatInstance, "The debugger could not be launched. In order to start the debugger, start the game as Admin!", 0xFFFFFF);
		return;
	}

	//allocate memory and create mapping object
	this->map_file_ = CreateFileMapping(
		INVALID_HANDLE_VALUE,    // use paging file
		NULL,                    // default security
		PAGE_READWRITE,          // read/write access
		0,                       // maximum object size (high-order DWORD)
		sizeof(core::DebugInfo),                // maximum object size (low-order DWORD)
		TEXT("Global\\MyFileMappingObject")); // name of mapping object

	//save pointer to our buffer / mapping object
	this->buffer_ = (core::DebugInfo*)MapViewOfFile(this->map_file_,   // handle to map object
		FILE_MAP_ALL_ACCESS, // read/write permission
		0,
		0,
		0);
}

core::Debugger::~Debugger()
{
	UnmapViewOfFile(this->buffer_);
	CloseHandle(this->map_file_);
}

void Debugger::WriteDebugMessage(DebugInfo* debug_info)
{
	unique_call_.lock();
	if (this->not_elevated_)
		return;


	CopyMemory((PVOID)this->buffer_, debug_info, sizeof(debug_info));
	unique_call_.unlock();
}

bool Debugger::IsElevated()
{
	BOOL fRet = FALSE;
	HANDLE hToken = NULL;
	if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken)) {
		TOKEN_ELEVATION Elevation;
		DWORD cbSize = sizeof(TOKEN_ELEVATION);
		if (GetTokenInformation(hToken, TokenElevation, &Elevation, sizeof(Elevation), &cbSize)) {
			fRet = Elevation.TokenIsElevated;
		}
	}
	if (hToken) {
		CloseHandle(hToken);
	}
	return fRet;

}
