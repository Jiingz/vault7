#include "callbacks.h"
#include <core/locator.h>
#include <DirectXMath.h>
#include <core/event/events.h>


HRESULT __stdcall core::Callbacks::HookedPresent(IDXGISwapChain* swap_chain, UINT sync_interval, UINT flags)
{
	if (!DrawFactory::initialized_)
		core::Locator::GetDrawFactory()->InitializeRenderer(swap_chain);

	core::Locator::GetEventBus()->Publish<event::OnTick>({});

	return Locator::GetHookingService()->GetOriginalPresent()(swap_chain, sync_interval, flags);
}