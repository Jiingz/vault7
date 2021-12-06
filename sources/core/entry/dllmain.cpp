#pragma warning(disable : 4996)

#include <process.h>

#include <core/game/manager/manager.h>
#include <core/event/events.h>
#include <core/locator.h>
#include <core/game/functions/function_accessor.h>

int main()
{
	core::Locator::GetHookingService()->HookPresent();
	core::Locator::GetWorld()->GetHeroes();

	core::Locator::GetFunctionAccessor()->PrintChat(*core::Locator::GetGameComponents()->GetChatInstance(), "TEST", 0xFFFFFF);

	LPVOID addr = LPVOID((DWORD)GetModuleHandle(NULL) + 0x509BD0);
	DWORD old;
	VirtualProtect(addr, 0x59, PAGE_READWRITE, &old);
	MessageBoxA(NULL, std::to_string(GetLastError()).c_str(), "TEST", NULL);
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