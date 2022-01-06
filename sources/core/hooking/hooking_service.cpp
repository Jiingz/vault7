#include <core/hooking/hooking_service.h>
#include <core/hooking/callbacks.h>
#include <core/locator.h>
#include <string>
#include <core/hooking/ultimate_hooks.h>
#include <core/libs/Detours/detours.h>

using namespace core;

HookingService::HookingService()
{
	this->kiero_status_ = kiero::init(kiero::RenderType::D3D11);

	//Activates DEP Policy since we need it for our DEP hooks
	if (GetSystemDEPPolicy())
		SetProcessDEPPolicy(PROCESS_DEP_ENABLE);

	UltHook.RestoreRtlAddVectoredExceptionHandler();
	UltHook.RestoreZwQueryInformationProcess();

}

kiero::Status::Enum HookingService::HookPresent()
{
	return kiero::bind(8, (void**)&present_, Callbacks::HookedPresent);
}

void HookingService::StartDEPHooks()
{
	UltHook.DEPAddHook(reinterpret_cast<DWORD>(GetModuleHandle(NULL)) + Offsets::onProcessSpell, reinterpret_cast<DWORD>(Callbacks::HookedOnProcessSpell), on_process_spell_, 0x59, new_on_process_spell, 1);
}

void core::HookingService::HookGetCursorPos()
{
	constexpr auto origin = &GetCursorPos;

	DetourRestoreAfterWith();
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)origin, Callbacks::HookedGetCursorPos);
	DetourTransactionCommit();
}

HookingService::Present HookingService::GetOriginalPresent()
{
	return this->present_;
}

HookingService::OnProcessSpell HookingService::GetOriginalOnProcessSpell()
{
	return this->on_process_spell_;
}
