#pragma once

#include <windows.h>


namespace memory {

	template <typename TType, SIZE_T TPreSize = 0, SIZE_T TPostSize = 0>
	struct AlignedMember
	{
		BYTE ___pre[TPreSize];
		TType value;
		BYTE ___post[TPreSize];
	};


	template <typename TType, SIZE_T TPreSize>
	struct AlignedMember<TType, TPreSize, 0>
	{
		BYTE ___pre[TPreSize];
		TType value;
	};


	template <typename TType, SIZE_T TPostSize>
	struct AlignedMember<TType, 0, TPostSize>
	{
		TType value;
		BYTE ___post[TPostSize];
	};

	template <typename TType>
	struct AlignedMember<TType, 0, 0>
	{
		TType value;
	};

}

