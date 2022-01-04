#pragma once
#include <cstdlib>
#include <cstdint>

namespace FNVHash
{
    template <typename Type, Type OffsetBasis, Type Prime>
    struct SizeDependentData
    {
        using type = Type;
        constexpr static auto kOffsetBasis = OffsetBasis;
        constexpr static auto kPrime = Prime;
    };

    template <size_t Bits>
    struct SizeSelector;

    template <>
    struct SizeSelector<32>
    {
        using type = SizeDependentData<std::uint32_t, 0x811c9dc5ul, 16777619ul>;
    };

    template <>
    struct SizeSelector<64>
    {
        using type = SizeDependentData<std::uint64_t, 0xcbf29ce484222325ull, 1099511628211ull>;
    };

    // Implements FNV-1a hash algorithm
    template <std::size_t Size>
    class FnvHash
    {
    private:
        using t_DataT = typename SizeSelector<Size>::type;
    public:
        using t_Hash = typename t_DataT::type;
    private:
        constexpr static auto kOffsetBasis = t_DataT::kOffsetBasis;
        constexpr static auto kPrime = t_DataT::kPrime;
    public:
        template <std::size_t N>

        static __forceinline constexpr auto HashConstexpr(const char(&str)[N], const std::size_t size = N) -> t_Hash
        {
            return static_cast<t_Hash>(1ull * (size == 1
                ? (kOffsetBasis ^ str[0])
                : (HashConstexpr(str, size - 1) ^ str[size - 1])) * kPrime);
        }

        static auto __forceinline HashRuntime(const char* str) -> t_Hash
        {
            auto result = kOffsetBasis;
            do
            {
                result ^= *str++;
                result *= kPrime;
            } while (*(str - 1) != '\0');

            return result;
        }
    };
}

using fnv = FNVHash::FnvHash<sizeof(void*) * 8>;
#define FNV(str) (std::integral_constant<fnv::t_Hash, fnv::HashConstexpr(str)>::value)

/*____________________________________________________________________________________________________________

Original Author: skadro
Github: https://github.com/skadro-official
License: See end of file

skCrypter
        Compile-time, Usermode + Kernelmode, safe and lightweight string crypter library for C++11+

                            *Not removing this part is appreciated*
____________________________________________________________________________________________________________*/

#ifdef _KERNEL_MODE
namespace std
{
    // STRUCT TEMPLATE remove_reference
    template <class _Ty>
    struct remove_reference {
        using type = _Ty;
    };

    template <class _Ty>
    struct remove_reference<_Ty&> {
        using type = _Ty;
    };

    template <class _Ty>
    struct remove_reference<_Ty&&> {
        using type = _Ty;
    };

    template <class _Ty>
    using remove_reference_t = typename remove_reference<_Ty>::type;

    // STRUCT TEMPLATE remove_const
    template <class _Ty>
    struct remove_const { // remove top-level const qualifier
        using type = _Ty;
    };

    template <class _Ty>
    struct remove_const<const _Ty> {
        using type = _Ty;
    };

    template <class _Ty>
    using remove_const_t = typename remove_const<_Ty>::type;
}
#else
#include <type_traits>
#endif

namespace skc
{
    template <class _Ty>
    using clean_type = typename std::remove_const_t<std::remove_reference_t<_Ty>>;

    template <int _size, char _key1, char _key2, typename T>
    class skCrypter
    {
    public:
        __forceinline constexpr skCrypter(T* data)
        {
            crypt(data);
        }

        __forceinline T* get()
        {
            return _storage;
        }

        __forceinline int size() // (w)char count
        {
            return _size;
        }

        __forceinline char key()
        {
            return _key1;
        }

        __forceinline T* encrypt()
        {
            if (!isEncrypted())
                crypt(_storage);

            return _storage;
        }

        __forceinline T* decrypt()
        {
            if (isEncrypted())
                crypt(_storage);

            return _storage;
        }

        __forceinline bool isEncrypted()
        {
            return _storage[_size - 1] != 0;
        }

        __forceinline void clear() // set full storage to 0
        {
            for (int i = 0; i < _size; i++)
            {
                _storage[i] = 0;
            }
        }

        __forceinline operator T* ()
        {
            decrypt();

            return _storage;
        }

    private:
        __forceinline constexpr void crypt(T* data)
        {
            for (int i = 0; i < _size; i++)
            {
                _storage[i] = data[i] ^ (_key1 + i % (1 + _key2));
            }
        }

        T _storage[_size]{};
    };
}

#define xor(str) skCrypt_key(str, __TIME__[4], __TIME__[7])
#define skCrypt_key(str, key1, key2) []() { \
			constexpr static auto crypted = skc::skCrypter \
				<sizeof(str) / sizeof(str[0]), key1, key2, skc::clean_type<decltype(str[0])>>((skc::clean_type<decltype(str[0])>*)str); \
					return crypted; }()