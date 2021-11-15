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
		Present oPresent;

	public:
		template <typename T>
		MH_STATUS CreateHook(LPVOID pTarget, LPVOID pDetour, T** ppOriginal)
		{
			return MH_CreateHook(pTarget, pDetour, reinterpret_cast<LPVOID*>(ppOriginal));
		}

		template <typename T>
		MH_STATUS CreateAPIHook(LPCWSTR pszModule, LPCSTR pszProcName, LPVOID pDetour, T** ppOriginal)
		{
			return MH_CreateHookApi(pszModule, pszProcName, pDetour, reinterpret_cast<LPVOID*>(ppOriginal));
		}

		//Initializes MH
		HookingService();

		//Hooks the present
		kiero::Status::Enum HookPresent();

		//returns the original present
		Present GetOriginalPresent();

	private:
		MH_STATUS minhook_status_;
		kiero::Status::Enum kiero_status_;
	};


}