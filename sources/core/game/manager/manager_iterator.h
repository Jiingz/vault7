#pragma once


#include <iterator>
#include <array>
#include <string>

namespace game
{
	//Replica of Leagues ManagerTemplate
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
}