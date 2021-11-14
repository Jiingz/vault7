#pragma once
#include <core/memory/accessor.h>

namespace game
{
	template<typename TReturnType, typename TTypedef, typename... Args>
	struct Function
	{
	public:
		Function(DWORD_PTR offset)
		{
			this->func_ = static_Cast<TTypedef>(memory::Accessor::AccessModuleAddress(offset));
		}

		TReturnType Call(Args... args)
		{
			return this->func_(args...);
		}

	private:
		TTypedef func_;
	};
}