#pragma once
#include <windef.h>

#include <core/memory/member.h>

namespace game::gameObjects {

	class GameObject
	{
	public:
#pragma region PADDING
		memory::AlignedMember<INT32, 28, 0> index;
		memory::AlignedMember<INT32, 42, 28> team;
#pragma endregion
	public:
		float GetPercentageHealth();
	};

}

using namespace game::gameObjects;
