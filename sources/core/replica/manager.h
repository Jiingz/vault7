#pragma once

#include <core/memory/accessor.h>
#include <core/memory/member.h>

#include <core/replica/game_object.h>

#include <windows.h>

#include <iterator>
#include <array>


namespace replica {


struct ManagerTemplate
{
    memory::AlignedMember<UINT32, 4, 0>     object_array;
    memory::AlignedMember<UINT32, 0, 48>    size; 
};


template <typename TType>
class ManagerTemplateIterator {
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type        = GameObject*;
    using difference_type   = ptrdiff_t;
    using pointer           = GameObject*;
    using reference         = GameObject&;

    explicit ManagerTemplateIterator(ManagerTemplate* ptr, SIZE_T offset)
        : ptr_(ptr) { }

    reference operator*() const noexcept  {
        return *operator->();
    }

    pointer operator->() const noexcept {
        _STL_VERIFY(index_ < ptr_->size.value, "cannot dereference out of range array iterator");

        auto object_array_ptr = reinterpret_cast<GameObject*>(*reinterpret_cast<DWORD_PTR*>(ptr_->object_array.value));
        return &object_array_ptr[index_];
    }

    ManagerTemplateIterator& operator++() noexcept {
        //_STL_VERIFY(_Ptr, "cannot increment value-initialized array iterator");
        //_STL_VERIFY(_Idx < _Size, "cannot increment iterator past end");
        ++index_;
        return *this;
    }

    ManagerTemplateIterator operator++(int) noexcept {
        ManagerTemplateIterator tmp = *this;
        ++*this;
        return tmp;
    }

    ManagerTemplateIterator& operator+=(const ptrdiff_t offset) noexcept {
        // _Verify_offset(_Off);
        index_ += static_cast<size_t>(offset);
        return *this;
    }

    ManagerTemplateIterator operator+(const ptrdiff_t offset) const noexcept {
        ManagerTemplateIterator tmp = *this;
        return tmp += offset;
    }

    bool operator==(const ManagerTemplateIterator& right) const noexcept {
        return index_ == right.index_;
    }

    bool operator!=(const ManagerTemplateIterator& right) const noexcept {
        return !(*this == right);
    }

    bool operator<(const ManagerTemplateIterator& right) const noexcept {
        //_Compat(_Right);
        return index_ < right.index_;
    }

    bool operator>(const ManagerTemplateIterator& right) const noexcept {
        return right < *this;
    }

    bool operator<=(const ManagerTemplateIterator& right) const noexcept {
        return !(right < *this);
    }

    bool operator>=(const ManagerTemplateIterator& right) const noexcept {
        return !(*this < right);
    }

private:
    ManagerTemplate* ptr_;
    SIZE_T index_;
};


class ManagerTemplateAccessor
{
public:
    ManagerTemplateAccessor(ManagerTemplate* manager)
        : manager_(manager) { }

    ManagerTemplateIterator Begin() {
        return this->begin();
    }

    ManagerTemplateIterator End() {
        return this->end();
    }

private:
    ManagerTemplateIterator begin() {
        return ManagerTemplateIterator(manager_, 0);
    }

    ManagerTemplateIterator end() {
        return ManagerTemplateIterator(manager_, manager_->size.value);
    }

private:
    ManagerTemplate* manager_;
};


class ManagerTemplateProvider
{
public:
    FORCEINLINE static ManagerTemplateAccessor GetAIHeroManager() {
        // auto manager = reinterpret_cast<ManagerTemplate*>(*reinterpret_cast<DWORD*>(reinterpret_cast<DWORD>(GetModuleHandle(NULL)) + Offsets::ManagerTemplate::AIHeroClient));

        auto manager = memory::Accessor::AccessModuleAddress<ManagerTemplate* /* TODO Offset */>();
        return ManagerTemplateAccessor(manager);
    }

    FORCEINLINE static ManagerTemplateAccessor GetAIMinionManager() {
        auto manager = memory::Accessor::AccessModuleAddress<ManagerTemplate* /* TODO Offset */>();
        return ManagerTemplateAccessor(manager);
    }

    FORCEINLINE static ManagerTemplateAccessor GetAITurretClient() {
        auto manager = memory::Accessor::AccessModuleAddress<ManagerTemplate* /* TODO Offset */>();
        return ManagerTemplateAccessor(manager);
    }
};

}

