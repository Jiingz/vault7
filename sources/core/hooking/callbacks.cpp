#include "callbacks.h"
#include <core/locator.h>
#include <DirectXMath.h>


HRESULT __stdcall core::Callbacks::HookedPresent(IDXGISwapChain* swap_chain, UINT sync_interval, UINT flags)
{
	if (!DrawFactory::initialized_)
		core::Locator::GetDrawFactory()->InitializeRenderer(swap_chain);

		return Locator::GetHookingService()->GetOriginalPresent()(swap_chain, sync_interval, flags);
}
