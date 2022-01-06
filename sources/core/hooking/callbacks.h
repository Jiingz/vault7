#pragma once
#include <d3d11.h>
#include <core/locator.h>
#include <core/hooking/structs.h>

namespace core
{
	class Callbacks
	{
	public:
		static HRESULT __stdcall HookedPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
		static int __fastcall HookedOnProcessSpell(void* spellBook, void* edx, ActiveSpell* activeSpell);
		static BOOL WINAPI HookedGetCursorPos(LPPOINT lpPoint);
	};
}