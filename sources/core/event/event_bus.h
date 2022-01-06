#pragma once

#include <core/utilities.h>

#include <unordered_map>
#include <vector>

template<typename T, typename R, typename... args>
inline void* void_cast(R(T::* f)(args...))
{
	union
	{
		R(T::* pf)(args...);
		void* p;
	};
	pf = f;
	return p;
}


namespace event
{
	class EventBus
	{
	public:

		template <typename TEvent>
		inline constexpr void Subscribe(void* callback) {
			subscribers_[core::utilities::GetHashCode<TEvent>()].emplace_back(callback);
		}

		template <typename TEvent>
		inline constexpr void Publish(TEvent event) {
			auto found = subscribers_.find(core::utilities::GetHashCode<TEvent>());

			if (found == subscribers_.end()) {
				return;
			}

			for (auto sub : found->second)
			{
				static_cast<void(*)(TEvent)>(sub)(event);
			}
		}

	private:
		std::unordered_map<size_t, std::vector<void*>> subscribers_;
	};
}

