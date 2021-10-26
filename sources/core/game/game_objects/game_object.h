#pragma once

#include <windef.h>
#include <core/memory/member.h>

namespace game {

	class GameObject
	{
	public:
		memory::AlignedMember<INT32, 28, 0> index;
		memory::AlignedMember<INT32, 42, 28> team;
	};

}
