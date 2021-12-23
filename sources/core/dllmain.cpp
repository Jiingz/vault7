#pragma warning(disable : 4996)

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <process.h>
#include <core/game/manager/manager.h>
#include <core/locator.h>
#include <core/features/feature_controller.h>

int main()
{
	//Hook the present
	core::Locator::GetHookingService()->HookPresent();
	//Load all modules
	feature::FeatureController::LoadFeatures();
	//Print info that Invictus has been loaded
	core::Locator::GetGameComponents()->PrintChat("Invictus++ Loaded");
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