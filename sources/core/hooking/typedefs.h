#pragma once
#include <Windows.h>

namespace core
{
	template<typename TTypedef>
	class Typedef
	{
	public:
		Typedef()
		{
			this->definition_ = TTypedef;
		}

		TTypedef get()
		{
			return this->definition_;
		}

	private:
		TTypedef definition_;
	};
}