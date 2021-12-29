#pragma warning(disable : 4996)

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <process.h>
#include <core/game/manager/manager.h>
#include <core/locator.h>
#include <core/features/feature_controller.h>
#include <core/mouse.h>
#include <core/libs/Detours/detours.h>

static auto origin = &GetCursorPos;

BOOL WINAPI hGetCursorPos(LPPOINT lpPoint)
{
	auto org = origin(lpPoint);

	if (Mouse.enabled)
	{
		//	Mouse.mutex.lock();
		//	lpPoint->x = Mouse.x;
		//	lpPoint->y = Mouse.y;
		//	Mouse.mutex.unlock();
	}
	return org;
}

int main()
{
	//Hook GetCursorPos using MS Detours Lib
	DetourRestoreAfterWith();
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)origin, hGetCursorPos);
	DetourTransactionCommit();


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