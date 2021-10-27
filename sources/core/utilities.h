#pragma once

#include <typeinfo>


namespace core::utilities
{
    template <typename T>
    constexpr static size_t GetHashCode() {
        return typeid(T).hash_code();
    }
}
