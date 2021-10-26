#pragma once

#include <windows.h>


namespace memory {

class Accessor {
public:
    template <typename TTarget, DWORD_PTR TOffset = 0>
    static TTarget AccessModuleAddress(const DWORD_PTR additional_offset = 0) {
        return reinterpret_cast<TTarget>(*reinterpret_cast<DWORD_PTR*>(reinterpret_cast<DWORD_PTR>(GetModuleHandle(NULL)) + TOffset + additional_offset));
    }


protected:
    template <typename TTarget, DWORD_PTR TOffset = 0, typename TThis = DWORD_PTR>
    TTarget AccessAddress(const DWORD_PTR additional_offset = 0) {
        return reinterpret_cast<TTarget>(reinterpret_cast<TThis>(this) + TOffset + additional_offset);
    }

    template <DWORD_PTR TOffset, typename TThis = DWORD_PTR>
    char* AccessStr() {
        return "";
       // return utilities::GetStr(reinterpret_cast<TThis>(this + TOffset));
    }

    typedef memory::Accessor Super;
};

}

