#pragma once

#include <windef.h>
#include <core/memory/member.h>

namespace game {

	class GameObject
	{
	public:
		memory::AlignedMember<INT32, 28, 0> index;
		memory::AlignedMember<INT32, 42, 28> team;

		/*
		
		char pad_0004[28]; //0x0004
	uint16_t Index; //0x0020
	char pad_0022[42]; //0x0022
	uint32_t Team; //0x004C
		*/
	};

}
