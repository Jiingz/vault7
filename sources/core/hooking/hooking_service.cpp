#include <core/hooking/hooking_service.h>
#include <core/hooking/callbacks.h>
#include <core/locator.h>

using namespace core;

HookingService::HookingService()
{
	this->kiero_status_ = kiero::init(kiero::RenderType::D3D11);
}

kiero::Status::Enum core::HookingService::HookPresent()
{
	return kiero::bind(8, (void**)&oPresent, Callbacks::HookedPresent);
}

HookingService::Present HookingService::GetOriginalPresent()
{
	return this->oPresent;
}