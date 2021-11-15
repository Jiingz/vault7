#pragma once
#include <d3d11.h>
#include <core/locator.h>

namespace core
{
	class Callbacks
	{
	public:
		static HRESULT __stdcall HookedPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
	};
}