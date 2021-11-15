#include "callbacks.h"

HRESULT __stdcall core::Callbacks::HookedPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{

	return Locator::GetHookingService()->GetOriginalPresent()(pSwapChain, SyncInterval, Flags);
}
