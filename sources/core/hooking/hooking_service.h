#pragma once
#include <minhook/include/MinHook.h>
namespace core
{
	class HookingService
	{
	public:

		HookingService()
		{
			this->init_status_ = MH_Initialize();
		}

		template <typename T>
		MH_STATUS CreateHook(LPVOID pTarget, LPVOID pDetour, T** ppOriginal)
		{
			return MH_CreateHook(pTarget, pDetour, reinterpret_cast<LPVOID*>(ppOriginal));
		}

		template <typename T>
		MH_STATUS CreateAPIHook(
			LPCWSTR pszModule, LPCSTR pszProcName, LPVOID pDetour, T** ppOriginal)
		{
			return MH_CreateHookApi(
				pszModule, pszProcName, pDetour, reinterpret_cast<LPVOID*>(ppOriginal));
		}

	private:
		MH_STATUS init_status_;
	};


}