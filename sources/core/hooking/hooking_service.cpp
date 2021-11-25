#include <core/hooking/hooking_service.h>
#include <core/hooking/callbacks.h>
#include <core/locator.h>

using namespace core;

HookingService::HookingService()
{
//	core::Locator::GetDebugger()->WriteDebugMessage(TEXT("HookingService: Started."));
	this->kiero_status_ = kiero::init(kiero::RenderType::D3D11);
}

kiero::Status::Enum core::HookingService::HookPresent()
{
	//core::Locator::GetDebugger()->WriteDebugMessage(TEXT("HookingService: Present Hooked."));
	return kiero::bind(8, (void**)&oPresent, Callbacks::HookedPresent);
}

HookingService::Present HookingService::GetOriginalPresent()
{
	return this->oPresent;
}