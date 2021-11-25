#include <process.h>

#include <core/game/manager/manager.h>
#include <core/event/events.h>
#include <core/locator.h>
#include <core/game/functions/function_accessor.h>

int main()
{
	core::Locator::GetHookingService()->HookPresent();
	core::Locator::GetWorld()->GetHeroes();

	core::DebugInfo dbg_info_;
	dbg_info_.addr_ = 12345;
	dbg_info_.message_ = "Debugger works! I am a shared structure";
	core::Locator::GetDebugger()->WriteDebugMessage(&dbg_info_);
	return 0;
}

bool APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		_beginthreadex(nullptr, 0, (_beginthreadex_proc_type)main, hModule, 0, nullptr);
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}