#include <process.h>

#include <core/game/manager/manager.h>
#include <core/event/events.h>
#include <core/locator.h>


int main()
{
	for (auto h : core::Locator::GetWorld()->GetHeroList())
	{
		MessageBoxA(NULL,std::to_string(h.health.value).c_str(), "TEST", NULL);
	}

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