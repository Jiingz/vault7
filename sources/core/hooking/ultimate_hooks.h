#pragma once
#include <Windows.h>
#include <vector>
#include <VersionHelpers.h>
#include <Zydis/Zydis.h>

#pragma warning(4:4596)

#define VP_Offset 0x170

#define NT_SUCCESS(Status) (((NTSTATUS)(Status)) >= 0)

struct HookDetails {
	DWORD hookAddress;
	DWORD addressToHook;
};

struct HookEntries
{
	std::vector<HookDetails> hookDetails;
	DWORD addressToHookOldProtect;
	DWORD addressToHookMbiStart;
	DWORD addressToHookMbiEnd;
	DWORD addressToHookMbiSize;
	DWORD allocatedAddressStart;
	DWORD allocatedAddressEnd;
	DWORD allocatedAddressSize;
	DWORD addressToHookoffsetFromStart;
};

LONG WINAPI LeoHandler(EXCEPTION_POINTERS* pExceptionInfo);

class UltimateHooks {
public:
	template <class fnType>
	bool DEPAddHook(DWORD Address, DWORD hk_Address, fnType& OldAddress, size_t Size, PVOID& Allocation, uint8_t Offset) {
		DWORD NewOnprocessSpellAddr = VirtualAllocateRegion(Allocation, Address, Size);
		CopyRegion((DWORD)Allocation, Address, Size);
		FixFuncRellocation(Address, (Address + Size), (DWORD)Allocation, Size);
		OldAddress = (fnType)(NewOnprocessSpellAddr);
		return addHook(Address, (DWORD)hk_Address, Offset);
	}
	bool deinit();
	DWORD RestoreRtlAddVectoredExceptionHandler();
	DWORD RestoreZwQueryInformationProcess();
private:
	bool IsDoneInit = false;
	PVOID VEH_Handle = nullptr;

	DWORD VirtualAllocateRegion(PVOID& NewFunction, DWORD OrigAddress, size_t size);
	void CopyRegion(DWORD dest, DWORD source, size_t size);
	void FixFuncRellocation(DWORD OldFnAddress, DWORD OldFnAddressEnd, DWORD NewFnAddress, size_t size);
	bool addHook(DWORD address, DWORD hkAddress, size_t offset);
	bool Hook(DWORD original_fun, DWORD hooked_fun, size_t offset);
	void FixRellocation(DWORD OldFnAddress, DWORD OldFnAddressEnd, DWORD NewFnAddress, size_t size, size_t _offset);
};
extern UltimateHooks UltHook;