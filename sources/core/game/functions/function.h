#pragma once

namespace game
{
	template<typename TReturnType, typename TTypedef, typename... Args>
	struct Function
	{
	public:
		Function()
		{
			this->func_ = nullptr;
		}

		Function(ULONG offset)
		{
			this->func_ = reinterpret_cast<TTypedef>(reinterpret_cast<DWORD>(GetModuleHandle(NULL)) + offset);
		}

		TReturnType Call(Args... args)
		{
			return this->func_(args...);
		}

		TReturnType operator()(Args... args) const {
			return this->func_(args...);
		}

	private:
		TTypedef func_;
	};
}