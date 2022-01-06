#pragma once
#include <d3d11.h>
#include <core/hooking/kiero.h>
#include <minhook/include/MinHook.h>

namespace core
{
	class HookingService
	{
	private:
		typedef HRESULT(__stdcall* Present)(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
		Present present_;

		typedef int(__thiscall* OnProcessSpell)(void* spellBook, void* spellData);
		OnProcessSpell on_process_spell_;

		/*typedef int(__thiscall* fnCreateObject)(GameObject* obj, unsigned int NetworkID);
		typedef int(__thiscall* fnDeleteObject)(void* thisPtr, GameObject* pObject);
		typedef int(__cdecl* fnOnNewPath)(GameObject* obj, Vector3* start, Vector3* end, Vector3* tail, int unk1, float* dashSpeed, unsigned dash, int unk3, char unk4, int unk5, int unk6, int unk7);*/

	public:

		//Initializes MH
		HookingService();

		//Hooks the present
		kiero::Status::Enum HookPresent();

		//hooks leagues callbacks using DEP
		void StartDEPHooks();

		//Hook GetCursorPos using MS Detours Lib
		void HookGetCursorPos();

		//returns the original present
		Present GetOriginalPresent();
		//returns the original OnProcessSpell
		OnProcessSpell GetOriginalOnProcessSpell();

	private:
		MH_STATUS minhook_status_;
		kiero::Status::Enum kiero_status_;
		PVOID new_on_process_spell;
	};


}