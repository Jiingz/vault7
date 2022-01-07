#pragma warning(disable : 4996)

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <process.h>
#include <core/game/manager/manager.h>
#include <core/locator.h>
#include <core/features/feature_controller.h>
#include <core/libs/Detours/detours.h>

HMODULE thread;

int main()
{
	//Hooks GetCursorPos WINAPI function to spoof the mouse position. Mostly used for CastSpell.
	//core::Locator::GetHookingService()->HookGetCursorPos();
	//Initialize functions
	core::Locator::GetFunctionAccessor()->GetAttackCastDelay.Initialize();
	core::Locator::GetFunctionAccessor()->GetAttackDelay.Initialize();
	core::Locator::GetFunctionAccessor()->GetbaseAttack.Initialize();
	core::Locator::GetFunctionAccessor()->GetBaseDrawPos.Initialize();
	core::Locator::GetFunctionAccessor()->NewCastSpell.Initialize();
	core::Locator::GetFunctionAccessor()->NewIssueOrder.Initialize();
	core::Locator::GetFunctionAccessor()->PrintChat.Initialize();
	core::Locator::GetFunctionAccessor()->WorldToScreen.Initialize();

	//Hook the present
	core::Locator::GetHookingService()->HookPresent();

	//Hook league callbacks using DEP
	core::Locator::GetHookingService()->StartDEPHooks();

	//Load all modules
	feature::FeatureController::LoadFeatures();
	//Print info that Invictus has been loaded
	core::Locator::GetGameComponents()->PrintChat("Invictus++ Loaded");
	return 0;
}


void OnExit() noexcept {

	//Save all configs on game close
	feature::FeatureController::GetOrbwalker()->SaveConfig();

	//Finish config writing
	core::Locator::config.FinishWriting();

	CloseHandle((HANDLE)thread);
}

bool APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		std::atexit(OnExit);
		thread = hModule;
		_beginthreadex(nullptr, 0, (_beginthreadex_proc_type)main, hModule, 0, nullptr);
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		OnExit();
		break;
	}
	return TRUE;
}