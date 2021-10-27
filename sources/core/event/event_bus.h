#pragma once

#include <core/utilities.h>

#include <unordered_map>
#include <vector>


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

