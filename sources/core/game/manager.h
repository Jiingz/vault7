#pragma once

#include <core/memory/accessor.h>
#include <core/memory/member.h>

#include <core/game/game_object.h>

#include <windows.h>

#include <iterator>
#include <array>
#include <string>

namespace game {


	struct ManagerTemplate
	{
		memory::AlignedMember<UINT32, 4, 0>     object_array;
		memory::AlignedMember<UINT32, 0, 48>    size;
	};


	template <typename TType>
	class ManagerTemplateIterator {
	public:
		using iterator_category = std::forward_iterator_tag;
		using value_type = TType*;
		using difference_type = ptrdiff_t;
		using pointer = TType*;
		using reference = TType&;

		explicit ManagerTemplateIterator(ManagerTemplate* ptr, SIZE_T offset)
			: ptr_(ptr), index_(offset) { }

		reference operator*() const noexcept {
			return *operator->();
		}

		pointer operator->() const noexcept {
			_STL_VERIFY(index_ < ptr_->size.value, "cannot dereference out of range array iterator");
			auto object_array_ptr = reinterpret_cast<TType*>(*reinterpret_cast<DWORD_PTR*>(ptr_->object_array.value + index_ * 0x4));
			return object_array_ptr;
		}

		ManagerTemplateIterator& operator++() noexcept {
			//_STL_VERIFY(_Ptr, "cannot increment value-initialized array iterator");
			//_STL_VERIFY(_Idx < _Size, "cannot increment iterator past end");
			++index_;
			return *this;
		}

		ManagerTemplateIterator operator++(int) noexcept {
			ManagerTemplateIterator tmp = *this;
			++* this;
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

		ManagerTemplateIterator<GameObject> Begin() {
			return this->begin();
		}

		ManagerTemplateIterator<GameObject> End() {
			return this->end();
		}

	private:
		ManagerTemplateIterator<GameObject> begin() {
			return ManagerTemplateIterator<GameObject>(manager_, 0);
		}

		ManagerTemplateIterator<GameObject> end() {
			return ManagerTemplateIterator<GameObject>(manager_, manager_->size.value);
		}

	private:
		ManagerTemplate* manager_;
	};


	class ManagerTemplateProvider
	{
	public:
		FORCEINLINE static ManagerTemplateAccessor GetAIHeroManager() {
			// auto manager = reinterpret_cast<ManagerTemplate*>(*reinterpret_cast<DWORD*>(reinterpret_cast<DWORD>(GetModuleHandle(NULL)) + Offsets::ManagerTemplate::AIHeroClient));

			auto manager = memory::Accessor::AccessModuleAddress<ManagerTemplate*, 0x1859FAC>();
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

