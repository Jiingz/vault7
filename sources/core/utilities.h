#pragma once

#include <typeinfo>
#include <WTypesbase.h>


namespace core::utilities
{
	template <typename T>
	constexpr static size_t GetHashCode() {
		return typeid(T).hash_code();
	}

	template< typename Function >
	static Function CallVirtual(PVOID Base, ULONG Index)
	{
		PULONG* VTablePointer = (PULONG*)Base;
		PULONG VTableFunctionBase = *VTablePointer;
		ULONG dwAddress = VTableFunctionBase[Index];
		return (Function)(dwAddress);
	}
}
