#pragma once
#include <type_traits>
namespace game
{
	enum class CallingConvention {
		Thiscall,
		Stdcall,
		Cdecl,
		Fastcall
	};

	template <CallingConvention TCallingConvention, typename TReturnType, ULONG TOffset = 0, typename ...TArgs>
	struct Function
	{
	private:
		typedef TReturnType(__thiscall* FunctionThisCall)(TArgs...);
		typedef TReturnType(__fastcall* FunctionFastcall)(TArgs...);
		typedef TReturnType(__stdcall* FunctionStdcall)(TArgs...);
		typedef TReturnType(__cdecl* FunctionCdecl)(TArgs...);

	public:
		typedef typename std::conditional <
			TCallingConvention == CallingConvention::Thiscall,
			FunctionThisCall,
			typename std::conditional<
			TCallingConvention == CallingConvention::Cdecl,
			FunctionCdecl,
			typename std::conditional<
			TCallingConvention == CallingConvention::Stdcall,
			FunctionStdcall,
			FunctionFastcall>>::type
			>::type DefinedFunction;

		Function()
		{
			this->func_ = reinterpret_cast<DefinedFunction>(reinterpret_cast<DWORD>(GetModuleHandle(NULL)) + TOffset);
		}

		TReturnType operator()(TArgs... args) const {
			return this->func_(args...);
		}

	private:
		DefinedFunction func_;
	};


	template< typename Function >
	static Function CallVirtual(PVOID Base, ULONG Index)
	{
		PULONG* VTablePointer = (PULONG*)Base;
		PULONG VTableFunctionBase = *VTablePointer;
		ULONG dwAddress = VTableFunctionBase[Index];
		return (Function)(dwAddress);
	}
}